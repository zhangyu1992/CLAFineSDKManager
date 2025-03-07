//
//  GSLiveConfInfo.h
//  GSCloudSdk
//
//  Created by leo on 2022/10/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSLiveConfInfo : NSObject
/// 直播id
@property(nonatomic, assign)NSInteger webcastId;
/// 场次id
@property(nonatomic, assign)NSInteger confId;
/// 观看人数
@property(nonatomic, assign)NSInteger audienceConcurrent;

@end

NS_ASSUME_NONNULL_END
