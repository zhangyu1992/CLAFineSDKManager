//
//  BrocadMsg.h
//  GSCloudSdk
//
//  Created by gensee on 2022/3/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, GSBrocadMsgMode)
{
    GSBrocadMsgMode_Single, //单条
    GSBrocadMsgMode_Multiple, //多条
};

typedef NS_ENUM(NSInteger, GSBrocadMsgState)
{
    GSBrocadMsgState_Publish, //发布
    GSBrocadMsgState_Cancel, //结束
};
@interface GSBrocadMsg : NSObject
@property(nonatomic, copy) NSString* Id;   //消息Id
@property(nonatomic, assign) GSBrocadMsgState state;// 公告状态
@property(nonatomic, copy) NSString *title;  //消息内容
@property(nonatomic, assign) GSBrocadMsgMode mode;// 公告模式
@end

NS_ASSUME_NONNULL_END
