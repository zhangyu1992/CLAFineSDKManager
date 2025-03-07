//
//  MtBaseSeriaQueue.h
//  ZNetMeeting
//
//  Created by jinxiangkun on 2018/12/6.
//  Copyright © 2018年 jinxiangkun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCObjectHeader.h"

@interface MtBaseSeriaQueue : NSObject

#if OS_OBJECT_USE_OBJC
@property (nonatomic, strong) dispatch_queue_t serialQueue;
#else
@property (nonatomic, assign) dispatch_queue_t serialQueue;
#endif
@property (nonatomic, assign) void * IsCallOnSeriaOrTargetQueueKey; //test key

//主线程调用block
- (void)callOnMainThread:(dispatch_block_t)block;

// 重新设置线程调用队列
- (void)resetSeriaQueue:(dispatch_queue_t)dispatchQueue;
//是否在当前的调用执行队列
- (BOOL)isCallOnSerialQueue;
//调用在当前调用执行队列
- (void)callInSerialQueue:(dispatch_block_t)callBlock;
//调用在当前调用执行队列
- (void)postInSerialQueue:(dispatch_block_t)callBlock;

@end
