//
//  NSProcessInfo+Version.h
//  NSProcessInfoVersion
//
//  Created by YIYIMAMA on 15/8/5.
//  Copyright (c) 2015年 yiyimama. All rights reserved.
//

#import "CCRuntime.h"

#import <TargetConditionals.h>
#import <AvailabilityMacros.h>



#if (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE) || \
(defined(MAC_OS_X_VERSION_MAX_ALLOWED) && MAC_OS_X_VERSION_MAX_ALLOWED >= 1060)
#import <Availability.h>
#endif

#if (defined(__MAC_OS_X_VERSION_MAX_ALLOWED) && __MAC_OS_X_VERSION_MAX_ALLOWED < 101000) || \
(defined(__IPHONE_OS_VERSION_MAX_ALLOWED) && __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_8_0)

typedef struct {
    NSInteger majorVersion;
    NSInteger minorVersion;
    NSInteger patchVersion;
} NSOperatingSystemVersion;

#endif

@interface NSProcessInfo (CCNameSpace(Version)) // 重新定义函数声明

#if (defined(__MAC_OS_X_VERSION_MAX_ALLOWED) && __MAC_OS_X_VERSION_MAX_ALLOWED < 101000) || \
(defined(__IPHONE_OS_VERSION_MAX_ALLOWED) && __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_8_0)

- (NSOperatingSystemVersion)operatingSystemVersion __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);
- (BOOL)isOperatingSystemAtLeastVersion:(NSOperatingSystemVersion)version __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

#endif

@end
