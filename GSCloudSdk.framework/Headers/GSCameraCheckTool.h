//
//  GSCameraCheckTool.h
//  GSCloudSdk
//
//  Created by 张俞 on 2022/4/27.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSCameraCheckTool : NSObject
/// 开始本地摄像头采集
- (void)startLocalCameraCaptureOnSuccess:(void(^)(AVCaptureVideoPreviewLayer * cameraLayer))success;
/// 停止本地摄像头采集
- (void)stopLocalCameraCaptureOnSuccess:(void(^)(void))success;
/// 重置摄像头方向
- (BOOL)resetLocalCameraPositionIsFront:(BOOL)isFront;
@end

NS_ASSUME_NONNULL_END
