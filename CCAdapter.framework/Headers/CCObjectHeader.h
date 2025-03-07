//
//  CCRuntimeUtility.h
//  ZNetMeeting
//
//  Created by jinxiangkun on 2018/12/4.
//  Copyright © 2018年 jinxiangkun. All rights reserved.
//

#ifndef _CC_RUNTIME_UTILITY_H_
#define _CC_RUNTIME_UTILITY_H_

#import "CCRuntime.h"

#include <assert.h>

//RELEASE Mode No LOG

#pragma mark - Prefix

//#define MyLog(fmt, ...) \
// NSLog(fmt, ##__VA_ARGS__)
#ifndef CCLog
//#if defined(DEBUG) && DEBUG
#if !(defined(DEBUG) && DEBUG)
#define CCLog(fmt, ...) do { } while(0)
#else
#define CCLog(fmt, ...) NSLog(fmt, ##__VA_ARGS__)
//#define CCLog(fmt, ...) \
//NSLog((@"CC Log: %@ [Line %d]" fmt), \
//    __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)
#endif
#endif //CC_LOG

#define MyExtern CC_EXTERN
#ifndef CC_EXTERN
#if defined(__cplusplus)
#define CC_EXTERN extern "C"
#else
#define CC_EXTERN extern
#endif
#endif //CC_EXTERN

#define MyInline CC_INLINE
#ifndef CC_INLINE
#if defined(__GNUC__) && (__GNUC__ == 4)
#define CC_INLINE static __inline__ \
__attribute__((always_inline))
#else
#define CC_INLINE static __inline__
#endif
#endif //CC_INLINE

#define MyAssert CC_ASSERT
#ifndef CC_ASSERT
//#if defined(DEBUG) && DEBUG
#if !(defined(DEBUG) && DEBUG)
#define CC_ASSERT(co, desc) ((void)0)
#else
//#define CC_ASSERT(co, desc) \
//((!(co))?\
//    NSLog(@"\n%@",(desc)):((void)0))
#define CC_ASSERT(co, desc) \
((!(co)?\
    (NSLog(@"\n%@",(desc)),assert(co)):\
    ((void)0)),(void)0)
#endif
#endif //CC_ASSERT

#pragma mark - Foundation object

#ifndef CC_FOUNDATION_OBJECT

#define MyIntString(v) CC_INT_STRING(v)
//+ (NSString *)intString:(int)val
#define CC_INT_STRING(val) \
[NSString stringWithFormat:@"%d", (int)val]

#define MyIntValue(s) CC_INT_VALUE(s)
//+ (int )intValue:(NSString *)str
#define CC_INT_VALUE(obj) \
((obj)?(([obj respondsToSelector:\
@selector(intValue)])?([obj intValue]):(0)):(0))

#define MyBoolString(v) CC_BOOL_STRING(v)
//+ (NSString *)boolString:(BOOL)val
#define CC_BOOL_STRING(val) \
[NSString stringWithFormat:@"%d", (int)val]

#define MyBoolValue(s) CC_BOOL_VALUE(s)
//+ (BOOL)boolValue:(NSString *)str
#define CC_BOOL_VALUE(obj) \
((obj)?(([obj respondsToSelector:\
@selector(boolValue)])?([obj boolValue]):(0)):(0))

#define MyIntegerString(v) CC_INTEGER_STRING(v)
//+ (NSString *)integerString:(NSInteger)val
#define CC_INTEGER_STRING(val) \
[NSString stringWithFormat:@"%ld", (NSInteger)val]

#define MyIntegerValue(s) CC_INTEGER_VALUE(s)
//+ (NSInteger)integerValue:(NSString *)str
#define CC_INTEGER_VALUE(obj) \
((obj)?(([obj respondsToSelector:\
@selector(integerValue)])?([obj integerValue]):(0)):(0))

#define MyFloatString(v) CC_FLOAT_STRING(v)
//+ (NSString *)floatString:(float)val
#define CC_FLOAT_STRING(val) \
[NSString stringWithFormat:@"%f", (float)val]

#define MyFloatValue(s) CC_FLOAT_VALUE(s)
//+ (float )floatValue:(NSString *)str
#define CC_FLOAT_VALUE(obj) \
((obj)?(([obj respondsToSelector:\
@selector(floatValue)])?([obj floatValue]):(0)):(0))

#define MyDoubleString(v) CC_DOUBLE_STRING(v)
//+ (double )doubleValue:(NSString *)str
#define CC_DOUBLE_STRING(val) \
[NSString stringWithFormat:@"%lf", (double)val]

#define MyDoubleValue(s) CC_DOUBLE_VALUE(s)
//+ (NSString *)doubleString:(double)val
#define CC_DOUBLE_VALUE(obj) \
((obj)?(([obj respondsToSelector:\
@selector(doubleValue)])?([obj doubleValue]):(0)):(0))

#define MyLongString(v) CC_LONG_STRING(v)
//+ (NSString *)longString:(long)val
#define CC_LONG_STRING(val) \
[NSString stringWithFormat:@"%ld", (long)val]

#define MyLongValue(s) CC_LONG_VALUE(s)
//+ (long)longValue:(NSString *)str
#define CC_LONG_VALUE(obj) \
((obj)?(([obj respondsToSelector:\
@selector(longValue)])?([obj longValue]):(\
([obj respondsToSelector:\
@selector(integerValue)])?([obj integerValue]):(0))):(0))

#define MyLongLongString(v) CC_LONGLONG_STRING(v)
//+ (NSString *)longLongString:(long long)val
#define CC_LONGLONG_STRING(val) \
[NSString stringWithFormat:@"%lld", (long long)val]

#define MyLongLongValue(s) CC_LONGLONG_VALUE(s)
//+ (long long)longLongValue:(NSString *)str
#define CC_LONGLONG_VALUE(obj) \
((obj)?(([obj respondsToSelector:\
@selector(longLongValue)])?([obj longLongValue]):(0)):(0))

#define MyUnsignedIntString(v) CC_UNSIGNEDINT_STRING(v)
//+ (NSString *)unsignedIntString:(unsigned int)val
#define CC_UNSIGNEDINT_STRING(val) \
[NSString stringWithFormat:@"%u", (unsigned int)val]

#define MyUnsignedIntValue(s) CC_UNSIGNEDINT_VALUE(s)
//+ (unsigned int)unsignedIntValue:(NSString *)str
#define CC_UNSIGNEDINT_VALUE(obj) \
((obj)?(([obj respondsToSelector:\
@selector(unsignedIntValue)])?([obj unsignedIntValue]):(\
([obj respondsToSelector:\
@selector(integerValue)])?([obj integerValue]):(0))):(0))

#define MyUnsignedLongVString(v) CC_UNSIGNEDLONG_STRING(v)
//+ (NSString *)unsignedLongString:(unsigned long long)val
#define CC_UNSIGNEDLONG_STRING(val) \
[NSString stringWithFormat:@"%llu", (unsigned long long)val]

#define MyUnsignedLongValue(s) CC_UNSIGNEDLONG_VALUE(s)
//+ (unsigned long)unsignedLongValue:(NSString *)str
#define CC_UNSIGNEDLONG_VALUE(obj) \
((obj)?(([obj respondsToSelector:\
@selector(unsignedLongValue)])?([obj unsignedLongValue]):(\
([obj respondsToSelector:\
@selector(longLongValue)])?([obj longLongValue]):(0))):(0))
//@selector(integerValue)])?([obj integerValue]):(0))):(0))

#define MyCStringObject(v) CC_CSTRING_OBJECT(v)
//+ (NSString *)objectString:(const char *)ptr
#define CC_CSTRING_OBJECT(ptr) \
(NSString *)\
((ptr)?([NSString stringWithCString:(const char *)ptr \
    encoding:(NSStringEncoding)NSUTF8StringEncoding]):(@""))

#define MyCStringValue(s) CC_CSTRING_POINTER(s)
//+ (const char *)stringValue:(NSString *)str
#define CC_CSTRING_POINTER(obj) \
(const char *)\
((str && ([str isKindOfClass:[NSString class]]))?\
([str UTF8String]?[str UTF8String]:(\
(const char *)[str cStringUsingEncoding:NSASCIIStringEncoding])):(0))

#define MyStringReference(p) CC_REFERENCE_OBJECT(p)
//+ (NSString *)referenceString:(const void *)ptr
#define CC_REFERENCE_OBJECT(ptr) \
[NSString stringWithFormat:@"%p", (void *)ptr]
//[NSString stringWithFormat:@"%p", (__bridge void *)ptr]

#define MyStringPointer(s) CC_REFERENCE_POINTER(s)
//+ (const void *)referenceValue:(NSString *)str
#define CC_REFERENCE_POINTER(obj) \
(const void *)\
((obj)?(([obj respondsToSelector:\
@selector(unsignedLongLongValue)])?([obj unsignedLongLongValue]):(\
([obj respondsToSelector:\
@selector(longLongValue)])?([obj longLongValue]):(0))):(0)) //

#endif //CC_FOUNDATION_OBJECT

#pragma mark - FOUNDATION ARRAY DICT

#define KeyTypeError @"key is type error"
#define ValTypeError @"obj is type error"
#define ListTypeError @"list is type error"
#define DictTypeError @"dict is type error"

#define MyHasSelector(obj,selector) CC_HAS_SELECTOR(obj,selector)
//- (BOOL)respondsToSelector:(SEL)aSelector
#define CC_HAS_SELECTOR(obj,selector) \
    ([(obj) respondsToSelector:(selector)])

#pragma mark - NSArray, NSMutableArray object

//NSArray, NSMutableArray

//#if defined(DEBUG) && DEBUG
#if !(defined(DEBUG) && DEBUG)

#define MyGetFirstObject(list) CC_FIRST_OBJECT(list)
//- (ObjectType)firstObject
#define CC_FIRST_OBJECT(list) \
((list) ? [(list) firstObject] : (id)nil)

#define MyGetLastObject(list) CC_LAST_OBJECT(list)
//- (ObjectType)lastObject
#define CC_LAST_OBJECT(list) \
((list) ? [(list) lastObject] : (id)nil)

#define MyGetObjectAt(list,index) CC_OBJECT_AT_INDEX((list),(index))
//- (ObjectType)objectAtIndex:(NSUInteger)index
#define CC_OBJECT_AT_INDEX(list,index) \
((list) ? \
    (((list).count>index)?([(list) objectAtIndex:(NSUInteger)(index)]):nil) : \
    (id)nil)

#else // DEBUG

//MyAssert([(list) isKindOfClass:[NSArray class]], ListTypeError)
#define MyGetFirstObject(list) CC_FIRST_OBJECT(list)
//- (ObjectType)firstObject
#define CC_FIRST_OBJECT(list) \
((list) ? \
    (([(list) isKindOfClass:[NSArray class]] || \
      [(list) isKindOfClass:[NSMutableArray class]]) ? \
        [(list) firstObject] : \
    (MyAssert([(list) isKindOfClass:[NSArray class]], ListTypeError), \
        (id)nil) ) : \
    (id)nil)

//MyAssert([(list) isKindOfClass:[NSArray class]], ListTypeError)
#define MyGetLastObject(list) CC_LAST_OBJECT(list)
//- (ObjectType)lastObject
#define CC_LAST_OBJECT(list) \
((list) ? \
    (([(list) isKindOfClass:[NSArray class]] || \
      [(list) isKindOfClass:[NSMutableArray class]]) ? \
        [(list) lastObject] : \
    (MyAssert([(list) isKindOfClass:[NSArray class]], ListTypeError), \
        (id)nil) ) : \
    (id)nil)

//MyAssert([(list) isKindOfClass:[NSArray class]], ListTypeError)
#define MyGetObjectAt(list,index) CC_OBJECT_AT_INDEX((list),(index))
//- (ObjectType)objectAtIndex:(NSUInteger)index
#define CC_OBJECT_AT_INDEX(list,index) \
((list) ? \
    (([(list) isKindOfClass:[NSArray class]] || \
      [(list) isKindOfClass:[NSMutableArray class]]) ? \
        (((list).count>(index))?([(list) objectAtIndex:(NSUInteger)(index)]):nil) : \
    (MyAssert([(list) isKindOfClass:[NSArray class]], ListTypeError), \
        (id)nil) ) : \
    (id)nil)

#endif

//NSMutableArray

#define MyDelLastObject(list) CC_REMOVE_LAST_OBJECT(list)
//- (void)removeLastObject
#define CC_REMOVE_LAST_OBJECT(list) \
if ( (list) != nil && \
[(list) isKindOfClass:[NSMutableArray class]]) \
{ \
    if (MyHasSelector((list),@selector(removeLastObject))) \
    { \
        [(NSMutableArray*)(list) removeLastObject]; \
    } \
}  else { \
    MyAssert((list) != nil, @"removeLastObject list is nil");\
    MyAssert(([(list) isKindOfClass:[NSMutableArray class]]), ListTypeError);\
}

#define MyDelFirstObject(list) CC_REMOVE_FIRST_OBJECT(list)
//- (void)removeFirstObject
#define CC_REMOVE_FIRST_OBJECT(list) \
if ( (list) != nil && \
    [(list) isKindOfClass:[NSMutableArray class]]) \
{ \
    if (MyHasSelector((list),@selector(removeObjectAtIndex:))) \
    { \
        if ([(list) count] > 0) { \
            [(NSMutableArray*)(list) removeObjectAtIndex:(NSUInteger)0]; \
        } \
    } \
} else { \
    MyAssert((list) != nil, @"removeFirstObject list is nil");\
    MyAssert(([(list) isKindOfClass:[NSMutableArray class]]), ListTypeError);\
}

//MyAssert((val) != nil, @"addObject: object is nil");
#define MyAddObject(list,val) CC_ADD_OBJECT((list),(val))
//- (void)addObject:(ObjectType)anObject
#define CC_ADD_OBJECT(list,val) \
if ( (list) != nil && \
    [(list) isKindOfClass:[NSMutableArray class]]) \
{ \
    if ((val) != nil && [(val) isKindOfClass:[NSObject class]] ) \
    { \
        if (MyHasSelector((list),@selector(addObject:))) \
        { \
            [(NSMutableArray*)(list) addObject:(id)(val)]; \
        } \
    }  else { \
        MyAssert((val) != nil, @"addObject: object is nil");\
        MyAssert(([(val) isKindOfClass:[NSObject class]]), ValTypeError);\
    } \
} else { \
    MyAssert((list) != nil, @"addObject: list is nil");\
    MyAssert(([(list) isKindOfClass:[NSMutableArray class]]), ListTypeError);\
}

//MyAssert((val) != nil, @"addObject: object is nil");
#define MyAddObjectAt(list,val,index) CC_INSERT_OBJECT_AT_INDEX((list),(val),(index))
//- (void)insertObject:(ObjectType)anObject atIndex:(NSUInteger)index
#define CC_INSERT_OBJECT_AT_INDEX(list,val,index) \
if ( (list) != nil && \
    [(list) isKindOfClass:[NSMutableArray class]]) \
{ \
    if ((val) != nil && [(val) isKindOfClass:[NSObject class]] ) \
    { \
        if (MyHasSelector((list),@selector(insertObject:atIndex:))) \
        { \
            if ((list).count > (index)) { \
                [(NSMutableArray*)(list) insertObject:(id)(val) \
                                            atIndex:(NSUInteger)(index)]; \
            } else { \
                [(NSMutableArray*)(list) addObject:(id)(val)]; \
            } \
        } \
    } else { \
        MyAssert((val) != nil, @"addObjectAt: object is nil");\
        MyAssert(([(val) isKindOfClass:[NSObject class]]), ValTypeError);\
    } \
} else { \
    MyAssert((list) != nil, @"addObjectAt: list is nil");\
    MyAssert(([(list) isKindOfClass:[NSMutableArray class]]), ListTypeError);\
}

//MyAssert((val) != nil, @"addObject: object is nil");
#define MyDelObject(list,val) CC_REMOVE_OBJECT((list),(val))
//- (void)removeObject:(ObjectType)anObject
#define CC_REMOVE_OBJECT(list,val) \
if ( (list) != nil && \
    [(list) isKindOfClass:[NSMutableArray class]]) \
{ \
    if ((val) != nil && [(val) isKindOfClass:[NSObject class]] ) \
    { \
        [(NSMutableArray*)(list) removeObject:(id)(val)]; \
    }  else { \
        MyAssert((val) != nil, @"delObject: object is nil");\
        MyAssert(([(val) isKindOfClass:[NSObject class]]), ValTypeError);\
    } \
} else { \
    MyAssert((list) != nil, @"delObject: list is nil");\
    MyAssert(([(list) isKindOfClass:[NSMutableArray class]]), ListTypeError);\
}

#define MyDelObjectAt(list,index) CC_REMOVE_OBJECT_AT((list),(index))
//- (void)removeObjectAtIndex:(NSUInteger)index
#define CC_REMOVE_OBJECT_AT(list,index) \
if ( (list) != nil && \
    [(list) isKindOfClass:[NSMutableArray class]]) \
{ \
    if ([list count] > index ) \
    { \
        if (MyHasSelector((list),@selector(removeObjectAtIndex:))) \
        { \
            [(NSMutableArray*)(list) removeObjectAtIndex:(NSUInteger)(index)]; \
        } \
    }  else { \
        MyAssert([list count] > (index), @"delObjectAt: index is err");\
    } \
} else { \
    MyAssert((list) != nil, @"delObjectAt: list is nil");\
    MyAssert(([(list) isKindOfClass:[NSMutableArray class]]), ListTypeError);\
}

#pragma mark - NSDictionary, NSMutableDictionary object

//NSDictionary, NSMutableDictionary

#if !(defined(DEBUG) && DEBUG)

//dict is nil, val is nil
//key is nil, val is nil
#define MyGetKeyValue(dict,key) MyGetObjectForKey((dict),(key))
#define MyGetObjectForKey(dict,key) CC_OBJECT_FOR_KEY((dict),(key))
//- (nullable ObjectType)objectForKey:(KeyType)aKey
#define CC_OBJECT_FOR_KEY(dict,key) \
((id)(((dict) && (key)) ? \
    (([(dict) isKindOfClass:[NSDictionary class]] || \
      [(dict) isKindOfClass:[NSMutableDictionary class]]) ? \
        ([(dict) objectForKey:(id)(key)]) : (id)nil) : \
    (id)nil))

#else
//dict is nil, val is nil
//MyAssert(((key) != nil), @"getObject: key is nil")
#define MyGetKeyValue(dict,key) MyGetObjectForKey((dict),(key))
#define MyGetObjectForKey(dict,key) CC_OBJECT_FOR_KEY((dict),(key))
//- (nullable ObjectType)objectForKey:(KeyType)aKey
#define CC_OBJECT_FOR_KEY(dict,key) \
((id)((key) ? ((dict) ? \
    (([(dict) isKindOfClass:[NSDictionary class]] || \
      [(dict) isKindOfClass:[NSMutableDictionary class]]) ? \
        ([(dict) objectForKey:(id)(key)]) : \
        (MyAssert([(dict) isKindOfClass:[NSDictionary class]], DictTypeError), \
        (id)nil) ) : (id)nil) :\
    (MyAssert(((key) != nil), @"getObject: key is nil"), \
     MyAssert(([(key) isKindOfClass:[NSString class]]), KeyTypeError), \
    (id)nil)))

#endif

//NSMutableDictionary

//MyAssert((dict) != nil, @"delObject: dict is nil");
#define MyDelKeyValue(dict,key) MyDelObjectForKey((dict),(key))
#define MyDelObjectForKey(dict,key) CC_REMOVE_OBJECT_FOR_KEY((dict),(key))
//- (void)removeObjectsForKeys:(NSArray<KeyType> *)keyArray
#define CC_REMOVE_OBJECT_FOR_KEY(dict,key) \
MyAssert(([(dict) isKindOfClass:[NSMutableDictionary class]]), DictTypeError); \
if ( (dict) != nil && \
    [(dict) isKindOfClass:[NSMutableDictionary class]]) \
{ \
    if ((key) != nil && [(key) isKindOfClass:[NSString class]] ) \
    { \
        if (MyHasSelector((dict),@selector(removeObjectForKey:))) \
        { \
            [(NSMutableDictionary*)(dict) removeObjectForKey:(id)(key)]; \
        } \
    } else { \
        MyAssert((key) != nil, @"delObject: key is nil");\
        MyAssert(([(key) isKindOfClass:[NSString class]]), KeyTypeError);\
    } \
} else { \
    MyAssert((dict) != nil, @"delObject: dict is nil");\
    MyAssert(([(dict) isKindOfClass:[NSMutableDictionary class]]), DictTypeError);\
}

//MyAssert((dict) != nil, @"setObject: dict is nil");
#define MySetKeyValue(dict,key,val) MySetObjectForKey((dict),(val),(key))
#define MySetObjectForKey(dict,val,key) CC_SET_OBJECT_FOR_KEY((dict),(val),(key))
//- (void)setObject:(ObjectType)anObject forKey:(KeyType <NSCopying>)aKey
#define CC_SET_OBJECT_FOR_KEY(dict,val,key) \
MyAssert(([(dict) isKindOfClass:[NSMutableDictionary class]]), DictTypeError); \
if ( (dict) != nil && \
    [(dict) isKindOfClass:[NSMutableDictionary class]]) \
{ \
    if ((key) != nil && [(key) isKindOfClass:[NSObject class]] && \
        (val) != nil && [(val) isKindOfClass:[NSObject class]] ) \
    { \
        if (MyHasSelector((dict),@selector(setObject:forKey:))) \
        { \
            [(NSMutableDictionary*)(dict) setObject:(id)(val) forKey:(id)(key)]; \
        } \
    }  else { \
        MyAssert((key) != nil, @"setObject: key is nil");\
        MyAssert(([(key) isKindOfClass:[NSObject class]]), KeyTypeError);\
        MyAssert((val) != nil, @"setObject: object is nil");\
        MyAssert(([(val) isKindOfClass:[NSObject class]]), ValTypeError);\
    } \
} else { \
    MyAssert((dict) != nil, @"setObject: dict is nil");\
    MyAssert(([(dict) isKindOfClass:[NSMutableDictionary class]]), DictTypeError);\
}

#if defined(DEBUG) && DEBUG

MyInline void CCNameSpace(CCTestNSMutableArray)() //macro test
{
    NSMutableArray * list = [NSMutableArray array];
    
    NSString * val = MyIntString(100);
    
    //list = nil;
    //val = nil;
    
    MyAddObject(list, val);
    MyAddObject(list, MyIntString(200));
    MyAddObject(list, MyIntegerString(300));
    MyAddObject(list, MyLongString(400));
    MyAddObject(list, MyFloatString(500));
    MyAddObject(list, MyDoubleString(600));
    MyAddObject(list, MyLongLongString(700));
    NSLog(@"%@", list);
    
    NSString * val3 = MyGetObjectAt(list, 100);
    NSLog(@"%@", val3);
    
    MyDelLastObject(list);
    MyDelFirstObject(list);
    NSLog(@"%@", list);
    
    val3 = MyGetObjectAt(list, 2);
    NSLog(@"%@", val3);
    
    NSLog(@"%@,%@", MyGetFirstObject(list), MyGetLastObject(list));
    
    MyDelObject(list, MyIntString(400));
    NSLog(@"%@", list);
    
    return;
}
#endif

#if defined(DEBUG) && DEBUG

MyInline void CCNameSpace(CCTestNSMutableDictionary)() //macro test
{
    NSMutableDictionary * dict = [NSMutableDictionary dictionary];
    
    NSString * key = @"test2";
    NSString * val = MyIntString(100);
    
    //list = nil;
    //val = nil;
    
    MySetObjectForKey(dict, val, @"test1");
    MySetObjectForKey(dict, MyFloatString(200), key);
    NSLog(@"%@", dict);
    
    //dict = nil;
    MyDelObjectForKey(dict, @"test1");
    NSLog(@"%@", dict);
    
    //dict = nil;
    //key = nil;
    NSString * test2 = MyGetObjectForKey(dict, key);
    NSLog(@"%d", MyIntValue(test2));
    
    MySetObjectForKey(dict, MyDoubleString(300), key);
    NSLog(@"%@", dict);
    
    NSString * value1 = MyGetObjectForKey(dict, @"test1");
    NSLog(@"%d", MyIntValue(value1));
    NSString * value2 = MyGetObjectForKey(dict, @"test2");
    NSLog(@"%d", MyIntValue(value2));
    
    //test key is not nil
    //key = nil; 
    value2 = (id)MyGetObjectForKey(dict, key);
    
    NSString * value3 =
    ((id)(((dict) && (key)) ? \
          (([(dict) isKindOfClass:[NSDictionary class]] || \
            [(dict) isKindOfClass:[NSMutableDictionary class]]) ? \
           ([(dict) objectForKey:(id)(key)]) : (id)nil) : \
          (id)nil));
    
    NSLog(@"%d", MyIntValue(value3));
    
    return;
}
#endif

#endif /* _CC_RUNTIME_UTILITY_H_ */
