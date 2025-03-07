//
//  GSTimerToolInfo.h
//  GSCloudSdk
//
//  Created by 张俞 on 2023/7/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    GSTimerType_Countdown = 0,// 倒计时
    GSTimerType_Positive = 1,// 正计时
} GSTimerType;

typedef enum : NSUInteger {
    GSTimerState_NoTimer = 0,
    GSTimerState_StartTimer = 1,
    GSTimerState_StopTimer = 2,
    GSTimerState_ReStartTimer = 3,
} GSTimerState;

@interface GSTimerToolInfo : NSObject
@property (nonatomic, copy) NSString * duration;
@property (nonatomic, copy) NSString * endTime;
@property (nonatomic, copy) NSString * nowTime;
/// 剩余时间
@property (nonatomic, copy) NSString * remainingTime;
@property (nonatomic, copy) NSString * startTime;
@property (nonatomic, assign) GSTimerType timeType;

@end

NS_ASSUME_NONNULL_END
