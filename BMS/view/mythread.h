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
};

#endif // MYTHREAD_H
