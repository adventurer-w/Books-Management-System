#include "admininfo.h"
#include "ui_admininfo.h"
#include "backend/all_head.h"
#include "backend/Utils.h"
#include "backend/MD5.h"
#include <QFile>
#include <QMessageBox>
#include <QPainter>
#include <QDebug>

extern User now_user;
extern Utils now_utils;

AdminInfo::AdminInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminInfo)
{
    ui->setupUi(this);

    qDebug() << "1";
    //left up sub_page use in appear message of user
    //左上页用来显示用户信息
    ui->lb_username_txt->setText(now_user.getName());
    vector<Department> major_result;
    now_utils.GetDepartmentByNo(now_user.getDepartmentNo(),major_result);
    qDebug() << "2";
//    ui->lb_major_txt->setText(QString::fromStdString(major_result[0].getName()));
    qDebug() << "3";
    ui->lb_number_txt->setText(now_user.getAccount());

    if(now_user.getSex()==1)
       ui->lb_sex_txt->setText("男");
    else
       ui->lb_sex_txt->setText("女");

    //left down sub_page use in modify password of user 
    //左下页用来修改密码


    //right sub_page use in modify message of user 
    //右半页用来修改用户信息
    ui->box_sex->addItems(QStringList()<<"男"<<"女");
    ui->line_name->setText(now_user.getName());
    qDebug() << "4";
    now_utils.GetDepartmentByNo(now_user.getDepartmentNo(),major_result);
//    ui->line_major->setText(QString::fromStdString(major_result[0].getName()));
    qDebug() << "5";
    ui->line_number->setText(now_user.getAccount());
    ui->line_major_2->setText(now_user.getEmail());
    loadQss(":/qss/admininfo/admininfo.qss");
}

AdminInfo::~AdminInfo()
{
    delete ui;
}

void AdminInfo::on_btn_modifyInfo_clicked(){
    QString account=ui->line_number->text();//学号
    QString name=ui->line_name->text();//姓名
    QString major=ui->line_major->text();//专业
    QString email=ui->line_major_2->text();//邮箱
    QString sex=ui->box_sex->currentText();//性别

    User usert;
    usert.setAccount(now_user.getAccount());

    now_user.setAccount(const_cast<char*>(account.toStdString().c_str()));
    now_user.setName(const_cast<char*>(name.toStdString().c_str()));
    vector<Department> major_result;
    now_utils.GetDepartmentByName(const_cast<char*>(major.toStdString().c_str()),major_result);
    now_user.setDepartmentNo(major_result[0].getDepartmentNo());
    now_user.setEmail(email.toStdString().c_str());
    if(sex=="男")
        now_user.setSex(1);
    else
        now_user.setSex(2);
    now_user.setNumBorrowed(now_user.getNumBorrowed());//借书数目
    now_user.setNumAppointed(now_user.getNumAppointed());//预约数
    now_user.setDebet(now_user.getDebet());//欠款数



    //增加弹窗
    if(now_utils.UpdateUser(usert,now_user)){
        // emit modifySignal();
        //qDebug()<<"修改成功";
        QMessageBox::information(this,"修改信息","修改个人信息成功啦！");
//        QWidget.update();
    }else{
        //qDebug()<<"修改失败";
        QMessageBox::information(this,"修改信息","真可惜，修改个人信息失败了!");
    }

}


void AdminInfo::on_btn_modifyPassword_clicked(){

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

void AdminInfo::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/adminProfile/background.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //qDebug() << "user paint" <<endl;


}
bool AdminInfo::loadQss(const QString &StyleSheetFile){
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
