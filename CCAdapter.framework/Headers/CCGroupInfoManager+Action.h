//
//  CCGroupInfoManager+Action.h
//  CCAdapterUI
//
//  Created by yiyimama on 2017/6/9.
//  Copyright © 2017年 yiyimama. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCGroupInfoManager.h"

@interface CCGroupInfoManager (Action)
//@interface CCGroupInfoManager_Action : NSObject

// 客户端接收创建群命令字
- (void)doReceiveGroupCreate:(CCNameSpace(CCMessageResult) *)result;

// 客户端接收邀请入群命令字
- (void)doReceiveGroupInvite:(CCNameSpace(CCMessageResult) *)result;

// 客户端接收处理入群邀请命令字
- (void)doReceiveGroupInviteDeal:(CCNameSpace(CCMessageResult) *)result;

// 客户端接收申请加群命令字(join)
- (void)doReceiveGroupApply:(CCNameSpace(CCMessageResult) *)result;

// 客户端接收处理申请加群命令字(join)
- (void)doReceiveGroupApplyDeal:(CCNameSpace(CCMessageResult) *)result;

// 客户端接收踢出用户命令字
- (void)doReceiveGroupKickOut:(CCNameSpace(CCMessageResult) *)result;

// 客户端接收退群协议命令字
- (void)doReceiveGroupQuit:(CCNameSpace(CCMessageResult) *)result;

// 客户端接收群设置命令字(attribute)
- (void)doReceiveGroupModify:(CCNameSpace(CCMessageResult) *)result;

// 客户端接收群设置管理员命令字(admin)
- (void)doReceiveGroupAdmin:(CCNameSpace(CCMessageResult) *)result;

// 客户端接收群收回管理员命令字(recover)
- (void)doReceiveGroupAdminRecover:(CCNameSpace(CCMessageResult) *)result;

// 客户端接收群设置所有者命令字(owner)
- (void)doReceiveGroupOwner:(CCNameSpace(CCMessageResult) *)result;

// 客户端接收用户群名片命令字(nick)
- (void)doReceiveGroupVcard:(CCNameSpace(CCMessageResult) *)result;

// 客户端接收群收取开关命令字
- (void)doReceiveGroupReceive:(CCNameSpace(CCMessageResult) *)result;

// 客户端接收解散群协议命令字(drop)
- (void)doReceiveGroupDisbanded:(CCNameSpace(CCMessageResult) *)result;

// 客户端接收到群权限修改
- (void)doReceiveGroupAuthChanged:(CCNameSpace(CCMessageResult) *)result;
// 客户端接收到群用户权限修改
- (void)doReceiveGroupUserAuthChanged:(CCNameSpace(CCMessageResult) *)result;
//接收到 权限修改申请
- (void)doReceiveGroupUserApplyAuthChanged:(CCNameSpace(CCMessageResult) *)result;
//客户端接收群主错误消息
- (void)doReceiveGroupOwnerErrorInfo:(CCNameSpace(CCMessageResult) *)result;
@end
