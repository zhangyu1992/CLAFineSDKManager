//
//  CCStdUtility.h
//  Net263CCLite
//
//  Created by yiyimama on 16/4/13.
//  Copyright © 2016年 yiyimama. All rights reserved.
//

#ifndef _Net263CCLite_CCStdUtility_h_
#define _Net263CCLite_CCStdUtility_h_

#import "CCRuntime.h"

#include <stdio.h>
#include <stdlib.h>

// stl, common
#include <string>
#include <list>
#include <vector>
#include <map>

#ifdef __cplusplus
//extern "C" {
#endif

//#define StringNotFound	-1
//#define StringNoPos std::string::npos

#define MyStdString(ss) \
(CCNameSpaceFunc(stdString)(ss))

std::string CCNameSpaceFunc(stdString)(NSString * str);

#define MyStdFormat(fmt,...) \
(CCNameSpaceFunc(stdFormat)(fmt,__VA_ARGS__))

std::string CCNameSpaceFunc(stdFormat)(const char *fmt, ...);

std::string CCNameSpaceFunc(stdFormatV)(const char *fmt, va_list args);

#define MyObjcString(ss) \
(CCNameSpaceFunc(objcString)(/*(std::string)*/ss))

NSString * CCNameSpaceFunc(objcString)(std::string str);

#define MyListFromArray(ls) \
(CCNameSpaceFunc(listFromArray)((NSMutableArray *)ls))

std::vector<std::string> CCNameSpaceFunc(listFromArray)(NSMutableArray * array);

#define MyArrayFromList(ls) \
(CCNameSpaceFunc(arrayFromList)((std::list<std::string>&)ls))

NSMutableArray * CCNameSpaceFunc(arrayFromList)(std::vector<std::string>& list);
    
#ifdef __cplusplus
//} // fix
#endif

#endif //_Net263CCLite_CCStdUtility_h_