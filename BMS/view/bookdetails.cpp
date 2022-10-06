#include "bookdetails.h"
#include "ui_bookdetails.h"
#include <QFile>
#include <QMessageBox>
BookDetails::BookDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookDetails)
{
    ui->setupUi(this);


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
