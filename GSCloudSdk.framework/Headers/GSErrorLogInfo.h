//
//  GSErrorLogInfo.h
//  GSCloudSdk
//
//  Created by leo on 2022/11/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSErrorLogInfo : NSObject

/// 错误code
@property (nonatomic, assign) NSInteger code;
/// 错误级别
@property (nonatomic, copy) NSString *type;
/// 上报内容
@property (nonatomic, copy) NSString *message;


@end

NS_ASSUME_NONNULL_END
