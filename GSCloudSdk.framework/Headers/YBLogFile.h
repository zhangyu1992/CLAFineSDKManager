//
//  YBLogFile.h
//  CFHttp
//
//  Created by net263 on 2022/3/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YBLogFile : NSObject
/**
 单例模式
 */
+ (YBLogFile*)shareInstance;

/*
 需要先调用这个方法，将日记重定向到日记文件
 **/
- (void)redirectLogToFile;
/**
 报告诊断信息
 */
- (void)reportDiagonse;
@end

NS_ASSUME_NONNULL_END
