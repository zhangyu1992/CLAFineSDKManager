//
//  CCThreadManager.h
//  Net263CCLite_IOS
//
//  Created by yiyimama on 15/11/18.
//  Copyright © 2015年 yiyimama. All rights reserved.
//

#ifndef _EM_DISPATCH_THREAD_UTIL_H_
#define _EM_DISPATCH_THREAD_UTIL_H_

#import "CCRuntime.h"

// 投递到主线程执行
#define dispatch_async_main_queue(b) \
[CCNameSpace(CCThreadManager) \
 callInMainThread:(dispatch_block_t)b]

// 投递到指定线程执行
//#define dispatch_thread_async(t,b) \
//[[CCNameSpace(CCThreadManager) sharedInstance] \
// callBlockInThread:(dispatch_block_t)b \
// thread:(NSThread *)t waitUntilDone:(BOOL)NO]

//thread carsh with breakpoint
//[[CCNameSpace(CCThreadManager) sharedInstance]
// callBlockInThread:(dispatch_block_t)^{ }
// thread:(NSThread *)thread waitUntilDone:(BOOL)NO];

@interface CCNameSpace(CCThreadManager) : NSObject

//+ (instancetype)share;
+ (instancetype)sharedInstance;

// 工作事件模式
+ (NSArray *)callArrayModes;

// 选择块在主线程执行
+ (BOOL)callInMainThread:(dispatch_block_t)block;

// 选择块在主线程执行, 主线程不能阻塞
//+ (BOOL)callInMainThread:(dispatch_block_t)block
//           waitUntilDone:(BOOL)waitUntilDone;

// 获得一个线程实例
- (NSThread *)dispatchNewThread:(NSString *)threadName;

// 退出并删除线程
- (void)exitThreadWithName:(NSString *)threadName;

// 线程是否在执行
- (BOOL)isRunningByName:(NSString *)threadName;

// 调用是否在线程执行
- (BOOL)isCallOnThreadByName:(NSString *)threadName;

// 通过名字获得线程实例
- (NSThread *)getThreadWithName:(NSString *)threadName;

// 选择块在线程执行
- (BOOL)callBlockInThread:(dispatch_block_t)block
               threadName:(NSString *)threadName;

// 选择块在线程执行
- (BOOL)callBlockInThread:(dispatch_block_t)block
               threadName:(NSString *)threadName
            waitUntilDone:(BOOL)waitUntilDone;

// 选择块在主线程执行
- (BOOL)callBlockInMainThread:(dispatch_block_t)block;

// 选择块在主线程执行
- (BOOL)callBlockInMainThread:(dispatch_block_t)block
                waitUntilDone:(BOOL)waitUntilDone;

// 选择块在线程执行
- (BOOL)callBlockInThread:(dispatch_block_t)block
                   thread:(NSThread *)aThread
            waitUntilDone:(BOOL)waitUntilDone;

// 投递块到线程执行
- (BOOL)performBlockOnThread:(dispatch_block_t)block
                  threadName:(NSString *)threadName
               waitUntilDone:(BOOL)waitUntilDone;

// 投递块到线程执行，由target触发
- (BOOL)performBlockOnThread:(dispatch_block_t)block
                      target:(id)target//self
                  threadName:(NSString *)threadName
               waitUntilDone:(BOOL)waitUntilDone;

// 投递块到线程执行，由target触发
- (BOOL)performBlockOnThread:(dispatch_block_t)block
                      target:(id)target//self
                      thread:(NSThread *)aThread
               waitUntilDone:(BOOL)waitUntilDone;

// 选择选择器在线程执行
- (BOOL)callSelectorInThread:(SEL)aSelector
                      target:(id)target
                  threadName:(NSString *)threadName
                  withObject:(id)aObject;

// 选择选择器在线程执行
- (BOOL)callSelectorInThread:(SEL)aSelector
                      target:(id)target
                  threadName:(NSString *)threadName
                  withObject:(id)aObject
               waitUntilDone:(BOOL)waitUntilDone;

// 投递选择器到线程执行，由target触发
- (BOOL)performSelectorOnThread:(SEL)aSelector
                         target:(id)target
                     threadName:(NSString *)threadName
                     withObject:(id)aObject
                  waitUntilDone:(BOOL)waitUntilDone;

// 选择选择器在线程执行
- (BOOL)callSelectorInThread:(SEL)aSelector
                      target:(id)target
                      thread:(NSThread *)aThread
                  withObject:(id)aObject
               waitUntilDone:(BOOL)waitUntilDone;

// 投递选择器到线程执行，由target触发
- (BOOL)performSelectorOnThread:(SEL)aSelector
                         target:(id)target
                         thread:(NSThread *)aThread
                     withObject:(id)aObject
                  waitUntilDone:(BOOL)waitUntilDone;


//@interface CCNameSpace(CCThreadManager) (Notification)

// 投递通知实例
- (void)postNotification:(NSNotification *)notification;

// 投递通知实例到某个线程
- (void)postNotificationWithName:(NSNotification *)notification
                        onThread:(NSThread *)postThread
                   waitUntilDone:(BOOL)wait;

// 投递通知实例到主线程
- (void)postNotificationOnMainThread:(NSNotification *)notification
                       waitUntilDone:(BOOL) wait;

// 投递通知名称与对像参数
- (void)postNotificationName:(NSString *)name
                      object:(id)object
                    userInfo:(NSDictionary *)userInfo;

// 投递通知名称与对像参数到某个线程
- (void)postNotificationWithName:(NSString *)name
                        onThread:(NSThread *)postThread
                          object:(id)object
                        userInfo:(NSDictionary *)userInfo
                   waitUntilDone:(BOOL)wait;

// 投递通知名称与对像参数到主线程, 投递主线程
- (void)postNotificationOnMainThread:(NSString *)name
                              object:(id)object
                            userInfo:(NSDictionary *)userInfo
                       waitUntilDone:(BOOL)wait;

@end

#endif //_EM_DISPATCH_THREAD_UTIL_H_