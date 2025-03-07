//
//  CCRuntime.h
//  Net263CCLite_IOS
//
//  Created by yiyimama on 16/1/18.
//  Copyright © 2016年 263. All rights reserved.
//

#ifndef _CC_RUNTIME_H_
#define _CC_RUNTIME_H_

#import <objc/runtime.h>
#import <Availability.h>
#import <AvailabilityMacros.h>
#import <TargetConditionals.h>

#if (defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE)
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#elif defined(TARGET_OS_MAC) && TARGET_OS_MAC
#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#import <AppKit/AppKit.h>
#endif

#if 0x0
#if __has_feature(objc_arc)
#define retain self
#define dealloc self
#define release self
#define autorelease self
#else
//#define retain retain
//#define dealloc dealloc
//#define autorelease autorelease
#define __bridge
#endif
#endif //0x0

//#pragma mark -
#pragma mark - namespace

// class命名空间
#define CCNameSpace(className) \
      className
//    CC263_##className
// class命名空间
#define CC(className) CCNameSpace(className)

// global变量命名空间
#define CCNameSpaceVar(className) \
    CCNameSpace(className)
// global变量命名空间
#define CCV(className) CCNameSpaceVar(className)

// global函数命名空间
#define CCNameSpaceFunc(className) \
    CCNameSpace(className)
// global函数命名空间
#define CCF(className) CCNameSpaceFunc(className)

// const前缀名称，不带双引号
#define CCNameSpaceStr(symbolName) \
        symbolName
//    "CC263_"#symbolName //
//    "CC263_"###symbolName //vc
// const前缀名称，不带双引号
#define CCNameSpaceStrObj(symbolName) \
        symbolName
//    @"CC263_"#symbolName //

//#pragma mark -
#pragma mark - arc mrc

// //-fobjc-arc //-fno-objc-arc

#ifndef __has_feature      // Optional.
// Compatibility with non-clang compilers.
#define __has_feature(x) 0
#endif

#if __has_feature(objc_arc)

//ARC模式
//-fobjc-arc
#define CCRetain(__v)
#define CCReturnRetained(__v) (__v)
#define CCAutorelease(__v)
#define CCReturnAutoreleased(__v) (__v)
#define CCRelease(__v)
#define CCReleaseToNull(__v) (__v = nil)
#define CCSuperDealloc(__v)

#else 

//非ARC模式
//-fno-objc-arc
#define CCRetain(__v) ([__v retain])
#define CCReturnRetained ([__v retain])
#define CCAutorelease(__v) ([__v autorelease])
#define CCReturnAutoreleased(__v) ([__v autorelease])
#define CCRelease(__v) ([__v release])
#define CCReleaseToNull(__v) ([__v release], __v = nil)
#define CCSuperDealloc(__v) ([super dealloc])
//#define CCDispatchQueueRelease(__v) (dispatch_release(__v))

#endif

#if !__has_feature(objc_instancetype)
#define instancetype id // type instancetype == id
#endif

//  Weak reference support

//#import <Availability.h>

#if (!__has_feature(objc_arc)) || \
(defined(__IPHONE_OS_VERSION_MIN_REQUIRED) &&  \
    __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_0) || \
(defined(__MAC_OS_X_VERSION_MIN_REQUIRED) && \
    __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_7)
#undef weak
#define weak unsafe_unretained
#undef __weak
#define __weak __unsafe_unretained
#endif


//#pragma mark -
#pragma mark - dispatch queue

/*
 If OS_OBJECT_USE_OBJC=1,
 then the dispatch objects will be treated like ObjC objects and will participate in ARC.
 See the section on "Dispatch Queues and Automatic Reference Counting" in 
 "Grand Central Dispatch (GCD) Reference" for details.
 */
#if OS_OBJECT_USE_OBJC
#define CCDispatchQueueRelease(__v)
#else
#define CCDispatchQueueRelease(__v) (dispatch_release(__v))
#endif

//#pragma mark -
#pragma mark - object-c pointer

// 对象转换指针
#define CCCastPointer(type, value) ((__bridge type)value)
// 指针转换对象
#define CCCastObject(type, value) ((__bridge_transfer type)value)

//#pragma mark -
#pragma mark - value bits operational

// 位运算标志宏
#ifndef AddBits
#define AddBits(status,flags) \
    (long long)((long long)status|(long long)flags)
#define CCSetAddBits(status, flags) \
    status = (long long)((long long)status|(long long)flags)
#endif
#ifndef DelBits
#define DelBits(status,flags) \
    (long long)((long long)status&(~(long long)flags))
#define CCSetDelBits(status, flags) \
    status = (long long)((long long)status&(~(long long)flags))
#endif
#ifndef HasBits
#define HasBits(status,flags) \
    ((long long)flags==((long long)status&(long long)flags))
#define CCGetHasBits(status, flags) HasBits(status,flags) // test bits
#endif

#endif /*_CC_RUNTIME_H_*/
