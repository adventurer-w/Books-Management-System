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
}

BorrowInstruction::~BorrowInstruction()
{
    delete ui;
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


