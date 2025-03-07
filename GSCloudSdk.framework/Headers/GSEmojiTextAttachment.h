//
//  GSEmojiTextAttachment.h
//  GSCloudSdk
//
//  Created by yhj on 2022/10/8.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface GSEmojiTextAttachment : NSTextAttachment
/**
* 保存emojiText的值
*/
@property (nonatomic, strong) NSString *emojiText;
/**
* 保存emoji key2file 的 key 值
*/
@property (nonatomic, strong) NSString *emojiKey;

@end

NS_ASSUME_NONNULL_END
