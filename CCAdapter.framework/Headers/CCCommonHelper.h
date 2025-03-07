//
//  CCCommonHelper.h
//  NetMeetingCC
//
//  Created by jinxiangkun on 2019/1/3.
//  Copyright © 2019年 jinxiangkun. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CCCommonHelper;
typedef CCCommonHelper CCCommon;

#define kUserAccount @"userAccount"  //账号
#define kUserPassWord @"userPassWord" //密码

//验证号码的正则
#define kInterNumberRegex @"^0{2}\\d{1,4}\\d{7,22}$"  //国际
#define kPhoneNumberRegex @"^(10|11|12|13|14|15|17|18|19)[0-9]{9}$"  //手机
#define kTeleNumberRegex  @"(^0{1}\\d{2,4}[-]?\\d{7,8}$)|(^0\\d{2,4}-?\\d{7,8}[-]\\d{1,4}$)"  //固话

struct CCUnreadMessageNumber
{
    NSInteger unreadSessionNum;
    NSInteger unreadWorkNum;
    NSInteger unreadAppNum;
};
typedef struct CCUnreadMessageNumber CCUnreadMessageNumber;

// ...
@interface CCCommonHelper : NSObject

// 屏幕分辨率
+ (CGRect)screenBounds;

// 创建全局唯一标识符
+ (NSString *)getUniqueIdentification;

+ (NSString *)getRightNum:(NSString *)setInNum;
+ (BOOL)check:(NSString *)phoneNumber;
+ (void)logput:(NSString*)txt;
+ (NSString *)generateUUID;
+ (NSString *)NSStringToMD5String:(NSString *)str;
+ (BOOL)isImageNull:(NSData *)data; //判断image图像是否为空

+(NSString *)stringToNull:(NSString *)str;
+(BOOL )isStringNull:(NSString *)str;
+(int)convertToInt:(NSString*)strtemp;

+(NSString *)convertSpecialStr:(NSString *)str; //转义字符的转化

+ (NSString *)getIPWithHostName:(const NSString*)hostName;
+ (NSMutableArray *)parserIPsWithHostName:(const NSString*)hostName;
+ (NSMutableArray *)parserDefaultPictureServerIps;
+ (NSMutableArray *)parserDefaultOfflineServerIPs;

+ (BOOL)isIPv4WithString:(NSString *)str;
+ (BOOL)isIPv6WithString:(NSString *)str;

+ (NSString *)base64Encoded:(NSData *)data;
+ (NSData *)base64Decoded:(NSData *)data;

+ (NSString *)getDeviceModelName;//设备信息
+ (NSString *)getDeviceSystemVersion; //系统版本
+ (float)getIOSVersion; //获取系统版本号
+ (NSString *)getdeviceIDFV; //获取唯一标识


@end
