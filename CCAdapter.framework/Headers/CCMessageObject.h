//
//  CCMessageObject.h
//  NetMeetingCC
//
//  Created by jinxiangkun on 2019/1/3.
//  Copyright © 2019年 jinxiangkun. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCModelBase.h"
#import "CCModelStruct.h"
#import "CCModelMessage.h"
#import "CCModelMethod.h"
#import "CCBaseObject.h"

typedef NS_ENUM(NSInteger, CCMessageRole)
{
    CCMessageRole_Receiver = 1, //消息接受者
    CCMessageRole_Sender = 2,   //消息发送者
};

typedef NS_ENUM(NSInteger, CCMessageHandleMode)
{
    CCMessageHandleMode_Tail = (1L << 0), //消息插入至队尾
    CCMessageHandleMode_Head = (1L << 1), //消息插入至头部
    CCMessageHandleMode_Order = (1L << 2), //消息顺序插入
};

typedef NS_ENUM(NSInteger, CCMessageDataType)
{
    CCMessageDataTypeUndefined = 0, //未确定
    CCMessageDataTypeCombinedMessage = (1 << 15), //组合消
    CCMessageDataTypeGeneral_Date = ((1 << 31) + 2), //时间
    CCMessageDataTypeSpeakAuth = (1<<16),//禁言和解除禁言提醒
};

#define CCMessageSendMessageCofirmInternal (30) //30秒超时

typedef NS_ENUM(long long, CCMessageFlags)
{
    CCMessageFlags_NoFlags = 0LL,
    CCMessageFlags_SendSuccess =  (1LL << 0), //消息发送成功
    CCMessageFlags_fileUploadSuccess = (1LL << 1), //文件上传成功
    CCMessageFlags_CombinedMessage = (1LL << 10), //图文混排消息
};

extern NSString * const CCResouceKey_ResouceKey; //键值
extern NSString * const CCResouceKey_ResouceURL; //链接地址
extern NSString * const CCResouceKey_ResoucePath; //文件路径
extern NSString * const CCResouceKey_ResouceName; //文件名称
extern NSString * const CCResouceKey_ResouceExt; //扩展名称
extern NSString * const CCResouceKey_VoiceDuration; //音频文件时长

typedef NS_ENUM(NSInteger, CCResouseDownloadState)
{
    CCResouseDownloadState_Downloading = (1L << 0), //正在下载
    CCResouseDownloadState_Success = (1L << 1), //下载成功
    CCResouseDownloadState_Fail = (1L << 2), //下载出错，失败
};

//文本与表情区分
@interface CCNameSpace(CCMessageItem) : CCNameSpace(CCBaseObject)

@property (nonatomic, assign) long long itemType;
@property (nonatomic, assign) NSRange range;
@property (nonatomic, copy) NSString *content;

@end

//将基础消息类型多条分解成单条l显示使用！
@interface CCNameSpace(CCMessageObject) : CCNameSpace(CCBaseObject)

@property (nonatomic, strong) CCMessageItemVideoMeet * meetModel;
@property (nonatomic, strong) CCMessageItemVideoMeetReply * replyMeetModel;
@property (nonatomic, strong) CCMessageItemVideoMeetNotify * videoMeetNotifyModel;

//会话ID
@property (nonatomic, copy) NSString * sid;
//会话的CID
@property (nonatomic, copy) NSString * scid;
//会话类型，单聊，群，应用
@property (nonatomic, assign) NSInteger chatType;

//命令字
@property (nonatomic, assign) NSInteger  cmd;
//Tag, uuid！
@property (nonatomic, strong) NSString * tag;
//消息ID
@property (nonatomic, strong) NSString * msgid;
//源消息ID
@property (nonatomic, strong) NSString * msgrid;
//消息时间, 单位是毫秒
@property (nonatomic, assign) long long  msgtime;
//0,正常消息, 1,已撤回消息
@property (nonatomic, assign) NSInteger  type;
//状态
@property (nonatomic, assign) long long status;
//消息类型 CCMessageType ??
@property (nonatomic, assign) NSInteger msgtype; //不用了
//是否为发送消息 1:收 2发
@property (nonatomic, assign) NSInteger direction;
//消息发送的状态，读node.status
//@property (nonatomic, assign) CCSendState status; //不用了
//消息基础信息引用类，主要依据类！
@property (strong) CCNameSpace(CCMessageNodeInfo) * node; //head

//发送者信息
@property (nonatomic, copy  ) NSString * uid;
//@property (nonatomic, copy  ) NSString * ownerUid;
@property (nonatomic, copy  ) NSString * cid;
//@property (nonatomic, copy  ) NSString * ownerCid;
@property (nonatomic, copy  ) NSString * name;
//@property (nonatomic, copy  ) NSString * ownerName;
@property (nonatomic, assign) NSInteger sestype; //会话信息的类型
//消息所属会话信息，主要依据类！
@property (strong) CCNameSpace(CCMessageOwnerInfo) * owner; //发送者信息

//群组的发送者信息
@property (nonatomic, copy  ) NSString * senderUid;
@property (nonatomic, copy  ) NSString * senderCid;
@property (nonatomic, copy  ) NSString * senderName;
@property (nonatomic, assign) NSInteger targettype; //接收者的类型
//消息发送至的信息，主要依据类！
@property (strong) CCNameSpace(CCMessageSenderInfo) * sender; //发送至信息

//发送时间, 消息时间, 单位是毫秒
@property (nonatomic, assign) long long datetime; //=msgtime
//消息的类型 CCMessageItemType, TEXT, IMAGE, Voice ...
@property (nonatomic, assign) long long dataType; //可能会不准

//消息的详细信息
@property (nonatomic, copy  ) NSString * body; //文本信息描述
@property (nonatomic, strong) NSMutableArray * msgBody; //消息体列表
//消息的内容信息，主要依据类！
//baseBody->getSubItemType 转换为 dataType
@property (strong) CCNameSpace(CCMessageItemBase) * baseBody; //转换为消息子类


// 正在上传资源
@property (nonatomic, assign) NSInteger isUpFailed;
@property (nonatomic, assign) BOOL resouseIsUploading; //上传资源中，防重入
// 正在下载资源
@property (nonatomic, assign) NSInteger isDownFailed;
@property (nonatomic, assign) BOOL resouseIsDownloading; //下载资源中，防重入
// 绘制消息的信息
@property (nonatomic, strong) NSMutableDictionary *textDrawInfo;

//缓存信息用字典
@property (nonatomic, strong) NSMutableDictionary * cachedInfos;
//消息携带资源信息
@property (nonatomic, strong) NSMutableDictionary * resourceInfos; //缓存信息类

@property (nonatomic, assign) CGFloat portraitHeight;
@property (nonatomic, assign) CGFloat landscapeHeight;

@property (nonatomic,assign) bool isFailedToResend; //是否是重新发送的消息，因为重新发送的消息要显示在最底部


//是否是别人发的消息
- (BOOL)isReciveMessage;
//(message.direction == CCMessageRole_Receiver)

//已上传图像的KEY
- (NSString *)localImageKey;
//原始图像的路径
- (NSString *)localImageFilePath;
//预览图像的路径
- (NSString *)localImageThumbNailFilePath;
//原始发送图像的路径
- (NSString *)senderImageFilePath; //只有大图

//已上传语音的KEY
- (NSString *)localVoiceKey;
//语音文件的路径
- (NSString *)localVoiceFilePath;
//原始发送语音的路径
- (NSString *)senderVoiceFilePath;

// 预览图像的最大大小
- (CGSize)imageMaxThumbnailSize;
// 预览图像的当前的大小
- (CGSize)imageCurrentThumbnailSize; //缩放值！

// 当大图下载成功后，可以生成小图
- (void)stroeImage:(CCNameSpace(CCMessageItemBase) *)msgItem;

// 消息成功后，清除发送的缓存文件！
- (void)cleanSendMessageSuccessMessageBodyFile;

// 重写上传成功后的缓存数据
+ (void)stroeImage:(CCNameSpace(CCMessageItemBase) *)msgItem
            result:(CCNameSpace(CCMethodUpFileResult) *)upResult;

// 重写上传成功后的缓存数据
+ (void)stroeVoice:(CCNameSpace(CCMessageItemBase) *)msgItem
            result:(CCNameSpace(CCMethodUpFileResult) *)upResult;

//消息发送监测
- (void)cleanSendMessageSuccessConfimTimer;
- (void)startSendMessageSuccessConfimTimerWithTimeInterval:(int)inter
                                                     Block:
    (void (^)(void))block performQueue:(dispatch_queue_t)queue;

- (void)startSendMessageSuccessConfimTimerWithBlock:(void (^)(void))block
                                       performQueue:(dispatch_queue_t)queue;

- (void)reStartSendMessageSuccessConfimTimerWithBlock:(void (^)(void))block
                                         performQueue:(dispatch_queue_t)queue;

+ (id)convertReciveMessageObj:(CCNameSpace(CCReceiveBase) *)msg;

// 转换为接收对像
+ (NSArray *)convertMessageChatInfoInfo:(CCNameSpace(CCMessageChatInfo) *)msg;

// 转换为发送消息对像！
//+ (CCMessageSendBase *)convertLocalSendMessageObj:(CCNameSpace(CCMessageObj) *)msg;
+ (CCMessageSendBase *)convertLocalSendMessageObj:(CCNameSpace(CCMessageObject) *)msg;

// 缓存当前消息对像的文件，上传文件
// 缓存当前消息对像的文件，上传文件，由图片服务器创建缩略图
//+ (void)uploadMessageFileInfo:(BOOL)updateThumbNail
+ (void)uploadMessageFileInfo:(CCNameSpace(CCMessageChatInfo) *)msg
                      msgItem:(CCNameSpace(CCMessageItemBase) *)msgItem
                       msgObj:(CCNameSpace(CCMessageObject) *)currentMsgObj
                       result:(void (^)(CCCallState state, NSString *localKey))block;

// 缓存当前消息对像的文件，下载文件
+ (void)downloadMessageFileInfo:(CCNameSpace(CCMessageChatInfo) *)msg
                        msgItem:(CCNameSpace(CCMessageItemBase) *)msgItem
                         msgObj:(CCNameSpace(CCMessageObject) *)currentMsgObj
                         result:(void (^)(CCCallState state, NSString *localUrl))block;

// 缓存当前消息对像的文件，下载文件
+ (void)downloadMessageFileInfo:(BOOL)updateThumbNail
                        msgInfo:(CCNameSpace(CCMessageChatInfo) *)msg
                        msgItem:(CCNameSpace(CCMessageItemBase) *)msgItem
                         msgObj:(CCNameSpace(CCMessageObject) *)currentMsgObj
                         result:(void (^)(CCCallState state, NSString *localUrl))block;


@end
