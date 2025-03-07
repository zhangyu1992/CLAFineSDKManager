//
//  CCCommonConfim.h
//  CCAdapterUI
//
//  Created by yiyimama on 2017/6/9.
//  Copyright © 2017年 yiyimama. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"

@interface CCCommonConfim : NSObject

//单例管理对像
+ (id)shareInstance;

// 获得用户的缓存对像
@property (nonatomic, strong) NSMutableDictionary * mCachedInfos;

// 获得用户的群组缓存对像
@property (nonatomic, strong) NSMutableDictionary * mGroupCachedInfos;

// 获得用户的群组队列键值
+ (NSString *)cachedKey:(NSString *)idStr
                    cid:(NSString *)cidStr;

// 获得用户的缓存对像队列
- (NSDictionary *)cachedInfos:(NSString *)idStr
                          cid:(NSString *)cidStr;

// 获得用户的群组的缓存对像队列
- (NSDictionary *)cachedGroupInfos:(NSString *)idStr
                               cid:(NSString *)cidStr;

// 发送消息数据的缓存列表，确认是否发送消息的命令成功！
@property (nonatomic, strong) NSMutableDictionary * mSendActionInfos;

// 发送消息数据的缓存列表，确认是否发送消息的命令成功！
@property (nonatomic, strong) NSMutableDictionary * mGroupSendActionInfos;

// 添加一个定时器的测试对像
- (void)addTimeOutWithUuid:(NSString *)uuidStr
                      time:(NSTimeInterval)timeInterval
                    target:(id)target action:(SEL)selector
                  userInfo:(id)userObject;

// 移除一个定时器的测试对像
- (void)delTimeOutWithUuid:(NSString *)uuidStr;


// 缓存群组发送对像的状态
- (void)addGroupMethodWithUuid:(NSString *)uuidStr
                   commandType:(NSInteger)commandType
                    sendObject:(id)requestInfo;

// 缓存群组发送对像的状态
- (void)addGroupMethodWithUuid:(NSString *)uuidStr
                   commandType:(NSInteger)commandType
                    sendObject:(id)requestInfo
                  actionObject:(id)actionObject;

// 获得群组发送对像的状态
- (NSDictionary *)getGroupMethodWithUuid:(NSString *)uuidStr;

// 收到回复后，删除群组发送对像的状态
- (NSDictionary *)delGroupMethodWithUuid:(NSString *)uuidStr
                             commandType:(NSInteger)commandType
                              recvObject:(id)responseInfo;

@end
