//
//  CCAdapterClass.h
//  test_adapter
//
//  Created by yiyimama on 17/4/5.
//  Copyright © 2017年 yiyimama. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCAdapterBase.h"

#import "CCModelKeyUtility.h"

// 服务的调用状态
enum MyAdapterStatus
{
    // 未调用状态
    MyStatusNone = (0ll),
    // 调用创建指针
    MyStatusInitialize = (1ll << 1),
    // 调用通过普通鉴权登陆
    MyStatusLoginAuth = (1ll << 7),
    // 调用通过普通鉴权登陆
    MyStatusLoginLocal = (1ll << 8),
    // 调用通过聊天Socket登陆
    MyStatusLoginWebSocket = (1ll << 9),
    // 关闭ccsdk的所有调用模式
    MyStatusUninitialize = (1ll << 31),
};
typedef enum MyAdapterStatus MyAdapterStatus;

@interface CCAdapterClass : NSObject
// 弱引用代理指针
@property (weak) id cacheDelegate;

// ccsdk的登录名
@property (strong) NSString * logName;
@property (assign) int captchaDiffer;
// ccsdk的登录密码
@property (strong) NSString * logPassword;
// ccsdk的登录appId
@property (strong) NSString * logAppId;
// ccsdk的服务器端口
@property (assign) signed int serverPort;
// ccsdk的服务器地址
@property (strong) NSString * serverAddress;
// ccsdk的登录状态，MyAdapterStatus
@property (assign) long long  logStatus;
// ccsdk的调用实例！认证信息
@property (strong) CCNameSpace(CCModelAuthInfo) * logInfo;
// ccsdk的调用实例！sdk指针
@property (strong) CCNameSpace(CCServiceManager) * manager;

// 初始化与代理模式
- (id)initWithDelegate:(id <CCNameSpace(CCServiceProtocol)>)delegate;

// 初始化当前实例
- (void)initializeService:(dispatch_block_t)callBlock;
// 反初始化当前实例！
- (void)uninitializeService:(dispatch_block_t)callBlock;

// 配置当前实例的初始化信息
//- (void)configureServiceClass;

// 当前时间值，毫秒
+ (uint64_t)currentTimeValue;

// 当前时间对像，参数毫秒值
+ (NSDate *)currentTimeDate:(uint64_t)value;

// 当前时间字符串，参数毫秒值
+ (NSString *)currentTimeString:(uint64_t)value;
+ (NSString *)md5Str:(NSString *)str;
// ccsdk的调用实例！sdk指针
- (CCNameSpace(CCServiceManager) *)shareManager;

#pragma mark Configure

// 全局数据库
- (NSString *)sdkDatabasePath;

- (void)setName:(NSString *)logName
           info:(NSString *)password;

- (void)setName:(NSString *)logName
           info:(NSString *)password
  captchaDiffer:(int)captchaDiffer;

- (void)setName:(NSString *)logName
           info:(NSString *)password
  captchaDiffer:(int)captchaDiffer appId:(NSString *)appId;
// 设置定位服务地址
- (void)setAddress:(NSString *)localAddress
              port:(signed int)localPort;
- (CCNameSpace(CCDeviceInfo) *)deviceInfo;
#pragma mark Login or Logout

// 当前用户是否是登陆状态
- (BOOL)isCurrentUserLoginIn;

// x.用户登陆，
// name 登陆的用户帐号，password 登陆类的用户密码
- (void)loginInForCurrentUser:(BOOL)isAuthMode result:
(void (^)(CCCallState state, CCNameSpace(CCLoginStateInfo) * logState))block;

// 0.用户退出登陆，退出当前已登陆的用户
- (void)loginOutForCurrentUser:(void (^)(CCCallState state))block;
//强制退出登录
- (void)forcedLoginOutForCurrentUser:(void (^)(CCCallState state))block;
// 登陆已经验证用户WebSocket连接
- (void)loginWebSocketWhenUserAuth:(void (^)(CCCallState state))block;

// 关闭已经验证的接入服务的网络连接
- (void)closeWebsocketForCurrentUser:(void (^)(CCCallState state))block;

// 检测到当前接入服务连接的状态！
- (void)OnWebsocketIsConnect:(NSString *)logName state:(CCCallState)state;

// 检测到当前接入服务是中断的状态！
- (void)OnWebsocketIsDisconnect:(long)lastError state:(CCCallState)state;

#pragma mark Query User info

// 根据uid与cid从数据库查询一个用户信息
- (void)getUserInfoFromLocal:(NSString *)uidStr
                         cid:(NSString *)cidStr
                      result:
(void (^)(CCCallState state, CCNameSpace(CCResultUser) * result))block;

// 根据uid与cid从服务器查询一个用户信息
- (void)getUserInfoFromServer:(NSString *)uidStr
                          cid:(NSString *)cidStr
                       result:
(void (^)(CCCallState state, CCNameSpace(CCResultUser) * result))block;

// 根据uid与cid从数据库查询一个用户信息,并返回用户的父级路径列表
- (void)getUserDepartsFromLocal:(NSString *)uidStr cid:(NSString *)cidStr
                         result:
(void (^)(CCCallState state,
          CCNameSpace(CCResultUser) * result, NSMutableArray * parentDeparts))block;


#pragma mark Query Roster Depart list

// 更新组织通讯录列表，新线程调用，异步模式！
- (void)updateRosterDataFromServer:(void (^)(CCCallState state))block;

// 从数据库查询所有客户信息列表接口
// retList 对像列表对像为 CCNodeBase * customerNode
- (void)getCurrentUserAllCustomerInfoList:
(void (^)(CCCallState state, NSMutableArray * retList))block;

// 从数据库查询根据客户cid查询客户的所有组织根节点列表
// retList 对像列表对像为 CCNodeBase * parentNode
- (void)getCurrentUserRootDepartmentInfoList:(NSString *)customerId
                                      result:
(void (^)(CCCallState state, NSMutableArray * retList))block;

// 查询并添加相关子节点的信息至 parentNode，id,与cid不为空
// wantsFillMaxDepth 当大于0时有效，最大限制向下添充多少级，多用户时延迟加载！
- (void)getCurrentUserChildrensToParentNode:(CCNodeBase *)parentNode
                              wantsMaxDepth:(NSInteger)wantsFillMaxDepth
                                  cachedMap:(NSMutableDictionary *)cachedNodeMap
                                 cachedOver:(void (^)(CCCallState state))block;

#pragma mark Read Message or Write Message

// 发送一条聊天消息，state == CCCallOK 代表入队成功，但未发送
- (void)writeMessage:(CCNameSpace(CCMessageSendBase) *)sendBody
              result:(void (^)(CCCallState state, CCSendState sendStatus))block;
// 消息同步
- (void)requestHistoryMsg:(CCHistoryMessage *)historyMessage FromWebSocket:(void (^)(CCCallState state/*, BOOL isOk*/))block;
- (NSString *)getUniqueIdentification;
- (void)getHistoryMessage:(CCHistoryMessage *)historyMessage FromDB:(void (^)(CCCallState state,
                                                                              NSMutableArray * list))block;
// 注册用户
- (void)registerUserInfoWith:(CCModelAccountRegisterModel *)registerModel result:(void (^)(CCCallState state))block;
// 获取注册用户
- (void)getRegisterUserInfoResult:(void (^)(CCCallState state,CCModelAccountRegisterModel * registerModel))block;


// 获取未读条数
- (void)getUnReadMsgCount:(CCNameSpace(CCHistoryMessage) *)history
                   result:(void (^)(CCCallState state,int unreadNumber))block;

// 获取未读消息列表
- (void)getAllMessageListWithHistoryMessage:(CCHistoryMessage *) historyMessage result:(void (^)(CCCallState state,CCNameSpace(CCMessageGetResult) * result))block;
/**
 设置同步的消息状态

 @param historyMessage update不为空时  设置的是update时间之前的为已读 否则是设置msgid为已读
 @param iSendStatus 消息状态 -- 暂时无用
 @param block 结果回调
 */
- (void)setHistoryMessageStatus:(CCHistoryMessage *)historyMessage status:(CCSendState)iSendStatus result:(void (^)(CCCallState state))block;
/**
 设置同步的消息状态 -- 为已读
 
 @param historyMessage update不为空时  设置的是update时间之前的为已读 否则是设置msgid为已读
 @param block 结果回调
 */
- (void)setHistoryMessageStatus:(CCHistoryMessage *)historyMessage result:(void (^)(CCCallState state))block;

// 获取更新服务器地址
- (void)getVersionUpdateRequestUrlWithType:(int)type result:(void (^)(NSString * requestUrl))block;
/// 根据type获取服务器地址
- (NSString *)getLocalServerWithType:(int)type result:(void (^)(NSString * serverAddress))block;
// 退出登录 清理信息 关闭socket
- (void)afterLogOutCleanInfoAndClosedSocket;
// 同步消息
- (void)syncHistoryMessage;
// 检查当前websocket连接状态
- (BOOL)checkWebsocketByReadState:(BOOL)bResult;

//关联二维码
- (void)associatedToLoadQRCodeWithDeviceInfo:(NSDictionary *)diviceInfo result:(void (^)(CCCallState state,long errCode))block;
//授权二维码
- (void)authToLoadQRCodeWithDeviceInfo:(NSDictionary *)diviceInfo result:(void (^)(CCCallState state,long errCode))block;

//邀请方查询授权二维码
- (void)checkLoadQRCodeWithDeviceInfo:(NSDictionary *)diviceInfo result:(void (^)(CCCallState state,long errCode,NSDictionary *info))block;

#pragma mark -- 获取扫码登录设备列表
- (void)fatchQRCodeLoadDeviceListWithParams:(NSDictionary *)params result:(void (^)(CCCallState state,long errCode,NSMutableArray *deviceArray))block;

#pragma mark -- 退出扫码设备
- (void)kickOutQRCodeLoadDeviceWithParams:(NSDictionary *)params result:(void (^)(CCCallState state,long errCode))block;

@end
