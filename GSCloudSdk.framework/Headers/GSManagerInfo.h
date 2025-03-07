//
//  GSManagerInfo.h
//  GSCloudSdk
//
//  Created by 张俞 on 2022/4/27.
//
#import <Foundation/Foundation.h>
#import <GSCloudSdk/CGStreamStatsInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSManagerInfo : GSUserInfo
/// 音频状态
@property (nonatomic, assign) GSAudioStatus audioStatus;

/// 视频状态
@property (nonatomic, assign) GSVideoStatus videoStatus;

/// 音频权限
@property (nonatomic, assign) BOOL audioAuth;
/// 视频权限
@property (nonatomic, assign) BOOL videoAuth;

/// 主控权限
@property (nonatomic, assign) BOOL avctlAuth;

/// 演示权限
@property (nonatomic, assign) BOOL shareAuth;
/// 是否是自己
@property (nonatomic, assign) BOOL isMySelf;

/// 自己是不是指定嘉宾
@property (nonatomic, assign) BOOL isSelfSpecialGuest;
@end

NS_ASSUME_NONNULL_END
