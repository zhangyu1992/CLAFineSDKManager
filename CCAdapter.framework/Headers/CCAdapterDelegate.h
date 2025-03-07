//
//  CCAdapterDelegate.h
//  test_adapter
//
//  Created by yiyimama on 17/4/13.
//  Copyright © 2017年 yiyimama. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCAdapterBase.h"
#import "CCAdapterClass.h"

@protocol CCNameSpace(CCServiceProtocol);

@interface CCPacketProtocol : NSObject
{
    // 服务回调指针对像，弱引用
    __weak id<CCNameSpace(CCServiceProtocol)> _serviceDelegate;
}

// 缓存引用对像的弱指针键值
@property (strong) NSString * packetKey;

// 0.设置回调代理类，如果想使用代理模式请求
- (id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;
- (void)setServiceDelegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;

@end

@interface CCAdapterDelegate : NSObject

// 获取共享单例
+ (instancetype)sharedInstance;

// CCPacketProtocol列表
@property (strong) NSMutableArray * packetList;
// CCPacketProtocol列表 key为CCServiceProtocol指针！
@property (strong) NSMutableDictionary * packetMap;
// CCAdapterDelegate的主要使用锁！
@property (nonatomic, strong) NSRecursiveLock * delegateLock;


#pragma id<CCNameSpace(CCServiceProtocol)>

// 添加一个测试层的代理实例，代理方法只有本类的实现的方法作回调
- (void)addServiceDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;
// 移除一个测试层的代理实例，代理方法只有本类的实现的方法作回调
- (void)removeServiceDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

#pragma mark status manager

// 获得服务器的当前状态值，位操作值的合集，单独测试位是否存在
//CCHasBits(sdkStatus, CCSdkStatusLoginAuth);
//CCHasBits(sdkStatus, CCSdkStatusLoginLocalName);
- (void)OnGetSdkStatus:(long long)sdkStatus
                 state:(CCCallState)state;

#pragma mark Login manager

// 错误返回信息描述
- (NSString *)errorString:(CCNameSpace(CCLoginStateInfo) *)logState;

// 5.用户登陆，name 登陆的用户帐号，password 登陆类的用户密码
// 其中 localState 是定位服务状态码，loginState 是认证服务状态码
- (void)OnLoginInWithLoginName:(NSString *)logName
                          info:(NSString *)logPassword
                         state:(CCCallState)state
                    loginState:(CCNameSpace(CCLoginStateInfo) *)logState;

// 7.用户退出登陆，退出当前已登陆的用户
- (void)OnLoginOutForCurrentUser:(CCNameSpace(CCModelAuthInfo) *)info
                           state:(CCCallState)state;

// 注：用户断网重连认证时，会话SID会发生变化，可更新相关数据！

// x.用户断网重连接认证，name 登陆的用户帐号，password 登陆类的用户密码
- (void)OnReAuthInWithLoginName:(NSString *)lognName
                          state:(CCCallState)state;

// x.用户断网重连接认证，name 登陆的用户帐号，password 登陆类的用户密码
// 其中 localState 是定位服务状态码，loginState 是认证服务状态码
- (void)OnReAuthInWithLoginName:(NSString *)lognName
                          state:(CCCallState)state
                     loginState:(CCNameSpace(CCLoginStateInfo) *)logState;

// 注意，补充回调信息
// 用户本地认证通过，当有联网认证时，发现认证信息的出错，主动回调反馈问题
- (void)OnAuthErrorWithLoginName:(NSString *)logName
                            info:(NSString *)logPassword
                      loginState:(CCNameSpace(CCLoginStateInfo) *)logState;

#pragma mark Roster manager

// 7.1 获得更新数据大小, 更新组织通讯录列表，代理方式回调
- (void)OnUpdateRosterDataFromServer:(CCCallState)state;

// 7.2 获得全新的组织数据, 刷新组织通讯录列表，代理方式回调
- (void)OnDownloadRosterDataFromServer:(CCCallState)state;


#pragma mark Websocket manager

// 网络连接PING
- (void)OnPingWebsocket:(BOOL)isPing state:(CCCallState)state;

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


#pragma id<CCNameSpace(CCReachabilityProtocol)

// 当前WiFi网络连接状态
- (BOOL)isWiFiReachability:(CCNameSpace(CCServiceManager) *)service;

// 如果WiFi为FALSE状态时，询问当前WWAN网络连接状态
- (BOOL)isInternetReachability:(CCNameSpace(CCServiceManager) *)service;

@end
