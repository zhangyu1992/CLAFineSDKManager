//
//  MtBaseObjects.h
//  MtAdapter
//
//  Created by jinxiangkun on 2019/1/8.
//  Copyright © 2019年 jinxiangkun. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCObjectHeader.h"
#import "MtShareMediaModel.h"


@interface MtBaseObject : NSObject

- (void)setDefault;

@end

// struct Sip
@interface MtSipInfo : MtBaseObject

@property (nonatomic, strong) NSString * server;
@property (nonatomic, strong) NSString * user;
@property (nonatomic, strong) NSString * password;

@end

// struct Notifying
@interface MtNotifying : MtBaseObject

@property (nonatomic, assign) NSInteger streamChange;
@property (nonatomic, assign) NSInteger participantActivities;

@end

@class MtTranscodingVideo;

// struct Transcoding
@interface MtTranscoding : MtBaseObject

@property (nonatomic, assign) NSInteger audio;
@property (nonatomic, strong) MtTranscodingVideo * video;

@end

// struct TranscodingVideo
@interface MtTranscodingVideo : MtBaseObject

@property (nonatomic, assign) NSInteger format;
@property (nonatomic, assign) NSInteger frameRate;
@property (nonatomic, assign) NSInteger bitrate;
@property (nonatomic, assign) NSInteger keyFrameInterval;

@end

// struct  Permission
@interface MtPermission : MtBaseObject

@property (nonatomic, assign) NSInteger audio;
@property (nonatomic, assign) NSInteger video;

- (void)reset:(NSInteger)audio video:(NSInteger)video;

@end

// struct VideoFormat
@interface MtVideoFormat : MtBaseObject

//h264", "vp8", "h265", "vp9"
@property (nonatomic, strong) NSString * codec;
//For "h264" output only, CB", "B", "M", "H"
@property (nonatomic, strong) NSString * profile;

+ (MtVideoFormat *)defaultVideoFormat;

@end

// struct AudioFormat
@interface MtAudioFormat : MtBaseObject

// "opus", "pcmu", "pcma", "aac", "ac3", "nellymoser"
@property (nonatomic, strong) NSString * codec;
// "opus/48000/2", "isac/16000/2", "isac/32000/2", "g722/16000/1"
@property (nonatomic, assign) NSInteger sampleRate;
// E.g "opus/48000/2", "opus" is codec, 48000 is sampleRate, 2 is channelNum
@property (nonatomic, assign) NSInteger channelNum;

+ (MtAudioFormat *)defaultAudioFormat;

@end

// struct  BGColor
@interface MtRgbColor : MtBaseObject

@property (nonatomic, assign) NSInteger r;
@property (nonatomic, assign) NSInteger g;
@property (nonatomic, assign) NSInteger b;

+ (MtRgbColor *)black;
+ (MtRgbColor *)white;

+ (MtRgbColor *)defaultBGColor;

@end

// struct  Area
@interface MtAreaRect : MtBaseObject

@property (nonatomic, assign) NSInteger left;
@property (nonatomic, assign) NSInteger top;
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;

@end

// struct Territory
@interface MtTerritory : MtBaseObject

@property (nonatomic, strong) NSString * _id;
@property (nonatomic, strong) NSString * shape;
@property (nonatomic, strong) MtAreaRect * area;

@end

// struct Resolution 分辨率
@interface MtResolution : MtBaseObject

@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;

@end

// struct Parameters
@interface MtParameters : MtBaseObject

@property (nonatomic, strong) MtResolution * resolution;
//valid values in [6, 12, 15, 24, 30, 48, 60]
@property (nonatomic, assign) NSInteger frameRate;
//kbps
@property (nonatomic, assign) NSInteger bitrate;
//valid values in [100, 30, 5, 2, 1]
@property (nonatomic, assign) NSInteger keyFrameInterval;

+ (MtParameters *)defaultParameters;

@end


// struct Templates
@interface MtTemplates : MtBaseObject

//valid values ["fluid", "lecture", "void"].
@property (nonatomic, strong) NSString * base;
//std::vector<Region> custom;
//Required if base is "void", type object::Array or null,
//the format is introduced in MCU server guide.
@property (nonatomic, strong) NSMutableArray * customs;


@end

// struct VideoLayout
@interface MtVideoLayout : MtBaseObject

// "letterbox" or "crop".
@property (nonatomic, strong) NSString * fitPolicy;
// ...
@property (nonatomic, strong) MtTemplates * templates;


@end

// struct ViewVideo
@interface MtViewVideo : MtBaseObject

@property (nonatomic, strong) MtRgbColor * bgColor;
@property (nonatomic, strong) MtVideoFormat * format;
@property (nonatomic, strong) MtParameters * parameters;
@property (nonatomic, assign) NSInteger maxInput;
//note, what does it means?
@property (nonatomic, assign) double_t motionFactor;
@property (nonatomic, assign) NSInteger keepActiveInputPrimary;
@property (nonatomic, strong) MtVideoLayout * layout;


@end

// struct ViewAudio
@interface MtViewAudio : MtBaseObject

//静音检测
@property (nonatomic, assign) NSInteger vad;
@property (nonatomic, strong) MtAudioFormat * format;


@end

// struct View
@interface MtViewObject : MtBaseObject

@property (nonatomic, strong) NSString * lable;
@property (nonatomic, strong) MtViewAudio * audio;
//note: object(ViewVideo) | false
@property (nonatomic, strong) MtViewVideo * video;

+ (MtViewObject *)defaultView;

@end

// struct MediaIn
@interface MtMediaIn : MtBaseObject

//std::vector<AudioFormat> audio;
@property (nonatomic, strong) NSMutableArray * audios;
//std::vector<VideoFormat> video;
@property (nonatomic, strong) NSMutableArray * videos;

- (void)addAudioFormat:(MtAudioFormat *)aFormat;
- (void)addVideoFormat:(MtVideoFormat *)vFormat;

@end

@class MtMediaOutVideo;
@class MtMediaOutVideoParameters;

// struct  MediaOut
@interface MtMediaOut : MtBaseObject

//std::vector<AudioFormat> audio;
@property (nonatomic, strong) NSMutableArray * audios;
@property (nonatomic, strong) MtMediaOutVideo * video;

@end

// struct MediaOutVideo
@interface MtMediaOutVideo : MtBaseObject

//std::vector<VideoFormat> format;
@property (nonatomic, strong) NSMutableArray * formats;
@property (nonatomic, strong) MtMediaOutVideoParameters * parameters;

@end

// struct MediaOutVideoParameters
@interface MtMediaOutVideoParameters : MtBaseObject

//std::vector<int> framerate;
// Array of framerate.E.g. [5, 15, 24, 30, 48, 60]
@property (nonatomic, strong) NSMutableArray * frameRates;
//std::vector<int> bitrate;
// Array of bitrate.E.g. [500, 1000, ... ]
@property (nonatomic, strong) NSMutableArray * bitRates;
//std::vector<int> keyFrameInterval;
// Array of keyFrameInterval.E.g. [100, 30, 5, 2, 1]
@property (nonatomic, strong) NSMutableArray * keyFrameIntervals;

+ (MtMediaOutVideoParameters *)deafultMediaOutVideoParameters;

@end


// struct Action
@interface MtAction : MtBaseObject

// only in ["mute one", "mute all", "kick out", "delete room"]
@property (nonatomic, strong) NSString * act;

@end

//角色设置
// struct  Role
@interface MtRoleInfo : MtBaseObject

// role name
@property (nonatomic, strong) NSString * role;
//permit customer join conference as vistor
@property (nonatomic, strong) NSString * password;
@property (nonatomic, strong) MtPermission * publish;
@property (nonatomic, strong) MtPermission * subscirbe;
// std::vector<Action> actions;
@property (nonatomic, strong) NSMutableArray * actions;

- (id)initWithRole:(NSString *)roleName
          password:(NSString *)password
        permission:(const long)permission;

- (long)getPermission;
- (void)setPermission:(const long)permission;

//系统预定义的role
//static void initDefaultRole(std::vector<Role>& roles)
+ (NSMutableArray *)getInitDefaultRoleInfos;

@end

//会议房间信息
@interface MtRoomInfoDetails : MtBaseObject
@property (nonatomic, copy) NSString * roomId;
@property (nonatomic, copy) NSString * topic;
@property (nonatomic, copy) NSString * initiator;
@property (nonatomic, copy) NSString * cid;
@property (nonatomic, copy) NSString * compere;
@property (nonatomic, copy) NSString * groupId;
@property (nonatomic, copy) NSString * shortlink;
@property (nonatomic, copy) NSString * resolution;

@property (nonatomic, copy) NSString * sipHostURL;

/// 参会人入会密码
@property (nonatomic, copy) NSString * sipPassCode;
/// 主持人入会密码
@property (nonatomic, copy) NSString * sipHostPassCode;
/// 会议接入号
@property (nonatomic, copy) NSString * sipAccessNumber;
/// 自助会议是否允许外呼，0表示禁止，1表示允许CAS外呼，2表示允许CAS和DTMF外呼
@property (nonatomic, copy) NSString * unattendedDialout;

@property (nonatomic, copy) NSString * initiatorName;


@property (nonatomic, assign) int createdTime;
@property (nonatomic, assign) int scheduledTime;
@property (nonatomic, assign) int multiview;
@property (nonatomic, assign) int lock;
@property (nonatomic, assign) int recordPermission;
@property (nonatomic, assign) int recorded;
@property (nonatomic, assign) int partyLimit;
@property (nonatomic, assign) int partyMore;
@property (nonatomic, assign) int cycleType;
@property (nonatomic, assign) int duration;
@property (nonatomic, assign) int recordStatus;
@property (nonatomic, strong) NSMutableArray *stRecordserArray; //录制相关d数组
/// 语音激励开关
@property (nonatomic, assign) int voiceActivatedStatus;
@property (nonatomic, copy) NSString* hostshortlink;//主持人链接入会url
/// 共享功能权限 0表示没有共享权限， 1表示有
@property (nonatomic, assign) int mobileScreenSharing;

/*
 std::string roomId;
 std::string topic;
 std::string initiator;
 std::string cid;
 std::string compere;
 int createdTime;
 int scheduledTime;
 int duration;
 int cycleType;
 std::vector<std::string> nday;
 std::string resolution;
 int multiview;
 int partyLimit;
 int partyMore;
 std::string groupId;
 int lock;
 int recordPermission;
 int recorded;
 std::string shortlink;
 */

@end
// struct  Room
@interface MtRoomInfo : MtBaseObject
@property (nonatomic, strong) NSString * cid;
@property (nonatomic, strong) NSString * gid;

//when create room, _id is unknow
@property (nonatomic, strong) NSString * _id;
//when create room, name has specified
@property (nonatomic, strong) NSString * name;
//-1 means unlimited, default 16
@property (nonatomic, assign) NSInteger inputLimit;
//-1 means unlimited, default -1
@property (nonatomic, assign) NSInteger participantLimit;

//std::vector<Role> roles; //MtRoleInfo
@property (nonatomic, strong) NSMutableArray * roles;
//std::vector<View> views; //MtViewObject
@property (nonatomic, strong) NSMutableArray * views;

@property (nonatomic, strong) MtSipInfo * sip;
@property (nonatomic, strong) MtMediaIn * mediaIn;
@property (nonatomic, strong) MtMediaOut * mediaOut;
@property (nonatomic, strong) MtNotifying * notifying;
@property (nonatomic, strong) MtTranscoding * transcoding;

- (id)initWithName:(NSString *)name
  participantLimit:(NSInteger)participantLimit
        inputLimit:(NSInteger)inputLimit;

- (void)addRole:(MtRoleInfo *)role;
- (void)addView:(MtViewObject *)view;

@end

// struct StUserInfo
@interface MtStUserInfo : MtBaseObject

@property (nonatomic, strong) NSString * uid;
@property (nonatomic, strong) NSString * cid;
@property (nonatomic, strong) NSString * sessionId;

@end

// struct User
@interface MtStParticipantsUserInfo : MtBaseObject

@property (nonatomic, strong) NSString * userName;
@property (nonatomic, strong) NSString * userId;
@property (nonatomic, strong) NSString * participantId;

@end
// struct StreamInfo
@interface MtStStreamInfo: MtBaseObject

@property (nonatomic, strong) NSString * label;
@property (nonatomic, strong) NSString * activeInput;
@property (nonatomic, strong) NSString * type;
@property (nonatomic, strong) NSString * owner;
@property (nonatomic, strong) NSArray * inViews;
// layout
@end

// struct Stream
@interface MtStStream : MtBaseObject

@property (nonatomic, strong) NSString * _id;
@property (nonatomic, strong) NSString * type;
@property (nonatomic, strong) MtStStreamInfo * streamInfo;
@end


// struct StRmInfo
@interface MtStRoomInfo : MtBaseObject
@property (nonatomic, strong) NSString * name;
@property (nonatomic, strong) NSString * compere;// 主持人姓名
@property (nonatomic, strong) MtRoomInfo * room;

@end

@interface MtStUserPermission : MtBaseObject
@property (nonatomic, strong) NSString * resolution;// 1080p   720p   360p
@property (nonatomic, assign) int resolutionWidth;//
@property (nonatomic, assign) int resolutionHeight;//

@property (nonatomic, assign) int multiview;// 合屏路数
@property (nonatomic, assign) int partyLimit;// 作为创建者最大方数
@property (nonatomic, assign) int record;//  1 有录制权限，0 无
@property (nonatomic, assign) int status;// 0 账号状态正常

@end
// struct RoomStatus

@interface MtStRoomStatus : MtBaseObject

@property (nonatomic, strong) NSString * compere_uid;// 主持人id
@property (nonatomic, strong) NSString * compere_cid;// 主持人id

@property (nonatomic, strong) NSString * roomName;//
@property (nonatomic, strong) NSString * compereName;// 

@property (nonatomic, assign) int mixInterval; //发布流超过mix上限时，滚屏时轮巡的时间间隔 单位s
@property (nonatomic, strong) NSString * audio; //取值为  active 或 inactive 目前有 设置和取消静音
@property (nonatomic, strong) NSString * sRoomId; //必填项
@property (nonatomic, strong) NSString * intervalName; //必填项
@property (nonatomic, strong) NSMutableArray * mixInfos;// 布局数组
@end

@interface MtStRoomLayout : MtBaseObject

@property (nonatomic, assign) bool manual; //YES:手动布局 NO：自动布局
@property (nonatomic, strong) NSString * sRoomId; //必填项
@property (nonatomic, strong) NSString * name; //必填项
@property (nonatomic, assign) int layoutNumber; // 布局路数 0：自动 1：一路
@property (nonatomic, copy) NSString * layoutId; // 布局id 

@property (nonatomic, assign) int mixInterval; //发布流超过mix上限时，滚屏时轮巡的时间间隔 单位s
@property (nonatomic, strong) NSString * shape;

@property (nonatomic, copy) NSArray * curLayout;

@end
@interface MtStInfoAreaRect : MtBaseObject

@property (nonatomic, strong) NSString *  left;
@property (nonatomic, strong) NSString *  top;
@property (nonatomic, strong) NSString *  width;
@property (nonatomic, strong) NSString *  height;

@end

@interface MtStInfoRoomRegion : MtBaseObject
@property (nonatomic, strong) MtStInfoAreaRect * infoArea;
@property (nonatomic, strong) NSString * shape;
@property (nonatomic, strong) NSString * layoutID;
@property (nonatomic, strong) NSString * streamID;
@property (nonatomic, strong) NSString * userName;
@property (nonatomic, strong) NSString * userID;
@property (nonatomic, strong) NSString * userCID;
@property (nonatomic, strong) NSString * ptid;
@property (nonatomic, assign) BOOL fixed;// 是指定参会人

@end

@interface MtStInfoRoomLayout : MtBaseObject
@property (nonatomic, strong) MtStInfoRoomRegion * infoRegion;
@end


// struct StJoinRoom
@interface MtStJoinRoom : MtBaseObject

@property (nonatomic, strong) NSString * sid;
@property (nonatomic, strong) NSString * userName;
@property (nonatomic, strong) NSString * passCode;

@end

// struct StMtInfo
@interface MtStMeetInfo : MtBaseObject

@property (nonatomic, strong) NSString * sid; //登录后用户的sid
@property (nonatomic, strong) NSString * sUserName; //游客的姓名
@property (nonatomic, strong) NSString * sPassCode; //会议角色相应的密码 （目前，仅针对游客）
@property (nonatomic, assign) BOOL isforce;//表示是否强制入会。  
@property (nonatomic, strong) NSString * sRoomId; //必填项

@property (nonatomic, strong) NSString * sRmToken; //入会Token,加入ICS会议使用
@property (nonatomic, strong) NSString * sSessionToken; //会控Token,会控时使用
@property (nonatomic, strong) NSString * cid;
@property (nonatomic, strong) NSString * gid;
@property (nonatomic, strong) NSString * topic;
@property (nonatomic, assign) BOOL isLock; //会议加锁
@property (nonatomic, assign) BOOL isForce; //会议已经在里面了
@property (nonatomic, copy) NSString * label;// 定制需求添加字段


@end


// struct StOpStream
@interface MtOpStream : MtBaseObject

@property (nonatomic, strong) NSString * op;
@property (nonatomic, strong) NSString * view;
@property (nonatomic, strong) NSString * stream;
@property (nonatomic, strong) NSString * region;

@end

// struct OpStream
@interface MtStOpStream : MtBaseObject

@property (nonatomic, strong) NSString * roomid;
@property (nonatomic, strong) NSString * streamid;
@property (nonatomic, strong) NSString * mctoken;
@property (nonatomic, strong) MtOpStream * sos; // StOpStream name OpStream change ??

@end

// struct StMtParticipantInfo 参会人信息
@interface MtStParticipantInfo : MtBaseObject

@property (nonatomic, strong) NSString * sid; //登录后用户的sid
@property (nonatomic, strong) NSString * sUserName; //游客的姓名
@property (nonatomic, strong) NSString * sPassCode; //会议角色相应的密码 （目前，仅针对游客）
@property (nonatomic, strong) NSString * sRoomId; //必填项

@property (nonatomic, strong) NSString * sParticipantId; //必填项


@end

// struct MtStRoomStatus 录制信息
@interface MtStRecording : MtBaseObject

@property (nonatomic, strong) NSString * sRoomId; //房间id
@property (nonatomic, strong) NSString * video; //音频流的streamId
@property (nonatomic, strong) NSString * audio; //视频流的 streamId

@end

// struct MtStRoomStatus 录制信息
@interface MtStRecordingRes : MtBaseObject

@property (nonatomic, strong) NSString * sRoomId; //房间id
@property (nonatomic, strong) NSString * recordingId; //录制流的id
@property (nonatomic,copy) NSString *errCode; //错误码
@property (nonatomic,copy) NSString *errMsg; //错误信息

@end

@interface StRecorderModel :MtBaseObject

@property (nonatomic,copy) NSString *ids; 
@property (nonatomic,assign) long long start;
@property (nonatomic,assign) long long stop;

@end

@interface MtDocAnnotation : NSObject

@property (nonatomic,copy) NSString *cid;
@property (nonatomic,assign) NSInteger cmd;
@property (nonatomic,copy) NSString *content;
@property (nonatomic,copy) NSString *fileId;
@property (nonatomic,copy) NSString *id_;
@property (nonatomic,copy) NSString *page;
@property (nonatomic,copy) NSString *roomId;
@property (nonatomic,copy) NSString *shareId;
@property (nonatomic,assign) NSInteger ts;
@property (nonatomic,copy) NSString *uid;

@end


@interface MtDocShardData : NSObject

@property (nonatomic,copy) NSString *annotation;
@property (nonatomic,strong) NSMutableArray *annotations;
@property (nonatomic,copy) NSString *cid;
@property (nonatomic,copy) NSString *fileId;
@property (nonatomic,copy) NSString *fileTitle;
@property (nonatomic,copy) NSString *host;
@property (nonatomic,copy) NSString *page;
@property (nonatomic,copy) NSString *pageTurning;
@property (nonatomic,copy) NSString *roomId;
@property (nonatomic,copy) NSString *shareId;
@property (nonatomic,assign) NSInteger status;
@property (nonatomic,copy) NSString *ts;
@property (nonatomic,copy) NSString *uid;
@property (nonatomic,copy) NSString *userName;
@property (nonatomic,copy) NSString *viewUrl;
@property (nonatomic,copy) NSString *zoomSize;


@end

@interface MtShareDocumentModel :MtBaseObject

@property (nonatomic,strong) NSDictionary *allInfoDictionary;
@property (nonatomic,strong) MtDocShardData *data;
@property (nonatomic,copy) NSString *host;
@property (nonatomic,copy) NSString *logKey;
@property (nonatomic,copy) NSString *message;
@property (nonatomic,assign) NSInteger responseTime;
@property (nonatomic,assign) NSInteger status;

@end

@interface MtSharingFileListReqModel :MtBaseObject
@property (nonatomic,copy) NSString *appName;
@property (nonatomic,copy) NSString *createEndTime;
@property (nonatomic,copy) NSString *createStartTime;
@property (nonatomic,copy) NSString *fileName;

@property (nonatomic,assign) NSInteger limit;
@property (nonatomic,copy) NSString *liveId;
@property (nonatomic,assign) NSInteger offset;
@property (nonatomic,copy) NSString *orderSource;
@property (nonatomic,copy) NSString *orderStatus;
@property (nonatomic,copy) NSString *roomId;

@property (nonatomic,assign) NSInteger source;
@property (nonatomic,copy) NSArray *status;

@property (nonatomic,assign) NSInteger type;
@property (nonatomic,copy) NSString *uploaderName;

@end
@interface MtSharingFileModel :MtBaseObject
@property (nonatomic,copy) NSString *appName;
@property (nonatomic,copy) NSString *cid;
@property (nonatomic,copy) NSString *ct;
@property (nonatomic,assign) NSInteger del;
@property (nonatomic,assign) NSInteger duration;
@property (nonatomic,copy) NSString *fileId;
@property (nonatomic,copy) NSString *fileSuffix;
@property (nonatomic,copy) NSString *filename;
@property (nonatomic,assign) NSInteger FileModelId;//id
@property (nonatomic,copy) NSString *refId;
@property (nonatomic,copy) NSString *roomId;

@property (nonatomic,assign) NSInteger size;
@property (nonatomic,assign) NSInteger source;
@property (nonatomic,copy) NSString *srcFileId;
@property (nonatomic,assign) NSInteger status;
@property (nonatomic,copy) NSString *transFileId;
@property (nonatomic,assign) NSInteger type;

@property (nonatomic,copy) NSString *uid;
@property (nonatomic,copy) NSString *uploaderName;
@property (nonatomic,copy) NSString *ut;


@property (nonatomic,copy) NSString *downLoadUrl;



@end
