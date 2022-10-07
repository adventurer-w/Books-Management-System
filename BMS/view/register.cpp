#include "register.h"
#include "ui_register.h"

extern User now_user;
extern Utils now_utils;

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->box_sex->addItems(QStringList()<<"男"<<"女");
//    getinfo();
}

Register::~Register()
{
    delete ui;
}

//void Register::getinfo(){


//}

void Register::on_btn_register_clicked()
{
    QString account=ui->line_bumber->text();//学号
    QString pwd=ui->line_password->text();//密码
    QString confirmPwd=ui->line_confirmPasswod->text();//确认密码
    QString name=ui->line_name->text();//姓名
    QString major=ui->line_major->text();//专业
    QString email=ui->line_email->text();//邮箱
    QString emailcode=ui->line_emailcode->text();//邮箱验证码
    QString sex=ui->box_sex->currentText();//性别

    MD5 md5;
    string b= md5.read(pwd.toStdString());//加密

    now_user.setAccount(const_cast<char*>(account.toStdString().c_str()));
    now_user.setName(const_cast<char*>(name.toStdString().c_str()));
    now_user.setMajor(const_cast<char*>(major.toStdString().c_str()));
    now_user.setAccount(const_cast<char*>(account.toStdString().c_str()));
    now_user.setAccount(const_cast<char*>(account.toStdString().c_str()));
    if(sex=="男")
        now_user.setSex(1);
    else
        now_user.setSex(2);
    now_user.setNumBorrowed(0);//借书数目
    now_user.setNumAppointed(0);//预约数
    now_user.setDebet(0);//欠款数

    if(pwd==confirmPwd){
        now_user.setPassword(const_cast<char*>(b.c_str()));
        int flag=now_utils.Register(now_user);
        if(flag==0){
            //账户已存在
            ui->label->setText("账户已存在");
        }else if(flag==-1){
            //注册失败
            ui->label->setText("注册错误");
        }else if(flag==1){
            //注册成功
            ui->label->setText("注册成功");
        }
    }else{
        ui->label->setText("确认密码与密码不一致");
    }

}
