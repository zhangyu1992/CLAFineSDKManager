//
//  GSCloudLive+RollCall.h
//  GSCloudSdk
//
//  Created by 张俞 on 2022/4/28.
//

NS_ASSUME_NONNULL_BEGIN

@interface GSCloudLive (RollCall)
/// 开始签到
/// @param title 签到标题
/// @param duration 签到倒计时时间
/// @param success 成功回调
/// @param failure 失败回调
- (void)startRollCallWithTitle:(NSString *)title Duration:(NSInteger)duration OnSuccess:(void(^)(void))success onFailure:(void(^)(YBError *error))failure;

/// 停止签到
/// @param success 成功回调
/// @param failure 失败回调
- (void)stopRollCallOnSuccess:(void(^)(void))success onFailure:(void(^)(YBError *error))failure;

/// 获取签到结果信息
/// @param success 成功回调
/// @param failure 失败回调
- (void)getRollCallResultInfoWithRollCallID:(NSString *)rollcallId OnSuccess:(void(^)(GSRollCallResultInfo * resultInfo))success onFailure:(void(^)(YBError *error))failure;

@end

NS_ASSUME_NONNULL_END
