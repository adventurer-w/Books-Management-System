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
    MyThread **threads;
    int maxThreadsNum;
    int runnableThreadsNum;
    int runningThreadsNum;
};

#endif // THREADPOOL_H
