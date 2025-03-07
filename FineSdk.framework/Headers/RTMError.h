//
//  RTMError.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/6/18.
//

#import <Foundation/Foundation.h>
#import <CCAdapter/CCServiceTypes.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTMError : NSObject

@property (nonatomic, copy) NSString *  errorCode;
@property (nonatomic, copy) NSString * errorDescription;

+(instancetype)errorWithConstaneDescription:(NSString *)errorDescription;
+(instancetype)errorWithCommenCCCallState:(CCCallState)state;


@end

NS_ASSUME_NONNULL_END
