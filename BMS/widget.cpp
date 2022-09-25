#include "widget.h"
#include "MainWindow.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置窗口名
    this->setWindowTitle("登录");
    ui->label_user_name->setScaledContents(true);   //图片自适应label大小
    ui->label_pwd->setScaledContents(true);         //图片自适应label大小

    ui->lineE_pwd->setEchoMode(QLineEdit::Password);//设置为小黑点

    connect(ui->btn_1,SIGNAL(clicked(bool)),this,SLOT(set_style()));
    connect(ui->btn_2,SIGNAL(clicked(bool)),this,SLOT(set_style()));
    connect(ui->btn_3,SIGNAL(clicked(bool)),this,SLOT(set_style()));
    connect(ui->btn_4,SIGNAL(clicked(bool)),this,SLOT(set_style()));
}

/*
* 槽函数-皮肤设置
*/
QPushButton* btn;
void Widget::set_style()
{
    btn = qobject_cast<QPushButton*>(sender());//获取发射信号的对象
    QString filePath;
    if("btn_1" == btn->objectName())        //粉色
    {
        filePath = ":/qss/login/style-1.qss";
    }else if("btn_2" == btn->objectName())  //黄蓝
    {
        filePath = ":/qss/login/style-2.qss";
    }else if("btn_3" == btn->objectName())  //浅紫
    {
        filePath = ":/qss/login/style-3.qss";
    }else if("btn_4" == btn->objectName())  //青绿
    {
        filePath = ":/qss/login/style-4.qss";
    }

    /*皮肤设置*/
    QFile file(filePath);/*QSS文件所在的路径*/
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btn_login_clicked()
{

    //需要连接后端
     this->hide();
    MainWindow *personal_homepage = new MainWindow;
     personal_homepage->show();
}
