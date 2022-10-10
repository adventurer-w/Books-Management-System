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
#include "backend/User.h"
#include "modifyinfowidget.h"
extern User now_user;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      mw(new MainWidget)
{

    ui->setupUi(this);
    this->setWindowTitle("图书系统");
    this->resize(1600,900);
    loadUserInfo();
    loadMenuBar();
    loadPages(0);


    QString qssfilename =":/qss/mainwindow/mainwindow.qss";
    this->loadQss(qssfilename);

}
void MainWindow::loadUserInfo(){
    ui->lb_username_main->setText(QString::fromStdString(now_user.getName()));

    ui->lb_number_main->setText(QString::fromStdString(now_user.getAccount()));
    qDebug() << "oh";

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
     path.addEllipse(60,60,80,80);//加入一个圆形   绘图是从左上角的（56，20）坐标开始绘制的  ，120，120是绘图的宽高
     pix.load(":/image/pic/personal_homepage.jpg");
     painter.setClipPath(path);
     painter.drawPixmap(QRect(60,60,80,80),pix);
}
bool MainWindow::loadQss(const QString &StyleSheetFile){

        /*QSS文件所在的路径*/
    QFile ofile(StyleSheetFile);
        bool Ret = ofile.open(QFile::ReadOnly);

        if (!Ret)
        {
             QMessageBox::information(this,"Tip1",ofile.errorString());
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
/*
以某种模式加载界面，其中0为初始化mw和个人信息,1为只初始化个人信息，一次类推
*/
void MainWindow::loadPages(int mode){
    if(mode == 0){
        mw->resize(1300,900);
        mw->move(this->x()+300,this->y());
        mw->setParent(this);
    }

    if(mode == 0 || mode ==1){
        /*默认导入 个人信息页面*/
        UserProfileWidget *userProfileWidget = new UserProfileWidget;
        userProfileWidget->resize(1300,900);
        //userProfileWidget->setParent(this->mw);
        mw->insertWidget(0,userProfileWidget);
        userProfileWidget->pmw = mw;
    }


    if(mode >= 2){
        /*默认导入 图书查询页面*/
        QueryBookWidget *queryBookWidget = new  QueryBookWidget;
        queryBookWidget->resize(1300,900);
        //userProfileWidget->setParent(this->mw);
        mw->insertWidget(1, queryBookWidget);
    }

    if(mode >= 3){
        /*导入 信息修改页面*/
        ModifyInfoWidget *modifyInfoWidget = new  ModifyInfoWidget;
        modifyInfoWidget->resize(1300,900);
        connect(modifyInfoWidget,SIGNAL(modifySignal()),this,SLOT(loadUserInfo()));
        //userProfileWidget->setParent(this->mw);
        mw->insertWidget(2, modifyInfoWidget);
    }


}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_userProfile_clicked()
{
    loadPages(1);
    mw->setCurrentIndex(0);

}

void MainWindow::on_btn_modifyInfo_clicked()
{
    loadPages(3);
    mw->setCurrentIndex(2);
}
void MainWindow::on_btn_queryBook_clicked()
{
    loadPages(2);
    mw->setCurrentIndex(1);

}
void MainWindow::on_btn_logout_clicked()
{
    Widget *login = new Widget;
    this->hide();
    login->show();
}
