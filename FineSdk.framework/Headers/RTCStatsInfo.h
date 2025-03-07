//
//  RTCStatsInfo.h
//  FineSdk
//
//  Created by 张俞 on 2021/6/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// 统计信息类

@interface RTCStatsInfo : NSObject
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

- (instancetype)initStatsInfoWithRate:(NSString *)rate Packets:(NSString *)packets LostPackets:(NSString *)lostPackets LostRate:(NSString *)lostRate CodeName:(NSString *)codeName;

- (instancetype)initStatsInfoWithRate:(NSString *)rate Packets:(NSString *)packets LostPackets:(NSString *)lostPackets LostRate:(NSString *)lostRate ResolutionWidth:(NSString *)resolutionWidth ResolutionHeight:(NSString *)resolutionHeight FrameRate:(NSString *)frameRate CodeName:(NSString *)codeName;

@end

NS_ASSUME_NONNULL_END
