#ifndef THREAD_H_
#define THREAD_H_
#include "Common.h"
#define MYLOG(fmt, ...) printf(("%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);printf("\n")
class Thread {
public:
    Thread();
    virtual ~Thread();
public:
    virtual void     run(){ MYLOG("Hello ThreadTest.");};
    void            start();
    void            stop();
    int             GetPriority();
    void            SetPriority(int priority);
public:
    static  void    Sleep(int time);
    void    yield();
    static  int     GetMaxPriority();
    static  int     GetMinPriority();
private:
#ifdef WP8
        std::thread* threadID;
#else
        pthread_t   threadID;
#endif
        int         priority;
    };
#endif
