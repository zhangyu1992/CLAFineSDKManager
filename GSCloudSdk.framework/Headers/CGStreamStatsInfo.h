//
//  CGStreamStatsInfo.h
//  GSCloudSdk
//
//  Created by 张俞 on 2022/4/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// 流轨道类型
typedef enum : NSUInteger {
    /// 音频轨道 + 视频轨道
    GSStreamTrackType_All,
    /// 音频轨道
    GSStreamTrackType_Audio,
    /// 视频轨道
    GSStreamTrackType_Video,
} GSStreamTrackType;

/// 推流分辨率
typedef enum : NSUInteger {
    GSPublishResolution_720P = 1,
    GSPublishResolution_540P = 2,
    GSPublishResolution_360P = 3,
    GSPublishResolution_1080P = 4,
} GSCameraPublishResolution;

/// 订阅分辨率
typedef enum : NSUInteger {
    GSSubscribeResolution_Auto = 0,
    GSSubscribeResolution_1080P = 1,
    GSSubscribeResolution_720P = 2,
    GSSubscribeResolution_360P = 3,
} GSSubscribeResolution;

/// 订阅比例
typedef enum : NSUInteger {
    GSSubscribeVideoRatio16_9 = 0,
    GSCSubscribeVideoRatio9_16 = 1,
} GSSubscribeVideoRatio;

/// 分辨率优先 帧率优先
typedef enum : NSUInteger {
    ///流畅优先
    GSDegradationPreference_MAINTAIN_FRAMERATE = 1,
    /// 质量优先
    GSDegradationPreference_MAINTAIN_RESOLUTION = 2,
    /// 自动
    GSDegradationPreference_BALANCED = 3,
} GSDegradationPreference;

/// 音频状态
typedef enum : NSUInteger {
    ///未知
    GSAudioUnKown,
    /// 正常
    GSAudioNormal,
    /// 静音
    GSAudioMute,
} GSAudioStatus;

/// 视频状态
typedef enum : NSUInteger {
    /// 未知
    GSVideoUnKown,
    /// 正常
    GSVideoNormal,
    /// 关闭视频
    GSVideoMute,
} GSVideoStatus;


@interface CGStreamStatsInfo : NSObject
/// 速率 kbps
@property (nonatomic, copy) NSString * rate;

/// 包数 发送包/接收包
@property (nonatomic, copy) NSString * packets;

/// 丢包数
@property (nonatomic, copy) NSString * lostPackets;

/// 丢包率
@property (nonatomic, copy) NSString * lostRate;

/// 分辨率 - 宽度
@property (nonatomic, copy) NSString * resolutionWidth;

/// 分辨率 - 高度
@property (nonatomic, copy) NSString * resolutionHeight;

/// 帧率
@property (nonatomic, copy) NSString * frameRate;

/// 编解码方式
@property (nonatomic, copy) NSString * codeName;
@end

NS_ASSUME_NONNULL_END
