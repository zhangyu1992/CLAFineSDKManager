//
//  CCUserInfoManager+Utility.h
//  CCAdapterUI
//
//  Created by jinxiangkun on 2017/5/31.
//  Copyright © 2017年 yiyimama. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCAdapterBase.h"

#import "CCUserInfoManager.h"

// code from CCAdapterClass

//遍历的中断key
#define CCRunBreak @"Break"
//遍历时发现用户的回调
typedef void (^CCResultNodeBlock)
(CCCallState state, CCNameSpace(CCModelNodeInfo) * obj,
NSMutableDictionary * actionObject); //如果存在中断，则不再继续执行

@interface CCUserInfoManager()

//队列
#if OS_OBJECT_USE_OBJC
@property (strong) dispatch_queue_t mUserInfoQueue;
#else
@property (assign) dispatch_queue_t mUserInfoQueue;
#endif

//组
#if OS_OBJECT_USE_OBJC
@property (strong) dispatch_group_t mUserInfoGroup;
#else
@property (assign) dispatch_group_t mUserInfoGroup;
#endif

#pragma mark Old Roster infos
//用户信息
@property (strong) NSMutableDictionary * mUserInfos;
//组织结构信息
@property (strong) NSMutableDictionary * mDepartmentInfos;
//联系人结构
@property (strong) NSMutableDictionary * mContractInfos;
//当前的，组织结构联系人结构
@property (strong) NSMutableArray * mDepartmentArray;
//当前的，常用联系人联系人结构
@property (strong) NSMutableArray * mFrequentContractInfos;
//搜索block
@property (strong) CCContractsSearchResultsBlock mSearchResultsBlock;

@end

@interface CCUserInfoManager (Utility)
//@interface CCUserInfoManager_Utility : NSObject

// 当前的登陆用户名
- (NSString *)logName;

/////////////////////////////////////////////////////////////////

// 添充一个根节点列表的对像
- (void)testAllDepartmentInfos:(BOOL)isCacheUser
                     cachedMap:(NSMutableDictionary *)cachedNodeMap
                        result:
(void (^)(CCCallState state, NSMutableArray * retList))block;

// 获得一个展开组织级用户的数量
- (void)resetCachedDepartmentCount:(NSMutableArray *)deptList
                            result:
(void (^)(CCCallState state,
          CCNameSpace(CCModelDepartmentInfo) * depart))block;

// 刷新缓存的组织结构列表
- (void)resetCachedDepartmentWhenReloadRoster:
(void (^)(CCCallState state, NSMutableArray * rootDeptList))block;

/////////////////////////////////////////////////////////////////

// 所有客户信息查询接口
// 获取所有级别的客户组织结构部门数据列表
- (void)getCurrentUserAllCustomerInfoList:
(void (^)(CCCallState state, NSMutableArray * retList))block;

// 从数据库查询根据cid查询客户的所有根节点列表
- (void)getCurrentUserRootDepartmentInfoList:(NSString *)customerId
                                      result:
(void (^)(CCCallState state, NSMutableArray * retList))block;

// 数据库接口区
// 根据uid与cid查询一个用户信息
- (void)getUserInfoFromLocal:(NSString *)uidStr cid:(NSString *)cidStr
                      result:
(void (^)(CCCallState state, CCNameSpace(CCResultUser) * result))block;

// 用户信息联网查询
// 根据uid与cid查询一个用户信息
- (void)getUserInfoFromServer:(NSString *)uidStr cid:(NSString *)cidStr
                       result:
(void (^)(CCCallState state, CCNameSpace(CCResultUser) * result))block;

// 根据uid与cid查询一个用户图像
- (void)getUserAvatarFromLocal:(NSString *)uidStr cid:(NSString *)cidStr
                        result:
(void (^)(CCCallState state, CCNameSpace(CCAvatarDownFileResult) *uar))block;

// 用户信息联网查询
// 根据uid与cid查询一个用户图像
- (void)getUserAvatarFromServer:(NSString *)uidStr cid:(NSString *)cidStr
                         result:
(void (^)(CCCallState state, CCNameSpace(CCAvatarDownFileResult) *uar))block;

// 根据uid与cid从数据库查询一个用户信息,并返回用户的父级路径列表
- (void)getUserDepartsFromLocal:(NSString *)uidStr cid:(NSString *)cidStr
                         result:
(void (^)(CCCallState state,
          CCNameSpace(CCResultUser) * result, NSMutableArray * parentDeparts))block;

// 查询所有子节点的统计数，count值，最新操作接口，保留值！
// 缓存字典键值为 "cid_uid" 为key, number 为value
// 缓存查询用的节点计数信息，缓存到给定的字典中，如果itemSet为空，查询全部根节点的计数信息
- (void)getDepartmentChildrensNumberCount:(CCNameSpace(CCItemInfo) *)itemSet
                                setToDict:(NSMutableDictionary *)toNumberDicts
                                   result:(void (^)(CCCallState state))block;

// 查询并添加相关子节点的信息至 parentNode，id,与cid不为空
// wantsFillMaxDepth 当大于0时有效，最大限制向下添充多少级，多用户时延迟加载！
- (void)getCurrentUserChildrensToParentNode:(CCNameSpace(CCModelNodeInfo) *)parentNode
                              wantsMaxDepth:(NSInteger)wantsFillMaxDepth
                                 cachedUser:(BOOL)isCachedUser
                                  userBlock:(CCResultNodeBlock)nodeblock
                                  cachedMap:(NSMutableDictionary *)cachedNodeMap
                                 cachedOver:(void (^)(CCCallState state))block;

// 测试用例
// 获得第0级的所有下级部门与部门用户的信息！
- (void)updateAllDepartmentInfoToRootNodeList:(NSMutableArray *)nodesList
                                   cachedUser:(BOOL)isCachedUser
                                    userBlock:(CCResultNodeBlock)userblock
                                    cachedMap:(NSMutableDictionary *)cachedNodeMap
                                   cachedOver:(void (^)(CCCallState state))block;

#pragma mark Query Roster Depart Or User list Utility


// 查询并添加相关子节点的信息至 parentNode，id,与cid不为空
- (void)updateDepartmentInfoFillParentNode:(CCNameSpace(CCModelNodeInfo) *)parentNode
                                cachedUser:(BOOL)isCachedUser
                                 userBlock:(CCResultNodeBlock)nodeblock
                                 cachedMap:(NSMutableDictionary *)cachedNodeMap
                                cachedOver:(void (^)(CCCallState state))block;

// 查询并添加相关子节点的信息至 parentNode，id,与cid不为空
// wantsFillMaxDepth 当大于0时有效，最大限制向下添充多少级，多用户时延迟加载！
- (void)updateDepartmentInfoFillParentNode:(CCNameSpace(CCModelNodeInfo) *)parentNode
                             wantsMaxDepth:(NSInteger)wantsFillMaxDepth
                                cachedUser:(BOOL)isCachedUser
                                 userBlock:(CCResultNodeBlock)nodeblock
                                 cachedMap:(NSMutableDictionary *)cachedNodeMap
                                cachedOver:(void (^)(CCCallState state))block;

// 类型转换帮助类
+ (CCNameSpace(CCModelNodeInfo) *)nodeWithRosterBase:(CCNameSpace(CCRosterBase) *)base;

@end
