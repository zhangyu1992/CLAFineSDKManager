//
//  GSShareInfo.h
//  GSCloudSdk
//
//  Created by 张俞 on 2022/5/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// 共享流类型
typedef enum : NSUInteger {
    /// 屏幕共享
    GSShareType_Screen,
    /// 插播共享
    GSShareType_Media,

} GSShareType;

@interface GSShareInfo : NSObject
///共享流类型 屏幕 、插播
@property (nonatomic, assign) GSShareType shareType;

///共享id
@property (nonatomic, copy) NSString * userID;
/// 是不是自己的流
@property (nonatomic, assign) BOOL isSelf;

@end

NS_ASSUME_NONNULL_END
