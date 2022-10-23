#include "threadpool.h"
#include <QDebug>
ThreadPool::ThreadPool()
{
    maxThreadsNum = MAX_DEFAULT_THREAD_NUM;
    threads = NULL;
    runnableThreadsNum=0;
}

ThreadPool::ThreadPool(int threadNum)
{
    maxThreadsNum = MAX_DEFAULT_THREAD_NUM;
    if(threadNum > maxThreadsNum){
        qDebug()<< "threads out of the limited! fail to create threads";
        return;
    }
    *threads = new MyThread[threadNum];
    for(int i=0; i<threadNum;++i){
        threads[i]=new MyThread();

    }
    runnableThreadsNum = threadNum;

}
ThreadPool::ThreadPool(int threadNum,BookList *bookList){
    maxThreadsNum = MAX_DEFAULT_THREAD_NUM;
    runningThreadsNum=0;
//    if(runnableThreadsNum>0 ){
//        for(int i=0; i< runnableThreadsNum; ++i){
//            if(threads[i]->isRunning())threads[i]->quit();
//            if(threadNum>runnableThreadsNum){
//                delete []threads[i];
//                qDebug()<< "Thread "<< i << " has been destroyed";
//            }
//        }
//        if(threadNum >runnableThreadsNum)delete threads;
//    }

    if(threadNum > maxThreadsNum){
        qDebug()<< "threads out of the limited! fail to create threads";
        return;
    }
    threads = new MyThread*[threadNum];
    for(int i=0; i<threadNum;++i){
        threads[i]=new MyThread(bookList,i);
        //threads[i]->run();

    }
    runnableThreadsNum = threadNum;
}
void ThreadPool::startAll(){

    if(threads == NULL){
        qDebug()<< "there's no thread in the pool!";
        return;
    }
    if(runnableThreadsNum <=0){
            qDebug()<< "there's no runnable thread in the pool!";
            return;
    }
    runningThreadsNum=runnableThreadsNum;
    for(int i=0; i<runnableThreadsNum;++i){
        threads[i]->start();
        connect(threads[i],SIGNAL(exitSignal(int)),this,SLOT(runningThreadListener(int)));
        //qDebug()<< "Thread "<< i << " is runnning";
    }

}
void ThreadPool::runningThreadListener(int mode){
    if(mode == 0){
        runningThreadsNum--;
    if(runningThreadsNum==0 && runnableThreadsNum>0){
        //qDebug()<< "destroy all threads!";
        destroyAll();
    }}
}
void ThreadPool::destroyAll(){
    for(int i=0; i< runnableThreadsNum; ++i){
        if(threads[i]->isRunning()){
            threads[i] ->disconnect();//然后使用
            threads[i]->quit();
            threads[i]->wait();
            qDebug()<< "Thread "<< i << " has been force quit";
        }

    }
    if(runnableThreadsNum > 0){
        for(int i=0; i< runnableThreadsNum; ++i){
            threads[i]->deleteLater();
            //qDebug()<< "Thread "<< i << " has been destroyed";
        }
        delete [] threads;
        runnableThreadsNum = 0;
    }
    else{
        threads = NULL;
        runnableThreadsNum = 0;
    }
}

ThreadPool::~ThreadPool(){
    for(int i=0; i< runnableThreadsNum; ++i){
        if(threads[i]->isRunning())threads[i]->quit();
    }
    if(runnableThreadsNum > 0){
        for(int i=0; i< runnableThreadsNum; ++i){
            delete []threads[i];
            //qDebug()<< "Thread "<< i << " has been destroyed";
        }
        delete []threads;
        runnableThreadsNum = 0;
    }
    else{
        threads = NULL;
        runnableThreadsNum = 0;
    }
}
