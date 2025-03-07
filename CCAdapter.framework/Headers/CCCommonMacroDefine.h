//
//  CCCommonMacroDefine.h
//  NetMeetingCC
//
//  Created by jinxiangkun on 2019/1/3.
//  Copyright © 2019年 jinxiangkun. All rights reserved.
//

#ifndef CCCommonMacroDefine_h
#define CCCommonMacroDefine_h

#import <Foundation/Foundation.h>

// Emoji
#define EmojiString  @"EmojiString"
// Previous
#define PreviousString  @"PreviousString"

#define CCAudioRecoderMode (0x0) // 录制模式

#define kCCAppInfoPrefix @"appInfo_"
#define kCCGlobalConfigPrefix @"globalConfig_"

#define CCSHOWNPICTURESUFFIX  @"-show"
#define CCBIGPICTURESUFFIX  @"-big"

#define CCDefaultPictureServerDomain @"pic.263em.com"
#define CCDefaultPictureServerBackupIP @"211.150.66.153"

#define CCDefaultOfflineServerDomain @"offline.263em.com"
#define CCDefaultOfflineServerBackupIP @"211.150.66.153"

#define MESSAGEUPEDGE 10.0f        //消息上边距
#define MESSAGEDOWNEDGE 10.0f       //消息下边界
#define MESSAGETOTALEDGE 20.0f      //消息总边距

#define NICKNAMEHEIGHT 12.0f        //昵称高度
#define PICTUREMARGIN 11.0f         //背景图与图片上下边距之和
#define DEFAULTPICTURESIZE  49.0f   //默认图片的大小

#define VOICEMESSAGEHEIGHT 60.0f    //声音默认高度

#define CCMessageDataTypeGeneralHeight 24.0f

//文字居中显示
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 60000
    #define MBLabelAlignmentCenter NSTextAlignmentCenter
#else
    #define MBLabelAlignmentCenter UITextAlignmentCenter
#endif

#define CCTabBarHidesBottomBarWhenPushed @"com.net263.CCTabBarHidesBottomBarWhenPushed"


#endif /* CCCommonMacroDefine_h */
