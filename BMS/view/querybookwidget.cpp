#include "querybookwidget.h"
#include "ui_querybookwidget.h"
#include "booklist.h"
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QTableView>
#include <QStandardItem>
#include <QStandardItemModel>
#include "stditemmodel.h"
#include "querybookwidget.h"
#include "ui_userprofilewidget.h"
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
#include "ui_searchlineedit.h"
#include "bookranking.h"
#include <QListView>
#include "backend/Utils.h"
//#include "mythread.h"
#include "threadpool.h"
#include <stdio.h>
extern Utils now_utils;
extern vector<Book> re;
extern Book now_book;
static ThreadPool *Pool;
QueryBookWidget::QueryBookWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QueryBookWidget),
    sub_mw(new MainWidget)
{
    ui->setupUi(this);


    ui->btn_bookname->setAutoExclusive(false);
    ui->btn_ISBN->setAutoExclusive(false);
    ui->btn_author->setAutoExclusive(false);


    ui->cbox_classify->addItems(QStringList()<<"全部");
    vector<BookClass> classifications;
    now_utils.GetAllClass(classifications);
    for(int i=0;i<classifications.size();i++)
        ui->cbox_classify->addItem(QString::fromStdString(classifications[i].getName()));

    ui->cbox_classify->setCurrentIndex(0);//设置默认选项
    loadPages();

    setShadow();
    QString qssfile = ":/qss/querybookwidget/querybook.qss";
    loadQss(qssfile);

}

QueryBookWidget::~QueryBookWidget()
{
    delete ui;

}


void QueryBookWidget::setShadow(){

    QAbstractItemView* view =
    ui->cbox_classify->view();

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(6);
    effect->setColor(Qt::black);
    effect->setOffset(0, 0);
    view->setGraphicsEffect(effect);
    view->update();

    static_cast<QWidget*>(view->parent())
      ->setStyleSheet(
          "QWidget{border:none;background-color: rgb(255, 255, 255);}");

    QWidget* container = static_cast<QWidget*>(view->parent());
    container->setAttribute(Qt::WA_TranslucentBackground);
    container->setWindowFlag(Qt::FramelessWindowHint);
    container->setWindowFlag(Qt::NoDropShadowWindowHint);




}
void QueryBookWidget::paintEvent(QPaintEvent *event)

{



    QPainter paint(this);
    paint.setPen(Qt::gray);
   // paint.drawLine(0,220,50,50);

    QPainter painter(this);//初始化
    QPixmap pix;
    //背景图
    pix.load(":/image/querybook/background.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

void QueryBookWidget::loadPages(){
    sub_mw->resize(1300,730);
    sub_mw->move(this->x(),this->y()+170);
    sub_mw->setParent(this);


    /*默认导入 个人信息页面*/
    BookRanking *bookRanking = new BookRanking;
    bookRanking->resize(1300,730);

    sub_mw->insertWidget(0,bookRanking);
    sub_mw->setCurrentIndex(0);
    bookRanking->psw = sub_mw;

    BookList *bookList = new BookList;
    bookList->resize(1300,730);
    sub_mw->insertWidget(1,bookList);

}

int flag=0;//1书名，2作者，3isbn

void QueryBookWidget::on_btn_bookname_clicked()
{
    if(flag == 1){
        flag=0;
        ui->btn_bookname->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }
    else {

        flag=1;
        ui->btn_bookname->setStyleSheet("color:rgb(255,255,255);\
                                        background-color:rgb(121,109,111);");
        ui->btn_author->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
        ui->btn_ISBN->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }
}

void QueryBookWidget::on_btn_author_clicked()
{
    if(flag == 2){
        flag=0;
        ui->btn_author->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }
    else {

        flag=2;
        ui->btn_author->setStyleSheet("color:rgb(255,255,255);\
                                        background-color:rgb(121,109,111);");
        ui->btn_bookname->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
        ui->btn_ISBN->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }

}

void QueryBookWidget::on_btn_ISBN_clicked()
{
    if(flag == 3){
        flag=0;
        ui->btn_ISBN->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }
    else {
        flag=3;
        ui->btn_ISBN->setStyleSheet("color:rgb(255,255,255);\
                                        background-color:rgb(121,109,111);");
        ui->btn_bookname->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
        ui->btn_author->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }
}


void QueryBookWidget::on_cbox_classify_currentIndexChanged(int){
    flag=0;
    ui->btn_ISBN->setStyleSheet("color:rgb(0,0,0);\
                                font-family:KaiTi;\
                                font-size:18px;\
                                font-weight:normal;\
                                padding:4px;");
    ui->btn_bookname->setStyleSheet("color:rgb(0,0,0);\
                                    font-family:KaiTi;\
                                    font-size:18px;\
                                    font-weight:normal;\
                                    padding:4px;");
    ui->btn_author->setStyleSheet("color:rgb(0,0,0);\
                                    font-family:KaiTi;\
                                    font-size:18px;\
                                    font-weight:normal;\
                                    padding:4px;");
}
/*
通过类别和key来得到符合条件的书本数据

*/
void QueryBookWidget::getBookList(QString classification, QString key){
    if(key.size()>BOOK_NAME_SIZE-1)
        QMessageBox::information(this,"提示信息","输入字符过长");
    else{
        re.clear();
        string info;
        if(flag==0){
            ui->lineEdit->clear();
            if(classification=="全部"){
                if(key!="")
                    now_utils.GetBooksByBookNameLike(const_cast<char*>(key.toStdString().c_str()),re);
            }else{
                vector<BookClass> result;
                now_utils.GetClassByName(const_cast<char*>(classification.toStdString().c_str()),result);
                now_utils.GetBooksByClassNo(result[0].getClassNo(),re);
            }
        }else if(flag==1){
            if(key.size()==0)
                info="请输入书名！";
            else
                now_utils.GetBooksByBookNameLike(const_cast<char*>(key.toStdString().c_str()),re);
//                now_utils.GetBooksByBookName(const_cast<char*>(key.toStdString().c_str()),re);

        }else if(flag==2){
            qDebug()<<key;
            if(key.size()==0)
                info="请输入作者名！";
            else
                now_utils.GetBooksByAuthorLike(const_cast<char*>(key.toStdString().c_str()),re);
//                now_utils.GetBooksByAuthor(const_cast<char*>(key.toStdString().c_str()),re);
        }else if(flag==3){
            if(key.size()==0)
                info="请输入ISBN号！";
            else if(key.size()!=13)
                info="ISBN号输入错误，请输入13位数字（无-隔开）";
            else{
                re.clear();
                Book bt;
                    if(now_utils.GetBookByIsbn(const_cast<char*>(key.toStdString().c_str()),bt))
                        re.push_back(bt);
            }

        }else{
            QMessageBox::information(this,"提示信息","查询错误，请重试！");
        }
        if(info.size()==0){
            if(re.size()==0)
            {
                QMessageBox::information(this,"提示信息","馆中暂时没有该书！");
            }
            else{
                BookList *bookList =new BookList();
                bookList->resize(1300,730);
                bookList->move(this->x(),this->y()+170);

                bookList->setStackWidget(sub_mw);
                sub_mw->insertWidget(1,bookList);
                sub_mw->setCurrentIndex(1);

                //            for(int i=0; i<10; ++i){
                //                thread[i] = new MyThread(bookList,i);
                //                thread[i]->start();
                //            }
                Pool = new ThreadPool(12,bookList);
                //Pool->ThreadPool::~ThreadPool();
                Pool->startAll();
            }
        }else{
            QMessageBox::information(this,"提示信息",QString::fromStdString(info));
        }

    }

}

void QueryBookWidget::killThread(){
    //thread->quit();
}
void QueryBookWidget::on_btn_search_clicked()
{

    QString classification=ui->cbox_classify->currentText();
    QString val=ui->lineEdit->text();
    getBookList(classification,val);

}

void QueryBookWidget::on_lineEdit_returnPressed()
{
    /*write code here*/


    /*add BookList new constructor function or other functions to Pass Parameters*/
    BookList *bookList =new BookList();
    bookList->resize(1300,730);
    sub_mw->insertWidget(1,bookList);
    sub_mw->setCurrentIndex(1);
}

bool QueryBookWidget::loadQss(const QString &StyleSheetFile){

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
