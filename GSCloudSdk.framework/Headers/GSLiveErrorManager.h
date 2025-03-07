//
//  GSLiveErrorManager.h
//  GSCloudSdk
//
//  Created by leo on 2022/11/17.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN
@class GSLiveCore;


@interface GSLiveErrorManager : NSObject

///初始化
+ (instancetype)sharedErrorManager;

///应用层不需要调用
- (void)setLiveCore:(GSLiveCore *)liveCore;

///设置 n 个为一组，向服务器发送一次，默认 10
- (void)setLogPageSize:(int)size;

///缓存的日志上限，默认 1000 条
- (void)setLogMaxSize:(int)size;

///添加日志
- (void)addErrorLog:(GSErrorLogInfo *)log;


@end

NS_ASSUME_NONNULL_END
