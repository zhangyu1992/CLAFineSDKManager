//
//  GSAudienceInfo.h
//  GSCloudSdk
//
//  Created by 张俞 on 2022/4/27.
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSAudienceInfo : GSUserInfo
/// 是否被禁言
@property (nonatomic, assign) BOOL isSilence;

/// 浏览器
@property (nonatomic, copy) NSString * browserName;

/// IP地址
@property (nonatomic, copy) NSString * ip;

/// 运营商
@property (nonatomic, copy) NSString * isp;

/// 房间uid
@property (nonatomic, copy) NSString * roomUid;

/// 排序id
@property (nonatomic, copy) NSString * sortId;

/// 系统类型
@property (nonatomic, copy) NSString * systemType;

@end

NS_ASSUME_NONNULL_END
