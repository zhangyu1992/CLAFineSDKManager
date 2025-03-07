//
//  CCPinyinHeader.h
//  Net263CCLite
//
//  Created by yiyimama on 16/4/15.
//  Copyright © 2016年 yiyimama. All rights reserved.
//

/*
 * // Example
 *
 * #import "pinyin.h"
 *
 * NSString *hanyu = @"中国共产党万岁！";
 * for (int i = 0; i < [hanyu length]; i++)
 * {
 *     printf("%c", pinyinHeaderLetter([hanyu characterAtIndex:i]));
 * }
 */

#ifndef _Net263CCLite_CCPinyinHeader_h_
#define _Net263CCLite_CCPinyinHeader_h_

#import "CCRuntime.h"

#define pinyinHeader pinyinHeaderLetter

#ifdef __cplusplus
extern "C" {
#endif
    
#define ALPHA @"ABCDEFGHIJKLMNOPQRSTUVWXYZ#"
char CCNameSpaceFunc(pinyinHeaderLetter)(unsigned short hanzi);
    
#ifdef __cplusplus
}
#endif

#endif //_Net263CCLite_CCPinyinHeader_h_