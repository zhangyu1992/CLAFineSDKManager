//
//  YBError.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/9.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#define AUTHORIZED_ERROR @"无权限"
#define ROLE_ERROR @"角色错误"
#define MediaControll_ERROR @"没有主控权限"
#define SERVICE_ERROR @"服务异常"
#define CONCURRENCE_ERROR @"当前直播间并发已满，不允许进入（超方）"
#define NETWORK_ERROR @"网络错误"
#define LOCATION_SERVER_ERROR @"本地服务器地址错误"
#define LIVEROOMNOTFOUND_ERROR @"该直播不存在"
#define NICKNAME_ERROR @"昵称过长"
#define LIVEID_NULL @"直播ID为空"
#define CL_OPERATION_FAILED @"操作失败"

@interface YBError : NSObject
@property (nonatomic, assign, readonly) NSInteger  errorCode;
@property (nonatomic, copy, readonly) NSString * errorDescription;

-(instancetype)initWithErrorCode:(NSInteger)errorCode errorDescription:(NSString*)errorDescription error:(nullable NSError* )error;
-(NSError*)error; //如果是网络错误，可以从NSError获取到具体的网络请求状态码
@end

NS_ASSUME_NONNULL_END
