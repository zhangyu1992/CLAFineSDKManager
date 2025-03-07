//
//  GSRewardEvent.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 *打赏相关回调
 */
@protocol GSRewardEvent <NSObject>
/**
 *收到打赏信息
 */
-(void)onReward:(GSRewardInfo *)rewardInfo;
/**
 *打赏列表变化
 */
-(void)onRewardChange;

@end

NS_ASSUME_NONNULL_END
