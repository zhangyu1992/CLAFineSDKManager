//
//  GSHostSettingInfo.h
//  GSCloudSdk
//
//  Created by 张俞 on 2023/7/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSHostSettingInfo : NSObject
@property(nonatomic, copy) NSString * hostDefaultLayout;

@property(nonatomic, copy) NSString * hostUsersDuration;

@property(nonatomic, copy) NSString * hostUsersShow;

@property(nonatomic, copy) NSString * loginPageBackground;

@property(nonatomic, copy) NSString * oginPageLogo;

@property(nonatomic, copy) NSString * skin;

@property(nonatomic, copy) NSString * videoWall;
@end

NS_ASSUME_NONNULL_END
