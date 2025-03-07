//
//  CCPinyinTrans.h
//  Net263CCLite
//
//  Created by yiyimama on 16/4/16.
//  Copyright © 2016年 yiyimama. All rights reserved.
//

#ifndef _Net263CCLite_CCPinyinTrans_h_
#define _Net263CCLite_CCPinyinTrans_h_



#include "CCPinyinFull.h"
#include "CCPinyinHeader.h"

#include <list>
#include <string>

#import "CCRuntime.h"

#define PinyinFull @"Net263CCLite_PinyinFull"
#define PinyinFirst @"Net263CCLite_PinyinFirst"

struct CCNameSpace(PinyinInfo)
{
    ~CCNameSpace(PinyinInfo)()
    {
        if(!_listPinyinFull.empty()) {
            _listPinyinFull.clear();
        }
        if(!_listPinyinFirst.empty()) {
            _listPinyinFirst.clear();
        }
    }
    
    std::list<std::string> _listPinyinFull;
    std::list<std::string> _listPinyinFirst;
};

//std::string CCNameSpaceFunc(fullPinyin)(std::string & str);
std::string CCNameSpaceFunc(fullPinyinFix)(std::string & str);

NSMutableDictionary * CCNameSpaceFunc(pinyinTransform)(std::string strUTF8);


#endif //_Net263CCLite_CCPinyinTrans_h_