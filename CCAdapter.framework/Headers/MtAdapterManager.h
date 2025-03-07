//
//  MtAdapterManager.h
//  MtAdapter
//
//  Created by jinxiangkun on 2019/1/14.
//  Copyright © 2019年 jinxiangkun. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCObjectHeader.h"

#import "MtBaseObjects.h"
#import "MtBaseSeriaQueue.h"

// 调用状态！
enum MtCallState
{
    MtCallOK = 200, //调用成功返回
    MtConference_Lock= 1305, //会议加锁
    MtConference_Force= 1409, //会议已经在里面了
    MtConference_Invalid= 1303, //The room id is invalid.
    MtConference_CidFrozen= 1105, //cid has been frozen
    MtRoomIDNotFound = 1200,  //会议不存在
    MtConference_Full = 1410, //会议已经在里面了 1410 1411 1412
    MtPermissionDennied = 1140,// 没有权限
    MtRoomIsRecording = 1502,// The meeting is being recorded.

    MtSessionTokenInvalid = 1131,//无效 
    MtSessionTokenExpired = 1132,    //过期
    MtSessionTokenError = 1133,    //其他错误 
    MtSessionTokenInvalidRoom = 1134 ,   //sessionToken包含的房间和请求房间不匹配 
    MtSessionTokenNotExist = 1135,    //请求头中未包含seesionToken 
    MtSessionTokenBuildFailed = 1136 ,   //新的sessionToken构建失败
    
    MtNetWorkFailed = 0, //网络未连接
    MtNoSdkInstance = 5, //没有sdk实例
//    MtRoomIDError = 404,  //没有sdk实例
    MtLoginInfoInvalid = 410,  //没有sdk实例
    MtNotFound = 404,  //

    MtRequestError = 500,
//    MtFailed = -1, //调用错误
//    MtUnknowError = 100, //未知错误
//    MtNoSessionID = 2, //没有设置SessionID
//    MtSessionIDTimeOut = 3, //SessionID已过期
//    MtNoSetServer = 11, //没有设置会议服务器地址
};
typedef enum MtCallState MtCallState;

// 客户端状态 //ZCMClientState
typedef NS_ENUM(NSInteger, MtSdkState)
{
    // 无状态
    MtSdkStateNone = 0,
    // 初始化Client实例
    MtSdkStateInit = 1L << 0,
    // 获得会议室Token
    MtSdkStateToken = 1L << 1,
    // 使用Token加入会议室成功
    MtSdkStateJoinRoom = 1L << 2,
    // 会议加锁
    MtSdkStateJoinRoom_lock = 1L << 3,
    // 有人已经在会议中了
    MtSdkStateJoinRoom_Force = 1L << 4,
    // 会议满员
    MtSdkStateJoinRoom_Full = 1L << 5,

    // 创建本地发布流
    //MtSdkStateLocalStream = 1L << 3,
    // 本地发布流发布成功
    //MtSdkStatePublishLocalStream = 1L << 4,
    // 本地实例明确断开会议室连接
    MtSdkStateDisconnected = 1L << 6,
    // 离开会议
    MtSdkStateLeaveRoom = 1L << 7,
    // 结束会议
    MtSdkStateLeaveAndDeletedRoom = 1L << 8,
    
};

// 缓存 MtSdk 指针
@interface MtAdapterSDK : NSObject

@property (nonatomic, assign) void * sdkPtr;
// SDK的当前工作状态！
@property (nonatomic, assign) long long state;

@end

//@interface MtAdapterManager : NSObject
@interface MtAdapterManager : MtBaseSeriaQueue

// 获取共享单例
+ (instancetype)sharedInstance;

// 会议的MtSdk缓存对像
@property (nonatomic, strong) MtAdapterSDK * lastSdk;
// 会议的MtSdk缓存对像列表
@property (nonatomic, strong) NSMutableArray * cachedSdks;

@property (nonatomic, assign) NSUInteger seqid;
// 创建会议的MtSdk会话管理句柄
- (MtAdapterSDK *)createMtAdapterSDK;

// 释放会议的MtSdk会话管理句柄对象
- (void)destroyMtAdapterSDK;

#pragma mark - class MtSdk

// 获取会话ID
- (NSString *)GetServer;
// 设置会话ID，会话ID须与CC服务器认证后获得
- (void)SetServer:(NSString *)server;

// 获取会话ID
- (MtStUserInfo *)GetUserInfo;
// 设置会话ID，会话ID须与CC服务器认证后获得
- (void)SetUserInfo:(MtStUserInfo *)userInfo;

#pragma mark - class IMtSession
/// 设置会议服务器sessionToken
- (void)resetMeetSDKSessionToken:(NSString *)sessionToken completeHandler:(void (^)(MtCallState state))block;
/**
 * @ 获取会议服务器Token
 *   服务器获取Token，鉴权操作，后续操作会用到此TOKEN结果
 *   此Token对象内会保存，外部不需要知道此Token值
 *   后续操作如报错token无效，客户端须再次调用此接口刷新Token
 *   如此函数报错，可查看Code.h中的错误码描述
 *   设置连接超时时间，默认30秒
 */
- (void)GetTokenWithTimeOut:(NSInteger)timeOut
            completeHandler:(void (^)(MtCallState state))block;
// 清除 accesstoken
- (void)deletedInfoToken;
/**
 * @ 创建会议,默认连接超时时间30s
 *   inInfo.room._id = roomid; 如成功 函数内会给其赋值
 */
- (void)CreateRoomWithTimeOut:(NSInteger)timeOut
                     roomInfo:(MtStRoomInfo *)riInfo
              completeHandler:(void (^)(MtCallState state,
                                        MtStRoomInfo * outInfo))block;



/**
 获取房间信息

 @param timeOut 超时时间
 @param riInfo 房间id
 @param block 回调
 */
- (void)GetRoomInfoWithTimeOut:(NSInteger)timeOut
                      roomInfo:(MtStRoomInfo *)riInfo
               completeHandler:(void (^)(MtCallState state,
                                         MtRoomInfoDetails * outInfo))block;

/**
 获取房间状态

 @param timeOut 超时时间
 @param rStatus 房间状态
 @param block 回调
 */
- (void)GetRoomStatusWithTimeOut:(NSInteger)timeOut
                      roomStatus:(MtStRoomStatus *)rStatus
                 completeHandler:(void (^)(MtCallState state,
                                           MtStRoomStatus * outInfo))block;

/**
 获取参会人列表

 @param timeOut 超时时间
 @param roomId roomid
 @param block 回调
 */
- (void)GetParticipantsListWithTimeOut:(NSInteger)timeOut
                                roomID:(NSString *)roomId
                       completeHandler:(void (^)(MtCallState state,NSArray * participants))block;

/**
 获取房间中所有流信息

 @param timeOut 超时时间
 @param roomId roomid
 @param block 回调
 */
- (void)GetStreamInfoWithTimeOut:(NSInteger)timeOut
                                roomID:(NSString *)roomId
                       completeHandler:(void (^)(MtCallState state,NSArray * streams))block;
/**
 * @ 加入会议服务器，结构体中
 *   设置连接超时时间，默认30秒
 *   sRoomId:必填项
 *   sid:从CC获取的sid
 *   sUserName: 游客登录时填写的用户名
 *   sPassCode：会议角色相应的密码
 *   sRmToken:入会TOKEN,如成功 函数内会给其赋值
 *   sMcToken:会控TOKEN,如成功，函数内会给其赋值
 */
- (void)JoinRoomWithTimeOut:(NSInteger)timeOut
                   meetInfo:(MtStMeetInfo *)inInfo
            completeHandler:(void (^)(MtCallState state,
                                      MtStMeetInfo *outInfo))block;

/**
 * @ 退出会议,默认连接超时时间30s
 */
- (void)ExitRoomWithTimeOut:(NSInteger)timeOut meetInfo:(MtStParticipantInfo *)inInfo
            completeHandler:(void (^)(MtCallState state))block;

/**
 删除房间 结束会议

 @param timeOut 超时时间
 @param sRoomid roomid
 @param block 回调
 */
- (void)DeleteRoomWithTimeOut:(NSInteger)timeOut
                     roomInfo:(NSString *)sRoomid
              completeHandler:(void (^)(MtCallState state))block;
/**
 * @ 流相关操作,默认连接超时时间30s
 */
- (void)SetStreamWithTimeOut:(NSInteger)timeOut
                  streamInfo:(MtStOpStream *)inInfo
             completeHandler:(void (^)(MtCallState state,
                                       MtStOpStream * outInfo))block;


/**
 离开会议（踢人）

 @param timeOut 超时时间 默认30秒
 @param inInfo 会议信息（必传 roomid ParticipantID）
 @param block 回调
 */
- (void)LeaveRoomWithTimeOut:(NSInteger)timeOut
                   meetInfo:(MtStParticipantInfo *)inInfo
            completeHandler:(void (^)(MtCallState state))block;

/**
 会议室静音

 @param timeOut 超时时间 默认30秒
 @param rStatus 会议室状态
 @param block 回调
 */
- (void)muteConferenceAudioWithTimeOut:(NSInteger)timeOut
                            roomStatus:(MtStRoomStatus *)rStatus
                       completeHandler:(void (^)(MtCallState state))block;

/**
 设置轮巡时间

 @param timeOut  超时时间 默认30秒
 @param rStatus 会议室状态
 @param block 回调
 */
- (void)pollingTimeOfRoomViewWithTimeOut:(NSInteger)timeOut
                                     roomStatus:(MtStRoomStatus *)rStatus
                                completeHandler:(void (^)(MtCallState state))block;

/**
 视频布局

 @param timeOut 超时时间 默认30秒
 @param roomLayout 布局信息
 @param block 回调
 */
- (void)layoutOfRoomViewWithTimeOut:(NSInteger)timeOut
                         roomLayout:(MtStRoomLayout *)roomLayout
                    completeHandler:(void (^)(MtCallState state))block;
/**
 开始录制

 @param timeOut 超时时间 默认30秒
 @param recordingInfo 流id
 @param block 回调
 */
- (void)startRecordingWithTimeOut:(NSInteger)timeOut
                    recordingInfo:(MtStRecording *)recordingInfo
                  completeHandler:(void (^)(MtCallState state,MtStRecordingRes * recordingRes))block;
/**
 停止录制
 
 @param timeOut 超时时间 默认30秒
 @param recordingResInfo 流id
 @param block 回调
 */
- (void)stopRecordingWithTimeOut:(NSInteger)timeOut
       recordingResInfo:(MtStRecordingRes *)recordingResInfo
                 completeHandler:(void (^)(MtCallState state, MtStRecordingRes *recordingRes))block;

- (NSString *)GetsessionTokenFromMTSDK;

- (void)GetUserPermissionWithTimeOut:(NSInteger)timeOut
                     completeHandler:(void (^)(MtCallState state,MtStUserPermission *userPermission))block;

//获取录制id
- (void)FetchRecordingIDWithRecordingDetails:(NSMutableArray *)recordingDetails CompleteHandler:(void (^)(MtStRecordingRes *recordingRes))block;

/// 刷新Sessiontoken
- (void)RefreshSessionTokenWithTimeOut:(NSInteger)timeOut
                      roomInfo:(MtStRoomInfo *)riInfo
               completeHandler:(void (^)(MtCallState state,NSString * sessionToken))block;
/// 设置语音激励状态
- (void)setVoiceStatusWithTimeOut:(NSInteger)timeOut roomInfo:(MtStRoomInfo *)riInfo voiceStatus:(BOOL)isOn completeHandler:(void (^)(MtCallState state))block;
/// 获取语音激励状态
- (void)getVoiceStatusWithTimeOut:(NSInteger)timeOut roomInfo:(MtStRoomInfo *)riInfo completeHandler:(void (^)(MtCallState state,BOOL isOn))block;

/// 获取布局池所有布局信息
- (void)getVoiceActiveALLLayoutPoolInfoWithTimeOut:(NSInteger)timeOut roomInfo:(MtStRoomInfo *)riInfo completeHandler:(void (^)(MtCallState state,NSDictionary * allLayoutDict))block;


/// 设置插播服务器地址
- (BOOL)SetInterCutServer:(NSString *)server;

/// 共享插播 -- 拉流到会中  // "true" 激活音频或者视频，"false"禁用。
- (void)shareMediaPullStreamToConferenceWithRoomID:(NSString *)roomid RTMPURL:(NSString *)rtmpUrl Audio:(BOOL)audio Video:(BOOL)video completeHandler:(void (^)(MtCallState state))block;

/// 共享插播 -- 停止拉流到会中
- (void)shareMediaStopPullStreamToConferenceWithRoomID:(NSString *)roomid  completeHandler:(void (^)(MtCallState state))block;

///  共享插播 -- 开始播放
- (void)shareMediaStartPlayWithRoomID:(NSString *)roomid ShareMediaModel:(MtShareMediaModel *)shareModel success:(void (^)(NSString * RTMPURL))success failed:(void(^)(void))failed;

/// 共享插播 -- 暂停播放
- (void)shareMediaPausePlayWithRoomID:(NSString *)roomid ShareMediaModel:(MtShareMediaModel *)shareModel success:(void (^)(void))success failed:(void(^)(void))failed;

/// 共享插播 -- 恢复播放
- (void)shareMediaResumePlayWithRoomID:(NSString *)roomid ShareMediaModel:(MtShareMediaModel *)shareModel success:(void (^)(void))success failed:(void(^)(void))failed;

/// 共享插播 -- 停止播放
- (void)shareMediaStopPlayWithRoomID:(NSString *)roomid ShareMediaModel:(MtShareMediaModel *)shareModel success:(void (^)(void))success failed:(void(^)(void))failed;

/// 共享插播 -- 拖动播放进度
- (void)shareMediaSeekPlayWithRoomID:(NSString *)roomid ShareMediaModel:(MtShareMediaModel *)shareModel success:(void (^)(NSInteger realseektime))success failed:(void(^)(void))failed;
/// 共享插播 -- 查询播放列表
// recordurl ： 字符串，为all表明该场次多有插播件信息，具体某个recordurl时候，表明只获取该recordurl的信息
- (void)shareMediaQueryPlayListWithRoomID:(NSString *)roomid Recordurl:(NSString *)recordurl success:(void (^)(NSArray * infos))success failed:(void(^)(void))failed;

/// 共享插播 主持人身份转移
- (void)shareMediaChangeHostWithRoomID:(NSString *)roomid ToUid:(NSString *)uid Cid:(NSString *)cid success:(void (^)(void))success failed:(void(^)(void))failed;
/// 查询插播文件列表
- (void)queryShareMediaFilesWithReqModel:(MtSharingFileListReqModel *)shareingFileListReq
                                 success:(void(^)(NSArray *shareFilesArray))success
                                failed:(void(^)(void))failed;
///设置共享文档服务器地址
- (BOOL)SetShareDocumentServer:(NSString *)server;
//查询是否存在共享文档
- (void)queryShareDocumentStatusWithDict:(NSDictionary *)dict
                                 success:(void(^)(MtShareDocumentModel *shareDocumentModel))success
                                  failed:(void(^)(void))failed;
//修改文档共享批注权限
- (void)documentShareNoteAuthCallWithNoteAuthValue:(BOOL)authValue DocumentShareId:(NSString *)shareId MsgId:(NSString *)msgId TimeOut:(int)timeout success:(void(^)(void))success failed:(void(^)(int error))failed;


/// 结束文档共享
- (void)documentShareEndShareCallWithDocumentShareId:(NSString *)shareId MsgId:(NSString *)msgId Success:(void(^)(void))success Failed:(void(^)(int error))failed;

/// 专属会议室 -- 获取专属会议室服务器地址
- (BOOL)getCVapiSServer;
///设置专属会议室服务器地址
- (BOOL)SetCVapiSServer:(NSString *)server;
///专属会议室 -- 打开/关闭/重置 个人固定专属会议 行为（1关闭 2打开 3重置）
- (void)exchangeExclusiveConferenceStatusWithDict:(NSDictionary *)dict
                                          success:(void(^)(NSDictionary *resultDict))success
                                           failed:(void(^)(NSDictionary *failedDict))failed;
///查询 个人固定专属会议详情
- (void)queryExclusiveConferenceDetailWithDict:(NSDictionary*)dict Success:(void(^)(NSDictionary *resultDict))success failed:(void(^)(NSDictionary *failedDict))failed;
///锁定 个人固定专属会议
- (void)lockExclusiveConferenceWithDict:(NSDictionary*)dict Success:(void(^)(NSDictionary *resultDict))success failed:(void(^)(NSDictionary *failedDict))failed;

@end

