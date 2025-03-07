//
//  CCThreadQueue.h
//  Net263CCLite_IOS
//
//  Created by yiyimama on 15/11/18.
//  Copyright © 2015年 yiyimama. All rights reserved.
//

#ifndef _EM_WEBCAST_QUEUE_BASE_H_
#define _EM_WEBCAST_QUEUE_BASE_H_

#import "CCRuntime.h"

#if 0
dispatch_queue_t
dispatch_get_main_queue(void);

dispatch_queue_t
dispatch_get_current_queue(void);

const char * // queueName
dispatch_queue_get_label(dispatch_queue_t queue);
#endif

//queue carsh with no breakpoint

@class CCNameSpace(CCThreadQueue);

typedef CCNameSpace(CCThreadQueue) CC263ThreadQueue;

@interface CCNameSpace(CCThreadQueue) : NSObject

@property (nonatomic, strong) NSString * queueName;

@property (nonatomic, assign) NSOperatingSystemVersion ver;

//@property (nonatomic, strong) NSThread * dispatchThread;

- (instancetype)initWithQueueName:(NSString *)queueName;

- (dispatch_queue_t)defualtDispatchQueue;

- (BOOL)isCallOnDispatchQueue;

//当前实例的函数执行队列
- (dispatch_queue_t)theDispatchCallbackQueue;

- (BOOL)isDispatchQueueIsNotNULL;

//[self setDispatchQueue:[self defualtDispatchQueue]];

- (void)setDispatchQueue:(dispatch_queue_t)dispatchQueue;

- (void)cleanDispatchQueue;

//调用在主线程调用执行
- (void)callInAsyncMainQueue:(dispatch_block_t)callBlock;

//调用在当前调用执行队列
- (void)callInDispatchQueue:(dispatch_block_t)callBlock; //only call

//调用在当前调用执行队列，完成后回调返回的队列
- (void)callInDispatchQueue:(dispatch_block_t)callBlock
                finishBlock:(dispatch_block_t)finishBlock
                finishQueue:(dispatch_queue_t)finishQueue; //if nil do main queue

//调用在当前调用执行队列
- (void)postInDispatchQueue:(dispatch_block_t)callBlock; //post call

//调用在当前调用执行队列，完成后回调返回的队列
- (void)postInDispatchQueue:(dispatch_block_t)callBlock
                finishBlock:(dispatch_block_t)finishBlock
                finishQueue:(dispatch_queue_t)finishQueue; //if nil do main queue

@end

#endif //_EM_WEBCAST_QUEUE_BASE_H_