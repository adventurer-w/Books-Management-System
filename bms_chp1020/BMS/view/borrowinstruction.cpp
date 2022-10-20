#include "borrowinstruction.h"
#include "ui_borrowinstruction.h"

BorrowInstruction::BorrowInstruction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BorrowInstruction)
{
    ui->setupUi(this);
    //loadQss();
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
