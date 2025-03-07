//
//  RTCFormat.h
//  FineSdk
//
//  Created by 张俞 on 2021/6/28.
//

#ifndef RTCFormat_h
#define RTCFormat_h

/// 摄像头方向
typedef enum : NSUInteger {
    RTCCameraPosition_Front,
    RTCCameraPosition_Back,
} RTCCameraPosition;

/// 推流类型
typedef enum : NSUInteger {
    /// 摄像头
    RTCPublishStreamType_Camera,
    /// 共享
    RTCPublishStreamType_Share,
} RTCPublishStreamType;

/// 流轨道类型
typedef enum : NSUInteger {
    /// 音频轨道 + 视频轨道
    RTCStreamTrackType_All,
    /// 音频轨道
    RTCStreamTrackType_Audio,
    /// 视频轨道
    RTCStreamTrackType_Video,
} RTCStreamTrackType;

/// 默认添加到混流中
typedef enum : NSUInteger {
    RTCDefaultAddMixStreamYES,
    RTCDefaultAddMixStreamNO,
} RTCDefaultAddMixStream;

/// 订阅流类型
typedef enum : NSUInteger {
    /// 混流
    RTCSubscribeStreamType_Mix,
    /// 直播流
    RTCSubscribeStreamType_Live,
    /// 共享流
    RTCSubscribeStreamType_Share,
    /// 单路流
    RTCSubscribeStreamType_Single,
} RTCSubscribeStreamType;

/// 共享流类型
typedef enum : NSUInteger {
    /// 屏幕共享
    RTCShareStreamType_Screen,
    /// 插播共享
    RTCShareStreamType_Media,

} RTCShareStreamType;

/// 分辨率优先 帧率优先
typedef NS_ENUM(NSInteger, RTCDegradationPreference) {
    ///流畅优先
    RTCDegradationPreference_MAINTAIN_FRAMERATE = 1,
    /// 质量优先
    RTCDegradationPreference_MAINTAIN_RESOLUTION = 2,
    /// 自动
    RTCDegradationPreference_BALANCED = 3,
};

/// 推流分辨率
typedef enum : NSUInteger {
    RTCPublishResolution_1080P,
    RTCPublishResolution_720P,
    RTCPublishResolution_540P,
    RTCPublishResolution_360P,
    RTCPublishResolution_180P,
} RTCCameraPublishResolution;

/// 订阅分辨率
typedef enum : NSUInteger {
    RTCSubscribeResolution_Auto,
    RTCSubscribeResolution_1080P,
    RTCSubscribeResolution_720P,
    RTCSubscribeResolution_540P,
    RTCSubscribeResolution_360P,
    RTCSubscribeResolution_180P,
} RTCSubscribeResolution;

/// 订阅比例
typedef enum : NSUInteger {
    RTCSubscribeVideoRatio16_9 = 0,
    RTCSubscribeVideoRatio9_16 = 1,
} RTCSubscribeVideoRatio;

/// 轮巡时间
typedef enum : NSUInteger {
    RTCRoomViewInterval_30S,
    RTCRoomViewInterval_60S,
    RTCRoomViewInterval_90S,
} RTCRoomViewInterval;

/// 角色
typedef enum : NSUInteger {
    /// 参会人
    RTCRoleParticipants = 1,
    /// 管理员
    RTCRoleAdministrator = 2,
    /// 主持人
    RTCRoleCompere = 3,
} RTCRoleType;

/// 设备类型
typedef enum : NSUInteger {
    RTCDevicesUnknow,
    RTCDevicesAndroid,
    RTCDevicesIOS,
    RTCDevicesWEB,
    RTCDevicesWindows,
    RTCDevicesMACOS,
    RTCDevicesAndroid_touch,
    RTCDevicesAndroid_box,
    RTCDevicesSIP,
    RTCDevicesMIC,// 连麦
    RTCDevicesPexip,// pexip 视频会议
} RTCDevicesType;

/// 申请类型
typedef enum : NSUInteger {
    /// 参会人没有申请
    RTCParticipantApplyNone,
    /// 音频权限申请
    RTCParticipantApplyAudio,
    /// 共享权限申请
    RTCParticipantApplyShare,
} RTCParticipantApplyType;


/// 音频状态
typedef enum : NSUInteger {
    ///未知
    RTCAudioUnKown,
    /// 正常
    RTCAudioNormal,
    /// 静音
    RTCAudioMute,
} RTCAudioStatus;

/// 视频状态
typedef enum : NSUInteger {
    /// 未知
    RTCVideoUnKown,
    /// 正常
    RTCVideoNormal,
    /// 关闭视频
    RTCVideoMute,
} RTCVideoStatus;

/// 呼叫状态
typedef enum : NSUInteger {
    /// 未知
    RTCParticipantsCallingStatus_UnKnown = 404,
    ///邀请中
    RTCParticipantsCallingStatus_Inviting = 0,
    ///同意邀请
    RTCParticipantsCallingStatus_AgreeInvite = 1,
    ///拒绝邀请
    RTCParticipantsCallingStatus_RefuseInvite = 2,
    ///申请中
    RTCParticipantsCallingStatus_ApplyJoinRoom = 3,
    ///同意申请
    RTCParticipantsCallingStatus_AgreeApplyJoin = 4,
    ///拒绝申请
    RTCParticipantsCallingStatus_RefuseApplyJoin = 5,
    ///已离开
    RTCParticipantsCallingStatus_Leave = 6,
    ///已被踢
    RTCParticipantsCallingStatus_Kicked = 7,
    ///取消邀请
    RTCParticipantsCallingStatus_CancelInvite = 8,

} RTCParticipantsCallingStatus;

     //已被踢

/// 参会人权限类型
typedef enum : NSUInteger {
    /// 未知
    RTCParticipantAuth_Unknown,
    /// 音频权限
    RTCParticipantAuth_Audio,
    /// 视频权限
    RTCParticipantAuth_Video,
    /// 主控权限
    RTCParticipantAuth_Avctl,
    /// 共享权限
    RTCParticipantAuth_Share,
    /// 置顶
    RTCParticipantAuth_Sort,
} RTCParticipantAuthType;

/// 会议室权限类型
typedef enum : NSUInteger {
    /// 未知
    RTCRoomAuthType_Unknown,
    /// 会议室音频权限
    RTCRoomAuthType_Audio,
    /// 会议室视频权限
    RTCRoomAuthType_Video,
    /// 会议室共享权限
    RTCRoomAuthType_Share,
    /// 会议室锁定
    RTCRoomAuthType_Lock,
    /// 聊天室发言权限
    RTCRoomAuthType_Speak,
    /// 共享批注权限
    RTCRoomAuthType_Note,
} RTCRoomAuthType;

/// 主持人改变类型
typedef enum : NSUInteger {
    /// 转移主持人身份
    RTCHostChangedType_HostChanged,
    /// 主持人收回身份
    RTCHostChangedType_HostRevoke,
    /// 用hostcode入会获取身份
    RTCHostChangedType_HostCode,
} RTCHostChangedType;

/// 邀请结果
typedef enum : NSUInteger {
    /// 同意邀请
    RTCInviteResultAgree,
    /// 拒绝邀请
    RTCInviteResultRefuse,
    /// 忙碌
    RTCInviteResultBusy,
} RTCInviteResult;

//聊天室消息状态
typedef enum : NSUInteger {
    ///正在发送
    RTCMessageStatus_sending = 0,
    ///发送成功
    RTCMessageStatus_sendingSuccess = 1,
    ///发送失败
    RTCMessageStatus_sendingFailed = 2,
    /// 接收到的消息
    RTCMessageStatus_received = 3,

} RTCMessageStatus;

/// 被踢掉线原因
typedef enum : NSUInteger {
    /// 被服务器踢掉
    RTCParticipantKickedByServer,
    /// 被自己踢掉
    RTCParticipantKickedBySelf,
    /// 被主持人踢掉
    RTCParticipantKickedByHost,
} RTCParticipantKickedReason;

/// RTCSocket连接状态
typedef enum : NSUInteger {
    /// 已连接
    RTCSocketConnectionStatus_Connected,
    /// 正在重连
    RTCSocketConnectionStatus_ReConnected,
    /// 连接断开
    RTCSocketConnectionStatus_DisConnected,
} RTCSocketConnectionStatus;

/// ICE连接状态
typedef enum : NSUInteger {
    RTCICEConnectionNew = 0,
    RTCICEConnectionChecking,
    RTCICEConnectionConnected,
    RTCICEConnectionCompleted,
    RTCICEConnectionFailed,
    RTCICEConnectionDisconnected,
    RTCICEConnectionClosed,
    RTCICEConnectionMax,
    RTCICEConnectionUnKnow,
} RTCICEConnectionStatus;

/// 布局类型
typedef enum : NSUInteger {
    /// 等分屏二路
    RTCLayoutEqual_Two = 2,
    /// 等分屏三路
    RTCLayoutEqual_Three = 3,
    /// 等分屏四路
    RTCLayoutEqual_Four = 4,
    /// 等分屏九路
    RTCLayoutEqual_Nine = 7,
    /// 等分屏十六路
    RTCLayoutEqual_Sixteen = 9,
    /// 焦点一路
    RTCLayoutFocus_One = 1,
    /// 焦点六路
    RTCLayoutFocus_Six = 5,
    /// 焦点八路
    RTCLayoutFocus_Eight = 6,
    /// 焦点十路
    RTCLayoutFocus_Ten = 10,
    /// 焦点十三路
    RTCLayoutFocus_Thirteen = 8,
    /// 焦点十六路
    RTCLayoutFocus_Sixteen = 11,
} RTCLayoutType;/// 混流布局类型
#endif /* RTCFormat_h */
