//
//  RTCRoomLayoutInfo.h
//  FineSdk
//
//  Created by 张俞 on 2021/7/2.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// 比例
@interface RTCFractionModel : NSObject

/// 分子
@property (nonatomic, assign) float numerator;
/// 分母
@property (nonatomic, assign) float denominator;
/// 比例值
@property (nonatomic, assign) float value;

@end
/// 区域范围
@interface RTCRegionArea : NSObject
@property (nonatomic, strong) RTCFractionModel * top;
@property (nonatomic, strong) RTCFractionModel * left;
@property (nonatomic, strong) RTCFractionModel * width;
@property (nonatomic, strong) RTCFractionModel * height;

@end
/// 区域信息
@interface RTCRegionInfo : NSObject

/// 区域id
@property (nonatomic, copy) NSString * regionId;
/// 参会人id
@property (nonatomic, copy) NSString * participantId;
/// 参会人姓名
@property (nonatomic, copy) NSString * participantName;
/// 是否被指定
@property (nonatomic, assign) BOOL isAppoint;
/// 是否离开
@property (nonatomic, assign) BOOL isLeave;

/// 视频状态
@property (nonatomic, assign) RTCVideoStatus videoStatus;
/// 音频状态
@property (nonatomic, assign) RTCAudioStatus audioStatus;

/// 音量
@property (nonatomic, assign) NSInteger volume;

/// 位置信息
@property (nonatomic, strong) RTCRegionArea * regionArea;

- (instancetype)initWithRegionId:(NSString *)regionId AreaDict:(NSDictionary *)areaDict InfoDict:(NSDictionary *)infoDict;

/// 根据参会人id更新布局信息
/// @param participantId 参会人id
/// @param isAppoint 是否指定
- (void)updataRegionInfoWithParticipantId:(NSString *)participantId Appoint:(BOOL)isAppoint;

/// 重置信息除了位置
- (void)resetRegionInfoWithOutArea;
@end

@interface RTCRoomLayoutInfo : NSObject
/// 布局类型
@property (nonatomic, assign) RTCLayoutType layoutType;

/// 布局信息数据 key:regionId value:RTCRegionInfo对象
@property (nonatomic, copy) NSDictionary * layoutInfoDict;

@end
NS_ASSUME_NONNULL_END
