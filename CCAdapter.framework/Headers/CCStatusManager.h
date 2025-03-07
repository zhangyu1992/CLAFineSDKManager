//
//  CCStatusManager.h
//  adapter
//
//  Created by yiyimama on 2017/5/23.
//  Copyright © 2017年 zsx. All rights reserved.
//

#ifndef _CCStatusManager_h_
#define _CCStatusManager_h_

#import <Foundation/Foundation.h>

#import "CCRuntime.h"

// 运行状态
enum CCStatusObjState
{
    //未运行
    CCStatusObjNone = 0,
    //执行运行中
    CCStatusObjRunning = 1,
    //执行完成失败
    CCStatusObjFailed = 2,
    //执行完成
    CCStatusObjComplete = 3,
    //执行状态超时
    CCStatusObjTimeout = 5,
};

@class CCNameSpace(CCStatusObj);
typedef void (^CCStatusObjCallBlock)\
(CCStatusObjState objState, CCNameSpace(CCStatusObj) * callObj);

@interface CCNameSpace(CCStatusObj) : NSObject

// 定时器的运行参数
@property (strong) NSString * strTag; //标识符
@property (assign) BOOL runCancel; //是否取消
@property (assign) NSInteger runState; //运行状态
// 用户数据的引用
@property (weak) id userObjectRef; //回调占用数据
// 用户数据的扩展容器
@property (strong) NSMutableDictionary * statusInfo; //扩展容器
// 操作的状态回调函数，当超时时回调指定的block
@property (assign) CCStatusObjCallBlock  statusCallbackBlock;

// 系统原生的状态指示器
#if (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE)
@property (weak) UIActivityIndicatorView * theIndicator;
#elif defined(TARGET_OS_MAC) && TARGET_OS_MAC
@property (weak) NSProgressIndicator     * theIndicator; //状态指示器
#endif

// 初始化一个带全局标识符的实例
- (instancetype)initWithIdentifier:(NSString *)strTag;

// 安装一个定时器的对像
- (void)beginStatusObjTimeout:(NSTimeInterval)ti
                       status:(CCStatusObjCallBlock)timeoutBlock;
// 系统原生的状态指示器
#if (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE)
- (void)beginStatusObjTimeout:(NSTimeInterval)ti
                       view:(UIActivityIndicatorView *)theIndicator
                     status:(CCStatusObjCallBlock)timeoutBlock;
#elif defined(TARGET_OS_MAC) && TARGET_OS_MAC
- (void)beginStatusObjTimeout:(NSTimeInterval)ti
                       view:(NSProgressIndicator    *)theIndicator
                     status:(CCStatusObjCallBlock)timeoutBlock;
#endif

// 手动调用定时器状态
- (void)invokeStatusObjWithState:(CCStatusObjState)statusObjState;

// 反安装一个定时器的对像
- (void)endStatusObjTimeoutWithState:(CCStatusObjState)statusObjState;

@end

//根据状态标识是否超时的帮助类

@interface CCNameSpace(CCStatusManager) : NSObject

// 获取共享单例
+ (instancetype)sharedInstance;

// 是否存在CCStatusObj对像实例
- (BOOL)hasStatusObjWithStringTag:(NSString *)strTag;

// 获得一个CCStatusObj对像实例状态，如果存在的话
- (CCStatusObjState)getStatusObjStateWithStringTag:(NSString *)strTag;

// 获得一个CCStatusObj对像实例，如果存在的话
- (CCNameSpace(CCStatusObj) *)getStatusObjWithStringTag:(NSString *)strTag;

// 移除一个CCStatusObj对像实例，如果存在的话
- (void)removeStatusObjWithStringTag:(NSString *)strTag;

// 添加一个CCStatusObj对像实例，如果不存在的话
- (CCNameSpace(CCStatusObj) *)resetStatusObjWithStringTag:(NSString *)strTag
                                                   status:(CCStatusObjCallBlock)timeoutBlock;

@end

#endif //_CCStatusManager_h_
