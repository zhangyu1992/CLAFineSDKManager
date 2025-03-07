//
//  GSUserDevInfo.h
//  GSCloudSdk
//
//  Created by 张俞 on 2022/4/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSUserDevInfo : GSUserInfo
/// 网络运营商
@property(nonatomic, copy) NSString *isp;
/// ip地址
@property(nonatomic, copy) NSString *ipAddr;
/// 设备
@property(nonatomic, copy) NSString *dev;
/// 浏览器
@property(nonatomic, copy) NSString *browserName;
@end

NS_ASSUME_NONNULL_END
