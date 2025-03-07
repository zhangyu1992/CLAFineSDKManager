//
//  GSLiveAudienceEvent.h
//  GSCloudSdk
//
//  Created by 张俞 on 2022/4/26.
//

#import <Foundation/Foundation.h>
@class GSAudienceInfo;

NS_ASSUME_NONNULL_BEGIN

@protocol GSLiveAudienceEvent <NSObject>
/**
 *观众用户加入
 */
-(void)onAudienceUserJoin:(GSAudienceInfo*)userInfo;

/**
 *观众用户头像更新
 */
-(void)onAudienceUserUpdate:(GSAudienceInfo*)userInfo;

/**
 *观众用户名更新
 */
-(void)onAudienceUserNameUpdate:(GSAudienceInfo*)userInfo;

/**
 *观众用户退出
 */
-(void)onAudienceUserLeve:(GSAudienceInfo*)userInfo;

/// 在线用户人数改变（用来刷新观众人数）
- (void)onLiveAssistantUserOnlineDidChangedToCount:(NSInteger)count;

/**
 *观众用户禁言列表改变
 */
-(void)onAudienceUserSilenceListDidChangedTo:(NSArray *)silenceList;

@end

NS_ASSUME_NONNULL_END
