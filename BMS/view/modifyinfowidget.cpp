#include "modifyinfowidget.h"
#include "ui_modifyinfowidget.h"

ModifyInfoWidget::ModifyInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyInfoWidget)
{
    ui->setupUi(this);
}

ModifyInfoWidget::~ModifyInfoWidget()
{
    delete ui;
}
