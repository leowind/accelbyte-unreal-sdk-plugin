// Copyright (c) 2018 - 2021 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#include "Core/AccelByteHttpRetryScheduler.h"
#include "Core/AccelByteReport.h"
#include "Core/AccelByteRegistry.h"
#include <algorithm>

DECLARE_LOG_CATEGORY_EXTERN(LogAccelByteHttpRetry, Log, All);
DEFINE_LOG_CATEGORY(LogAccelByteHttpRetry);

using namespace std;

namespace AccelByte
{

namespace HttpRequest
{
	bool IsFinished(const FHttpRequestPtr& Request)
	{
		return Request->GetStatus() == EHttpRequestStatus::Failed ||
			Request->GetStatus() == EHttpRequestStatus::Failed_ConnectionError ||
			Request->GetStatus() == EHttpRequestStatus::Succeeded;
	}
}

const int FHttpRetryScheduler::InitialDelay = 1;
const int FHttpRetryScheduler::MaximumDelay = 30;
const int FHttpRetryScheduler::TotalTimeout = 60;

FHttpRetryScheduler::FHttpRetryTask::FHttpRetryTask(const FHttpRequestPtr& Request, const FHttpRequestCompleteDelegate& CompleteDelegate, double RequestTime, double NextDelay)
	: Request(Request)
	, CompleteDelegate(CompleteDelegate)
	, RequestTime(RequestTime)
	, NextDelay(NextDelay)
	, NextRetryTime(RequestTime + NextDelay)
	, ScheduledRetry(false)
{
}

bool FHttpRetryScheduler::ProcessRequest(const FHttpRequestPtr& Request, const FHttpRequestCompleteDelegate& CompleteDelegate, double RequestTime)
{
	if (State == EHttpRetrySchedulerState::SHUTTING_DOWN)
	{
		UE_LOG(LogAccelByteHttpRetry, Warning, TEXT("Cannot process request, HTTP Retry Scheduler is SHUTTING DOWN"));
		return false;
	}
	if (State == EHttpRetrySchedulerState::UNINITIALIZED)
	{
		UE_LOG(LogAccelByteHttpRetry, Warning, TEXT("Cannot process request, HTTP Retry Scheduler is UNINITIALIZED"));
		return false;
	}


	FReport::LogHttpRequest(Request);
	bool bIsStarted = Request->ProcessRequest();

	RetryList.Add(MakeShared<FHttpRetryTask>(Request, CompleteDelegate, RequestTime, InitialDelay));

	return bIsStarted;
}

bool FHttpRetryScheduler::PollRetry(double CurrentTime)
{
	if (RetryList.Num() == 0)
	{
		return false;
	}

	TArray<TSharedRef<FHttpRetryTask>> CompletedTasks;

	RetryList.RemoveAll([CurrentTime, &CompletedTasks](const TSharedRef<FHttpRetryTask>& CurrentTask)
	{
		if (!CurrentTask->Request.IsValid())
		{
			return true;
		}

		if (CurrentTask->ScheduledRetry)
		{
			if (CurrentTime >= CurrentTask->NextRetryTime)
			{
				CurrentTask->ScheduledRetry = false;
				FReport::LogHttpRequest(CurrentTask->Request);
				CurrentTask->Request->ProcessRequest();
			}
			else
			{
				return false;
			}
		}

		switch (CurrentTask->Request->GetStatus())
		{
		case EHttpRequestStatus::Processing:
			if (CurrentTime >= CurrentTask->RequestTime + FHttpRetryScheduler::TotalTimeout)
			{
				CurrentTask->Request->CancelRequest();
			}

			return false;
		case EHttpRequestStatus::Succeeded: //got response
			switch (CurrentTask->Request->GetResponse()->GetResponseCode())
			{
			case EHttpResponseCodes::ServerError:
			case EHttpResponseCodes::BadGateway:
			case EHttpResponseCodes::ServiceUnavail:
			case EHttpResponseCodes::GatewayTimeout:
				if (CurrentTime >= CurrentTask->RequestTime + FHttpRetryScheduler::TotalTimeout)
				{
					CompletedTasks.Add(CurrentTask);
					return true;
				}

				CurrentTask->ScheduleNextRetry(CurrentTime);

				return false;
			case EHttpResponseCodes::Forbidden:
				CompletedTasks.Add(CurrentTask);

				return true;
			default:
				CompletedTasks.Add(CurrentTask);

				return true;
			}
		case EHttpRequestStatus::NotStarted:
			if (CurrentTime >= CurrentTask->RequestTime + FHttpRetryScheduler::TotalTimeout)
			{
				CompletedTasks.Add(CurrentTask);
				return true;
			}

			return false;
		case EHttpRequestStatus::Failed_ConnectionError: //network error
			if (CurrentTime >= CurrentTask->RequestTime + FHttpRetryScheduler::TotalTimeout)
			{
				CompletedTasks.Add(CurrentTask);
				return true;
			}

			CurrentTask->ScheduleNextRetry(CurrentTime);

			return false;
		case EHttpRequestStatus::Failed: //request cancelled
			CompletedTasks.Add(CurrentTask);

			return true;
		default:
			return false;
		}
	});

	for (const auto& Task : CompletedTasks)
	{
		const FHttpRequestPtr& Request = Task->Request;
		FReport::LogHttpResponse(Request, Request->GetResponse());
		Task->CompleteDelegate.ExecuteIfBound(Request, Request->GetResponse(), HttpRequest::IsFinished(Request));
	}

	return true;
}

void FHttpRetryScheduler::Startup()
{
	PollRetryHandle = FTicker::GetCoreTicker().AddTicker(
        FTickerDelegate::CreateLambda([this](float DeltaTime)
        {
            PollRetry(FPlatformTime::Seconds());

            return true;
        }),
        0.2f);

	State = EHttpRetrySchedulerState::INITIALIZED;
	UE_LOG(LogAccelByteHttpRetry, Verbose, TEXT("HTTP Retry Scheduler has been INITIALIZED"));
}

void FHttpRetryScheduler::Shutdown()
{
	State = EHttpRetrySchedulerState::SHUTTING_DOWN;

	if (PollRetryHandle.IsValid())
	{
		FTicker::GetCoreTicker().RemoveTicker(PollRetryHandle);
		PollRetryHandle.Reset();
	}

	// flush http requests
	if (RetryList.Num() != 0)
	{
		double MaxFlushTimeSeconds = -1.0;
		GConfig->GetDouble(TEXT("HTTP"), TEXT("MaxFlushTimeSeconds"), MaxFlushTimeSeconds, GEngineIni);

		if (MaxFlushTimeSeconds <= 0)
		{
			UE_LOG(LogAccelByteHttpRetry, Log, TEXT("HTTP MaxFlushTimeSeconds is not configured, it may prevent the shutdown, until all requests flushed"));
		}

		// try flush once
		FHttpModule::Get().GetHttpManager().Flush(true);
		FHttpModule::Get().GetHttpManager().Tick(0);

		// cancel unfinished http requests, so don't hinder the shutdown
		for (auto& Task : RetryList)
		{
			if (Task->Request.IsValid() && Task->Request->GetStatus() == EHttpRequestStatus::Processing)
			{
				Task->Request->CancelRequest();
			}
		}
		RetryList.Empty();
	};
}

void FHttpRetryScheduler::FHttpRetryTask::ScheduleNextRetry(double CurrentTime)
{
	NextDelay *= 2;
	NextDelay += FMath::RandRange(-NextDelay, NextDelay) / 4;

	if (NextDelay > FHttpRetryScheduler::MaximumDelay)
	{
		NextDelay = FHttpRetryScheduler::MaximumDelay;
	}

	NextRetryTime = CurrentTime + NextDelay;

	if (NextRetryTime > RequestTime + FHttpRetryScheduler::TotalTimeout)
	{
		NextRetryTime = RequestTime + FHttpRetryScheduler::TotalTimeout;
	}

	ScheduledRetry = true;

}

}
