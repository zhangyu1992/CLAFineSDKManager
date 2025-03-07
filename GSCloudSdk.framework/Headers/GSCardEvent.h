//
//  GSCardEvent.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 *答题卡相关回调
 */
@protocol GSCardEvent <NSObject>
/**
 *答题发布
 */
-(void)onCardPublish:(GSCard *)card;//GSCard

/**
 *答题结束
 */
-(void)onCardEnd;//GSCard

/**
 *答题结果
 */
-(void)onCardResult:(GSCard *)card;//GSCard

/**
 *直播室有人提交了问答
 */
- (void)onRoomAnswerSheetSubmit:(GSAnswerSheetSubmit *)submit;

@end

NS_ASSUME_NONNULL_END
