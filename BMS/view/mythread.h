#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include "booklist.h"
#include <QMetaType>
#include <QMutex>
#include<QRunnable>
#include<QObject>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
    MyThread(BookList *bookList,int id);
    void say(int index);
    void run() override;
    BookList *bookList;

    static QMutex mutex;
    static bool visited[3000+1];
    int id;
signals:
    void exitSignal(int mode);
    void updateBooksSignal();


};

#endif // MYTHREAD_H
