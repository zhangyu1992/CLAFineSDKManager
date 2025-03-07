//
//  CCModelMeet.h
//  adapter
//
//  Created by yiyimama on 2018/5/25.
//  Copyright © 2018年 zsx. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCModelBase.h"

//meet type
enum CC_EM_MTTYPE
{
    CC_EMT_SIGNIN = 0x0000,
    CC_EMT_SIGNOUT,
    CC_EMT_MULTIIN,
    CC_EMT_MULTIOUT
};
typedef enum CC_EM_MTTYPE CC_EM_MTTYPE;

//deal state
enum CC_EM_OPTYPE
{
    CC_EOT_DEFAULT = 0x0000,
    CC_EOT_ACCEPT,
    CC_EOP_REFUSE
};
typedef enum CC_EM_OPTYPE CC_EM_OPTYPE;

//msg state
enum CC_EM_MSGSTATE
{
    CC_EMS_UNREAD = 0x0000,
    CC_EMS_READ
};
typedef enum CC_EM_MSGSTATE CC_EM_MSGSTATE;

// class MtSearchSt
@interface CCNameSpace(CCMeetSearchStruct) : NSObject

@property (assign) NSInteger mss_page; //当前页码
@property (assign) NSInteger mss_total; //总页码
@property (assign) NSInteger mss_count; //每页条数

@end

// class MtParticipant
@interface CCNameSpace(CCMeetParticipant) : NSObject

@property (strong) NSString * mpuid; //用户编号
@property (strong) NSString * mpcid; //客户编号
@property (strong) NSString * mpname; //用户名称

@end

// class MtInfo
@interface CCNameSpace(CCMeetModelData) : NSObject

@property (assign) long long date; //会议时间
@property (assign) CC_EM_MTTYPE mttype; //会议描述
@property (assign) CC_EM_OPTYPE optype; //会议处理方式
@property (strong) NSString * roomid; //会议ID
@property (strong) NSString * roompwd; //会议密码
@property (strong) NSString * roomname; //会议名字

@end

// class MtmInfo
@interface CCNameSpace(CCMeetMessageData) : NSObject

@property (strong) NSString * msgid; //消息ID
@property (strong) NSString * msgroomid; //会议房间ID
@property (assign) long long  msgdate; //消息时间
@property (strong) NSString * msgtitle; //消息主题
@property (strong) NSString * msgbody; //消息体
@property (assign) CC_EM_MSGSTATE msgstate; //会议消息状态，已读、未读
@property (strong) NSString * from_uid; //会议消息来源
@property (strong) NSString * from_cid; //会议消息来源
@property (strong) NSString * from_name; //会议消息来源

@end

// class SdkMeetMessage
@interface CCNameSpace(CCMessageMeetInfo) : NSObject //加入数据库结构

@property (strong) CCMeetModelData * miInfo; //会议详细信息 MtInfo
@property (strong) CCMeetMessageData * miMsg; //会议消息详情 MtmInfo
@property (strong) NSMutableArray * lpInvitees; //会议参与者 std::list<MtParticipant>


@end


