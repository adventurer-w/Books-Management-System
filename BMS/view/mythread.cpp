#include "mythread.h"
#include <QDebug>
#include <QMetaType>
#include "cstring"
#include "backend/all_head.h"
#include "backend/Utils.h"
#include "GlobalSetting.h"
MyThread::MyThread()
{

}
MyThread::MyThread(BookList *bookList){
    qRegisterMetaType<QList<QPersistentModelIndex>>("QList<QPersistentModelIndex>");
    qRegisterMetaType<QVector<int>>("QVector<int>");
    qRegisterMetaType<QVector<int>>("QVector<int>");

    this->bookList = bookList;
}

extern vector<Book> re;
void MyThread::run(){

    //qDebug()<< "your thread is running : "<< re.size();
    for(int i = 20; i<re.size();++i)
    {
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

       emit bookList->loadImgSignal(fitpixmap);
    }

    //qDebug()<< "exit :";

}
