//
//  CCEmojiTextAttachment.h
//  emojiDemo
//
//  Created by xugw0711 on 2017/4/24.
//  Copyright © 2017年 xugw0711. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CCEmojiTextAttachment : NSTextAttachment

@property(strong, nonatomic) NSString *emojiTag;
@property(assign, nonatomic) CGSize emojiSize;

@end
