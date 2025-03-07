//
//  RTCSubscribeConfig.h
//  FineSdk
//
//  Created by 张俞 on 2022/4/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// 订阅配置
@interface RTCSubscribeConfig : NSObject

/// 订阅流类型
@property (nonatomic, assign) RTCSubscribeStreamType streamType;

/// 订阅流中轨道类型
@property (nonatomic, assign) RTCStreamTrackType trackType;

/// 订阅比例
@property (nonatomic, assign) RTCSubscribeVideoRatio subscribeVideoRatio;


/// 订阅分辨率
@property (nonatomic, assign) RTCSubscribeResolution subscribeResolution;

/// 参会人id 在订阅单路时必传
@property (nonatomic, copy) NSString * participantId;

@end

NS_ASSUME_NONNULL_END
