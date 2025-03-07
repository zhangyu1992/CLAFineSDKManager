//
//  GSCloudLiveConfig.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/8.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSCloudLiveConfig : NSObject
@property(nonatomic, assign)BOOL isHttp;
@property(nonatomic, copy, readonly)NSString *locationServerUrl;
///视频源比例
@property(nonatomic, assign)YBVideoCropMode cropMode;
///文档是否使用默认工具栏 默认Yes
@property(nonatomic, assign)BOOL isDocBurshToolBar;

-(void)setLocationServerUrl:(NSString *)serverUrl;
@end

NS_ASSUME_NONNULL_END
