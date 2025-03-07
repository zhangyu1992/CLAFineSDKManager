//
//  GSUserInfo.h
//  GSCloudSdk
//
//  Created by gensee on 2022/3/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSUserInfo : NSObject
///用户id
@property(nonatomic, copy) NSString *userId;
///用户角色
@property(nonatomic, assign) YBUserRole role;
/// 设备类型
@property(nonatomic, assign) YBUserDevice device;
///用户昵称
@property(nonatomic, copy) NSString *nickName;
///用户头像
@property(nonatomic, copy) NSString *headImgUrl;
///登录方式
@property(nonatomic, copy) NSString *roomDev;
///设备
@property(nonatomic, copy) NSString *deviceType;
///权限集
@property(nonatomic, strong) NSArray *authList;
///头像
@property(nonatomic, copy) NSString *placehold_img;

@end

NS_ASSUME_NONNULL_END
