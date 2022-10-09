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

    loadBookDetail();
    setIcons();
    loadQss(":/qss/bookdetails/bookdetails.qss");
}

BookDetails::~BookDetails()
{
    delete ui;
}
void BookDetails::loadBookDetail(){
    ui->lb_author_2->setText(now_book.getAuthor());
    ui->lb_ISBN_2->setText(now_book.getIsbn());
    ui->lb_bookname2->setText(now_book.getBookName());
    ui->lb_publish_2->setText(now_book.getPublisher());
    ui->lb_grade_txt->setText(QString::number(now_book.getPoint()));
    ui->lb_intro_txt->setText(now_book.getIntroduction());
    ui->lb_remain_txt->setText(QString::number(now_book.getLeft())+"\\"+QString::number(now_book.getAllNum()));

    ui->lb_collect_txt->setText("未知");//后期判断是否需要增加收藏数

    ui->lb_classify_txt->setText(now_book.getClassifition());
    ui->lb_publishtime_txt->setText(now_book.getPublishDate());

    ui->lb_bookposition_txt->setText("未知");//后期判断是否需要增加图书位置
    ui->lb_historyborrow_txt->setText(QString::number(now_book.getHistoryNum()));

    QLabel *l1 = new QLabel();     //创建lable

    l1-> setFixedSize (120,150);

    string t1(now_book.getImgPath());
    string t2(now_book.getIsbn());
    string pic=":/image/cover/"+t1+"/"+t2+".jpg";

    if(t2.size()==13)
        pic=":/image/cover/"+t1+"/"+t2+".jpg";
    else
        pic=":/image/cover/moren.jpg";

    QPixmap pixmap(pic.c_str());
    QPixmap fitpixmap;
    if(pixmap.isNull()){
        QPixmap pixmap2(":/image/cover/moren.jpg");
        fitpixmap = pixmap.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }

    fitpixmap = pixmap.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    ui->lb_bookphoto->setPixmap(fitpixmap);    //加载图片

    ui->lb_bookphoto->setScaledContents(true);
    ui->lb_bookphoto->setAlignment(Qt::AlignCenter);      //设置居中

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



void BookDetails::on_btn_star_clicked(){//收藏

}

void BookDetails::on_btn_borrow_clicked(){//借阅
    Record record;
    if(now_book.getLeft()>0){
        record.setIsbn(now_book.getIsbn());
        record.setDate("2022-10-7");//后期增加自动获取时间
        record.setAuthor(now_book.getAuthor());
        record.setAccount(now_user.getAccount());
        record.setBookName(now_book.getBookName());
        record.setPublisher(now_book.getPublisher());



        //增加弹窗，提示借书成功与否



        bool f=now_utils.InsertRecord(record);
        if(f){
            //qDebug()<<"借书成功！";
            QMessageBox::information(this,"借阅书籍","小伙好手速，借书成功！");
            now_book.setLeft(now_book.getLeft()-1);
            Book bookt;
            bookt.setIsbn(now_book.getIsbn());
            int f2=now_utils.UpdateBook(bookt, now_book);
            if(!f2){
                //qDebug()<<"借阅书籍造成书籍信息错误！";
                QMessageBox::information(this,"借阅书籍","借阅书籍造成书籍信息错误！");
            }
        }else{
            //qDebug()<<"已借阅该图书！一种图书无法借阅两本";
            QMessageBox::information(this,"借阅书籍","已借阅该图书！一种图书无法借阅两本");
        }
    }else{
        //qDebug()<<"该图书无库存，如需要请预约！";
        QMessageBox::information(this,"借阅书籍","该图书无库存，如需要请预约！");
    }

}

void BookDetails::on_btn_reserve_clicked(){//预约
    Reserve reserve;
    reserve.setIsbn(now_book.getIsbn());
    reserve.setDate("2022-10-10");//后期增加自动获取时间
    reserve.setAuthor(now_book.getAuthor());
    reserve.setAccount(now_user.getAccount());
    reserve.setBookName(now_book.getBookName());
    reserve.setPublisher(now_book.getPublisher());
    //(！！需要没人预约且无人预约,否则会返回失败!!)
    bool f=now_utils.InsertReserve(reserve);
    if(f){
        //qDebug()<<"预约成功！";
        QMessageBox::information(this,"预约书籍","小伙好手速，预约成功！");
        now_book.setLeft(now_book.getLeft()-1);
    }else{
        //qDebug()<<"该图书已被预约，请静候";
        QMessageBox::information(this,"预约书籍","哎呀，差点就预约上了，换一本预约吧！");
    }
}
