//
//  CCBaseObject.h
//  NetMeetingCC
//
//  Created by jinxiangkun on 2019/1/3.
//  Copyright © 2019年 jinxiangkun. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"

@interface CCNameSpace(CCBaseObject) : NSObject <NSCopying, NSMutableCopying>

/**
 *  浅复制目标的所有属性
 *  @param instance 目标对象
 *  @return BOOL—YES:复制成功,NO:复制失败
 */
- (BOOL)easyShallowCopy:(NSObject *)instance;

/**
 *  深复制目标的所有属性
 *  @param instance 目标对象
 *  @return BOOL—YES:复制成功,NO:复制失败
 */
- (BOOL)easyDeepCopy:(NSObject *)instance;


@end

