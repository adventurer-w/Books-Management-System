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
#include <QPushButton>
#include <QDebug>
#include "userprofilewidget.h"
#include "querybookwidget.h"
#include "mainwidget.h"
#include "backend/User.h"
#include "modifyinfowidget.h"
#include "admininfo.h"
#include "adminbookmanagement.h"
extern User now_user;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      mw(new MainWidget)
{

    ui->setupUi(this);
    this->setWindowTitle("图书系统");
    this->resize(1600,900);
    userType = 1;
    loadUserInfo();
    loadMenuBar();
    loadPages(0);


    QString qssfilename =":/qss/mainwindow/mainwindow.qss";
    this->loadQss(qssfilename);

}
void MainWindow::loadUserInfo(){
    ui->lb_username_main->setText(QString::fromStdString(now_user.getName()));

    ui->lb_number_main->setText(QString::fromStdString(now_user.getAccount()));

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
    QString userMenuBars[]={"user.png","modify.png","library.png","logout.png"};
    QString adminMenuBars[]={"user.png","library.png","lookup.png","logout.png"};

    QString userMenuText[]={"个人中心","修改信息","图书查询","退出登录"};
    QString adminMenuText[]={"个人中心","图书管理","借阅管理","退出登录"};
    //QString adminObjectNames[]={"btn_admininfo","btn_bookmanagement","btn_borrowmanagement","btn_logout"};


    int barsCount=4;
    int pos_x=30;
    int pos_y=250;
    int btn_width= 200;
    int btn_height= 50;
    QString *pBar = userType? userMenuBars:adminMenuBars;
    QString *pText = userType? userMenuText:adminMenuText;
    for(int i=0; i<barsCount;++i){
        QPixmap pixmap(imgroot+pBar[i]);
        QPixmap fitpixmap = pixmap.scaled(20, 20, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        btn = new QPushButton(this);
        btn->setObjectName(QString::number(i));
        btn->setText(pText[i]);
        btn->move(pos_x,pos_y);
        btn->resize(btn_width,btn_height);
        btn->setIcon(QIcon(fitpixmap));
        btn->setIconSize(QSize(20, 20));
        btn->setFlat(true);
        btnList.append(btn);
        connect(btnList.at(i),SIGNAL(clicked()),this,SLOT(menuBarBtnClicked()));
        pos_y+=btn_height;
    }



}
/*
以某种模式加载界面，其中0为初始化mw和个人信息,1为只初始化个人信息，一次类推；4为导入管理员个人信息，以此类推
*/
void MainWindow::loadPages(int mode){
    if(mode == 0){
        mw->resize(1300,900);
        mw->move(this->x()+300,this->y());
        mw->setParent(this);
    }
    if(userType == 0){//表示管理员
        if(mode == 0 || mode==1){
            /*导入管理员个人信息界面  */
            AdminInfo *adminInfo = new AdminInfo;
            adminInfo->resize(1300,900);
            //connect(adminInfo,SIGNAL(modifySignal()),this,SLOT(loadUserInfo()));
            mw->insertWidget(0,adminInfo);
        }

        if(mode == 0||mode == 2){
            /*导入管理员图书信息管理界面 */
            AdminBookManagement *adminBookManagement = new AdminBookManagement;
            adminBookManagement->resize(1300,900);
            //connect(adminBookManagement,SIGNAL(modifySignal()),this,SLOT(loadAdminInfo()));
            mw->insertWidget(1,adminBookManagement);
        }
        if(mode == 0||mode ==3){
            /*导入管理员个人借阅信息管理界面  */
        }
    }
    else{
        if(mode == 0 || mode ==1){
            /*默认导入 个人信息页面*/
            UserProfileWidget *userProfileWidget = new UserProfileWidget;
            userProfileWidget->resize(1300,900);
            //userProfileWidget->setParent(this->mw);
            mw->insertWidget(0,userProfileWidget);
            userProfileWidget->pmw = mw;
        }


        if(mode == 0 ||mode == 2){
            /*导入 信息修改页面*/
            ModifyInfoWidget *modifyInfoWidget = new  ModifyInfoWidget;
            modifyInfoWidget->resize(1300,900);
            connect(modifyInfoWidget,SIGNAL(modifySignal()),this,SLOT(loadUserInfo()));
            //userProfileWidget->setParent(this->mw);
            mw->insertWidget(1, modifyInfoWidget);
        }

        if(mode == 0||mode == 3){
            /*默认导入 图书查询页面*/
            QueryBookWidget *queryBookWidget = new  QueryBookWidget;
            queryBookWidget->resize(1300,900);
            //userProfileWidget->setParent(this->mw);
            mw->insertWidget(2, queryBookWidget);

        }
       }


}
MainWindow::~MainWindow()
{
    delete ui;
    qDeleteAll(btnList);
    btnList.clear();
}
void MainWindow::menuBarBtnClicked(){
    QPushButton *this_btn = qobject_cast<QPushButton*>(sender());
    int mode = sender()->objectName().toInt();
    if(mode < 0)return ;
    //qDebug() << "mode:"<<mode;
    loadPages(mode+1);
    mw->setCurrentIndex(mode);
}
