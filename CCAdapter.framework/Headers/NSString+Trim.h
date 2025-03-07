//
//  NSString+Trim.h
//  EMNetMeeting_iPhone
//
//  Created by yiyimama on 16/2/25.
//  Copyright © 2016年 263. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Trim)

+ (NSString *)trim:(NSString *)val //去掉前后字符
  trimCharacterSet:(NSCharacterSet *)characterSet;
+ (NSString *)trimLeft:(NSString *)val //去掉前字符
      trimCharacterSet:(NSCharacterSet *)characterSet;
+ (NSString *)trimRight:(NSString *)val //去掉后字符
       trimCharacterSet:(NSCharacterSet *)characterSet;

+ (NSString *)trimWhitespace:(NSString *)val; //去掉前后空格
+ (NSString *)trimLeftWhitespace:(NSString *)val; //去掉前空格
+ (NSString *)trimRightWhitespace:(NSString *)val; //去掉后空格

+ (NSString *)trimNewline:(NSString *)val; //去掉前后回车符
+ (NSString *)trimLeftNewline:(NSString *)val; //去掉前回车符
+ (NSString *)trimRightNewline:(NSString *)val; //去掉后回车符

+ (NSString *)trimWhitespaceAndNewline:(NSString *)val; //去掉前后空格和回车符
+ (NSString *)trimLeftWhitespaceAndNewline:(NSString *)val; //去掉前空格和回车符
+ (NSString *)trimRightWhitespaceAndNewline:(NSString *)val; //去掉后空格和回车符


@end
