#include "borrowinstruction.h"
#include "ui_borrowinstruction.h"
#include "backend/Utils.h"
extern Utils now_utils;

BorrowInstruction::BorrowInstruction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BorrowInstruction)
{
    ui->setupUi(this);
    //loadQss();

    ui->textEdit->setText(QString::fromStdString(now_utils.getGuidelines()));
    ui->line_teacher->setText();
    ui->line_undergraduate->setText();
    ui->line_master->setText();
    ui->line_doctor->setText();
}

BorrowInstruction::~BorrowInstruction()
{
    delete ui;
}

void BorrowInstruction::on_btn_modifyConfirm_clicked(){

    

    //增加弹窗
    if(now_utils.UpdateUser(usert,now_user)){
        QMessageBox::information(this,"修改信息","修改成功");
    }else{
        QMessageBox::information(this,"修改信息","修改失败");
    }

}

bool BorrowInstruction::loadQss(const QString &StyleSheetFile){

        /*QSS文件所在的路径*/
        QFile ofile(StyleSheetFile);
        bool Ret = ofile.open(QFile::ReadOnly);

        if (!Ret)
        {
             QMessageBox::information(this,"Tip_booklist",ofile.errorString());
             return false;
        }

        this->setStyleSheet(ofile.readAll());
        ofile.close();

}


