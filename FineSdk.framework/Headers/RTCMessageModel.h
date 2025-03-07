//
//  RTCMessageModel.h
//  FineSdk
//
//  Created by 张俞 on 2021/7/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCMessageModel : NSObject

@property (nonatomic, copy) NSString * participantId;

@property (nonatomic, copy) NSString * participantName;
@property (nonatomic, copy) NSString * messageContent;

@property (nonatomic, assign) RTCMessageStatus messageStatus;
@property (nonatomic, copy) NSString *msgId;

@end

NS_ASSUME_NONNULL_END
