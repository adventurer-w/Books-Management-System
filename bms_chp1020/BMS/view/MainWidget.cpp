#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QStackedWidget>
#include "QPainter"
#include "QDebug"
MainWidget::MainWidget(QWidget *parent) :
    QStackedWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}
//void MainWidget::paintEvent(QPaintEvent *){
//    //需要Qpainter头文件
//    QPainter painter(this);//初始化
//    QPixmap pix;
//    //背景图
//    pix.load(":/image/mainwindow/background.jpg");
//    //painter.drawPixmap(0,0,this->width(),this->height(),pix);
//    //qDebug() << "stack paint" <<endl;

//}
