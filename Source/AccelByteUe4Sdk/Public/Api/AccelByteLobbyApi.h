// Copyright (c) 2018-2020 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Core/AccelByteError.h"
#include "Models/AccelByteLobbyModels.h"

// Forward declarations
class IWebSocket;

namespace AccelByte
{
class Credentials;
class Settings;

namespace Api
{

enum class EWebSocketState
{
	Closed = 0,
	Connecting = 1,
	Connected = 2,
	Closing = 3,
	Reconnecting = 4
};

enum class EWebSocketEvent : uint8
{
	None = 0,
	Connect = 1,
	Connected = 2,
	Close = 4,
	Closed = 8,
	ConnectionError = 16
};

ENUM_CLASS_FLAGS(EWebSocketEvent);
	
/**
 * @brief Lobby API for chatting and party management.
 * Unlike other servers which use HTTP, Lobby server uses WebSocket (RFC 6455).
 */
class ACCELBYTEUE4SDK_API Lobby
{
public:
	Lobby(const Credentials& Credentials, const Settings& Settings, float PingDelay = 30.f, float InitialBackoffDelay = 1.f, float MaxBackoffDelay = 30.f, float TotalTimeout = 60.f, TSharedPtr<IWebSocket> WebSocket = nullptr);
	~Lobby();
private:
	const Credentials& Credentials;
	const Settings& Settings;

public:

    // Party 
    /**
     * @brief delegate for handling info party response.
     */
    DECLARE_DELEGATE_OneParam(FPartyInfoResponse, const FAccelByteModelsInfoPartyResponse&); 


    /**
     * @brief delegate for handling create party response.
     */
    DECLARE_DELEGATE_OneParam(FPartyCreateResponse, const FAccelByteModelsCreatePartyResponse&); 

    /**
     * @brief delegate for handling leave party response.
     */
    DECLARE_DELEGATE_OneParam(FPartyLeaveResponse, const FAccelByteModelsLeavePartyResponse&); 

    /**
     * @brief delegate for handling leave party notification.
     */
    DECLARE_DELEGATE_OneParam(FPartyLeaveNotif, const FAccelByteModelsLeavePartyNotice&);                  // Passive


    /**
     * @brief delegate for handling invite party response.
     */
    DECLARE_DELEGATE_OneParam(FPartyInviteResponse, const FAccelByteModelsPartyInviteResponse&); 

    /**
     * @brief delegate for handling party invitation notification
     */
    DECLARE_DELEGATE_OneParam(FPartyInviteNotif, const FAccelByteModelsInvitationNotice&);       // Passive

    /**
     * @brief delegate for handling get party invitation notification
     */
    DECLARE_DELEGATE_OneParam(FPartyGetInvitedNotif, const FAccelByteModelsPartyGetInvitedNotice&);  // Passive

    /**
     * @brief delegate for handling join party response
     */
    DECLARE_DELEGATE_OneParam(FPartyJoinResponse, const FAccelByteModelsPartyJoinReponse&); 

    /**
     * @brief delegate for handling join party notification
     */
    DECLARE_DELEGATE_OneParam(FPartyJoinNotif, const FAccelByteModelsPartyJoinNotice&);              // Passive

	/**
	* @brief delegate for handling reject party response
	*/
	DECLARE_DELEGATE_OneParam(FPartyRejectResponse, const FAccelByteModelsPartyRejectResponse&); 

	/**
	* @brief delegate for handling reject party notification
	*/
	DECLARE_DELEGATE_OneParam(FPartyRejectNotif, const FAccelByteModelsPartyRejectNotice&);;              // Passive
	
    /**
     * @brief delegate for handling member kicked from party event
     */
    DECLARE_DELEGATE_OneParam(FPartyKickResponse, const FAccelByteModelsKickPartyMemberResponse&); 
    
    /**
     * @brief delegate for handling member kicked from party event notification
     */
    DECLARE_DELEGATE_OneParam(FPartyKickNotif, const FAccelByteModelsGotKickedFromPartyNotice&);   // Passive

	/**
	 * @brief delegate for handling member kicked from party event
	 */
	DECLARE_DELEGATE_OneParam(FPartyDataUpdateNotif, const FAccelByteModelsPartyDataNotif&);

	/**
	 * @brief delegate for handling get party code event
	 */
	DECLARE_DELEGATE_OneParam(FPartyGetCodeResponse, const FAccelByteModelsPartyGetCodeResponse&);

	/**
	 * @brief delegate for handling delete party code event
	 */
	DECLARE_DELEGATE_OneParam(FPartyDeleteCodeResponse, const FAccelByteModelsPartyDeleteCodeResponse&);

	/**
	 * @brief delegate for handling join party via party code event
	 */
	DECLARE_DELEGATE_OneParam(FPartyJoinViaCodeResponse, const FAccelByteModelsPartyJoinReponse&);

	/**
	 * @brief delegate for handling promote party leader response
	 */
	DECLARE_DELEGATE_OneParam(FPartyPromoteLeaderResponse, const FAccelByteModelsPartyPromoteLeaderResponse&);

    // Chat
    /**
     * @brief delegate for handling private message response
     */
    DECLARE_DELEGATE_OneParam(FPersonalChatResponse, const FAccelByteModelsPersonalMessageResponse&);    

    /**
     * @brief delegate for handling private message event notification
     */
    DECLARE_DELEGATE_OneParam(FPersonalChatNotif, const FAccelByteModelsPersonalMessageNotice&);         // Passive

    /**
     * @brief delegate for handling party message event response
     */
    DECLARE_DELEGATE_OneParam(FPartyChatResponse, const FAccelByteModelsPartyMessageResponse&);

    /**
     * @brief delegate for handling party message event notification
     */
    DECLARE_DELEGATE_OneParam(FPartyChatNotif, const FAccelByteModelsPartyMessageNotice&);              // Passive
    
	/**
	 * @brief delegate for handling join default channel message event response
	 */
	DECLARE_DELEGATE_OneParam(FJoinDefaultChannelChatResponse, const FAccelByteModelsJoinDefaultChannelResponse&);

	/**
	 * @brief delegate for handling channel message event response
	 */
	DECLARE_DELEGATE_OneParam(FChannelChatResponse, const FAccelByteModelsChannelMessageResponse&);

	/**
	 * @brief delegate for handling channel message event notification
	 */
	DECLARE_DELEGATE_OneParam(FChannelChatNotif, const FAccelByteModelsChannelMessageNotice&);

    // Presence
    /**
     * @brief delegate for handling user change presence status
     */
    DECLARE_DELEGATE_OneParam(FSetUserPresenceResponse, const FAccelByteModelsSetOnlineUsersResponse&);

    /**
     * @brief delegate for handling other user change their presence status event
     */
    DECLARE_DELEGATE_OneParam(FFriendStatusNotif, const FAccelByteModelsUsersPresenceNotice&);

    /**
     * @brief delegate for handling get all user presence
     */
    DECLARE_DELEGATE_OneParam(FGetAllFriendsStatusResponse, const FAccelByteModelsGetOnlineUsersResponse&);        


    // Notification
	/**
	 * @brief delegate for handling incoming notification
	*/
	DECLARE_DELEGATE_OneParam(FMessageNotif, const FAccelByteModelsNotificationMessage&); //Passive

    // Matchmaking
	/**
	 * @brief delegate for handling matchmaking response
	 */
	DECLARE_DELEGATE_OneParam(FMatchmakingResponse, const FAccelByteModelsMatchmakingResponse&);

	/**
	 * @brief delegate for handling ready consent response
	 */
	DECLARE_DELEGATE_OneParam(FReadyConsentResponse, const FAccelByteModelsReadyConsentRequest&);

    /**
     * @brief delegate for handling matchmaking notification
     */
    DECLARE_DELEGATE_OneParam(FMatchmakingNotif, const FAccelByteModelsMatchmakingNotice&);

	/*
	 * @brief delegate for handling ready consent notification
	 */
	DECLARE_DELEGATE_OneParam(FReadyConsentNotif, const FAccelByteModelsReadyConsentNotice&);

	/*
	 * @brief delegate for handling rematchmaking notification
	 */
	DECLARE_DELEGATE_OneParam(FRematchmakingNotif, const FAccelByteModelsRematchmakingNotice&);

	/*
	 * @brief delegate for handling DS notification
	 */
	DECLARE_DELEGATE_OneParam(FDsNotif, const FAccelByteModelsDsNotice&);

	// Friends
	/**
	 * @brief delegate for handling request friend response
	 */
	DECLARE_DELEGATE_OneParam(FRequestFriendsResponse, const FAccelByteModelsRequestFriendsResponse&);
	
	/**
	 * @brief delegate for handling unfriend response
	 */
	DECLARE_DELEGATE_OneParam(FUnfriendResponse, const FAccelByteModelsUnfriendResponse&);
	
	/**
	 * @brief delegate for handling list outgoing friends response
	 */
	DECLARE_DELEGATE_OneParam(FListOutgoingFriendsResponse, const FAccelByteModelsListOutgoingFriendsResponse&);
	
	/**
	 * @brief delegate for handling cancel friend response
	 */
	DECLARE_DELEGATE_OneParam(FCancelFriendsResponse, const FAccelByteModelsCancelFriendsResponse&);
	
	/**
	 * @brief delegate for handling list incoming friends response
	 */
	DECLARE_DELEGATE_OneParam(FListIncomingFriendsResponse, const FAccelByteModelsListIncomingFriendsResponse&);
	
	/**
	 * @brief delegate for handling accept friend response
	 */
	DECLARE_DELEGATE_OneParam(FAcceptFriendsResponse, const FAccelByteModelsAcceptFriendsResponse&);
	
	/**
	 * @brief delegate for handling reject friend response
	 */
	DECLARE_DELEGATE_OneParam(FRejectFriendsResponse, const FAccelByteModelsRejectFriendsResponse&);
	
	/**
	 * @brief delegate for handling load friend list response
	 */
	DECLARE_DELEGATE_OneParam(FLoadFriendListResponse, const FAccelByteModelsLoadFriendListResponse&);

	/**
	 * @brief delegate for handling get friendship status response
	 */
	DECLARE_DELEGATE_OneParam(FGetFriendshipStatusResponse, const FAccelByteModelsGetFriendshipStatusResponse&);

	// Friends + Notification
	/**
	 * @brief delegate for handling notification when your request friend is accepted
	 */
	DECLARE_DELEGATE_OneParam(FAcceptFriendsNotif, const FAccelByteModelsAcceptFriendsNotif&);

	/**
	 * @brief delegate for handling notification when you receive a request friend
	 */
	DECLARE_DELEGATE_OneParam(FRequestFriendsNotif, const FAccelByteModelsRequestFriendsNotif&);

	/**
	 * @brief delegate for handling unfriend notification
	 */
	DECLARE_DELEGATE_OneParam(FUnfriendNotif, const FAccelByteModelsUnfriendNotif&);
	
	/**
	 * @brief delegate for handling cancel friend notification
	 */
	DECLARE_DELEGATE_OneParam(FCancelFriendsNotif, const FAccelByteModelsCancelFriendsNotif&);

	/**
	 * @brief delegate for handling reject friend notification
	 */
	DECLARE_DELEGATE_OneParam(FRejectFriendsNotif, const FAccelByteModelsRejectFriendsNotif&);
	
	//Block
	/**
	 * @brief delegate for handling block player response
	 */
	DECLARE_DELEGATE_OneParam(FBlockPlayerResponse, const FAccelByteModelsBlockPlayerResponse&);

	/**
	 * @brief delegate for handling unblock player response
	 */
	DECLARE_DELEGATE_OneParam(FUnblockPlayerResponse, const FAccelByteModelsUnblockPlayerResponse&);
	
	/**
	 * @brief delegate for handling list blocked user response
	 */
	DECLARE_DELEGATE_OneParam(FListBlockedUserResponse, const FAccelByteModelsListBlockedUserResponse&);

	/**
	 * @brief delegate for handling list blocker response
	 */
	DECLARE_DELEGATE_OneParam(FListBlockerResponse, const FAccelByteModelsListBlockerResponse&);

	// Block + Notif
	/**
	 * @brief delegate for handling notification when you block a player
	 */
	DECLARE_DELEGATE_OneParam(FBlockPlayerNotif, const FAccelByteModelsBlockPlayerNotif&);

	/**
	 * @brief delegate for handling notification when you unblock a player
	 */
	DECLARE_DELEGATE_OneParam(FUnblockPlayerNotif, const FAccelByteModelsUnblockPlayerNotif&);

	//Signaling
	/**
	 * @brief delegate for handling signaling P2P message
	 */
	DECLARE_DELEGATE_TwoParams(FSignalingP2P, const FString&, const FString&);

	//Error
	/**
	* @brief delegate for handling signaling P2P message
	*/
	DECLARE_DELEGATE_TwoParams(FErrorNotif, int32, const FString&);				//passive
	
	/**
	 * @brief delegate for handling response when setting session attribute
	 */
	DECLARE_DELEGATE_OneParam(FSetSessionAttributeResponse, const FAccelByteModelsSetSessionAttributesResponse&);

	/**
	 * @brief delegate for handling response when setting session attribute
	 */
	DECLARE_DELEGATE_OneParam(FGetSessionAttributeResponse, const FAccelByteModelsGetSessionAttributesResponse&);

	/**
	 * @brief delegate for handling response when setting session attribute
	 */
	DECLARE_DELEGATE_OneParam(FGetAllSessionAttributeResponse, const FAccelByteModelsGetAllSessionAttributesResponse&);

	DECLARE_DELEGATE(FConnectSuccess);
	DECLARE_DELEGATE_OneParam(FDisconnectNotif, const FAccelByteModelsDisconnectNotif&)
	DECLARE_DELEGATE_ThreeParams(FConnectionClosed, int32 /* StatusCode */, const FString& /* Reason */, bool /* WasClean */);
	
public:
    /**
	 * @brief Connect to the Lobby server via websocket. You must connect to the server before you can start sending/receiving. Also make sure you have logged in first as this operation requires access token.
	 */
	void Connect();

	/**
	 * @brief Disconnect from server if and only if the you have connected to server. If not currently connected, then this does nothing.
	 */
	void Disconnect();

	/**
	 * @brief Check whether the websocket is currently connected to the Lobby server.
	 * 
	 * @return true if it's connected, false otherwise.
	 */
	bool IsConnected() const;
	
	/**
	 * @brief Send ping
	 */
	void SendPing();

	/**
	 * @brief Send a private message to another user.
	 * 
	 * @param UserId The recipient's user ID.
	 * @param Message Message to be sent.
	 */
	FString SendPrivateMessage(const FString& UserId, const FString& Message);

	/**
	 * @brief Send a message to other party members.
	 * 
	 * @param Message Message to be sent.
	 */
    FString SendPartyMessage(const FString& Message);
	
	/**
	 * @brief Request to join the default channel chat.
	 */
	FString SendJoinDefaultChannelChatRequest();

	/**
	 * @brief Send a message to joined channel chat.
	 */
	FString SendChannelMessage(const FString& Message);

    //------------------------
    // Party
    //------------------------

	/**
	 * @brief Get information about current party.
	 */
	FString SendInfoPartyRequest();

	/**
	 * @brief Create a party.
	 */
    FString SendCreatePartyRequest();

	/**
	 * @brief Leave current party.
	 */
    FString SendLeavePartyRequest();

	/**
	 * @brief Invite a user to party.
	 * 
	 * @param UserId The target user ID to be invited.
	 */
    FString SendInviteToPartyRequest(const FString& UserId);

    /**
     * @brief Set presence status on lobby service
     *
     * @param State the presence state that you want to use. State is Presence type
     * @param GameName the game name that you play
     */
	FString SendSetPresenceStatus(const Availability Availability, const FString& Activity);

	/**
	 * @brief Accept a party invitation.
	 * 
	 * @param PartyId Party ID from the invitation notice.
	 * @param InvitationToken Random string from the invitation notice.
	 */
	FString SendAcceptInvitationRequest(const FString& PartyId, const FString& InvitationToken);
	
	/**
	* @brief Reject a party invitation.
	* 
	* @param PartyId Party ID from the invitation notice.
	* @param InvitationToken Random string from the invitation notice.
	*/
	FString SendRejectInvitationRequest(const FString& PartyId, const FString& InvitationToken);
	
	/**
	 * @brief Kick a party member.
	 * 
	 * @param UserId The target user ID to be kicked.
	 */
	FString SendKickPartyMemberRequest(const FString& UserId);

	/**
	 * @brief Generate and Get Party code.
	 * 
	 */
	FString SendPartyGetCodeRequest();

	/**
	 * @brief Remove Party invite code.
	 * 
	 */
	FString SendPartyDeleteCodeRequest();

	/**
	 * @brief Join Party via party code.
	 * 
	 * @param partyCode The target party Code to be joined.
	 */
	FString SendPartyJoinViaCodeRequest(const FString& partyCode);

	/**
	 * @brief Get a list of online users in the Lobby server.
	 */
    FString SendGetOnlineUsersRequest();

	/**
	 * @brief Promote party member to party leader.
	 * 
	 * @param UserId The target user ID to be promoted.
	 */
	FString SendPartyPromoteLeaderRequest(const FString& UserId);

	//------------------------
	// Notification
	//------------------------
	/**
	* @brief Get all pending notification(s) that is sent to user when user is not connected to lobby. Please call this function after user connected to lobby.
	*
	*/
	void GetAllAsyncNotification();

	// Matchmaking
	/**
	* @brief start the matchmaking
	*
	* @param GameMode The mode that party member want to play.
	* @param ServerName The Local DS name, fill it blank if you don't use Local DS.
	* @param ClientVersion The version of DS, fill it blank to choose the default version.
	* @param Latencies list of servers and their latencies to client, DSM will created the server on one of this list. Fill it blank if you use Local DS.
	* @param PartyAttributes String map custom attributes to be added on matchmaking and also will be passed to ds too. Example: {"Map":"Dungeon1", "Rank":"B", "Stage":"04"}
	* @param TempPartyUserIds UserIDs to form a temporary party with (include user who started the matchmaking). Temporary party will disband when matchmaking finishes.
	* @param ExtraAttributes custom attributes defined in game mode's matching/flexing rule.
	*/
	FString SendStartMatchmaking(FString GameMode, FString ServerName = TEXT(""), FString ClientVersion = TEXT(""), TArray<TPair<FString, float>> Latencies = TArray<TPair<FString, float>>(), TMap<FString, FString> PartyAttributes = TMap<FString, FString>(), TArray<FString> TempPartyUserIds = TArray<FString>(), TArray<FString> ExtraAttributes = TArray<FString>());

	/**
	* @brief start the matchmaking
	*
	* @param GameMode The mode that party member want to play.
	* @param TempPartyUserIds UserIDs to form a temporary party with (include user who started the matchmaking). Temporary party will disband when matchmaking finishes.
	* @param ServerName The Local DS name, fill it blank if you don't use Local DS.
	* @param ClientVersion The version of DS, fill it blank to choose the default version.
	* @param Latencies list of servers and their latencies to client, DSM will created the server on one of this list. Fill it blank if you use Local DS.
	* @param PartyAttributes String map custom attributes to be added on matchmaking and also will be passed to ds too. Example: {"Map":"Dungeon1", "Rank":"B", "Stage":"04"}
	* @param ExtraAttributes custom attributes defined in game mode's matching/flexing rule.
	*/
	FString SendStartMatchmaking(FString GameMode, TArray<FString> TempPartyUserIds, FString ServerName = TEXT(""), FString ClientVersion = TEXT(""), TArray<TPair<FString, float>> Latencies = TArray<TPair<FString, float>>(), TMap<FString, FString> PartyAttributes = TMap<FString, FString>(), TArray<FString> ExtraAttributes = TArray<FString>());

	/**
	* @brief start the matchmaking
	*
	* @param GameMode The mode that party member want to play.
	* @param PartyAttributes String map custom attributes to be added on matchmaking and also will be passed to ds too. Example: {"Map":"Dungeon1", "Rank":"B", "Stage":"04"}
	* @param ServerName The Local DS name, fill it blank if you don't use Local DS.
	* @param ClientVersion The version of DS, fill it blank to choose the default version.
	* @param Latencies list of servers and their latencies to client, DSM will created the server on one of this list. Fill it blank if you use Local DS.
	* @param TempPartyUserIds UserIDs to form a temporary party with (include user who started the matchmaking). Temporary party will disband when matchmaking finishes.
	* @param ExtraAttributes custom attributes defined in game mode's matching/flexing rule.
	*/
	FString SendStartMatchmaking(FString GameMode, TMap<FString, FString> PartyAttributes, FString ServerName = TEXT(""), FString ClientVersion = TEXT(""), TArray<TPair<FString, float>> Latencies = TArray<TPair<FString, float>>(), TArray<FString> TempPartyUserIds = TArray<FString>(), TArray<FString> ExtraAttributes = TArray<FString>());

	/**
	* @brief start the matchmaking
	*
	* @param GameMode The mode that party member want to play.
	* @param PartyAttributes String map custom attributes to be added on matchmaking and also will be passed to ds too. Example: {"Map":"Dungeon1", "Rank":"B", "Stage":"04"}
	* @param TempPartyUserIds UserIDs to form a temporary party with (include user who started the matchmaking). Temporary party will disband when matchmaking finishes.
	* @param ServerName The Local DS name, fill it blank if you don't use Local DS.
	* @param ClientVersion The version of DS, fill it blank to choose the default version.
	* @param Latencies list of servers and their latencies to client, DSM will created the server on one of this list. Fill it blank if you use Local DS.
	* @param ExtraAttributes custom attributes defined in game mode's matching/flexing rule.
	*/
	FString SendStartMatchmaking(FString GameMode, TMap<FString, FString> PartyAttributes, TArray<FString> TempPartyUserIds, FString ServerName = TEXT(""), FString ClientVersion = TEXT(""), TArray<TPair<FString, float>> Latencies = TArray<TPair<FString, float>>(), TArray<FString> ExtraAttributes = TArray<FString>());

	/**
	* @brief cancel the currently running matchmaking process
	*
	* @param GameMode The mode that party member want to cancel.
	* @param IsTemParty Is canceling matchmaking that was started using temporary party.
	*/
	FString SendCancelMatchmaking(FString GameMode, bool IsTempParty = false);

	/**
	* @brief send ready consent request
	*
	* @param MatchId The id of a match user ready to play.
	*/
	FString SendReadyConsentRequest(FString MatchId);

	// Friends
	/**
	* @brief Send request friend request.
	*
	* @param param UserId Targeted user ID.
	*/
	void RequestFriend(FString UserId);

	/**
	* @brief Send unfriend request.
	*
	* @param UserId Targeted user ID.
	*/
	void Unfriend(FString UserId);

	/**
	* @brief Send list of outgoing friends request.
	*/
	void ListOutgoingFriends();

	/**
	* @brief Send cancel friend request.
	*
	* @param UserId Targeted user ID.
	*/
	void CancelFriendRequest(FString UserId);

	/**
	* @brief Send list of incoming friends request.
	*/
	void ListIncomingFriends();

	/**
	* @brief Send accept friend request.
	*/
	void AcceptFriend(FString UserId);

	/**
	* @brief Send reject friend request.
	*/
	void RejectFriend(FString UserId);

	/**
	* @brief Send load friends list request.
	*/
	void LoadFriendsList();

	/**
	* @brief Send get friendship status request.
	*
	* @param UserId Targeted user ID.
	*/
	void GetFriendshipStatus(FString UserId);


	/*
	 * @brief Block specified player from being able to do certain action against current user
	 * the specified player will be removed from friend list
	 * 
	 * Action that blocked player can't do : 
	 * -Add Friend
	 * -Direct Chat
	 * -Invite to Party
	 * -Invite to Group
	 * -Matchmaking as one alliance
	 * 
	 *	Additional Limitation : 
	 *	Blocked Player can't access blocker/current user's user ID
	 *  
	 * @param UserID the specified player's user ID. (Target to block)
	 * 
	 */
	 void BlockPlayer(const FString& UserId);

	 /**
	  * @brief Unblock specified player enabling them to do certain action against current user
	  *
	  * Action that unblocked player can do :
	  * -Add Friend
	  * -Direct Chat
	  * -Invite to Party
	  * -Invite to Group
	  * -Matchmaking as one alliance
	  *  
	  *	Additional Limitation :
	  *	Unblocked Player can now access blocker/current user's user ID
	  *
	  * @param UserID the specified player's user ID. (Target to block)
	  *
	  */
	 void UnblockPlayer(const FString& UserId);

	/**
	 * @brief Send a signaling message to another user.
	 *
	 * @param UserId The recipient's user ID.
	 * @param Message Signaling message to be sent.
	 */
	FString SendSignalingMessage(const FString& UserId, const FString& Message);

	/**
	 * @brief Set user attribute to lobby session. 
	 *
	 * @param Key the attribute's key.
	 * @param Value the attribute's value.
	 */
	FString SetSessionAttribute(const FString& Key, const FString& Value);

	/**
	 * @brief Get user attribute from lobby session.
	 *
	 * @param Key the attribute's key.
	 */
	FString GetSessionAttribute(const FString& Key);

	/**
	 * @brief Get all user attribute from lobby session.
	 */
	FString GetAllSessionAttribute();

	/**
	* @brief Unbind all delegates set previously.
	*/
	void UnbindEvent();

	void SetConnectSuccessDelegate(const FConnectSuccess& OnConnectSuccess)
	{
		ConnectSuccess = OnConnectSuccess;
	}
	void SetConnectFailedDelegate(const FErrorHandler& OnConnectError)
	{
		ConnectError = OnConnectError;
	}
	void SetDisconnectNotifDelegate(const FDisconnectNotif OnDisconnectNotice)
	{
		DisconnectNotif = OnDisconnectNotice;
	}
	void SetConnectionClosedDelegate(const FConnectionClosed& OnConnectionClosed)
	{
		ConnectionClosed = OnConnectionClosed;
	}
	void SetPartyLeaveNotifDelegate(const FPartyLeaveNotif& OnLeavePartyNotice)
	{
		PartyLeaveNotif = OnLeavePartyNotice;
	}
	void SetPartyInviteNotifDelegate(const FPartyInviteNotif& OnPartyInviteNotif)
	{
		PartyInviteNotif = OnPartyInviteNotif;
	}
	void SetPartyGetInvitedNotifDelegate(const FPartyGetInvitedNotif& OnInvitePartyGetInvitedNotice)
	{
		PartyGetInvitedNotif = OnInvitePartyGetInvitedNotice;
	}
	void SetPartyJoinNotifDelegate(const FPartyJoinNotif& OnInvitePartyJoinNotice)
	{
		PartyJoinNotif = OnInvitePartyJoinNotice;
	}
	void SetPartyInvitationRejectedNotifDelegate(const FPartyRejectNotif& OnInvitePartyRejectNotice)
	{
		PartyRejectNotif = OnInvitePartyRejectNotice;
	}
	void SetPartyKickNotifDelegate(const FPartyKickNotif& OnInvitePartyKickedNotice)
	{
		PartyKickNotif = OnInvitePartyKickedNotice;
	}
	void SetPrivateMessageNotifDelegate(FPersonalChatNotif OnPersonalChatNotif)
	{
		PersonalChatNotif = OnPersonalChatNotif;
	};
	void SetPartyChatNotifDelegate(FPartyChatNotif OnPersonalChatNotif)
	{
		PartyChatNotif = OnPersonalChatNotif;
	}
	void SetUserPresenceNotifDelegate(FFriendStatusNotif OnUserPresenceNotif)
	{
		FriendStatusNotif = OnUserPresenceNotif;
	};
	void SetMessageNotifDelegate(const FMessageNotif& OnNotificationMessage)
	{
		MessageNotif = OnNotificationMessage;
	}
	void SetOnFriendRequestAcceptedNotifDelegate(const FAcceptFriendsNotif& OnAcceptFriendsNotif)
	{
		AcceptFriendsNotif = OnAcceptFriendsNotif;
	}
	void SetOnIncomingRequestFriendsNotifDelegate(const FRequestFriendsNotif& OnRequestFriendsNotif)
	{
		RequestFriendsNotif = OnRequestFriendsNotif;
	}
	void SetOnUnfriendNotifDelegate(const FUnfriendNotif& OnUnfriendNotif)
	{
		UnfriendNotif = OnUnfriendNotif;
	}
	void SetOnCancelFriendsNotifDelegate(const FCancelFriendsNotif& OnCancelFriendsNotif)
	{
		CancelFriendsNotif = OnCancelFriendsNotif;
	}
	void SetOnRejectFriendsNotifDelegate(const FRejectFriendsNotif& OnRejectFriendsNotif) 
	{
		RejectFriendsNotif = OnRejectFriendsNotif;
	}
	void SetParsingErrorDelegate(const FErrorHandler& OnParsingError)
	{
		ParsingError = OnParsingError;
	}

	// Party
	/**
	* @brief set info party response
	*
	* @param OnInfoPartyResponse set delegate .
	*/
	void SetInfoPartyResponseDelegate(FPartyInfoResponse OnInfoPartyResponse)
	{
		PartyInfoResponse = OnInfoPartyResponse;
	};

	/**
	* @brief create party response delegate
	*
	* @param OnCreatePartyResponse set delegate .
	*/
	void SetCreatePartyResponseDelegate(FPartyCreateResponse OnCreatePartyResponse)
	{
		PartyCreateResponse = OnCreatePartyResponse;
	};

	/**
	* @brief set leave party response delegate
	*
	* @param OnLeavePartyResponse set delegate .
	*/
	void SetLeavePartyResponseDelegate(FPartyLeaveResponse OnLeavePartyResponse)
	{
		PartyLeaveResponse = OnLeavePartyResponse;
	};

	/**
	* @brief set invite party response delegate
	*
	* @param OnInvitePartyResponse set delegate .
	*/
	void SetInvitePartyResponseDelegate(FPartyInviteResponse OnInvitePartyResponse)
	{
		PartyInviteResponse = OnInvitePartyResponse;
	};

	/**
	* @brief set invite party join response
	*
	* @param OnInvitePartyJoinResponse set delegate .
	*/
	void SetInvitePartyJoinResponseDelegate(FPartyJoinResponse OnInvitePartyJoinResponse)
	{
		PartyJoinResponse = OnInvitePartyJoinResponse;
	};
	
	/**
	* @brief set invite party reject response
	*
	* @param OnInvitePartyRejectResponse set delegate .
	*/
	void SetInvitePartyRejectResponseDelegate(FPartyRejectResponse OnInvitePartyRejectResponse)
	{
		PartyRejectResponse = OnInvitePartyRejectResponse;
	};

	/**
	* @brief set invite party kick member reponse
	*
	* @param OnInvitePartyKickMemberResponse set delegate .
	*/
	void SetInvitePartyKickMemberResponseDelegate(FPartyKickResponse OnInvitePartyKickMemberResponse)
	{
		PartyKickResponse = OnInvitePartyKickMemberResponse;
	};

	void SetPartyDataUpdateResponseDelegate(FPartyDataUpdateNotif OnPartyDataUpdateResponse) 
	{
		PartyDataUpdateNotif = OnPartyDataUpdateResponse;
	};

	/**
	* @brief get party code reponse
	*
	* @param OnPartyGetCodeResponse set delegate .
	*/
	void SetPartyGetCodeResponseDelegate(FPartyGetCodeResponse OnPartyGetCodeResponse)
	{
		PartyGetCodeResponse = OnPartyGetCodeResponse;
	};

	/**
	* @brief delete party code reponse
	*
	* @param OnPartyDeleteCodeResponse set delegate .
	*/
	void SetPartyDeleteCodeResponseDelegate(FPartyDeleteCodeResponse OnPartyDeleteCodeResponse)
	{
		PartyDeleteCodeResponse = OnPartyDeleteCodeResponse;
	};

	/**
	* @brief join party via party code reponse
	*
	* @param OnPartyJoinViaCodeResponse set delegate .
	*/
	void SetPartyJoinViaCodeResponseDelegate(FPartyJoinViaCodeResponse OnPartyJoinViaCodeResponse)
	{
		PartyJoinViaCodeResponse = OnPartyJoinViaCodeResponse;
	};

	/**
	* @brief set promote party leader reponse
	*
	* @param OnPromotePartyLeaderResponse set delegate .
	*/
	void SetPartyPromoteLeaderResponseDelegate(FPartyPromoteLeaderResponse OnPartyPromoteLeaderResponse)
	{
		PartyPromoteLeaderResponse = OnPartyPromoteLeaderResponse;
	};

	// Chat
	/**
	* @brief set private message delegate
	*
	* @param OnPrivateMessageResponse set delegate .
	*/
	void SetPrivateMessageResponseDelegate(FPersonalChatResponse OnPrivateMessageResponse)
	{
		PersonalChatResponse = OnPrivateMessageResponse;
	};

	/**
	* @brief set party message response
	*
	* @param OnPartyMessageResponse set delegate .
	*/
	void SetPartyMessageResponseDelegate(FPartyChatResponse OnPartyMessageResponse)
	{
		PartyChatResponse = OnPartyMessageResponse;
	};

	/**
	* @brief set join channel chat response
	*
	* @param OnJoinDefaultChannelResponse set delegate.
	*/
	void SetJoinChannelChatResponseDelegate(FJoinDefaultChannelChatResponse OnJoinDefaultChannelResponse)
	{
		JoinDefaultChannelResponse = OnJoinDefaultChannelResponse;
	};

	/**
	* @brief set channel message response
	*
	* @param OnChannelMessageResponse set delegate.
	*/
	void SetChannelMessageResponseDelegate(FChannelChatResponse OnChannelMessageResponse)
	{
		ChannelChatResponse = OnChannelMessageResponse;
	};

	/**
	* @brief set channel message notif
	*
	* @param OnChannelMessageNotif set delegate.
	*/
	void SetChannelMessageNotifDelegate(FChannelChatNotif OnChannelMessageNotif)
	{
		ChannelChatNotif = OnChannelMessageNotif;
	}

	// Presence
	/**
	* @brief set user presence response
	*
	* @param OnSetUserPresenceResponse set delegate .
	*/
	void SetUserPresenceResponseDelegate(FSetUserPresenceResponse OnSetUserPresenceResponse)
	{
		SetUserPresenceResponse = OnSetUserPresenceResponse;
	};

	/**
	* @brief set info party response
	*
	* @param OnGetAllUserPresenceResponse set delegate .
	*/
	void SetGetAllUserPresenceResponseDelegate(FGetAllFriendsStatusResponse OnGetAllUserPresenceResponse)
	{
		GetAllFriendsStatusResponse = OnGetAllUserPresenceResponse;
	};

	// Notification

	// Matchmaking
	/**
	* @brief set start matchmaking response
	*
	* @param OnMatchmakingStart set delegate .
	*/
	void SetStartMatchmakingResponseDelegate(FMatchmakingResponse OnMatchmakingStart)
	{
		MatchmakingStartResponse = OnMatchmakingStart;
	};

	/**
	* @brief set cancel matchmaking notification
	*
	* @param OnMatchmakingCancel set delegate .
	*/
	void SetCancelMatchmakingResponseDelegate(FMatchmakingResponse OnMatchmakingCancel)
	{
		MatchmakingCancelResponse = OnMatchmakingCancel;
	};

	/**
	* @brief set ready consent response notification
	*
	* @param OnReadyConsentResponse set delegate .
	*/
	void SetReadyConsentResponseDelegate(FReadyConsentResponse OnReadyConsentResponse)
	{
		ReadyConsentResponse = OnReadyConsentResponse;
	};

	/**
	* @brief set matchmaking notification
	*
	* @param OnMatchmakingNotification set delegate .
	*/
	void SetMatchmakingNotifDelegate(FMatchmakingNotif OnMatchmakingNotification)
	{
		MatchmakingNotif = OnMatchmakingNotification;
	};

	/**
	* @brief set ready consent notification
	*
	* @param OnReadyConsentNotification set delegate .
	*/
	void SetReadyConsentNotifDelegate(FReadyConsentNotif OnReadyConsentNotification)
	{
		ReadyConsentNotif = OnReadyConsentNotification;
	};

	/**
	* @brief set rematchmaking notification
	*
	* @param OnRematchmakingNotification set delegate .
	*/
	void SetRematchmakingNotifDelegate(FRematchmakingNotif OnRematchmakingNotification)
	{
		RematchmakingNotif = OnRematchmakingNotification;
	};

	/**
	* @brief set ready consent notification
	*
	* @param OnReadyConsentNotification set delegate .
	*/
	void SetDsNotifDelegate(FDsNotif OnDsNotification)
	{
		DsNotif = OnDsNotification;
	};

	// Friends
	/**
	* @brief Set request for friends response.
	*
	* @param OnRequestFriendsResponse Delegate that will be set.
	*/
	void SetRequestFriendsResponseDelegate(FRequestFriendsResponse OnRequestFriendsResponse)
	{
		RequestFriendsResponse = OnRequestFriendsResponse;
	};

	/**
	* @brief Set unfriend response.
	*
	* @param OnUnfriendResponse Delegate that will be set.
	*/
	void SetUnfriendResponseDelegate(FUnfriendResponse OnUnfriendResponse)
	{
		UnfriendResponse = OnUnfriendResponse;
	};

	/**
	* @brief Set list outgoing request of friend response.
	*
	* @param OnListOutgoingFriendsResponse Delegate that will be set.
	*/
	void SetListOutgoingFriendsResponseDelegate(FListOutgoingFriendsResponse OnListOutgoingFriendsResponse)
	{
		ListOutgoingFriendsResponse = OnListOutgoingFriendsResponse;
	};

	/**
	* @brief Set cancel request of friend response.
	*
	* @param OnCancelFriendsResponse Delegate that will be set.
	*/
	void SetCancelFriendsResponseDelegate(FCancelFriendsResponse OnCancelFriendsResponse)
	{
		CancelFriendsResponse = OnCancelFriendsResponse;
	};

	/**
	* @brief Set incoming request of friend response.
	*
	* @param OnListIncomingFriendsResponse Delegate that will be set.
	*/
	void SetListIncomingFriendsResponseDelegate(FListIncomingFriendsResponse OnListIncomingFriendsResponse)
	{
		ListIncomingFriendsResponse = OnListIncomingFriendsResponse;
	};

	/**
	* @brief Set accept friend response.
	*
	* @param OnAcceptFriendsResponse Delegate that will be set.
	*/
	void SetAcceptFriendsResponseDelegate(FAcceptFriendsResponse OnAcceptFriendsResponse)
	{
		AcceptFriendsResponse = OnAcceptFriendsResponse;
	};

	/**
	* @brief Set reject request for friend response.
	*
	* @param OnRejectFriendsResponse Delegate that will be set.
	*/
	void SetRejectFriendsResponseDelegate(FRejectFriendsResponse OnRejectFriendsResponse)
	{
		RejectFriendsResponse = OnRejectFriendsResponse;
	};

	/**
	* @brief Set load friend list response.
	*
	* @param OnLoadFriendListResponse Delegate that will be set.
	*/
	void SetLoadFriendListResponseDelegate(FLoadFriendListResponse OnLoadFriendListResponse)
	{
		LoadFriendListResponse = OnLoadFriendListResponse;
	};

	/**
	* @brief Set get friendship status response.
	*
	* @param OnGetFriendshipStatusResponse Delegate that will be set.
	*/
	void SetGetFriendshipStatusResponseDelegate(FGetFriendshipStatusResponse OnGetFriendshipStatusResponse)
	{
		GetFriendshipStatusResponse = OnGetFriendshipStatusResponse;
	};

	// Player

	void SetBlockPlayerResponseDelegate(FBlockPlayerResponse OnBlockPlayerResponse)
	{
		BlockPlayerResponse = OnBlockPlayerResponse;
	};

	void SetUnblockPlayerResponseDelegate(FUnblockPlayerResponse OnUnblockPlayerResponse)
	{
		UnblockPlayerResponse = OnUnblockPlayerResponse;
	};

	void SetListBlockedUserResponseDelegate(FListBlockedUserResponse OnListBlockedUserResponse)
	{
		ListBlockedUserResponse = OnListBlockedUserResponse;
	};

	void SetListBlockerResponseDelegate(FListBlockerResponse OnListBlockerResponse)
	{
		ListBlockerResponse = OnListBlockerResponse;
	};

	void SetBlockPlayerNotifDelegate(FBlockPlayerNotif OnBlockPlayerNotif)
	{
		BlockPlayerNotif = OnBlockPlayerNotif;
	};

	void SetUnblockPlayerNotifDelegate(FUnblockPlayerNotif OnUnblockPlayerNotif)
	{
		UnblockPlayerNotif = OnUnblockPlayerNotif;
	};

	// Error
	void SetErrorNotifDelegate(FErrorNotif OnErrorNotif)
	{
		ErrorNotif = OnErrorNotif;
	};

	/**
	* @brief Set SignalingP2P delegate.
	*
	* @param OnSignalingP2P Delegate that will be set.
	*/
	void SetSignalingP2PDelegate(FSignalingP2P OnSignalingP2P)
	{
		SignalingP2P = OnSignalingP2P;
	};

	/**
	* @brief Set SetSessionAttribute delegate.
	*
	* @param OnSetSessionAttributeResponse Delegate that will be set.
	*/
	void SetSetSessionAttributeDelegate(FSetSessionAttributeResponse OnSetSessionAttributeResponse)
	{
		SetSessionAttributeResponse = OnSetSessionAttributeResponse;
	};

	/**
	* @brief Set GetSessionAttribute delegate.
	*
	* @param OnSetSessionAttributeResponse Delegate that will be set.
	*/
	void SetGetSessionAttributeDelegate(FGetSessionAttributeResponse OnGetSessionAttributeResponse)
	{
		GetSessionAttributeResponse = OnGetSessionAttributeResponse;
	};

	/**
	* @brief Set SetSessionAttribute delegate.
	*
	* @param OnSetSessionAttributeResponse Delegate that will be set.
	*/
	void SetGetAllSessionAttributeDelegate(FGetAllSessionAttributeResponse OnGetAllSessionAttributeResponse)
	{
		GetAllSessionAttributeResponse = OnGetAllSessionAttributeResponse;
	};

	/**
	* @brief Bulk add friend(s), don't need any confirmation from the player.
	*
	* @param UserIds the list of UserId you want to make friend with.
	* @param OnSuccess This will be called when the operation succeeded.
	* @param OnError This will be called when the operation failed. 
	*/
	void BulkFriendRequest(FAccelByteModelsBulkFriendsRequest UserIds, FVoidHandler OnSuccess, FErrorHandler OnError);

	/**
	* @brief  Get party data by party ID.
	*
	* @param PartyId Targeted party Id.
	* @param OnSuccess This will be called when the operation succeeded. Will return FAccelByteModelsPartyData model.
	* @param OnError This will be called when the operation failed.
	*/
	void GetPartyData(const FString& PartyId, const THandler<FAccelByteModelsPartyData>& OnSuccess, const FErrorHandler& OnError) const;

	/*
	* @brief Bulk Get User(s) Presence, can get specific user's presence status not limited to friend.
	*
	* @param UserIds the list of UserId you want to request.
	* @param OnSuccess This will be called when the operation succeeded. The result is a FAccelByteModelsBulkUserStatusNotif.
	* @param OnError This will be called when the operation failed.
	* @param CountOnly Will only return the status count, without the user's data when set to true.
	*/
	void BulkGetUserPresence(const TArray<FString>& UserIds, const THandler<FAccelByteModelsBulkUserStatusNotif>& OnSuccess, const FErrorHandler& OnError, bool CountOnly = false);


	/**
	* @brief  Get party storage (attributes) by party ID.
	*
	* @param PartyId Targeted party Id.
	* @param OnSuccess This will be called when the operation succeeded. Will return FAccelByteModelsPartyDataNotif model.
	* @param OnError This will be called when the operation failed.
	*/
	void GetPartyStorage(const FString& PartyId, const THandler<FAccelByteModelsPartyDataNotif>& OnSuccess, const FErrorHandler& OnError);

	/**
	* @brief  List Blocked User's Id
	*
	* @param UserId User Id of the Player.
	* @param OnSuccess This will be called when the operation succeeded. Will return FAccelByteModelsListBlockedUserResponse model.
	* @param OnError This will be called when the operation failed.
	*/
	void GetListOfBlockedUsers(const FString& UserId, const THandler<FAccelByteModelsListBlockedUserResponse> OnSuccess, const FErrorHandler& OnError);

	/*
	* @brief List Blocked User's Id, override of GetListOfBlockedUser,
	* will get current user's List of Blocked User's Id
	*
	* @param OnSuccess This will be called when the operation succeeded. Will return FAccelByteModelsListBlockedUserResponse model.
	* @param OnError This will be called when the operation failed.
	*/
	void GetListOfBlockedUsers(const THandler<FAccelByteModelsListBlockedUserResponse> OnSuccess, const FErrorHandler& OnError);

	/**
	* @brief List Id of Player that blocks an User.
	*
	* @param UserId User Id of the Player.
	* @param OnSuccess This will be called when the operation succeeded. Will return FAccelByteModelsListBlockerResponse model.
	* @param OnError This will be called when the operation failed.
	*/
	void GetListOfBlockers(const FString& UserId, const THandler<FAccelByteModelsListBlockerResponse> OnSuccess, const FErrorHandler& OnError);

	/*
	* @brief List Blockers User's Id, override of GetListOfBlocker,
	* will get current user's List of Blocker User's Id
	*
	* @param OnSuccess This will be called when the operation succeeded. Will return FAccelByteModelsListBlockerResponse model.
	* @param OnError This will be called when the operation failed.
	*/

	void GetListOfBlockers(const THandler<FAccelByteModelsListBlockerResponse> OnSuccess, const FErrorHandler& OnError);

	void SendNotificationToUser(const FString& SendToUserId, const FAccelByteModelsFreeFormNotificationRequest& Message, bool bAsync, const FVoidHandler& OnSuccess, const FErrorHandler& OnError);

	/**
	* @brief  Write party storage (attributes) data to the targeted party ID.
	* Beware:
	* Object will not be write immediately, please take care of the original object until it written.
	*
	* @param PartyId Targeted party Id.
	* @param PayloadModifier Function to modify the latest party data with your customized modifier.
	* @param OnSuccess This will be called when the operation succeeded. Will return FAccelByteModelsPartyDataNotif model.
	* @param OnError This will be called when the operation failed.
	* @param RetryAttempt the number of retry to do when there is an error in writing to party storage (likely due to write conflicts).
	*/
	void WritePartyStorage(const FString& PartyId, TFunction<FJsonObjectWrapper(FJsonObjectWrapper)> PayloadModifier, const THandler<FAccelByteModelsPartyDataNotif>& OnSuccess, const FErrorHandler& OnError, uint32 RetryAttempt = 1);

	/**
	* @brief Change the delay parameters to maintain connection in the lobby before lobby connected.
	*
	* @param NewTotalTimeout new Time limit until stop to re-attempt.
	* @param NewBackoffDelay new Initial delay time.
	* @param NewMaxDelay new Maximum delay time.
	*/
	void SetRetryParameters(int32 NewTotalTimeout = 60000, int32 NewBackoffDelay = 1000, int32 NewMaxDelay = 30000);
	
	static FString LobbyMessageToJson(FString Message);

private:
	Lobby(Lobby const&) = delete; // Copy constructor
	Lobby(Lobby&&) = delete; // Move constructor
	Lobby& operator=(Lobby const&) = delete; // Copy assignment operator
	Lobby& operator=(Lobby &&) = delete; // Move assignment operator

	void OnConnected();
	void OnConnectionError(const FString& Error);
	void OnMessage(const FString& Message);
	void OnClosed(int32 StatusCode, const FString& Reason, bool WasClean);

    FString SendRawRequest(FString MessageType, FString MessageIDPrefix, FString CustomPayload = TEXT(""));
    bool Tick(float DeltaTime);
    FString GenerateMessageID(FString Prefix = TEXT(""));
	void CreateWebSocket();

	const float LobbyTickPeriod = 0.5;
	const float PingDelay;
	float InitialBackoffDelay;
	float MaxBackoffDelay;
	float TotalTimeout;
	bool bWasWsConnectionError = false;
	float BackoffDelay;
	float RandomizedBackoffDelay;
	float TimeSinceLastPing;
	float TimeSinceLastReconnect;
	float TimeSinceConnectionLost;
	FString ChannelSlug;
	EWebSocketState WsState;
	EWebSocketEvent WsEvents;
	FTickerDelegate LobbyTickDelegate;
    FDelegateHandle LobbyTickDelegateHandle;
	TSharedPtr<IWebSocket> WebSocket;
	FAccelByteModelsLobbySessionId LobbySessionId;
	FConnectSuccess ConnectSuccess;
	FErrorHandler ConnectError;
    FErrorHandler ParsingError;
	FDisconnectNotif DisconnectNotif;
	FConnectionClosed ConnectionClosed;
	
    // Party 
    FPartyInfoResponse PartyInfoResponse;
    FPartyCreateResponse PartyCreateResponse;
    FPartyLeaveResponse PartyLeaveResponse;
    FPartyLeaveNotif PartyLeaveNotif;
    FPartyInviteResponse PartyInviteResponse;
    FPartyInviteNotif PartyInviteNotif;
    FPartyGetInvitedNotif PartyGetInvitedNotif;
    FPartyJoinResponse PartyJoinResponse;
    FPartyJoinNotif PartyJoinNotif;
    FPartyRejectResponse PartyRejectResponse;
    FPartyRejectNotif PartyRejectNotif;
    FPartyKickResponse PartyKickResponse;
    FPartyKickNotif PartyKickNotif;
	FPartyDataUpdateNotif PartyDataUpdateNotif;
	FPartyGetCodeResponse PartyGetCodeResponse;
	FPartyDeleteCodeResponse PartyDeleteCodeResponse;
	FPartyJoinViaCodeResponse PartyJoinViaCodeResponse;
	FPartyPromoteLeaderResponse PartyPromoteLeaderResponse;

    // Chat
    FPersonalChatResponse PersonalChatResponse;
    FPersonalChatNotif PersonalChatNotif;
    FPartyChatResponse PartyChatResponse;
    FPartyChatNotif PartyChatNotif;
	FJoinDefaultChannelChatResponse JoinDefaultChannelResponse;
	FChannelChatResponse ChannelChatResponse;
	FChannelChatNotif ChannelChatNotif;

    // Presence
    FSetUserPresenceResponse SetUserPresenceResponse;
    FFriendStatusNotif FriendStatusNotif;
    FGetAllFriendsStatusResponse GetAllFriendsStatusResponse;

    // Notification
	FMessageNotif MessageNotif;

    // Matchmaking
	FMatchmakingResponse MatchmakingStartResponse;
	FMatchmakingResponse MatchmakingCancelResponse;
	FReadyConsentResponse ReadyConsentResponse;
    FMatchmakingNotif MatchmakingNotif;
	FReadyConsentNotif ReadyConsentNotif;
	FRematchmakingNotif RematchmakingNotif;
	FDsNotif DsNotif;

	// Friends
	FRequestFriendsResponse RequestFriendsResponse;
	FUnfriendResponse UnfriendResponse;
	FListOutgoingFriendsResponse ListOutgoingFriendsResponse;
	FCancelFriendsResponse CancelFriendsResponse;
	FListIncomingFriendsResponse ListIncomingFriendsResponse;
	FAcceptFriendsResponse AcceptFriendsResponse;
	FRejectFriendsResponse RejectFriendsResponse;
	FLoadFriendListResponse LoadFriendListResponse;
	FGetFriendshipStatusResponse GetFriendshipStatusResponse;

	// Friends + Notification
	FAcceptFriendsNotif AcceptFriendsNotif;
	FRequestFriendsNotif RequestFriendsNotif;
	FUnfriendNotif UnfriendNotif;
	FCancelFriendsNotif CancelFriendsNotif;
	FRejectFriendsNotif RejectFriendsNotif;

	// Block
	FBlockPlayerResponse BlockPlayerResponse;
	FUnblockPlayerResponse UnblockPlayerResponse;
	FListBlockedUserResponse ListBlockedUserResponse;
	FListBlockerResponse ListBlockerResponse;

	// Block + Notification
	FBlockPlayerNotif BlockPlayerNotif;
	FUnblockPlayerNotif UnblockPlayerNotif;

	// Error
	FErrorNotif ErrorNotif;

	struct PartyStorageWrapper
	{
		FString PartyId;
		int RemainingAttempt;
		THandler<FAccelByteModelsPartyDataNotif> OnSuccess;
		FErrorHandler OnError;
		TFunction<FJsonObjectWrapper(FJsonObjectWrapper)> PayloadModifier;
	};

	void RequestWritePartyStorage(const FString& PartyId, const FAccelByteModelsPartyDataUpdateRequest& Data, const THandler<FAccelByteModelsPartyDataNotif>& OnSuccess, const FErrorHandler& OnError, FSimpleDelegate OnConflicted = NULL);

	void WritePartyStorageRecursive(TSharedPtr<PartyStorageWrapper> DataWrapper);

	//Signaling P2P
	FSignalingP2P SignalingP2P;

	//Session Attribute
	FSetSessionAttributeResponse SetSessionAttributeResponse;
	FGetSessionAttributeResponse GetSessionAttributeResponse;
	FGetAllSessionAttributeResponse GetAllSessionAttributeResponse;
};

} // Namespace Api
} // Namespace AccelByte
