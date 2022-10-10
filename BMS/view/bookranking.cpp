#include "bookranking.h"
#include "ui_bookranking.h"
#include "booklist.h"
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QTableView>
#include <QStandardItem>
#include <QStandardItemModel>
#include "stditemmodel.h"
#include "querybookwidget.h"
#include<QPushButton>
#include "QPainter"
#include "QDebug"
#include "QFrame"
#include <QLabel>
#include <QLayout>
#include <QColor>
#include <QFile>
#include <QMessageBox>
#include<QScrollBar>
#include <QString>
#include <QStackedLayout>
#include "MainWidget.h"
#include"QFontDialog"
#include "searchlineedit.h"
#include"backend/all_head.h"
#include"backend/Utils.h"
#include"GlobalSetting.h"
extern Utils now_utils;
extern vector<Book> result;
extern vector<Book> result_boy;
extern vector<Book> result_girl;
extern vector<Book> result_point;
BookRanking::BookRanking(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookRanking)
{
    ui->setupUi(this);
    setShadow();
    showPopularBook();
    loadQss(":/qss/bookranking/bookranking.qss");
}


void BookRanking::setShadow(){
    //设置阴影
   this->setStyleSheet("background-color: rgb(255, 255, 255);");
   ui->fm_collect->setStyleSheet("background-color: rgb(0, 0, 0);");
   ui->fm_collect->setStyleSheet("border-radius:8px;");
   ui->fm_man->setStyleSheet("background-color: rgb(0, 0, 0);");
   ui->fm_man->setStyleSheet("border-radius:8px;");
   ui->fm_woman->setStyleSheet("background-color: rgb(0, 0, 0);");
   ui->fm_woman->setStyleSheet("border-radius:8px;");
   ui->fm_newbook->setStyleSheet("background-color: rgb(0, 0, 0);");
   ui->fm_newbook->setStyleSheet("border-radius:8px;");
   //设置具体阴影
   QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
   shadow_effect->setOffset(0, 0);
   //阴影颜色
   shadow_effect->setColor(QColor(38, 78, 119, 127));
   //阴影半径
   shadow_effect->setBlurRadius(22);

   //设置具体阴影
   QGraphicsDropShadowEffect *shadow_effect1 = new QGraphicsDropShadowEffect(this);
   shadow_effect1->setOffset(0, 0);
   //阴影颜色
   shadow_effect1->setColor(QColor(38, 78, 119, 127));
   //阴影半径
   shadow_effect1->setBlurRadius(22);

   QGraphicsDropShadowEffect *shadow_effect2 = new QGraphicsDropShadowEffect(this);
   shadow_effect2->setOffset(0, 0);
   //阴影颜色
   shadow_effect2->setColor(QColor(38, 78, 119, 127));
   //阴影半径
   shadow_effect2->setBlurRadius(22);

   QGraphicsDropShadowEffect *shadow_effect3 = new QGraphicsDropShadowEffect(this);
   shadow_effect3->setOffset(0, 0);
   //阴影颜色
   shadow_effect3->setColor(QColor(38, 78, 119, 127));
   //阴影半径
   shadow_effect3->setBlurRadius(22);

   ui->fm_collect->setGraphicsEffect(shadow_effect);
   ui->fm_man->setGraphicsEffect(shadow_effect1);
   ui->fm_woman->setGraphicsEffect(shadow_effect2);
   ui->fm_newbook->setGraphicsEffect(shadow_effect3);
}

QPixmap p(string t1,string t2){
    string pic;
    if(t2.size()==13)
        pic=pictureDbPath+t1+"/"+t2+".jpg";
    else
        pic=pictureDbPath+"moren.jpg";
    QPixmap pixmap(pic.c_str());
    return pixmap;

}



void BookRanking::showPopularBook(){


//    if(now_utils.UpdateBookRank())
//        qDebug()<<"总借阅榜单update成功！";

    QPixmap pix[7];//展示本书，后期可更改
    for(int i=0;i<7;i++){
        pix[i]=p(result[i].getImgPath(),result[i].getIsbn());
    }
    ui->lb_book1->setPixmap(pix[0]);//label 加载图片imgpath
    ui->lb_book1->setScaledContents(true);    //根据label大小缩放图片
    ui->lb_bookname1->setText(result[0].getBookName());

    ui->lb_book2->setPixmap(pix[1]);//label 加载图片imgpath
    ui->lb_book2->setScaledContents(true);    //根据label大小缩放图片
    ui->lb_bookname2->setText(result[1].getBookName());

    ui->lb_book3->setPixmap(pix[2]);//label 加载图片imgpath
    ui->lb_book3->setScaledContents(true);    //根据label大小缩放图片
    ui->lb_bookname3->setText(result[2].getBookName());

    ui->lb_book4->setPixmap(pix[3]);//label 加载图片imgpath
    ui->lb_book4->setScaledContents(true);    //根据label大小缩放图片
    ui->lb_bookname4->setText(result[3].getBookName());

    ui->lb_book5->setPixmap(pix[4]);//label 加载图片imgpath
    ui->lb_book5->setScaledContents(true);    //根据label大小缩放图片
    ui->lb_bookname5->setText(result[4].getBookName());

    ui->lb_book6->setPixmap(pix[5]);//label 加载图片imgpath
    ui->lb_book6->setScaledContents(true);    //根据label大小缩放图片
    ui->lb_bookname6->setText(result[5].getBookName());

    ui->lb_book7->setPixmap(pix[6]);//label 加载图片imgpath
    ui->lb_book7->setScaledContents(true);    //根据label大小缩放图片
    ui->lb_bookname7->setText(result[6].getBookName());


//    if(now_utils.UpdateBoyRank())
//        qDebug()<<"男生借阅排行榜update成功！";


    ui->lb_man1->setText(result_boy[0].getBookName());
    ui->lb_man2->setText(result_boy[1].getBookName());
    ui->lb_man3->setText(result_boy[2].getBookName());

//    if(now_utils.UpdateGirlRank())
//        qDebug()<<"女生借阅排行榜update成功！";


    ui->lb_woman1->setText(result_girl[0].getBookName());
    ui->lb_woman2->setText(result_girl[1].getBookName());
    ui->lb_woman3->setText(result_girl[2].getBookName());

//    if(now_utils.UpdatePointRank())
//        qDebug()<<"高分借阅排行榜update成功！";


    ui->lb_collect1->setText(result_point[0].getBookName());
    ui->lb_collect2->setText(result_point[1].getBookName());
    ui->lb_collect3->setText(result_point[2].getBookName());


}
bool BookRanking::loadQss(const QString &StyleSheetFile){

        /*QSS文件所在的路径*/
        QFile ofile(StyleSheetFile);
        bool Ret = ofile.open(QFile::ReadOnly);

        if (!Ret)
        {
             QMessageBox::information(this,"Tip_querybook",ofile.errorString());
             return false;
        }

        this->setStyleSheet(ofile.readAll());
        ofile.close();

}

BookRanking::~BookRanking()
{
    delete ui;
}
