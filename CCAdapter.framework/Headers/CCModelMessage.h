//
//  CCModelMessage.h
//  adapter
//
//  Created by jinxiangkun on 17/3/26.
//  Copyright © 2017年 zsx. All rights reserved.
//

#ifndef _CC_CCDataModel_Message_H_
#define _CC_CCDataModel_Message_H_

#import <Foundation/Foundation.h>

#import "CCModelBase.h"
#import "CCModelMethod.h"
#import "CCModelStruct.h"

//不能包含C++
//#include "CCEMInterface.h"

// 与ccsdk通讯接口，很乱的接口！
//ccsdk/include/SdkDefine/MsgSt.h

//#define MSG_TYPE_TEXT   0
//#define MSG_TYPE_JSON   1

#define STMSG_CFM           0
#define STMSG_PER           1
#define STMSG_GROUP         2
#define STMSG_DIS           3
#define STMSG_GPAC_NOTIFY   4
#define STMSG_GPINFO_NOTIFY 5
#define STMSG_PUSH_RES      6
#define STMSG_UNPUSH_RES    7
#define STMSG_LOGOUT_RES    8
#define STMSG_KICKED_NOTIFY      9
#define STMSG_GROUP_GETOWNER_RESULT 15

#define STMSG_CHAT_ROOM_MESSAGE_NOTIFY 0xFF39

#define STMSG_FIXED_GROUP_TO_ALL_MESSAGE_NOTIFY 40

#define STMSG_UNKNOW        1000

/////////////////////////////////////////////////////////////

enum CCChatObjectType //消息的接收类型
{
    CCChatObjectTypeBase = -1, //st_re_base
    CCChatObjectTypeAck = 0, //st_re_ack //0：收到的消息确认信息
    CCChatObjectTypePerson = CCItemInfoTypeUser, //st_re_pmsg //1：收到个人消息
    CCChatObjectTypeGroup = CCItemInfoTypeGroup, //st_re_gmsg //2：群消息
    CCChatObjectTypeTempGroup = CCItemInfoTypeTempGroup, //st_re_dmsg //3：临时组消息
    CCChatObjectTypeUnknow = 1000, //st_re_unknow //1000：未知协议
};
typedef enum CCChatObjectType CCChatObjectType;

// struct st_base_info //消息的基础抽像
@interface CCNameSpace(CCMessageBase) : NSObject

// int get_interface()
- (NSInteger)getObjectType; // 消息对像的类型
//@property (readonly, assign) CCChatObjectType objectType;

@end

// struct st_chat_update //消息的原节点更新类型
@interface CCNameSpace(CCMessageChatUpdate) : CCNameSpace(CCMessageBase)

@property (strong) NSString * tag; //tag
@property (strong) NSString * uid; //用户ID
@property (strong) NSString * cid; //客户ID，可选
@property (assign) NSInteger eiwType; //会话类型
@property (strong) NSString * msgid; //消息ID
@property (assign) long long  msgtime; //'收发时间，精度到毫秒
@property (assign) CCSendState status; //发送的状态

@end

// struct st_re_base //消息的接收抽像
@interface CCNameSpace(CCReceiveBase) : CCNameSpace(CCMessageBase)

// int get_interface()
- (NSInteger)getReceiveType; //CCReceiveType
//@property (readonly, assign) CCChatObjectType receiveType;

@end

// struct st_chat_info //个人消息的信息条目抽像
@interface CCNameSpace(CCMessageChatInfo) : CCNameSpace(CCReceiveBase)

// int get_interface() { return 1; }
- (NSInteger)getObjectType; // 消息所属对像的类型

//消息基础信息
@property (strong) CCNameSpace(CCMessageNodeInfo) * node;
//消息所属会话信息
@property (strong) CCNameSpace(CCMessageOwnerInfo) * owner;
//发送至的信息
@property (strong) CCNameSpace(CCMessageSenderInfo) * sender;
//消息的内容信息
@property (strong) CCNameSpace(CCMessageBodyBase) * msgbody;

@end

/////////////////////////////////////////////////////////////

// Ack-回复确认

enum CCMessageSendType //消息的发送类型
{
    CCMessageSendTypeBase = -1,//st_base
    CCMessageSendTypeUnknow = 0,//st_unknow
    CCMessageSendTypeAck = 1, //st_msg_ack_to_server
    CCMessageSendTypeChat = 2, //struct SendSruct 聊天消息
    //CCMessageSendTypeBody = 3, //st_msg_send 作废？
};
typedef enum CCMessageSendType CCMessageSendType;

// struct st_send_
@interface CCNameSpace(CCMessageSendBase) : NSObject

- (NSInteger)getObjectType; // CCChatObjectType
- (NSInteger)getMessageSendType; //CCMessageSendTypeAck

@property (assign) long long ts; //时间戳, 单位是毫秒
@property (strong) NSString * tag; //用户发送的uuid
@property (assign) /*const*/ void * userRef; //用户引用指针，可空

@end

// 消息同步
@interface CCNameSpace(CCHistoryMessage) : NSObject

@property (copy) NSString * type;
@property (copy) NSString * cid;
@property (copy) NSString * hid;
@property (copy) NSString * max; //时间戳, 最大值
@property (copy) NSString * updatetime; //时间戳, 更新时间
@property (copy) NSString * MSGID;


@property (assign) long long  starttime; //起始时间
@property (assign) long long  endtime;   //结束时间
@property (assign) NSInteger  count;     //每页消息条数
@property (assign) NSInteger  page;      //获取第几页消息
@property (assign) NSInteger  maxpage;   //消息总页码
//方向，0 向前查找 即查找消息时间<updatetime的消息
//     1 向后查找 即查找消息时间>updatetime的消息，
@property (copy) NSString * direction;
@property (assign) int  status;     //消息状态 已读 未读

@end


// struct st_msg_ack_to_server
@interface CCNameSpace(CCMessageSendAck) : CCNameSpace(CCMessageSendBase)

- (NSInteger)getObjectType; // CCChatObjectType
- (NSInteger)getMessageSendType; //CCMessageSendType

@property (assign) NSInteger cmd; //命令字
//@property (assign) long long ts; //时间戳, 单位是毫秒
@property (strong) NSString * id_; //信息id
@property (strong) NSString * rid; //源信息id
//@property (strong) NSString * uid; //确认者UID
//@property (strong) NSString * cid; //确认者消息CID

@end

// struct SendSruct 发送的个人聊天信息
@interface CCNameSpace(CCMessageSendChat) : CCNameSpace(CCMessageSendBase)

- (NSInteger)getObjectType; // CCChatObjectType
- (NSInteger)getMessageSendType; //CCMessageSendTypeChat

//@property (assign) long long ts; //时间戳, 单位是毫秒
@property (strong) CCNameSpace(CCMessageNodeBase) * node; //消息基础信息
//@property (strong) CCNameSpace(CCMessageSenderInfo) * owner; //发送至的信息
@property (strong) CCNameSpace(CCMessageSenderInfo) * sender; //owner发送至的信息
@property (strong) CCNameSpace(CCMessageBodyBase) * msgbody; //消息的内容信息

@end

#if 0x0 // 作废
// struct st_msg_send 发送的聊天信息 作废？
@interface CCNameSpace(CCMessageSendBody) : CCNameSpace(CCMessageSendBase)

- (NSInteger)getObjectType; // CCChatObjectType
- (NSInteger)getMessageSendType; //CCMessageSendTypeBody

//@property (assign) long long ts; //时间戳, 单位是毫秒
@property (strong) CCNameSpace(CCCommandHead) * head; //命令头
@property (strong) CCNameSpace(CCMessageSendBase) * body; //发送体

@end
#endif


/////////////////////////////////////////////////////////////

// CxSdkSession.cpp //会话管理类

enum CCReceiveType //消息的接收类型
{
    CCReceiveTypeBase = CCChatObjectTypeBase, //st_re_base
    CCReceiveTypeAck = STMSG_CFM, //0：收到的消息确认信息
    CCReceiveTypePerson = CCChatObjectTypePerson, //1：收到个人消息
    CCReceiveTypeGroup = CCChatObjectTypeGroup, //2：群消息
    CCReceiveTypeTempGroup = CCChatObjectTypeTempGroup, //3：临时组消息
    CCReceiveTypeGroupActionNotify = STMSG_GPAC_NOTIFY, //4：群组推送动作消息
    CCReceiveTypeGroupInfoNotify = STMSG_GPINFO_NOTIFY, //5：群组推送信息消息
    CCReceiveTypePushInfoNotify = STMSG_PUSH_RES, //6：推送消息，呼叫，其他等
    //CCReceiveTypeRegisterPushNotify = STMSG_PUSH_RES, //6：推送消息，呼叫，其他等
    CCReceiveTypeUnregisterPushNotify = STMSG_UNPUSH_RES, //7: 取消推送结果返回
    CCReceiveTypeLogoutReply = STMSG_LOGOUT_RES, //8: 注销结果返回
    CCReceiveTypeKickOutByServer = STMSG_KICKED_NOTIFY, // 被提掉线

    CCReceiveTypeUnknow = CCChatObjectTypeUnknow, //1000：未知协议
   
};
typedef enum CCReceiveType CCReceiveType;

// struct st_re_ack
// struct ReMsgReply : public IReBase
@interface CCNameSpace(CCReceiveAck) : CCNameSpace(CCReceiveBase)

- (NSInteger)getReceiveType;

@property (assign) NSInteger  cmd; //命令字
@property (strong) NSString * tag; //Tag
@property (strong) NSString * msgid; //消息ID
@property (strong) NSString * info; //说明
@property (strong) NSString * uid; //消息UID
@property (strong) NSString * cid; //消息CID
@property (assign) long long  msgtime; //消息时间

@end

// struct st_re_unknow
@interface CCNameSpace(CCReceiveUnknow) : CCNameSpace(CCReceiveBase)

- (NSInteger)getReceiveType;

@property (strong) NSString * json; //未知协议数据

@end

// struct st_re_pmsg 个人消息类型
@interface CCNameSpace(CCReceivePerson) : CCNameSpace(CCMessageChatInfo)

- (NSInteger)getReceiveType;

@end

// struct st_re_gmsg 群消息类型
@interface CCNameSpace(CCReceiveGroup) : CCNameSpace(CCMessageChatInfo)

- (NSInteger)getReceiveType;

//@property (strong) NSString * groupid; //群ID
//@property (strong) NSString * groupcid; //群CID
//@property (strong) NSString * groupname; //群用户名

@end

// struct st_re_dmsg 临时会话消息类型
@interface CCNameSpace(CCReceiveTempGroup) : CCNameSpace(CCMessageChatInfo)

- (NSInteger)getReceiveType;

//@property (strong) NSString * groupid; //群ID
//@property (strong) NSString * groupcid; //群CID
//@property (strong) NSString * groupname; //群用户名

@end

/////////////////////////////////////////////////////////////

// 群组的消息结构体信息

// struct DbGroupAction
@interface CCNameSpace(CCReceiveGroupAction) : CCNameSpace(CCReceiveBase)

- (NSInteger)getReceiveType;

// 协议Cmd用以辨别内部协议类型
@property (assign) NSInteger cmd; //命令字
@property (strong) NSString * gid; //群ID
@property (strong) NSString * gcid; //群客户ID
@property (strong) NSString * gname; //群名字
@property (strong) NSString * uid; //操作者ID
@property (strong) NSString * ucid; //操作者客户ID
@property (strong) NSString * uname; //操作者名字
@property (strong) NSString * msgid; //信息id
@property (strong) NSString * msgrid; //源信息id
@property (strong) NSString * details; //说明
@property (assign) NSInteger istatus; //消息状态
@property (assign) long long  msgtime; //消息时间
// std::list<group_user_t> lgMember;
@property (strong) NSMutableArray * baseList; //用户明细

@property (strong) NSMutableArray * vExcludes; //排除的用户明细
@property (strong) NSString * authType; //权限说明
@property (assign) NSInteger authValue; //权限状态
@property (strong) NSMutableDictionary * infoDict; //附加信息
@property (assign) BOOL cancel; //取消邀请
@property (assign) BOOL isPushNotice; //是推送来的
@property (nonatomic,assign) NSInteger reason;
@property (nonatomic,assign) NSInteger act_mode;//0：成员状态同步变更（默认，兼容云视），并通知appserver，1：仅改变群组属性


@end
// join 、转移主持人的报错信息
@interface CCNameSpace(CCReceiveErrorInfo) : CCNameSpace(CCReceiveBase)

- (NSInteger)getReceiveType;

// 协议Cmd用以辨别内部协议类型
@property (assign) NSInteger cmd; //命令字
@property (strong) NSString * gid; //群ID
@property (strong) NSString * cid; //群客户ID
@property (strong) NSString * opt; //上行操作类型 join: 申请入会（1407），change_owner：转移主持人(1421)
@property (assign) NSInteger reason; //提醒原因 0: 无passcode的join或change_owner 1: join是通过passcode提权  2: join时创建者收回权限 3: 会中通过passcode提权 4: 会中创建者收回权限
@property (assign) NSInteger errcode; //错误编号 400:passcode 不匹配 403：权限拒绝 404: 组不存在 500：其他错误
@property (assign) NSInteger auth; //是否需申请人会, opt=join时有效，1:需申请入会权限 0：无需申请入会
@property (strong) NSString * msgid; //信息id

@end


@interface CCNameSpace(CCReceiveHistoryMessage) : CCNameSpace(CCReceiveBase)

- (NSInteger)getReceiveType;

// 协议Cmd用以辨别内部协议类型
@property (assign) NSInteger cmd; //命令字
@property (strong) NSString * sMsgid; //信息id
@property (assign) NSInteger status; //消息状态
@property (assign) NSInteger stkey; //消息类型值
@property (strong) NSString * info; // 消息info


@end
@interface CCNameSpace(CCReceiveUserAuthApply) : CCNameSpace(CCReceiveBase)

- (NSInteger)getReceiveType;

// 协议Cmd用以辨别内部协议类型
@property (assign) NSInteger cmd; //命令字
@property (strong) NSString * gid; //群ID
@property (strong) NSString * gcid; //群客户ID
@property (strong) NSString * gname; //群名字
@property (strong) NSString * uid; //操作者ID
@property (strong) NSString * ucid; //操作者客户ID
@property (strong) NSString * uname; //操作者名字
@property (strong) NSString * msgid; //信息id
@property (strong) NSString * msgrid; //源信息id
@property (strong) NSString * details; //说明
@property (assign) NSInteger istatus; //消息状态
@property (assign) long long  msgtime; //消息时间
// std::list<group_user_t> lgMember;
@property (strong) NSMutableArray * baseList; //用户明细

@property (strong) NSString * authType; //权限说明
@property (assign) NSInteger authValue; //权限状态
@property (strong) NSMutableDictionary * infoDict; //附加信息
@end

// struct ReGroupInfo
@interface CCNameSpace(CCReceiveGroupInfo) : CCNameSpace(CCReceiveBase)

- (NSInteger)getReceiveType;

// 群表中添加或更新群列表
@property (strong) CCNameSpace(CCModelFixedGroupInfo) * groupInfo;

@end

//struct st_push_res
@interface CCNameSpace(CCReceivePushInfo) : CCNameSpace(CCReceiveBase)

- (NSInteger)getReceiveType;

// 协议Cmd用以辨别内部协议类型
@property (assign) NSInteger cmd; //命令字
@property (strong) NSString * msgid; //信息id
@property (strong) NSString * msgrid; //源信息id
@property (assign) NSInteger istatus; //消息状态
@property (strong) NSString * pushInfo; //Push 消息info

@end

//struct st_push_res
@interface CCNameSpace(CCReceiveKickOutInfo) : CCNameSpace(CCReceiveBase)

- (NSInteger)getReceiveType;

// 协议Cmd用以辨别内部协议类型
@property (assign) NSInteger cmd; //命令字
@property (strong) NSString * sMsgid; //信息id
@property (assign) NSInteger status; //消息状态
@property (assign) NSInteger stkey; //消息类型值
@property (strong) NSString * info; // 消息info
@property (assign) NSInteger subtype; // 被踢原因
/*subtype
 0 , info ""    缺省的原类型 1 , info UserDelete 用户删除 subtype 2 , info UserDisable     用户禁用 subtype 3 , info LoginDelete     登录信息删除 subtype 4 , info LoginModify     登录信息修改*/
@end

/////////////////////////////////////////////////////////////


// 接收消息的类实例类型
// struct st_msg_base
@interface CCNameSpace(CCMessageResult) : NSObject

- (BOOL)isEmptyMessage;

@property (strong) CCNameSpace(CCCommandHead) * head; //命令头
@property (strong) CCNameSpace(CCReceiveBase) * data; //接收的消息

@end

// 接收消息的类实例类型别名
typedef CCNameSpace(CCMessageResult) CCNameSpace(CCMessageRecvResult);

//扫码登录设备类型
@interface CCNameSpace(CCQRCodeLoadDevic) : CCNameSpace(CCReceiveBase)

@property (nonatomic,copy) NSString *devId;
@property (nonatomic,assign) loginDeviceType devType;
@property (nonatomic,assign) long long timestamp; //扫码登录时间
@property (nonatomic,assign) bool bOnLine; 

@end


@interface CCNameSpace(CCReceiveStartShareDocumentMessage) : CCNameSpace(CCReceiveBase)
- (NSInteger)getReceiveType;
// 协议Cmd用以辨别内部协议类型
@property (assign) NSInteger cmd; //命令字
@property (copy) NSString * id_; //信息id
@property (copy) NSString * gid;
@property (copy) NSString * app_id;
@property (assign) NSInteger ts;
@property (copy) NSString* from_cid;
@property (copy) NSString * from_uid;
@property (copy) NSString * from_dev;
@property (copy) NSDictionary * from;
@property (copy) NSDictionary * sess;
@property (assign) NSInteger type;
@property (copy) NSString * body;
@end

/// chatroom
@interface CCNameSpace(CCReceiveChatRoomMessage) : CCNameSpace(CCReceiveBase)
- (NSInteger)getReceiveType;
// 协议Cmd用以辨别内部协议类型
@property (assign) NSInteger cmd; //命令字
@property (assign) NSInteger type;
@property (copy) NSString * msg_id; //信息id
@property (copy) NSString * jsonBody;
@property (copy) NSDictionary * attrsDict;

@end

/// chatroom 绑定
@interface CCNameSpace(CCReceiveChatRoomBindMessage) : CCNameSpace(CCReceiveBase)
- (NSInteger)getReceiveType;
// 协议Cmd用以辨别内部协议类型
@property (assign) NSInteger cmd; //命令字
@property (assign) NSInteger type;
@property (copy) NSString * msg_id; //信息id
@property (copy) NSString * app_id; 

@property (copy) NSString * to_cid;
@property (copy) NSString * to_uid;
@property (copy) NSString * to_dev;
@property (assign) int status; //命令字
@property (assign) long long ts; //命令字
@property (copy) NSString * info;

@end

#endif //_CC_CCDataModel_Message_H_
