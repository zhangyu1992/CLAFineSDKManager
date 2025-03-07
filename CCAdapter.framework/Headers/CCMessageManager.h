//
//  CCMessageManager.h
//  Net263CCLiteDemo_IOS
//
//  Created by xugw0711 on 16/12/15.
//  Copyright © 2016年 net263. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"

#import "CCMessageObject.h"

extern NSString * const CCDataOperationTypeKey;
extern NSString * const CCDataOperationNewObjectkey;
extern NSString * const CCDataOperationConditionKey;
extern NSString * const CCDataOperationUpdateValue;

/*
 *本地数据库操作
 */
typedef NS_ENUM(unsigned long long, CCDataOperationType)
{
    //新建
    CCDataOperationType_New = (1LL << 0),
    //删除
    CCDataOperationType_Delete = (1LL << 1),
    //修改
    CCDataOperationType_Update = (1LL << 2),
    //查询
    CCDataOperationType_Query = (1LL << 3),
};

/*
 *消息操作-服务端
 */
typedef NS_ENUM(unsigned long long, CCRemoteMessageOperationType)
{
    //发送消息
    CCRemoteMessageOperationType_Send = (1LL << 0),
    //删除消息
    CCRemoteMessageOperationType_Delete = (1LL << 1),
    //修改消息
    CCRemoteMessageOperationType_Update = (1LL << 2),
    //查询消息
    CCRemoteMessageOperationType_Query = (1LL << 3),
};

/*
 *会话操作-服务端
 */
typedef NS_ENUM(unsigned long long, CCRemoteSessionOperationType)
{
    //删除会话
    CCRemoteSessionOperationType_Delete = (1LL << 0),
    //未读数清0
    CCRemoteSessionOperationType_CleanUnreadNumber = (1LL << 1),
    //查询会话
    CCRemoteSessionOperationType_Query = (1LL << 2),
};


@interface CCMessageManager : NSObject

/*
 *共享实例
 */
+ (id)shareMessageManager;

/*
 *操作消息
 */
- (void)handleMessageWithParam:(NSMutableDictionary *)mParam;

/*
 *发送消息
 */
- (void)sendMessage:(CCNameSpace(CCMessageObject) *)message;

/*
 *发送消息，带附件的那种
 */
- (void)sendParamMessage:(CCNameSpace(CCMessageObject) *)message;

/*
 *更改本地消息
 */
- (void)updateMessageWithMessagID:(NSString *)msgID
                            param:(NSMutableDictionary *)mParam;

/*
 *查询本地消息 CCNameSpace(CCItemInfo) CCNameSpace(CCGetConfig)
 */
- (void)queryMessageWithParam:(NSMutableDictionary *)mParam
                       result:(void (^)(NSMutableArray *mResults))block;

/*
 *查询本地消息 CCNameSpace(CCItemInfo) CCNameSpace(CCGetConfig), 同步模式
 */
- (void)callQueryMessageWithParam:(NSMutableDictionary *)mParam
                       result:(void (^)(NSMutableArray *mResults))block;

/*
 *更改本地会话
 */
- (void)handleSessionWithParam:(NSMutableDictionary *)mParam
                     withBlock:(void (^)(NSInteger result, id obj1, id obj2))block;

/*
 *查询本地会话
 */
- (void)querySessionWithParam:(NSMutableDictionary *)mParam
                       result:(void (^)(NSMutableArray *mResults))block;


@end
