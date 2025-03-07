//
//  CCAdapterTools.h
//  CCAdapter
//
//  Created by jinxiangkun on 2019/1/10.
//  Copyright © 2019年 jinxiangkun. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCObjectHeader.h"

#import "CCCommonMacroDefine.h"

// CCAdapterTools
@interface CCAdapterTools : NSObject

+ (NSArray *)callArrayModes;

//主线程调用block
+ (void)callOnMainThread:(dispatch_block_t)block;

// 计算缩放系数！
+ (float)scaleOfSize:(CGSize)scaleSize
             inFrame:(CGSize)frameSize;


//配置文件等公共文件存储路径
+ (NSString *)baseFilePath_Public;
//皮肤文件
+ (NSString *)baseFilePath_Interface;

//音频文件存储路径
+ (NSString *)baseFilePath_Voice;
//图像文件存储路径
+ (NSString *)baseFilePath_Picture;

//音频文件存储路径-重定向到用户目录
+ (NSString *)userFilePath_Voice;
//图像文件存储路径-重定向到用户目录
+ (NSString *)userFilePath_Picture;

//域名存储路径
+ (NSString *)filePathOfServerDomain:(NSString *)serverDomain;
//全局配置信息路径
+ (NSString *)filePathOfGolbalConfigWithUserAccount:(NSString *)userAcc;

+ (NSString *)description_with_class:(Class)cls instance:(id)inst;

@end

