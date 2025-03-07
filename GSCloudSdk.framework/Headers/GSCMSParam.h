//
//  GSCMSParam.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/11.
//

#import <Foundation/Foundation.h>
#import <GSCloudSdk/GSJoinParam.h>
NS_ASSUME_NONNULL_BEGIN

@interface GSCMSParam : GSJoinParam
@property(nonatomic, copy)NSString *smsCode;//短信验证码
@property(nonatomic, copy)NSString *phoneNumber;//手机号
@property(nonatomic, copy)NSString *email;//邮箱地址
@end

NS_ASSUME_NONNULL_END
