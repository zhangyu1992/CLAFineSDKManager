//
//  AMRAudioQueueBase.h
//  AudioQueuePlayerIOS
//
//  Created by YIYIMAMA on 15/8/31.
//  Copyright (c) 2015年 yiyimama. All rights reserved.
//

#ifndef _AMR_AUDIO_QUEUE_BASE_H_
#define _AMR_AUDIO_QUEUE_BASE_H_

#import "CCRuntime.h"
//#import "NSProcessInfo+Version.h"

@interface AMRAudioQueueBase : NSObject

@property (nonatomic, assign) NSOperatingSystemVersion ver;

//当前实例的回调状态队列，是否需要释放
//@property (nonatomic, assign) BOOL  isDelegateQueueFreeWhenDone;

@property (nonatomic, assign) void *IsCallOnDelegateOrTargetQueueKey;

//当前实例的回调状态队列
#if OS_OBJECT_USE_OBJC
@property (nonatomic, strong) dispatch_queue_t delegateCallbackQueue;
#else
@property (nonatomic, assign) dispatch_queue_t delegateCallbackQueue;
#endif

- (BOOL)isCallOnDelegateQueue;

//获得当前实例的回调状态队列
- (dispatch_queue_t)theDelegateCallbackQueue;

- (void)setDelegateQueue:(dispatch_queue_t)delegateQueue;

//当前实例的函数执行队列，是否需要释放
//@property (nonatomic, assign) BOOL  isDispatchQueueFreeWhenDone;

@property (nonatomic, assign) void *IsCallOnDispatchOrTargetQueueKey;

//当前实例的函数执行队列
#if OS_OBJECT_USE_OBJC
@property (nonatomic, strong) dispatch_queue_t dispatchCallbackQueue;
#else
@property (nonatomic, assign) dispatch_queue_t dispatchCallbackQueue;
#endif

- (BOOL)isCallOnDispatchQueue;

//当前实例的函数执行队列
- (dispatch_queue_t)theDispatchCallbackQueue;

- (void)setDispatchQueue:(dispatch_queue_t)dispatchQueue;

@end

#endif