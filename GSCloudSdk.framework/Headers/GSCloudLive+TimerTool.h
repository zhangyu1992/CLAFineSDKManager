//
//  GSCloudLive+TimerTool.h
//  GSCloudSdk
//
//  Created by 张俞 on 2023/7/20.
//

#import <GSCloudSdk/GSCloudSdk.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSCloudLive (TimerTool)
/// 开始计时
- (void)startTimerWithDuration:(NSInteger)duration TimeType:(GSTimerType)timeType OnSuccess:(void(^)(void))success onFailure:(void(^)(YBError *error))failure;

///结束计时
- (void)stopTimerOnSuccess:(void(^)(void))success onFailure:(void(^)(YBError *error))failure;

/// 重置计时
- (void)refreshTimerOnSuccess:(void(^)(void))success onFailure:(void(^)(YBError *error))failure;

/// 获取计时信息
- (void)getTimerInfoOnSuccess:(void(^)(GSTimerToolInfo * timerToolInfo))success onFailure:(void(^)(YBError *error))failure;
@end

NS_ASSUME_NONNULL_END
