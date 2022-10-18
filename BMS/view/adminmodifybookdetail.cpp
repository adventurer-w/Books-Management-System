#include "adminmodifybookdetail.h"
#include "ui_adminmodifybookdetail.h"
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
extern int add_or_mod;

AdminModifyBookDetail::AdminModifyBookDetail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminModifyBookDetail)
{
    ui->setupUi(this);

    loadBookDetail();
    setIcons();
    loadQss(":/qss/bookdetails/bookdetails.qss");
}

AdminModifyBookDetail::~AdminModifyBookDetail()
{
    delete ui;
}

void AdminModifyBookDetail::loadBookDetail(){
    ui->line_bookname->setText(now_book.getBookName());
    ui->line_author->setText(now_book.getAuthor());
    ui->line_publish->setText(now_book.getPublisher());
    ui->line_ISBN->setText(now_book.getIsbn());  
    ui->line_classify->setText(now_book.getClassifition());
    ui->line_publishtime->setText(now_book.getPublishDate());
    ui->line_remain->setText(QString::number(now_book.getAllNum()));
    ui->lineEdit->insertPlainText(now_book.getIntroduction());

    connect(ui->book_pushButton, &QPushButton::clicked, this, &AdminModifyBookDetail::on_pushButton_clicked);

    // ui->lb_grade_txt->setText(QString::number(now_book.getPoint()));

    // ui->lb_collect_txt->setText("未知");//后期判断是否需要增加收藏数

    // ui->lb_bookposition_txt->setText("未知");//后期判断是否需要增加图书位置

    // ui->lb_historyborrow_txt->setText(QString::number(now_book.getHistoryNum()));
//    ui->lb_intro_txt->setText(now_book.getIntroduction());

    // QLabel *l1 = new QLabel();     //创建lable

    // l1-> setFixedSize (120,150);

    // string t1(now_book.getImgPath());
    // string t2(now_book.getIsbn());
    // string pic;
    // if(t2.size()==13)
    //            pic=t1+"/"+t2+".jpg";
    //        else
    //            pic=":/image/cover/moren.jpg";

    // QPixmap pixmap(pic.c_str());
    //        QPixmap fitpixmap;
    //        if(pixmap.isNull()){
    //            qDebug()<<"1空";
    //            QPixmap pixmap2(":/image/cover/moren.jpg");
    //            fitpixmap = pixmap2.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    //        }else{
    //            fitpixmap = pixmap.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    //        }
    // ui->lb_bookphoto->setPixmap(fitpixmap);    //加载图片

    // ui->lb_bookphoto->setScaledContents(true);
    // ui->lb_bookphoto->setAlignment(Qt::AlignCenter);      //设置居中

}
void AdminModifyBookDetail::setStackWidget(MainWidget *p){
    this->psw = p;
}
void AdminModifyBookDetail::setIcons(){
    /*将图标图片缩小到指定尺寸*/
    QPixmap pixmap(":/image/querybook/back.png");
    QPixmap fitpixmap = pixmap.scaled(35, 35, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//    ui->btn_back->setIcon(QIcon(fitpixmap));
//    ui->btn_back->setIconSize(QSize(35, 35));
//    ui->btn_back->setFlat(true);
}
bool AdminModifyBookDetail::loadQss(const QString &StyleSheetFile){
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

void AdminModifyBookDetail::on_pushButton_clicked(){

    Book old_book;
    if(now_book.getIsbn())
        qDebug() << "abc";
    old_book.setIsbn(now_book.getIsbn());
    /*
    ui->line_bookname->setText(now_book.getBookName());
    ui->line_author->setText(now_book.getAuthor());
    ui->line_publish->setText(now_book.getPublisher());
    ui->line_ISBN->setText(now_book.getIsbn());
    ui->line_classify->setText(now_book.getClassifition());
    ui->line_publishtime->setText(now_book.getPublishDate());
    ui->line_remain->setText(QString::number(now_book.getAllNum()));
    */
    QString bookname=ui->line_bookname->text();//书名
    QString author=ui->line_author->text();//作者
    QString publish=ui->line_publish->text();//出版社
    QString ISBN=ui->line_ISBN->text();//ISBN
    QString classify=ui->line_classify->text();//类别
    QString publishtime=ui->line_publishtime->text();//出版时间
    QString remain=ui->line_remain->text();//库存
    QString introduction = ui->lineEdit->toPlainText();

    now_book.setBookName(const_cast<char*>(bookname.toStdString().c_str()));
    now_book.setAuthor(const_cast<char*>(author.toStdString().c_str()));
    now_book.setPublisher(const_cast<char*>(publish.toStdString().c_str()));
    now_book.setIsbn(const_cast<char*>(ISBN.toStdString().c_str()));
    now_book.setClassification(const_cast<char*>(classify.toStdString().c_str()));
    now_book.setPublishDate(const_cast<char*>(publishtime.toStdString().c_str()));
    now_book.setAllNum(remain.toInt());
    now_book.setIntroduction(const_cast<char*>(introduction.toStdString().c_str()));
    qDebug() << "come";

        if(now_utils.UpdateBook(old_book,now_book)){
            // emit modifySignal();
            //qDebug()<<"修改成功";
            QMessageBox::information(this,"修改信息","修改图书信息成功啦！");
        }else{
            //qDebug()<<"修改失败";
            QMessageBox::information(this,"修改信息","真可惜，修改图书信息失败了!");
        }


}

