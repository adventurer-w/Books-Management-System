#include "mainwindow.h"
#include "widget.h"
#include "ui_mainwindow.h"
#include "QPainter"
#include <QAction>
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QMessageBox>
#include "backend/MD5.h"
#include<iostream>


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //设置固定大小
    //this->setFixedSize(600,600);
    //设置窗口名
    this->setWindowTitle("个人主页");
    //可以设置窗口名旁边图标
    //this->setWindowIcon(QIcon(":/res/"));
    //退出按钮,转到登录页
   Widget *login=new Widget;
    connect(ui->action_quit,&QAction::triggered,[=](){
               this->hide();
              login->show();
           });

    //设置字体

       //ft.setPointSize(20);
       QFont ft ( "华为楷体",20);//设置字体，STKaiti是华文楷体
       //字体大小
       //  ft.setPointSize(20);
       QPalette label_pe;
      //字体颜色
      //label_pe.setColor(QPalette::WindowText, Qt::white);
      // ui->lb_username->setPalette(label_pe);
       //ui->lb_username->setFont(ft);
       //ui->lb_username->setText("username");
       QString qssfilename =":/qss/mainwindow/mainwindow.qss";
       this->loadQss(qssfilename);
}
//放背景图
void MainWindow::paintEvent(QPaintEvent *){
    //需要Qpainter头文件
    QPainter painter(this);//初始化
    QPixmap pix;
    //背景图
    pix.load(":/image/mainwindow/background2.png");

    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //画头像
    QPainterPath path;
     path.addEllipse(100,60,120,120);//加入一个圆形   绘图是从左上角的（56，20）坐标开始绘制的  ，120，120是绘图的宽高
     pix.load(":/image/pic/personal_homepage.jpg");
     painter.setClipPath(path);
     painter.drawPixmap(QRect(100,60,120,120),pix);
}
bool MainWindow::loadQss(const QString &StyleSheetFile){

    QFile file(StyleSheetFile);/*QSS文件所在的路径*/
    QFile ofile(StyleSheetFile);
        bool Ret = ofile.open(QFile::ReadOnly);

        if (!Ret)
        {
             QMessageBox::information(this,"Tip",ofile.errorString());
             return false;
        }

        this->setStyleSheet(ofile.readAll());
        ofile.close();

}
MainWindow::~MainWindow()
{
    delete ui;
}

