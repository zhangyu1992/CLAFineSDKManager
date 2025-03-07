//
//  NSObject+EasyCopy.h
//  NSObject-EasyCopy
//
//  Created by xugw0711 on 16/12/15.
//  Copyright © 2016年 xugw0711. All rights reserved.
//

#import <Foundation/Foundation.h>

// a copy category for NSObject 
@interface NSObject (EasyCopy)

/**
 *  浅复制目标的所有属性
 *
 *  @param instance 目标对象
 *
 *  @return BOOL—YES:复制成功,NO:复制失败
 */
- (BOOL)easyShallowCopy:(NSObject *)instance;

/**
 *  深复制目标的所有属性
 *
 *  @param instance 目标对象
 *
 *  @return BOOL—YES:复制成功,NO:复制失败
 */
- (BOOL)easyDeepCopy:(NSObject *)instance;

@end
