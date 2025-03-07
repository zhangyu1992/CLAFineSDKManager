//
//  NSArray+Version.h
//  Net263CCLite_IOS
//
//  Created by yiyimama on 15/9/8.
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

@interface NSArray (CCNameSpace(Version))

#if (defined(__MAC_OS_X_VERSION_MAX_ALLOWED) && __MAC_OS_X_VERSION_MAX_ALLOWED < __MAC_10_9) || \
(defined(__IPHONE_OS_VERSION_MAX_ALLOWED) && __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_4_0)

- (id)firstObject NS_AVAILABLE(10_7, 4_0);

#endif

- (id)add_objectAtIndex:(NSUInteger)index;

@end

@interface NSMutableArray (Version)

- (void)add_addObject:(id)anObject;

- (id)add_objectAtIndex:(NSUInteger)index;

- (void)add_removeObjectAtIndex:(NSUInteger)index;

- (void)add_insertObject:(id)anObject atIndex:(NSUInteger)index;

- (void)add_replaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject;

//#if (defined(__MAC_OS_X_VERSION_MAX_ALLOWED) && __MAC_OS_X_VERSION_MAX_ALLOWED < 1090) || \
//(defined(__IPHONE_OS_VERSION_MAX_ALLOWED) && __IPHONE_OS_VERSION_MAX_ALLOWED < __IPHONE_6_0)

- (void)add_removeFirstObject; //NS_AVAILABLE(10_7, 6_0);

- (void)add_removeLastObject; //NS_AVAILABLE(10_7, 6_0);

//#endif

@end

//#endif

