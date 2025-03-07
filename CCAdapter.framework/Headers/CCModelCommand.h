//
//  CCModelCommand.h
//  adapter
//
//  Created by yiyimama on 2017/5/18.
//  Copyright © 2017年 zsx. All rights reserved.
//

#ifndef _CC_CCDataModel_Command_H_
#define _CC_CCDataModel_Command_H_

#import <Foundation/Foundation.h>

#import "CCModelBase.h"
//#import "gson/iCmd.h" // libcc

// 命令字的返回状态
enum CCCommandStatusCode
{
    //StatusCode
    //正常
    CCStatusCodeOK = 200,
    //错误访问
    CCStatusCodeBadRequest = 400,
    //未授权
    CCStatusCodeUnauthorized = 401,
    //禁止访问
    CCStatusCodeInvalidLogin = 403,
    //未找到
    CCStatusCodeNotFound = 404,
    //方法禁用
    CCStatusCodeNotAllowed = 405,
    //不接受
    CCStatusCodeNotAcceptable = 406,
    //需要代理授权
    CCStatusCodeProxyRequired = 407,
    //请求超时
    CCStatusCodeRequestTimeout = 408,
    //未知错误
    CCStatusCodeUnknownError = 421,
    //服务出现异常
    CCStatusCodeInternalServerError = 500,
};

// cmd: 协议命令字,是否必须：是
// ctype: 指定数据体的主要类型,是否必须：否
// stype: 指定数据体的次要类型,是否必须：否
// path: 消息经过路径,是否必须：否

#define	CC_CTYPE_STRING    @"txt"
#define	CC_STYPE_STRING    @"json"

// 常见ctype 与 stype 的定义及关联如下，
// 当不提供 ctype 时则默认值为 txt，
// 当 ctype 为 txt 且 stype 不存在时则默认值为 json
// txt - json,xml,plain,html，
// img - gif,jpg,png,bmp，doc - pdf,word,ppt,excel
// media - voice,video，bin - octream

// path 为该消息经由的节点路由，以逗号”,”分隔，按先后顺序排序。
// 每一个集群节点的接入层应该首先检查该字段，需要防止路由产生回路。

enum CCCommandMessageType //协议命令字
{
    // 客户端Ping命令字
    mtype_ping = -1,
    // 客户端空命令字，或未知命令字
    mtype_unknown = 0,

    // 客户端登录返回命令字
    mtype_recv_login_reply = 1100,
    
    // 客户端发送命令字
    mtype_send_message = 1101,
    // 客户端发送返回命令字
    mtype_send_message_reply = 1102,
    
    // 客户端接收命令字
    mtype_recv_message = 1103,
    // 客户端接收返回命令字
    mtype_recv_message_reply = 1104,

    // 客户端离线信息请求命令字
    mtype_offline_message = 1105,
    // 客户端离线信息返回命令字
    mtype_offline_message_reply	= 1106,
    
    // 客户端注册推送信息
    mtype_register_pushnotify = 1107,
    // 客户端注册推送信息返回命令字
    mtype_register_pushnotify_reply	= 1108,

    // 客户端请求在线状态命令字
    mtype_send_presence = 1201,
    // 客户端请求在线状态返回命令字
    mtype_send_presence_reply = 1202,
    
    // 客户端发送聊天会话数据
    mtype_send_chat_session = 1203,
    // 客户端发送聊天会话数据返回
    mtype_send_chat_session_reply = 1204,
    
    // 客户端发送聊天会话更新数据
    mtype_send_chat_update = 1205,
    // 客户端发送聊天会话更新数据返回
    mtype_send_chat_update_reply = 1206,
    
    // 客户端发送用户数据更新数据
    mtype_send_user_update = 1207,
    // 客户端发送用户数据更新数据返回
    mtype_send_user_update_reply = 1208,
    
    // 客户端接收聊天会话数据
    mtype_recv_chat_update = 2101,
    // 客户端接收聊天会话数据返回
    mtype_recv_chat_update_reply = 2102,
    
    // 客户端发送用户数据更新
    mtype_recv_user_update = 2103,
    // 客户端发送用户数据更新返回
    mtype_recv_user_update_reply = 2104,
    
    // 客户端发送群消息命令字
    mtype_send_group_message = 1301,
    // 客户端发送群消息返回命令字
    mtype_send_group_message_reply = 1302,
    
    // 客户端接收群消息命令字
    mtype_recv_group_message = 1303,
    // 客户端接收群消息返回命令字
    mtype_recv_group_message_reply = 1304,

    // 客户端请求创建群命令字
    mtype_send_group_create = 1401,
    // 客户端请求创建群返回命令字
    mtype_send_group_create_reply = 1402,

    // 客户端接收创建群命令字
    mtype_recv_group_create = 4101,
    // 客户端接收创建群返回命令字
    mtype_recv_group_create_reply = 4102,

    // 客户端请求邀请入群命令字
    mtype_send_group_invite = 1403,
    // 客户端返回邀请入群命令字
    mtype_send_group_invite_reply = 1404,
    
    // 客户端接收邀请入群命令字
    mtype_recv_group_invite = 4103,
    // 客户端接收返回邀请入群命令字
    mtype_recv_group_invite_reply = 4104,
    
    // 客户端请求处理入群邀请命令字
    mtype_send_group_invite_deal = 1405,
    // 客户端请求处理入群邀请返回命令字
    mtype_send_group_invite_deal_reply = 1406,
    
    // 客户端接收处理入群邀请命令字
    mtype_recv_group_invite_deal = 4105,
    // 客户端接收处理入群邀请返回命令字
    mtype_recv_group_invite_deal_reply = 4106,

    // 客户端请求申请加群命令字(apply)
    mtype_send_group_join = 1407,
    // 客户端请求申请加群返回命令字(apply)
    mtype_send_group_join_reply = 1408,
    
    // 客户端接收申请加群命令字(apply)
    mtype_recv_group_join = 4107,
    // 客户端接收申请加群返回命令字(apply)
    mtype_recv_group_join_reply = 4108,
    
    // 客户端发送处理申请加群命令字(apply)
    mtype_send_group_join_deal = 1409,
    // 客户端发送处理申请加群返回命令字(apply)
    mtype_send_group_join_deal_reply = 1410,
    
    // 客户端接收处理申请加群命令字(apply)
    mtype_recv_group_join_deal = 4109,
    // 客户端接收处理申请加群返回命令字(apply)
    mtype_recv_group_join_deal_reply = 4110,

    // 客户端请求踢出用户命令字
    mtype_send_group_kickout = 1411,
    // 客户端请求踢出用户返回命令字
    mtype_send_group_kickout_reply = 1412,
    
    // 4.4.1.21服务端推送退群结果协议
    // 客户端接收踢出用户命令字
    mtype_recv_group_kickout = 4111,
    // 客户端接收踢出用户返回命令字
    mtype_recv_group_kickout_reply = 4112,

    // 客户端请求退群协议命令字
    mtype_send_group_quit = 1413,
    // 客户端请求退群协议返回命令字
    mtype_send_group_quit_reply = 1414,
    
    // 客户端接收退群协议命令字
    mtype_recv_group_quit = 4113,
    // 客户端接收退群协议返回命令字
    mtype_recv_group_quit_reply = 4114,

    // 客户端请求群设置命令字(attribute)
    mtype_send_group_modify   = 1415,
    // 客户端请求群设置返回命令字(attribute)
    mtype_send_group_modify_reply = 1416,
    
    // 客户端接收群设置命令字(attribute)
    mtype_recv_group_modify   = 4115,
    // 客户端接收群设置返回命令字(attribute)
    mtype_recv_group_modify_reply = 4116,
    
#if 0x0
    // 客户端请求设置群管理员命令字
    mtype_send_group_role = 1417,
    // 客户端请求设置群管理员返回命令字
    mtype_send_group_role_reply = 1418,
#endif
#if 0x0
    // 客户端接收设置群管理员命令字
    mtype_recv_group_role = 4117,
    // 客户端接收设置群管理员返回命令字
    mtype_recv_group_role_reply = 4118,
#endif
    
    // 客户端请求群设置管理员命令字(admin)
    mtype_send_group_admin = 1417,
    // 客户端请求群设置管理员返回命令字(admin)
    mtype_send_group_admin_reply = 1418,
    
    // 客户端接收群设置管理员命令字(admin)
    mtype_recv_group_admin = 4117,
    // 客户端接收群设置管理员返回命令字(admin)
    mtype_recv_group_admin_reply = 4118,
    
    // 客户端请求群收回管理员命令字(recover)
    mtype_send_group_admin_recover = 1419,
    // 客户端请求群收回管理员返回命令字(recover)
    mtype_send_group_admin_recover_reply = 1420,
    
    // 客户端接收群收回管理员命令字(recover)
    mtype_recv_group_admin_recover = 4119,
    // 客户端接收群收回管理员返回命令字(recover)
    mtype_recv_group_admin_recover_reply = 4120,
    
    // 客户端请求群设置所有者命令字(owner)
    mtype_send_group_owner = 1421,
    // 客户端请求群设置所有者返回命令字(owner)
    mtype_send_group_owner_reply = 1422,
    
    // 客户端接收群设置所有者命令字(owner)
    mtype_recv_group_owner = 4121,
    // 客户端接收群设置所有者返回命令字(owner)
    mtype_recv_group_owner_reply = 4122,
    
    // 客户端请求用户群名片命令字(nick)
    mtype_send_group_vcard = 1423,
    // 客户端请求用户群名片返回命令字(nick)
    mtype_send_group_vcard_reply = 1424,
    
    // 客户端接收用户群名片命令字(nick)
    mtype_recv_group_vcard = 4123,
    // 客户端接收用户群名片返回命令字(nick)
    mtype_recv_group_vcard_reply = 4124,
    
    // 客户端请求群收取开关命令字
    mtype_send_group_receive = 1425,
    // 客户端请求群收取开关返回命令字
    mtype_send_group_receive_reply = 1426,
    
    // 客户端接收群收取开关命令字
    mtype_recv_group_receive = 4125,
    // 客户端接收群收取开关返回命令字
    mtype_recv_group_receive_reply = 4126,

    // 客户端请求解散群协议命令字(drop)
    mtype_send_group_disbanded = 1427,
    // 客户端请求解散群协议返回命令字(drop)
    mtype_send_group_disbanded_reply = 1428,
    
    // 客户端请求设置 群权限
    mtype_send_group_Auth = 1429,
    mtype_send_group_Auth__reply = 1430,

    
    // 客户端请求设置 群成员信息
    mtype_send_group_MemberMessage = 1431,
    mtype_send_group_MemberMessage_reply = 1432,

    // 客户端请求设置 群成员申请权限
    mtype_send_group_MemberApplyMessage = 1433,
    mtype_send_group_MemberApplyMessage_reply = 1434,

    
    // 客户端接收解散群协议命令字(drop)
    mtype_recv_group_disbanded = 4127,
    // 客户端接收解散群协议返回命令字(drop)
    mtype_recv_group_disbanded_reply = 4128,
    
    // 客户端接收到 群权限被修改
    mtype_recv_group_AuthChanged = 4129,
    mtype_recv_group_AuthChanged_reply = 4130,

    // 客户端接收到 群成员信息被修改
    mtype_recv_group_MemberMessageChangedNoti = 4131,
    mtype_recv_group_MemberMessageChangedNoti_reply = 4132,
    
    // 客户端接收到 群成员申请 权限通知
    mtype_recv_group_MemberApplyMessageChangedNoti = 4133,
    mtype_recv_group_MemberApplyMessageChangedNoti_reply = 4134,
    
    // 客户端接收到 群主转移失败消息
    mtype_recv_group_OwnerChanged_ErrorNoti = 4137,

    
    // 客户端接收到 消息同步 应答
    mtype_recv_Message_sync_HistoryMessage_Noti = 4201,
    
    
    // 客户端接收到 被踢出
    mtype_recv_kickout_byserver = 9004,
    // 客户端接收到退出成功消息
    mtype_recev_logout_succuss = 1000,
    //客户端接收到此账号在其他设备上登录或者退出的消息,取值判断的地方不一样，所以有两个值
    mtype_recev_SaveAcountLoad_noti = 14,
    mtype_recev_SaveAcountLoadDevice_noti = 100,
    //客户端接收到共享文档类型的通知
    mtype_recev_DocumentShareType_noti = 3107,
    //接收到开始共享文档
    mtype_recev_startShareDocument_noti = 3071,
    //接收到结束共享文档
    mtype_recev_endShareDocument_noti = 3072,
    //文档标注权限
    mtype_recev_ShareDocumentNoteAuth_noti = 3073,
    //文档自由翻页权限
    mtype_recev_ShareDocumentFreelyTurnPageAuth_noti = 3074,
    //文档百分比
    mtype_recev_ShareDocumentPercent_noti = 3075,
    //文档翻页
    mtype_recev_ShareDocumentTurnPageAuth_noti = 3076,
    //文档标注
    mtype_recev_ShareDocumentNote_noti = 3077,
    //文档标注删除
    mtype_recev_ShareDocumentNoteDelete_noti = 3078,
    //共享文档上传后转码状态改变
    mtype_recev_TranscodingComplete_noti = 3079,
    
    mtype_recev_MediaSharePlayAndStop_noti = 6001,
    mtype_recev_MediaShareProgress_noti = 6002,
    
    
    /// chatroom 绑定APPID
    mtype_recv_BindAppId_Message = 103,
    /// chatroom 解绑APPID
    mtype_recv_UnBindAppId_Message = 105,
    
    mtype_recv_MTGroups_Message_ToGroup = 3107,
    mtype_recv_MTGroups_Message_ToSomeOne = 3125,
    mtype_recv_MTGroups_Message_ToHost = 3127,


};
typedef \
enum CCCommandMessageType CCCommandMessageType;

#endif //_CC_CCDataModel_Command_H_
