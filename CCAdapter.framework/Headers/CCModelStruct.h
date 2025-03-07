//
//  CCModelStruct.h
//  adapter
//
//  Created by jinxiangkun on 17/4/17.
//  Copyright © 2017年 zsx. All rights reserved.
//

#ifndef _CC_CCDataModel_Session_Struct_H_
#define _CC_CCDataModel_Session_Struct_H_

#import <Foundation/Foundation.h>

#import "CCModelBase.h"
#import "CCModelMethod.h"
#import "CCModelCommand.h"

//#include "CCEMInterface.h" //不能包含C++

// 与ccsdk通讯接口，很乱的接口！

//'状态，
// 0：未发送；
// 1：正在发送，2：发送成功；
// 3：发送失败；4未读；：5：已读',
#define  STATUS_UNSEND    0
#define  STATUS_SENDING   1
#define  STATUS_SENDSUCC  2
#define  STATUS_SENDFAIL  3
#define  STATUS_UNREAD    4
#define  STATUS_READED    5
#define  STATUS_WITHDRAW  6

// 100：草稿的状态 ??
#define  STATUS_DRAFT     100

// 消息的发送与接收状态
enum CCSendState
{
    CCSendStatePre = 0, //发送前
    CCSendStateUnsend = 0, //发送前
    CCSendStateSending = 1, //发送中
    CCSendStateSendFailed = 2, //发送失败
    CCSendStateSended = 3, //未读/发送成功
    CCSendStateReaded = 4, //已读状态
    CCSendStateWithdraw = 5, //撤回状态
    CCSendStateMissReaded = 6, //错过的邀请 + 已读

};
typedef enum CCSendState CCSendState;


// 消息的收发消息方向定义
#define  DIRECTION_RECV    1
#define  DIRECTION_SEND    2

enum CCSendDirectionState
{
    CCSendDirectionStateNone = 0,
    CCSendDirectionStateRecvIn = 1, //接收
    CCSendDirectionStateSendOut = 2, //发出
};

// Ses-会话
// 这个是session的类型
// enum EM_ITEMOWNER
// 1：人，2：群，3：临时会话，4：应用，5：系统消息；6：好友申请',
enum CCMessageTargetType
{
    CCMessageTargetNone = CCItemInfoTypeUnknow,
    CCMessageTargetUser = CCItemInfoTypeUser, // 用户
    CCMessageTargetGroup = CCItemInfoTypeGroup, // 群
    CCMessageTargetTempGroup = CCItemInfoTypeTempGroup, // 临时群
    CCMessageTargetApp = CCItemInfoTypeApp, // 应用
    CCMessageTargetSystem = CCItemInfoTypeSystem, // 系统
    CCMessageTargetFriend = CCItemInfoTypeFriend, // 好友
    CCMessageTargetDepart = CCItemInfoTypeDepart, // 部门
    CCMessageTargetCustomer = CCItemInfoTypeCustomer, // 客户
    //CCMessageTargetAssistant = CCItemInfoTypeAssistant, // 助理
};

// struct st_session
// 最后一条消息的msgid如果为草稿，则ID为固定ID。
@interface CCNameSpace(CCSessionInfo) : NSObject

@property (strong) NSString * key; //id+cid
@property (strong) NSString * uid; //用户ID
@property (strong) NSString * cid; //客户ID，可选
@property (strong) NSString * name; //会话名字
@property (assign) NSInteger type; //会话类型 CCMessageTargetType
@property (assign) NSInteger unreadnum; //未读消息计数
@property (assign) long long  sestime; //会话时间，精度到毫秒
@property (strong) NSString * msgid; //最后一条消息的消息ID，
@property (assign) NSInteger msgstatus; //最后一条消息的状态，CCSendState
@property (strong) NSString * lastcontent; //最后一条消息的消息预览

- (void)updateSession:(CCNameSpace(CCSessionInfo) *)other;

@end

// Ack-回复确认

// struct st_msg_head
@interface CCNameSpace(CCMessageHead) : NSObject

@property (assign) NSInteger  cmd; //命令字 
//@property (strong) NSString * cmd; //命令字 CCCommandMessageType
@property (strong) NSString * tag; //用户标识
@property (strong) NSString * ctype; //主要类型
@property (strong) NSString * stype; //次要类型
@property (strong) NSString * id_; //ID号,当HEAD头出现id:true时才返回

@end

typedef  CCNameSpace(CCMessageHead) CCNameSpace(CCCommandHead);

// struct st_ack_send 发送确认信息
// struct st_ack_recv 接收到推送的确认信息
@interface CCNameSpace(CCMessageReply) : NSObject

@property (assign) NSInteger  status; //状态码
@property (strong) NSString * info; //状态描述
@property (assign) long long  ts; //时间戳, 单位是毫秒
@property (strong) NSString * id_; //ID号,当HEAD头出现id:true时才返回

@end

typedef  CCNameSpace(CCMessageReply) CCNameSpace(CCCommandReply);


/////////////////////////////////////////////////////////////

// 通用发送接收的目标信息
// struct SenderSt
@interface CCNameSpace(CCMessageTarget) : NSObject

@property (strong) NSString * id_; //接收者或发送者id
@property (strong) NSString * cid; //接收者或发送者客户ID
@property (strong) NSString * name; //接收者或发送者名字

@end

// 消息的标识所属会话信息
// struct SessionSt
@interface CCNameSpace(CCMessageOwnerInfo) : CCNameSpace(CCMessageTarget)

@property (assign) NSInteger  sestype; //会话信息的类型
//@property (strong) NSString * sesid; // 会话信息"id_::cid"

@end

// 发送用的接收者目标信息
// struct RecverSt
@interface CCNameSpace(CCMessageSenderInfo) : CCNameSpace(CCMessageTarget)

//接收者类型 CCMessageTargetType
@property (assign) NSInteger  targettype; //接收者的类型

// 从sdk的类型值转换到adapter的类型值
//+ (NSInteger)targetTypeFromSDK:(long long)sdkType;
// 从adapter的类型值转换到sdk的类型值
//+ (long long)targetTypeToSDK:(CCMessageTargetType)sdkType;

@end

/////////////////////////////////////////////////////////////

// enum EmMsgType
enum CCMessageNodeType
{
    CCMessageNodeTypeText = 0x0, //EMT_TEXT
    CCMessageNodeTypeJson, // EMT_JSON
};
typedef enum CCMessageNodeType CCMessageNodeType;

// 消息的基础信息节点内容
// struct MsgExInfo
@interface CCNameSpace(CCMessageNodeBase) : NSObject

@property (strong) NSString * tag; //Tag, uuid！
@property (strong) NSString * msgid; //消息ID
//@property (strong) NSString * msgrid; //源消息ID
@property (assign) long long  msgtime; //消息时间, 单位是毫秒

@end

// 消息的基础信息节点属性内容
// struct MsgProperty
@interface CCNameSpace(CCMessageNodeInfo) : CCNameSpace(CCMessageNodeBase)

@property (assign) NSInteger   cmd; //命令字
@property (assign) NSInteger   type; //0,正常消息, 1,已撤回消息
@property (assign) CCSendState status; //消息发送的状态
@property (assign) NSInteger   direction; //是否为发送消息 1:收 2发
@property (assign) NSInteger   msgtype; //消息类型 CCMessageType ??

@end

/////////////////////////////////////////////////////////////

// 发送消息子对像类型
// enum EmSubMsg
enum CCMessageItemType
{
    CCMessageItemTypeNone = -1,
    CCMessageItemTypeText = 0, //文本 //ESM_TEXT = 0x0000,
    CCMessageItemTypeImage = 1, // 图片 //ESM_IMAGE,
    CCMessageItemTypeVoice = 2, // 语音 //ESM_VOICE,
    CCMessageItemTypeFace = 3, // 表情 //ESM_FACE,
    CCMessageItemTypeGroupAction = 4, //群内的操作消息 //ESM_GPACTION,
    CCMessageItemTypeVideoConf = 5, //视频会议 //ESM_VIDEO_CONF,
    CCMessageItemTypeVideoMeet = 6, //视频会议邀请 //ESM_VIDEO_MEET,
    CCMessageItemTypeVideoMeetInviteReply = 7, //视频会议邀请回复 //ESM_VIDEO_MEET,
    CCMessageItemTypeVideoMeetNotify = 8, //视频会议通知消息 //ESM_MEET_NOTIFY,

};

// 消息子对像基类
// class ISubMsg
@interface CCNameSpace(CCMessageItemBase) : NSObject

// 获取消息类型
- (NSInteger)getSubItemType;
// 获取编码后的消息，例如图片替换为[image]等
- (NSString *)getEncoderText;

// 从sdk的类型值转换到adapter的类型值
//+ (NSInteger)msgItemTypeFromSDK:(long long)sdkType;
// 从adapter的类型值转换到sdk的类型值
//+ (long long)msgItemTypeToSDK:(CCMessageItemType)sdkType;

@end

// 消息子对像文本消息类
// class SubMsgText
@interface CCNameSpace(CCMessageItemText) : CCNameSpace(CCMessageItemBase)

// 获取消息类型
- (NSInteger)getSubItemType;

@property (strong) NSString * content; //文本信息的内容

@end

// 消息子对像表情消息类
// class SubMsgFace
@interface CCNameSpace(CCMessageItemFace) : CCNameSpace(CCMessageItemBase)

// 获取消息类型
- (NSInteger)getSubItemType;

@property (strong) NSString * content; //表情信息的内容

@end

// 消息子对像图像消息类
// class SubMsgImage
@interface CCNameSpace(CCMessageItemImage) : CCNameSpace(CCMessageItemBase)

// 获取消息类型
- (NSInteger)getSubItemType;

//@property (strong) NSString * content; //文本信息的内容
@property (assign) NSInteger imagesize; //图片的大小
@property (strong) NSString * imagekey; //图片的id值
@property (strong) NSString * imageurl; //图片的网络路径
@property (strong) NSString * imagefile; //图片的本地路径

@end

// 消息子对像语音消息类
// class SubMsgVoice
@interface CCNameSpace(CCMessageItemVoice) : CCNameSpace(CCMessageItemBase)

// 获取消息类型
- (NSInteger)getSubItemType;

//@property (strong) NSString * content; //文本信息的内容
@property (strong) NSString * voicekey; //语音的id值
@property (strong) NSString * voiceurl; //语音的网络路径
@property (strong) NSString * voicefile; //语音的本地路径
@property (assign) long long  voicelength; //语音长度精确到毫秒

@end

// 消息子对像视频会议消息类
// class SubMsgVideoConf
@interface CCNameSpace(CCMessageItemVideoConf) : CCNameSpace(CCMessageItemBase)

// 获取消息类型
- (NSInteger)getSubItemType;

@property (strong) NSString * videoRoomId; //视频会议的房间Id
@property (strong) NSString * videoRoomUrl; //视频会议的会议地址

@end

// 消息子对像视频会议消息类
// class SubMsgVideoMeet
@interface CCNameSpace(CCMessageItemVideoMeet) : CCNameSpace(CCMessageItemBase)

// 获取消息类型
- (NSInteger)getSubItemType;

@property (strong) NSString * title; //会议主题
@property (strong) NSString * body; //邀请携带消息
@property (strong) NSString * videoRoomId; //会议房间号
@property (strong) NSString * videoRoomName; //会议名字
@property (strong) NSString * videoRoomPwd; //会议密码
@property (strong) NSString * videoMeetType;// 消息类型
@property (assign) long long  llRoomStart; //会议开始时间
//std::string sTitle;       //会议主题
//std::string sBody;        //邀请携带消息
//std::string sRoomId;      //会议房间号
//std::string sRoomPwd;     //会议密码
//std::string sRoomName;    //会议名字
//long long   llRoomStart;  //会议开始时间

@end

@interface CCNameSpace(CCMessageItemVideoMeetReply) : CCNameSpace(CCMessageItemBase)

// 获取消息类型
- (NSInteger)getSubItemType;

@property (strong) NSString * event; //邀请消息的ID
@property (strong) NSString * body; //邀请携带消息
@property (assign) int  iAction;    //0:同意 1:拒绝 其他:自定义

@end
@interface CCNameSpace(CCMessageItemVideoMeetNotify) : CCNameSpace(CCMessageItemBase)

// 获取消息类型
- (NSInteger)getSubItemType;

@property (strong) NSString * event; //邀请消息的ID
@property (strong) NSString * body; //邀请携带消息
@property (strong) NSDictionary * bodyDict; //邀请携带消息

@property (assign) int  act;   

@end
// 消息发送或接收的统一消息体对像
// struct MsgBody
// 可以创建通用帮助函数可以构造一份数据出来！
@interface CCNameSpace(CCMessageBodyBase) : NSObject

// 获得文本消息内容串
- (NSString *)message;

// 消息内容数据的列表
@property (strong) NSMutableArray * baseList;

// 添加文本信息
- (void)addContentText:(NSString *)text;
// 添加表情信息
- (void)addContentFace:(NSString *)face;
// 添加图片信息
- (void)addContentImage:(NSString *)imageFile;
// 添加图片信息对像
- (void)addContentItemImage:(CCNameSpace(CCMessageItemImage) *)object;
// 添加语音信息, milliSecond语音的长度
- (void)addContentVoice:(NSString *)voiceFile length:(long long)milliSecond;
// 添加语音信息对像
- (void)addContentItemVoice:(CCNameSpace(CCMessageItemVoice) *)object;
// 添加视频会议对像
- (void)addContentItemVideoConf:(CCNameSpace(CCMessageItemVideoConf) *)object;
// 添加网络会议消息对像
- (void)addContentItemVideoMeet:(CCNameSpace(CCMessageItemVideoMeet) *)object;
// 添加网络会议消息回复对像
- (void)addContentItemVideoMeetReply:(CCNameSpace(CCMessageItemVideoMeetReply) *)object;

- (void)addContentItemMeetVideoConf:(CCNameSpace(CCMessageItemVideoMeet) *)object;

- (void)addContentItemMeetVideoConfReply:(CCNameSpace(CCMessageItemVideoMeetReply) *)object;

@end

/////////////////////////////////////////////////////////////

// 注册推送平台
// struct platform_info_t : IInterface
@interface CCNameSpace(CCPlatformPushInfo) : NSObject

@property (assign) NSInteger cmd; //命令字
@property (assign) NSInteger type; //类型，iOS为5
@property (strong) NSString * sToken; //Token识别号

@end

/////////////////////////////////////////////////////////////

// 发送消息的文件传输结构体 StFile.h

// @传参
// struct StUpInfo
@interface CCNameSpace(CCMethodUpFileInfo) : NSObject

// ESM_IMAGE, ESM_VOICE ...
@property (assign) NSInteger fileType; //文件类型
@property (strong) NSString * suffixType; //文件后缀名
@property (strong) NSString * fileName; //文件名
@property (strong) NSString * localFileUrl; //本地文件路径 UTF8

// 根据文件路径填充参数
- (void)setFileInfo:(NSString *)sPathFile;

@end

// @返回下载结果
// struct StUpResult
@interface CCNameSpace(CCMethodUpFileResult) : NSObject

@property (assign) bool bSuccess;  //操作是否成功
@property (strong) NSString * name;   //文件名
@property (strong) NSString * owner;  //拥有者
@property (strong) NSString * url;    //文件url
@property (strong) NSString * local;  //新的本地路径
@property (strong) NSString * key;    //文件key
@property (strong) NSString * ctype;  //文件类型
@property (strong) NSString * stype;  //文件类型
@property (assign) int        size;   //文件大小
@property (assign) long       ctime;  //上传时间
@property (assign) int        ttl;    //服务器的保存时间

@end

// @下载传参
// struct StDownInfo
@interface CCNameSpace(CCMethodDownFileInfo) : NSObject

// ESM_IMAGE, ESM_VOICE ...
@property (assign) NSInteger fileType;//文件类型
@property (strong) NSString * messageID;
@property (strong) NSString * key;    //文件key
@property (strong) NSString * url;    //文件url
@property (assign) NSInteger  eiType;  //EM_ITEMOWNER
@property (assign) BOOL       bThumbNail; //是否下载小图

@end

// @返回下载结果
// struct StDownResult
@interface CCNameSpace(CCMethodDownFileResult) : NSObject

@property (assign) bool bSuccess;  //操作是否成功
@property (strong) NSString * url;    //文件url
@property (assign) int        size;   //文件大小
@property (strong) NSString * key;    //文件key
@property (strong) NSString * localUrl;  //新的本地路径
@property (strong) NSString * messageID; //文件消息id


@end

/////////////////////////////////////////////////////////////

// 发送头像的文件传输结构体 AvatarSt.h

// @上传头像结果
// struct UpAvatarResult
@interface CCNameSpace(CCAvatarUpFileResult) : NSObject

@property (assign) bool bSuccess;  //操作是否成功
@property (strong) NSString * sNewPathFile;  //新的文件路径

@end

// @下载头像结果
// struct DownAvatarResult
@interface CCNameSpace(CCAvatarDownFileResult) : NSObject

@property (assign) bool bSuccess;  //操作是否成功
@property (strong) NSString * sNewPathFile;  //新的文件路径

@end



#endif //_CC_CCDataModel_Session_Struct_H_
