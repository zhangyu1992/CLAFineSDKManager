//
//  RTCEngine.h
//  FineSdk
//
//  Created by 张俞 on 2021/6/29.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#import <FineSdk/RTCError.h>
#import <FineSdk/RTCFormat.h>
#import <FineSdk/RTCRoomInfo.h>
#import <FineSdk/RTCUserPermission.h>
#import <FineSdk/RTCRoomLayoutInfo.h>
#import <FineSdk/RTCParticipantInfo.h>
#import <FineSdk/RTCMessageModel.h>


NS_ASSUME_NONNULL_BEGIN

@interface RTCEngine : NSObject

- (instancetype)init NS_UNAVAILABLE;
/// 房间ID
@property (nonatomic, copy, readonly) NSString * roomId;

/// 初始化
/// @param roomid roomid必传
- (instancetype)initWithRoomId:(NSString *)roomid;

/// 获取sessiontoken
- (NSString *)getSessionToken;

////////////////////////////// 以下是本人可以做的操作 ///////////////////////////////

/// 打开/关闭 本地音频
/// isMute = YES：关闭音频 =NO：打开音频
- (void)muteLocalAudio:(BOOL)isMute OnSuccess:(void(^)(void))success OnFailed:(void(^)(RTCError *))failed;

/// 打开/关闭 本地视频
- (void)muteLocalVideo:(BOOL)isMute OnSuccess:(void(^)(void))success OnFailed:(void(^)(RTCError *))failed;

/// 打开/关闭 本地共享音频
- (void)muteLocalShareAudio:(BOOL)isMute;

/// 开始本地摄像头采集
/// @param success 成功回调
- (void)startLocalCameraCapture:(void(^)(AVCaptureVideoPreviewLayer * cameraLayer))success;

/// 停止本地摄像头采集
/// @param success 成功回调
- (void)stopLocalCameraCapture:(void(^)(void))success;

/// 重置摄像头方向
/// @param cameraPosition 摄像头方向
- (BOOL)resetLocalCameraPosition:(RTCCameraPosition)cameraPosition;
/// 设置推流前是否将视频加入混流
- (BOOL)resetCameraPublishDefaultAddMixStream:(BOOL)isAdd;
/// 设置推流时音轨状态
- (BOOL)resetLocalStreamAudioTrackEnable:(BOOL)audioTrackEnable;

/// 重置摄像头镜像
- (BOOL)resetCameraVideoMirrored:(BOOL)isVideoMirrored;

/// 获取摄像头是否镜像
- (BOOL)getCameraVideoMirrored;

/// 设置推流视频裁剪比例(横屏不旋转时，不支持裁剪) 默认为0， 不裁剪
- (BOOL)resetLocalStreamCropScale:(CGFloat)cropScale;
/// 是否将裁剪后的分辨率调整为标准（16：9）分辨率 目前只支持540P 360P 默认为NO，不调整
- (BOOL)resetLocalStreamCropAdjustToStandardResolution:(BOOL)isAdjust;

/// 横屏采集视频是否旋转 默认为NO，不旋转
- (BOOL)resetCaptuerVideoLandscapeRotates:(BOOL)landscapeRotates;
/// 静音远端流声音
/// @param isMute YES：静音
/// @param streamType 流类型
- (void)muteRemoteStreamAudio:(BOOL)isMute streamType:(RTCSubscribeStreamType)streamType;

/// 收回主持人权限(前提：会议创建者才可以收回主持人权限)
- (void)revokeAdmin;

/// 申请参会人权限(音频 + 共享)
- (void)applyParticipantAuthWithAuthType:(RTCParticipantAuthType)authType;

/// 发送聊天室消息
- (void)sendMessageToChat:(NSString *)message OnSendingMessageModel:(void(^)(RTCMessageModel * messageModel))sending;

////////////////////////////// 以下是 可以获取到的信息 ///////////////////////////////

/// 从服务器更新组织通讯录到本地数据库
- (void)updateOrganizeListFromServerOnSuccess:(void(^)(void))success OnFailed:(void(^)(RTCError * error))failed;

/// 本地数据库查询一级组织架构信息
- (void)queryFirstLevelDepartmentStructFromLocalDBWithResult:(void (^)(NSMutableArray* array))result;

/// 获取一个组织架构下的下属组织结构信息
- (void)queryChildDepartmentsWithDepartmentId:(NSString*)departmentId
                                    CustomerId:(NSString*)customerId
                                       result:(void (^)(NSMutableArray* array))result;

/// 从服务器更新聊天室消息到本地数据库
/// @param updateTime 更新时间 0：最新时间
/// @param updateCount 更新消息条数
/// @param success 成功回调
/// @param failed 失败回调
- (void)updateChatHistoryMessageFromServerWithUpdateTime:(long long)updateTime
                                         UpdateCount:(NSInteger)updateCount OnSuccess:(void (^)(void))success
                                               OnFailed:(void(^)(RTCError *error))failed;
/// 从本地获取聊天室消息
/// @param page 页数 从1开始
/// @param count 每页的消息数量
/// @param success 成功回调
- (void)queryChatHistoryMessageFromDBWithPage:(NSInteger)page Count:(NSInteger)count OnSuccess:(void(^)(NSArray *))success;

/// 从服务器更新会议信息和参会人列表到本地数据库
/// @param success 成功回调
/// @param failed 失败回调
- (void)updateRoomInfoAndParticipantsFromServerOnSuccess:(void(^)(void))success OnFailed:(void(^)(RTCError * error))failed;

/// 从本地获取参会人列表
/// @param joinedList 已入会列表
/// @param unJoinedList 未入会列表
- (void)getParticipantsFromDBJoinedList:(void(^)(NSArray *  joinedList))joinedList UnJoinedList:(void(^)(NSArray *  unJoinedList))unJoinedList;

/// 从本地获取本人参会信息
/// @param selfPInfo 自己的参会人信息
- (void)getParticipantsFromDBSelfParticipantInfo:(void(^)(RTCParticipantInfo *  selfPInfo))selfPInfo;

/// 从本地获取获取房间信息
- (void)getRoomInfoOnSuccess:(void(^)(RTCRoomInfo * roomInfo))success OnFailed:(void(^)(RTCError *))failed;


/// 获取账号配置
- (void)getQueryUserPermissionOnSuccess:(void(^)(RTCUserPermission * userPermission))success OnFailed:(void(^)(RTCError *))failed;

/// 获取语音激励状态
- (void)getvoiceActiveEnabledOnSuccess:(void(^)(BOOL isOn))success OnFailed:(void(^)(RTCError *))failed;

/// 获取轮巡时间
- (void)getRoomViewIntervalOnSuccess:(void(^)(RTCRoomViewInterval viewInterval))success OnFailed:(void(^)(RTCError *))failed;

/// 获取布局池信息(未用)
- (void)getRoomLayoutPoolInfoOnSuccess:(void (^)(NSDictionary * allLayoutDict))success OnFailed:(void(^)(RTCError *))failed;

/// 获取房间布局设置
/// @param success isauto：是否是自动布局 layoutType：当前显示的布局类型
/// @param failed 失败回调
- (void)getRoomLayoutSettingsOnSuccess:(void(^)(BOOL isAuto,RTCLayoutType layoutType))success OnFailed:(void(^)(RTCError *))failed;

/// 获取指定类型的布局信息 指定参会人按顺序排列
- (void)getLayoutInfoWithLayoutType:(RTCLayoutType)layoutType OnSuccess:(void(^)(RTCRoomLayoutInfo *))success OnFailed:(void(^)(RTCError *))failed;



@end

NS_ASSUME_NONNULL_END
