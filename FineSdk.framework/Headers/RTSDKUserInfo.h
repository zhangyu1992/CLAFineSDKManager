//
//  RTSDKUserInfo.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/6/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTSDKUserInfo : NSObject

@property (nonatomic, copy) NSString *uid;
@property (nonatomic, copy) NSString *cid;
@property (nonatomic, copy) NSString *sid;
@property (nonatomic, copy) NSString *userName;
@property (nonatomic, copy) NSString *passwd;
@property (nonatomic, copy) NSString *account;

@property (nonatomic, copy) NSString *mobile;


@end

NS_ASSUME_NONNULL_END
