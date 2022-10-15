#include "admininfo.h"
#include "ui_admininfo.h"
#include <QPainter>
#include <QMessageBox>
#include <QFile>
AdminInfo::AdminInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminInfo)
{
    ui->setupUi(this);
    loadQss(":/qss/modifyinfowidget/modifyinfo.qss");
}

AdminInfo::~AdminInfo()
{
    delete ui;
}
void AdminInfo::paintEvent(QPaintEvent *){
    //需要Qpainter头文件
    QPainter painter(this);//初始化
    QPixmap pix;
    //背景图
    pix.load(":/image/UserProfile/background.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //qDebug() << "user paint" <<endl;


}
bool AdminInfo::loadQss(const QString &StyleSheetFile){
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
