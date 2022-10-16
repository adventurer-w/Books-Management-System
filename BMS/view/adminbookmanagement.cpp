#include "adminbookmanagement.h"
#include "ui_adminbookmanagement.h"
#include <QPainter>
#include <QMessageBox>
#include <QFile>

AdminBookManagement::AdminBookManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminBookManagement)
{
    ui->setupUi(this);
    loadQss(":/qss/admin/bookmanagement.qss");
}

AdminBookManagement::~AdminBookManagement()
{
    delete ui;
}
void AdminBookManagement::paintEvent(QPaintEvent *){
    //需要Qpainter头文件
    QPainter painter(this);//初始化
    QPixmap pix;
    //背景图
    pix.load(":/image/querybook/background.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);


}
bool AdminBookManagement::loadQss(const QString &StyleSheetFile){
    /*QSS文件所在的路径*/
    QFile ofile(StyleSheetFile);
    bool Ret = ofile.open(QFile::ReadOnly);

    if (!Ret)
    {
         QMessageBox::information(this,"Tip_adminInfo",ofile.errorString());
         return false;
    }

    this->setStyleSheet(ofile.readAll());
    ofile.close();
}
