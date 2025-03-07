//
//  CCModelTransform.h
//  adapter
//
//  Created by jinxiangkun on 17/3/26.
//  Copyright © 2017年 zsx. All rights reserved.
//

#ifndef _CC_CCDataModel_Transform_H_
#define _CC_CCDataModel_Transform_H_

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCModelBase.h"
#import "CCModelMethod.h"
#import "CCModelStruct.h"
#import "CCModelGroup.h"
#import "CCModelMessage.h"

//#include "ccsdk.h"
//不能包含C++ Object-C 专用转换类

@interface CCNameSpace(CCModelTransform) : NSObject

// Object-C设备信息转换类
+ (CCNameSpace(CCDeviceInfo) *)devInfoFromDictionary:(NSDictionary *)dict;
// Object-C设备信息转换类
+ (NSDictionary *)dictionaryFromDevInfo:(CCNameSpace(CCDeviceInfo) *)info;

// 传递参数信息转换类
+ (CCNameSpace(CCItemInfo) *)itemInfoFromDictionary:(NSDictionary *)dict;
// 传递参数信息转换类
+ (NSDictionary *)dictionaryFromItemInfo:(CCNameSpace(CCItemInfo) *)info;
+ (NSDictionary *)dictionaryFromGroupMember:(CCNameSpace(CCStGroupMember) *)info;
// 返回状态信息转换类
+ (CCNameSpace(CCStatusInfo) *)statusInfoFromDictionary:(NSDictionary *)dict;
// 返回状态信息转换类
+ (NSDictionary *)dictionaryFromStatusInfo:(CCNameSpace(CCStatusInfo) *)info;

// Object-C用户登录信息类
+ (CCNameSpace(CCModelAuthInfo) *)authInfoFromDictionary:(NSDictionary *)dict;
// Object-C用户登录信息类
+ (NSDictionary *)dictionaryFromAuthInfo:(CCNameSpace(CCModelAuthInfo) *)info;

// 用户信息转换类
+ (CCNameSpace(CCModelUserInfo) *)userInfoFromDictionary:(NSDictionary *)dict;
// Object-C用户信息转换类
+ (NSDictionary *)dictionaryFromUserInfo:(CCNameSpace(CCModelUserInfo) *)info;

// Object-C客户信息转换类
+ (CCNameSpace(CCModelCustomerInfo) *)customerInfoFromDictionary:(NSDictionary *)dict;
// Object-C客户信息转换类
+ (NSDictionary *)dictionaryFromCustomerInfo:(CCNameSpace(CCModelCustomerInfo) *)info;

// Object-C部门表信息转换类
+ (CCNameSpace(CCDepartCount) *)departCountFromDictionary:(NSDictionary *)dict;
// Object-C部门表信息转换类
+ (NSDictionary *)dictionaryFromDepartCount:(CCNameSpace(CCDepartCount) *)info;

// Object-C部门表信息转换类
+ (CCNameSpace(CCDepartItem) *)departItemFromDictionary:(NSDictionary *)dict;
// Object-C部门表信息转换类
+ (NSDictionary *)dictionaryFromDepartItem:(CCNameSpace(CCDepartItem) *)info;

// Object-C部门表信息转换类
+ (CCNameSpace(CCDepartPath) *)departPathFromDictionary:(NSDictionary *)dict;
// Object-C部门表信息转换类
+ (NSDictionary *)dictionaryFromDepartPath:(CCNameSpace(CCDepartPath) *)info;

// Object-C部门表信息转换类
+ (CCNameSpace(CCModelDepartmentInfo) *)departInfoFromDictionary:(NSDictionary *)dict;
// Object-C部门表信息转换类
+ (NSDictionary *)dictionaryFromDepartInfo:(CCNameSpace(CCModelDepartmentInfo) *)info;

// Object-C部门用户信息转换类
+ (CCNameSpace(CCModelDepartmentUserInfo) *)departUserInfoFromDictionary:(NSDictionary *)dict;
// Object-C部门用户信息转换类
+ (NSDictionary *)dictionaryFromDepartUserInfo:(CCNameSpace(CCModelDepartmentUserInfo) *)info;

// 查询用户的返回结构转换
+ (CCNameSpace(CCResultUser) *)resultUserInfoFromDictionary:(NSDictionary *)dict;
// 查询用户的返回结构转换
+ (NSDictionary *)dictionaryFromResultUserInfo:(CCNameSpace(CCResultUser) *)info;

// Object-C群组信息转换类
+ (CCNameSpace(CCModelFixedGroupInfo) *)fixedGroupInfoFromDictionary:(NSDictionary *)dict;
// Object-C群组信息转换类
+ (NSDictionary *)dictionaryFromFixedGroupInfo:(CCNameSpace(CCModelFixedGroupInfo) *)info;

// Object-C群组用户信息转换类
+ (CCNameSpace(CCModelFixedGroupUserInfo) *)fixedGroupUserInfoFromDictionary:(NSDictionary *)dict;
// Object-C群组用户信息转换类
+ (NSDictionary *)dictionaryFromFixedGroupUserInfo:(CCNameSpace(CCModelFixedGroupUserInfo) *)info;

// Object-C群组信息转换类
+ (CCNameSpace(CCModelTempGroupInfo) *)tempGroupInfoFromDictionary:(NSDictionary *)dict;
// Object-C群组信息转换类
+ (NSDictionary *)dictionaryFromTempGroupInfo:(CCNameSpace(CCModelTempGroupInfo) *)info;

// Object-C群组用户信息转换类
+ (CCNameSpace(CCModelTempGroupUserInfo) *)tempGroupUserInfoFromDictionary:(NSDictionary *)dict;
// Object-C群组用户信息转换类
+ (NSDictionary *)dictionaryFromTempGroupUserInfo:(CCNameSpace(CCModelTempGroupUserInfo) *)info;

// Object-C群组类型转换类
+ (CCNameSpace(CCModelGroupInfoList) *)groupInfoListFromDictionary:(NSDictionary *)dict;
// Object-C群组类型转换类
+ (NSDictionary *)dictionaryFromGroupInfoList:(CCNameSpace(CCModelGroupInfoList) *)info;

// Object-C群组类型转换类
+ (CCNameSpace(CCGroupConfirm) *)groupConfirmFromDictionary:(NSDictionary *)dict;
// Object-C群组类型转换类
+ (NSDictionary *)dictionaryFromGroupConfirm:(CCNameSpace(CCGroupConfirm) *)info;

// Object-C群组类型转换类
+ (CCNameSpace(CCGroupInfo) *)groupInfoFromDictionary:(NSDictionary *)dict;
// Object-C群组类型转换类
+ (NSDictionary *)dictionaryFromGroupInfo:(CCNameSpace(CCGroupInfo) *)info;

// Object-C群组类型转换类
+ (CCNameSpace(CCGroupUser) *)groupUserFromDictionary:(NSDictionary *)dict;
// Object-C群组类型转换类
+ (NSDictionary *)dictionaryFromGroupUser:(CCNameSpace(CCGroupUser) *)info;

// Object-C群组类型转换类
+ (CCNameSpace(CCGroupCreate) *)groupCreateFromDictionary:(NSDictionary *)dict;
// Object-C群组类型转换类
+ (NSDictionary *)dictionaryFromGroupCreate:(CCNameSpace(CCGroupCreate) *)info;


// Object-C群组类型转换类
+ (CCNameSpace(CCStGroupObject) *)StGroupObjectFromDictionary:(NSDictionary *)dict;
// Object-C群组类型转换类
+ (NSDictionary *)dictionaryFromStGroupObject:(CCNameSpace(CCStGroupObject) *)info;

// Object-C群组类型转换类
+ (CCNameSpace(CCStGroupInviteDeal) *)StGroupInviteDealFromDictionary:(NSDictionary *)dict;
// Object-C群组类型转换类
+ (NSDictionary *)dictionaryFromStGroupInviteDeal:(CCNameSpace(CCStGroupInviteDeal) *)info;

// Object-C群组类型转换类
+ (CCNameSpace(CCStGroupAttribute) *)StGroupAttributeFromDictionary:(NSDictionary *)dict;
// Object-C群组类型转换类
+ (NSDictionary *)dictionaryFromStGroupAttribute:(CCNameSpace(CCStGroupAttribute) *)info;
// 群用户权限申请信息装换
+ (NSDictionary *)dictionaryFromGroupMemberApply:(CCNameSpace(CCStGroupMemberApply) *)info;


// Object-C群组类型转换类
+ (CCNameSpace(CCModelGroupDetails) *)StGroupDetailsFromDictionary:(NSDictionary *)dict;
// Object-C群组类型转换类
+ (NSDictionary *)dictionaryFromStGroupDetails:(CCNameSpace(CCModelGroupDetails) *)info;

// 会议邀请回复
+ (NSDictionary *)dictionaryFromMsgItemVideoMeetReply:(CCNameSpace(CCMessageItemVideoMeetReply) *)info;

// Object-C接收信息转换类
+ (CCNameSpace(CCGetConfig) *)getConfigFromDictionary:(NSDictionary *)dict;
// Object-C接收信息转换类
+ (NSDictionary *)dictionaryFromGetConfig:(CCNameSpace(CCGetConfig) *)info;

// Object-C会话信息转换类
+ (CCNameSpace(CCSessionInfo) *)sessionInfoFromDictionary:(NSDictionary *)dict;
// Object-C会话信息转换类
+ (NSDictionary *)dictionaryFromSessionInfo:(CCNameSpace(CCSessionInfo) *)info;

// Object-C消息类信息转换类
+ (CCNameSpace(CCMessageHead) *)commandHeadFromDictionary:(NSDictionary *)dict;
// Object-C消息类信息转换类
+ (NSDictionary *)dictionaryFromCommandHead:(CCNameSpace(CCMessageHead) *)info;

// Object-C发送消息转换类
+ (CCNameSpace(CCMessageReply) *)commandReplyFromDictionary:(NSDictionary *)dict;
// Object-C发送消息转换类
+ (NSDictionary *)dictionaryFromCommandReply:(CCNameSpace(CCMessageReply) *)info;

// Object-C消息类信息转换类
+ (CCNameSpace(CCMessageOwnerInfo) *)ownerInfoFromDictionary:(NSDictionary *)dict;
// Object-C消息类信息转换类
+ (NSDictionary *)dictionaryFromOwnerInfo:(CCNameSpace(CCMessageOwnerInfo) *)info;

// Object-C消息类信息转换类
+ (CCNameSpace(CCMessageSenderInfo) *)senderInfoFromDictionary:(NSDictionary *)dict;
// Object-C消息类信息转换类
+ (NSDictionary *)dictionaryFromSenderInfo:(CCNameSpace(CCMessageSenderInfo) *)info;

// Object-C消息类信息转换类
+ (CCNameSpace(CCMessageNodeBase) *)msgNodeBaseFromDictionary:(NSDictionary *)dict;
// Object-C消息类信息转换类
+ (NSDictionary *)dictionaryFromMsgNodeBase:(CCNameSpace(CCMessageNodeBase) *)info;

// Object-C消息类信息转换类
+ (CCNameSpace(CCMessageNodeInfo) *)msgNodeInfoFromDictionary:(NSDictionary *)dict;
// Object-C消息类信息转换类
+ (NSDictionary *)dictionaryFromMsgNodeInfo:(CCNameSpace(CCMessageNodeInfo) *)info;

// Object-C消息类信息转换类
+ (CCNameSpace(CCMessageItemText) *)msgItemTextFromDictionary:(NSDictionary *)dict;
// Object-C消息类信息转换类
+ (NSDictionary *)dictionaryFromMsgItemText:(CCNameSpace(CCMessageItemText) *)info;

// Object-C消息类信息转换类
+ (CCNameSpace(CCMessageItemFace) *)msgItemFaceFromDictionary:(NSDictionary *)dict;
// Object-C消息类信息转换类
+ (NSDictionary *)dictionaryFromMsgItemFace:(CCNameSpace(CCMessageItemFace) *)info;

// Object-C消息类信息转换类
+ (CCNameSpace(CCMessageItemImage) *)msgItemImageFromDictionary:(NSDictionary *)dict;
// Object-C消息类信息转换类
+ (NSDictionary *)dictionaryFromMsgItemImage:(CCNameSpace(CCMessageItemImage) *)info;

// Object-C消息类信息转换类
+ (CCNameSpace(CCMessageItemVoice) *)msgItemVoiceFromDictionary:(NSDictionary *)dict;
// Object-C消息类信息转换类
+ (NSDictionary *)dictionaryFromMsgItemVoice:(CCNameSpace(CCMessageItemVoice) *)info;

// Object-C消息类信息转换类
+ (NSDictionary *)dictionaryFromMsgItemVideoConf:(CCNameSpace(CCMessageItemVideoConf) *)info;
// Object-C消息类信息转换类
+ (CCNameSpace(CCMessageItemVideoConf) *)msgItemVideoConfFromDictionary:(NSDictionary *)dict;

// Object-C消息类信息转换类
+ (NSDictionary *)dictionaryFromMsgItemVideoMeet:(CCNameSpace(CCMessageItemVideoMeet) *)info;
// Object-C消息类信息转换类
+ (CCNameSpace(CCMessageItemVideoMeet) *)msgItemVideoMeetFromDictionary:(NSDictionary *)dict;
// 会议邀请回复转换类
+ (CCNameSpace(CCMessageItemVideoMeetReply) *)msgItemVideoMeetReplayFromDictionary:(NSDictionary *)dict;

// Object-C消息类信息转换类
+ (CCNameSpace(CCMessageBodyBase) *)msgBodyBaseFromDictionary:(NSDictionary *)dict;
// Object-C消息类信息转换类
+ (NSDictionary *)dictionaryFromMsgBodyBase:(CCNameSpace(CCMessageBodyBase) *)info;

// Object-C接收信息转换类
+ (CCNameSpace(CCMessageChatInfo) *)chatInfoFromDictionary:(NSDictionary *)dict;
// Object-C接收信息转换类
+ (NSDictionary *)dictionaryFromChatInfo:(CCNameSpace(CCMessageChatInfo) *)info;

// Object-C更新信息转换类
+ (CCNameSpace(CCMessageChatUpdate) *)chatUpdateFromDictionary:(NSDictionary *)dict;
// Object-C更新信息转换类
+ (NSDictionary *)dictionaryFromChatUpdate:(CCNameSpace(CCMessageChatUpdate) *)info;

// Object-C发送消息转换类
+ (CCNameSpace(CCMessageSendAck) *)sendAckFromDictionary:(NSDictionary *)dict;
// Object-C发送消息转换类
+ (NSDictionary *)dictionaryFromSendAck:(CCNameSpace(CCMessageSendAck) *)info;

// Object-C发送消息转换类
+ (CCNameSpace(CCMessageSendChat) *)sendChatFromDictionary:(NSDictionary *)dict;
// Object-C发送消息转换类
+ (NSDictionary *)dictionaryFromSendChat:(CCNameSpace(CCMessageSendChat) *)info;

// Object-C接收消息转换类
+ (CCNameSpace(CCReceiveAck) *)receiveAckFromDictionary:(NSDictionary *)dict;
// Object-C接收消息转换类
+ (NSDictionary *)dictionaryFromReceiveAck:(CCNameSpace(CCReceiveAck) *)info;

// Object-C接收消息转换类
+ (CCNameSpace(CCReceiveUnknow) *)receiveUnknowFromDictionary:(NSDictionary *)dict;
// Object-C接收消息转换类
+ (NSDictionary *)dictionaryFromReceiveUnknow:(CCNameSpace(CCReceiveUnknow) *)info;

// Object-C接收消息转换类
+ (CCNameSpace(CCReceivePerson) *)receivePersonFromDictionary:(NSDictionary *)dict;
// Object-C接收消息转换类
+ (NSDictionary *)dictionaryFromReceivePerson:(CCNameSpace(CCReceivePerson) *)info;

// Object-C接收消息转换类
+ (CCNameSpace(CCReceiveGroup) *)receiveGroupFromDictionary:(NSDictionary *)dict;
// Object-C接收消息转换类
+ (NSDictionary *)dictionaryFromReceiveGroup:(CCNameSpace(CCReceiveGroup) *)info;

// Object-C接收消息转换类
+ (CCNameSpace(CCReceiveTempGroup) *)receiveTempGroupFromDictionary:(NSDictionary *)dict;
// Object-C接收消息转换类
+ (NSDictionary *)dictionaryFromReceiveTempGroup:(CCNameSpace(CCReceiveTempGroup) *)info;

// 接收信息转换类 CCMessageChatInfo
+ (void)fillChatInfoFromDictionary:(NSDictionary *)dict info:(CCNameSpace(CCMessageChatInfo) *)info;
// 接收信息转换类 CCMessageChatInfo
+ (void)fillDictionaryFromChatInfo:(CCNameSpace(CCMessageChatInfo) *)info dict:(NSMutableDictionary *)dict;

// Object-C接收消息转换类
+ (CCNameSpace(CCReceiveGroupInfo) *)receiveGroupInfoFromDictionary:(NSDictionary *)dict;
// Object-C接收消息转换类
+ (NSDictionary *)dictionaryFromReceiveGroupInfo:(CCNameSpace(CCReceiveGroupInfo) *)info;

// Object-C接收消息转换类
+ (CCNameSpace(CCReceiveGroupAction) *)receiveGroupActionFromDictionary:(NSDictionary *)dict;

+ (CCNameSpace(CCReceiveErrorInfo) *)receiveErrorInfoFromDictionary:(NSDictionary *)dict;
// Object-C接收消息转换类
+ (NSDictionary *)dictionaryFromReceiveGroupAction:(CCNameSpace(CCReceiveGroupAction) *)info;
+ (CCNameSpace(CCReceiveUserAuthApply) *)receiveUserAuthApplyFromDictionary:(NSDictionary *)dict;

+ (CCNameSpace(CCReceiveHistoryMessage) *)receiveHistoryMessageFromDictionary:(NSDictionary *)dict;
// Object-C接收文件转换类
+ (CCNameSpace(CCMethodUpFileInfo) *)methodUpFileInfoFromDictionary:(NSDictionary *)dict;
// Object-C接收文件转换类
+ (NSDictionary *)dictionaryFromMethodUpFileInfo:(CCNameSpace(CCMethodUpFileInfo) *)info;

// Object-C接收文件转换类
+ (CCNameSpace(CCMethodUpFileResult) *)methodUpFileResultFromDictionary:(NSDictionary *)dict;
// Object-C接收文件转换类
+ (NSDictionary *)dictionaryFromMethodUpFileResult:(CCNameSpace(CCMethodUpFileResult) *)info;

// Object-C接收文件转换类
+ (CCNameSpace(CCMethodDownFileInfo) *)methodDownFileInfoFromDictionary:(NSDictionary *)dict;
// Object-C接收文件转换类
+ (NSDictionary *)dictionaryFromMethodDownFileInfo:(CCNameSpace(CCMethodDownFileInfo) *)info;

// Object-C接收文件转换类
+ (CCNameSpace(CCMethodDownFileResult) *)methodDownFileResultFromDictionary:(NSDictionary *)dict;
// Object-C接收文件转换类
+ (NSDictionary *)dictionaryFromMethodDownFileResult:(CCNameSpace(CCMethodDownFileResult) *)info;


// Object-C接收文件转换类
+ (CCNameSpace(CCAvatarUpFileResult) *)avatarUpFileResultFromDictionary:(NSDictionary *)dict;
// Object-C接收文件转换类
+ (NSDictionary *)dictionaryFromAvatarUpFileResult:(CCNameSpace(CCAvatarUpFileResult) *)info;

// Object-C接收文件转换类
+ (CCNameSpace(CCAvatarDownFileResult) *)avatarDownFileResultFromDictionary:(NSDictionary *)dict;
// Object-C接收文件转换类
+ (NSDictionary *)dictionaryFromAvatarDownFileResult:(CCNameSpace(CCAvatarDownFileResult) *)info;
// 踢人接收消息 转 模型
+ (CCNameSpace(CCReceiveKickOutInfo) *)receiveKickOutInfoFromDictionary:(NSDictionary *)dict;
// 接收同账号设备登录消息转换类
+ (CCNameSpace(CCQRCodeLoadDevic) *)receivesameCountLoadFromDictionary:(NSDictionary *)dict;
//接收到开始共享文档消息转换
+ (CCNameSpace(CCReceiveStartShareDocumentMessage) *)receiveStartShareDocumentFromDictionary:(NSDictionary *)dict;
@end

#endif //_CC_CCDataModel_Transform_H_
