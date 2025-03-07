//
//  CCModelBase.h
//  adapter
//
//  Created by jinxiangkun on 17/3/23.
//  Copyright © 2017年 zsx. All rights reserved.
//

#ifndef _CC_CCDataModel_H_
#define _CC_CCDataModel_H_

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCServiceTypes.h"

// 客户端数据结构
// 263CC数据模型.doc

// 基础数据类型
@interface CCNameSpace(CCModelBase) : NSObject

@end

///////////////////////////////////////////////
// CC常量数据类型

// struct st_dev_info
@interface CCNameSpace(CCDeviceInfo) : CCNameSpace(CCModelBase)

@property (strong) NSString * tag; //序号
@property (strong) NSString * cmd; //命令字
@property (strong) NSString * name; //登录名
@property (strong) NSString * os; //操作系统信息
@property (strong) NSString * dev; //设备唯一标识
@property (strong) NSString * devt; //设备类型
@property (strong) NSString * version; //设备版本号

@end

//认证方式，
//1：密码；2短信验证码，3：二维码
enum CCAuthType //认证方式
{
    CC_AUTH_PASSWORD = 1, //密码
    CC_AUTH_SMSCODE = 2, //短信验证码
    CC_AUTH_QRCODE = 3, //二维码
};
typedef enum CCAuthType CCAuthType;

//状态，0：注销；1：登录；
enum CCLoginState //登录状态
{
    CC_LOGIN_STATE_OUT = 0, //注销
    CC_LOGIN_STATE_IN = 1, //登录
};
typedef enum CCLoginState CCLoginState;

// 出席状态，
//0：离线，1：隐身，2：离开；3：忙碌；4：在线；5：HomeOut
enum CCUserPresence //出席状态
{
    CC_PRESENCE_UNKNOWN = -1, //未知
    CC_PRESENCE_UNAVAILABLE = 0, //离线
    CC_PRESENCE_INVISIBLE = 1, //隐身
    CC_PRESENCE_AWAY = 2, //离开
    CC_PRESENCE_BUSY = 3, //忙碌
    CC_PRESENCE_AVAILABLE = 4, //在线
    CC_PRESENCE_HOMEOUT = 5, //HomeOut 切后台
};
typedef enum CCUserPresence CCUserPresence;

enum CCConnectState //连接状态
{
    CC_STATE_UNKNOWN       = 0LL,
    CC_STATE_CONNECTING    = 1LL << 1, // 正在连接
    CC_STATE_CONNECTED     = 1LL << 2, // 已经连接
    CC_STATE_DISCONNECTING = 1LL << 3, // 正在断开连接
    CC_STATE_DISCONNECED   = 1LL << 4, // 断开连接
};
typedef enum CCConnectState CCConnectState;


// 用户登录信息表
@interface CCNameSpace(CCModelAuthInfo) : CCNameSpace(CCModelBase)

@property (strong) NSString * name; //登录名
@property (strong) NSString * password; //登录密码
@property (assign) NSInteger authtype; //认证方式 CCAuthType
@property (assign) NSInteger status; //登录状态 CCLoginState
@property (strong) NSString * cid; //客户编号，登录成功后返回
@property (strong) NSString * uid; //用户编号，登录成功后返回
@property (strong) NSString * authsid; //认证会话编号(auth)
@property (assign) NSInteger presence; //出席状态 CCUserPresence
@property (strong) NSString * version; //登录版本信息
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒
@property (strong) NSString * accessToken; //认证会话编号(auth)

// 更新当前的登录信息表
- (void)updateAuthInfo:(CCNameSpace(CCModelAuthInfo) *)info;

@end
// 用户注册 信息
@interface CCNameSpace(CCModelAccountRegisterModel) : CCNameSpace(CCModelBase)

@property (strong) NSString * name; //登录名
@property (strong) NSString * passwd; //登录密码
@property (strong) NSString *  user; //账号
@property (strong) NSString * cmd; //
@property (strong) NSString * email; //
@property (strong) NSString * tel; //
@property (strong) NSString * phone; //
@property (strong) NSString * fax; //

@end
///////////////////////////////////////////////

//同步标识，0：未同步；1：已同步
enum CCSyncState //更新状态
{
    CC_SYNC_NOUPDATE = 0, //未更新
    //CC_SYNC_UPDATEING = 1,//正在更新
    CC_SYNC_UPDATEDONE = 1 //已经更新
};
typedef enum CCSyncState CCSyncState;

//更新状态：0：未更新；1：正在更新
enum CCUpdateState //更新状态
{
    CC_UPDATE_NOUPDATE = 0, //未更新
    CC_UPDATE_UPDATEING = 1,//正在更新
    CC_UPDATE_UPDATEDONE = 2 //已经更新
};
typedef enum CCUpdateState CCUpdateState;


///////////////////////////////////////////////

enum CCModelNodeType
{
    CCBaseTypeUnknow,
    CCBaseTypeUser, //用户类型
    CCBaseTypeDepart, //部门类型
    CCBaseTypeCustomer, //客户类型
    CCBaseTypeDepartUser, //部门用户类型
};
typedef enum CCModelNodeType CCModelNodeType;

// struct 部门节点类型抽像
//@interface CCNameSpace(CCModelNodeInfo) : NSObject
@interface CCNameSpace(CCModelNodeInfo) : CCNameSpace(CCModelBase)

//@property (assign) CCModelNodeType type; //节点类型
//@property (strong) NSString * id_; //通用id，uid or did
@property (strong) NSString * cid; //客户id
@property (strong) NSString * pdid; //部门的上级id
@property (strong) NSString * name; //部门名字，必填
@property (strong) NSString * pinyin; //拼音
@property (strong) NSString * pyhead; //拼音头
@property (assign) NSInteger  sort; //同级部门排序值
@property (strong) NSString * path; //部门路径，如：/1/2/3/
@property (assign) NSInteger  level; //层级，依次类推
@property (strong) NSMutableArray * parents; //部门节点上级
@property (strong) NSMutableDictionary * parentsMap; //部门节点上级
@property (strong) NSMutableArray * childrens; //部门节点子级
@property (strong) NSMutableDictionary * childrensMap; //部门节点子级

//通用id，uid or did
- (NSString *)id_;
// 节点类型
- (NSInteger)nodeType;
// 同级部门排序值
- (NSInteger)getSort;
// 获得路径的数组信息
- (NSMutableArray *)getAllPathID;
// 获得第一项上级节点
- (CCNameSpace(CCModelNodeInfo) *)getParentNode;

// 将其他节点信息拷贝至当前节点
- (void)updateNodeInfo:(CCNameSpace(CCModelNodeInfo) *)other;
// 添加上级信息节点，如果存在则更新
- (void)addParentNode:(CCNameSpace(CCModelNodeInfo) *)node
                  key:(NSString *)nodeKey;
// 添加子一级信息节点，如果存在则更新
- (void)addChildrenNode:(CCNameSpace(CCModelNodeInfo) *)node
                    key:(NSString *)nodeKey;

@end

//////////////////////////////////////////////////

//客户端类型，
//1：人；2：智能机器人；3：安卓视频盒子
enum CCClientType //客户端类型
{
    CC_CLIENT_UNKNOWN = 0, //未知
    CC_CLIENT_NORMAL = 1, //普通客户端
    CC_CLIENT_SMARTROBOT = 2, //智能机器人
    CC_CLIENT_ANDROIDBOX = 3 //安卓视频盒子
};
typedef enum CCClientType CCClientType;
@interface CCModelUserInfoPermission : CCNameSpace(CCModelBase)
@property (nonatomic, strong) NSString * resolution;// 1080p   720p   360p
@property (nonatomic, assign) int resolutionWidth;//
@property (nonatomic, assign) int resolutionHeight;//

@property (nonatomic, assign) int multiview;// 合屏路数
@property (nonatomic, assign) int partyLimit;// 作为创建者最大方数
@property (nonatomic, assign) int record;//  1 有录制权限，0 无
@property (nonatomic, assign) int status;// 0 账号状态正常

@end

// 用户信息表
// struct  st_user
//@interface CCNameSpace(CCModelUserInfo) : CCNameSpace(CCModelBase)
@interface CCNameSpace(CCModelUserInfo) : CCNameSpace(CCModelNodeInfo)

@property (strong) NSString * uid; //用户ID
//@property (strong) NSString * cid; //客户ID
@property (strong) NSString * name; //用户名字
//@property (strong) NSString * pinyin; //拼音
//@property (strong) NSString * pyhead; //拼音头
@property (strong) NSString * mobile; //手机
@property (strong) NSString * mail; //邮箱
@property (strong) NSString * tel; //固话
@property (strong) NSString * fax; //传真
@property (strong) NSString * position; //职位
@property (strong) NSString * signname; //签名
@property (strong) NSString * portraiturl; //头像URL
@property (assign) NSInteger type; //客户端类型 CCClientType
//@property (assign) NSInteger sort; //排序值，默认是0
@property (assign) NSInteger siteid; //站点编号，默认是0
@property (strong) NSString * status; // 用户状态
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒
@property (nonatomic,copy) NSString *selectPhoneNumber; //选择要呼叫的电话号码
@property (nonatomic,strong) NSMutableArray<NSString*> *subordinateDpartments;//所在部门

@end

// 用户信息扩展表
@interface CCNameSpace(CCModelUserInfoExtend) : CCNameSpace(CCModelBase)

@property (strong) NSString * cid; //客户ID
@property (strong) NSString * uid; //用户ID
@property (strong) NSString * nick; //用户昵称
@property (strong) NSString * jobnumber; //用户工号
@property (strong) NSString * address; //联系人地址
@property (strong) NSString * company; //公司名称
@property (strong) NSString * companyaddress; //公司地址
@property (strong) NSString * remarks; //备注信息
@property (strong) NSString * extend; //扩展信息，预留
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒

@end


// 客户表, 顾客表
// struct  st_customer
//@interface CCNameSpace(CCModelCustomerInfo) : CCNameSpace(CCModelBase)
@interface CCNameSpace(CCModelCustomerInfo) : CCNameSpace(CCModelNodeInfo)

//@property (strong) NSString * cid; //客户ID
//@property (strong) NSString * name; //客户名字
//@property (strong) NSString * pinyin; //拼音
//@property (strong) NSString * pyhead; //拼音头
//@property (strong) NSString * path; //客户路径
//@property (assign) NSInteger sort; //同级部门排序值
@property (assign) NSInteger usernum; //用户数量
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒

@end


// 部门表信息
// struct  st_dept
//@interface CCNameSpace(CCModelDepartmentInfo) : CCNameSpace(CCModelBase)
@interface CCNameSpace(CCModelDepartmentInfo) : CCNameSpace(CCModelNodeInfo)

@property (strong) NSString * did; //部门ID
//@property (strong) NSString * name; //部门名字，必填
//@property (strong) NSString * pinyin; //拼音
//@property (strong) NSString * pyhead; //拼音头
//@property (strong) NSString * pdid; //父部门ID
//@property (strong) NSString * cid; //客户ID
// level 层级，0：表示根，1：表示一级，依次类推
//@property (assign) NSInteger level; //层级，依次类推
//@property (assign) NSInteger sort; //同级部门排序值
// path 如：/1/2/3/，是以“/”分割部门id组成的路径
//@property (strong) NSString * path; //部门路径，如：/1/2/3/
@property (assign) NSInteger usernum; //用户数量
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒

@end


// 部门与用户关系表
// struct  st_relative
//@interface CCNameSpace(CCModelDepartmentUserInfo) : CCNameSpace(CCModelBase)
@interface CCNameSpace(CCModelDepartmentUserInfo) : CCNameSpace(CCModelNodeInfo)

@property (strong) NSString * did; //部门ID
//@property (strong) NSString * cid; //客户ID
@property (strong) NSString * uid; //用户ID
//@property (assign) NSInteger sort; //用户在部门中的排序值
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒

@end


//////////////////////////////////////////////////
// CC群组数据类型

//类型：1：普通群；2：系统群
enum CCGroupType //群类型
{
    CC_GROUP_TYPE_NONE = 0,
    CC_GROUP_TYPE_NORMAL = 1, //普通群表
    CC_GROUP_TYPE_SYSTEM = 2  //系统群表
};
typedef enum CCGroupType CCGroupType;

//类型，1：普通成员；2：管理员；3：创建者；
enum CCGroupUserType //群用户类型
{
    GROUP_MEMBER_NONE = 0,
    GROUP_MEMBER_NORMAL = 1, //普通成员
    GROUP_MEMBER_ADMIN = 2,  //管理员
    GROUP_MEMBER_OWNER = 3,  //创建者
};
typedef enum CCGroupUserType CCGroupUserType;

//申请标识，0：申请中；1：申请成功；2：申请被拒绝
enum CCGroupUserAccept
{
    CC_GROUP_APFLAG_NONE = 0, //申请中
    CC_GROUP_APFLAG_SUCCESS = 1, //申请成功
    CC_GROUP_APFLAG_REJECTED = 2, //申请被拒绝
};
typedef enum CCGroupUserAccept CCGroupUserAccept;

//接收标识，0：不接受不提醒；1：接受不提醒；2：接受并提醒
enum CCGroupUserReceive
{
    CC_GROUP_RXFLAG_NONE = 0, //不接受不提醒
    CC_GROUP_RXFLAG_RECV_NO_SHOW = 1, //接受不提醒
    CC_GROUP_RXFLAG_RECV_AND_SHOW = 2, //接受并提醒
};
typedef enum CCGroupUserReceive CCGroupUserReceive;

//状态：0：激活；1：不激活；
enum CCGroupStatus //群状态
{
    CC_GROUP_STATUS_ACTIVE = 0, //0：不接受；
    CC_GROUP_STATUS_NO_ACTIVE = 1, //1：接受不提示；
};
typedef enum CCGroupStatus CCGroupStatus;

//状态：0：不接受；1：接受不提示；2：接受并提示；
enum CCGroupShowStatus //群消息状态
{
    CC_GROUP_STATUS_NO_ACCEPT = 0, //0：不接受；
    CC_GROUP_STATUS_ACCEPT_NO_SHOW = 1, //1：接受不提示；
    CC_GROUP_STATUS_ACCEPT_AND_SHOW = 2, //2：接受并提示；
};
typedef enum CCGroupShowStatus CCGroupShowStatus;


@class CCNameSpace(CCModelGroupUserBase);

// 群基础数据信息
@interface CCNameSpace(CCModelGroupBase) : NSObject

@property (strong) NSString * gid; //群ID
@property (strong) NSString * cid; //群客户ID
@property (strong) NSString * name; //群名字，必填
@property (strong) NSString * version; //版本号(保留用)
//@property (strong) NSMutableArray * userList;//成员明细
@property (strong) NSMutableDictionary * userInfos;//成员信息
@property (strong) NSMutableDictionary * nickInfos;//在群组中的昵称

@property (assign) NSInteger valid; //有效的数据
@property (assign) NSInteger delflag; //是否删除状态

@property (assign) NSInteger sort; //排序值
@property (assign) NSInteger audio; //音频权限
@property (assign) NSInteger video; //视频权限
@property (assign) NSInteger share; //共享权限
@property (assign) NSInteger note; //批注权限
@property (assign) NSInteger speak; //发言权限
@property (assign) NSInteger cname; //修改昵称权限

// 将其他节点信息拷贝至当前节点
- (void)updateGroupBase:(CCNameSpace(CCModelGroupBase) *)other;

// 添加用户节点信息拷贝至当前节点
- (void)addGroupUserInfo:(CCNameSpace(CCModelGroupUserBase) *)userInfo;
// 删除用户节点信息根据用户ID与客户ID
- (void)removeGroupUserByID:(NSString *)uidStr cid:(NSString *)cidStr;
// 获得用户节点信息根据用户ID与客户ID
- (CCNameSpace(CCModelGroupUserBase) *)userInfoByID:(NSString *)uidStr cid:(NSString *)cidStr;

@end

@class CCNameSpace(CCResultUser);

// 群用户基础数据信息
@interface CCNameSpace(CCModelGroupUserBase) : NSObject

@property (strong) NSString * gid; //群ID
@property (strong) NSString * gcid; //客户ID
@property (strong) NSString * uid; //用户ID
@property (strong) NSString * ucid; //客户ID
@property (strong) NSString * uname; //用户在群中昵称，空为用户名
@property (assign) NSInteger usertype; //类型，CCGroupUserType 3:群主 2：管理员 1；普通成员

@property (assign) NSInteger valid; //有效的数据
@property (assign) NSInteger delflag; //是否删除状态

@property (assign) NSInteger status; //会中状态
@property (assign) NSInteger sort; //排序值
@property (assign) NSInteger audio; //音频权限
@property (assign) NSInteger video; //视频权限
@property (assign) NSInteger share; //共享权限
@property (assign) NSInteger note; //批注权限
@property (assign) NSInteger speak; //发言权限
@property (assign) NSInteger cname; //修改昵称权限
@property (assign) NSInteger avctl; //音视频控制权限

// 将其他节点信息拷贝至当前节点
- (void)updateGroupUserBase:(CCNameSpace(CCModelGroupUserBase) *)other;

// 重新获取群用户信息方法
- (void)reloadGroupUserInfo:
(void (^)(CCCallState state, CCNameSpace(CCResultUser) * info))block;

@end

// 群表信息
// struct DbGroupInfo //struct DbRole
@interface CCNameSpace(CCModelFixedGroupInfo) : CCNameSpace(CCModelGroupBase)

//@property (strong) NSString * gid; //群ID
//@property (strong) NSString * cid; //群客户ID
//@property (strong) NSString * name; //群名字，必填
@property (strong) NSString * pinyin; //拼音
@property (strong) NSString * pyhead; //拼音头
@property (strong) NSString * topic; //群公告
@property (assign) NSInteger auth; //CCGroupUserAccept??
@property (assign) NSInteger type; //类型：CCGroupType
@property (assign) NSInteger maxnumber; //最大人数
@property (assign) NSInteger currentnumber; //当前人数
@property (assign) NSInteger status; //状态：CCGroupStatus
// struct DbRole - int iRole; //自己在群中的角色
@property (assign) NSInteger userrole; //类型，CCGroupUserType
@property (assign) NSInteger rxflag; //状态：CCGroupUserReceive
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒
@property (strong) NSString * hostPasscode; //主持人入会code
@property (strong) NSString * nickName; // 昵称

// 将其他节点信息拷贝至当前节点
- (void)updateGroupInfo:(CCModelFixedGroupInfo *)other;

@end

@class CCNameSpace(CCResultUser);

// 群权限 修改
// struct DbGroupInfo //struct DbRole
@interface CCNameSpace(CCModelAuthGroupInfo) : CCNameSpace(CCModelGroupBase)

@property (strong) NSDictionary * userDict;//{cid:uid}

@property (strong) NSString * type; //"type": 可选值：sort/share/audio/state/speek
@property (copy) NSString * value; //“value”: 对应设置的值，只能是数字
@property (assign) int act_mode;  // 0：成员状态同步变更（默认，兼容云视），并通知appserver，1：仅改变群组属性

@end
// 群与用户关系表
// struct DbGroupUser
@interface CCNameSpace(CCModelFixedGroupUserInfo) : CCNameSpace(CCModelGroupUserBase)

//@property (strong) NSString * gid; //群ID
//@property (strong) NSString * gcid; //群客户ID
//@property (strong) NSString * uid; //用户ID
//@property (strong) NSString * ucid; //用户客户ID
//@property (strong) NSString * uname; //用户在群中昵称，空为用户名
//@property (assign) NSInteger usertype; //类型，CCGroupUserType
//@property (assign) NSInteger receive; //接收标识 CCGroupUserReceive
//@property (assign) NSInteger userstate; //申请标识 CCGroupUserAccept
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒
// StRtUser sru;  //该用户详细数据
@property (strong) CCNameSpace(CCResultUser) * resUser; //该用户详细数据
//@property (strong) CCNameSpace(CCModelUserInfo) * userinfo; //该用户详细数据

- (CCNameSpace(CCModelUserInfo) *)userInfo;
// 重新加载用户信息
- (CCNameSpace(CCModelUserInfo) *)reloadUserInfo:(BOOL)isWait;

@end


// 临时会话信息, 与群表相同
@interface CCNameSpace(CCModelTempGroupInfo) : CCNameSpace(CCModelGroupBase)

//@property (strong) NSString * gid; //群ID
//@property (strong) NSString * cid; //客户ID
//@property (strong) NSString * name; //群名字，必填
@property (strong) NSString * topic; //群公告
@property (strong) NSString * pinyin; //拼音
@property (strong) NSString * pyhead; //拼音头
@property (assign) NSInteger auth; //CCGroupUserAccept??
@property (assign) NSInteger type; //类型：CCGroupType
@property (assign) NSInteger maxnumber; //最大人数
@property (assign) NSInteger currentnumber; //当前人数
@property (assign) NSInteger status; //状态：CCGroupStatus
// struct DbRole - int iRole; //自己在群中的角色
@property (assign) NSInteger userrole; //类型，CCGroupUserType
@property (assign) NSInteger rxflag; //状态：CCGroupUserReceive
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒

// 将其他节点信息拷贝至当前节点
- (void)updateGroupInfo:(CCModelTempGroupInfo *)other;

@end

@class CCNameSpace(CCResultUser);

// 临时会话与用户关系表
@interface CCNameSpace(CCModelTempGroupUserInfo) : CCNameSpace(CCModelGroupUserBase)

//@property (strong) NSString * gid; //群ID
//@property (strong) NSString * gcid; //客户ID
//@property (strong) NSString * uid; //用户ID
//@property (strong) NSString * ucid; //客户ID
//@property (strong) NSString * uname; //用户在群中昵称，空为用户名
//@property (assign) NSInteger usertype; //类型，CCGroupUserType
//@property (assign) NSInteger receive; //接收标识 CCGroupUserReceive
//@property (assign) NSInteger userstate; //申请标识 CCGroupUserAccept
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒
// StRtUser sru;  //该用户详细数据
@property (strong) CCNameSpace(CCResultUser) * resUser; //该用户详细数据
//@property (strong) CCNameSpace(CCModelUserInfo) * userinfo; //该用户详细数据

- (CCNameSpace(CCModelUserInfo) *)userInfo;
// 重新加载用户信息
- (CCNameSpace(CCModelUserInfo) *)reloadUserInfo:(BOOL)isWait;

@end


//////////////////////////////////////////////////
// CC消息数据类型

//会话状态，
//0x00000000：无状态；
//0x00000001：@消息；0x00000002：草稿
enum CCModelSessionState //会话状态
{
    CC_SESSION_STATE_NORAML = 0, //状态
    CC_SESSION_STATE_AT = 1, //@消息
    CC_SESSION_STATE_DRAFT = 2, //草稿
};
typedef enum CCModelSessionState CCModelSessionState;

//1：人，2：群，3：临时会话，
//4：应用，5：系统消息；6：好友申请
enum CCModelSessionType //会话类型
{
    CC_SESSION_TYPE_NONE = 0,
    CC_SESSION_TYPE_CHAT = 1, //普通成员
    CC_SESSION_TYPE_GROUP = 2, //群组成员
    CC_SESSION_TYPE_TEMPGROUP = 3,  //临时会话 Discuss
    CC_SESSION_TYPE_SAAS = 4,  //应用消息
    CC_SESSION_TYPE_SYSTEM = 5,  //系统消息
    CC_SESSION_TYPE_FIREND = 6,  //好友申请消息
    //CC_SESSION_TYPE_MAIL = 7, //邮件消息
    //CC_SESSION_TYPE_CALENDAR = 7, //日程消息
    //CC_SESSION_TYPE_MEETING = 7, //会议消息
    //CC_SESSION_TYPE_ASSISTANT = 7, //CC助手消息
    //CC_SESSION_TYPE_TBP = 7, //网盘消息
    //CC_SESSION_TYPE_ROBOT = 7, //机器人消息
    //CC_SESSION_TYPE_BBS = 7, //公告消息
    //CC_SESSION_TYPE_SYSTEM = 7, //系统消息
};
typedef enum CCModelSessionType CCModelSessionType;


// 会话信息表
@interface CCNameSpace(CCModelSessionInfo) : CCNameSpace(CCModelBase)

@property (strong) NSString * uid; //用户ID
@property (strong) NSString * cid; //客户ID，可选
@property (strong) NSString * sid; //会话ID
@property (strong) NSString * name; //会话名字，必填
@property (assign) NSInteger type; //会话类型 CCModelSessionType
@property (assign) NSInteger msgtype; //消息类型 CCModelMessageType
@property (strong) NSString * msgtext; //消息预览
@property (assign) NSInteger unreadnum; //未读消息计数
@property (assign) NSInteger sync; //同步标识，CCSyncState
@property (assign) NSInteger status; //消息状态 CCModelSessionState
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒

@end


//////////////////////////////////////////////////


//1：文本消息；2：图片消息；3：语音消息；
//4：应用消息；5：好友申请消息；6：好友应答消息
enum CCModelMessageType
{
    CC_MESSAGE_TYPE_UNKNOW = -1,
    CC_MESSAGE_TYPE_NONE = 0,
    CC_MESSAGE_TYPE_TEXT = 1, //文本消息
    CC_MESSAGE_TYPE_IMAGE = 2, //图片消息
    CC_MESSAGE_TYPE_VOICE = 3, //语音消息
    CC_MESSAGE_TYPE_GROUP_ACTION = 4, //群内的操作消息
    CC_MESSAGE_TYPE_VIDEO_CONF = 5, //视频会议
    CC_MESSAGE_TYPE_SAAS = 6, //应用消息
    CC_MESSAGE_TYPE_FIREND = 7, //好友申请消息
    CC_MESSAGE_TYPE_REFIREND = 8, //好友应答消息
    //CC_MESSAGE_TYPE_MAIL = 7, //邮件消息
    //CC_MESSAGE_TYPE_CALENDAR = 8, //日程消息
    //CC_MESSAGE_TYPE_MEETING = 9, //会议消息
    //CC_MESSAGE_TYPE_ASSISTANT = 10, //CC助手消息
    //CC_MESSAGE_TYPE_TBP = 11, //网盘消息
    //CC_MESSAGE_TYPE_ROBOT = 12, //机器人消息
    //CC_MESSAGE_TYPE_BBS = 13, //公告消息
    //CC_MESSAGE_TYPE_SYSTEM = 14, //系统消息
    //CC_MESSAGE_TYPE_FILE = 15, //文件消息
    //CC_MESSAGE_TYPE_OFFLINE = 16, //文本消息
    //CC_MESSAGE_TYPE_VIDEO = 17, //视频文件消息
    //CC_MESSAGE_TYPE_RECEIPT = 0xFF, //回执消息消息
};
typedef enum CCModelMessageType CCModelMessageType;

//发送状态，
//通用，0：未发送；1：正在发送，2：发送成功；3：发送失败；
//CHAT，{通用}；4：未读；5：已读
//SYSTEM，{通用}；4未读；：5：已读
//GROUP，{通用}；4：未读；5：已读
//TMPGROUP，{通用}；4：未读；5：已读
//ASSISTANT，{通用}；4：未读；5：已读
//TBP，{通用}；4：未读；5：已读
//BBS，{通用}；4：未读；5：已读
//ROBOT，{通用}；4：未读；5：已读
//RECEIPT，{通用}；4：未读；5：已读
//CALENDAR，{通用}；4：未读；5：同意；6：拒绝；7：不确定
//MEETING，{通用}；4：未读；5：同意；6：拒绝；7：不确定；8：开会中；9：会议结束
enum CCModelMessageStatus
{
    // 以下为共用部分
    CC_MESSAGE_STATUS_NONE = 0, //0：未发送
    CC_MESSAGE_STATUS_SENDING = 1, //1：正在发送
    CC_MESSAGE_STATUS_SENDSUCCESS = 2, //2：发送成功
    CC_MESSAGE_STATUS_SENDFAILED = 3, //发送失败
    CC_MESSAGE_STATUS_UNREAD = 4, //未读
    // 以下为非共用部分
    CC_MESSAGE_STATUS_HAVEREAD = 5, //已读
    CC_MESSAGE_STATUS_AGREE = 5, //同意
    CC_MESSAGE_STATUS_DISAGREE = 6, //同意
    CC_MESSAGE_STATUS_UNCERTAIN = 7, //不确定
    CC_MESSAGE_STATUS_ONMEETING = 8, //开会中
    CC_MESSAGE_STATUS_MEETINGEND = 9, //会议结束
};
typedef enum CCModelMessageStatus CCModelMessageStatus;

//消息方向，1：收；2：发
enum CCMessageDirectionType
{
    CC_DIRECTION_UNKNOW = 0, //未知
    CC_DIRECTION_SENDER = 2, //发出的消息
    CC_DIRECTION_RECEIVE = 1, //收到的消息
};
typedef enum CCMessageDirectionType CCMessageDirectionType;


// 基础消息信息类型
@interface CCNameSpace(CCModelMessageInfo) : CCNameSpace(CCModelBase)

// tag 建议是毫秒，建索引
@property (strong) NSString * tag; //标识，客户端确保唯一
@property (strong) NSString * uid; //用户ID，建索引
@property (strong) NSString * cid; //客户ID，可选
@property (strong) NSString * sid; // 会话ID，建索引
@property (strong) NSString * gid; //群、临时会话ID
@property (strong) NSString * gname; //群、临时会话名字
@property (strong) NSString * gtopic; //群、临时会话公告
@property (strong) NSString * from; //发信系统ID,UID
@property (strong) NSString * fromcid; //发信系统客户CID
@property (strong) NSString * fromname; //发信系统名字
@property (strong) NSString * to; //收信系统ID,UID
@property (strong) NSString * tocid; ////收信系统客户CID
@property (strong) NSString * toname; //收信系统名字
@property (assign) NSInteger type; //会话类型，可选 CCModelSessionType
@property (assign) NSInteger draft; //草稿，0：不是草稿；1：是草稿
@property (assign) NSInteger direction; //消息方向，CCMessageDirection
@property (strong) NSString * msgid; //消息ID，服务器下发的值，建索引
@property (assign) NSInteger msgtype; //消息类型：CCModelMessageType
@property (assign) long long msgtime; //收发时间，精度到毫秒
@property (assign) NSInteger status; //消息状态，CCModelMessageStatus
@property (strong) NSString * msgtext; //消息文本部分
@property (assign) NSInteger msgsize; //消息体大小，可选数据
@property (strong) NSString * msgbody; //消息体数据（格式化），可选数据
@property (strong) NSString * resource; //携带资源信息，图片，语音... or Url
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒

@end


//////////////////////////////////////////////////
// 其他类型

// 会议室状态
//状态：0未预定，1：已预定未使用；2：已预定正在使用
enum CCConferenceStatus
{
    CC_CONFERENCE_NOT_SCHEDULED = 0, //0：未预定
    CC_CONFERENCE_SCHEDULED_NOT_USED = 1, //1：已预定未使用
    CC_CONFERENCE_SCHEDULED_AND_USED = 2, //2：已预定正在使用
};
typedef enum CCConferenceStatus CCConferenceStatus;


// 会议室信息表(会议室预定)
@interface CCNameSpace(CCModelConferenceRoom) : CCNameSpace(CCModelBase)

@property (strong) NSString * crid; //会议室ID
@property (strong) NSString * name; //会议室名称
@property (assign) NSInteger status; //状态，0：闲；1：忙
@property (assign) NSInteger capacity; //容纳人数，默认是0
@property (strong) NSString * tel; //电话
@property (strong) NSString * video; //视频终端信息
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒

@end

// 会议室状态(会议室预定)
@interface CCNameSpace(CCModelConferenceStatus) : CCNameSpace(CCModelBase)

@property (strong) NSString * crid; //会议室ID
@property (assign) long long beginTime;//开始时间，秒
@property (assign) long long endTime;//结束时间，秒
//状态：0未预定，1：已预定未使用；2：已预定正在使用
@property (assign) NSInteger status; //会议室状态 CCConferenceStatus
@property (assign) long long createtime; //创建时间，单位是毫秒
@property (assign) long long updatetime; //更新时间，单位是毫秒

@end

//定义设备枚举类型
typedef enum devType {
    UNKNOW = 0,
    IPHONE,
    ANDROID,
    WINDOWS,
    WEB,
    HARDWAREDEVICE,//硬件设备
    ANDROID_9Z,
    ANDROID_X6,
    ANDROID_TOUCH
} loginDeviceType;

//扫码登录设备类型
@interface CCNameSpace(CCModelQRCodeLoadDeviceModel) : CCNameSpace(CCModelBase)

@property (nonatomic,copy) NSString *devId;
@property (nonatomic,assign) loginDeviceType devType;
@property (nonatomic,assign) long long timestamp; //扫码登录时间

@end


#endif //_CC_CCDataModel_H_
