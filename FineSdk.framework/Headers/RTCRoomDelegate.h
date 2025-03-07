//
//  RTCRoomDelegate.h
//  FineSdk
//
//  Created by 张俞 on 2021/7/2.
//

#import <Foundation/Foundation.h>
#import <FineSdk/RTCFormat.h>
#import <FineSdk/RTCRoomLayoutInfo.h>
#import <FineSdk/RTCParticipantInfo.h>
#import <FineSdk/RTCMessageModel.h>
#import <FineSdk/RTCStreamInfo.h>


NS_ASSUME_NONNULL_BEGIN


//////////////// 会议室相关回调方法 ///////////////
@protocol RTCRoomDelegate <NSObject>

/// 会议室权限改变
/// @param roomAuthType 权限类型
/// @param result 权限结果 YES：有权限 NO：无权限
- (void)onRoomAuthority:(RTCRoomAuthType)roomAuthType didChangedWithResult:(BOOL)result ExcludeParticipantIdsArray:(NSArray*)participantIdsArray;

/// 会议录制开始/结束
/// @param recordStatus YES：开始录制 NO：结束录制
- (void)onRoomRecordStatusDidChaned:(BOOL)recordStatus;

/// 布局改变通知
/// @param LayoutInfo 布局信息
- (void)onRoomLayoutDidChanged:(RTCRoomLayoutInfo *)LayoutInfo;

/// 远端流加入会议
/// @param streamType 流类型
- (void)remoteStreamDidJoinRoom:(RTCSubscribeStreamType)streamType WithShareStreamInfo:(RTCShareStreamInfo *)shareStreamInfo;

/// 远端流离开会议
/// @param streamType 类类型
- (void)remoteStreamDidLeaveRoom:(RTCSubscribeStreamType)streamType WithShareStreamInfo:(RTCShareStreamInfo *)shareStreamInfo;

/// 会议将要结束
- (void)onRoomWillBeEnd;

/// 会议结束
- (void)onRoomDidEnd;

/// 会议socket连接状态改变
/// @param connectionStatus 连接状态
- (void)onRoomSocketConnectionDidChangedToConnectionStatus:(RTCSocketConnectionStatus)connectionStatus;

/// 会议推流 ice状态改变
/// @param streamType 流类型
/// @param connectionStatus 连接状态
- (void)onRoomPublishStreamType:(RTCPublishStreamType)streamType DidChangedICEConnectionStatus:(RTCICEConnectionStatus)connectionStatus;

/// 会议订阅 ice状态改变
/// @param streamType 流类型
/// @param connectionStatus 连接状态
- (void)onRoomSubscribeStreamType:(RTCSubscribeStreamType)streamType DidChangedICEConnectionStatus:(RTCICEConnectionStatus)connectionStatus;


@end


////////////////////// 主持人相关回调方法 /////////////////////////////
@protocol RTCRoomHostDelegate <NSObject>
/// 收到参会人申请入会消息
/// @param participantInfo 参会人信息
- (void)onParticipantApplyJoinRoom:(RTCParticipantInfo *)participantInfo;

/// 有参会人申请权限
/// @param participantId 参会人id
/// @param pAuthType 权限类型
- (void)onParticipant:(NSString *)participantId ApplyAuthority:(RTCParticipantApplyType)pAuthType;

/// 参会人回复邀请结果
/// @param participantId 参会人id
/// @param inviteResult 邀请结果
- (void)onParticipant:(NSString *)participantId InviteResult:(RTCInviteResult)inviteResult;

@end

///////////////////////// 参会人相关回调方法 //////////////////////
@protocol RTCRoomParticipantDelegate <NSObject>
/// 参会人加入会议
/// @param participantInfo 参会人信息
- (void)onParticipantJoined:(RTCParticipantInfo *)participantInfo;

/// 参会人离开会议
/// @param participantInfo 参会人新
- (void)onParticipantLeft:(RTCParticipantInfo *)participantInfo;

/// 参会人权限改变
/// @param participantId 参会人id
/// @param pAuthType 权限类型
/// @param result 权限结果 YES：有权限 NO：无权限
- (void)onParticipant:(NSString *)participantId Authority:(RTCParticipantAuthType)pAuthType didChangedWithResult:(NSInteger)result;

/// 参会人音频状态改变
/// @param participantId 参会人id
/// @param isSelf 是否是本人
/// @param audioStatus 音频状态
- (void)onParticipant:(NSString *)participantId IsSelf:(BOOL)isSelf didChangedAudioStatus:(RTCAudioStatus)audioStatus;

/// 参会人视频状态改变
/// @param participantId 参会人id
/// @param isSelf 是否是本人
/// @param videoStatus 视频状态
- (void)onParticipant:(NSString *)participantId IsSelf:(BOOL)isSelf didChangedVideoStatus:(RTCVideoStatus)videoStatus;


/// 参会人 音量改变
/// @param participantId 参会人id
/// @param volume 音量
- (void)onParticipant:(NSString *)participantId didChangedAudioVolume:(NSInteger)volume;

/// 主持人身份改变
/// @param participantId 参会人id
/// @param changedType 身份转移类型
- (void)onRoomHostDidChanedToParticipant:(NSString *)participantId WithHostChangedType:(RTCHostChangedType)changedType;


/// 自己被从会议踢掉原因
/// @param kickedReason 踢掉原因
- (void)onParticipantKickedFromRoomReason:(RTCParticipantKickedReason)kickedReason;


/// 接收到聊天室消息
/// @param messageModel 消息
- (void)onReceiveChatMessage:(RTCMessageModel *)messageModel;

/// 接收到聊天室发送消息状态改变
/// @param messageStatus 消息状态
/// @param messageId 消息id
- (void)onParticipantReceiveChatSendMessageStatusChanged:(RTCMessageStatus)messageStatus MessageId:(NSString *)messageId;

@end


NS_ASSUME_NONNULL_END
