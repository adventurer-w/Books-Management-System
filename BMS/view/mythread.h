#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include "booklist.h"
#include <QMetaType>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
    MyThread(BookList *bookList);

    void run() override;
    BookList *bookList;
signals:
    void exitSignal();
    void updateBooksSignal();


};

#endif // MYTHREAD_H
