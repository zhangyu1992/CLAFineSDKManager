//
//  RTSDK.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/6/9.
//

#import <Foundation/Foundation.h>

#import <FineSdk/RTSDK.h>
#import <FineSdk/RTGuid.h>
#import <FineSdk/RTMHeaders.h>
#import <FineSdk/RTMModelHeaders.h>
#import <FineSdk/RTCHeaders.h>
#import <FineSdk/RTCModelHeaders.h>
#import <FineSdk/RTMErrHeaders.h>

NS_ASSUME_NONNULL_BEGIN

/// 会议相关代理
@protocol RTSDKRoomDelegate <NSObject>
@required
/// 会议加锁时，接收到申请入会返回结果
/// @param isAgree YES ：同意 NO：不同意
- (void)RTSDKRoomReceiveApplyJoinRoomResult:(BOOL)isAgree;

/// 接收到申请入会结果（会议加锁和不加锁都会返回）
/// @param isAgree YES ：同意 NO：不同意
/// @param passCodeOk passCode是否正确
/// @param passcodeType passCode类型
- (void)RTSDKRoomReceiveApplyJoinRoomResult:(BOOL)isAgree PassCodeOk:(BOOL)passCodeOk PasscodeType:(NSString *)passcodeType UserList:(NSArray *)userList;
@end
/// cc会话相关代理
@protocol RTSDKSessionDelegate <NSObject>
@required
/// 接收到账号被踢掉线消息
/// @param kickoutReason 被踢原因
- (void)RTSDKSessionReceiveKickOutMessageByServerWithKickoutReason:(RTM_KickoutByServerReason)kickoutReason;
@optional
/// cc服务器连接状态改变
/// @param connectionStatus 连接状态
- (void)RTSDKSessionCCServerConnectionStatusDidChangedWithConnectionStatus:(RTM_CCServerConnectionStatus)connectionStatus;

@end

@interface RTSDK : NSObject

/// SDK服务器地址 默认为 cclocation.263cv.net:18080
@property (nonatomic, copy,readonly) NSString * sdkServerAddress;
/// 会议代理对象
@property (nonatomic, weak) id<RTSDKRoomDelegate> rtRoomDelegate;

/// 会话代理对象
@property (nonatomic, weak) id<RTSDKSessionDelegate> rtSessionDelegate;

/// 在加入会议成功后创建，可实现对会议的操作
@property (nonatomic, strong,readonly) RTCRoom * rtcRoom;

/// RTSDK 初始化时创建，可实现即时通讯功能
@property (nonatomic, strong, readonly) RTMSession *rtmSession;
//是否已经登录
@property (nonatomic, assign, getter=isAlreadyLogin) BOOL alreadyLogin;

///获取单例对象
+ (instancetype)shareInstance;

/// 重置SDK服务器地址（不重置地址默认使用cclocation.263cv.net:18080）
/// @param host 域名
/// @param port 端口
/// @param handle 重置成功回调，重置服务器地址成功后会退出登录，清空本地数据。
- (void)resetSDKServerAddressWithHost:(NSString *)host Port:(NSString *)port completeHandle:(void(^)(BOOL isSuccess))handle;

/// 登录SDK
/// @param account 账号
/// @param password 密码
/// @param appId appId
/// @param success 成功回调
/// @param failed 失败回调
-(void)loginWithAccount:(NSString*)account
               Password:(NSString*)password
                  AppId:(NSString *)appId
                success:(void (^)(RTSDKUserInfo * userInfoModel))success
                 failed:(void (^)(RTMError *error))failed;

/// 强制退出登录 不等服务器返回
/// @param success 成功回调
- (void)forceLogoutSuccess:(void(^)(void))success;

/// 查询当前登录的用户信息
/// @param success 成功回调
/// @param failed 失败回调
- (void)queryCurrentLoginUserSuccess:(void (^)(RTSDKUserInfo * userInfoModel))success
                               failed:(void (^)(RTMError *error))failed;


/// 创建会议
/// @param roomName 会议名称
/// @param success 创建会议成功回调 返回会议id
/// @param failure 创建会议失败回调
- (BOOL)createRoomWithRoomName:(NSString *)roomName OnSuccess:(void(^)(NSString * roomId))success OnFailure:(void(^)(RTCError * error))failure;

/// 结束会议
/// @param success 结束会议成功回调
/// @param failure 结束会议失败回调
- (BOOL)destroyRoomOnSuccess:(void(^)(void))success OnFailure:(void(^)(RTCError * error))failure;


/// 加入会议
/// @param joinConfig 入会配置
/// @param success 加入会议成功回调
/// @param failure 加入会议失败回调
- (BOOL)joinRoomWithJoinConfig:(RTCJoinConfig *)joinConfig OnSuccess:(void(^)(void))success OnFailure:(void(^)(RTCError *))failure;

/// 离开会议
/// @param success 离开会议成功回调
/// @param failure 离开会议失败回调
- (BOOL)leaveRoomOnSuccess:(void(^)(void))success OnFailure:(void(^)(RTCError * error))failure;

/// 开始本地摄像头采集
/// @param success 成功回调
- (void)startLocalCameraCaptureOnSuccess:(void(^)(AVCaptureVideoPreviewLayer * cameraLayer))success;

/// 停止本地摄像头采集
/// @param success 成功回调
- (void)stopLocalCameraCaptureOnSuccess:(void(^)(void))success;

/// 重置摄像头方向
/// @param cameraPosition 摄像头方向
- (BOOL)resetLocalCameraPosition:(RTCCameraPosition)cameraPosition;

/// 当会议加锁时发送申请消息给主持人
- (void)sendApplyJoinRoomMessageToCompereWhenRoomLock;

/// 当会议没有锁时申请加入会议
- (void)sendApplyJoinRoomMessageToCompereWhenRoomUnLock;

- (BOOL)getIsClickLeave;
@end

NS_ASSUME_NONNULL_END
