#include "searchlineedit.h"
#include "ui_searchlineedit.h"
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include <QMessageBox>
#include <QLabel>
#include <QDebug>
#include <QObject>
SearchLineEdit::SearchLineEdit(QWidget *parent) :
    QLineEdit(parent),
    ui(new Ui::SearchLineEdit)
{
    ui->setupUi(this);
    btn=new QPushButton(this);
    btn->setEnabled(true);
    QLabel *lb = new QLabel;
    lb->setText("Search");
    QHBoxLayout* layout=new QHBoxLayout(this);
    layout->setMargin(10);
    layout->setSpacing(0);
    layout->addStretch(1);
    layout->addWidget(lb);

    /*将图标图片缩小到指定尺寸*/
    QPixmap pixmap(":/image/SearchLineEdit/search.png");
    QPixmap fitpixmap = pixmap.scaled(20, 20, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    btn->setIcon(QIcon(fitpixmap));
    btn->setIconSize(QSize(20, 20));
    btn->setFlat(true);

    layout->addStretch(49);
    layout->addWidget(btn);
    btn->raise();
    this->setLayout(layout);
    btn->setFixedSize(20,20);
    lb->setFixedSize(100,20);

    this->setGeometry(0,0,360,40);
    //this->setFixedSize(360,40);
    // 设置输入框中文件输入区，不让输入的文字被隐藏在按钮
    this->setTextMargins(70, 0, 20 , 0);//left,top,right,bottom
    this->setMaxLength(20);
    loadQss(":/qss/searchlineedit/le_btn.qss");
    this->setAlignment((Qt::AlignVCenter));
    QObject::connect(btn,SIGNAL(clicked()),this,SLOT(sendKey()));
}

bool SearchLineEdit::loadQss(const QString &StyleSheetFile){

        /*QSS文件所在的路径*/
        QFile ofile(StyleSheetFile);
        bool Ret = ofile.open(QFile::ReadOnly);

        if (!Ret)
        {
             QMessageBox::information(this,"Tip_searchLineEdit",ofile.errorString());
             return false;
        }

        this->setStyleSheet(ofile.readAll());
        ofile.close();

}
SearchLineEdit::~SearchLineEdit()
{
    delete ui;
}

void SearchLineEdit::sendKey(){
        emit this->keySignal(this->text());
}
