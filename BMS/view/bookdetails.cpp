#include "bookdetails.h"
#include "ui_bookdetails.h"
#include <QFile>
#include <QMessageBox>
#include "backend/all_head.h"
#include <backend/Utils.h>
#include <backend/User.h>
#include <QDebug>

extern Utils now_utils;
extern User now_user;
extern vector<Book> re;
extern Book now_book;


BookDetails::BookDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookDetails)
{
    ui->setupUi(this);
    ui->lb_author_2->setText(now_book.getAuthor());
    ui->lb_ISBN_2->setText(now_book.getIsbn());
    ui->lb_bookname2->setText(now_book.getBookName());
    ui->lb_publish_2->setText(now_book.getPublisher());
    ui->lb_grade_txt->setText(QString::number(now_book.getPoint()));
    ui->lb_intro_txt->setText(now_book.getIntroduction());
    ui->lb_remain_txt->setText(QString::number(now_book.getLeft())+"\\"+QString::number(now_book.getAllNum()));
//    ui->lb_collect_txt->setText(now_book.get);收藏数
    ui->lb_classify_txt->setText(now_book.getClassifition());
    ui->lb_publishtime_txt->setText(now_book.getPublishDate());
//    ui->lb_bookposition_txt->setText(now_book.getClassifition());
    ui->lb_historyborrow_txt->setText(QString::number(now_book.getHistoryNum()));

    setIcons();
    loadQss(":/qss/bookdetails/bookdetails.qss");
}

BookDetails::~BookDetails()
{
    delete ui;
}
void BookDetails::setStackWidget(MainWidget *p){
    this->psw = p;
}
void BookDetails::setIcons(){
    /*将图标图片缩小到指定尺寸*/
    QPixmap pixmap(":/image/querybook/back.png");
    QPixmap fitpixmap = pixmap.scaled(35, 35, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->btn_back->setIcon(QIcon(fitpixmap));
    ui->btn_back->setIconSize(QSize(35, 35));
    ui->btn_back->setFlat(true);
}
bool BookDetails::loadQss(const QString &StyleSheetFile){
    /*QSS文件所在的路径*/
    QFile ofile(StyleSheetFile);
    bool Ret = ofile.open(QFile::ReadOnly);

    if (!Ret)
    {
         QMessageBox::information(this,"Tip_bookdetails",ofile.errorString());
         return false;
    }

    this->setStyleSheet(ofile.readAll());
    ofile.close();

}

void BookDetails::on_btn_back_clicked(){
    psw->setCurrentIndex(1);
}

void BookDetails::on_btn_back_doubleclicked(){
    psw->setCurrentIndex(0);
}

void BookDetails::on_pushButton_clicked(){//收藏

}

void BookDetails::on_pushButton_2_clicked(){//借阅
    Record record;
    record.setIsbn(now_book.getIsbn());
    record.setDate("2022-10-7");//后期增加自动获取时间
    record.setAuthor(now_book.getAuthor());
    record.setAccount(now_user.getAccount());
    record.setBookName(now_book.getBookName());
    record.setPublisher(now_book.getPublisher());
    int f=now_utils.InsertRecord(record);
    qDebug()<<"是否借书成功"<<f<<"\n\n";
}

void BookDetails::on_pushButton_3_clicked(){//预约

}
