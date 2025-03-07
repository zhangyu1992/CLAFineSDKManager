//
//  CCNotificationKeys.h
//  NetMeetingCC
//
//  Created by jinxiangkun on 2019/1/3.
//  Copyright © 2019年 jinxiangkun. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCAdapterKeys.h"

// 用户
typedef NS_ENUM(unsigned long long, CCUserInfoAction)
{
    CCUserInfoAction_NickName,
    CCUserInfoAction_HeadImage,
    CCUserInfoAction_Sign,
};

typedef NS_ENUM(unsigned long long, CCMessageAction)
{
    CCMessageAction_ReciviceOfflineMessages,    //接受离线消息
    CCMessageAction_ReciviceMessage,  //收到消息
    CCMessageAction_RecvicedConfimMessage,  //收到回执消息
    CCMessageAction_SendMessage,    //发送消息
    CCMessageAction_DeleteMessage,  //删除消息
    CCMessageAction_RelayMessage,   //转发消息
    CCMessageAction_FavoriteMessage,    //收藏消息
    CCMessageAction_DraftChange,    //文本输入框变动，草稿变化
    CCMessageAction_CleanHistoryMessages,   //清除历史消息
    CCMessageAction_ChangedUnreadNumber,    //改变未读数
};

typedef NS_ENUM(unsigned long long, CCClientConfigType)
{
    CCClientConfigType_ServerAddress,
    //CCClientConfigKey_ServerAddress, CCClientConfigKey_ServerPort
};

//群
typedef NS_ENUM(unsigned long long, CCGroupAction)
{
    //创建群
    CCGroupAction_CreateGroup = ((1LL<<16) + 0),
    //加入群
    CCGroupAction_JoinGroup = ((1LL<<16) + 1),
    //退出群
    CCGroupAction_ExitGroup = ((1LL<<16) + 2),
    //解散群
    CCGroupAction_DissolveGroup = ((1LL<<16) + 3),
    //踢出群
    CCGroupAction_KickOutGroup = ((1LL<<16) + 4),
    //群信息更新
    CCGroupAction_UpdateGroupInfo = ((1LL<<16) + 7),
    //修改群
    CCGroupAction_ModifyGroup = ((1LL<<32) + 0),
    //修改群名称
    CCGroupAction_ModifyGroupName = ((1LL<<32) + 1),
    //修改群公告
    CCGroupAction_ModifyGroupNotice = ((1LL<<32) + 2),
    //修改群主
    CCGroupAction_ModifyGroupOwner = ((1LL<<32) + 3),
    //修改管理员
    CCGroupAction_ModifyGroupManager = ((1LL<<32) + 4),
    //修改群消息免打扰
    CCGroupAction_ModifyGroupReceiveMessageConfig = ((1LL<<32) + 5),
};

//组
typedef NS_ENUM(unsigned long long, CCDiscussGroupAction)
{
    //创建群组
    CCDiscussGroupAction_CreateDiscussGroup = ((1LL<<16) + 0),
    //加入群组
    CCDiscussGroupAction_JoinDiscussGroup = ((1LL<<16) + 1),
    //退出群组
    CCDiscussGroupAction_ExitDiscussGroup = ((1LL<<16) + 2),
    //解散群组
    CCDiscussGroupAction_DissolveDiscussGroup = ((1LL<<16) + 3),
    //修改群组名称
    CCDiscussGroupAction_ModifyDiscussGroupName = ((1LL<<32) + 1),
    //修改群组公告
    CCDiscussGroupAction_ModifyDiscussGroupNotice = ((1LL<<32) + 2),
    //修改群组消息免打扰
    CCDiscussGroupAction_ModifyDiscussGroupReceiveMessageConfig = ((1LL<<32) + 5),
};

@interface CCNotificationKeys : NSObject

+ (NSDictionary *)groupInfoObjectWithId:(NSString *)mId
                                 action:(unsigned long long)mAction value:(id)val;

+ (NSDictionary *)discussGroupInfoObjectWithId:(NSString *)mId
                                        action:(unsigned long long)mAction value:(id)val;

+ (NSDictionary *)messageNotificationObjectWithId:(NSString *)mId
                                           action:(unsigned long long)mAction value:(id)val;

@end

