//
//  CCSessionObject.h
//  NetMeetingCC
//
//  Created by jinxiangkun on 2019/1/3.
//  Copyright © 2019年 jinxiangkun. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCModelStruct.h"
#import "CCBaseObject.h"

@interface CCNameSpace(CCSessionObject) : CCNameSpace(CCSessionInfo) <NSCopying, NSMutableCopying>

// 浅复制目标的所有属性
- (BOOL)easyShallowCopy:(NSObject *)instance;

// 深复制目标的所有属性
- (BOOL)easyDeepCopy:(NSObject *)instance;

@property (nonatomic, assign) long long status;

@property (nonatomic, strong) NSString *sendingMsgId;

// 转换类型 CCSessionInfo
+ (CCNameSpace(CCSessionInfo) *)convertSessionInfoForObj:(CCNameSpace(CCSessionObject) *)obj;
// 转换类型 CCSessionObject
+ (CCNameSpace(CCSessionObject) *)convertSessionObjForInfo:(CCNameSpace(CCSessionInfo) *)info;

@end

