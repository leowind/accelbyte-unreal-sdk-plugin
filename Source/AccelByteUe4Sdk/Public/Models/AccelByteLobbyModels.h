// Copyright (c) 2018 - 2020 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectWrapper.h"
#include "Dom/JsonValue.h"
#include "Models/AccelByteGeneralModels.h"
#include "AccelByteLobbyModels.generated.h"

// Emulate namespace with long class names
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsLobbyType
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString Type;
};

// ------------------------------------------------------------------------------------------------
// Party 
// ------------------------------------------------------------------------------------------------

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPartyData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FJsonObjectWrapper Custom_Attribute;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	TArray<FString> Invitees;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Leader;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	TArray<FString> Members;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Namespace;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString PartyId;
	int64 UpdatedAt;
};

// Get current party info
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsInfoPartyResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString Code;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString PartyId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString LeaderId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        TArray<FString> Members;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		TArray<FString> Invitees;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString InvitationToken;
};


// Get current party data
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsDataPartyResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		TMap<FString, FString> custom_attribute;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString updatedAt;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString partyId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString leaderId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		TArray<FString> members;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		TArray<FString> invitees;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString invitationToken;
};

//Create new party
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsCreatePartyResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString Code;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString PartyId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString LeaderId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		TArray<FString> Members;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        TArray<FString> Invitees;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString InvitationToken;
};

//Leave current party
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsLeavePartyResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString Code;
};

//Party leave notice
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsLeavePartyNotice
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString UserID;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString LeaderID;
};

//Invite user to party
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPartyInviteResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString Code;
};

//Invitation notice
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsInvitationNotice
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString InviterID;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString InviteeID;
};

//Being invited
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPartyGetInvitedNotice
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString From;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString PartyId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString InvitationToken;
};

// Accept Invitation
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPartyJoinReponse
{
    GENERATED_BODY()
        UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString Code;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString PartyId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString LeaderId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        TArray<FString> Members;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        TArray<FString> Invitees;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString InvitationToken;
};

// Invitation being accepted
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPartyJoinNotice
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString UserId;
};

// Accept Invitation
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPartyRejectResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Code;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString PartyId;
};

// Invitation being accepted
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPartyRejectNotice
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString PartyId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString LeaderId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString UserId;
};

// Kick member
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsKickPartyMemberResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString Code;
};

// Get party Code
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPartyGetCodeResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Code;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString PartyCode;
};

// Delete party Code
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPartyDeleteCodeResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString Code;
};


//Being kicked
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsGotKickedFromPartyNotice
{
    GENERATED_BODY()
        UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString LeaderId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString UserId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString PartyId;
};



//Kick notice
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsKickNotice
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString LeaderId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString UserId;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
        FString PartyId;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPartyPromoteLeaderResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString PartyId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString LeaderId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		TArray<FString> Members;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		TArray<FString> Invitees;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString invitationToken;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString Code;
};

// ------------------------------------------------------------------------------------------------
// Chat 
// ------------------------------------------------------------------------------------------------
// Send personal chat
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPersonalMessageResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString Code;
};

// Receive personal chat
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPersonalMessageNotice
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Id;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString From;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString To;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Payload;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString ReceivedAt;
};

// Send party chat
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPartyMessageResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString Code;
};

//Receive party chat 
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPartyMessageNotice
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Id;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString From;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString To;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Payload;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString ReceivedAt;
};

// join default channel chat
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsJoinDefaultChannelResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString ChannelSlug;
};

// send channel chat request
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsChannelMessageRequest
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString ChannelSlug;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString payload;
};

// Receive channel chat
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsChannelMessageNotice
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString From;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString ChannelSlug;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString Payload;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString SentAt;
};

// Send channel chat
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsChannelMessageResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Code;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Message;
};

// ------------------------------------------------------------------------------------------------
// Presence 
// ------------------------------------------------------------------------------------------------
// Set user status
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsSetOnlineUsersResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString Code;
};


USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsUsersPresenceNotice
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString UserID;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString Availability;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString Activity;
};



// List all friends presence
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsGetOnlineUsersResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Code;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString type;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString id;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	TArray<FString> friendsId;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    TArray<FString> availability;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    TArray<FString> activity;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    TArray<FString> lastSeenAt;
};

// ------------------------------------------------------------------------------------------------
// Notification 
// ------------------------------------------------------------------------------------------------
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsNotificationMessage
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Id;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString From;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString To;
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString Topic;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Payload;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FDateTime SentAt;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsFreeFormNotificationRequest
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Topic;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Message;
};

// ------------------------------------------------------------------------------------------------
// Matchmaking
// ------------------------------------------------------------------------------------------------
UENUM(BlueprintType)
/**
 * @brief matchmaking status enumeration.
 */
enum class EAccelByteMatchmakingStatus : uint8
{
	Unknown = 0	UMETA(DisplayName = "unknown"),
	Start		UMETA(DisplayName = "start"),
	Timeout		UMETA(DisplayName = "timeout"),
	Cancel		UMETA(DisplayName = "cancel"),
	Done		UMETA(DisplayName = "done"),
	Unavailable UMETA(DisplayName = "unavailable"),
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsMatchmakingResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString Code;
};

// Matchmaking notification
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsMatchmakingNotice
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    FString MatchId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
    EAccelByteMatchmakingStatus Status{EAccelByteMatchmakingStatus::Unknown};
};

// DS Notification
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsDsNotice
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Status;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString MatchId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString PodName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Ip;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	int32 Port;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Message;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString IsOK;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Region;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	TMap<FString, int32> Ports;
};

// Ready Consent Request
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsReadyConsentRequest
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString Code;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString MatchId;
};

// Ready Consent Notice
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsReadyConsentNotice
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString MatchId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	FString UserId;
};

// Rematchmaking Notice
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsRematchmakingNotice
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
	int32 BanDuration;
};

// Lobby Disconnect Notice
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsDisconnectNotif
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | General | DisconnectNotif")
	FString Message;
};

// ------------------------------------------------------------------------------------------------
// Friends
// ------------------------------------------------------------------------------------------------
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsRequestFriendsResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | RequestFriendsResponse")
		FString Code;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsUnfriendResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | UnfriendResponse")
		FString Code;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsListOutgoingFriendsResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | ListOutgoingFriendsResponse")
		FString Code;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | ListOutgoingFriendsResponse")
		TArray<FString> friendsId;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsCancelFriendsResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | CancelFriendsResponse")
		FString Code;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsListIncomingFriendsResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | ListIncomingFriendsResponse")
		FString Code;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | ListIncomingFriendsResponse")
		TArray<FString> friendsId;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsAcceptFriendsResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | AcceptFriendsResponse")
		FString Code;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsRejectFriendsResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | RejectFriendsResponse")
		FString Code;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsLoadFriendListResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | ListOfFriendsResponse")
		FString Code;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | ListOfFriendsResponse")
		TArray<FString> friendsId;
};

UENUM(BlueprintType)
/**
 * @brief Friends relation enumeration.
 */
enum class ERelationshipStatusCode : uint8
{
	Friend = 3,
	Incoming = 2,
	Outgoing = 1,
	NotFriend = 0
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsGetFriendshipStatusResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | GetFriendshipStatusResponse")
		FString Code;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | GetFriendshipStatusResponse")
		ERelationshipStatusCode friendshipStatus;
};

USTRUCT(BlueprintType)
struct FAccelByteModelsGetFriendshipStatusStringResponse
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, NotBlueprintType, Category = "AccelByte | Lobby | Models | Friends | GetFriendshipStatusStringResponse")
        FString Code;
    UPROPERTY(EditAnywhere, NotBlueprintType, Category = "AccelByte | Lobby | Models | Friends | GetFriendshipStatusStringResponse")
        FString friendshipStatus;
};

UENUM(BlueprintType)
/**
 * @brief presence enumeration.
 */
enum class Availability : uint8
{
	Offline = 0,
	Availabe = 1,
	Busy = 2,
	Invisible = 3
};

UENUM(BlueprintType)
/**
 * @brief general presence enumeration.
 */
	enum class EAccelByteGeneralUserStatus : uint8
{
	Offline UMETA(DisplayName = "offline"),
	Online UMETA(DisplayName = "online"),
	Busy UMETA(DisplayName = "busy"),
	Invisible UMETA(DisplayName = "invisible")
};

USTRUCT(BlueprintType)
struct FAccelByteModelsAcceptFriendsNotif
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | AcceptFriendsNotif")
		FString friendId;
};

USTRUCT(BlueprintType)
struct FAccelByteModelsRequestFriendsNotif
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | RequestFriendsNotif")
		FString friendId;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsBulkFriendsRequest
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | BulkFriendsRequest")
		TArray<FString> FriendIds;
};

USTRUCT(BlueprintType)
struct FAccelByteModelsUnfriendNotif
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | UnfriendNotif")
		FString friendId;
};

USTRUCT(BlueprintType)
struct FAccelByteModelsCancelFriendsNotif
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | CancelFriendNotif")
		FString userId;
};

USTRUCT(BlueprintType)
struct FAccelByteModelsRejectFriendsNotif
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | RejectFriendNotif")
		FString userId;
};
		
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsUserStatusNotif
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Lobby | UserStatusNotif")
		FString UserID;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Lobby | UserStatusNotif")
		EAccelByteGeneralUserStatus Availability;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Lobby | UserStatusNotif")
		FString Activity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Lobby | UserStatusNotif")
		FString Namespace;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Lobby | UserStatusNotif")
		FString LastSeenAt;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsBulkUserStatusNotif
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Lobby | BulkUserStatusNotif")
		TArray<FAccelByteModelsUserStatusNotif> Data;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Lobby | BulkUserStatusNotif")
		int32 Online;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Lobby | BulkUserStatusNotif")
		int32 Busy;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Lobby | BulkUserStatusNotif")
		int32 Invisible;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Lobby | BulkUserStatusNotif")
		int32 Offline;
};
// ------------------------------------------------------------------------------------------------
// Party Storage
// ------------------------------------------------------------------------------------------------

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPartyDataNotif
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString PartyId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString LeaderId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		TArray<FString> Members;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		TArray<FString> Invitees;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FJsonObjectWrapper Custom_attribute;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString UpdatedAt;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPartyDataUpdateRequest
{
	GENERATED_BODY()
		int64 UpdatedAt;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FJsonObjectWrapper Custom_attribute;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPartyDataUpdateStringRequest
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString UpdatedAt;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FJsonObjectWrapper Custom_attribute;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsActivePartiesData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		TArray<FAccelByteModelsPartyDataNotif> Data;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FAccelByteModelsPaging Paging;
};

// ------------------------------------------------------------------------------------------------
// Session Attribute
// ------------------------------------------------------------------------------------------------

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsSetSessionAttributesResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString Code;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsGetSessionAttributesResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString Code;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString Value;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsGetAllSessionAttributesResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString Code;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FJsonObjectWrapper attributes;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsSetSessionAttributeRequest
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		TMap<FString, FString> Attributes;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsGetSessionAttributeResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString Key;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString Value;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsGetSessionAttributeAllResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		TMap<FString, FString> Attributes;
};
// ------------------------------------------------------------------------------------------------
// Block Players
// ------------------------------------------------------------------------------------------------

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsBlockPlayerResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | AcceptFriendsResponse")
		FString Code;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsUnblockPlayerResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | RejectFriendsResponse")
		FString Code;
};

USTRUCT(BlueprintType)
struct FAccelByteModelsBlockPlayerNotif
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | RequestFriendsNotif")
		FString UserId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | RequestFriendsNotif")
		FString BlockedUserId;
};

USTRUCT(BlueprintType)
struct FAccelByteModelsUnblockPlayerNotif
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | RequestFriendsNotif")
		FString UserId;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | Friends | RequestFriendsNotif")
		FString UnblockedUserId;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FBlockedData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString BlockedUserId;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsListBlockedUserResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		TArray<FBlockedData> Data;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FBlockerData
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		FString UserId;
};

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsListBlockerResponse
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Category | Models | Lobby")
		TArray<FBlockerData> Data;
};

// ------------------------------------------------------------------------------------------------
// General
// ------------------------------------------------------------------------------------------------
USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsLobbySessionId
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AccelByte | Lobby | Models | General | LobbySessionId")
	FString LobbySessionID;
};
