//
//  NSDictionary+Version.h
//  Net263CCLite_IOS
//
//  Created by yiyimama on 15/9/3.
//  Copyright (c) 2015年 263. All rights reserved.
//



#import <TargetConditionals.h>
#import <AvailabilityMacros.h>

#if (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE) || \
(defined(TARGET_OS_MAC) && MAC_OS_X_VERSION_MAX_ALLOWED >= 1060)
#import <Availability.h>
#endif

//#if defined(TARGET_OS_IPHONE) || defined(TARGET_OS_MAC)

#if !TARGET_OS_IPHONE
#import <AppKit/AppKit.h>
#import <AppKit/NSViewController.h>
#else
#include <Foundation/NSObjCRuntime.h>
#endif

@interface NSMutableDictionary (CCNameSpace(Version))

- (void)add_setObject:(id)obj forKey:(id<NSCopying>)key;

- (void)add_removeObjectForKey:(id)aKey;

- (void)add_setObject:(id)obj forKeyedSubscript:(id <NSCopying>)key;

#if (defined(__MAC_OS_X_VERSION_MAX_ALLOWED) && __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_10) || \
(defined(__IPHONE_OS_VERSION_MAX_ALLOWED) && __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_6_0)

- (void)setObject:(id)obj forKeyedSubscript:(id <NSCopying>)key NS_AVAILABLE(10_7, 6_0);

#else

#endif

@end

//#endif
