//
//  RTMAcount.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/6/18.
//

#import <Foundation/Foundation.h>
#import <FineSdk/RTMErrHeaders.h>
#import <FineSdk/RTMModelHeaders.h>

typedef void(^SameAcountDeviceLoadChange)(RTDevInfoModel* _Nullable deviceModel);

NS_ASSUME_NONNULL_BEGIN

@interface RTMAcount : NSObject

- (NSString *)getCurrentLoginUserId;
- (NSString *)getCurrentLoginUserCId;

///登录同一账号设备变更时的回调
@property (nonatomic, copy) SameAcountDeviceLoadChange deviceLoadChangeBlock;

/// 注册用户（账号自动生成）
/// @param userName 注册的用户名称
/// @param password 注册的用户密码
/// @param success 成功回调
/// @param failed 失败回调
- (void)registerUserWithUserName:(NSString*)userName
                        password:(NSString*)password
                         success:(void (^)(RTSDKUserInfo *registerUser))success
                          failed:(void(^)(RTMError *error))failed;

/// 注册用户（需传入账号）
/// @param userName 注册的用户名称
/// @param account 注册的用户账号
/// @param password 注册的用户密码
/// @param success 成功回调
/// @param failed 失败回调
- (void)registerUserWithUserName:(NSString*)userName
                         account:(nullable NSString*)account
                        password:(NSString*)password
                         success:(void (^)(RTSDKUserInfo *registerUser))success
                          failed:(void(^)(RTMError *error))failed;


/// 查询最近一次注册账号的信息
/// @param success 成功回调
/// @param failed 失败回掉
- (void)queryLastRegisterSuccess:(void (^)(RTSDKUserInfo *user))success
                          failed:(void(^)(RTMError *error))failed;


/// 获取同一账号下登录的设备列表
/// @param success 成功回调
/// @param failed 失败回掉
- (void)queryDeviceListSuccess:(void (^)(NSMutableArray<RTDevInfoModel*> *devlist))success
                        failed:(void(^)(RTMError *error))failed;



/// 退出同一账号下的其他设备
/// @param devID 要退出设备的id
/// @param success 成功回调
/// @param failed 失败回掉
- (void)kickOutDeviceWithDeviceID:(NSString*)devID
                          success:(void (^)(void))success
                           failed:(void(^)(RTMError *error))failed;


@end

NS_ASSUME_NONNULL_END
