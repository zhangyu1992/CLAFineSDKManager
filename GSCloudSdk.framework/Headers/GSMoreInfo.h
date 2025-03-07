//
//  GSMoreInfo.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSMoreInfo : NSObject
@property(nonatomic, assign)NSInteger pageNum;
@property(nonatomic, assign)NSInteger pageSize;
@property(nonatomic, assign)NSInteger totalCounts;
@property(nonatomic, assign)NSInteger totalPages;
@end

NS_ASSUME_NONNULL_END
