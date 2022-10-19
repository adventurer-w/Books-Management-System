#include "modifybookcategory.h"
#include "ui_modifybookcategory.h"
#include "booklist.h"
#include "ui_booklist.h"
#include <QTableView>
#include <QPushButton>
#include<QLabel>
#include"QAbstractScrollArea"
#include<QScrollBar>//滑动条
#include <QFile>
#include <QMessageBox>
#include "MainWidget.h"
#include "bookdetails.h"
#include "querybookwidget.h"
#include "backend/all_head.h"
#include "backend/Utils.h"
#include <QDebug>
#include "GlobalSetting.h"
#include"QLineEdit"
ModifyBookCategory::ModifyBookCategory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyBookCategory)
{
    ui->setupUi(this);
    model = new StdItemModel();

    model->setColumnCount(2); //设置有2列
    model->setHeaderData(0,Qt::Horizontal,"类别");  //设置第一列的表头为类型
    model->setHeaderData(1,Qt::Horizontal,"删除");  //设置第一列的表头为名称
    //model->setHeaderData(2,Qt::Horizontal,"修改");


    ui->tb->setModel(model);
    /*后续这里根据数量来动态设置列表框的高*/
    ui->tb->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->tbv_borrow->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    //ui->tb->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    //横向填满，下面设置列宽没用了
    //ui->tb->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//布局排版是全部伸展开的效果

   //loadclassify();
}

ModifyBookCategory::~ModifyBookCategory()
{
    delete ui;
}
void ModifyBookCategory::loadclassify(){
    int n=8;
    for(int i=0;i<n;i++){
        QLineEdit *l;
        l->setText("理工类");
        ui->tb->setIndexWidget(model->index(i,0),l);     //显示
        connect(l,&QLineEdit::returnPressed,this,&ModifyBookCategory::on_linePressed);
    //returnPressed()

         QPushButton *btn_delete = new QPushButton("删除");
         ui->tb->setIndexWidget(model->index(i,1),btn_delete);     //显示
         connect(btn_delete,&QPushButton::clicked,this,&ModifyBookCategory::on_btn_delete_clicked);

//         QPushButton *btn_modify = new QPushButton("修改");
//         ui->tb->setIndexWidget(model->index(i,2),btn_modify);     //显示
//         connect(btn_delete,&QPushButton::clicked,this,&ModifyBookCategory::on_btn_modify_clicked);
    }
}
void ModifyBookCategory::on_linePressed(){
    QLineEdit *line = (QLineEdit*)sender();
    //提取按钮的自定义属性 数据类型须统一
   // QString ISBN = button->property("tb_ISBN").toString();//根据ISBN删借阅信息
//    now_utils.GetBookByIsbn(const_cast<char*>(ISBN.toStdString().c_str()),now_book);
//    BookDetails *bookDetails= new BookDetails();
//    bookDetails->resize(1300,730);
//    bookDetails->setStackWidget(psw);
//    psw->insertWidget(2,bookDetails);
//    psw->setCurrentIndex(2);
    QString classify = line->text();

    qDebug()<<classify;
}
//void ModifyBookCategory::on_btn_modify_clicked(){

//}

void ModifyBookCategory::on_btn_delete_clicked(){

}
