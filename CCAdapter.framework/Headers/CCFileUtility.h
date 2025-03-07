//
//  CCFileUtility.h
//  Net263CCLite_IOS
//
//  Created by yiyimama on 16/4/15.
//  Copyright © 2016年 yiyimama. All rights reserved.
//

#ifndef _CC_COMMON_FILE_UTILITY_H_
#define _CC_COMMON_FILE_UTILITY_H_

#import "CCRuntime.h"

@interface CCNameSpace(CCFileUtility) : NSObject

// 文件是否存在
+ (BOOL)fileExistsAtPath:(NSString *)filePath;

// 文件是否存在，输出是否是目录
+ (BOOL)fileExistsAtPath:(NSString *)filePath
                isFolder:(BOOL *)isFolder;

// 文件夹是否存在，不是同名的文件
+ (BOOL)folderExistsAtPath:(NSString *)folderPath;

// 文件否存在，创建目录
+ (BOOL)createDirectoryAtPath:(NSString *)filePath;

// 文件是存在，删除目录
+ (BOOL)removeDirectoryAtPath:(NSString *)filePath;

// 单个文件的大小
+ (uint64_t)fileSizeAtPath:(NSString *)filePath;

// 遍历文件夹获得文件夹大小
+ (uint64_t)folderSizeAtPath:(NSString *)folderPath;

// 读取文件的映射数据
+ (NSData *)readMappedDataOfFile:(NSString *)filePath
                           error:(NSError **)error;

@end

#endif //_CC_COMMON_FILE_UTILITY_H_
