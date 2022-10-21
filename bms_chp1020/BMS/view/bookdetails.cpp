#include "bookdetails.h"
#include "ui_bookdetails.h"
#include <QFile>
#include <QMessageBox>
#include "backend/all_head.h"
#include <backend/Utils.h>
#include <backend/User.h>
#include <QDebug>
#include "GlobalSetting.h"
#include <qdatetime.h>
extern Utils now_utils;
extern User now_user;
extern vector<Book> re;
extern Book now_book;
extern vector<BookClass> now_book_class;


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
    ui->lb_bookname1->setText(now_book.getBookName());
    ui->lb_publish_2->setText(now_book.getPublisher());
    ui->lb_grade_txt->setText(QString::number(now_book.getPoint()));
    ui->lb_remain_txt->setText(QString::number(now_book.getLeft())+"/"+QString::number(now_book.getAllNum()));

    ui->lb_collect_txt->setText("未知");//后期判断是否需要增加收藏数
    vector<BookClass> now_book_class;
    now_utils.GetClassByNo(now_book.getClassNo(),now_book_class);
    ui->lb_classify_txt->setText(now_book_class[0].getName());
    ui->lb_publishtime_txt->setText(now_book.getPublishDate());

    ui->lb_bookposition_txt->setText("未知");//后期判断是否需要增加图书位置

    ui->lb_historyborrow_txt->setText(QString::number(now_book.getHistoryNum()));
//    ui->lb_intro_txt->setText(now_book.getIntroduction());

    QLabel *l1 = new QLabel();     //创建lable

    l1-> setFixedSize (120,150);

    string t1(now_book.getImgPath());
    string t2(now_book.getIsbn());
    string pic;
    if(t2.size()==13)
               pic=pictureDbPath+t1;
           else
               pic=pictureDbPath+"moren.jpg";

    QPixmap pixmap(pic.c_str());
   QPixmap fitpixmap;
   if(pixmap.isNull()){
//       qDebug()<<"1空";
       QPixmap pixmap2((pictureDbPath+"moren.jpg").c_str());
       fitpixmap = pixmap2.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
   }else{
       fitpixmap = pixmap.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
   }
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
    //qDebug()<< "back"<< preIndex << " psw:"<< psw;
    psw->setCurrentIndex(this->preIndex);
}



void BookDetails::on_btn_star_clicked(){//收藏

}

void BookDetails::on_btn_borrow_clicked(){//借阅
    Record record;
    if(now_user.getDebet()>0)
        QMessageBox::information(this,"借阅书籍","请先缴纳欠款方可借书！");
    else{
        if(now_book.getLeft()>0){
            record.setIsbn(now_book.getIsbn());


            QDateTime dateTime = QDateTime::currentDateTime();//获取系统当前的时间
            QString str = dateTime .toString("yyyy-MM-dd hh:mm:ss");//格式化时间
    //        QString str="2022-06-10 10:10:10";//测试时使用
            record.setDate(str.toStdString().c_str());

            record.setAuthor(now_book.getAuthor());
            record.setAccount(now_user.getAccount());
            record.setBookName(now_book.getBookName());
            record.setPublisher(now_book.getPublisher());

            if(now_utils.InsertRecord(record)){
                //qDebug()<<"借书成功！";
                QMessageBox::information(this,"借阅书籍","小伙好手速，借书成功！");
                now_book.setLeft(now_book.getLeft()-1);
                Book bookt;
                bookt.setIsbn(now_book.getIsbn());
                User ut;
                ut.setAccount(now_user.getAccount());
                now_user.setNumBorrowed(now_user.getNumBorrowed()+1);

                if(!now_utils.UpdateBook(bookt, now_book)){





                    //加入系统日志
                    //QMessageBox::information(this,"借阅书籍","借阅书籍造成书籍信息错误！")


                }
                if(!now_utils.UpdateUser(ut,now_user)){

                    //加入系统日志
                    //QMessageBox::information(this,"借阅书籍","借阅书籍造成书籍信息错误！")

                }
            }else{
                QMessageBox::information(this,"借阅书籍","已借阅该图书！一种图书无法借阅两本");
            }
        }else{
            QMessageBox::information(this,"借阅书籍","该图书无库存，如需要请预约！");
        }

    }
}

void BookDetails::on_btn_reserve_clicked(){//预约
    bool flag=false;
    vector<Record> record;
    now_utils.GetUserBorrowList(now_user.getAccount(),record);
    for(int i=0;i<record.size();i++){
//        qDebug()<<record[i].getIsbn();
        if(record[i].getIsbn()==now_book.getIsbn()){
            flag=true;
            break;
        }
    }

    if(now_user.getDebet()>0)
        QMessageBox::information(this,"预约书籍","请先缴纳欠款方可预约书！");
    else if(flag){
        QMessageBox::information(this,"预约书籍","已借阅该图书，不可预约");
    }
    else if(now_book.getLeft()>0){
        QMessageBox::information(this,"预约书籍","该图书尚有库存无法预约");
    }
//    else if(){
//        //需要借阅上限还有一本的空闲

//    }
    else{
        Reserve reserve;
        reserve.setIsbn(now_book.getIsbn());

        //resereve.setDate("2022-06-11");//测试时使用
        QDateTime dateTime = QDateTime::currentDateTime();//获取系统当前的时间
        QString str = dateTime .toString("yyyy-MM-dd hh:mm:ss");//格式化时间
        reserve.setDate(str.toStdString().c_str());

        reserve.setAuthor(now_book.getAuthor());
        reserve.setAccount(now_user.getAccount());
        reserve.setBookName(now_book.getBookName());
        reserve.setPublisher(now_book.getPublisher());
        //(！！需要没人预约且无人预约,否则会返回失败!!)
        if(now_utils.InsertReserve(reserve)){
            //qDebug()<<"预约成功！";
            QMessageBox::information(this,"预约书籍","小伙好手速，预约成功！");
            User ut;
            ut.setAccount(now_user.getAccount());
            now_user.setNumBorrowed(now_user.getNumBorrowed()+1);
            now_utils.UpdateUser(ut,now_user);
        }else{
            //qDebug()<<"该图书已被预约，请静候";
            QMessageBox::information(this,"预约书籍","哎呀，差点就预约上了，换一本预约吧！");
        }
    }
}
void BookDetails::setPreIndex(int index){
    this->preIndex = index;
}
