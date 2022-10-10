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

extern Utils now_utils;
extern vector<Book> re;
extern Book now_book;

QueryBookWidget::QueryBookWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QueryBookWidget),
    sub_mw(new MainWidget)
{
    ui->setupUi(this);


    ui->btn_bookname->setAutoExclusive(false);
    ui->btn_ISBN->setAutoExclusive(false);
    ui->btn_author->setAutoExclusive(false);

    ui->cbox_classify->addItems(QStringList()<<"全部"<<"历史"<<"散文"<<"科幻"<<"互联网"<<"传记"<<"推理");
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

}

int flag=0;//1书名，2作者，3isbn
int ctrl = 0x000;
void QueryBookWidget::on_btn_bookname_clicked(){

    if((ctrl>>8) % 2 == 1){
        ui->btn_bookname->setDown(false);
        ctrl &= 0x011;
        //qDebug() << "clear bookname " << ctrl ;

        ui->btn_bookname->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }
    else {

        ui->btn_bookname->setDown(true);
        ctrl |= 0x100;
        //qDebug() << "add bookname " << ctrl ;
        flag=1;
        ui->btn_bookname->setStyleSheet("color:rgb(255,255,255);\
                                        background-color:rgb(121,109,111);");
    };



}

void QueryBookWidget::on_btn_author_clicked(){
    if((ctrl>>4) % 2 == 1){
        ui->btn_author->setDown(false);
        ctrl &= 0x101;
        //qDebug() << "clear author name " << ctrl ;

        ui->btn_author->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }
    else {
        ui->btn_author->setDown(true);
        ctrl |= 0x010;
        //qDebug() << "add author name " << ctrl ;
        flag=2;
        ui->btn_author->setStyleSheet("color:rgb(255,255,255);\
                                        background-color:rgb(121,109,111);");
    };


}

void QueryBookWidget::on_btn_ISBN_clicked(){
    if((ctrl) % 2 == 1){
        ui->btn_ISBN->setDown(false);
        ctrl &= 0x110;
        //qDebug() << "clear ISBNname " << ctrl ;

        ui->btn_ISBN->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }

    else {
        ui->btn_ISBN->setDown(true);
        ctrl |= 0x001;
        //qDebug() << "add ISBNname " << ctrl ;
        flag=3;
        ui->btn_ISBN->setStyleSheet("color:rgb(255,255,255);\
                                        background-color:rgb(121,109,111);");
    };


}

void QueryBookWidget::on_cbox_classify_currentIndexChanged(int){
    flag=0;
}
/*
通过类别和key来得到符合条件的书本数据

*/
void QueryBookWidget::getBookList(QString classification, QString key){
    re.clear();
    if (classification=="全部" && ctrl == 0)flag=1;
    //qDebug() << classification << "  "<< flag;
    if(flag==0){
        now_utils.GetBooksByClassification(const_cast<char*>(classification.toStdString().c_str()),re);
    }else if(flag==1){
        now_utils.GetBooksByBookName(const_cast<char*>(key.toStdString().c_str()),re);
    }else if(flag==2){
        now_utils.GetBooksByAuthor(const_cast<char*>(key.toStdString().c_str()),re);
    }else{
        now_utils.GetBookByIsbn(const_cast<char*>(key.toStdString().c_str()),now_book);
        re.push_back(now_book);
    }
//    if(re.size()!=0)
//        qDebug()<<"书名"<<re[0].getBookName();
    BookList *bookList =new BookList();
    bookList->resize(1300,730);
    bookList->setStackWidget(sub_mw);
    sub_mw->insertWidget(1,bookList);
    sub_mw->setCurrentIndex(1);


}
void QueryBookWidget::on_btn_search_clicked()
{
    /*write code here*/


    /*add BookList new constructor function or other functions to Pass Parameters*/

    QString classification=ui->cbox_classify->currentText();
    QString val=ui->lineEdit->text();

    //qDebug()<<"分类"<<classification;
    //qDebug()<<"搜索值"<<val;


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
