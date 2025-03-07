//
//  CCAdapterManager.h
//  CCAdapter
//
//  Created by jinxiangkun on 2019/1/8.
//  Copyright © 2019年 jinxiangkun. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCAdapterKeys.h"
#import "CCAdapterClass.h"
#import "CCAdapterDelegate.h"

/*
 邵黎明
 CC 服务器增加了一个根据sid获取cid uid的接口，
 与之前验证sid cid uid接口使用同一个端口。
 POST 211.157.148.82:8089/login/authsid?cmd=getcuid 
 请求
 {"sid": "cc.1542677738.447610.1303455736"}
 返回
 {"status":200,"info":"ok","cid":"U10000063167","uid":"200000230568"}
 */

#define CCMakeStringTag() \
[CCAdapterManager getUniqueIdentification]

@interface CCAdapterManager : NSObject //(ServiceProtocol)

// 获取共享单例
+ (instancetype)sharedInstance;

@property (nonatomic, assign) BOOL loginFlag;
// 登陆用户的状态
@property (nonatomic, assign) BOOL isWebsockedContend;
// 当前的cc用户信息
@property (nonatomic, strong) CCAdapterClass * theClient;
// 当前的ccsdk adapter
@property (nonatomic, strong) CCNameSpace(CCServiceManager) * share;
// 登陆用户的主要信息，登陆信息，用户信息
@property (nonatomic, strong) CCNameSpace(CCModelAuthInfo) *ccModelAuthInfo;
@property (nonatomic, strong) CCNameSpace(CCModelUserInfo) *ccModelUserInfo;
// 用户账号的配置信息
@property (nonatomic, strong) CCNameSpace(CCModelUserInfoPermission) *ccModelUserPermission;
@property (nonatomic, strong) NSDictionary * userVersionUpdataInfo;

// 注册推送用的内部数据对像
@property (strong, nonatomic) NSString * devicetoken;
@property (strong, nonatomic) NSData * deviceTokenData; // notification set!
@property (strong, nonatomic) UIUserNotificationSettings * notificationSettings;

@property (nonatomic, copy) void(^NetWorkStateChanged)(NSInteger netState);
// 当前帐号的用户ID
- (NSString *)currentUserID;

// 当前帐号的用户登陆名
- (NSString *)currentUserName;

// 当前帐号的客户ID
- (NSString *)currentCustomerID;

// 当前的根路径
- (NSString *)currentSdkPath;

// 当前的用户路径
- (NSString *)currentUserPath;

// 当前WiFi网络连接状态
- (BOOL)isWiFiReachability;

// 如果WiFi为FALSE状态时，询问当前WWAN网络连接状态
- (BOOL)isInternetReachability;
- (BOOL)isNetWorkConnection;
// 关闭当前的适配层
- (void)closeAdapterClass;

// 创建一个新的适配层
- (void)createAdapterClass;


// 测试一个当前的CC客户端信息
- (BOOL)runAdapterClassWithUser:(NSString *)user info:(NSString *)password
                       authMode:(BOOL)isAuthMode;

// 测试一个当前的CC客户端信息, isAuthMode, 是否使用强制联网认证模式
- (BOOL)runAdapterClassWithUser:(NSString *)user info:(NSString *)password
                       authMode:(BOOL)isAuthMode waitMode:(BOOL)isWait;
// 测试一个当前的CC客户端信息
- (BOOL)runAdapterClassWithUser:(NSString *)user info:(NSString *)password captchaDiffer:(int)captcha authMode:(BOOL)isAuthMode waitMode:(BOOL)isWait;

- (BOOL)runAdapterClassWithUser:(NSString *)user info:(NSString *)password captchaDiffer:(int)captcha appId:(NSString *)appId authMode:(BOOL)isAuthMode waitMode:(BOOL)isWait;

- (void)AutoLogin:(void (^)(CCCallState state, CCNameSpace(CCModelAuthInfo) * info))block;
// 自动登录获取 登录的用户列表
- (void)AutoLoginToGetLoginInfoList:
(void (^)(CCCallState state, NSArray * info))block;
// 测试某个block的调用
- (void)performBlock:(void (^)(void))block;


// 获取唯一标识
//[CCAdapterTools getUniqueIdentification]
+ (NSString *)getUniqueIdentification;


#pragma mark status manager

// 获得服务器的当前状态值，位操作值的合集，单独测试位是否存在
//CCHasBits(sdkStatus, CCSdkStatusLoginAuth);
//CCHasBits(sdkStatus, CCSdkStatusLoginLocalName);
- (void)OnGetSdkStatus:(long long)sdkStatus
                 state:(CCCallState)state;

#pragma mark Login manager

// 5.用户登陆，name 登陆的用户帐号，password 登陆类的用户密码
// 其中 localState 是定位服务状态码，loginState 是认证服务状态码
- (void)OnLoginInWithLoginName:(NSString *)logName
                          info:(NSString *)logPassword
                         state:(CCCallState)state
                    loginState:(CCNameSpace(CCLoginStateInfo) *)logState;

// 7.用户退出登陆，退出当前已登陆的用户
- (void)OnLoginOutForCurrentUser:(CCNameSpace(CCModelAuthInfo) *)info
                           state:(CCCallState)state;

// 用户退出登录
- (void)loginOutAdapterClassForCurrentUser:(void (^)(CCCallState state))block;
// 获取验证码
- (void)loginErrorGetCaptchaIdWithLoginName:(NSString *)loginName andMaxNumber:(int)iMaxNumber result:
(void (^)(NSString * captchaid))block;
#pragma mark Websocket manager

// 网络连接PING
- (void)OnPingWebsocket:(BOOL)isPing state:(CCCallState)state;

// 检测到当前接入服务连接时发送DeviceToken
- (void)sendRemotePushNotificationDeviceToken;

// 检测到当前接入服务连接的状态！
- (void)OnWebsocketIsConnect:(NSString *)logName state:(CCCallState)state;

// 检测到当前接入服务是中断的状态！
- (void)OnWebsocketIsDisconnect:(long)lastError state:(CCCallState)state;

#pragma mark Session && Message manager


// 获得某个会话的项目主动推送更新
- (void)OnSessionUpdate:(CCNameSpace(CCSessionInfo) *)result
                  state:(CCCallState)state;

// 读取了一条聊天消息, 主动接收的推送消息！
- (void)OnReadMessage:(CCNameSpace(CCMessageResult) *)result
                state:(CCCallState)state;

// 读取了一条控制的消息, 主动接收的推送消息！
- (void)OnReadServerNotify:(CCNameSpace(CCMessageResult) *)result
                     state:(CCCallState)state;

// 发送了一条聊天消息，队列调用发送后
- (void)OnWriteMessage:(CCNameSpace(CCMessageSendBase) *)send
                 state:(CCCallState)state;

// 发送了一条聊天消息，发送失败
- (void)OnWriteMessageFailed:(CCNameSpace(CCMessageSendBase) *)send
                       state:(CCCallState)state;

// 发送了一条聊天消息，发送未知类型
- (void)OnWriteMessageUnknow:(CCNameSpace(CCMessageSendBase) *)send
                       state:(CCCallState)state;

#pragma mark Message manager do Action

// 接收到消息后是否进行提示
- (void)voicePromptWhenRecvicedMessage;

// 接收到基础类型的消息
- (void)receiveMessageTypeBase:(CCNameSpace(CCMessageResult) *)result;

// 接收到未知类型的消息
- (void)receiveMessageTypeUnknow:(CCNameSpace(CCMessageResult) *)result;

// 收到了发送的回复消息！
- (void)receiveMessageTypeConfim:(CCNameSpace(CCMessageResult) *)result;

// 发送接收消息的回复消息
- (void)writeReplyMessageWithMessageID:(NSString *)msgid;

// 发送接收消息的回复消息，带协议命令字！
- (void)writeReplyMessageWithMessageID:(NSString *)msgid
                               command:(NSInteger)commandType;

// 发送接收消息的回复消息，带协议命令字！
- (void)writeReplyMessageWithMessage:(CCNameSpace(CCMessageResult) *)result;

// 收到了推送的聊天消息！
- (void)receiveMessageTypeChatInfo:(CCNameSpace(CCMessageResult) *)result;

// 收到了推送的群组消息！
- (void)receiveMessageTypeGroupInfo:(CCNameSpace(CCMessageResult) *)result;

// 收到了发送的回复消息！
- (void)receiveMessageGroupConfim:(CCNameSpace(CCMessageResult) *)result;

// 收到了推送的群组事件消息！
- (void)receiveMessageTypeGroupAction:(CCNameSpace(CCMessageResult) *)result;
// 收到群组错误消息
- (void)receiveMessageTypeGroupOwnerErrorInfo:(CCNameSpace(CCMessageResult) *)result;
// 检测版本更新
- (void)getVersionUpdateRequestUrlWithType:(int)type result:(void (^)(NSString * requestUrl))block;
/// 根据type获取服务器地址
- (NSString *)getLocalServerWithType:(int)type result:(void (^)(NSString * serverAddress))block;
#pragma mark -- 关联二维码
- (void)associatedToLoadQRCodeWithDeviceInfo:(NSDictionary *)diviceInfo result:(void (^)(CCCallState state,long errCode))block;

#pragma mark -- 授权二维码
- (void)authToLoadQRCodeWithDeviceInfo:(NSDictionary *)diviceInfo result:(void (^)(CCCallState state,long errCode))block;

#pragma mark -- 邀请方查询授权二维码状态
- (void)checkLoadQRCodeWithDeviceInfo:(NSDictionary *)diviceInfo result:(void (^)(CCCallState state,long errCode,NSDictionary *info))block;

#pragma mark -- 获取扫码登录设备列表
- (void)fatchQRCodeLoadDeviceListWithParams:(NSDictionary *)params result:(void (^)(CCCallState state,long errCode,NSMutableArray *deviceArray))block;

#pragma mark -- 退出扫码设备
- (void)kickOutQRCodeLoadDeviceWithParams:(NSDictionary *)params result:(void (^)(CCCallState state,long errCode))block;



@end
