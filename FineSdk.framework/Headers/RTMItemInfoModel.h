//
//  RTMItemInfoModel.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/6/25.
//

#import <Foundation/Foundation.h>
#import <FineSdk/RTMEnum.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTMItemInfoModel : NSObject

@property (nonatomic, copy) NSString * id_; //通用id
@property (nonatomic, copy) NSString * cid; //客户id
@property (nonatomic, copy) NSString * logname;//用户名
@property (nonatomic, copy) NSString *msgId;//消息ID

- (instancetype)initWithID:(NSString*)Id
                       CID:(NSString*)CID
                   logName:(NSString*)logName
                 messageId:(NSString*)msgId;

+ (instancetype)itemInfoModelWithID:(NSString*)Id
                                CID:(NSString*)CID
                            logName:(NSString*)logName
                          messageId:(NSString*)msgId;

@end

NS_ASSUME_NONNULL_END
