//
//  CCJSON.hpp
//  Net263CCSDK
//
//  Created by yiyimama on 16/12/27.
//  Copyright © 2016年 net263. All rights reserved.
//

#ifndef CCJSON_hpp
#define CCJSON_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <map>

#include "CCMutexUtility.h"
//#include "Net263CC/CCConfig.h"
//#include "Net263CC/CCAutoPtr.h"
//#include "Net263CC/CCRefCountedObject.h"

// JSON生成器，解释使用更强大的库
//https://github.com/DaveGamble/cJSON.

namespace CC263
{
    /* cJSON Types: */
    #define cJSON_False  (1 << 0)
    #define cJSON_True   (1 << 1)
    #define cJSON_NULL   (1 << 2)
    #define cJSON_Number (1 << 3)
    #define cJSON_String (1 << 4)
    #define cJSON_Array  (1 << 5)
    #define cJSON_Object (1 << 6)
    #define cJSON_LongLong (1 << 7) //fix long
    
    #define cJSON_IsReference 256
    #define cJSON_StringIsConst 512
    
    class CCJSON;
    
    /* define our own boolean type */
    typedef int cjbool;
    //#define true ((cjbool)1)
    //#define false ((cjbool)0)
    
    struct cJSON;
    
    /* The cJSON structure: */
    struct cJSON
    {
        struct cJSON *next;
        struct cJSON *prev;
        struct cJSON *child;
        
        /* The type of the item, as above. */
        int     type;
        /* The item's string, 
         if type==cJSON_String */
        char *  valuestring;
        /* The item's number, 
         if type==cJSON_Number */
        int     valueint;
        /* The item's number, 
         if type==cJSON_Number */
        double  valuedouble;
        /* The item's number, 
         if type==cJSON_LongLong */
        long long   valuelong;
        /* The item's number, 
         if type==cJSON_LongLong */
        unsigned long long   valueulong;
        /* The item's name string, 
         if this item is the child of,
         or is in the list of subitems of an object. */
        char *  string;
        
        cJSON() // 初始化数字
        {
            next = 0x0;
            prev = 0x0;
            child = 0x0;
            type = cJSON_NULL;
            valueint = (int)0x0;
            valuedouble = (double)0.0;
            valuelong = (long long)0x0;
            valueulong = (long long)0x0;
        }
    };
    typedef struct cJSON cJSON;
    
    // 带内存释放的cJSON
    class CCJSON //: public CCRefCountedObject
    {
    public:
        CCJSON();
        virtual ~CCJSON();
        
    public:
        void cJSON_Minify(char *json);
        
    public:
        // 类管理创建内存
        void * cJSON_malloc(size_t size);
        // 类管理释放内存
        void cJSON_free(void * arrayPtr);
        
        // not used
        //void *(CCJSON::*cJSON_malloc)(size_t sz);
        //void (CCJSON::*cJSON_free)(void *ptr);
        
    protected:
        // 检查节点指针
        bool checkPointer(void *ptr);
        // 缓存节点指针
        void cachePointer(cJSON *ptr);
        // 内存创建锁
        //mutable Poco::FastMutex _mutex;
        CCNameSpace(MyStdMutex) _mutex;
        // how to catch object pointer ???
        std::map<long long, cJSON *> _cachedObjectMap;
        // how to catch memory pointer ???
        std::map<long long, const char *> _cachedMemoryMap;
        
    public:
        // 这个库解析有问题,16进制数！
        /* Supply a block of JSON,
         and this returns a cJSON object you can interrogate. 
         Call cJSON_Delete when finished. */
        cJSON *cJSON_Parse(const char *value);
        /* Render a cJSON entity to text for transfer/storage. 
         Free the char* when finished. */
        char  *cJSON_Print(const cJSON *item);
        /* Render a cJSON entity to text for transfer/storage without any formatting. 
         Free the char* when finished. */
        char  *cJSON_PrintUnformatted(const cJSON *item);
        /* Render a cJSON entity to text using a buffered strategy. 
         prebuffer is a guess at the final size. 
         guessing well reduces reallocation. 
         fmt=0 gives unformatted, =1 gives formatted */
        char  *cJSON_PrintBuffered(const cJSON *item,
                                   int prebuffer, int fmt);
        /* Render a cJSON entity to text using a buffer 
         already allocated in memory with length buf_len. 
         Returns 1 on success and 0 on failure. */
        int cJSON_PrintPreallocated(cJSON *item,
                                    char *buf, const int len, const int fmt);
        /* Delete a cJSON entity and all subentities. */
        void   cJSON_Delete(cJSON *c);
        
        /* Returns the number of items in an array (or object). */
        int	  cJSON_GetArraySize(const cJSON *array);
        /* Retrieve item number "item" from array "array". 
         Returns NULL if unsuccessful. */
        cJSON *cJSON_GetArrayItem(const cJSON *array, int item);
        /* Get item "string" from object. Case insensitive. */
        cJSON *cJSON_GetObjectItem(const cJSON *object, const char *string);
        /* Has item "string" from object. Case insensitive. */
        int cJSON_HasObjectItem(const cJSON *object, const char *string);
        /* For analysing failed parses. 
         This returns a pointer to the parse error. 
         You'll probably need to look a few chars back to make sense of it. 
         Defined when cJSON_Parse() returns 0. 0 when cJSON_Parse() succeeds. */
        const char *cJSON_GetErrorPtr(void);
        
        /* These calls create a cJSON item of the appropriate type. */
        cJSON *cJSON_CreateNull(void);
        cJSON *cJSON_CreateTrue(void);
        cJSON *cJSON_CreateFalse(void);
        cJSON *cJSON_CreateBool(int b);
        // int, float, double
        cJSON *cJSON_CreateNumber(double num);
        cJSON *cJSON_CreateString(const char *string);
        cJSON *cJSON_CreateLongLong(long long num);
        cJSON *cJSON_CreateArray(void);
        cJSON *cJSON_CreateObject(void);
        
        /* These utilities create an Array of count items. */
        cJSON *cJSON_CreateIntArray(const int *numbers, int count);
        cJSON *cJSON_CreateFloatArray(const float *numbers, int count);
        cJSON *cJSON_CreateDoubleArray(const double *numbers, int count);
        cJSON *cJSON_CreateStringArray(const char **strings, int count);
        cJSON *cJSON_CreateLongLongArray(const long long *numbers, int count);
        
        /* Macros for creating things quickly. */
        #define cJSON_AddNullToObject(ref,object,name) \
            ref.cJSON_AddItemToObject(object, name, ref.cJSON_CreateNull())
        /* Macros for creating things quickly. */
        #define cJSON_AddTrueToObject(ref,object,name) \
            ref.cJSON_AddItemToObject(object, name, ref.cJSON_CreateTrue())
        /* Macros for creating things quickly. */
        #define cJSON_AddFalseToObject(ref,object,name) \
            ref.cJSON_AddItemToObject(object, name, ref.cJSON_CreateFalse())
        /* Macros for creating things quickly. */
        #define cJSON_AddBoolToObject(ref,object,name,b) \
            ref.cJSON_AddItemToObject(object, name, ref.cJSON_CreateBool(b))
        /* Macros for creating things quickly. */
        #define cJSON_AddNumberToObject(ref,object,name,n) \
            ref.cJSON_AddItemToObject(object, name, ref.cJSON_CreateNumber(n))
        /* Macros for creating things quickly. */
        #define cJSON_AddStringToObject(ref,object,name,s) \
            ref.cJSON_AddItemToObject(object, name, ref.cJSON_CreateString(s))
        /* Macros for creating things quickly. */
        #define cJSON_AddLongLongToObject(ref,object,name,n) \
            ref.cJSON_AddItemToObject(object, name, ref.cJSON_CreateLongLong(n))
        
        /* Append item to the specified array/object. */
        void cJSON_AddItemToArray(cJSON *array, cJSON *item);
        void cJSON_AddItemToObject(cJSON *object, const char *string, cJSON *item);
        /* Use this when string is definitely const (i.e. a literal, or as good as), 
         and will definitely survive the cJSON object.
         * WARNING: When this function was used, 
         make sure to always check that (item->type & cJSON_StringIsConst) is zero before
         * writing to `item->string` */
        void cJSON_AddItemToObjectCS(cJSON *object, const char *string, cJSON *item);
        /* Append reference to item to the specified array/object. 
         Use this when you want to add an existing cJSON to a new cJSON, 
         but don't want to corrupt your existing cJSON. */
        void cJSON_AddItemReferenceToArray(cJSON *array, cJSON *item);
        void cJSON_AddItemReferenceToObject(cJSON *object, const char *string, cJSON *item);
        
        /* Remove/Detatch items from Arrays/Objects. */
        cJSON *cJSON_DetachItemFromArray(cJSON *array, int which);
        void   cJSON_DeleteItemFromArray(cJSON *array, int which);
        cJSON *cJSON_DetachItemFromObject(cJSON *object, const char *string);
        void   cJSON_DeleteItemFromObject(cJSON *object, const char *string);
        
        /* Update array items. */
        /* Shifts pre-existing items to the right. */
        void cJSON_InsertItemInArray(cJSON *array, int which, cJSON *newitem);
        void cJSON_ReplaceItemInArray(cJSON *array, int which, cJSON *newitem);
        void cJSON_ReplaceItemInObject(cJSON *object,const char *string,cJSON *newitem);
        
        /* Duplicate a cJSON item */
        /* Duplicate will create a new, identical cJSON item to the one you pass,
         in new memory that will need to be released.
         With recurse!=0, it will duplicate any children connected to the item.
         The item->next and ->prev pointers are always zero on return from Duplicate. */
        cJSON *cJSON_Duplicate(const cJSON *item, int recurse);
        
        /* ParseWithOpts allows you to require (and check) 
         that the JSON is null terminated, 
         and to retrieve the pointer to the final byte parsed. */
        /* If you supply a ptr in return_parse_end and parsing fails, 
         then return_parse_end will contain a pointer to the error. 
         If not, then cJSON_GetErrorPtr() does the job. */
        cJSON *cJSON_ParseWithOpts(const char *value,
                                   const char **return_parse_end,
                                   int require_null_terminated);
        
        /* Macro for iterating over an array */
        #define cJSON_ArrayForEach(pos, head) \
        for(pos = (head)->child; pos != NULL; pos = pos->next)
        
        /* When assigning an integer value, it needs to be propagated to valuedouble too. */
        #define cJSON_SetIntValue(object,val) \
        ((object) ? (object)->valuedouble = (object)->valueint = (val) : (val))
        
        #define cJSON_SetNumberValue(object,val) \
        ((object) ? (object)->valueint = (object)->valuedouble = (val) : (val))
        
        
    private:
        struct printbuffer
        {
            char *buffer;
            int length;
            int offset;
            cjbool noalloc;
        } ;
        typedef struct printbuffer printbuffer;
        
        cJSON * cJSON_New_Item(void);
        cJSON * create_reference(const cJSON *item);
        int cJSON_strcasecmp(const char *s1, const char *s2);
        char * cJSON_strdup(const char* str);
        const char *parse_number(cJSON *item, const char *num);
        int update(const printbuffer *p);
        char * ensure(printbuffer *p, int needed);
        char * print_number(const cJSON *item, printbuffer *p);
        char * print_longlong(const cJSON *item, printbuffer *p);
        const char *parse_string(cJSON *item, const char *str, const char **ep);
        char * print_string_ptr(const char *str, printbuffer *p);
        char * print_string(const cJSON *item, printbuffer *p);
        const char * parse_value(cJSON *item, const char *value, const char **ep);
        char * print_value(const cJSON *item, int depth, cjbool fmt, printbuffer *p);
        const char *parse_array(cJSON *item,const char *value,const char **ep);
        char * print_array(const cJSON *item, int depth, cjbool fmt, printbuffer *p);
        const char *parse_object(cJSON *item, const char *value, const char **ep);
        char * print_object(const cJSON *item, int depth, cjbool fmt, printbuffer *p);
        void suffix_object(cJSON *prev, cJSON *item);
    };
};

#endif /* CCJSON_hpp */
