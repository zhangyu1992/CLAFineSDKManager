//
//  CCMessageTypeUtility.h
//  CCAdapterUI
//
//  Created by yiyimama on 2017/5/25.
//  Copyright © 2017年 yiyimama. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
#import "CCAdapterBase.h"
#import "CCAdapterClass.h"

@interface CCMessageTypeUtility : NSObject

// 创建一个接收消息返回的确认消息
// (CCNameSpace(CCMessageSendAck) *)
+ (id)receiveSendAckObject:(CCNameSpace(CCMessageResult) *)theObject;

// 获得消息的原始ID
+ (NSString *)getMessageObjectID:(CCNameSpace(CCMessageResult) *)theObject;


@end
