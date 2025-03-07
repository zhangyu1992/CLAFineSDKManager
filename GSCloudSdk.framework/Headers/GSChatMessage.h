//
//  GSChatMessage.h
//  GSCloudSdk
//
//  Created by net263 on 2022/3/10.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface YBChatQuote : NSObject

@property(nonatomic, copy)NSString *name;
@property(nonatomic, copy)NSString *uid;
@property(nonatomic, copy)NSString *chatContent;
@property(nonatomic, copy)NSString *msgId;
@property(nonatomic, copy)NSString *from_dev;
@property(nonatomic, copy)NSString *imgUrl;
@property (nonatomic,assign)BOOL imgState;
@property (nonatomic, copy)NSString *ucid;
@end

@interface YBChatContent : NSObject
@property(nonatomic, copy)NSString *body;       //聊天消息内容
@property(nonatomic, copy)NSString *name;       //发送者昵称
@property(nonatomic, assign)NSInteger role;     //发送者角色
@property(nonatomic, copy)NSString *type;       //消息类型  image normal
@property(nonatomic, strong)YBChatQuote *quote; //要回复的消息内容
@property (nonatomic,copy) NSString *headImgUrl;//头像

/** 包含表情后的文本 */
- (NSAttributedString *) bodyStringTextFont:(NSString *)body
                                          textFont:(UIFont *)font;
- (NSDictionary *) dictionarybodyStringTextFont:(NSString *)body
                             textFont:(UIFont*)font;
- (NSString *)emojStringTransformToString:(NSString *)body;

-(NSString *)contentFromEmojiAttributed:(NSAttributedString *)attributedString;

- (NSAttributedString *) bodyStringTextFont:(NSString *)body
                                   textFont:(UIFont*)font  ImageSize:(CGSize)size;

@end
@interface GSChatMessage : NSObject
@property(nonatomic, assign)NSInteger audit_status; //审核状态
@property(nonatomic, assign)NSInteger status;
@property(nonatomic, assign)NSInteger createTime;   //发送时间
@property(nonatomic, copy)NSString *from_dev;
@property(nonatomic, copy)NSString *from_uid;
@property(nonatomic, copy)NSString *mid;
@property(nonatomic, strong)YBChatContent *content;
@property(nonatomic, assign) BOOL isTop;            //置顶
@property(nonatomic, assign) BOOL isHiglight;       //高亮
@property(nonatomic, assign) BOOL isSilence;        //禁言
@property(nonatomic, assign) BOOL isApproved;       //是否通过审核

/// 系统消息
@property(nonatomic, copy) NSString * systemMessage;

@end

NS_ASSUME_NONNULL_END
