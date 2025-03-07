//
//  GSLiveManagerEvent.h
//  GSCloudSdk
//
//  Created by 张俞 on 2022/4/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// 管理员信息变化事件回调
@protocol GSLiveManagerEvent <NSObject>
/**
 *管理员加入
 */
- (void)onManagerJoin:(GSManagerInfo*)userInfo;

/**
 *管理员信息更新
 */
- (void)onManagerUpdateUserInfo:(GSUserInfo*)userInfo;

/**
 *管理员退出
 */
- (void)onManagerLeave:(GSManagerInfo*)userInfo;

/**
 *管理员的主控权变更
 */
- (void)onMainControlUserId:(NSString *)userId;

/**
 *管理员的演示权变更
 */
- (void)onShowingUserId:(NSString *)userId;

/**
 *嘉宾是否可以看观众列表
 */
- (void)onGuestSeeAudienceAuth:(BOOL)canSee;



/**
 *管理员的视频状态改变
 */
- (void)onManager:(NSString *)userId didChangedVideoStatus:(GSVideoStatus)videoStatus;

/**
 *管理员的音频状态改变
 */
- (void)onManager:(NSString *)userId didChangedAudioStatus:(GSAudioStatus)audioStatus;



@end

NS_ASSUME_NONNULL_END
