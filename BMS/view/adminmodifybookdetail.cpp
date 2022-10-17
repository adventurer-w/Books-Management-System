#include "adminmodifybookdetail.h"
#include "ui_adminmodifybookdetail.h"

AdminModifyBookDetail::AdminModifyBookDetail(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminModifyBookDetail)
{
    ui->setupUi(this);
}

AdminModifyBookDetail::~AdminModifyBookDetail()
{
    delete ui;
}
