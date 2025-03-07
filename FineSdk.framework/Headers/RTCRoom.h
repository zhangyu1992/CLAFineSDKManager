//
//  RTCRoom.h
//  FineSdk
//
//  Created by 张俞 on 2021/7/15.
//

#import <FineSdk/RTCCompereEngine.h>
#import <FineSdk/RTCRoomDelegate.h>

#import <FineSdk/RTCStatsInfo.h>
#import <FineSdk/RTCSubscribeConfig.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCRoom : RTCCompereEngine
/// 设置RTCRoomDelegate代理对象
- (void)setRoomDelegate:(id<RTCRoomDelegate>)roomDelegate;
/// 设置RTCRoomHostDelegate代理对象
- (void)setRoomHostDelegate:(id<RTCRoomHostDelegate>)hostDelegate;
/// 设置RTCRoomParticipantDelegate代理对象
- (void)setRoomParticipantDelegate:(id<RTCRoomParticipantDelegate>)participantDelegate;

/// 离开会议(**此方法只离开会议，RTSDK中离开会议方法成功后会自动退出游客登录**)
/// @param success 离开会议成功回调
/// @param failed 离开会议失败回调
- (BOOL)leaveRoomSuccess:(void(^)(void))success Failed:(void(^)(RTCError * error))failed;

/// 将本地摄像头流 推送到服务器
/// @param trackType 流包含的轨道类型 默认是音轨+视轨
/// @param success 成功回调
/// @param failure 失败回调
- (void)publishLocalStreamToServerWithStreamTrackType:(RTCStreamTrackType)trackType OnSuccess:(void(^)(void))success OnFailure:(void(^)(NSError * _Nonnull error))failure;

/// 停止本地流(摄像头/共享) 推送到服务器
/// @param publishStreamType 推送的流类型
/// @param success 成功回调
/// @param failure 失败回调
- (void)stopPublishStreamWithPublishStreamType:(RTCPublishStreamType)publishStreamType OnSuccess:(void(^)(void))success OnFailure:(void(^)(NSError * _Nonnull error))failure;


/// 设置本地流(摄像头/共享) 发送视频质量
/// @param preference 流畅、自动、质量
/// @param publishStreamType 推送的流类型
- (void)resetDegradationPreference:(RTCDegradationPreference)preference PublishStreamType:(RTCPublishStreamType)publishStreamType;

/// 获取本地流(摄像头/共享) 发送视频质量
/// @param publishStreamType 推送的流类型
- (RTCDegradationPreference)getDegradationPreferenceWithPublishStreamType:(RTCPublishStreamType)publishStreamType;

/// 设置本地摄像头流 视频发送分辨率
/// @param resolution 分辨率
- (BOOL)resetCameraPublishResolution:(RTCCameraPublishResolution)resolution;

/// 获取本地摄像头流 视频发送分辨率
- (RTCCameraPublishResolution)getCameraPublishResolution;

/// 获取推流(摄像头/共享) 统计信息
/// @param streamType 推送的流类型
/// @param audioStatsInfo 统计音频信息
/// @param videoStatsInfo 统计视频信息
- (void)getLocalPublishStatsWithPublishStreamType:(RTCPublishStreamType)streamType AudioReport:(void(^)(RTCStatsInfo *))audioStatsInfo VideoStatsInfo:(void(^)(RTCStatsInfo *))videoStatsInfo;

/// 检查当前是否有订阅
/// @param streamType 流类型
- (BOOL)checkSubscriptionStatusWithStreamType:(RTCSubscribeStreamType)streamType;

/// 订阅远端流(混流/共享/单路)
/// @param subscribeConfig 订阅配置
/// @param success 成功返回 流渲染视图
/// @param failure 失败回调
- (void)subscribeRemoteStreamWithSubscribeConfig:(RTCSubscribeConfig *)subscribeConfig OnSuccess:(void(^)(UIView * streamAttachView))success OnFailure:(void(^)(NSError * _Nullable error))failure;

/// 更新订阅live分辨率
- (void)updateLiveSubscribeResolution:(RTCSubscribeResolution)resolution andVideoRatio:(RTCSubscribeVideoRatio)videoRatio;

/// 取消订阅流(混流/共享/单路)
/// @param streamType 流类型
- (void)unSubscribeWithStreamType:(RTCSubscribeStreamType)streamType;


/// 获取订阅(混流/共享/单路) 统计信息
/// @param streamType 订阅的流类型
/// @param audioStatsInfo 统计音频信息
/// @param videoStatsInfo 统计视频信息
- (void)getRemoteSubscribeStatsWithPublishStreamType:(RTCSubscribeStreamType)streamType AudioReport:(void(^)(RTCStatsInfo *))audioStatsInfo VideoStatsInfo:(void(^)(RTCStatsInfo *))videoStatsInfo;

@end

NS_ASSUME_NONNULL_END
