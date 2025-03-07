//
//  GSMessage.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSMessage : NSObject
@property(nonatomic, copy)NSString *msgId;
@property(nonatomic, copy)NSString *content; //json字符串
@end

NS_ASSUME_NONNULL_END
