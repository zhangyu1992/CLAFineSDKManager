//
//  Net263LogCollect.h
//  Net263LogCollectSDK
//
//  Created by 张俞 on 2023/8/1.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define CollectLog(FORMAT, ...) [[Net263LogCollect shareInstance] collectConsoleLogWithMessage:[NSString stringWithFormat:@"%s | [line:%d] | %@",__FUNCTION__,__LINE__,[NSString stringWithFormat:FORMAT, ##__VA_ARGS__]]]

@interface Net263LogCollect : NSObject
/// 单利对象
+ (instancetype)shareInstance;
/// 是否开启日志收集上传功能
@property (nonatomic, assign, readonly) BOOL isOpenLogCollect;

/// 开始日志收集
- (BOOL)startLogCollect:(NSString *)net263LogCollectID;

///  停止日志收集
- (BOOL)stopNet263LogCollect:(NSString *)net263LogCollectID;

/// 添加网络信息
- (void)addNetwork:(NSString *)network;
/// 添加直播间ID信息
- (void)addWebCastId:(NSString *)webcastId;
/// 添加user信息
- (void)addUserInfoCID:(NSString *)cid UID:(NSString *)uid UserName:(NSString *)userName;


/// 收集控制台日志信息
- (void)collectConsoleLogWithMessage:(NSString *)message;
/// 收集日志文本 code + message
- (void)collectLogWithCode:(NSString *)code Message:(NSString *)message;
/// 收集日志文本 code + type + message
- (void)collectLogWithCode:(NSString *)code Type:(NSString *)type Message:(NSString *)messag;

@end

NS_ASSUME_NONNULL_END
