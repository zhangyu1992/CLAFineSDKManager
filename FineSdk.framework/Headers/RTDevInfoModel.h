//
//  RTDevInfoModel.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/6/10.
//

#import <Foundation/Foundation.h>
#import <FineSdk/RTMEnum.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTDevInfoModel : NSObject

///设备唯一标识
@property (nonatomic, copy) NSString *dev;
///设备类型
@property (nonatomic, assign) RT_DeviceType devt;

///登录时间
@property (nonatomic,assign) long long timestamp;
///登录或者退出
@property (nonatomic, assign) bool bOnLine;


@end

NS_ASSUME_NONNULL_END
