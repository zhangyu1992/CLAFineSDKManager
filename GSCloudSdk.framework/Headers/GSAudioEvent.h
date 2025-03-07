//
//  GSAudioEvent.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, YBAVSTATUS)
{
    YBAVSTATUS_APPLY_FAILURE,//申请失败
    YBAVSTATUS_UNAPPLY_FAILURE,//取消申请失败
    YBAVSTATUS_JOIN_MEETING_FAILURE,//加入metting失败
    YBAVSTATUS_LEAVE_MEETING_FAILURE,//离开metting失败
    YBAVSTATUS_PUBLISH_STREAM_FAILURE,//发布流失败
    YBAVSTATUS_MUTE_MIC_FAILURE,//操作MIC失败
    YBAVSTATUS_SUBSCRIBE_MIXSTREAM_FAILURE,//订阅混合流失败
};
@protocol GSAudioEvent <NSObject>
/**
 *开麦过程的失败状态
 */
-(void)onAudioTalkFailure:(YBAVSTATUS)status;

/**
 *申请连麦中...
 */
-(void)onApplyingAudioTalk;
/**
 *连麦成功，打开了MIC
 */
-(void)onOpenAudioTalk;

/**
 *关麦成功，关闭了MIC
 */
-(void)onCloseAudioTalk;

/**
 *主播拒绝邀请
 */
-(void)onRejectAudioTalk;

/**
 *主播是否开放连麦
 */
-(void)onAudioTalkEnable:(BOOL)enable;

/**
 *收到用户连麦操作
 */
-(void)onUserAudioTalkAction;

@end

NS_ASSUME_NONNULL_END
