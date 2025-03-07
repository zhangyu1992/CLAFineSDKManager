//
//  RTGuid.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/6/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTGuid : NSObject

//发出的消息参数中的ID必须是由此接口生成，登录后可使用
+ (NSString *)newMessageGuid;
//判断Guid是否有效，登录后可使用
+ (bool)messageGuidIsValid:(NSString*)Guid;

@end

NS_ASSUME_NONNULL_END
