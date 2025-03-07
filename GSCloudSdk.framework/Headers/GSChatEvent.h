//
//  GSChatEvent.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, GSOPERATIONMSG)
{
    GSOPERATION_Delete,     //删除单条
    GSOPERATION_All_Delete, //删除某人全部
    GSOPERATION_Silence,     //禁言
    GSOPERATION_Audit,       //审核
    GSOPERATION_ROOM_Silence,//房间禁言
    GSOPERATION_Audit_Msg,   //部分消息审核
    GSOPERATION_Audit_AllMsg,//审核全部通过
    GSOPERATION_IsTop,       //置顶或者取消置顶
    GSOPERATION_Highlight,   //高亮
    GSOPERATION_CancelSilence,//取消禁言
};

/**
 *聊天相关回调
 */
@protocol GSChatEvent <NSObject>
/**
 *全局禁言/解除禁言
 *enable:YES 允许 NO 禁言
 */
-(void)onLiveChatEnable:(BOOL)enable;

/**
 *个人禁言/解除禁言
 *userId:用户id
 *nable:YES 允许 NO 禁言
 */
-(void)onUserChatEnable: (BOOL)enable userId:(NSString*)userId;

/**
 *聊天审核开/关
 *isOpen:YES 开  NO：关
 */
-(void)onChatAuditStatus:(BOOL)isOpen;
/**
 *收到聊天消息
 */
-(void)onChatMsg:(GSChatMessage *)message;

/**
 *消息置顶/取消置顶
 */
-(void)onMsgTop:(NSString*)msgId isTop:(BOOL)isTop;

/**
 *高亮消息
 */
-(void)onHighlight:(NSString*)msgId isHighLight:(BOOL)isHighLight;

/**
 *消息删除 删除单条消息
 */
-(void)onMsgDelete:(NSString*)msgId;

/**
 *消息删除 删除全部消息
 */
-(void)onMsgDeleteAll:(NSString *)userid;

/**
 *收到需审核的聊天消息
 */
-(void)onAuditChatMsg:(GSChatMessage *)message;

@end

NS_ASSUME_NONNULL_END
