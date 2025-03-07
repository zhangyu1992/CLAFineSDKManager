//
//  RTCUserPermission.h
//  FineSdk
//
//  Created by 张俞 on 2021/6/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// 用户账号配置类
@interface RTCUserPermission : NSObject
@property (nonatomic, copy) NSString * resolution;// 1080p   720p   360p
@property (nonatomic, assign) int resolutionWidth;//
@property (nonatomic, assign) int resolutionHeight;//

@property (nonatomic, assign) int multiview;// 合屏路数
@property (nonatomic, assign) int partyLimit;// 作为创建者最大方数
@property (nonatomic, assign) int record;//  1 有录制权限，0 无
@property (nonatomic, assign) int status;// 0 账号状态正常
@end

NS_ASSUME_NONNULL_END
