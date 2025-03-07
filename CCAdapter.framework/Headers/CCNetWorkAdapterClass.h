//
//  CCNetWorkAdapterClass.h
//  CCAdapter
//
//  Created by 张小鱼 on 2019/11/18.
//  Copyright © 2019 jinxiangkun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CCNetWorkAdapterClass : NSObject

/**
 get 请求

 @param URLString URL
 @param parameters 请求参数
 @param success 成功回调
 @param failure 失败回调
 */
+ (void)postRequestWithURL:(NSString *)URLString andHeader:(NSDictionary *)header ParametersDict:(NSDictionary *)parameters SuccessResponseObject:(void(^)(id responseObject))success Failure:(void(^)(NSError * error))failure;

+ (void)getRequestWithURL:(NSString *)URLString andHeader:(NSDictionary *)header ParametersDict:(NSDictionary *)parameters SuccessResponseObject:(void(^)(id responseObject))success Failure:(void(^)(NSError * error))failure;

+ (void)patchRequestWithURL:(NSString *)URLString andHeader:(NSDictionary *)header ParametersDict:(NSDictionary *)parameters SuccessResponseObject:(void(^)(id responseObject))success Failure:(void(^)(NSError * error))failure;
@end

NS_ASSUME_NONNULL_END
