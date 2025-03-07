//
//  RTMRoster.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/7/8.
//

#import <Foundation/Foundation.h>
#import <FineSdk/RTMErrHeaders.h>
#import <FineSdk/RTMDepartmentInfoModel.h>
#import <FineSdk/RTMDepartmentUserInfoModel.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTMRoster : NSObject


/// 从服务器更新组织通讯录到本地数据库
/// @param success 更新成功回调
/// @param failed 更新失败回调
- (void)updateRosterFromServerSuccess:(void (^)(void))success
                               failed:(void(^)(RTMError *error))failed;

/// 本地数据库查询一级组织架构信息
/// @param result 查询结果回调
- (void)queryFirstLevelDepartmentStructFromLocalDBResult:(void (^)(NSMutableArray* array))result;



/// 查询一个组织架构下的人员数量
/// @param departmentDID 要查询的组织架构的did
/// @param departmentCID 要查询的组织架构的cid
/// @param success 成功回调
/// @param failed 失败回调
- (void)queryOneDepartmentUserCountFromDBWithDepartmentDID:(NSString*)departmentDID
                                             departmentCID:(NSString*)departmentCID
                                                      path:(NSString*)path
                                                   success:(void (^)(long count))success
                                                    failed:(void(^)(RTMError *error))failed;

/// 获取一个组织架构下的下一级组织结构信息
/// @param currentDID 当前组织结构的id
/// @param currentCID 当前组织结构的cid
/// @param result 结果回调
- (void)queryChildDepartmentsFromParentDID:(NSString*)currentDID
                                 parentCID:(NSString*)currentCID
                                    result:(void (^)(NSMutableArray* array))result;

/// 从本地数据库中查询一个人在组织结构中的信息
/// @param userID 要查询人员的id
/// @param userCID 要查询人员的cid
/// @param success 成功回调
/// @param failed 失败回调
- (void)queryOnePersonInfoFromLocalDBWithUserID:(NSString*)userID
                                        userCID:(NSString*)userCID
                                        success:(void (^)(RTMDepartmentUserInfoModel* userInfo))success
                                         failed:(void(^)(RTMError *error))failed;

//从服务器中查询一个人在组织结构中的信息
- (void)queryOnePersonInfoFromServerWithUserID:(NSString *)userID
                                       userCID:(NSString *)userCID
                                       success:(void (^)(RTMDepartmentUserInfoModel * userInfo))success
                                        failed:(void (^)(RTMError * error))failed;

/// 根据userIDList从本地数据库中查询userIDList内的全部用户信息
/// @param userIDList 要查询的userID数组
/// @param success 成功回调
/// @param failed 失败回调
- (void)queryUserInfosFromDBWithUIDList:(NSMutableArray*)userIDList
                                success:(void (^)(NSMutableArray* array))success
                                 failed:(void(^)(RTMError *error))failed;


/// 查询一个组织结构的信息
/// @param departmentID 当前组织结构的id
/// @param departmentCID 当前组织结构的cid
/// @param success 成功回调
/// @param failed 失败回调
- (void)queryOneDepartmentInfoFromDBWithDepartmentID:(NSString*)departmentID
                                       departmentCID:(NSString*)departmentCID
                                             success:(void (^)(RTMDepartmentInfoModel* departmentInfoModel))success
                                              failed:(void(^)(RTMError *error))failed;



/// 查询一个组织结构的上级组织结构信息（包括本组织结构）
/// @param departmentID 当前组织结构的id
/// @param departmentCID 当前组织结构的cid
/// @param success 成功回调
/// @param failed 失败回调
- (void)queryPreLevelDepartmentWithDepartmentID:(NSString*)departmentID
                                  departmentCID:(NSString*)departmentCID
                                        success:(void (^)(NSMutableArray* array))success
                                         failed:(void(^)(RTMError *error))failed;


/// 查询一系列组织结构信息
/// @param departmentIDArray 组织结构的ID数组
/// @param success  成功回调
/// @param failed 失败回调
- (void)queryDepartmentInfosFromDBWithDepartmentIDList:(NSMutableArray *)departmentIDArray
                                               success:(void (^)(NSMutableArray* array))success
                                                failed:(void(^)(RTMError *error))failed;



/// 搜索用户
/// @param nameOrMobile 要搜索的内容，可以是name或者mobile
/// @param result 搜索结果回调
- (void)searchUserByContent:(NSString*)nameOrMobile
                     result:(void (^)(NSMutableArray* array))result;


@end

NS_ASSUME_NONNULL_END
