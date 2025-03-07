//
//  GSVoteEvent.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol GSVoteEvent <NSObject>
/**
 *问卷发布
 **/
-(void)onVotePublish:(GSVoteCard *)card;

/**
 *问卷结束
 **/
-(void)onVoteEnd:(NSString *)paperId;

/**
 *直播室有人回复了问卷
 */
- (void)onVoteReplay:(GSPaperReplay *)replay;

@end

NS_ASSUME_NONNULL_END
