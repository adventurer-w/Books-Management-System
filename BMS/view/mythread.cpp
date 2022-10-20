#include "mythread.h"
#include <QDebug>
#include <QMetaType>
MyThread::MyThread()
{

}
MyThread::MyThread(BookList *bookList){
    qRegisterMetaType<QList<QPersistentModelIndex>>("QList<QPersistentModelIndex>");
    qRegisterMetaType<QVector<int>>("QVector<int>");
    qRegisterMetaType<QVector<int>>("QVector<int>");

    qDebug()<< "booklist load"<<endl;
    this->bookList = bookList;
}


void MyThread::run(){
    int n=10;

    if(bookList==NULL)return ;
    while(true){
        this->bookList->loadBooks();
        if(bookList->curRecord>=500)break;
    }



}
