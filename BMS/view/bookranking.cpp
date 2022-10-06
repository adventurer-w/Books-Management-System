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


void BookRanking::showPopularBook(){
     QPixmap pix;
     pix.load(":/image/querybook/live.jpg");
    ui->lb_book1->setPixmap(pix);//label 加载图片imgpath
    ui->lb_book1->setScaledContents(true);    //根据label大小缩放图片
     ui->lb_bookname1->setText("活着");
    // 根据label宽度等比例缩放图片
    //ui->lb_book1->setPixmap(pix.scaledToWidth(ui->lb_book1->width()));

    // 根据label高度等比例缩放图片
    //ui->lb_book1->setPixmap(pix.scaledToHeight(ui->lb_book1->height()));

//    QImage *image=new QImage;
//    image->load(":/image/querybook/live.jpg");
//    ui->lb_book1->setPixmap(QPixmap::fromImage(*image));
//    ui->lb_book1->resize(image->width(),image->height());
//    ui->lb_bookname1->setText("活着");
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
