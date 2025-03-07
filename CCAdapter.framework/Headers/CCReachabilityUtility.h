//
//  CCReachabilityUtility.h
//  test_adpater
//
//  Created by jinxiangkun on 17/4/6.
//  Copyright © 2017年 zsx. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"

//CCReachabilityUtility * reachability = nil;
//reachability = [CCReachabilityUtility sharedInstance];

@interface CCReachabilityUtility : NSObject

+ (instancetype)sharedInstance;

#pragma mark 网络连接状态

// 目标地址可连接
@property (nonatomic, assign) BOOL isReachable;
// 本机WWAN已连接
@property (nonatomic, assign) BOOL isReachableViaWWAN;
// 本机WiFi已连接
@property (nonatomic, assign) BOOL isReachableViaWiFi;

// 是否连接网络
- (BOOL)isServerReach;

// 删除网络测试
- (void)uninstallReachability;

// 检测网络是否连接
- (BOOL)checkIsInternetConnectionReachability;

// 重新测试网络地址，使用域名
- (void)reachabilityWithHost:(NSString *)strHost;

// 重新测试网络地址，实际登陆的随机IP地址
- (void)reachabilityWithHostIP:(NSString *)hostStr
                          port:(NSString *)portStr;

@end
