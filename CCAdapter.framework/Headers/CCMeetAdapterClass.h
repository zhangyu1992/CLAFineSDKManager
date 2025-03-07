//
//  CCMeetAdapterClass.h
//  CCAdapterUI
//
//  Created by 张张 on 2018/12/10.
//  Copyright © 2018年 yiyimama. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCMessageManager.h"
#import "CCUserInfoManager.h"
#import "CCModelBase.h"

NS_ASSUME_NONNULL_BEGIN
typedef enum : NSUInteger {
    VideoMeetMessageTypeInvited = 0,
    VideoMeetMessageTypeOffLine = 1,
    VideoMeetMessageTypeBusy = 2,
    VideoMeetMessageTypeAccept = 3,
    VideoMeetMessageTypeDeny = 4,
    VideoMeetMessageTypeNoAnswer = 5,
    VideoMeetMessageTypeCancel = 6,
    VideoMeetMessageTypeApply_Audio = 7,// 申请打开声音权限
    VideoMeetMessageTypeApply_Share = 8,// 申请打开分享权限

    VideoMeetMessageTypeUnknow = 100,
} VideoMeetMessageType;
@interface CCMeetAdapterClass : NSObject
+ (instancetype)shareInstance;

/**
 呼叫用户

 @param roomName 房间名称
 @param roomid 房间ID
 @param passCode 密码
 @param userInfo 用户信息
 */
- (void)sendVideMeetWithRoomName:(NSString *)roomName RoomID:(NSString *)roomid PassCode:(NSString *)passCode ToCallUser:(CCModelUserInfo *)userInfo;

/**
 消息回复

 @param videoMeetReply 回复类型
 @param userInfo 参数
 */
- (void)replyVideMeetModel:(VideoMeetMessageType)videoMeetReply fromRoomID:(NSString *)roomid ToCallUser:(CCModelUserInfo *)userInfo;

@end

NS_ASSUME_NONNULL_END
