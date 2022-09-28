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
#include "userprofilewidget.h"
#include "mainwidget.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      mw(new MainWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("个人主页");
    this->resize(1600,900);
    mw->resize(1300,900);
    mw->move(this->x()+300,this->y());
    mw->setParent(this);

    /*默认导入 个人信息页面*/
    UserProfileWidget *userProfileWidget = new UserProfileWidget;
    userProfileWidget->resize(1300,900);
    //userProfileWidget->setParent(this->mw);

    mw->addWidget(userProfileWidget);



//    QPixmap pixmap(":/image/mainwindow/username.png");
//    QPixmap fitpixmap = pixmap.scaled(20, 20, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//    ui->btn_userProfile->setIcon(QIcon(fitpixmap));
//    ui->btn_userProfile->setIconSize(QSize(20, 20));
//    ui->btn_userProfile->setFlat(true);

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
MainWindow::~MainWindow()
{
    delete ui;
}

