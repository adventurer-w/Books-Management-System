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
    vector<Department> result;
    for(int i = 0; i < 4; i++ )
        now_utils.GetDepartmentByNo(i,result);
    ui->line_teacher->setText(QString::number(result[0].getMaxBook()));
    ui->line_undergraduate->setText(QString::number(result[1].getMaxBook()));
    ui->line_master->setText(QString::number(result[2].getMaxBook()));
    ui->line_doctor->setText(QString::number(result[3].getMaxBook()));
}

BorrowInstruction::~BorrowInstruction()
{
    delete ui;
}

void BorrowInstruction::on_btn_modifyConfirm_clicked(){
    //读入四个文本框
    int limit_book[4];
    limit_book[0] = ui->line_teacher->text().toInt();
    limit_book[1]=ui->line_undergraduate->text().toInt();
    limit_book[2]=ui->line_master->text().toInt();
    limit_book[3]=ui->line_doctor->text().toInt();

    //对应写入
    vector<Department> result;
    for(int i = 0; i < 4; i ++ )
    {
        now_utils.GetDepartmentByNo(i,result);
        result[i].setMaxBook(limit_book[i]);
    }
    
    //增加弹窗
    QMessageBox::information(this,"修改信息","修改成功");

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


