//
//  CCGroupInfoManagerProtocol.h
//  CCAdapter
//
//  Created by 张小鱼 on 2019/10/29.
//  Copyright © 2019 jinxiangkun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCMessageInfoManager.h"

typedef enum : NSUInteger {
    CCGroupUserAuthTypeUnknow,
    CCGroupUserAuthTypeAudio,
    CCGroupUserAuthTypeVideo,
    CCGroupUserAuthTypeShare,
    CCGroupUserAuthTypeSort,
    CCGroupUserAuthTypeSpeak,
    CCGroupUserAuthTypeStatus,
    CCGroupUserAuthTypeNote,
    CCGroupUserAuthTypeAvctl,

} CCGroupUserAuthType;

typedef enum : NSUInteger {
    CCGroupAuthTypeUnknow,
    CCGroupAuthTypeAudio,
    CCGroupAuthTypeVideo,
    CCGroupAuthTypeShare,
    CCGroupAuthTypeSort,
    CCGroupAuthTypeSpeak,
    CCGroupAuthTypeStatus,
    CCGroupAuthTypeNote,
    CCGroupAuthTypeAuth,
    CCGroupAuthTypeCName,
} CCGroupAuthType;

NS_ASSUME_NONNULL_BEGIN
@protocol CCGroupInfoManagerDelegate <NSObject>

/**
 接收到 创建群消息

 @param groupMessage 群信息
 */
- (void)groupInfoDidReceiveCreateNewGroupMessage:(CCReceiveGroupAction *)groupMessage;

/**
 接收到 邀请入群反馈消息 同意、拒绝
 
 @param groupMessage 群信息
 */
- (void)groupInfoDidReceiveHandleInviteGroupMessage:(CCReceiveGroupAction *)groupMessage;
/**
 接收到 邀请入群的消息
 
 @param groupMessage 群信息
 */
- (void)groupInfoDidReceiveInviteToGroupMessage:(CCReceiveGroupAction *)groupMessage FromResult:(CCMessageResult *)fromResult;
/**
 接收到入群申请
 @param groupMessage 申请信息
 */
- (void)groupInfoDidReceiveApplyJoinGroupMessageFrom:(CCReceiveGroupAction *)groupMessage;

/**
 接收到 入群申请 反馈消息 同意、拒绝
 
 @param groupMessage 群信息
 */
- (void)groupInfoDidReceiveHandleApplyGroupMessage:(CCReceiveGroupAction *)groupMessage;

/**
 接收到群权限 被修改 消息

 @param groupMessage 修改信息
 */
- (void)groupInfoDidReceiveGroupAuth:(CCGroupAuthType)groupAuth ChangedMessageFrom:(CCReceiveGroupAction *)groupMessage;

/**
 接收到群成员权限 被修改 消息
 
 @param groupMessage 修改信息
 */
- (void)groupInfoDidReceiveGroupUserAuth:(CCGroupUserAuthType)userAuthType ChangedMessageFrom:(CCReceiveGroupAction *)groupMessage;
/**
 接收到群成员权限 申请权限
 
 @param groupMessage 修改信息
 */
- (void)groupInfoDidReceiveGroupUserAuthApply:(CCGroupUserAuthType)userAuthType ChangedMessageFrom:(CCReceiveUserAuthApply *)groupMessage;
/**
 接收到转移群主的消息

 @param groupMessage 新群主消息
 */
- (void)groupInfoDidReceiveChangedGroupOwnerMessageTo:(CCReceiveGroupAction *)groupMessage;

/**
 接收到群成员名字改变消息

 @param groupMessage 群消息
 */
- (void)groupInfoDidReceiveChangedGroupVcardMessageTo:(CCReceiveGroupAction *)groupMessage;

/**
 接收到被踢出群的消息
 
 @param groupMessage 消息
 */
- (void)groupInfoDidReceiveKickOutFromConferenceMessage:(CCReceiveGroupAction *)groupMessage;

/**接收到有人退出群消息*/
- (void)groupInfoDidReceiveUserQuitFromConferenceMessage:(CCReceiveGroupAction *)groupMessage;

/**
 接收到群主错误信息
 */
- (void)groupInfoDidReceiveGroupOwnerErrorInfo:(CCReceiveErrorInfo*)errorInfo;

@end
@interface CCGroupInfoManagerProtocol : NSObject

@end

NS_ASSUME_NONNULL_END
