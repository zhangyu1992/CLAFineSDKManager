//
//  RTMEnum.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/6/25.
//

#ifndef RTMEnum_h
#define RTMEnum_h

//群组消息方向
typedef NS_ENUM(NSInteger, RTM_MessageDirectionType){
    RTM_GroupMessage_Send = 0,     //发送方
    RTM_GroupMessage_Receive = 1,  //接收方
};

//群组消息状态
typedef NS_ENUM(NSInteger, RTM_GroupMessageSendStatus){
    RTM_GroupMessage_Status_sending = 0,        //正在发送
    RTM_GroupMessage_Status_sendingSuccess = 1, //发送成功
    RTM_GroupMessage_Status_sendingFailed = 2,  //发送失败
};


//消息状态
typedef NS_ENUM(NSInteger, RTM_MessageStatus){
    RTM_MSG_STATUS_UNSEND = 0,      //未发送
    RTM_MSG_STATUS_SENDING = 1,     //正在发送
    RTM_MSG_STATUS_SENDFAIL = 2,    //发送失败
    RTM_MSG_STATUS_UNREADORSUCC = 3,//未读/发送成功
    RTM_MSG_STATUS_READED = 4,      //已读
    RTM_MSG_STATUS_WITHDRAW = 5,    //撤回
    RTM_MSG_STATUS_MISS = 6,        //错过的消息，当有实效的消息失效后需要设置为此值
    RTM_MSG_STATUS_AGREE = 7,       //同意的消息
    RTM_MSG_STATUS_REJECT = 8,      //拒绝的消息
};

//系统消息类型
typedef NS_ENUM(NSUInteger,RTM_SyetemMessageType){
    RTM_SyetemMessageType_Calling,         // 会议邀请
    RTM_SyetemMessageType_Schedule,        // 会议日程
    RTM_SyetemMessageType_MissCalling,     // 错过的呼叫
    RTM_SyetemMessageType_ConferenceStart, // 会议开始
    RTM_SyetemMessageType_ScheduleExchange,// 会议日程变更
    RTM_SyetemMessageType_ScheduleCancel,  // 会议取消
};

//群组成员类型
typedef NS_ENUM(NSUInteger,RTM_GroupUserType){
    RTM_GroupUserType_Member = 1,       // 普通成员
    RTM_GroupUserType_Administrator = 2,//管理员
    RTM_GroupUserType_Creator = 3,      //创建者
};

//发送的消息类型
typedef NS_ENUM (NSInteger,RTM_MessageSendType){
    RTM_MESSAGE_TYPE_UNKNOW = -1,
    RTM_MESSAGE_TYPE_NONE = 0,
    RTM_MESSAGE_TYPE_TEXT = 1,           //文本消息
    RTM_MESSAGE_TYPE_IMAGE = 2,          //图片消息
    RTM_MESSAGE_TYPE_VOICE = 3,          //语音消息
    RTM_MESSAGE_TYPE_GROUP_ACTION = 4,   //群内的操作消息
    RTM_MESSAGE_TYPE_VIDEO_CONF = 5,     //视频会议
    RTM_MESSAGE_TYPE_SAAS = 6,           //应用消息
    RTM_MESSAGE_TYPE_FIREND = 7,         //好友申请消息
    RTM_MESSAGE_TYPE_REFIREND = 8,       //好友应答消息
};

//邀请回复消息类型
typedef NS_ENUM(NSInteger,RTM_ReplyInviteType) {
    RTM_InviteReplyType_Agree,           //同意邀请
    RTM_InviteReplyType_Refuse_kBusy,    // 拒绝邀请——占线
    RTM_InviteReplyType_Refuse_kDeny,    // 拒绝挂断
};

// 是否接收消息
typedef NS_ENUM(NSUInteger,RTM_MessageReceiveSetType) {
    RTM_CCMessageReceiveSet_Normal,      // 接收提示
    RTM_CCMessageReceiveSet_NotPrompt,   // 接收不提示
    RTM_CCMessageReceiveSet_FORBIDDEN,   // 2:完全阻止
};

//群成员状态
typedef NS_ENUM(NSInteger,RTM_GroupUserStatus){
    RTM_GROUP_USER_STATUS_INVITING,      //邀请中
    RTM_GROUP_USER_STATUS_INVITE_AGREE,  //同意邀请
    RTM_GROUP_USER_STATUS_INVITE_REFUSE, //拒绝邀请
    RTM_GROUP_USER_STATUS_JOIN_PROPOSING,//申请中
    RTM_GROUP_USER_STATUS_JOIN_ASSENT,   //同意申请
    RTM_GROUP_USER_STATUS_JOIN_REJECT,   //拒绝申请
    RTM_GROUP_USER_STATUS_LEAVED,        //已离开
    RTM_GROUP_USER_STATUS_KICKED,        //已被踢
    RTM_GROUP_USER_STATUS_Cancel,
};

// 群权限类型
typedef NS_ENUM(NSUInteger,RTM_GroupAuthType){
    RTM_GroupAuthType_Unknow,
    RTM_GroupAuthType_Audio,   //音频权限
    RTM_GroupAuthType_Video,   //视频权限
    RTM_GroupAuthType_Share,   //共享权限
    RTM_GroupAuthType_Sort,    //排序权限
    RTM_GroupAuthType_Speak,   // 发言权限
    RTM_GroupAuthType_State,   //备用
    RTM_GroupAuthType_Note,     //批注权限
    RTM_GroupAuthType_Auth,    //锁定状态
};

//群成员权限
typedef NS_ENUM(NSUInteger,RTM_GroupUserAuthType){
    RTM_GroupUserAuthTypeUnknow,
    RTM_GroupUserAuthTypeAudio,    //音频权限
    RTM_GroupUserAuthTypeVideo,    //视频权限
    RTM_GroupUserAuthTypeShare,    //共享权限
    RTM_GroupUserAuthTypeSort,     //排序
    RTM_GroupUserAuthTypeSpeak,    //发言权限
    RTM_GroupUserAuthTypeStatus,   //备用
    RTM_GroupUserAuthTypeNote,     //批注权限
    RTM_GroupUserAuthTypeAvctl,     //音视频控制权限

};

//设备类型
typedef NS_ENUM(NSInteger,RT_DeviceType){
    RT_DeviceType_UNKNOW = 0,
    RT_DeviceType_IPHONE,        //苹果
    RT_DeviceType_ANDROID,       //安卓
    RT_DeviceType_WINDOWS,       //windows
    RT_DeviceType_WEB,           //web
    RT_DeviceType_HARDWAREDEVICE,//硬件设备
    RT_DeviceType_ANDROID_9Z,
    RT_DeviceType_ANDROID_X6,
    RT_DeviceType_ANDROID_TOUCH
};

//账号被提掉线原因
typedef NS_ENUM(NSUInteger,RTM_KickoutByServerReason) {
    RTM_KickoutByServerReason_UNKNOW = 0,       //未知原因
    RTM_KickoutByServerReason_UserDelete = 1,   //用户被删除
    RTM_KickoutByServerReason_UserDisable = 2,  //用户被禁用
    RTM_KickoutByServerReason_LoginDelete = 3,  //登录信息删除
    RTM_KickoutByServerReason_LoginModify = 4,  //登录信息修改
    RTM_KickoutByServerReason_OtherdeviceLoad = 5,//账号在其它设备登录
    RTM_KickoutByServerReason_SidDisable = 6,//sid失效
};

/// cc服务器连接状态
typedef NS_ENUM(NSUInteger,RTM_CCServerConnectionStatus){
    RTM_CCServerConnectionStatus_DisConnection,// 连接断开
    RTM_CCServerConnectionStatus_Connecting,// 连接中
    RTM_CCServerConnectionStatus_Connection,// 连接成功
};


#endif /* RTMEnum_h */
