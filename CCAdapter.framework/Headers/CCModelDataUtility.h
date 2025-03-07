//
//  CCModelDataUtility.h
//  adapter
//
//  Created by yiyimama on 17/4/7.
//  Copyright © 2017年 zsx. All rights reserved.
//

#ifndef _CC_CCDataModel_DataUtility_H_
#define _CC_CCDataModel_DataUtility_H_

#import <Foundation/Foundation.h>

#import <assert.h>

#import "CCModelBase.h"
#import "CCModelMethod.h"
#import "CCModelMessage.h"

// 生成消息的发送与回复ID
#define CCGetCurrentDatetime() \
([[NSDate date] timeIntervalSince1970] * 1000)

// 生成消息的发送与回复ID
static inline
NSString * CCGetUniqueIdentification()
{
    CFUUIDRef uuidObj = CFUUIDCreate(nil);
    CFStringRef strRef = CFUUIDCreateString(nil, uuidObj);
    NSString * identification =
    [NSString stringWithFormat:@"%@",
     (__bridge NSString *)strRef];
    identification = [identification lowercaseString];
    CFRelease(uuidObj);
    CFRelease(strRef);
    return identification;
}

@interface CCNameSpace(CCModelDataUtility) : NSObject


// 为了维护session使用的临时对像
+ (CCNameSpace(CCSessionInfo) *)
SessionFromSendBodyObject:(CCNameSpace(CCMessageSendChat) *)sendObject;

// 为了维护session使用的临时对像
+ (CCNameSpace(CCSessionInfo) *)
SessionFromReceiveMessage:(CCNameSpace(CCMessageResult) *)readObject;

// 为了维护session使用的临时对像
+ (CCNameSpace(CCMessageChatInfo) *)
ChatInfoFromSendBodyObject:(CCNameSpace(CCMessageSendChat) *)sendObject;

// 为了维护session使用的临时对像
+ (CCNameSpace(CCMessageChatInfo) *)
ChatInfoFromReceiveMessage:(CCNameSpace(CCMessageResult) *)readObject;

// 有接收到消息时，转换为确认回复对像
+ (CCNameSpace(CCMessageSendAck) *)
ReplyAckFromReceiveMessage:(CCNameSpace(CCMessageRecvResult) *)result;

// 查询历史消息
// 有发送失败数据时，转换为发送对像再次发送
+ (CCNameSpace(CCMessageSendChat) *)
SendObjectFromSendFailedInfo:(CCNameSpace(CCMessageChatInfo) *)failedObject;


@end


#endif //_CC_CCDataModel_DataUtility_H_
