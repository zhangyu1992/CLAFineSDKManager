//
//  RTCCompereEngine.h
//  FineSdk
//
//  Created by 张俞 on 2021/7/15.
//

#import <FineSdk/RTCEngine.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCCompereEngine : RTCEngine

////////////////////////////// 以下是 主持人可以对会议进行的操作 ///////////////////////////////
/// 结束会议
- (void)interruptRoomOnSuccess:(void(^)(void))success OnFailed:(void(^)(RTCError * rtcError))failed;

/// 设置会议权限（只修改权限）
/// @param authType 权限类型
/// @param auth 权限值：YES：有权限 NO：没有权限
- (void)setRoomAuthWithAuthType:(RTCRoomAuthType)authType ToAuthValue:(BOOL)auth OnSuccess:(void(^)(void))success OnFailed:(void(^)(RTCError *))failed;

/// 静音房间(修改权限并且修改音频状态会排除有演示权的嘉宾)
/// @param ismute YES:静音 NO:解除静音
/// @param success 成功回调
/// @param failed 失败回调
- (void)muteRoomAudio:(BOOL)ismute OnSuccess:(void(^)(void))success OnFailed:(void(^)(RTCError *))failed;

/// 开启/停止 录像
- (void)setRoomRecordStatus:(BOOL)isStartReport OnSuccess:(void(^)(void))success OnFailed:(void(^)(RTCError *))failed;

/// 设置自动布局
- (void)setAutoVideoLayoutOnSuccess:(void(^)(void))success OnFailed:(void(^)(RTCError *))failed;

/// 设置手动布局
/// @param roomLayoutInfo 布局信息
/// @param success 成功回调
/// @param failed 失败回调
- (void)setManualVideoLayoutWithRoomLayoutInfo:(RTCRoomLayoutInfo *)roomLayoutInfo success:(void(^)(void))success failed:(void(^)(RTCError *))failed;

/// 设置房间轮巡时间
- (void)setRoomViewInterval:(RTCRoomViewInterval)interval OnSuccess:(void(^)(void))success  OnFailed:(void(^)(RTCError *))failed;


/// 设置语音激励状态
- (void)setVoiceActiveEnable:(BOOL)enable OnSuccess:(void(^)(void))success OnFailed:(void(^)(RTCError *))failed;


////////////////////////////// 以下是 主持人可以对参会人进行的操作 /////////////////////////////

/// 回复参会人 申请入会
/// @param participantId 参会人id
/// @param isAgree 是否同意入会
/// @param success 成功回调
/// @param failed 失败回调
- (void)replyParticipant:(NSString *)participantId ApplyJoinRoomResult:(BOOL)isAgree OnSuccess:(void(^)(void))success OnFailed:(void(^)(RTCError *))failed;

/// 设置参会人权限
/// @param participantId 参会人id
/// @param authType 权限类型
/// @param authValue 权限值
/// @param failed 失败回调
- (void)setParticipantAuthWithParticipantId:(NSString *)participantId AuthType:(RTCParticipantAuthType)authType AuthValue:(BOOL)authValue OnFailed:(void(^)(RTCError *))failed;

/// 静音其他参会人
- (BOOL)muteAudio:(BOOL)ismute WithParticipantId:(NSString *)participantId OnSuccess:(void(^)(void))success OnFailed:(void(^)(RTCError *))failed;

/// 开关其他参会人视频
- (BOOL)muteVideo:(BOOL)ismute WithParticipantId:(NSString *)participantId OnSuccess:(void(^)(void))success OnFailed:(void(^)(RTCError *))failed;

/// 转移主持人身份
- (BOOL)changeHostRoleToParticipant:(NSString *)participantId OnFailed:(void(^)(RTCError *))failed;

/// 踢出参会人（请出会议）
- (void)kickoutParticipant:(NSString *)participantId OnSuccess:(void(^)(void))success OnFailed:(void(^)(RTCError *))failed;

/// 邀请单个参会人
/// @param participantId 参会人id
/// @param success 成功回调
/// @param failed 失败回调
- (void)inviteParticipantToJoinRoomWithParticipantId:(NSString * )participantId OnSuccess:(void(^)(void))success OnFailed:(void(^)(RTCError *))failed;

/// 邀请多个参会人
/// @param inviteArray 参会人id数组
/// @param success 成功回调
/// @param failed 失败回调
- (void)inviteParticipantToJoinRoomWithInviteArray:(NSArray * )inviteArray OnSuccess:(void(^)(void))success OnFailed:(void(^)(RTCError *))failed;
@end

NS_ASSUME_NONNULL_END
