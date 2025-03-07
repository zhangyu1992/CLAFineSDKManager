//
//  GSTokenParam.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/11.
//

#import <Foundation/Foundation.h>
#import <GSCloudSdk/GSJoinParam.h>
NS_ASSUME_NONNULL_BEGIN

@interface GSTokenParam : GSJoinParam
@property(nonatomic, copy)NSString *passCode;//直播口令

@end

NS_ASSUME_NONNULL_END
