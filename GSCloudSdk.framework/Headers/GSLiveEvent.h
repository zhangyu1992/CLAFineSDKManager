//
//  GSLiveEvent.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/15.
//

#import <Foundation/Foundation.h>
#import <GSCloudSdk/GSIntercutFileInfo.h>
#import <GSCloudSdk/GSAnswerSheet.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, YBLeaveReason)
{
    YBLeaveReason_Normal, //正常退出
    YBLeaveReason_Kickout, //踢出
    YBLeaveReason_Live_Finish, //直播结束
    YBLeaveReason_timeout, //链接超时
    YBLeaveReason_Socket_DisConnected, //soket链接失败
    YBLeaveReason_KickoutBySpecialGuest, //被指定嘉宾踢出

};

typedef NS_ENUM(NSInteger, LotteryState)
{
    Lottery_START,
    Lottery_END,
};

typedef NS_ENUM(NSInteger, RollcallState)
{
    Rollcall_START,// 签到开始
    Rollcall_END,// 签到结束
};

typedef NS_ENUM(NSInteger, YBLiveStatus)
{
    YBLiveStatus_NotStart, //未开始
    YBLiveStatus_Ready, //准备中
    YBLiveStatus_Living,//直播中
    YBLiveStatus_Expired //过期
};

typedef NS_ENUM(NSInteger, YBadvocateLiveStatus)
{
    YBadvocateLiveStatus_StartLiving, //开始
    YBadvocateLiveStatus_EndLiving  //结束
};

typedef NS_ENUM(NSInteger, YBRecordStatus)
{
    YBRecordStatus_Start, //开始
    YBRecordStatus_End //结束
};

typedef NS_ENUM(NSInteger, YBRESOURCETYPE)
{
    YBRESOURCE_Doc,        //文档
    YBRESOURCE_Lod,        //插播
    YBRESOURCE_Warm,       //暖场
    YBRESOURCE_PseudoLive, //伪直播
};


/**
 *直播间相关回调
 */
@protocol GSLiveEvent <NSObject>
/**
 *加入直播
 */
-(void)onJoinLive:(YBStatusCode)code error:(YBError*)error;
/**
 *直播状态
 */
-(void)onLiveStatus:(YBLiveStatus)status;

/**
 *录制状态
 */
-(void)onRecordStatus:(YBRecordStatus)status;

/**
 *本人视频状态改变
 */
- (void)onMySelf:(NSString *)userId didChangedVideoStatus:(GSVideoStatus)videoStatus;

/**
 *本人音频状态改变
 */
- (void)onMySelf:(NSString *)userId didChangedAudioStatus:(GSAudioStatus)audioStatus;

/// 直播间主播身份发生改变
- (void)onLiveHostRoleDidChangeTo:(NSString *)hostUserId;

/**
 *用户信息变化
 */
-(void)onUserUpdate;

/**
 *用户加入
 */
- (void)onUserJoin:(GSUserInfo*)userInfo;

/**
 *用户退出
 */
- (void)onUserLeave:(GSUserInfo*)userInfo;

/**
 *显示在线人数
 */
-(void)onLiveShowOnlinCount:(BOOL)isShow;

/**
 *在线用户人数
 */
-(void)onLiveOnlineCount:(NSInteger)count;

/**
 *抽奖
 *step:0:开始  1:结束
 *users:抽奖信息
 */
-(void)onLottery:(LotteryState)step users:(GSLottery*)users;

/**
 *公告
 */
-(void)onBroadMsg:(GSBrocadMsg*)msg;

/**
 *公告模式变化
*/
-(void)onBroadMsgModeChange:(GSBrocadMsgMode)mode;

/**
 *签到状态改变
 */
-(void)onRollCall:(RollcallState)step timeout:(NSInteger)timeout tipStr:(NSString *)tipStr rollcallInfo:(GSRollCallInfo *)rollcallInfo;

/**
 *签到统计
 */
-(void)onRollCallStatistics:(GSRollCallInfo *)rollcallInfo;

/**
 *退出
 */
-(void)onLiveLeave:(YBLeaveReason)reason;

/**
 *支持的标签
 */
-(void)onLiveTags:(NSArray<LiveRoomTags*>*)tags;
/**
 *流数据
 */
-(void)onLivePullStreamUrl:(PullStreamUrl*)streamUrl;

/**
 *登录重连中
 */
-(void)onLiveLoginReconnecting;
/**
 *音视频重连中
 */
- (void)onLiveMediaReconnecting;
/**
 *音视频重连成功
 */
- (void)onLiveMediaReconnectionSuccess;
/**
 *直播页面设置
 */
-(void)onLiveBroadcastSetting:(LiveSettingInfo *)settingInfo;
/**
 *主播设置信息
 */
-(void)onLiveHostSetting:(GSHostSettingInfo *)hostSettingInfo;

/**
 *直播简介信息
 */
-(void)onLiveIntroduction:(NSString *)content;

/**
 *推流变化
 */
-(void)onCustomStreamChange;

/**
 *推流失败
 */
-(void)onCustomStreamOnFail:(NSString *)streamId;

/**
 *直播室音频主控模式
 *isAudioAuth:YES 关  NO：开
 */
-(void)onRoomAudioAuth:(BOOL )isAudioAuth;

/**
 *直播室视频主控模式
 *isVideoAuth:YES 关  NO：开
 */
-(void)onRoomVideoAuth:(BOOL )isVideoAuth;

/**
 *直播室重新订阅直播流成功
 */
- (void)onRoomDidReSubscribeLiveStreamSuccessWithRemoteView:(UIView *)remoteView;

/**
 *直播室重新订阅视频墙成功
 */
- (void)onRoomDidReSubscribeVideoWallSuccessWithRemoteView:(UIView *)videoWallView;
/**
 *直播室有直播流加入
 */
- (void)onRoomDidAddLiveStream;
/**
 *直播室有直播流离开
 */
- (void)onRoomDidLeaveLiveStream;

/**
 *直播室有共享流（桌面共享&插播共享）加入
 */
- (void)onRoomDidAddShareStreamWithSharedInfo:(GSShareInfo *)shareInfo;
/**
 *直播室有共享流（桌面共享&插播共享）离开
 */
- (void)onRoomDidLeaveShareStreamWithSharedInfo:(GSShareInfo *)shareInfo;


/**
 *直播室切换了直播源
 */
- (void)onRoomSwitchLiveStram:(YBLiveStreamType)liveType;

/**
 *直播室结束拉流
 */
- (void)onRoomStopLiveStram;

/**
 *直播室相关分享配置
 */
- (void)onRoomShareConten:(LiveWatchInfo *)shareInfo;
/**
 *媒体播放时全员是否有音频权限
 *isVoiceAuth  NO：全员静音
 */
-(void)onRoomMediaShareVoiceAuthDidChange:(BOOL )isVoiceAuth;
/**
 *插播文件状态发生改变
 */
-(void)onIntercutFileChange:(GSIntercutPlayingFileChangeInfo *)changeFileInfo;
/// 计时
- (void)onLiveTimerToolState:(GSTimerState)timerState TimerInfo:(GSTimerToolInfo*)timerInfo;

@end

NS_ASSUME_NONNULL_END
