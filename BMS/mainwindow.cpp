#include "mainwindow.h"
#include "widget.h"
#include "ui_mainwindow.h"
#include "QPainter"
#include <QAction>
#include <QFile>
#include <QTextStream>
#include <QApplication>
#include <QMessageBox>
#include <QStackedWidget>
#include <QDebug>
#include "userprofilewidget.h"
#include "querybookwidget.h"
#include "mainwidget.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      mw(new MainWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("个人主页");
    this->resize(1600,900);
    loadMenuBar();
    loadPages();

    QString qssfilename =":/qss/mainwindow/mainwindow.qss";
    this->loadQss(qssfilename);

}
//放背景图
void MainWindow::paintEvent(QPaintEvent *){
    //需要Qpainter头文件
    QPainter painter(this);//初始化
    QPixmap pix;
    //背景图
    pix.load(":/image/mainwindow/background.jpg");

    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //画头像
    QPainterPath path;
     path.addEllipse(100,60,80,80);//加入一个圆形   绘图是从左上角的（56，20）坐标开始绘制的  ，120，120是绘图的宽高
     pix.load(":/image/pic/personal_homepage.jpg");
     painter.setClipPath(path);
     painter.drawPixmap(QRect(100,60,120,120),pix);
}
bool MainWindow::loadQss(const QString &StyleSheetFile){

        /*QSS文件所在的路径*/
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

void MainWindow::loadMenuBar(){
    QString imgroot =":/image/mainwindow/";
    QString menuBars[]={"user.png","modify.png","library.png","logout.png"};
    int barsCount=4;
    //qDebug() << menuBars->size();
    for(int i=0; i<barsCount;++i){
        QPixmap pixmap(imgroot+menuBars[i]);
        QPixmap fitpixmap = pixmap.scaled(20, 20, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        QPushButton *btn = new QPushButton;
        switch(i){
            case 0:btn = ui->btn_userProfile;break;
            case 1:btn = ui->btn_modifyInfo;break;
            case 2:btn = ui->btn_queryBook;break;
            case 3:btn = ui->btn_logout;break;
        default:qDebug() << "from mainwindow.cpp line 88 outOfIndex"<<endl;
        }

        btn->setIcon(QIcon(fitpixmap));
        btn->setIconSize(QSize(20, 20));
        btn->setFlat(true);
    }


}
void MainWindow::loadPages(){

    mw->resize(1300,900);
    mw->move(this->x()+300,this->y());
    mw->setParent(this);

    /*默认导入 个人信息页面*/
    UserProfileWidget *userProfileWidget = new UserProfileWidget;
    userProfileWidget->resize(1300,900);
    //userProfileWidget->setParent(this->mw);
    mw->insertWidget(0,userProfileWidget);


    /*默认导入 图书查询页面*/
    QueryBookWidget *queryBookWidget = new  QueryBookWidget;
    queryBookWidget->resize(1300,900);
    //userProfileWidget->setParent(this->mw);
    mw->insertWidget(1, queryBookWidget);

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_userProfile_clicked()
{
    mw->setCurrentIndex(0);

}

void MainWindow::on_btn_modifyInfo_clicked()
{

}
void MainWindow::on_btn_queryBook_clicked()
{
    mw->setCurrentIndex(1);

}
