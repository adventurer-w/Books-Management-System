#include "register.h"
#include "ui_register.h"
#include "backend/length.h"
#include <QMessageBox>
#include<QDebug>
#include"smtp.h"
#include"QDateTime"
extern User now_user;
extern Utils now_utils;

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->box_sex->addItems(QStringList()<<" "<<"男"<<"女");

//    ui->box_department->addItems(QStringList()<<" "<<"计算机科学与技术");

//    vector<string> classifications;
//    for(int i=0;i<classifications.size();i++)
//        ui->box_department->addItem(QString::fromStdString(classifications[i]));

    this->setWindowTitle("注册");
//    getinfo();
}

Register::~Register()
{
    delete ui;
}

//void Register::getinfo(){


//}

string emailcode;
int clickNum=0;
QDateTime last_time;

void Register::on_btn_emailcode_clicked(){

    QString email=ui->line_email->text();
    qDebug()<<email;
    for(int i=0;i<6;i++){
        emailcode+=(qrand() % 10 +48);
    }

    string s,t;
    if(email.size()<=0)
        s="请输入邮箱\n";
    else if(email.size()>EMAIL_SIZE-1){
        t=EMAIL_SIZE;
        s="邮箱应小于等于"+t+"个字符\n";
    }else if(!now_utils.CheckEmail(const_cast<char*>(email.toStdString().c_str()))){
        s="邮箱格式为:名称@域名，且只允许字母、数字、下划线、英文句号、以及中划线组成\n";
    }
    if(s.size()>0){
        QMessageBox::information(this,"提示信息",QString::fromStdString(s));
    }else{

        CSmtp smtp(
                    25,                             /*smtp端口*/
                    "smtp.163.com",                 /*smtp服务器地址*/
                    "chenhaopeng0327@163.com",         /*你的邮箱地址*/
                    "CAVELDHPXYDOOGDK",                   /*邮箱授权码*/
                    email.toStdString(),  /*目的邮箱地址,这一部分用空格分割可添加多个收信人*/
                    "图书馆注册验证码",                           /*主题*/
                    emailcode     /*邮件正文*/
                    );

        int err;
        if ((err = smtp.SendEmail_Ex()) != 0)
        {
            if (err == 1)
                qDebug() << "错误1: 由于网络不畅通，发送失败!" << endl;
            if (err == 2)
                qDebug() << "错误2: 用户名错误,请核对!" << endl;
            if (err == 3)
                qDebug() << "错误3: 用户密码错误，请核对!" << endl;
            if (err == 4)
                qDebug() << "错误4: 请检查附件目录是否正确，以及文件是否存在!" << endl;
        }
    }
    emailcode.clear();
}

void Register::on_btn_register_clicked()
{
    bool flag=true;
    if(clickNum==3){
        QDateTime now_time = QDateTime::currentDateTime();//获取系统当前的时间
        qint64 time=last_time.secsTo(now_time);
        if(time<=5*50){
            flag=false;
            QMessageBox::information(this,"提示信息","尝试超过3次，请稍后再试！");
        }else{
            clickNum=2;
        }
    }
    if(flag){
        QString account=ui->line_bumber->text();//学号
        QString pwd=ui->line_password->text();//密码
        QString confirmPwd=ui->line_confirmPasswod->text();//确认密码
        QString name=ui->line_name->text();//姓名
        QString major;/*=ui->box_department->currentText();*///专业
        QString email=ui->line_email->text();//邮箱
        QString user_emailcode=ui->line_emailcode->text();//邮箱验证码
        QString sex=ui->box_sex->currentText();//性别

        MD5 md5;
        string b= md5.read(pwd.toStdString());//加密

        now_user.setAccount(const_cast<char*>(account.toStdString().c_str()));
        now_user.setName(const_cast<char*>(name.toStdString().c_str()));
        vector<Department> major_result;
        now_utils.GetDepartmentByName(const_cast<char*>(major.toStdString().c_str()),major_result);
    //    now_user.setDepartmentNo(1);

        now_user.setEmail(const_cast<char*>(email.toStdString().c_str()));
        if(sex=="男")
            now_user.setSex(1);
        else
            now_user.setSex(2);
        now_user.setNumBorrowed(0);//借书数目
        now_user.setNumAppointed(0);//预约数
        now_user.setDebet(0);//欠款数

        string s;
        if(account.size()<6)
            s+="账号应大于等于6个字符\n";
        else if(account.size()>11)
            s+="账号应小于等于11个字符\n";
        else if(!now_utils.CheckAccount(const_cast<char*>(account.toStdString().c_str())))
            s+="账号不能包含除数字以外的字符\n";

        if(pwd.size()<6)
            s+="密码应大于等于6个字符\n";
        else if(pwd.size()>=30)
            s+="密码应小于等于30个字符\n";
        else if(!now_utils.CheckPassword(const_cast<char*>(pwd.toStdString().c_str()))){
            s+="密码不合法（应至少1个大写字母，1个小写字母和1个数字）\n";
        }

        string t;
        if(name.size()<=0)
            s+="请输入昵称\n";
        else if(name.size()>USER_NAME_SIZE-1){
            t=USER_NAME_SIZE-1;
            s+="昵称应小于等于"+t+"个字符\n";
        }

        if(major.size()<=0)
            s+="请输入身份\n";
        else if(major.size()>MAJOR_SIZE-1){
            t=MAJOR_SIZE-1;
            s+="专业名应小于等于"+t+"个字符\n";
        }

        if(email.size()<=0)
            s+="请输入邮箱\n";
        else if(email.size()>EMAIL_SIZE-1){
            t=EMAIL_SIZE;
            s+="邮箱应小于等于"+t+"个字符\n";
        }else if(!now_utils.CheckEmail(const_cast<char*>(email.toStdString().c_str()))){
            s+="邮箱格式为:名称@域名，且只允许字母、数字、下划线、英文句号、以及中划线组成\n";
        }

        //邮箱验证码 emailcode
        if(user_emailcode.toStdString()!=emailcode){
            clickNum++;
            if(clickNum==3){
                s+="验证码错误超过3次，请5分钟后再试！\n";
                last_time = QDateTime::currentDateTime();//获取系统当前的时间
    //            QString str = dateTime .toString("yyyy-MM-dd hh:mm:ss");//格式化时间
            }else{
                s+="验证码错误\n";
            }
        }

    //    qDebug()<<s.size()<<QString::fromStdString(s);
        if(s.size()>0)
            QMessageBox::information(this,"提示信息",QString::fromStdString(s));
        else{

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
                }else if(flag==-2){
                    ui->label->setText("用户名不合法，前两位不能为00");
                }else if(flag==-3){
                    ui->label->setText("密码不合法");
                }else if(flag==-4){
                    ui->label->setText("邮箱不合法");
                }

            }else{
                ui->label->setText("确认密码与密码不一致");
            }
       }
   }

}
