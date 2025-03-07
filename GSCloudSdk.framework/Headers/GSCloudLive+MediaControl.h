//
//  GSCloudLive+MediaControl.h
//  GSCloudSdk
//
//  Created by 张俞 on 2022/4/27.
//
NS_ASSUME_NONNULL_BEGIN
@interface GSCloudLive (MediaControl)
/// 推流
- (void)publishLocalMediaToLiveOnSuccess:(void(^)(void))success OnFailed:(void(^)(YBError *))failed;
/// 查看本地摄像头视频
- (BOOL)getCameraVideoPreviewLayerOnSuccess:(void(^)(AVCaptureVideoPreviewLayer * cameraLayer))success;
/// 关闭摄像头
- (void)stopCameraOnSuccess:(void(^)(void))success OnFailed:(void(^)(YBError *))failed;

/// 开关本地摄像头
- (void)switchLocalCameraVideoStatus:(BOOL)status OnSuccess:(void(^)(void))success OnFailed:(void(^)(YBError *))failed;
/// 开关本地麦克风
- (void)switchLocalMicAudioStatus:(BOOL)status OnSuccess:(void(^)(void))success OnFailed:(void(^)(YBError *))failed;
/// 开关本地扬声器
- (void)switchLocalSpeakerStatus:(BOOL)status OnSuccess:(void(^)(void))success OnFailed:(void(^)(YBError *))failed;

/// 重置摄像头方向
- (BOOL)resetLocalCameraPositionIsFront:(BOOL)isFront;
/// 设置音轨是否可用(推流前可用)
- (BOOL)beforePublishSetLocalStreamAudioTrackEnable:(BOOL)audioTrackEnable;
/// 设置是否合屏到混流中(推流前可用)
- (BOOL)beforePublishSetLocalStreamIsAddMixStream:(BOOL)isAdd;

/// 重置摄像头镜像
- (BOOL)resetCameraVideoMirrored:(BOOL)isVideoMirrored;
/// 获取摄像头是否镜像
- (BOOL)getCameraVideoMirrored;

/// 设置推流裁剪比例 默认为0 不裁剪
- (BOOL)resetPublishLocalStreamCropScale:(CGFloat)cropScale;
/// 是否将裁剪后的分辨率调整为标准（16：9）分辨率 目前只支持540P 360P 默认为NO，不调整
- (BOOL)resetPublishLocalStreamCropAdjustToStandardResolution:(BOOL)isAdjust;

/// 横屏采集视频是否旋转
- (BOOL)resetCaptuerVideoLandscapeRotates:(BOOL)landscapeRotates;

/// 设置本地摄像头发送视频质量
- (BOOL)resetPublishCameraDegradationPreference:(GSDegradationPreference)preference;
/// 获取本地摄像头发送视频质量
- (GSDegradationPreference)getPublishCameraDegradationPreference;

/// 设置本地摄像头流 视频发送分辨率
- (BOOL)resetCameraPublishResolution:(GSCameraPublishResolution)resolution;
/// 获取本地摄像头流 视频发送分辨率
- (GSCameraPublishResolution)getCameraPublishResolution;

/// 获取摄像头推流统计信息
- (BOOL)getLocalCameraPublishStatsAudioReport:(void(^)(CGStreamStatsInfo * audioStatsInfo))audioStatsInfo VideoStatsInfo:(void(^)(CGStreamStatsInfo * videoStatsInfo))videoStatsInfo;

/// 设置本地共享发送视频质量
- (BOOL)resetPublishShareDegradationPreference:(GSDegradationPreference)preference;
/// 获取本地共享发送视频质量
- (GSDegradationPreference)getPublishShareDegradationPreference;

/// 获取共享推流统计信息
- (BOOL)getLocalSharePublishStatsAudioReport:(void(^)(CGStreamStatsInfo *audioStatsInfo))audioStatsInfo VideoStatsInfo:(void(^)(CGStreamStatsInfo * videoStatsInfo))videoStatsInfo;
/// 停止本地屏幕共享
- (BOOL)stopLocalScreenShare;
/// 开关本地共享音频
- (BOOL)switchLocalScreenShareAudio:(BOOL)status;

/// 获取当前订阅直播流的分辨率
- (GSSubscribeResolution )getSubscribeLiveStreamResolution;
/// 订阅远端直播流
- (void)subscribeRemoteLiveStreamWithStreamResolution:(GSSubscribeResolution)resolution StreamTrackType:(GSStreamTrackType)trackType OnSuccess:(void(^)(UIView * remoteView))success OnFailure:(void(^)(YBError *error))failure;
/// 更新订阅live分辨率
- (void)updateSubscribeLiveWithResolution:(GSSubscribeResolution)resolution;
/// 停止订阅直播流
- (BOOL)stopSubscribeRemoteLiveStream;

/// 获取订阅远端流统计信息
- (BOOL)getRemoteLiveStreamSubscribeStatsAudioReport:(void(^)(CGStreamStatsInfo * audioStatsInfo))audioStatsInfo VideoStatsInfo:(void(^)(CGStreamStatsInfo * videoStatsInfo))videoStatsInfo;

///打开嘉宾视频墙
- (void)openGuestVideoWallStreamTrackType:(GSStreamTrackType)trackType
                           OnSuccess:(void(^)(UIView * videoWallView))success
                           OnFailure:(void(^)(YBError * _Nullable error))failure;

///停止订阅Common流
- (BOOL)stopSubscribeRemoteCommonStream;

/// 获取视频墙统计信息
- (BOOL)getVideoWallStatsAudioReport:(void(^)(CGStreamStatsInfo * audioStatsInfo))audioStatsInfo VideoStatsInfo:(void(^)(CGStreamStatsInfo * videoStatsInfo))videoStatsInfo;



@end

NS_ASSUME_NONNULL_END
