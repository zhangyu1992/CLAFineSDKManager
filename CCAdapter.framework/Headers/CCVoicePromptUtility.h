//
//  CCVoicePromptUtility.h
//  Net263CCLiteDemo_IOS
//
//  Created by xugw0711 on 16-12-14.
//  Copyright (c) 2016年 xugw0711. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <AVFoundation/AVFoundation.h> 

typedef NS_ENUM(unsigned long long, CCVoicePromptUtilityType)
{
    CCVoicePromptUtilityType_Message = (1LL << 8),
    CCVoicePromptUtilityType_Mail = (1LL << 8) + 1,
    CCVoicePromptUtilityType_KeyboardNumner_0 = (1LL << 16),
    CCVoicePromptUtilityType_KeyboardNumner_1 = (1LL << 16) + 1,
    CCVoicePromptUtilityType_KeyboardNumner_2 = (1LL << 16) + 2,
    CCVoicePromptUtilityType_KeyboardNumner_3 = (1LL << 16) + 3,
    CCVoicePromptUtilityType_KeyboardNumner_4 = (1LL << 16) + 4,
    CCVoicePromptUtilityType_KeyboardNumner_5 = (1LL << 16) + 5,
    CCVoicePromptUtilityType_KeyboardNumner_6 = (1LL << 16) + 6,
    CCVoicePromptUtilityType_KeyboardNumner_7 = (1LL << 16) + 7,
    CCVoicePromptUtilityType_KeyboardNumner_8 = (1LL << 16) + 8,
    CCVoicePromptUtilityType_KeyboardNumner_9 = (1LL << 16) + 9,
    CCVoicePromptUtilityType_KeyboardNumner_Star = (1LL << 16) + 10,
    CCVoicePromptUtilityType_KeyboardNumner_Pound = (1LL << 16) + 11,
};

@interface CCVoicePromptUtility : NSObject

+ (CCVoicePromptUtility*)defaultVoicePromptUtility;

- (void)playMsgSound;
- (void)playMsgVibrate;

- (void)playMailSound;
- (void)playMailVibrate;

- (void)playSoundType:(unsigned long long)type;

- (void)playRing;
- (void)stopRing;

- (void)playWait;
- (void)stopWait;

@end
