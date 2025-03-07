//
//  GSPushStream.h
//  GSCloudSdk
//
//  Created by leo on 2022/4/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSPushStream : NSObject
///推流地址Id
@property (nonatomic,copy) NSString *Id;
///直播间Id
@property (nonatomic,copy) NSString *webcastId;
///推流平台名字
@property (nonatomic,copy) NSString *platform;
///推流url
@property (nonatomic,copy) NSString *pushStreamUrl;
///分辨率
@property (nonatomic,copy) NSString *resolution;
///流类型0 云视流 1第三方推流 2第三方拉流 3伪直播流
@property (nonatomic,assign) NSInteger opTy;
@property (nonatomic,assign) NSInteger recordId;
@property (nonatomic,assign) NSInteger state;
@property (nonatomic,assign) NSInteger confId;


@end

NS_ASSUME_NONNULL_END
