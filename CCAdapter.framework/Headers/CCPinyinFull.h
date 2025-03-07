//
//  CCPinyinFull.h
//  Net263CCLite
//
//  Created by yiyimama on 16/4/15.
//  Copyright © 2016年 yiyimama. All rights reserved.
//

#ifndef _Net263CCLite_CCPinyinFull_h_
#define _Net263CCLite_CCPinyinFull_h_

#import "CCRuntime.h"

#ifdef __cplusplus
extern "C" {
#endif
    
#ifndef HZ2PY_OUTPUT_BUF_ARRAY_SIZE
#define HZ2PY_OUTPUT_BUF_ARRAY_SIZE 1024
#endif

void CCNameSpaceFunc(utf8_to_pinyin)(const char *utf, char *out);
    
#ifdef __cplusplus
}
#endif
    
#if 0x0 //HZ2PY_BINARY
int main(int argc, char *argv[])
{
    int has_check_utf8 = 0;
    char utf[HZ2PY_FILE_READ_BUF_ARRAY_SIZE];
    char outbuf[HZ2PY_OUTPUT_BUF_ARRAY_SIZE];
    
    while (1)
    {
        memset(utf, 0, sizeof(char) * HZ2PY_FILE_READ_BUF_ARRAY_SIZE);
        memset(outbuf, 0, sizeof(char) * HZ2PY_OUTPUT_BUF_ARRAY_SIZE);
        
        if (read(STDIN_FILENO, utf, HZ2PY_FILE_READ_BUF_ARRAY_SIZE - 1) <= 0)
            break;
        
        if ( has_check_utf8 == 0 )
        {
            if ( !is_utf8_string(utf) )
            {
                printf("File encoding is not utf-8!\n");
                return 1;
            }
            has_check_utf8 = 1;
        }
        
        CCNameSpaceFunc(utf8_to_pinyin)(utf, outbuf);
        printf("%s", outbuf);
    }
    
    return 0;
}
#endif


#endif //_Net263CCLite_CCPinyinFull_h_