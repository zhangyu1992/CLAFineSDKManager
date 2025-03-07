//
//  CCGroupInfoManager.h
//  CCAdapterUI
//
//  Created by yiyimama on 2017/6/6.
//  Copyright © 2017年 yiyimama. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCObjectHeader.h"

#import "CCAdapterKeys.h"
#import "CCAdapterBase.h"
#import "CCAdapterClass.h"
#import "CCNotificationKeys.h"

#import "CCCommonHelper.h"
#import "CCCommonConfim.h"
#import "CCGroupInfoManagerProtocol.h"

#define CCCroupCleanUserInfo (0x0)

@interface CCGroupInfoManager : NSObject

//单例管理对像
+ (id)shareGroupInfoManager;

+ (NSString *)getUniqueIdentification;

// 代理对象 -- 接收到的代理回调
@property (nonatomic, weak) id <CCGroupInfoManagerDelegate> groupReceiveInfoDelegate;

@property (nonatomic, strong) NSHashTable * delegateArray;

//群人员信息
//@property (nonatomic, strong) NSMutableDictionary * mUserInfos;
//群组信息 CCNameSpace(CCModelFixedGroupInfo)
@property (nonatomic, strong) NSMutableDictionary * mGroupInfos;
//群组用户信息 CCNameSpace(CCModelFixedGroupUserInfo)
//@property (nonatomic, strong) NSMutableArray * mGroupUserList;
@property (nonatomic, strong) NSMutableDictionary * mGroupUserInfos;
//临时会话信息 CCNameSpace(CCModelTempGroupInfo)
@property (nonatomic, strong) NSMutableDictionary * mTempGroupInfos;
//临时会话用户信息 CCNameSpace(CCModelTempGroupUserInfo)
//@property (nonatomic, strong) NSMutableArray * mTempGroupUserList;
@property (nonatomic, strong) NSMutableDictionary * mTempGroupUserInfos;
//群组信息更新队列
@property (nonatomic, strong) CCNameSpace(CCThreadQueue) * groupQueue;
//群组发送信息更新队列
@property (nonatomic, strong) CCNameSpace(CCThreadQueue) * groupActionQueue;

// 服务器下载群组信息
- (void)downloadGroupListFromServer;

// 服务器下载群组信息
- (void)downloadGroupListFromServer:(void (^)(CCCallState state))block;

// 当成功登陆后从数据库中获得群组信息
- (void)reloadGroupInfosFromDataBase:(void (^)(CCCallState state))block;

//// 从内存缓存中获得群组信息
//- (void)queryGroupInfosFromMemoryCached:
//(void (^)(CCCallState state, NSMutableArray * retGroupList))block;
//
//// 从内存缓存中查询一个群组的信息
//- (void)queryGroupInfoFromMemoryCached:(NSString *)gidStr cid:(NSString *)cidStr
//                            result:
//(void (^)(CCCallState state, CCNameSpace(CCModelFixedGroupInfo) * retInfo))block;
//
//// 从内存缓存中查询一个群组的用户列表信息
//- (void)queryGroupUserListFromMemoryCached:(NSString *)gidStr cid:(NSString *)cidStr
//                                    result:
//(void (^)(CCCallState state, NSMutableArray * retGroupUserList))block;
//
//// 从内存缓存中查询一个群组的用户列表，返回字典结构信息
//- (void)queryGroupUserInfosFromMemoryCached:(NSString *)gidStr cid:(NSString *)cidStr
//                                     result:
//(void (^)(CCCallState state, NSMutableDictionary * retGroupUserInfos))block;


// 成功后发送群组发送对像的状态
- (void)groupInfoChangedSendWithObject:(NSDictionary *)info;

// 成功后接收后群组接收对像的状态
- (void)groupInfoChangedRecvWithObject:(NSDictionary *)info; // post notify

// 缓存群组发送对像的状态
- (void)addGroupMethodWithUuid:(NSString *)uuidStr
                   commandType:(NSInteger)commandType sendObject:(id)requestInfo;
// 缓存群组发送对像的状态
- (void)addGroupMethodWithUuid:(NSString *)uuidStr
                   commandType:(NSInteger)commandType sendObject:(id)requestInfo
                  actionObject:(id)actionObject;
// 删除缓存的群组发送对像
- (void)delGroupMethodWithUuid:(NSString *)uuidStr
                        result:(CCNameSpace(CCMessageResult) *)result;

@end
