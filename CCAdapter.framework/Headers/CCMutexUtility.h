//
//  CCMutexUtility.h
//  Net263CCLite_IOS
//
//  Created by yiyimama on 16/4/13.
//  Copyright © 2016年 yiyimama. All rights reserved.
//

#ifndef _Net263CCLite_IOS_CCStdMutex_h_
#define _Net263CCLite_IOS_CCStdMutex_h_

#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

#import "CCRuntime.h"

class CCNameSpace(MyStdMutex)
{
private:
    pthread_mutex_t m_mutex;
    
public:
    CCNameSpace(MyStdMutex)()
    {
        pthread_mutex_init( &m_mutex, 0 );
    }
    
    virtual ~CCNameSpace(MyStdMutex)()
    {
        pthread_mutex_destroy( &m_mutex );
    }
    
    int lock()
    {
        return pthread_mutex_lock( &m_mutex );
    }
    
    int unlock()
    {
        return pthread_mutex_unlock( &m_mutex );
    }
};

typedef CCNameSpace(MyStdMutex) CCMyStdMutex;
typedef CCNameSpace(MyStdMutex) CC_STD_MUTEX;

template
<class CCNameSpace(MyStdMutex)>
class CCNameSpace(MyStdLockGuard)
{
private:
    typedef CCNameSpace(MyStdMutex) mutex_type;
    
    mutex_type& m_mutex;
    
public:
    CCNameSpace(MyStdLockGuard)(mutex_type & m) : m_mutex(m)
    {
        m_mutex.lock(); // local var create
    }
    
    virtual ~CCNameSpace(MyStdLockGuard)() // unlock when func ret 
    {
        m_mutex.unlock(); // local var dealloc
    }
};

typedef CCNameSpace(MyStdLockGuard)<CCNameSpace(MyStdMutex)> CCMyStdLockGuard;
typedef CCNameSpace(MyStdLockGuard)<CCNameSpace(MyStdMutex)> CC_STD_LOCK_GUARD;


#endif //_Net263CCLite_IOS_CCStdMutex_h_