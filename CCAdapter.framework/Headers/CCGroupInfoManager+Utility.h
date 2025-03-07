//
//  CCGroupInfoManager+Utility.h
//  CCAdapterUI
//
//  Created by yiyimama on 2017/6/7.
//  Copyright © 2017年 yiyimama. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCGroupInfoManager.h"

@interface CCGroupInfoManager()

//@property (nonatomic) CCAdapterManager * appDelegate;

// 是否从数据库加载了群组信息
@property (nonatomic, assign) BOOL mLoadGroupInfosFromDataBase;
// 是否从数据库加载了临时会话组信息
@property (nonatomic, assign) BOOL mLoadTempGroupInfosFromDataBase;

////管理队列
#if OS_OBJECT_USE_OBJC
@property (nonatomic, strong) dispatch_queue_t mGroupUpdateQueue;
#else
@property (nonatomic, assign) dispatch_queue_t mGroupUpdateQueue;
#endif

@end

@interface CCGroupInfoManager (Utility)
//@interface CCGroupInfoManager_Utility : NSObject

// 更新群组列表信息
- (void)updateAllGroupListFromServer:(void (^)(CCCallState state))block;

// 更新群组详细信息，等待完成模式！
- (void)updateAllGroupInfosFromServer:(void (^)(CCCallState state,NSMutableArray *groupList))block;

// 更新一个群组详细信息，等待完成模式！
- (void)updateOneGroupInfoFromServer:(CCNameSpace(CCModelFixedGroupInfo) *)info
                              result:(void (^)(CCCallState state))block;

// 从数据库中获得群组信息
- (void)queryGroupInfosFromDataBase:
(void (^)(CCCallState state, NSMutableArray * retGroupList))block;

// 从数据库查询一个群组的信息
- (void)queryGroupInfoFromDataBase:(NSString *)gidStr cid:(NSString *)cidStr
                            result:
(void (^)(CCCallState state, CCNameSpace(CCModelFixedGroupInfo) * retInfo))block;

// 从数据库查询一个群组的信息, 是否查询用户信息
- (void)queryGroupInfoFromDataBase:(NSString *)gidStr cid:(NSString *)cidStr
                         queryUser:(BOOL)queryUserState result:
(void (^)(CCCallState state, CCNameSpace(CCModelFixedGroupInfo) * retInfo))block;

// 从数据库查询一个群组的用户列表信息
- (void)queryGroupUserListFromDataBase:(NSString *)gidStr cid:(NSString *)cidStr
                                result:
(void (^)(CCCallState state, NSMutableArray * retGroupUserList))block;

// 从数据库查询一个群组的用户列表，返回字典结构信息
- (void)queryGroupUserInfosFromDataBase:(NSString *)gidStr cid:(NSString *)cidStr
                                result:
(void (^)(CCCallState state, NSMutableDictionary * retGroupUserInfos))block;






@end
