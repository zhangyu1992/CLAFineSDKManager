//
//  GSLogCollectCode.h
//  GSCloudSdk
//
//  Created by 张俞 on 2023/8/4.
//

#ifndef GSLogCollectCode_h
#define GSLogCollectCode_h


// 日志收集通用code
#define CLA_CollectLog(code,message) [[Net263LogCollect shareInstance] collectLogWithCode:code Message:message]

/// 控制台日志信息
#define LCCommonCode_ConsoleLogs @"1000"

/// GSCloudSdk接口请求报错
#define LCNetDataReqError @"1001"

/// app 启动次数
#define LCCommonCode_LaunchAPP @"1002"


/// 离开直播间（用于用户统计）
#define LCCommonCode_LeaveLive @"1011"

/// 加入直播间 （用于用户统计）
#define LCCommonCode_JoinLive @"1012"



// 用户点击事件
/// 开始直播
#define LCOperationCode_StartLive @"2000"
/// 添加、上传文档
#define LCOperationCode_UpLoadDoc @"2001"
/// 发布文档
#define LCOperationCode_PublishDoc @"2002"
/// 添加白板
#define LCOperationCode_AddWhiteBoard @"2003"

/// 关联文档、取消关联
#define LCOperationCode_RelateDoc @"2004"
/// 删除文档
#define LCOperationCode_DeleteDoc @"2005"

/// 大小窗口切换（Pad端）
#define LCOperationCode_ChangeWindow @"2006"

/// 关闭连麦次数
#define LCOperationCode_CloseLianMic @"2007"
/// 启用连麦次数
#define LCOperationCode_OpenLianMic @"2008"


/// 开始录制
#define LCOperationCode_StartRecord @"2009"
/// 开始推流本地视频
#define LCOperationCode_PublishLocalStream @"2010"
/// 开始订阅直播流
#define LCOperationCode_SubscribeLiveStream @"2011"
/// 开关摄像头
#define LCOperationCode_SwitchCamera @"2012"
/// 开关音频
#define LCOperationCode_SwitchMic @"2013"
/// 改变摄像头方向
#define LCOperationCode_ChangedCameraFront @"2014"
/// 转移主播身份
#define LCOperationCode_TransferHost @"2015"
/// 转移主控权
#define LCOperationCode_TransferMainControl @"2016"
/// 转移演示权
#define LCOperationCode_TransferShareAuthor @"2017"
/// 修改昵称
#define LCOperationCode_ChangedNickname @"2018"
/// 开始签到
#define LCOperationCode_StartSignin @"2019"
/// 新增公告
#define LCOperationCode_NewNotice @"2020"
/// 开始计时
#define LCOperationCode_StartTimer @"2021"
/// 开关音频主控模式
#define LCOperationCode_SwitchAudioControl @"2022"
/// 开关视频主控模式
#define LCOperationCode_SwitchVideoControl @"2023"
/// 开关本地视频镜像
#define LCOperationCode_SwitchMirror @"2024"
/// 本地视频分辨率切换
#define LCOperationCode_ChangedResolution @"2025"
/// 开关聊天禁言
#define LCOperationCode_SwitchChatEnable @"2026"
/// 开关嘉宾是否显示观众列表
#define LCOperationCode_SwitchShowAudienceList @"2027"

/// 观众窗口跟随切换
#define LCOperationCode_SwitchAudienceWindowChange @"2028"

/// 点击分享
#define LCOperationCode_ClickShare @"2029"

/// 点击在线客服
#define LCOperationCode_ClickOnlineCervices @"2030"
/// 点击报告故障
#define LCOperationCode_ClickUpReport @"2031"


/// 连接状态code
/// ccp/user/v1/heartbeat
#define LCConnectStatusCode_CCPHeartbeat @"3000"

/// CC socket
#define LCConnectStatusCode_CCSocket @"3001"

/// OWT socket
#define LCConnectStatusCode_OWTSocket @"3002"

/// 本地音视频推流ICE
#define LCConnectStatusCode_PublishICE @"3003"

/// 订阅直播流ICE
#define LCConnectStatusCode_SubscribeICE @"3004"



#endif /* GSLogCollectCode_h */
