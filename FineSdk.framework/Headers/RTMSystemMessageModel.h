//
//  RTMSystemMessageModel.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/6/25.
//

#import <Foundation/Foundation.h>
#import <FineSdk/RTMEnum.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTMSystemMessageModel : NSObject

@property (nonatomic, copy) NSString * roomid;
/**
 通知类型
 */
@property (nonatomic, assign) RTM_SyetemMessageType  messageType;

/**
 通知标题
 */
@property (nonatomic, copy) NSString * notificationTitle;

/**
 会议主题
 */
@property (nonatomic, copy) NSString * conferenceTitle;

/**
 收到通知的时间
 */
@property (nonatomic, copy) NSString * receiveTime;
// 消息时间
@property (nonatomic, copy) NSString * msgtime;
// 消息id
@property (nonatomic, copy) NSString * msgId;

@property (nonatomic, assign) long long receiveTimeValue;

/**
 是否已读
 */
@property (nonatomic, assign) BOOL isRead;
@property (nonatomic, assign) NSInteger  act;

@end

NS_ASSUME_NONNULL_END
