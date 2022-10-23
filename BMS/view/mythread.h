#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include "booklist.h"
#include <QMetaType>
#include <QMutex>
#include<QRunnable>
#include<QObject>

#define MAX_RESOURCE_NUM 3001
class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
    MyThread(BookList *bookList,int id);
    void say(int index);//输出相关线程信息
    void run() override;//重写run方法，通过thread->start()将就绪线程转为运行时线程

    static QMutex mutex;//互斥锁
    static bool visited[MAX_RESOURCE_NUM];//资源变量

signals:
    void exitSignal(int mode);//用于主线程和子线程通信

private:
    BookList *bookList;
    int id;

};

#endif // MYTHREAD_H
