#ifndef THREADPOOL_H
#define THREADPOOL_H

#include "mythread.h"
#define MAX_DEFAULT_THREAD_NUM 16
class ThreadPool :QObject
{
    Q_OBJECT
public:
    ThreadPool();
    ThreadPool(int threadNum);
    ThreadPool(int threadNum,BookList *bookList);
    ~ThreadPool();

    void startAll();
    void destroyAll();
private slots:
    void runningThreadListener(int mode);
private:
    MyThread **threads;      //线程指针
    int maxThreadsNum;      //最大线程数量
    int runnableThreadsNum;//就绪线程数量
    int runningThreadsNum;//运行线程数量
};

#endif // THREADPOOL_H
