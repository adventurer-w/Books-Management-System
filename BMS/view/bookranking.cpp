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
#include "QFontDialog"
#include "searchlineedit.h"
#include"backend/all_head.h"
#include"backend/Utils.h"
#include"GlobalSetting.h"
#include "bookdetails.h"
#include "qclickedlabel.h"
#include "GlobalSetting.h"
extern Utils now_utils;
extern Book now_book;
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
        pic=pictureDbPath+t1;
    else
        pic=pictureDbPath+"moren.jpg";


   QPixmap pixmap(pic.c_str());
   QPixmap fitpixmap;
   if(pixmap.isNull()){

       QPixmap pixmap2((pictureDbPath+"moren.jpg").c_str());
       fitpixmap = pixmap2.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
   }else{
       fitpixmap = pixmap.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
   }

    return fitpixmap;

}

void BookRanking::navigateToDetails(){

    QLabel *lb = (QLabel*)sender();
    //提取按钮的自定义属性 数据类型须统一
    QString ISBN = lb->property("lb_ISBN").toString();//根据ISBN删借阅信息
    now_utils.GetBookByIsbn(const_cast<char*>(ISBN.toStdString().c_str()),now_book);
    BookDetails *bookDetails= new BookDetails();
    bookDetails->resize(1300,730);
    bookDetails->move(0,170);
    bookDetails->setPreIndex(0);
    bookDetails->setStackWidget(psw);
    psw->insertWidget(2,bookDetails);
    psw->setCurrentIndex(2);
}
/*
 @author yuan
 @func show borrow rank

*/
void BookRanking::showBorrowRank(){

    QPixmap pix[7];//展示本书，后期可更改
    for(int i=0;i<7;i++){
        pix[i]=p(string(result[i].getImgPath()),string(result[i].getIsbn()));
    }

    int pos_x = 30;
    int pos_y = 80;

    for(int i=0; i<7; ++i){
        QClickedLabel *clb = new QClickedLabel;
        QClickedLabel *clb_txt = new QClickedLabel;
        clb->setParent(this);
        clb_txt->setParent(this);
        clb->setPixmap(pix[i]);
        clb->setScaledContents(true);    //根据label大小缩放图片
        clb->resize(130,170);
        clb->move(pos_x,pos_y);
        clb_txt->setText(result[i].getBookName());
        clb_txt->resize(110,30);
        clb_txt->move(pos_x,pos_y+180);
        clb->setProperty("lb_ISBN",result[i].getIsbn());
        clb_txt->setProperty("lb_ISBN",result[i].getIsbn());
        connect(clb,SIGNAL(clicked()),this,SLOT(navigateToDetails()));
        connect(clb_txt,SIGNAL(clicked()),this,SLOT(navigateToDetails()));
        pos_x+=170;
    }


}
void BookRanking::showHighScoreRank(){
    int rankMaxItems = 3;//每个榜单展示最大三个项
    int Ranks = 3;//一共四个榜单
    int rankItemHeight = 60;//每个榜单单项的高度
    vector<vector<Book>> results = {result_point,result_boy,result_girl};
    int pos_x = 130;
    int pos_y = 490;
    for(int i= 0; i< Ranks; ++i){
//        qDebug()<< "i: " << i;
        vector<Book> item= results[i];
//        qDebug()<< "item: " << item[i];
        for(int j=0; j< rankMaxItems; ++j){
            QClickedLabel *clb = new QClickedLabel;
            clb->setParent(this);
            clb->resize(165,40);
            clb->move(pos_x,pos_y);
            clb->setProperty("lb_ISBN",item[j].getIsbn());
            clb->setText(item[j].getBookName());
            connect(clb,SIGNAL(clicked()),this,SLOT(navigateToDetails()));
            pos_y+=rankItemHeight;
        }
        pos_x+=300;
        pos_y=490;
    }
}

void BookRanking::showPopularBook(){

    showBorrowRank();
    showHighScoreRank();
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
