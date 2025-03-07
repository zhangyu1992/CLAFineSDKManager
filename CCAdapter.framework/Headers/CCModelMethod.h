//
//  CCModelMethod.h
//  adapter
//
//  Created by jinxiangkun on 17/3/26.
//  Copyright © 2017年 zsx. All rights reserved.
//

#ifndef _CC_CCDataModel_Method_H_
#define _CC_CCDataModel_Method_H_

#import <Foundation/Foundation.h>

#import "CCModelBase.h"
#import "CCServiceTypes.h"
#import "CCModelGroup.h"
//#include "CCEMInterface.h" //不能包含C++

// @获取Sdk内部路径
enum CCSdkPathType
{
    CCSdkPathTypeRoot = 0x0,
    CCSdkPathTypeUser, //用户
    CCSdkPathTypeImage, //图像
    CCSdkPathTypeVoice, //语音
    CCSdkPathTypeFile, //文件
    CCSdkPathTypeAvatar, //头像
};
typedef \
enum CCSdkPathType CCSdkPathType;

///...

@interface CCNameSpace(CCStatusInfo) : NSObject

// 状态码
@property (assign) long status;
// 错误码
@property (assign) long errcode;
// 状态描述
@property (strong) NSString * info;

@end

// struct 登陆超时值
@interface CCNameSpace(CCLinkTimeOut) : NSObject

// 注意，预设置30秒，当设置值>0为有效值，单位为秒

// 定位服务器超时时间，单位秒
@property (assign) int timeoutLocation;
// 认证服务器超时时间，单位秒
@property (assign) int timeoutAuthLogin;
// 连接websocket超时时间，单位秒
@property (assign) int timeoutWebSocket;
// 连接Roster服务器超时时间，单位秒
@property (assign) int timeoutLoadRoster;

@end


// struct 登陆状态类型
@interface CCNameSpace(CCLoginStateInfo) : NSObject

// 本地认证状态
@property (assign) CCLocalAuthState localAuth;
// 线上联机认证状态
@property (assign) CCOnlineAuthState onlineAuth;
// 定位服务状态码
@property (assign) CCLocalStatusCode localState;
// 认证服务状态码
@property (assign) CCLoginStatusCode loginState;

// 用户的认证信息，uid, cid可查询数据信息
@property (strong) CCNameSpace(CCModelAuthInfo) * authInfo;

// 更新当前的认证信息
- (void)updateAuthInfo:(CCNameSpace(CCModelAuthInfo) *)other;

// 更新当前的登录状态信息表
- (void)updateLoginState:(CCNameSpace(CCLoginStateInfo) *)other;

@end

///////////////////////////////////////////////////

@class CCNameSpace(CCDepartPath);

// enum EM_ITEMOWNER
enum CCItemInfoType
{
    CCItemInfoTypeUnknow = 0,//EIW_UNKNOW
    CCItemInfoTypeUser = 1, //EIW_USER //用户
    CCItemInfoTypeGroup = 2, //EIW_GROUP, //群组
    CCItemInfoTypeTempGroup = 3, //EIW_DISCUSSION, //临时会话
    CCItemInfoTypeApp = 4, //EIW_APPLICATION, //应用
    CCItemInfoTypeSystem = 5, //EIW_SYSTEM, //系统
    CCItemInfoTypeFriend = 6, //EIW_FRIEND, //好友申请
    CCItemInfoTypeDepart = 7,//EIW_DEPT //组织
    CCItemInfoTypeCustomer = 8,//EIW_CUSTOMEER //客户
    CCItemInfoTypeGroupAction = 9, //EIW_GPACTION //群系统消息
    //CCItemInfoTypeAssistant, //助理
};
typedef enum CCItemInfoType CCItemInfoType;

// struct st_iteminfo
@interface CCNameSpace(CCItemInfo) : NSObject

@property (strong) NSString * id_; //通用id
@property (strong) NSString * cid; //客户id
@property (strong) NSString * logname;//用户名
@property (assign) NSInteger  rcr; //CCItemInfoType
//@property (assign) CCItemInfoType rcr; //CCItemInfoType

@end

// class cc_get_option
@interface CCNameSpace(CCGetOption) : NSObject

@property (strong) NSString * key; // 搜索键值
@property (assign) NSInteger  limit; // 限制条目 >0 有效

@end

// struct DeptCountSt
@interface CCNameSpace(CCDepartCount) : NSObject

@property (strong) CCNameSpace(CCItemInfo) * itemInfo;
@property (assign) int iDepartCount; //设置组织节点成员个数

@end

//////////////////////////////////////////////////////////////

// 虚基类
// class cc_base_result
@interface CCNameSpace(CCResultBase) : NSObject

- (NSArray *)getResultList;
- (NSDictionary *)getResultMap;

@property (strong) NSMutableArray * baseList;
@property (strong) NSMutableDictionary * baseMap;

@end

// enum em_cc_roster
enum CCRosterType
{
    CCRosterTypeUnknow = 0, //CCItemInfoTypeUnknow,//ecr_unknow
    CCRosterTypeUser, //CCItemInfoTypeUser, //ecr_user //用户
    CCRosterTypeDepart, //CCItemInfoTypeDepart,//ecr_dept //组织
    CCRosterTypeCustomer, //CCItemInfoTypeCustomer,//ecr_customer //客户
    CCRosterTypeDepartUser, //CCRosterTypeCustomer + 1, //ecr_relative //组织客户
    CCRosterTypeResultUser, //CCRosterTypeCustomer + 2, //ecr_res_user
    CCRosterTypeResultDepart, //CCRosterTypeCustomer + 3, //ecr_res_dept
};
typedef enum CCRosterType CCRosterType;

// 虚基类
// struct cc_roster_base
@interface CCNameSpace(CCRosterBase) : NSObject

- (NSString *)getID; //获得相关ID
- (NSString *)getCID; //获得客户ID
- (NSInteger)getRosterType; //获得类型

// 节点路径列表
@property (strong) NSMutableArray * baseList;

// 上级节点信息
- (CCNameSpace(CCDepartPath) *)firstDepartInfo;
// 填加节点路径
- (void)addDepartPath:(CCNameSpace(CCDepartPath) *)item;
// 重置节点名称
- (void)resetDepartName:(NSString *)id_ cid:(NSString *)cid
                   name:(NSString *)name;

@end

// struct ItemSt
@interface CCNameSpace(CCDepartItem) : NSObject

@property (strong) NSString * id_; //部门ID
@property (strong) NSString * cid; //客户ID
@property (strong) NSString * name; //部门名字

@end

// 部门表信息
// struct stu_dept_info
@interface CCNameSpace(CCDepartPath) : NSObject

@property (strong) NSString * id_; //部门ID
@property (strong) NSString * cid; //客户ID
@property (strong) NSString * name; //部门名字，必填
@property (assign) NSInteger sort; //同级部门排序值
@property (strong) NSString * path; //部门路径，如：/1/2/3/
@property (strong) NSMutableArray * listitem; //根节点到该节点所经过的所有节点基本数据，只在有需求时填充

- (NSInteger)getSort;
- (NSMutableArray *)getAllPathID;

@end

// class CxRosterResult
@interface CCNameSpace(CCRosterResult) : CCNameSpace(CCResultBase)

- (void)setResultEmpty;
- (NSArray *)getResultList;
- (NSDictionary *)getResultMap;

//@property (strong) NSMutableArray * baseList;
//@property (strong) NSMutableDictionary * baseMap;

@end


// struct st_up_user
@interface CCNameSpace(CCRosterUser) : CCNameSpace(CCRosterBase)

@property (strong) CCNameSpace(CCModelUserInfo) * info; //用户信息

- (NSString *)getID; //获得相关ID
- (NSString *)getCID; //获得客户ID
- (NSInteger)getRosterType; //获得类型 CCRosterType

@end

// struct st_up_customer
@interface CCNameSpace(CCRosterCustomer) : CCNameSpace(CCRosterBase)

@property (strong) CCNameSpace(CCModelCustomerInfo) * info; //用户信息

- (NSString *)getID; //获得相关ID
- (NSString *)getCID; //获得客户ID
- (NSInteger)getRosterType; //获得类型 CCRosterType

@end

// struct st_up_dept
@interface CCNameSpace(CCRosterDepartment) : CCNameSpace(CCRosterBase)

@property (strong) CCNameSpace(CCModelDepartmentInfo) * info; //用户信息

- (NSString *)getID; //获得相关ID
- (NSString *)getCID; //获得客户ID
- (NSInteger)getRosterType; //获得类型 CCRosterType

@end

// struct st_res_user
@interface CCNameSpace(CCResultUser) : CCNameSpace(CCRosterUser)

//@property (strong) CCNameSpace(CCModelUserInfo) * info; //用户信息

- (NSString *)getID; //获得相关ID
- (NSString *)getCID; //获得客户ID
- (NSInteger)getRosterType; //获得类型 CCRosterType

@end

//struct st_res_dept
@interface CCNameSpace(CCResultDepartment) : CCNameSpace(CCRosterDepartment)

//@property (strong) CCNameSpace(CCModelDepartmentInfo) * info; //用户信息

- (NSString *)getID; //获得相关ID
- (NSString *)getCID; //获得客户ID
- (NSInteger)getRosterType; //获得类型 CCRosterType

@end

// struct st_up_dept_user
@interface CCNameSpace(CCRosterDepartmentUser) : CCNameSpace(CCRosterBase)

@property (strong) CCNameSpace(CCModelDepartmentUserInfo) * info; //用户信息

- (NSString *)getID; //获得相关ID
- (NSString *)getCID; //获得客户ID
- (NSInteger)getRosterType; //获得类型 CCRosterType

@end

/////////////////////////////////////////////////////////////

// 消息的调用结构体信息

// struct st_msg_conf
@interface CCNameSpace(CCGetConfig) : NSObject

@property (strong) NSString * key; //关键字搜索
@property (assign) long long  starttime; //起始时间
@property (assign) long long  endtime;   //结束时间
@property (assign) NSInteger  count;     //每页消息条数
@property (assign) NSInteger  page;      //获取第几页消息
@property (assign) NSInteger  maxpage;   //消息总页码

@end

// struct st_mst_getresult
@interface CCNameSpace(CCMessageGetResult) : NSObject

// 消息结果列表 CCNameSpace(CCMessageChatInfo)
@property (strong) NSMutableArray * list;
// 消息获取条件+结果描述信息
@property (strong) CCNameSpace(CCGetConfig) * config;

@end


/////////////////////////////////////////////////////////////

// 群组的调用结构体信息

enum CCGroupGetModeType
{
    CCGroupGetModeActive = 0x0, //活动的、有效的数据
    CCGroupGetModeNoActive = 0x1, //非活跃的、失效的
    CCGroupGetModeAll = 0xF000, //全部数据, 活动的+非活跃的
};
typedef enum CCGroupGetModeType CCGroupGetModeType;


@class CCNameSpace(CCGroupUser);

// struct StGpObject
@interface CCNameSpace(CCStGroupObject) : NSObject

@property (strong) NSString * gid; //群ID
@property (strong) NSString * cid; //客户ID
@property (strong) NSString * name; //群名字
// std::list<group_user_t> lMember;
@property (strong) NSMutableArray * baseList; //用户明细
@property (strong) NSDictionary * infoDict; //附加信息
@property (assign) BOOL cancel; // yes:取消邀请
@property (strong) NSString * passcode; //转移的原因

@end

// struct StInviteDeal
@interface CCNameSpace(CCStGroupInviteDeal) : NSObject

@property (assign) BOOL bAgree; //答复，是否同意
@property (strong) CCGroupApplyDeal * applyDeal;
@property (strong) NSDictionary * infoDict;//附加信息
@property (strong) NSString * obj_user_Uid;; //被邀请的UID
@property (strong) NSString * obj_user_Cid;; //被邀请的CID
@property (strong) NSString * obj_owner_Cid; //邀请者的cid
@property (strong) NSString * obj_owner_Gid; //群ID


@end
@interface CCNameSpace(CCStGroupJoinApple) : CCItemInfo
@property (strong) NSString * nickName; //昵称

@property (strong) NSString * hostPasscode; //主持人链接入会
@end
// struct StAttribute
@interface CCNameSpace(CCStGroupAttribute) : NSObject

@property (strong) NSString * gid; //群ID
@property (strong) NSString * cid; //客户ID
@property (strong) NSString * name; //群名字
@property (strong) NSString * topic; //群公告
@property (assign) NSInteger auth; //
@property (assign) NSInteger type; //群类型
@property (assign) NSInteger maxnum; //最大人数

@end
// 群成员信息
@interface CCNameSpace(CCStGroupMember) : NSObject
@property (strong) NSString * set_type;
@property (strong) NSString * set_Value;
@property (assign) NSInteger act_mode; // 0：成员状态同步变更（默认，兼容云视），并通知appserver，1：仅改变群组属性
/**{cid:uid}*/
@property (strong) NSDictionary * userDict;//{cid:uid}
@property (strong) NSString * gid; //群ID
@property (strong) NSString * cid; //群主客户ID

//"type": 可选值：sort/share/audio/state/speek
//“value”: 对应设置的值，只能是数字

@end
// 群成员 申请消息
@interface CCNameSpace(CCStGroupMemberApply) : NSObject
@property (strong) NSString * apply_type;// 申请权限类型
@property (strong) NSString * gid; //群ID
@property (strong) NSString * cid; //群主客户ID
@end
//typedef std::list<DbGroupUser>  LGROUPUSER;
//typedef std::list<DbGroupInfo>  LGROUPINFO;

// struct DbGroupList 获取群列表
@interface CCNameSpace(CCModelGroupInfoList) : NSObject

@property (strong) NSString * gid; //群ID
@property (strong) NSString * gcid; //群客户ID
@property (strong) NSString * uid; //用户ID
@property (strong) NSString * ucid; //用户客户ID
@property (assign) NSInteger flag; //
//'类型，1：普通成员；2：管理员；3：创建者；
@property (assign) NSInteger usertype; //类型，CCGroupUserType
// std::list<DbGroupInfo> fixedgroups;
@property (strong) NSMutableArray * baseList; //用户明细
@property (strong) CCNameSpace(CCModelFixedGroupInfo) * groupInfos;

@end

// struct GpDetails 获取群信息
//群详细信息，包括群信息和群成员信息
@interface CCNameSpace(CCModelGroupDetails) : NSObject

// std::list<DbGroupUser> lGpUsers;
@property (strong) NSMutableArray * baseList; //用户明细
@property (strong) CCNameSpace(CCModelFixedGroupInfo) * groupInfo;

@end


/////////////////////////////////////////////////////////////




#endif //_CC_CCDataModel_Method_H_
