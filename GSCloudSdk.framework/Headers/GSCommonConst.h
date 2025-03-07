//
//  GSCommonConst.h
//  GSCloudSdk
//定义些公共的常量或宏，外部也可以使用
//  Created by net263 on 2022/3/8.
//
#import <Foundation/Foundation.h>
#import <Net263LogCollectSDK/Net263LogCollectSDK.h>

#ifndef GSCommonConst_h
#define GSCommonConst_h
/// 日志收集
#define YBLog(fmt, ...) CollectLog((@"" fmt), ##__VA_ARGS__)

typedef NS_ENUM(NSInteger, YBStatusCode)
{
    YBStatusCode_ServerReason_UNKNOW = 0,       //未知原因
    YBStatusCode_ServerReason_UserDelete = 1,   //用户被删除
    YBStatusCode_ServerReason_UserDisable = 2,  //用户被禁用≤
    YBStatusCode_ServerReason_LoginDelete = 3,  //登录信息删除
    YBStatusCode_ServerReason_LoginModify = 4,  //登录信息修改
    YBStatusCode_ServerReason_OtherdeviceLoad = 5,//账号在其它设备登录
    YBStatusCode_ServerReason_SidDisable = 6,//sid失效
   
    
    YBStatusCode_ResponseOk = 200,
    YBStatusCode_Unauthorized = 401,
    YBStatusCode_Forbidden = 403,
    YBStatusCode_NotFound = 404,
    YBStatusCode_BLACKLIST = 6048, //黑名单
    YBStatusCode_LiveNotStart = 201,//直播未开始
    YBStatusCode_LiveService_Error = 6022,  //sessionKey返回500
    YBStatusCode_LicenceFull_Error = 6000,  //并发已满
    YBStatusCode_LiveIDNotFound_Error = 1000,  //直播间id格式不正确
    YBStatusCode_LiveRoomNotFound_Error = 2014,  //直播间不存在
    
    YBStatusCode_SUCCESS = 999999,
    YBStatusCode_NetReqError = -263263263,  //网络请求及解析相关
    YBStatusCode_CCOpError = -263263264,    //CC注册或登陆失败
    YBStatusCode_LocationServerError = -263263265, //获取server列表出错
    YBStatusCode_LoginFailedDuringForceLogoutError = -263263266, //在登录的过程中强制退出导致登录失败
    YBStatusCode_LoginFailedJoinMettingError =  -263263267,//加入会议失败
    YBStatusCode_NoPlayAuthError = -263263268, //没有播放权限
    YBStatusCode_CodeError = -263263269, //鉴权失败
    YBStatusCode_WriteToFileError = -263263270, //保存文件失败
    YBStatusCode_CreateFileError = -263263271, //创建文件夹失败
    YBStatusCode_NotAuthorizedError = -263263272,   //没有主控权
    YBStatusCode_RoleError = -263263273,   //角色错误
    YBStatusCode_NotMediaControError = -263263274,   //没有音视频控制权限
    YBStatusCode_IntercutFileMaximumQuantity = -263263275,   //插播文件达到最大数量
    YBStatusCode_JoinMettingAfterLeave  = -263263276,   //加入会议失败，因为已经点击了离开
    YBStatusCode_ContractOverdue = -263263277,   //合同过了有效期
    YBStatusCode_LiveType_Error = -263263278,//直播类型不支持
    YBStatusCode_LiveRoomFull_Error = -263263279,  //存储空间已满
    YBStatusCode_NickNameTooLong_Error = -263263280,  //昵称超过字符限制
};

typedef NS_ENUM(NSInteger, YBLiveTimeDelay)
{
    YBLiveTimeDelay_RTS,
    YBLiveTimeDelay_FLV,
    YBLiveTimeDelay_HLS,
};

typedef NS_ENUM(NSInteger, YBUserRole)
{
    YBUserRole_UNKNOWN = 100,//未知角色
    YBUserRole_AUDIENCE = 5,  //观众
    YBUserRole_ANCHOR = 6,//主播
    YBUserRole_GUEST = 7,//嘉宾
    YBUserRole_ASSISTANT = 8,//助手
    YBUserRole_SpecialGUEST = 9,//指定嘉宾

};
typedef NS_ENUM(NSInteger, YBUserDevice)
{
    YBUserDevice_Unknown = -1,  //未知
    YBUserDevice_Phone = 0,  //手机
    YBUserDevice_Computer = 1,  //电脑
};
typedef NS_ENUM(NSInteger,YBGoodsLiveStatusChange){
    YBGoodsLiveStatusChange_UNKOWN = 0,    //
    YBGoodsLiveStatusChange_ADD = 1,       //添加商品
    YBGoodsLiveStatusChange_DELETE = 2,    //删除商品
    YBGoodsLiveStatusChange_ONSHELF = 3,   //商品上架
    YBGoodsLiveStatusChange_OFFSHELF = 4,  //商品下架
};

typedef NS_ENUM(NSInteger,YBIntercutFileStatus) {
    YBIntercutFileStatus_Download = 0,  // 下载中
    YBIntercutFileStatus_Ready = 1,     // 准备好
    YBIntercutFileStatus_Play = 2,      // 播放
    YBIntercutFileStatus_Pause = 3,     // 暂停
    YBIntercutFileStatus_Stop = 4,      // 停止
    YBIntercutFileStatus_Error = 5,     // 异常
    YBIntercutFileStatus_ResumePlay = 6,     // 恢复播放
};


typedef NS_ENUM (NSInteger,YBIntercutFilePlayType)  {
    YBIntercutFilePlayType_CYCLE = 0,   //单曲循环
    YBIntercutFilePlayType_NOCYCLE = 1, //不循环
};



typedef NS_ENUM (NSInteger,YBRoomAuthType)  {
    YBRoomAuthType_Audio = 1,   //会议室音频权限
    YBRoomAuthType_Video = 2, //会议室视频权限
};

typedef NS_ENUM (NSInteger,YBRoomVoipStatus)  {
    YBRoomVoipStatus_Open = 0, //打开连麦
    YBRoomVoipStatus_Close = 1,   //关闭连麦
    
};

typedef NS_ENUM (NSInteger,YBPaperStatus)  {
    YBPaperStatus_UNPUB = 0,    //未发布
    YBPaperStatus_PUBING = 1,   //发布中
    YBPaperStatus_END = 2,      //结束问卷
    YBPaperStatus_SUB = 3,      //提交
    YBPaperStatus_DELETE = 4,   //删除
};


typedef NS_ENUM (NSInteger,YBAnswerSheetStatus)  {
    YBAnswerSheetStatus_UNPUB = 0,    //未发布
    YBAnswerSheetStatus_PUBING = 1,   //发布中
    YBAnswerSheetStatus_END = 2,      //结束问卷
    YBAnswerSheetStatus_SUB = 3,      //提交
    YBAnswerSheetStatus_PubResult = 4,   //已发布答题结果
};

typedef NS_ENUM (NSInteger,YBLiveStreamType)  {
    YBLiveStreamType_YSLIVE = 0,    //云视流
    YBLiveStreamType_THIRDLIVE  = 1,   //第三方推流
    YBLiveStreamType_THIRDPULLLIVE = 2,      //第三方拉流
    YBLiveStreamType_PRETENDLIVE = 3,      //伪直播流
};

typedef NS_ENUM (NSInteger,YBVideoCropMode)  {
    YBVideoCropMode16_9 = 0,   //16：9
    YBVideoCropMode9_16 = 1,      //9：16
    YBVideoCropMode_All = 2,    //所有
};

#endif /* GSCommonConst_h */
