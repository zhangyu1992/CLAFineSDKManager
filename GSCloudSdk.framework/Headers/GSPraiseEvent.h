//
//  GSPraiseEvent.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 *点赞相关回调
 */
@protocol GSPraiseEvent <NSObject>
//收到直播中点赞信息
-(void)onPraise:(NSInteger)praiseCount;

@end

NS_ASSUME_NONNULL_END
