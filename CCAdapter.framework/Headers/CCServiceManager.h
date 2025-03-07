//
//  CCServiceManager.h
//  adapter
//
//  Created by yiyimama on 17/3/24.
//  Copyright © 2017年 zsx. All rights reserved.
//

#ifndef _CC263_CCServiceManager_H_
#define _CC263_CCServiceManager_H_

#import <Foundation/Foundation.h>

#import "CCRuntime.h"

#import "CCModelBase.h"
#import "CCModelMethod.h"
#import "CCModelMessage.h"
#import "CCModelTransform.h"

// 代理方式的调用协议返回类！
#import "CCServiceTypes.h"
#import "CCServiceProtocol.h"

// 线程调用类
@class CCNameSpace(CCThreadQueue);

@class CCNameSpace(CCServiceManager);

// 服务的调用状态
enum CCSdkServiceStatus
{
    // 未调用状态
    CCSdkStatusNone = (0ll),
    // 调用创建指针
    CCSdkStatusInit = (1ll << 1),
    // 调用设置设备信息
    CCSdkStatusDevInfo = (1ll << 2),
    // 调用设置服务器地址
    CCSdkStatusLocationServer = (1ll << 3),
    // 调用设置用户数据库目录
    CCSdkStatusDatabaseUser = (1ll << 4),
    // 调用设置全局数据库目录
    CCSdkStatusDatabaseGlobal = (1ll << 5),
    // 调用通过普通鉴权登陆
    CCSdkStatusLoginAuth = (1ll << 7),
    // 调用通过数据无网登陆
    CCSdkStatusLoginLocalName = (1ll << 8),
    // 调用通过聊天Socket登陆
    CCSdkStatusLoginWebSocket = (1ll << 9),
    // 调用登陆成功后创建用户数据库目录
    CCSdkStatusDatabaseUserCreate = (1ll << 10),
    // 调用通过更新Roster数据信息
    CCSdkStatusUndateRoster = (1ll << 11),
    // 关闭ccsdk的所有调用模式 uninitializeService
    CCSdkStatusUninitialize = (1ll << 31),
    // 不可以可以开始登录
    CCSdkStatusLoginUnAble = (1ll << 41),
};
typedef enum CCSdkServiceStatus CCSdkServiceStatus;

// 注意：CCServiceProtocol 使用时机
// 大部分方法分为两种，当调用block的方法，不由代理方法返回结果
// 大部分方法分为两种，当没有调用block的方法，由代理方法返回结果

#define CCUpdateRosterDataFromServerNotification \
    @"CCUpdateRosterDataFromServerNotification"
#define CCDownloadRosterDataFromServerNotification \
    @"CCDownloadRosterDataFromServerNotification"

@interface CCNameSpace(CCServiceManager) : NSObject

// 获取共享单例
+ (instancetype)sharedInstance;

// 服务调用线程队列
@property (nonatomic, strong) CCNameSpace(CCThreadQueue) * dispatchQueue;
// 服务回调线程队列
@property (nonatomic, strong) CCNameSpace(CCThreadQueue) * delegateQueue;

#pragma mark Delegate

// 0.设置回调代理类，如果想使用代理模式请求
- (id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;
- (void)setServiceDelegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;

// 0.设置网络状态代理类，如果想使用代理模式请求
- (id<CCNameSpace(CCReachabilityProtocol)>)reachabilityDelegate;
- (void)setReachabilityDelegate:(id<CCNameSpace(CCReachabilityProtocol)>)reachabiDelegate;

#pragma mark Configuration

// 1.初始化服务管理类，创建调用实例指针，阻塞至调用完成！
- (void)initializeService;
- (void)initializeService:(void (^)(CCCallState error))block;

// x.反初始化服务管理类，将删除调用实例指针（test），回调回来后清理完成！
- (void)uninitializeService;
- (void)uninitializeService:(void (^)(CCCallState error))block;

// 获得某个线程的错误码，在调用线程获得，并在调用线程进行回调
- (CCCallState)lastErrorCode:(int *)pErrorCode;
- (void)getLastErrorCode:(void (^)(CCCallState error, int iErrorCode))block;

// 2.设置全局数据库的路径与数据库打开密码
- (void)setSdkDatabasePath:(NSString *)path info:(NSString *)pass;
- (void)setSdkDatabasePath:(NSString *)path info:(NSString *)password
                    result:(void (^)(CCCallState state))block;

// 2.设置用户数据库的路径与数据库打开密码
- (void)setUserDatabasePath:(NSString *)path info:(NSString *)pass;
- (void)setUserDatabasePath:(NSString *)path info:(NSString *)password
                     result:(void (^)(CCCallState state))block;

// 3.设置设备信息，如果没有设备信息，将在回调中查询信息
- (void)setDeviceInfo:(CCNameSpace(CCDeviceInfo) *)device;
- (void)setDeviceInfo:(CCNameSpace(CCDeviceInfo) *)deviceInfo
               result:(void (^)(CCCallState state))block;

// 获取全局配置数据，需要先打开全局数据库
- (void)getSdkConfig:(NSString *)key
              result:(void (^)(NSString * value))block;
- (void)getSdkConfig:(NSString *)key
            delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 设置全局配置数据，需要先打开全局数据库
- (void)setSdkConfig:(NSString *)key value:(NSString *)value
              result:(void (^)(CCCallState state))block;
- (void)setSdkConfig:(NSString *)key value:(NSString *)value
            delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 获取用户配置数据，需要先打开用户数据库，要登陆成功后才能使用
- (void)getUserConfig:(NSString *)key
               result:(void (^)(NSString * value))block;
- (void)getUserConfig:(NSString *)key
             delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 设置用户配置数据，需要先打开用户数据库，要登陆成功后才能使用
- (void)setUserConfig:(NSString *)key value:(NSString *)value
               result:(void (^)(CCCallState state))block;
- (void)setUserConfig:(NSString *)key value:(NSString *)value
             delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 4.设置服务器地址与端口
- (void)setServerAddress:(NSString *)ipStr port:(short)port;
- (void)setServerAddress:(NSString *)ipStr port:(short)portVal
                  result:(void (^)(CCCallState state))block;
- (void)setServerAddress:(NSString *)ipStr port:(short)portVal
                delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// x.获得服务器地址与端口，@"host", @"port"
- (void)getServerAddress;
- (void)getServerAddress:(void (^)(NSDictionary * addressInfo))block;
- (void)getServerAddressByDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 可选设置，每次初始化后会重置为默认
// 设置当前的相关网络服务连接超时时间，变量的值大于0时有效
- (void)setCurrentTimeout:(CCNameSpace(CCLinkTimeOut) *)timeInfo
                   result:(void (^)(CCCallState state))block;
// 获得当前的相关网络服务连接超时时间，变量的值大于0时有效
- (void)getCurrentTimeout:(void (^)(CCCallState state,
                                    CCNameSpace(CCLinkTimeOut) *timeInfo))block;

// 数据库清理数据内容接口，
// 用户的数据清理要等登陆成功后，才可以清理当前的登陆用户的数据
- (void)cleanDatabaseCacheDataWithType:(CCCacheType)iType
                                result:(void (^)(CCCallState state))block;
- (void)cleanDatabaseCacheDataWithType:(CCCacheType)iType
                              delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

#pragma mark Login in or out
// 获取验证码
- (void)loginErrorGetCaptchaIdWithLoginName:(NSString *)loginName andMaxNumber:(int)iMaxNumber result:
(void (^)(NSString * captchaid))block;
// 5.用户登陆，name 登陆的用户帐号，password 登陆类的用户密码
// 其中 localState 是定位服务状态码，loginState 是认证服务状态码
// 是否启用强制认证模式！
- (void)loginInWithLoginName:(NSString *)name info:(NSString *)password captchaDiffer:(int)captchaDiffer appId:(NSString *)appId
                    authMode:(BOOL)isAuthMode result:
(void (^)(CCCallState state, CCNameSpace(CCLoginStateInfo) * loginState))block;

// 登陆已经验证用户WebSocket连接
- (void)loginWebSocketWhenAuth:(NSString *)loginName;
- (void)loginWebSocketWhenAuth:(NSString *)loginName
                        result:(void (^)(CCCallState state, int iStateCode))block;
- (void)loginWebSocketWhenAuth:(NSString *)loginName
                      delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// x.用户退出登陆，退出当前已登陆的用户
- (void)loginOutForCurrentUser;
- (void)loginOutForCurrentUser:(void (^)(CCCallState state))block;
- (void)loginOutForCurrentUserByDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;
//强制退出登录
- (void)forcedLoginOutForCurrentUser:(void (^)(CCCallState state))block;
// 测试接入服务是否成功！
- (void)websocketIsLinked; //代理模式
- (void)websocketIsLinked:(void (^)(CCCallState state, BOOL isLinked))block;
- (void)websocketIsLinkedByDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// x.部分操作方法，需要登陆认证后才能正常操作，含有离线工作方式？

#define CCHasBits(status,flag) \
((long long)flag==((long long)status&(long long)flag))
// 获得适配层的当前状态值，位操作值的合集，单独测试位是否存在
- (void)getSdkStatusByDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;
- (void)getSdkStatus:(void (^)(CCCallState state, long long sdkStatus))block;

// 获得适配层的当前主存储目录，根据全局目录相对生成
- (void)getSdkPathWithType:(CCSdkPathType)type
                  delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;
- (void)getSdkPathWithType:(CCSdkPathType)type
                    result:(void (^)(CCCallState state, NSString * path))block;

#pragma mark Login in auth user info

// 获取根据用户名对应的登录用户的信息
- (void)getUserAuthInfoByName:(NSString *)loginName;
- (void)getUserAuthInfoByName:(NSString *)loginName
                       result:
(void (^)(CCCallState state, CCNameSpace(CCModelAuthInfo) * info))block;
- (void)getUserAuthInfoByName:(NSString *)loginName
                     delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 获取最后登录的用户的信息
- (void)getLastUserAuthInfo; //代理模式
- (void)getLastUserAuthInfo:
(void (^)(CCCallState state, CCNameSpace(CCModelAuthInfo) * info))block;
- (void)getLastUserAuthInfoByDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 获取当前登录的用户的信息
- (void)getCurrentUserAuthInfo; //代理模式
- (void)getCurrentUserAuthInfo:
(void (^)(CCCallState state, CCNameSpace(CCModelAuthInfo) * info))block;
- (void)getCurrentUserAuthInfoByDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

#pragma mark Session manager

// 会话列表数据维护
// M_SESSION&  GetSessionList();
- (void)getSessionList:(void (^)(CCCallState state, NSMutableArray * list))block;
- (void)getSessionListByDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 获得一个会话的项目，传入uid,cid 或是 gid,cid
- (void)getOneSession:(CCNameSpace(CCItemInfo) *)itemSet
               result:
(void (^)(CCCallState state, CCNameSpace(CCSessionInfo) * info))block;
// 获得一个会话的项目，传入uid,cid 或是 gid,cid
- (void)getOneSession:(CCNameSpace(CCItemInfo) *)itemSet
             delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;

//// 添加一个会话的项目，传入uid,cid不为空，会话信息可从最后一条消息中查询
//- (void)addOneSession:(CCNameSpace(CCSessionInfo) *)info
//               result:(void (^)(CCCallState state))block;
//// 添加一个会话的项目，传入uid,cid不为空，会话信息可从最后一条消息中查询
//- (void)addOneSession:(CCNameSpace(CCSessionInfo) *)info
//             delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;

// 移除一个会话的项目，传入uid,cid 或是 gid,cid，不会删除消息库中的聊天记录
- (void)removeOneSession:(CCNameSpace(CCItemInfo) *)itemSet
                  result:
(void (^)(CCCallState state, CCNameSpace(CCSessionInfo) * info))block;
// 移除一个会话的项目，传入uid,cid 或是 gid,cid，不会删除消息库中的聊天记录
- (void)removeOneSession:(CCNameSpace(CCItemInfo) *)itemSet
                delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;

// 设置消息未读数字，传入uid,cid 或是 gid,cid
- (void)setUnReadNumber:(CCNameSpace(CCItemInfo) *)itemSet
                  count:(int)iReadNumber
                 result:(void (^)(CCCallState state))block;
// 设置消息未读数字，传入uid,cid 或是 gid,cid
- (void)setUnReadNumber:(CCNameSpace(CCItemInfo) *)itemSet
                  count:(int)iReadNumber
               delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;

// 清除消息未读数字，传入uid,cid 或是 gid,cid
- (void)clearUnReadNumber:(CCNameSpace(CCItemInfo) *)itemSet
                   result:(void (^)(CCCallState state))block;
// 清除消息未读数字，传入uid,cid 或是 gid,cid
- (void)clearUnReadNumber:(CCNameSpace(CCItemInfo) *)itemSet
                 delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;


#pragma mark Message manager

#if 0x0 //声明在上面
// 登陆已经验证用户WebSocket连接
- (void)loginWebSocketWhenAuth:(NSString *)loginName;
- (void)loginWebSocketWhenAuth:(NSString *)loginName
                        result:(void (^)(CCCallState state, int iStateCode))block;
- (void)loginWebSocketWhenAuth:(NSString *)loginName
                      delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;
#endif

// 网络连接PING
- (void)pingWebsocket:(void (^)(CCCallState state, BOOL isPing))block;
- (void)pingWebsocketByDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

#if 0x0 //声明在上面
// 测试接入服务是否成功！
- (void)websocketIsLinked; //代理模式
- (void)websocketIsLinked:(void (^)(CCCallState state, BOOL isLinked))block;
- (void)websocketIsLinkedByDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;
#endif

// 关闭接入服务的网络连接
- (void)closeWebsocket:(void (^)(CCCallState state))block;
- (void)closeWebsocketByDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 注册推送平台
- (void)remotePushNotification:(NSString *)msgId
                      pushInfo:(CCNameSpace(CCPlatformPushInfo) *)pushInfo
                        result:(void (^)(CCCallState state))block;
// 注册推送平台 登录websocket之后调用
- (void)registerPushNotification:(NSString *)msgId
                        pushInfo:(CCNameSpace(CCPlatformPushInfo) *)pushInfo
                          result:(void (^)(CCCallState state))block;

// 获取离线消息 登录WebSocket成功之后调用
- (void)getOffLineMsgFromWebSocket:(void (^)(CCCallState state))block;
- (void)getOffLineMsgFromWebSocketByDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;
// 消息同步 接口
- (void)requestHistoryMsg:(CCHistoryMessage *)historyMessage FromWebSocket:(void (^)(CCCallState state/*, BOOL isOk*/))block;

// 读取聊天消息，由SDK调用，有消息后回调代理接口
// 线程数据接收后，回调 @selector(OnReadMessage:state:)
//- (void)readMessage:(int)iTimeOut
//           delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;

// 获取一个消息GUID
// 只有以此接口生成的Guid为消息ID的才能发送成功，否则会返回错误 InvalidGuid;
- (NSString *)newMessageGuid:(CCCallState *)pState;

// 判断此ID是否已经有效，是否加入当前的服务中
- (CCCallState)messageGuidIsValidOnCurrentService:(NSString *)aGuid;

// 发送一条聊天消息，state == CCCallOK 代表入队成功，但未发送
// @selector(OnWriteDelegate:state:status:)
- (void)writeMessage:(CCNameSpace(CCMessageSendBase) *)sendBody
            delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;
// 发送一条聊天消息，state == CCCallOK 代表入队成功，但未发送
- (void)writeMessage:(CCNameSpace(CCMessageSendBase) *)sendBody
              result:(void (^)(CCCallState state, CCSendState sendStatus))block;
// 线程数据发送后，回调 @selector(OnWriteMessage:state:) // CCSendStateSending
// 线程数据发送后，回调 @selector(OnWriteMessageFailed:state:) // CCSendStateSendFailed
// 线程数据发送后，回调 @selector(OnWriteMessageUnknow:state:) // 发送未知消息数据类型

// 缓存一条聊天消息，state == CCCallOK 代表本地存储成功，但不发送
- (void)saveMessageToLocal:(CCNameSpace(CCMessageSendBase) *)sendBody
                  delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;
// 缓存一条聊天消息，state == CCCallOK 代表本地存储成功，但不发送
- (void)saveMessageToLocal:(CCNameSpace(CCMessageSendBase) *)sendBody
                    result:(void (^)(CCCallState state, BOOL isSaved))block;

// 获取历史消息记录, CCGetConfig 是一个约定查询范围的结构信息
- (void)getHistoryMessages:(CCNameSpace(CCItemInfo) *)itemSet
                    config:(CCNameSpace(CCGetConfig) *)getConfig
                    result:(void (^)(CCCallState state,
                                     CCNameSpace(CCMessageGetResult) * result))block;
// 获取历史消息记录, CCGetConfig 是一个约定查询范围的结构信息
- (void)getHistoryMessages:(CCNameSpace(CCItemInfo) *)itemSet
                    config:(CCNameSpace(CCGetConfig) *)getConfig
                  delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;
// 获取未读条数
- (void)getUnReadMsgCount:(CCNameSpace(CCHistoryMessage) *)history
                   result:(void (^)(CCCallState state,int unreadNumber))block;
// 获取未读消息列表
- (void)getAllMessageListWithHistoryMessage:(CCHistoryMessage *) historyMessage result:(void (^)(CCCallState state,CCNameSpace(CCMessageGetResult) * result))block;

// 获取历史消息记录, CCGetConfig 是一个约定查询范围的结构信息, 直接调用模式
- (void)callHistoryMessages:(CCNameSpace(CCItemInfo) *)itemSet
                    config:(CCNameSpace(CCGetConfig) *)getConfig
                    result:(void (^)(CCCallState state,
                                     CCNameSpace(CCMessageGetResult) * result))block;

// 设置一个消息的发送状态或接收状态信息
- (void)setMessageStatus:(NSString *)messageId
                  status:(CCSendState)iSendStatus itemOwner:(CCItemInfoType)itemType
                  result:(void (^)(CCCallState state))block;
// 设置一个消息的发送状态或接收状态信息
- (void)setMessageStatus:(NSString *)messageId
                  status:(CCSendState)iSendStatus itemOwner:(CCItemInfoType)itemType
                delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;

// 删除一条信息条目，messageId不为空
- (void)deleteMessageByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                     messageId:(NSString *)messageId
                        result:(void (^)(CCCallState state))block;
// 删除一条信息条目，messageId不为空
- (void)deleteMessageByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                     messageId:(NSString *)messageId
                      delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;

// 删除多条信息条目，CCGetConfig 是一个约定范围的结构信息
- (void)deleteMessageByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                        config:(CCNameSpace(CCGetConfig) *)getConfig
                        result:(void (^)(CCCallState state))block;
// 删除多条信息条目，CCGetConfig 是一个约定范围的结构信息
- (void)deleteMessageByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                        config:(CCNameSpace(CCGetConfig) *)getConfig
                      delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;


#pragma mark Roster update

// 7.获得需要更新的组织列表数据大小，根据网络是否要执行更新
- (void)getNeedUpdateRosterSize; //代理模式
- (void)getNeedUpdateRosterSize:(void (^)(CCCallState state,
                                          long dataSize))block;
- (void)getNeedUpdateRosterSizeByDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 7.1 获得更新数据大小, 更新组织通讯录列表，新线程调用，异步模式！
- (void)updateRosterDataFromServer; //代理模式
- (void)updateRosterDataFromServer:(void (^)(CCCallState state))block;
- (void)updateRosterDataFromServerByDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 7.2 获得全新的组织数据, 刷新组织通讯录列表，新线程调用，异步模式！
- (void)downloadRosterDataFromServer; //代理模式
- (void)downloadRosterDataFromServer:(void (^)(CCCallState state))block;
- (void)downloadRosterDataFromServerByDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

#pragma mark Query depart Or User info

// 用户信息联网查询
// 根据itemSet条件id查询一个用户信息
- (void)getUserInfoFromServer:(CCNameSpace(CCItemInfo) *)itemSet
                       result:
(void (^)(CCCallState state, CCNameSpace(CCResultUser) * info))block;
// 根据itemSet条件id查询一个用户信息，代理协议模式
- (void)getUserInfoFromServer:(CCNameSpace(CCItemInfo) *)itemSet
                     delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 数据库接口区
// 根据itemSet条件id查询一个用户信息
- (void)getUserInfoByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                      result:
(void (^)(CCCallState state, CCNameSpace(CCResultUser) * info))block;
// 根据itemSet条件id查询一个用户信息，代理协议模式
- (void)getUserInfoByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                    delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 数据库接口区
// 根据itemSet条件id查询一个组织通讯录信息
- (void)getDepartInfoByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                           result:
(void (^)(CCCallState state, CCNameSpace(CCResultDepartment) * info))block;
// 根据itemSet条件id查询一个组织通讯录信息，代理协议模式
- (void)getDepartInfoByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                      delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 数据库接口区
// 根据itemSet条件id查询一个部门的上级所有节点信息
// NSMutableArray<CCNameSpace(CCResultDepartment) *> * parentList
- (void)getDepartAllParentsByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                              result:
(void (^)(CCCallState state, NSMutableArray * parentList))block;
// 根据itemSet条件id查询一个部门的上级所有节点信息
// NSMutableArray<CCNameSpace(CCResultDepartment) *> * parentList
- (void)getDepartAllParentsByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                            delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 数据库接口区
// 根据itemSet条件id查询一个部门的人数
// 返回值iCount：如果为-1则标识计算失败
- (void)getDepartCountByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                       likePath:(NSString *)likePath result:
(void (^)(CCCallState state, long iCount))block;
// 根据itemSet条件id查询一个部门的人数，代理协议模式
- (void)getDepartCountByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                       likePath:(NSString *)likePath
                      delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 数据库接口区
// 根据itemSet条件id设置一个部门的人数
- (void)setDepartCountByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                          count:(NSInteger)iCount result:
(void (^)(CCCallState state, bool isSetOk))block;
// 根据itemSet条件id设置一个部门的人数，代理协议模式
- (void)setDepartCountByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                          count:(NSInteger)iCount
                       delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 组织结构获取接口, PC SDK 版本使用
// 根据inList查询全部用户信息，结果填充进result中
- (void)getUsersInfoFromArrayList:(NSMutableArray *)uidList
                            result:
(void (^)(CCCallState state, CCNameSpace(CCRosterResult) * result))block;
// 根据inList查询全部用户信息，结果填充进result中，代理协议模式
- (void)getUsersInfoFromArrayList:(NSMutableArray *)uidList
                         delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 组织结构获取接口, PC SDK 版本使用
// 根据inList查询全部组织结构信息，结果填充进result中
- (void)getDepartInfoFromArrayList:(NSMutableArray *)didList
                             result:
(void (^)(CCCallState state, CCNameSpace(CCRosterResult) * result))block;
// 根据inList查询全部组织结构信息，结果填充进result中，代理协议模式
- (void)getDepartInfoFromArrayList:(NSMutableArray *)didList
                          delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

#pragma mark Upload & Download file

//@上传个人头像
//只能上传自己的头像，无需传入其他信息，只传入要发送的图片路径即可
- (void)uploadAvatarFile:(NSString *)filePath
                  result:
(void (^)(CCCallState state, CCNameSpace(CCAvatarUpFileResult) *uar))block;
//只能上传自己的头像，无需传入其他信息，只传入要发送的图片路径即可
- (void)uploadAvatarFile:(NSString *)filePath
                delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

//@下载个人头像
//返回值：是否下载到了服务器上的新头像
- (void)downloadAvatarFile:(CCNameSpace(CCItemInfo) *)itemSet
                    result:
(void (^)(CCCallState state, CCNameSpace(CCAvatarDownFileResult) *uar))block;
//下载个人头像，是否下载到了服务器上的新头像
- (void)downloadAvatarFile:(CCNameSpace(CCItemInfo) *)itemSet
                  delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

//@获取本地缓存内的头像，下载个人头像
- (void)getCacheAvatarFile:(CCNameSpace(CCItemInfo) *)itemSet
                    result:
(void (^)(CCCallState state, CCNameSpace(CCAvatarDownFileResult) *uar))block;
//@获取本地缓存内的头像，下载个人头像
- (void)getCacheAvatarFile:(CCNameSpace(CCItemInfo) *)itemSet
                  delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

//@上传消息的发送文件
//StUpResult UpLoadFile(StUpInfo const& sni,
//                      char const* tag = NULL,bool bThumbnail=false);
- (void)uploadMessageFile:(CCNameSpace(CCMethodUpFileInfo) *)sni
                      tag:(NSString *)tagStr thumbnail:(BOOL)bThumbnail
                   result:
(void (^)(CCCallState state, CCNameSpace(CCMethodUpFileResult) *result))block;
//@上传消息的发送文件
//StUpResult UpLoadFile(StUpInfo const& sni,
//                      char const* tag = NULL,bool bThumbnail=false);
- (void)uploadMessageFile:(CCNameSpace(CCMethodUpFileInfo) *)sni
                       tag:(NSString *)tagStr thumbnail:(BOOL)bThumbnail
                  delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

//@下载消息的发送文件
//StDownResult DownLoadFile(StDownInfo const& sni, char const* tag = NULL);
- (void)downloadMessageFile:(CCNameSpace(CCMethodDownFileInfo) *)sni
                        tag:(NSString *)tagStr
                     result:
(void (^)(CCCallState state, CCNameSpace(CCMethodDownFileResult) *result))block;
//@下载消息的发送文件
//StDownResult DownLoadFile(StDownInfo const& sni, char const* tag = NULL);
- (void)downloadMessageFile:(CCNameSpace(CCMethodDownFileInfo) *)sni
                        tag:(NSString *)tagStr
                   delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;


#pragma mark FixedGroup update

// 获取群列表, 需要与服务器交互，调用函数已单起线程
- (void)updateGroupListFromServer:(NSString *)strTag
                           result:(void (^)(CCCallState state))block;
- (void)updateGroupListFromServer:(NSString *)strTag
                         delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 获取群信息, 需要与服务器交互，调用函数已单起线程
- (void)updateGroupInfoFromServer:(NSString *)strTag
                          itemSet:(CCNameSpace(CCItemInfo) *)itemSet
                           result:(void (^)(CCCallState state))block;
- (void)updateGroupInfoFromServer:(NSString *)strTag
                          itemSet:(CCNameSpace(CCItemInfo) *)itemSet
                         delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;


// 获取群成员, 需要与服务器交互，调用函数已单起线程
- (void)updateGroupUsersFromServer:(NSString *)strTag
                           itemSet:(CCNameSpace(CCItemInfo) *)itemSet
                            result:(void (^)(CCCallState state))block;
- (void)updateGroupUsersFromServer:(NSString *)strTag
                           itemSet:(CCNameSpace(CCItemInfo) *)itemSet
                          delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

#pragma mark Query FixedGroup Or FixedGroupUser info

// 数据库接口区

// 获取群列表信息，当数据库更新后，获得相关数据
- (void)getGroupListByGetModeType:(CCGroupGetModeType)getMode
                           result:(void (^)(CCCallState state,
                                            NSMutableArray * retList))block;
- (void)getGroupListByGetModeType:(CCGroupGetModeType)getMode
                         delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 获取群详细信息，当数据库更新后，获得相关数据
- (void)getGroupInfoByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                       result:
(void (^)(CCCallState state,
          CCNameSpace(CCModelFixedGroupInfo) * result))block;
- (void)getGroupInfoByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                     delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 获取群详细用户列表信息，当数据库更新后，获得相关数据
- (void)getGroupUsersByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                        result:(void (^)(CCCallState state,
                                         NSMutableArray * retList))block;
- (void)getGroupUsersByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                      delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 获取单个群详细信息(包含成员)，当数据库更新后，获得相关数据
- (void)getGroupDetailsByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                          result:
(void (^)(CCCallState state,
          CCNameSpace(CCModelGroupDetails) * result))block;
- (void)getGroupDetailsByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                        delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;


#pragma mark FixedGroup action & message

// 创建群, 结构内对象非指针项为必填项，
// topic 指针项为选填, 非必填项需使用添加函数添加
// baseList - 用户明细
// NSMutableArray<CCNameSpace(CCGroupUser) *> baseList
- (void)sendCreateGroupToServer:(NSString *)strTag
                       anObject:(CCNameSpace(CCGroupCreate) *)anObject
                         result:(void (^)(CCCallState state))block;
- (void)sendCreateGroupToServer:(NSString *)strTag
                       anObject:(CCNameSpace(CCGroupCreate) *)anObject
                       delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 发送邀请其他人加入群, 邀请入群
// baseList - 用户明细
// NSMutableArray<CCNameSpace(CCGroupUser) *> baseList
- (void)sendGroupInviteToServer:(NSString *)strTag
                       anObject:(CCNameSpace(CCStGroupObject) *)anObject
                         result:(void (^)(CCCallState state))block;
- (void)sendGroupInviteToServer:(NSString *)strTag
                       anObject:(CCNameSpace(CCStGroupObject) *)anObject
                       delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 发送邀请反馈, 同意或拒绝他人的邀请
- (void)sendGroupInviteDealToServer:(NSString *)strTag
                       anObject:(CCNameSpace(CCStGroupInviteDeal) *)anObject
                         result:(void (^)(CCCallState state))block;
- (void)sendGroupInviteDealToServer:(NSString *)strTag
                       anObject:(CCNameSpace(CCStGroupInviteDeal) *)anObject
                       delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 发送申请加入群, join某个群
- (void)sendGroupApplyToServer:(NSString *)strTag
                      anObject:(CCNameSpace(CCStGroupJoinApple) *)itemSet
                        result:(void (^)(CCCallState state))block;
- (void)sendGroupApplyToServer:(NSString *)strTag
                      anObject:(CCNameSpace(CCStGroupJoinApple) *)itemSet
                      delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 发送申请入群反馈, 同意或拒绝他人申请
- (void)sendGroupApplyDealToServer:(NSString *)strTag
                      anObject:(CCNameSpace(CCStGroupInviteDeal) *)anObject
                        result:(void (^)(CCCallState state))block;
- (void)sendGroupApplyDealToServer:(NSString *)strTag
                      anObject:(CCNameSpace(CCStGroupInviteDeal) *)anObject
                      delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 发送群踢人, 踢某些人出群
// baseList - 用户明细
// NSMutableArray<CCNameSpace(CCGroupUser) *> baseList
- (void)sendGroupKitOutToServer:(NSString *)strTag
                       anObject:(CCNameSpace(CCStGroupObject) *)anObject
                         result:(void (^)(CCCallState state))block;
- (void)sendGroupKitOutToServer:(NSString *)strTag
                       anObject:(CCNameSpace(CCStGroupObject) *)anObject
                       delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 发送退群命令, quit某个群
- (void)sendQuitGroupToServer:(NSString *)strTag
                      anObject:(CCNameSpace(CCItemInfo) *)itemSet
                        result:(void (^)(CCCallState state))block;
- (void)sendQuitGroupToServer:(NSString *)strTag
                      anObject:(CCNameSpace(CCItemInfo) *)itemSet
                      delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 发送解散群命令, disbanded某个群
- (void)sendDropGroupToServer:(NSString *)strTag
                     anObject:(CCNameSpace(CCItemInfo) *)itemSet
                       result:(void (^)(CCCallState state))block;
- (void)sendDropGroupToServer:(NSString *)strTag
                     anObject:(CCNameSpace(CCItemInfo) *)itemSet
                     delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 发送设置管理员, 更改某些人管理员
// baseList - 用户明细
// NSMutableArray<CCNameSpace(CCGroupUser) *> baseList
- (void)sendGroupAdminToServer:(NSString *)strTag
                       anObject:(CCNameSpace(CCStGroupObject) *)anObject
                         result:(void (^)(CCCallState state))block;
- (void)sendGroupAdminToServer:(NSString *)strTag
                       anObject:(CCNameSpace(CCStGroupObject) *)anObject
                       delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 发送撤回管理员, 取消某些人管理员
// baseList - 用户明细
// NSMutableArray<CCNameSpace(CCGroupUser) *> baseList
- (void)sendGroupRecoverAdminToServer:(NSString *)strTag
                      anObject:(CCNameSpace(CCStGroupObject) *)anObject
                        result:(void (^)(CCCallState state))block;
- (void)sendGroupRecoverAdminToServer:(NSString *)strTag
                      anObject:(CCNameSpace(CCStGroupObject) *)anObject
                      delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 发送移交群主权限, 更改某人为群主
// baseList - 用户明细
// NSMutableArray<CCNameSpace(CCGroupUser) *> baseList
- (void)sendGroupOwnerToServer:(NSString *)strTag
                      anObject:(CCNameSpace(CCStGroupObject) *)anObject
                        result:(void (^)(CCCallState state))block;
- (void)sendGroupOwnerToServer:(NSString *)strTag
                      anObject:(CCNameSpace(CCStGroupObject) *)anObject
                      delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 发送设置群信息, 更改群信息
// baseList - 用户明细
// NSMutableArray<CCNameSpace(CCGroupUser) *> baseList
- (void)sendGroupVcardToServer:(NSString *)strTag
                      anObject:(CCNameSpace(CCStGroupObject) *)anObject
                        result:(void (^)(CCCallState state))block;
- (void)sendGroupVcardToServer:(NSString *)strTag
                      anObject:(CCNameSpace(CCStGroupObject) *)anObject
                      delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 发送设置群属性, 更改群属性
- (void)sendGroupAttributeToServer:(NSString *)strTag
                          anObject:(CCNameSpace(CCStGroupAttribute) *)anObject
                            result:(void (^)(CCCallState state))block;
- (void)sendGroupAttributeToServer:(NSString *)strTag
                          anObject:(CCNameSpace(CCStGroupAttribute) *)anObject
                          delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;


// 发送设置群接收设置, 设置群接收
- (void)sendGroupReceiveToServer:(NSString *)strTag
                        anObject:(CCNameSpace(CCItemInfo) *)itemSet
                      receiveSet:(CCGroupShowStatus)iReceiveSet
                          result:(void (^)(CCCallState state))block;
- (void)sendGroupReceiveToServer:(NSString *)strTag
                        anObject:(CCNameSpace(CCItemInfo) *)itemSet
                      receiveSet:(CCGroupShowStatus)iReceiveSet
                        delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;
// 发送群成员 信息
- (void)sendSetGroupMemberMessageToServer:(NSString *)strTag
                                 anObject:(CCNameSpace(CCStGroupMember) *)itemSet
                                   result:(void (^)(CCCallState state))block;
- (void)sendSetGroupMessageToServer:(NSString *)strTag
                                 anObject:(CCNameSpace(CCStGroupMember) *)itemSet
                                   result:(void (^)(CCCallState state))block;
// 发送群成员 申请信息
- (void)sendGroupMemberApplyMessageToServer:(NSString *)strTag
                                   anObject:(CCNameSpace(CCStGroupMemberApply) *)itemSet
                                     result:(void (^)(CCCallState state))block;
#pragma mark Search depart Or User info

// 搜索用户与部门信息
// 根据Option键值查询全部条目，结果填充进result中
- (void)searchAllInfosByOption:(CCNameSpace(CCGetOption) *)optionInfo
                        result:
(void (^)(CCCallState state, CCNameSpace(CCRosterResult) * result))block;
// 根据Option键值查询全部条目，结果填充进result中，代理协议模式
- (void)searchAllInfosByOption:(CCNameSpace(CCGetOption) *)optionInfo
                      delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 搜索用户
// 根据Option键值查询用户条目，结果填充进result中
- (void)searchUserInfosByOption:(CCNameSpace(CCGetOption) *)optionInfo
                         result:
(void (^)(CCCallState state, CCNameSpace(CCRosterResult) * result))block;
// 根据Option键值查询用户条目，结果填充进result中，代理协议模式
- (void)searchUserInfosByOption:(CCNameSpace(CCGetOption) *)optionInfo
                       delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 搜索部门
// 根据Option键值查询部门条目，结果填充进result中
- (void)searchDepartInfosByOption:(CCNameSpace(CCGetOption) *)optionInfo
                           result:
(void (^)(CCCallState state, CCNameSpace(CCRosterResult) * result))block;
// 根据Option键值查询部门条目，结果填充进result中，代理协议模式
- (void)searchDepartInfosByOption:(CCNameSpace(CCGetOption) *)optionInfo
                         delegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;


#pragma mark Query roster depart Or User tree list

// 获取所有级别的客户组织结构部门数据列表
- (void)getCustomerInfoFromLocal;
- (void)getCustomerInfoFromLocal:
(void (^)(CCCallState state, CCNameSpace(CCRosterResult) * result))block;
// 获取所有级别的客户组织结构部门数据列表，代理协议模式
- (void)getCustomerInfoFromLocalByDelegate:(id<CCNameSpace(CCServiceProtocol)>)delegate;

// 获取指定级别的客户部门数据cid不为空
// 当level>=0 获取指定级别的部门数据列表
- (void)getDepartInfoFromLocal:(NSString *)cidStr level:(int)iLevel
                        result:
(void (^)(CCCallState state, CCNameSpace(CCRosterResult) * result))block;
// 当level>=0 获取指定级别的部门数据列表，代理协议模式
- (void)getDepartInfoFromLocal:(NSString *)cidStr level:(int)iLevel
                      delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;

// 获取一个部门节点下的所有一级子节点，结果填充进result中
- (void)getChildrenFirstByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                           option:(CCNameSpace(CCGetOption) *)optionInfo
                           result:
(void (^)(CCCallState state, CCNameSpace(CCRosterResult) * result))block;
// 获取一个部门节点下的所有一级子节点，结果填充进result中，代理协议模式
- (void)getChildrenFirstByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                           option:(CCNameSpace(CCGetOption) *)optionInfo
                         delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;


// 获取某一个部门节点下的所有用户节点，包括子孙节点
// 结果集在getResultMap()中获取，结果填充进result中
- (void)getChildrenUsersByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                           option:(CCNameSpace(CCGetOption) *)optionInfo
                           result:
(void (^)(CCCallState state, CCNameSpace(CCRosterResult) * result))block;
// 获取某一个部门节点下的所有用户节点，包括子孙节点，代理协议模式
- (void)getChildrenUsersByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                           option:(CCNameSpace(CCGetOption) *)optionInfo
                         delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;

// 获取第一级子节点信息
// 详细分化 分别为获取第一级部门和第一级用户，结果填充进result中
- (void)getFirstLevelDepartByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                              option:(CCNameSpace(CCGetOption) *)optionInfo
                              result:
(void (^)(CCCallState state, CCNameSpace(CCRosterResult) * result))block;
// 获取第一级子节点信息，代理协议模式
- (void)getFirstLevelDepartByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                              option:(CCNameSpace(CCGetOption) *)optionInfo
                            delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;

// 获取第一级用户信息
// 详细分化 分别为获取第一级部门和第一级用户，结果填充进result中
- (void)getFirstLevelUsersByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                             option:(CCNameSpace(CCGetOption) *)optionInfo
                             result:
(void (^)(CCCallState state, CCNameSpace(CCRosterResult) * result))block;
// 获取第一级用户信息，代理协议模式
- (void)getFirstLevelUsersByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                             option:(CCNameSpace(CCGetOption) *)optionInfo
                           delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;

// 获取某一个节点所经过的所有节点，展开后需要加载的节点的集合
// 返回结果getResultMap()  包含list中所有部门展开时所需要的节点信息的集合
// 返回结果getResultList() 包含该节点经过的所有父节点集合，0~无限，逐级深入
- (void)getChildrenAllExpandByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                               option:(CCNameSpace(CCGetOption) *)optionInfo
                               result:
(void (^)(CCCallState state, CCNameSpace(CCRosterResult) * result))block;
// 获取某一个节点所经过的所有节点，展开后需要加载的节点的集合，代理协议模式
- (void)getChildrenAllExpandByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                               option:(CCNameSpace(CCGetOption) *)optionInfo
                             delegate:(id<CCNameSpace(CCServiceProtocol)>)serviceDelegate;
// 注册用户
- (void)registerUserInfoWith:(CCModelAccountRegisterModel *)registerModel result:(void (^)(CCCallState state))block;
// 获取注册用户
- (void)getRegisterUserInfoResult:(void (^)(CCCallState state,CCModelAccountRegisterModel * registerModel))block;
// 获取登录额用户列表
- (void)getLastUserAuthInfoList:
(void (^)(CCCallState state, NSArray * infoArray))block;
// 设置信息已读状态状态
- (void)setHistoryMsgStatusFromWebSocket:(CCHistoryMessage *) historyMessage result:(void (^)(CCCallState state))block;
// 设置信息状态
- (void)setHistoryMsgStatusFromWebSocket:(CCHistoryMessage *) historyMessage status:(CCSendState)iSendStatus result:(void (^)(CCCallState state))block;
// 获取更新服务器地址
- (void)getVersionUpdateRequestUrlWithType:(int)type result:(void (^)(NSString * requestUrl))block;
/// 根据type获取服务器地址
- (NSString *)getLocalServerWithType:(int)type result:(void (^)(NSString * serverAddress))block;
// 注销推送平台
- (void)unRegisterRemotePushNotification:(NSString *)msgId
                                pushInfo:(CCNameSpace(CCPlatformPushInfo) *)pushInfo
                                  result:(void (^)(CCCallState state))block;
// 退出登录 清理信息 关闭socket
- (void)afterLogOutCleanInfoAndClosedSocket;
// 检查当前websocket连接状态
- (BOOL)checkWebsocketByReadState:(BOOL)bResult;

//关联二维码
- (void)associatedToLoadQRCodeWithDeviceInfo:(NSDictionary *)diviceInfo result:(void (^)(CCCallState state,long errCode))block;

//授权二维码
- (void)authToLoadQRCodeWithDeviceInfo:(NSDictionary *)diviceInfo result:(void (^)(CCCallState state,long errCode))block;
//邀请方查询授权二维码
- (void)checkToLoadQRCodeWithDeviceInfo:(NSDictionary *)diviceInfo result:(void (^)(CCCallState state,long errCode,NSDictionary *dict))block;
//获取扫码登录设备列表
- (void)fatchQRCodeLoadDeviceListWithParams:(NSDictionary *)params result:(void (^)(CCCallState state,long errCode,NSMutableArray *deviceArray))block;

//退出扫码设备
- (void)kickOutQRCodeLoadDeviceWithParams:(NSDictionary *)params result:(void (^)(CCCallState state,long errCode))block;


/// 申请加入chatroom -- 1605
- (void)applyJoinChatRoomWithRoomId:(NSString *)roomId AppId:(NSString * )appId Msg:(NSString *)msg MsgId:(NSString *)msgId Tag:(NSString *)tag result:(void (^)(CCCallState state))block;
/// 申请退出chatroom -- 1607
- (void)applyOutChatRoomWithRoomId:(NSString *)roomId AppId:(NSString * )appId MsgId:(NSString *)msgId Tag:(NSString *)tag result:(void (^)(CCCallState state))block;
/// room公聊消息 -- 1701 1707 1725
- (void)sendPublicMsgToChatRoomWithHeadAttr:(NSDictionary *)attrDict MsgId:(NSString *)msgId CMD:(int)cmd ChatJson:(NSString *)chatJson result:(void (^)(CCCallState state))block;

/// 绑定其他app_id -- 103
- (void)bindAppIdWithAppId:(NSString * )appId MsgId:(NSString *)msgId result:(void (^)(CCCallState state))block;
/// 解绑其他app_id -- 105
- (void)unBindAppIdWithAppId:(NSString * )appId MsgId:(NSString *)msgId result:(void (^)(CCCallState state))block;
@end

#endif //_CC263_CCServiceManager_H_
