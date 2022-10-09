#include "modifyinfowidget.h"
#include "ui_modifyinfowidget.h"
#include "backend/all_head.h"
#include "backend/Utils.h"
#include "backend/MD5.h"
#include <QFile>
#include <QMessageBox>
#include <QPainter>
#include <QDebug>
extern User now_user;
extern Utils now_utils;

ModifyInfoWidget::ModifyInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyInfoWidget)
{
    ui->setupUi(this);
    ui->box_sex->addItems(QStringList()<<"男"<<"女");

    ui->line_name->setText(now_user.getName());
    ui->line_major->setText(now_user.getMajor());
    ui->line_number->setText(now_user.getAccount());
   // ui->line_major_2->setText(now_user.getemail);//后期可以考虑增加邮箱
//    if(now_user.getSex()==1)
//        ui->box_sex->setItemText("男");
//    else
//        ui->box_sex->setItemText("男");
    loadQss(":/qss/modifyinfowidget/modifyinfo.qss");
}

ModifyInfoWidget::~ModifyInfoWidget()
{
    delete ui;
}

void ModifyInfoWidget::on_btn_modifyInfo_clicked(){
    QString account=ui->line_number->text();//学号
    QString name=ui->line_name->text();//姓名
    QString major=ui->line_major->text();//专业
    QString email=ui->line_major_2->text();//邮箱
    QString sex=ui->box_sex->currentText();//性别

    User usert;
    usert.setAccount(now_user.getAccount());

    now_user.setAccount(const_cast<char*>(account.toStdString().c_str()));
    now_user.setName(const_cast<char*>(name.toStdString().c_str()));
    now_user.setMajor(const_cast<char*>(major.toStdString().c_str()));
    //now_user.setAccount(const_cast<char*>(account.toStdString().c_str()));
    //now_user.setAccount(const_cast<char*>(account.toStdString().c_str()));
    if(sex=="男")
        now_user.setSex(1);
    else
        now_user.setSex(2);
    now_user.setNumBorrowed(0);//借书数目
    now_user.setNumAppointed(0);//预约数
    now_user.setDebet(0);//欠款数



    //增加弹窗



    if(now_utils.UpdateUser(usert,now_user)){
        emit modifySignal();
        //qDebug()<<"修改成功";
        QMessageBox::information(this,"修改信息","修改个人信息成功啦！");
    }else{
        //qDebug()<<"修改失败";
        QMessageBox::information(this,"修改信息","真可惜，修改个人信息失败了!");
    }

}

void ModifyInfoWidget::on_btn_modifyPassword_clicked(){

    User usert;
    usert.setAccount(now_user.getAccount());

    QString pwd=ui->line_password->text();//密码
    QString confirmPwd=ui->line_confirmPassword->text();//确认密码
    MD5 md5;
    string b= md5.read(pwd.toStdString());//加密


    //增加弹窗


    //增加提示信息label



    if(pwd==confirmPwd){
        now_user.setPassword(const_cast<char*>(b.c_str()));
        if(now_utils.UpdateUser(usert,now_user)){
            //qDebug()<<"修改成功";
            QMessageBox::information(this,"修改信息","修改密码成功啦！");
        }else{
            //qDebug()<<"修改失败";
            QMessageBox::information(this,"修改信息","修改密码出了点问题！");
        }
    }
}
void ModifyInfoWidget::paintEvent(QPaintEvent *event)

{



    QPainter paint(this);
    paint.setPen(Qt::gray);
   // paint.drawLine(0,220,50,50);

    QPainter painter(this);//初始化
    QPixmap pix;
    //背景图
    pix.load(":/image/modifyinfo/background.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
bool ModifyInfoWidget::loadQss(const QString &StyleSheetFile){

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
