#include "adminbookmanagement.h"
#include "ui_adminbookmanagement.h"

AdminBookManagement::AdminBookManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminBookManagement)
{
    ui->setupUi(this);
}

AdminBookManagement::~AdminBookManagement()
{
    delete ui;
}
