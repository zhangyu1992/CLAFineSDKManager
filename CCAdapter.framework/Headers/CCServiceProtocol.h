//
//  CCServiceProtocol.h
//  adapter
//
//  Created by yiyimama on 17/3/24.
//  Copyright © 2017年 zsx. All rights reserved.
//

#ifndef _CC263_CCServiceProtocol_H
#define _CC263_CCServiceProtocol_H

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCModelBase.h"
#import "CCModelMethod.h"
#import "CCModelGroup.h"
#import "CCModelMessage.h"
#import "CCServiceTypes.h"

// 服务管理协议
@class CCNameSpace(CCServiceManager);

// 网络状态回调协议
@protocol CCNameSpace(CCReachabilityProtocol) <NSObject>

@required //必要的

#pragma mark Reachability

@optional //可选的

// 当前WiFi网络连接状态
- (BOOL)isWiFiReachability:(CCNameSpace(CCServiceManager) *)service;

// 如果WiFi为FALSE状态时，询问当前WWAN网络连接状态
- (BOOL)isInternetReachability:(CCNameSpace(CCServiceManager) *)service;

@end

// 服务状态回调协议
@protocol CCNameSpace(CCServiceProtocol) <NSObject>

@required //必要的

@optional //可选的

#pragma mark Configuration

// 1.初始化服务管理类，创建调用实例指针，阻塞至调用完成！
- (void)OnInitializeService:(CCCallState)error;

// x.反初始化服务管理类，将删除调用实例指针（test），回调回来后清理完成！
- (void)OnUninitializeService:(CCCallState)error;

// 2.设置全局数据库的路径与数据库打开密码，代理方式回调
- (void)OnSetSdkDatabasePath:(NSString *)path
                        info:(NSString *)password
                       state:(CCCallState)state;

// 2.设置用户数据库的路径与数据库打开密码，代理方式回调
- (void)OnSetUserDatabasePath:(NSString *)path
                         info:(NSString *)password
                        state:(CCCallState)state;

// 获取全局配置数据，需要先打开全局数据库
- (void)OnGetSdkConfig:(NSString *)key
                 value:(NSString *)value;

// 设置全局配置数据，需要先打开全局数据库
- (void)OnSetSdkConfig:(NSString *)key value:(NSString *)value
                 state:(CCCallState)state;

// 获取用户配置数据，需要先打开用户数据库，不区分用户名
- (void)OnGetUserConfig:(NSString *)key
                  value:(NSString *)value;

// 设置用户配置数据，需要先打开用户数据库，不区分用户名v
- (void)OnSetUserConfig:(NSString *)key value:(NSString *)value
                  state:(CCCallState)state;

// 3.设置设备信息，如果没有设备信息，将在回调中查询信息
- (void)OnSetDeviceInfo:(CCNameSpace(CCDeviceInfo) *)deviceInfo
                  state:(CCCallState)state;

// 获得服务器地址与端口，@"host", @"port"
- (void)OnGetServerAddress:(NSDictionary *)addressInfo;

// 4.设置服务器地址与端口，代理方式回调
- (void)OnSetServerAddress:(NSString *)ipStr port:(short)portVal
                     state:(CCCallState)state;

// 数据库清理数据内容接口，
// 用户的数据清理要等登陆成功后，才可以清理当前的登陆用户的数据
- (void)OnCleanDatabaseCacheDataWithType:(CCCacheType)iType
                                   state:(CCCallState)state;

#pragma mark Login in

// 5.用户登陆，name 登陆的用户帐号，password 登陆类的用户密码
- (void)OnLoginInWithLoginName:(NSString *)logName
                          info:(NSString *)logPassword
                         state:(CCCallState)state;

// 5.用户登陆，name 登陆的用户帐号，password 登陆类的用户密码
// 其中 localState 是定位服务状态码，loginState 是认证服务状态码
- (void)OnLoginInWithLoginName:(NSString *)logName
                          info:(NSString *)logPassword
                         state:(CCCallState)state
                    loginState:(CCNameSpace(CCLoginStateInfo) *)logState;

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

// 7.用户退出登陆，退出当前已登陆的用户
- (void)OnLoginOutForCurrentUser:(CCNameSpace(CCModelAuthInfo) *)info
                           state:(CCCallState)state;

// 获得服务器的当前状态值，位操作值的合集，单独测试位是否存在
//CCHasBits(sdkStatus, CCSdkStatusLoginAuth);
//CCHasBits(sdkStatus, CCSdkStatusLoginLocalName);
- (void)OnGetSdkStatus:(long long)sdkStatus state:(CCCallState)state;


// 获得适配层的当前主存储目录，根据全局目录相对生成
- (void)OnGetSdkPathWithType:(CCSdkPathType)type
                      result:(NSString *)sdkPath state:(CCCallState)state;

#pragma mark Login in auth user info

// 获取最后登录的用户的信息
- (void)OnGetLastUserAuthInfo:(CCNameSpace(CCModelAuthInfo) *)info
                        state:(CCCallState)state;

// 获取当前登录的用户的信息
- (void)OnGetCurrentUserAuthInfo:(CCNameSpace(CCModelAuthInfo) *)info
                           state:(CCCallState)state;

// 获取根据用户名列出对应的登录用户的信息
- (void)OnGetUserAuthInfoByName:(NSString *)logName
                           info:(CCNameSpace(CCModelAuthInfo) *)info
                          state:(CCCallState)state;

#pragma mark Session manager

// 会话列表数据维护 CCNameSpace(CCSessionInfo)
- (void)OnGetSessionList:(NSMutableArray *)list // list NSObjects
                   state:(CCCallState)state;

// 获得某个会话的项目主动推送更新
- (void)OnSessionUpdate:(CCNameSpace(CCSessionInfo) *)result
                  state:(CCCallState)state;

// 获得某个会话的项目
- (void)OnGetOneSession:(CCNameSpace(CCItemInfo) *)itemSet
                 result:(CCNameSpace(CCSessionInfo) *)result
                  state:(CCCallState)state;

// 添加一个会话的项目，传入uid,cid不为空，会话信息可从最后一条消息中查询
- (void)OnAddOneSession:(CCNameSpace(CCSessionInfo) *)info
                  state:(CCCallState)state;

// 移除一个会话的项目，传入uid,cid 或是 gid,cid，不会删除消息库中的聊天记录
- (void)OnRemoveOneSession:(CCNameSpace(CCItemInfo) *)itemSet
                    result:(CCNameSpace(CCSessionInfo) *)result
                     state:(CCCallState)state;

// 设置一个会话消息未读数字 id, cid, 不为空
- (void)OnSetUnReadNumber:(CCNameSpace(CCItemInfo) *)itemSet
                    count:(int)iReadNumber
                    state:(CCCallState)state;

// 清除一个会话消息未读数字 id, cid, 不为空
- (void)OnClearUnReadNumber:(CCNameSpace(CCItemInfo) *)itemSet
                      state:(CCCallState)state;

#pragma mark Message manager

// 网络连接PING
- (void)OnPingWebsocket:(BOOL)isPing state:(CCCallState)state;

// 测试用户接入服务是否成功！
- (void)OnLoginWebSocketWhenAuth:(NSString *)loginName
                       errorCode:(int)iStateCode state:(CCCallState)state;

// 关闭网络连接
- (void)OnCloseWebsocket:(CCCallState)state;

// 测试接入服务是否成功！
- (void)OnWebsocketIsLinked:(BOOL)isLinked state:(CCCallState)state;

// 检测到当前接入服务连接的状态！
- (void)OnWebsocketIsConnect:(NSString *)logName state:(CCCallState)state;

// 检测到当前接入服务是中断的状态！
- (void)OnWebsocketIsDisconnect:(long)lastError state:(CCCallState)state;

// 获取未读消息 登录成功之后调用，获得调用状态
- (void)OnGetOffLineMsgFromWebSocket:(CCCallState)state;

// 读取了一条聊天消息, 主动接收的推送消息！
- (void)OnReadMessage:(CCNameSpace(CCMessageResult) *)result
                state:(CCCallState)state;

// 读取了一条控制的消息, 主动接收的推送消息！
- (void)OnReadServerNotify:(CCNameSpace(CCMessageResult) *)result
                     state:(CCCallState)state;

// 调用发送一条聊天消息，调用代理
- (void)OnWriteDelegate:(CCNameSpace(CCMessageSendBase) *)send
                  state:(CCCallState)state status:(CCSendState)sendStatus;

// 发送了一条聊天消息，队列调用发送后
- (void)OnWriteMessage:(CCNameSpace(CCMessageSendBase) *)send
                 state:(CCCallState)state;

// 发送了一条聊天消息，发送失败
- (void)OnWriteMessageFailed:(CCNameSpace(CCMessageSendBase) *)send
                       state:(CCCallState)state;

// 发送了一条聊天消息，发送未知类型
- (void)OnWriteMessageUnknow:(CCNameSpace(CCMessageSendBase) *)send
                       state:(CCCallState)state;

// 调用发送一条聊天消息，调用代理
- (void)OnSaveMessageToLocal:(CCNameSpace(CCMessageSendBase) *)send
                       state:(CCCallState)state status:(BOOL)isSaved;


// 设置一个消息的发送状态或接收状态信息
- (void)OnSetMessageStatus:(NSString *)messageId
                    status:(CCSendState)iSendStatus
                 itemOwner:(CCItemInfoType)itemType
                     state:(CCCallState)state;

// 删除一条信息条目，messageId不为空
- (void)OnDeleteMessageByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                       messageId:(NSString *)messageId
                           state:(CCCallState)state;

// 删除多条信息条目，CCGetConfig 是一个约定范围的结构信息
- (void)OnDeleteMessageByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                          config:(CCNameSpace(CCGetConfig) *)getConfig
                           state:(CCCallState)state;

// 获取历史消息记录, CCGetConfig 是一个约定查询范围的结构信息
- (void)OnGetHistoryMessages:(CCNameSpace(CCItemInfo) *)itemSet
                      config:(CCNameSpace(CCGetConfig) *)getConfig
                      result:(CCNameSpace(CCMessageGetResult) *)result
                       state:(CCCallState)state;

#pragma mark Roster update

// 7.获得需要更新的组织列表数据大小，根据网络是否要执行更新
- (void)OnGetNeedUpdateRosterSize:(long)dataSize state:(CCCallState)state;

// 7.1 获得更新数据大小, 更新组织通讯录列表，代理方式回调
- (void)OnUpdateRosterDataFromServer:(CCCallState)state;

// 7.2 获得全新的组织数据, 刷新组织通讯录列表，代理方式回调
- (void)OnDownloadRosterDataFromServer:(CCCallState)state;

#pragma mark Query depart Or User info

// 根据itemSet条件id查询一个用户信息，代理方式回调
- (void)OnGetUserInfoFromServer:(CCNameSpace(CCItemInfo) *)itemSet
                       result:(CCNameSpace(CCResultUser) *)result
                          state:(CCCallState)state;

// 根据itemSet条件id查询一个用户信息，代理方式回调
- (void)OnGetUserInfoByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                        result:(CCNameSpace(CCResultUser) *)result
                         state:(CCCallState)state;

// 根据itemSet条件id查询一个组织通讯录信息，代理方式回调
- (void)OnGetDepartInfoByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                        result:(CCNameSpace(CCResultDepartment) *)result
                           state:(CCCallState)state;

// 根据itemSet条件id查询一个部门的上级所有节点信息
// NSMutableArray<CCNameSpace(CCResultDepartment) *> * parentList
- (void)OnGetDepartAllParentsByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                                result:(NSMutableArray *)parentList
                                 state:(CCCallState)state;

// 根据itemSet条件id查询一个部门的人数，代理协议模式
- (void)OnGetDepartCountByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                         likePath:(NSString *)likePath count:(long)iCount
                            state:(CCCallState)state;

// 根据itemSet条件id设置一个部门的人数，代理协议模式
- (void)OnSetDepartCountByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                            count:(NSInteger)iCount isSetOk:(bool)isSetOk
                            state:(CCCallState)state;

// 组织结构获取接口, PC SDK 版本使用
// 根据inList查询全部用户信息，结果填充进，result中
- (void)OnGetUsersInfoFromArrayList:(NSMutableArray *)inUidList
                           result:(CCNameSpace(CCRosterResult) *)result
                              state:(CCCallState)state;
// 组织结构获取接口, PC SDK 版本使用
// 根据inList查询全部组织结构信息，结果填充进inList，result中
- (void)OnGetDepartInfoFromArrayList:(NSMutableArray *)inDidList
                            result:(CCNameSpace(CCRosterResult) *)result
                               state:(CCCallState)state;

#pragma mark Upload & Download file

//@上传个人头像
//只能上传自己的头像，无需传入其他信息，只传入要发送的图片路径即可
- (void)OnUploadAvatarFile:(NSString *)filePath
                    result:(CCNameSpace(CCAvatarUpFileResult) *)uar
                     state:(CCCallState)state;

//返回值：是否下载到了服务器上的新头像
- (void)OnDownloadAvatarFile:(CCNameSpace(CCItemInfo) *)itemSet
                      result:(CCNameSpace(CCAvatarDownFileResult) *)uar
                       state:(CCCallState)state;

//@获取本地缓存内的头像，下载个人头像
- (void)OnGetCacheAvatarFile:(CCNameSpace(CCItemInfo) *)itemSet
                      result:(CCNameSpace(CCAvatarDownFileResult) *)uar
                       state:(CCCallState)state;

//@上传消息的发送文件
- (void)OnUploadMessageFile:(CCNameSpace(CCMethodUpFileInfo) *)sni
                        tag:(NSString *)tagStr thumbnail:(BOOL)bThumbnail
                     result:(CCNameSpace(CCMethodUpFileResult) *)result
                      state:(CCCallState)state;

//@下载消息的发送文件
- (void)OnDownloadMessageFile:(CCNameSpace(CCMethodDownFileInfo) *)sni
                          tag:(NSString *)tagStr
                       result:(CCNameSpace(CCMethodDownFileResult) *)result
                        state:(CCCallState)state;

#pragma mark FixedGroup update

// 获取群列表, 需要与服务器交互，调用函数已单起线程
- (void)OnUpdateGroupListFromServer:(NSString *)strTag
                              state:(CCCallState)state;

// 获取群信息, 需要与服务器交互，调用函数已单起线程
- (void)OnUpdateGroupInfoFromServer:(NSString *)strTag
                            itemSet:(CCNameSpace(CCItemInfo) *)itemSet
                              state:(CCCallState)state;

// 获取群成员, 需要与服务器交互，调用函数已单起线程
- (void)OnUpdateGroupUsersFromServer:(NSString *)strTag
                             itemSet:(CCNameSpace(CCItemInfo) *)itemSet
                               state:(CCCallState)state;


#pragma mark Query FixedGroup Or FixedGroupUser info

// 获取群列表信息，当数据库更新后，获得相关数据
- (void)OnGetGroupListByGetModeType:(CCGroupGetModeType)getMode
                             result:(NSMutableArray *)retList
                              state:(CCCallState)state;

// 获取群详细信息，当数据库更新后，获得相关数据
- (void)OnGetGroupInfoByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                         result:(CCNameSpace(CCModelFixedGroupInfo) *)result
                          state:(CCCallState)state;

// 获取群详细用户列表信息，当数据库更新后，获得相关数据
- (void)OnGetGroupUsersByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                          result:(NSMutableArray *)retList
                           state:(CCCallState)state;

// 获取单个群详细信息(包含成员)，当数据库更新后，获得相关数据
- (void)OnGetGroupDetailsByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                            result:(CCNameSpace(CCModelGroupDetails) *)result
                             state:(CCCallState)state;

#pragma mark FixedGroup message

// 创建群, 结构内对象非指针项为必填项，
// topic 指针项为选填, 非必填项需使用添加函数添加
// NSMutableArray<CCNameSpace(CCGroupUser) *> baseList
- (void)OnSendCreateGroupToServer:(NSString *)strTag
                         anObject:(CCNameSpace(CCGroupCreate) *)anObject
                            state:(CCCallState)state;

// 发送邀请其他人加入群, 邀请入群
// NSMutableArray<CCNameSpace(CCGroupUser) *> baseList
- (void)OnSendGroupInviteToServer:(NSString *)strTag
                         anObject:(CCNameSpace(CCStGroupObject) *)anObject
                            state:(CCCallState)state;

// 发送邀请反馈, 同意或拒绝他人的邀请
- (void)OnSendGroupInviteDealToServer:(NSString *)strTag
                         anObject:(CCNameSpace(CCStGroupInviteDeal) *)anObject
                            state:(CCCallState)state;

// 发送申请加入群, join某个群
- (void)OnSendGroupApplyToServer:(NSString *)strTag
                        anObject:(CCNameSpace(CCStGroupJoinApple) *)itemSet
                           state:(CCCallState)state;

// 发送申请入群反馈, 同意或拒绝他人申请
- (void)OnSendGroupApplyDealToServer:(NSString *)strTag
                         anObject:(CCNameSpace(CCStGroupInviteDeal) *)anObject
                            state:(CCCallState)state;

// 发送群踢人, 踢某些人出群
// NSMutableArray<CCNameSpace(CCGroupUser) *> baseList
- (void)OnSendGroupKitOutToServer:(NSString *)strTag
                         anObject:(CCNameSpace(CCStGroupObject) *)anObject
                            state:(CCCallState)state;

// 发送退群命令, quit某个群
- (void)OnSendQuitGroupToServer:(NSString *)strTag
                       anObject:(CCNameSpace(CCItemInfo) *)itemSet
                          state:(CCCallState)state;

// 发送解散群命令, disbanded某个群
- (void)OnSendDropGroupToServer:(NSString *)strTag
                       anObject:(CCNameSpace(CCItemInfo) *)itemSet
                          state:(CCCallState)state;

// 发送设置管理员, 更改某些人管理员
// NSMutableArray<CCNameSpace(CCGroupUser) *> baseList
- (void)OnSendGroupAdminToServer:(NSString *)strTag
                        anObject:(CCNameSpace(CCStGroupObject) *)anObject
                           state:(CCCallState)state;

// 发送撤回管理员, 取消某些人管理员
// NSMutableArray<CCNameSpace(CCGroupUser) *> baseList
- (void)OnSendGroupRecoverAdminToServer:(NSString *)strTag
                             anObject:(CCNameSpace(CCStGroupObject) *)anObject
                                state:(CCCallState)state;

// 发送移交群主权限, 更改某人为群主
// NSMutableArray<CCNameSpace(CCGroupUser) *> baseList
- (void)OnSendGroupOwnerToServer:(NSString *)strTag
                        anObject:(CCNameSpace(CCStGroupObject) *)anObject
                           state:(CCCallState)state;

// 发送设置群信息, 更改群信息
// NSMutableArray<CCNameSpace(CCGroupUser) *> baseList
- (void)OnSendGroupVcardToServer:(NSString *)strTag
                        anObject:(CCNameSpace(CCStGroupObject) *)anObject
                           state:(CCCallState)state;

// 发送设置群属性, 更改群属性
- (void)OnSendGroupAttributeToServer:(NSString *)strTag
                          anObject:(CCNameSpace(CCStGroupAttribute) *)anObject
                               state:(CCCallState)state;

// 发送设置群接收设置, 设置群接收
- (void)OnSendGroupReceiveToServer:(NSString *)strTag
                          anObject:(CCNameSpace(CCItemInfo) *)itemSet
                        receiveSet:(CCGroupShowStatus)iReceiveSet
                             state:(CCCallState)state;


#pragma mark Search depart Or User info

// 搜索用户与部门信息
// 根据Option键值查询全部条目，结果填充进result中
- (void)OnSearchAllInfosByOption:(CCNameSpace(CCGetOption) *)optionInfo
                        result:(CCNameSpace(CCRosterResult) *)result
                           state:(CCCallState)state;

// 搜索用户
// 根据Option键值查询用户条目，结果填充进result中
- (void)OnSearchUserInfosByOption:(CCNameSpace(CCGetOption) *)optionInfo
                         result:(CCNameSpace(CCRosterResult) *)result
                            state:(CCCallState)state;

// 搜索部门
// 根据Option键值查询部门条目，结果填充进result中
- (void)OnSearchDepartInfosByOption:(CCNameSpace(CCGetOption) *)optionInfo
                           result:(CCNameSpace(CCRosterResult) *)result
                              state:(CCCallState)state;

//
#pragma mark Query roster depart Or User list

// 获取所有级别的客户组织结构部门数据列表
- (void)OnGetCustomerInfoFromLocal:(CCNameSpace(CCRosterResult) *)result
                             state:(CCCallState)state;

// 获取指定级别的客户部门数据cid不为空
// 当level>=0 获取指定级别的部门数据列表
- (void)OnGetDepartInfoFromLocal:(NSString *)cidStr level:(int)iLevel
                          result:(CCNameSpace(CCRosterResult) *)result
                           state:(CCCallState)state;

// 获取一个部门节点下的所有一级子节点，结果填充进result中
- (void)OnGetChildrenFirstByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                             option:(CCNameSpace(CCGetOption) *)optionInfo
                             result:(CCNameSpace(CCRosterResult) *)result
                              state:(CCCallState)state;

// 获取某一个部门节点下的所有用户节点，包括子孙节点
// 结果集在getResultMap()中获取，结果填充进result中
- (void)OnGetChildrenUsersByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                             option:(CCNameSpace(CCGetOption) *)optionInfo
                             result:(CCNameSpace(CCRosterResult) *)result
                              state:(CCCallState)state;

// 获取第一级子节点信息
// 详细分化 分别为获取第一级部门和第一级用户，结果填充进result中
- (void)OnGetFirstLevelDepartByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                                option:(CCNameSpace(CCGetOption) *)optionInfo
                                result:(CCNameSpace(CCRosterResult) *)result
                                 state:(CCCallState)state;

// 获取第一级用户信息
// 详细分化 分别为获取第一级部门和第一级用户，结果填充进result中
- (void)OnGetFirstLevelUsersByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                               option:(CCNameSpace(CCGetOption) *)optionInfo
                               result:(CCNameSpace(CCRosterResult) *)result
                                state:(CCCallState)state;

// 获取某一个节点所经过的所有节点，展开后需要加载的节点的集合
// 返回结果getResultMap()  包含list中所有部门展开时所需要的节点信息的集合
// 返回结果getResultList() 包含该节点经过的所有父节点集合，0~无限，逐级深入
- (void)OnGetChildrenAllExpandByItemSet:(CCNameSpace(CCItemInfo) *)itemSet
                                 option:(CCNameSpace(CCGetOption) *)optionInfo
                                 result:(CCNameSpace(CCRosterResult) *)result
                                  state:(CCCallState)state;

@end

#endif /* _CC263_CCServiceProtocol_H */
