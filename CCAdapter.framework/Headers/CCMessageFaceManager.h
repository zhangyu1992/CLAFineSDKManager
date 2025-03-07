//
//  CCMessageFaceManager.h
//  Net263CCLiteDemo_IOS
//
//  Created by xugw0711 on 2017/4/20.
//  Copyright © 2017年 xugw0711. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "CCRuntime.h"
//#import "CCNotificationKeys.h"

@interface CCMessageFaceManager : NSObject

+ (CCMessageFaceManager *)shareFaceManager;

- (UIImage *)faceImageForContent:(NSString *)str;
- (UIImage *)faceImageShowForContent:(NSString *)str;

- (NSArray *)getEmojis;

@end
