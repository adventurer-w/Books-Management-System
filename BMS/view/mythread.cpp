#include "mythread.h"
#include <QDebug>
#include <QMetaType>
#include "cstring"
#include "backend/all_head.h"
#include "backend/Utils.h"
#include "GlobalSetting.h"
#include <QMutex>
MyThread::MyThread()
{

}
MyThread::MyThread(BookList *bookList,int id){
    qRegisterMetaType<QList<QPersistentModelIndex>>("QList<QPersistentModelIndex>");
    qRegisterMetaType<QVector<int>>("QVector<int>");
    qRegisterMetaType<QVector<int>>("QVector<int>");

    this->bookList = bookList;
    this->id = id;
    if(id == 0){
        for(int i=0; i<2001; ++i){
            visited[i]=false;

        }
    }
}

extern vector<Book> re;
QMutex MyThread::mutex; //分配空间
bool MyThread::visited[3000+1];
void MyThread::run(){

    //qDebug()<< "your thread is running : "<< re.size();
    if(bookList == NULL){emit exitSignal(0);return ;}
    for(int i = 20; i<re.size();++i)
    {
        if(visited[i]==true)continue;
        mutex.lock();
        if(visited[i]==true){
            mutex.unlock();
            continue;
        }
        else visited[i]=true;
        mutex.unlock();
        string t1(re[i].getImgPath());
        string t2(re[i].getIsbn());
        string pic;
        if(t2.size()==13)
                   pic=pictureDbPath+t1;
               else
                   pic=pictureDbPath+"moren.jpg";

       QPixmap pixmap(pic.c_str());
       QPixmap fitpixmap;
       if(pixmap.isNull()){
           QPixmap pixmap2((pictureDbPath+"moren.jpg").c_str());
              //qDebug() << "null" << i;
           fitpixmap = pixmap2.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
       }else{
           fitpixmap = pixmap.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

       }

       emit bookList->loadImgSignal(fitpixmap,i);


       //say(i);

    }
    emit exitSignal(0);
    //qDebug()<< "exit thread "<< id ;

}
void MyThread::say( int index){
    qDebug()<< "thread"<<id<< " get index:"<<index;
}
