//
//  RTMLinker.h
//  FineSdk
//
//  Created by 胡亚磊 on 2021/6/18.
//

#import <Foundation/Foundation.h>
#import <FineSdk/RTMGroupMessageSendModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^sendMessageSuccess)(NSString*);
typedef void(^sendMessageFail)(NSString*);
typedef void(^receiveMessage)(RTMGroupMessageSendModel*);

@interface RTMLinker : NSObject

@property (nonatomic, copy) sendMessageSuccess sendMessageSuccessBlock;
@property (nonatomic, copy) sendMessageFail sendMessageFailBlock;
@property (nonatomic, copy) receiveMessage receiveMessageBlock;

//发送文本消息到群组
- (void)sendTextMessage:(RTMGroupMessageSendModel*)message;



//回复接收到的消息
- (void)ReplyMessage:(NSString*)msgId;

@end

NS_ASSUME_NONNULL_END
