// Copyright (c) 2020 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#pragma once

#include "AccelByteError.h"
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"

#include "AccelByteUtilities.generated.h"

using AccelByte::THandler;
using AccelByte::FErrorHandler;

class ACCELBYTEUE4SDK_API FAccelByteUtilities
{
public:
	template<typename CharType = TCHAR, template<typename> class PrintPolicy = TPrettyJsonPrintPolicy, typename InStructType>
	static bool TArrayUStructToJsonString(const TArray<InStructType>& InArray, FString& OutJsonString, int64 CheckFlags = 0, int64 SkipFlags = 0, int32 Indent = 0)
	{
		const UStruct* StructDefinition = InStructType::StaticStruct();
		TArray< TSharedPtr<FJsonValue> > JsonArray;

		for (auto& Item : InArray)
		{
			const void* Struct = &Item;
			TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
			if (FJsonObjectConverter::UStructToJsonObject(StructDefinition, Struct, JsonObject.ToSharedRef(), CheckFlags, SkipFlags, nullptr))
			{
				TSharedRef< FJsonValueObject > JsonValue = MakeShareable(new FJsonValueObject(JsonObject));
				JsonArray.Add(JsonValue);
			}
		}

		TSharedRef<TJsonWriter<CharType, PrintPolicy<CharType>>> JsonWriter = TJsonWriterFactory<CharType, PrintPolicy<CharType>>::Create(&OutJsonString, Indent);
		if (FJsonSerializer::Serialize(JsonArray, JsonWriter))
		{
			JsonWriter->Close();
			return true;
		}
		else
		{
			UE_LOG(LogJson, Warning, TEXT("UStructToFormattedObjectString - Unable to write out json"));
			JsonWriter->Close();
		}

		return false;
	}

	static void RemoveEmptyStrings(TSharedPtr<FJsonObject> Json);
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPubIp
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Web | Models | Ip")
		FString Ip;
};

class ACCELBYTEUE4SDK_API FAccelByteNetUtilities
{
public:
	static void GetPublicIP(const THandler<FAccelByteModelsPubIp>& OnSuccess, const FErrorHandler& OnError);
	static void DownloadFrom(const FString& Url, const FHttpRequestProgressDelegate& OnProgress, const THandler<TArray<uint8>>& OnDownloaded, const FErrorHandler& OnError);
	static void UploadTo(const FString& Url, const TArray<uint8>& DataUpload, const FHttpRequestProgressDelegate& OnProgress, const AccelByte::FVoidHandler& OnSuccess, const FErrorHandler& OnError);
};