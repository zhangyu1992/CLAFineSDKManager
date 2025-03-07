//
//  GSUserOnlineInfo.h
//  GSCloudSdk
//
//  Created by 张俞 on 2023/6/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSUserOnlineInfo : NSObject

@property(nonatomic, copy) NSString *userId;
@property(nonatomic, copy) NSString *webcastId;
@property(nonatomic, copy) NSString *confId;
@property(nonatomic, copy) NSString *onlineTimeSum;
@property(nonatomic, copy) NSString *historicalOnlineTime;
@property(nonatomic, copy) NSString *systemTime;
@property(nonatomic, copy) NSString *userLastJoinTime;

@end

NS_ASSUME_NONNULL_END
