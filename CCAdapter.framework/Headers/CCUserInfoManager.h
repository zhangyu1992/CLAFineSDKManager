//
//  CCUserInfoManagerEx.h
//  CCAdapterUI
//
//  Created by yiyimama on 2017/5/31.
//  Copyright © 2017年 yiyimama. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCUserInfoManageProtocol.h"

#import "CCRuntime.h"
#import "CCObjectHeader.h"

#import "CCAdapterKeys.h"
#import "CCAdapterBase.h"
#import "CCAdapterClass.h"
#import "CCNotificationKeys.h"

// 最大缓存的用户信息数量！
#define CCCachedMaxUserInfoCount (1024)

// 常用联系人的 did,cid
#define CCDepartmentInfoTypeIDCommonUser @"CommonUser_0x7fffffff"
// 常用通讯录的 did,cid
#define CCDepartmentInfoTypeIDCommonMobile @"CommonMobile_0x7fffffff"
// 常用群组的 did,cid
#define CCDepartmentInfoTypeIDCommonGroup @"CommonGroup_0x7fffffff"
// 常用临时会话的 did,cid
#define CCDepartmentInfoTypeIDCommonTempGroup @"CommonTempGroup_0x7fffffff"

/*
 *用户数据管理
 */
typedef NS_ENUM(unsigned long long, CCContractsSearchType)
{
    CCContractsSearchType_Department = (1LL << 0),
    CCContractsSearchType_Person = (1LL << 2),
    CCContractsSearchType_FrequentContract = (1LL << 16),
};

typedef void (^CCContractsSearchResultsBlock)(id, id, id);

extern NSString *const CCContractsListInitFinishedNotification;

extern NSString *const CCContractsListCachedFinishedNotification;

@interface CCUserInfoManager : NSObject

//添加联系人、删除联系人、修改联系人信息
+ (id)shareUserInfoManager;

#pragma mark New Share Roster infos
//客户结构信息列表
@property (strong) NSMutableArray * mAllCustomerList;
//组织结构联系人根结构
@property (strong) NSMutableArray * mRootDepartmentList;
//缓存部分用户结构的列表
@property (strong) NSMutableArray * mCachedUsersList;
//缓存部分用户结构的字典
@property (strong) NSMutableDictionary * mCachedUserInfos;
//缓存部分用户头像结构的字典
@property (strong) NSMutableDictionary * mCachedUserAvatarInfos;
//缓存全部组织结构的字典
@property (strong) NSMutableDictionary * mCachedDepartmentInfos;

@property (nonatomic, weak) id <CCUserInfoManageProtocolDelegate> historyDelegate;
// 重置组织列表信息
- (void)resetList;

// 加载组织列表
- (void)loadTestData;

//组织结构更新
-(void)updateDepartmentContact;

//下载组织结构部门
-(void)downLoadDepartmentFromServe;

//更新本地组织列表
- (void)loadLocalDepartment:(CCNameSpace(CCModelAuthInfo) *)info;

// 查询组织架构
- (void)deparmentStructureWithResult:(void (^)(id departmentInfo))block;

//根据部门查询用户
- (void)userinfoWithDepartment:(id)obj
                        result:(void (^)(NSArray *userInfos))block;

//查询某一部门下的用户信息
- (void)userInfosWithDepartmentId:(NSString *)departId
                           result:(void (^)(id departmentInfo))block;

//查询某个用户的信息，二次回调更新信息
- (void)userInfoWithUserId:(NSString *)userId customerId:(NSString *)cidStr
                    result:(void (^)(id resultUser))block;

//查询某个用户的信息，二次回调更新信息
- (void)userInfoWithUserId:(NSString *)userId customerId:(NSString *)cidStr
                    update:(BOOL)updateFromServer
                    result:(void (^)(id resultUser))block;

//获得本地用户的头像信息
- (void)emptyUserAvatarImage:(void (^)(UIImage * resultImage))block;

//获得本地用户的头像对像，如无文件返回空对像
- (UIImage *)localUserAvatarImageWithPath:(NSString *)sFilePath;

//获得本地用户的头像对像，如无文件返回空对像
- (void)localUserAvatarImageWithPath:(NSString *)sFilePath
                              result:(void (^)(UIImage * resultImage))block;

//查询某个用户的头像信息，二次回调更新信息
- (void)userAvatarWithUserId:(NSString *)userId customerId:(NSString *)cidStr
                      update:(BOOL)updateFromServer
                      result:(void (^)(CCCallState state, NSString * sNewPathFile))block;

//查询某个用户，根据CCItemInfo的uid+cid信息
- (void)getUserInfo:(NSString *)logName ItemInfo:(CCItemInfo *)searchItem
             result:(void (^)(id departmentInfo))block;

//根据会话列表获取最近联系人
- (void)getRecentlyContacs:(void (^)(id departmentInfo))block;

//搜索用
- (void)searchContact:(NSString *)searchString result:(void (^)(NSArray *))block;
//搜索用，返回相关对像类型
- (void)searchResultAll:(NSString *)searchString result:(void (^)(NSArray *))block;

@end
