//
//  GSWXParam.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/11.
//

#import <Foundation/Foundation.h>
#import <GSCloudSdk/GSJoinParam.h>

NS_ASSUME_NONNULL_BEGIN
@interface WxUserInfo : NSObject
@property(nonatomic, copy)NSString *workWxAvatar;//头像url
@property(nonatomic, copy)NSString *workWxDeviceId;//手机设备号(由企业微信在安装时随机生成，删除重装会改变，升级不受影响)
@property(nonatomic, copy)NSString *workWxUserId;//成员UserID
@property(nonatomic, copy)NSString *workWxUserName;//成员名字
@end;
@interface GSWXParam : GSJoinParam
@property(nonatomic, strong)WxUserInfo *workWxUserInfo;
@property(nonatomic, copy)NSString *wxId;//微信Id
@end

NS_ASSUME_NONNULL_END
