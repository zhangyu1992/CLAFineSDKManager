//
//  ObjectCHelper.h
//  NSProcessInfoVersion
//
//  Created by YIYIMAMA on 15/8/5.
//  Copyright (c) 2015年 yiyimama. All rights reserved.
//

#ifndef _OBJECT_C_HELPER_H_
#define _OBJECT_C_HELPER_H_

#import "CCRuntime.h"

#import <CoreFoundation/CoreFoundation.h>

#define DEBUGLOG (0x1)

#if defined(DEBUG) && DEBUG
#define NSASSERTLOG (0x1)
#else
#define NSASSERTLOG (0x0)
#endif

//OBJC_EXPORT BOOL class_respondsToSelector(Class cls, SEL sel)
//    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

CF_INLINE
BOOL
CCNameSpace(class_hasInstanceMethod)
(Class clazz, SEL realSelector)
{
    return (class_respondsToSelector(clazz, realSelector));
}

//OBJC_EXPORT BOOL class_addMethod(Class cls, SEL name, IMP imp,
//                                 const char *types)
//    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

CF_INLINE
void
CCNameSpace(class_addInstanceMethod)
(Class clazz, SEL realSelector, SEL fakeSelector)
{
    if (!class_getInstanceMethod(clazz, realSelector))
    {
        Method method =
        class_getInstanceMethod(clazz, fakeSelector);
        
        if (!class_addMethod(clazz, realSelector,
                             method_getImplementation(method),
                             method_getTypeEncoding(method)))
        {
#if defined(DEBUG) && DEBUG && DEBUGLOG
            NSLog(@"\n class_addMethod:"
                  @"\n error adding -[%@ %@]"
                  @"\n (-[%@ %@])",
                  NSStringFromClass(clazz), NSStringFromSelector(fakeSelector),
                  NSStringFromClass(clazz), NSStringFromSelector(realSelector));
#endif
        } else {
#if defined(DEBUG) && DEBUG && DEBUGLOG
            NSLog(@"\n class_addMethod:"
                  @"\n added -[%@ %@]"
                  @"\n (-[%@ %@])",
                  NSStringFromClass(clazz), NSStringFromSelector(fakeSelector),
                  NSStringFromClass(clazz), NSStringFromSelector(realSelector));
#endif
        }
    }
    else {
#if defined(DEBUG) && DEBUG && DEBUGLOG
        NSLog(@"\n class_getInstanceMethod:\n "
              @"skipped adding -[%@ %@]"
              @"\n (-[%@ %@]); already exists",
              NSStringFromClass(clazz), NSStringFromSelector(fakeSelector),
              NSStringFromClass(clazz), NSStringFromSelector(realSelector));
#endif
    }
}

//OBJC_EXPORT IMP class_replaceMethod(Class cls, SEL name, IMP imp,
//                                    const char *types)
//    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

CF_INLINE
BOOL
CCNameSpace(class_resetInstanceMethod)
(Class clazz, SEL realSelector, SEL fakeSelector)
{
    if (!class_getInstanceMethod(clazz, realSelector))
//  if (!CCNameSpace(class_hasInstanceMethod)(clazz, realSelector))
    {
        // not has, add Method !
        CCNameSpace(class_addInstanceMethod)
        (clazz, realSelector, fakeSelector);
        
        return
        CCNameSpace(class_hasInstanceMethod)(clazz, realSelector);
    }
    else {
        Method method =
        class_getInstanceMethod(clazz, fakeSelector);
        if (!class_replaceMethod(clazz, realSelector,
                                 method_getImplementation(method),
                             method_getTypeEncoding(method)))
        {
#if defined(DEBUG) && DEBUG && DEBUGLOG
            NSLog(@"\n class_replaceMethod:"
                  @"\n error replace -[%@ %@]"
                  @"\n (-[%@ %@])",
                  NSStringFromClass(clazz), NSStringFromSelector(fakeSelector),
                  NSStringFromClass(clazz), NSStringFromSelector(realSelector));
#endif
            return false;
        }
        else {
#if defined(DEBUG) && DEBUG && DEBUGLOG
            NSLog(@"\n class_replaceMethod:"
                  @"\n replaced -[%@ %@]"
                  @"\n (-[%@ %@])",
                  NSStringFromClass(clazz), NSStringFromSelector(fakeSelector),
                  NSStringFromClass(clazz), NSStringFromSelector(realSelector));
#endif
            return true;
        }
    }
}

#endif //_OBJECT_C_HELPER_H_
