//
//  CCModelGroup.h
//  adapter
//
//  Created by yiyimama on 2017/5/18.
//  Copyright © 2017年 zsx. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCRuntime.h"

#import "CCModelBase.h"
//#import "CCModelMethod.h"
#import "CCModelCommand.h"

@interface CCNameSpace(CCGroupBase) : NSObject

@end

// struct IInterface
@interface CCNameSpace(CCCommandBase) : NSObject

// 获得命令字的类型
//- (NSInteger)getCmdType;
- (CCCommandMessageType)getCmdType;

@end

// struct group_normol_confirm_t
@interface CCNameSpace(CCGroupConfirm) : NSObject

@property (assign) NSInteger status; //确认号
@property (strong) NSString * info; //确认信息

@end

// struct group_info
@interface CCNameSpace(CCGroupInfo) : CCNameSpace(CCCommandBase)

@property (strong) NSString * gid; //群ID
@property (strong) NSString * cid; //客户ID
@property (strong) NSString * name; //群名字

@end

//struct group_user_t
@interface CCNameSpace(CCGroupUser) : CCNameSpace(CCGroupBase)

@property (strong) NSString * uid; //用户ID
@property (strong) NSString * cid; //客户ID
@property (strong) NSString * name; //用户名字

@end

@interface CCNameSpace(CCGroupSet) : CCNameSpace(CCGroupUser)
@property (strong) NSString * type;
@property (assign) NSString * value;
//"type": 可选值：sort/share/audio/state/speek
//“value”: 对应设置的值，只能是数字
@end

// struct group_create_t
@interface CCNameSpace(CCGroupCreate) : CCNameSpace(CCCommandBase)

@property (strong) NSString * name; //群名字
@property (strong) NSString * topic; //群公告
@property (assign) NSInteger auth; //申请入群是否需要确认
@property (assign) NSInteger type; //群类型 3.会议组
@property (assign) NSInteger maxnum; //最大人数
// std::list<group_user_t> user;
// NSMutableArray<CCNameSpace(CCGroupUser) *>
@property (strong) NSMutableArray * baseList; //用户明细

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_send_group_create

@end

// struct group_create_notify_t
@interface CCNameSpace(CCGroupCreateNotify) : CCNameSpace(CCGroupInfo)

//@property (strong) NSString * gid; //群ID
//@property (strong) NSString * cid; //客户ID
//@property (strong) NSString * name; //群名字
@property (strong) NSString * topic; //群公告
@property (assign) NSInteger auth; //
@property (assign) NSInteger type; //群类型
@property (assign) NSInteger maxnum; //最大人数

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_recv_group_create

@end

// struct group_invite_t
@interface CCNameSpace(CCGroupInvite) : CCNameSpace(CCGroupInfo)

// std::list<group_user_t> invitee;
@property (strong) NSMutableArray * baseList; //用户明细
@property (strong) CCNameSpace(CCGroupUser) * inviter; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_send_group_invite

@end

// struct group_invited_notify_t
@interface CCNameSpace(CCGroupInviteNotify) : CCNameSpace(CCGroupInfo)

@property (strong) CCNameSpace(CCGroupUser) * inviter; //用户信息
@property (strong) CCNameSpace(CCGroupUser) * invitee; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_recv_group_invite

@end

// struct group_invited_deal_t
@interface CCNameSpace(CCGroupInviteDeal) : CCNameSpace(CCGroupInfo)

@property (strong) NSString * response; //"agree/refuse"
@property (strong) CCNameSpace(CCGroupUser) * inviter; //用户信息
@property (strong) CCNameSpace(CCGroupUser) * invitee; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_send_group_invite_deal

@end

// struct group_invited_deal_notify_t
@interface CCNameSpace(CCGroupInviteDealNotify) : CCNameSpace(CCGroupInfo)

@property (strong) NSString * response; //"agree/refuse"
@property (strong) CCNameSpace(CCGroupUser) * inviter; //用户信息
@property (strong) CCNameSpace(CCGroupUser) * invitee; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_recv_group_invite_deal

@end

//1407  Apply for membership

// struct group_apply_t
@interface CCNameSpace(CCGroupApply) : CCNameSpace(CCGroupInfo)

@property (strong) CCNameSpace(CCGroupUser) * proposer; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_send_group_join

@end

// struct group_apply_notify_t
@interface CCNameSpace(CCGroupApplyNotify) : CCNameSpace(CCGroupInfo)

@property (strong) CCNameSpace(CCGroupUser) * proposer; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_recv_group_join

@end

// struct group_apply_deal_t
@interface CCNameSpace(CCGroupApplyDeal) : CCNameSpace(CCGroupInfo)

@property (strong) NSString * response; //"agree/refuse"
@property (strong) CCNameSpace(CCGroupUser) * proposer; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_send_group_join_deal

@end

// struct group_apply_deal_notify_t
@interface CCNameSpace(CCGroupApplyDealNotify) : CCNameSpace(CCGroupInfo)

@property (strong) NSString * response; //"agree/refuse"
@property (strong) CCNameSpace(CCGroupUser) * auditor; //用户信息
@property (strong) CCNameSpace(CCGroupUser) * proposer; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_recv_group_join_deal

@end


// struct group_kickout_t
@interface CCNameSpace(CCGroupKickout) : CCNameSpace(CCGroupInfo)

// std::list<group_user_t> out;;
@property (strong) NSMutableArray * baseList; //用户明细
//@property (strong) CCNameSpace(CCGroupUser) * kicker; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_send_group_kickout

@end

// struct group_kickout_notify_t
@interface CCNameSpace(CCGroupKickoutNotify) : CCNameSpace(CCGroupInfo)

// std::list<group_user_t> out;;
@property (strong) NSMutableArray * baseList; //用户明细
@property (strong) CCNameSpace(CCGroupUser) * kicker; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_recv_group_kickout

@end


// struct group_quit_t
@interface CCNameSpace(CCGroupQuit) : CCNameSpace(CCGroupInfo)

// std::list<group_user_t> quitter;
@property (strong) NSMutableArray * baseList; //用户明细
//@property (strong) CCNameSpace(CCGroupUser) * quitter; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_send_group_quit

@end

// struct group_kickout_notify_t
@interface CCNameSpace(CCGroupQuitNotify) : CCNameSpace(CCGroupInfo)

// std::list<group_user_t> quitter;
//@property (strong) NSMutableArray * baseList; //用户明细
@property (strong) CCNameSpace(CCGroupUser) * quitter; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_recv_group_quit

@end

// group_set_attribute_t
@interface CCNameSpace(CCGroupAttribute) : CCNameSpace(CCGroupInfo)

//@property (strong) NSString * name; //群名字
@property (strong) NSString * topic; //群公告
@property (assign) NSInteger auth; //
@property (assign) NSInteger type; //群类型
@property (assign) NSInteger maxnum; //最大人数

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_send_group_modify

@end

// struct group_create_notify_t
@interface CCNameSpace(CCGroupAttributeNotify) : CCNameSpace(CCGroupInfo)

//@property (strong) NSString * name; //群名字
@property (strong) NSString * topic; //群公告
@property (assign) NSInteger auth; //
@property (assign) NSInteger type; //群类型
@property (assign) NSInteger maxnum; //最大人数

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_recv_group_modify

@end

// struct group_set_admin_t
@interface CCNameSpace(CCGroupAdmin) : CCNameSpace(CCGroupInfo)

// std::list<group_user_t> admin;
@property (strong) NSMutableArray * baseList; //用户明细
//@property (strong) CCNameSpace(CCGroupUser) * handler; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_send_group_admin

@end

// struct group_admin_notify_t
@interface CCNameSpace(CCGroupAdminNotify) : CCNameSpace(CCGroupInfo)

// std::list<group_user_t> admin;
@property (strong) NSMutableArray * baseList; //用户明细
@property (strong) CCNameSpace(CCGroupUser) * handler; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_recv_group_admin

@end

// struct group_recover_admin_t
@interface CCNameSpace(CCGroupRecoverAdmin) : CCNameSpace(CCGroupInfo)

// std::list<group_user_t> member;
@property (strong) NSMutableArray * baseList; //用户明细
@property (strong) CCNameSpace(CCGroupUser) * handler; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_send_group_admin_recover

@end

// struct group_recover_admin_notify_t
@interface CCNameSpace(CCGroupRecoverAdminNotify) : CCNameSpace(CCGroupInfo)

// std::list<group_user_t> member;
@property (strong) NSMutableArray * baseList; //用户明细
@property (strong) CCNameSpace(CCGroupUser) * handler; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_recv_group_admin_recover

@end

// struct group_set_owner_t
@interface CCNameSpace(CCGroupOwner) : CCNameSpace(CCGroupInfo)

// std::list<group_user_t> owner;
//@property (strong) NSMutableArray * baseList; //用户明细
@property (strong) CCNameSpace(CCGroupUser) * owner; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_send_group_owner

@end

// struct group_admin_notify_t
@interface CCNameSpace(CCGroupOwnerNotify) : CCNameSpace(CCGroupInfo)

// std::list<group_user_t> owner;
//@property (strong) NSMutableArray * baseList; //用户明细
@property (strong) CCNameSpace(CCGroupUser) * owner; //用户信息
@property (strong) CCNameSpace(CCGroupUser) * handler; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_recv_group_owner

@end


// struct group_set_vcard_t
@interface CCNameSpace(CCGroupVcard) : CCNameSpace(CCGroupInfo)

// std::list<group_user_t> user;
@property (strong) NSMutableArray * baseList; //用户明细
//@property (strong) CCNameSpace(CCGroupUser) * handler; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_send_group_vcard

@end

// struct group_vcard_notify_t
@interface CCNameSpace(CCGroupVcardNotify) : CCNameSpace(CCGroupInfo)

// std::list<group_user_t> user;
@property (strong) NSMutableArray * baseList; //用户明细
@property (strong) CCNameSpace(CCGroupUser) * handler; //用户信息

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_recv_group_vcard

@end


// struct group_set_recv_t
@interface CCNameSpace(CCGroupReceive) : CCNameSpace(CCGroupInfo)

@property (strong) NSString * rxflag;

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_send_group_receive

@end

// struct group_recv_notify_t
@interface CCNameSpace(CCGroupReceiveNotify) : CCNameSpace(CCGroupInfo)

@property (strong) NSString * rxflag;

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_recv_group_receive

@end


// struct group_disbanded_t
@interface CCNameSpace(CCGroupDisbanded) : CCNameSpace(CCGroupInfo)

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_send_group_disbanded

@end

// struct group_disbanded_notify_t
@interface CCNameSpace(CCGroupDisbandedNotify) : CCNameSpace(CCGroupInfo)

// 获得命令字的类型
- (CCCommandMessageType)getCmdType; //mtype_recv_group_disbanded

@end


