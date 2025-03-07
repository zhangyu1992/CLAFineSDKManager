//
//  CCGroupInfoManager+ActionTo.h
//  CCAdapterUI
//
//  Created by jinxiangkun on 2017/6/11.
//  Copyright © 2017年 yiyimama. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCGroupInfoManager.h"

@interface CCGroupInfoManager (ActionTo)
//@interface CCGroupInfoManager_ActionTo : NSObject

// 测试对像是否存在列表中
-(NSInteger)isContainInArray:(id)info
                compareArray:(NSArray *)_array;

// 客户端发送创建群命令字
- (id)doSendGroupCreate:(CCNameSpace(CCGroupCreate)*)anObject
               userList:(NSMutableArray *)userList;

// 客户端发送邀请用户入群命令字
- (id)doSendGroupInvite:(CCNameSpace(CCModelFixedGroupInfo)*)groupInfo
               userList:(NSMutableArray *)userList WithInfoDict:(NSMutableDictionary *)infoDict;
// 客户端发送取消邀请用户入群
- (id)doSendGroupCancelInvite:(CCNameSpace(CCModelFixedGroupInfo)*)groupInfo
                     userList:(NSMutableArray *)userList WithInfoDict:(NSMutableDictionary *)infoDict;
// 客户端发送处理用户入群命令字
- (id)doSendGroupInviteDeal:(CCNameSpace(CCMessageResult) *)result
                     bAgree:(BOOL)bAgreeInvite infoDict:(NSMutableDictionary *)infoDict;
- (id)doSendReplyGroupInviteDeal:(CCNameSpace(CCStGroupInviteDeal) *)anObject;
// 客户端发送申请加群命令字(join)
- (id)doSendGroupApply:(CCNameSpace(CCModelFixedGroupInfo)*)group;

// 客户端发送处理申请加群命令字
- (id)doSendGroupApplyDeal:(CCNameSpace(CCMessageResult) *)result
                    bAgree:(BOOL)bAgreeInvite;
// 客户端发送处理申请加群命令字
- (id)doSendGroupApplyHandler:(CCNameSpace(CCModelFixedGroupInfo)*)groupInfo
                     userList:(CCModelUserInfo *)userInfo bAgree:(BOOL)bAgreeApply;
// 客户端发送踢出用户命令字
- (id)doSendGroupKickOut:(CCNameSpace(CCModelFixedGroupInfo)*)group
                userList:(NSMutableArray *)userList;

// 客户端发送退群协议命令字
- (id)doSendGroupQuit:(CCNameSpace(CCModelFixedGroupInfo)*)group;

// 客户端发送设置管理员, 更改某些人管理员
- (id)doSendGroupAdmin:(CCNameSpace(CCModelFixedGroupInfo)*)group
              userList:(NSMutableArray *)userList;

// 客户端发送撤回管理员, 取消某些人管理员
- (id)doSendGroupRecoverAdmin:(CCNameSpace(CCModelFixedGroupInfo)*)group
                     userList:(NSMutableArray *)userList;

// 客户端发送移交群主权限, 更改某人为群主
- (id)doSendGroupOwner:(CCNameSpace(CCModelFixedGroupInfo)*)group
              userInfo:(CCNameSpace(CCModelUserInfo) *)userInfo;

// 客户端发送设置群信息, 更改群信息
- (id)doSendGroupVcard:(CCNameSpace(CCModelFixedGroupInfo)*)group
              anObject:(CCNameSpace(CCGroupUser) *)anObject;

// 客户端发送设置群属性, 更改群属性
- (id)doSendGroupAttribute:(CCNameSpace(CCModelFixedGroupInfo)*)group
                  anObject:(CCNameSpace(CCStGroupAttribute) *)anObject;

// 客户端发送设置群接收设置, 设置群接收
- (id)doSendGroupReceive:(CCNameSpace(CCModelFixedGroupInfo)*)group
              receiveSet:(CCGroupShowStatus)iReceiveSet;

// 客户端发送解散群协议命令字(drop)
- (id)doSendGroupDisbanded:(CCNameSpace(CCModelFixedGroupInfo)*)group;
// 客户端发送 设置群 命令
- (id)doSendGroupAuthMessageSet:(CCNameSpace(CCModelAuthGroupInfo)*)groupInfo;
// 客户端发送 设置群成员 命令
- (id)doSendGroupUserAuthMessageSet:(CCNameSpace(CCModelAuthGroupInfo)*)groupInfo;
// 客户端发送 设置群成员申请权限 命令
-(id)doSendGroupUserApplyAuthMessage:(CCNameSpace(CCModelAuthGroupInfo)*)groupInfo;

//会议创建者收回主持人权限
- (id)takeBackGroupOwnerWithGroupInfo:(CCModelFixedGroupInfo *)groupInfo;
@end
