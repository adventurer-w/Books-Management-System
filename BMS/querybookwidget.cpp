#include "querybookwidget.h"
#include "ui_querybookwidget.h"

QueryBookWidget::QueryBookWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QueryBookWidget)
{
    ui->setupUi(this);
}

QueryBookWidget::~QueryBookWidget()
{
    delete ui;
}
