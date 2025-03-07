//
//  CCAdapterKeys.h
//  CCAdapter
//
//  Created by jinxiangkun on 2019/1/8.
//  Copyright © 2019年 jinxiangkun. All rights reserved.
//

#ifndef CCAdapterKeys_h
#define CCAdapterKeys_h

//配置信息
#define CCClientConfig_ServerAddress \
@"CCClientConfig_ServerAddress"
#define CCClientConfig_ServerPort \
@"CCClientConfig_ServerPort"
#define CCClientConfig_MeetServerAddress \
@"CCClientConfig_MeetServerAddress"
#define CCClientConfig_MeetServerPort \
@"CCClientConfig_MeetServerPort"
#define CCClientConfig_NotifyWhenRecvicedNewMessage \
@"CCClientConfig_NotifyWhenRecvicedNewMessage"
#define CCClientConfig_NotifyShowMessageDetailContext \
@"CCClientConfig_NotifyShowMessageDetailContext"
#define CCClientConfig_NotifyModeVoice \
@"CCClientConfig_NotifyModeVoice"
#define CCClientConfig_NotifyModeVibration \
@"CCClientConfig_NotifyModeVibration"

//登陆状态变化
#define CCClientDidLoginNotification \
@"com.net263.CCClientDidLoginNotification"
#define CCClientWillLogoutNotification \
@"com.net263.CCClientWillLogoutNotification"
#define CCClientDidLogoutNotification \
@"com.net263.CCClientDidLogoutNotification"

#define CCClientConfigKey_ServerAddress \
@"com.net263.CCClientConfigKey_ServerAddress"
#define CCClientConfigKey_ServerPort \
@"com.net263.CCClientConfigKey_ServerPort"

#define CCGetUserAuthInfoNotification \
@"com.net263.CCGetUserAuthInfoNotification"
#define CCGetUserModelInfoNotification \
@"com.net263.CCGetUserModelInfoNotification"
#define CCSendUserAuthInfoNotification \
@"com.net263.CCSendUserAuthInfoNotification"
#define CCSendUserModelInfoNotification \
@"com.net263.CCSendUserModelInfoNotification"

//停止播放语音
#define CCStopAudioPlayerNotification \
@"com.net263.CCStopAudioPlayerNotification"
//登陆账户切换
#define CCLoginAccoutChangedNotification \
@"com.net263.CCLoginAccoutChangedNotification"

//消息通知
#define CCMessageNotification \
@"com.net263.CCMessageNotification"
#define CCTransmitMessageNotification \
@"com.net263.CCTransmitMessageNotification"
#define CCMessageNotificationKey_UID \
@"com.net263.CCMessageNotificationKey_UID"
#define CCMessageNotificationKey_CID \
@"com.net263.CCMessageNotificationKey_CID"
#define CCMessageNotificationKey_Action \
@"com.net263.CCMessageNotificationKey_Action"
#define CCMessageNotificationKey_Value \
@"com.net263.CCMessageNotificationKey_Value"
#define CCMessageNotificationKey_SendingResult \
@"com.net263.CCMessageNotificationKey_SendingResult"

#define CCMessageReceiveJoinRoomInvitationNotification \
@"com.net263.CCMessageReceiveJoinRoomInvitationNotification"

#define CCClientSyncHistoryMessageNotification \
@"com.net263.CCClientSyncHistoryMessageNotification"

#define CCMessageNotificationSystemMessageNotification \
@"com.net263.CCMessageNotificationSystemMessageNotification"

#define CCMessageRegisterPushSuccessNotification \
@"com.net263.CCMessageRegisterPushSuccessNotification"
//未读数通知

#define CCUnreadNumberChangedNotification \
@"com.net263.CCUnreadNumberChangedNotification"
#define CCUnreadNumberChangedNotificationKey_UID \
@"com.net263.CCUnreadNumberChangedNotificationKey_UID"
#define CCUnreadNumberChangedNotificationKey_CID \
@"com.net263.CCUnreadNumberChangedNotificationKey_CID"
#define CCUnreadNumberChangedNotificationKey_Value \
@"com.net263.CCUnreadNumberChangedNotificationKey_Value"
#define CCUnreadNumberChangedNotificationKey_TriggerClass \
@"com.net263.CCUnreadNumberChangedNotificationKey_TriggerClass"

//用户信息

//用户信息发生改变
#define CCUserInfoChangedNotification \
@"com.net263.CCUserInfoChangedNotification"
//用户ID
#define CCUserInfoChangedNotificationKey_UID \
@"com.net263.CCUserInfoChangedNotificationKey_UID"
//用户客户ID
#define CCUserInfoChangedNotificationKey_CID \
@"com.net263.CCUserInfoChangedNotificationKey_CID"
//用户通知操作类型
#define CCUserInfoChangedNotificationKey_Action \
@"com.net263.CCUserInfoChangedNotificationKey_Action"
//用户通知的object，字典
#define CCUserInfoChangedNotificationKey_VALUE \
@"com.net263.CCUserInfoChangedNotificationKey_VALUE"
//用户昵称
#define CCUserInfoChangedNotificationKey_NICKName \
@"com.net263.CCUserInfoChangedNotificationKey_NICKName"
//用户头像
#define CCUserInfoChangedNotificationKey_HEADIMAGE \
@"com.net263.CCUserInfoChangedNotificationKey_HEADIMAGE"
//用户手机
#define CCUserInfoChangedNotificationKey_MOBILE \
@"com.net263.CCUserInfoChangedNotificationKey_MOBILE"
//用户签名
#define CCUserInfoChangedNotificationKey_SIGNNAME \
@"com.net263.CCUserInfoChangedNotificationKey_SIGNNAME"
//用户部门
#define CCUserInfoChangedNotificationKey_DEPARTMENT \
@"com.net263.CCUserInfoChangedNotificationKey_DEPARTMENT"

//更新了组织结构列表了！
#define CCClientDidUpdateRosterNotification \
@"com.net263.CCClientDidUpdateRosterNotification"

//用户设置更新了
#define CCClientConfigChangedNotification \
@"com.net263.CCClientConfigChangedNotification"
//
#define CCClientConfigChangedNotificationKey_Type \
@"com.net263.CCClientConfigChangedNotificationKey_Type"
//
#define CCClientConfigChangedNotificationKey_Value \
@"com.net263.CCClientConfigChangedNotificationKey_Value"

//群信息
//加入群, 退群， 解散群，群名称，群公告，群主变化，群管理员，是否接受群消息

//群消息更新
#define CCGroupInfoChangedNotification \
@"com.net263.CCGroupInfoChangedNotification"
//群消息更新
#define CCGroupInfoChangedSendNotification \
@"com.net263.CCGroupInfoChangedSendNotification"
//群消息更新
#define CCGroupInfoChangedRecvNotification \
@"com.net263.CCGroupInfoChangedRecvNotification"
//群ID
#define CCGroupInfoChangedNotificationKey_GID \
@"com.net263.CCGroupInfoChangedNotificationKey_GID"
//群客户ID
#define CCGroupInfoChangedNotificationKey_CID \
@"com.net263.CCGroupInfoChangedNotificationKey_CID"
//动作
#define CCGroupInfoChangedNotificationKey_ACTION \
@"com.net263.CCGroupInfoChangedNotificationKey_ACTION"
//用户签名
#define CCGroupInfoChangedNotificationKey_VALUE \
@"com.net263.CCGroupInfoChangedNotificationKey_VALUE"

//组信息
//加入组， 退出组，解散组， 修改组名称，修改组公告， 是否接受组消息

//组消息更新
#define CCDiscussGroupInfoChangedNotification \
@"com.net263.CCDiscussGroupInfoChangedNotification"
//群ID
#define CCDiscussGroupInfoChangedNotificationKey_GID \
@"com.net263.CCDiscussGroupInfoChangedNotificationKey_GID"
//动作
#define CCDiscussGroupInfoChangedNotificationKey_ACTION \
@"com.net263.CCDiscussGroupInfoChangedNotificationKey_ACTION"
//用户签名
#define CCDiscussGroupInfoChangedNotificationKey_VALUE \
@"com.net263.CCDiscussGroupInfoChangedNotificationKey_VALUE"
//退出成功通知
#define CCMessageLogoutSuccess @"com.net263.CCMessageLogoutSuccess"

//同一账号在其他端登录通知
#define CCMessageSameAcountLoadChangeNotify @"com.net263.CCMessageSameAcountLoadChangeNotify"
//单例设备列表已经更新成功，需要重新回去设备列表通知
#define CCMessageNeedReloadDeviceListNotify @"com.net263.CCMessageNeedReloadDeviceListNotify"
//文档转码完成通知
#define CCMessageTranscodingCompleteNotify @"com.net263.CCMessageTranscodingCompleteNotify"
//接收到文档共享通知
#define CCMessageReceiveShareDocumentNotify @"com.net263.CCMessageReceiveShareDocumentNotify"
//接收到结束文档共享通知
#define CCMessageReceiveEndShareDocumentNotify @"com.net263.CCMessageReceiveEndShareDocumentNotify"
//接收到文档共享通用通知
#define CCMessageReceiveShareDocumentCommenNotify @"com.net263.CCMessageReceiveShareDocumentCommenNotify"
//接收到插播共享通知
#define CCMessageReceiveShareMediaCommenNotify @"com.net263.CCMessageReceiveShareMediaCommenNotify"

//接收到文档共享批注改变通知
#define CCMessageReceiveShareDocumentNoteAuthNotify @"com.net263.CCMessageReceiveShareDocumentNoteAuthNotify"

//接收到chatroom消息
#define CCMessageReceiveChatRoomCommenNotify @"com.net263.CCMessageReceiveChatRoomCommenNotify"
//接收到chatroom绑定和解绑消息
#define CCMessageReceiveBindChatRoomCommenNotify @"com.net263.CCMessageReceiveBindChatRoomCommenNotify"

//接收到分组消息
#define CCMessageReceiveMeetingGroupNotify @"com.net263.CCMessageReceiveMeetingGroupNotify"


#endif /* CCAdapterKeys_h */
