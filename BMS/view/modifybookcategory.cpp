#include "modifybookcategory.h"
#include "ui_modifybookcategory.h"
#include "booklist.h"
#include "ui_booklist.h"
#include <QTableView>
#include <QPushButton>
#include <QLabel>
#include "QAbstractScrollArea"
#include <QScrollBar> //滑动条
#include <QFile>
#include <QMessageBox>
#include "MainWidget.h"
#include "bookdetails.h"
#include "querybookwidget.h"
#include "backend/all_head.h"
#include "backend/Utils.h"
#include <QDebug>
#include "GlobalSetting.h"
#include "QLineEdit"

extern Utils now_utils;
extern vector<BookClass> now_book_class;

ModifyBookCategory::ModifyBookCategory(QWidget *parent) : QWidget(parent),
                                                          ui(new Ui::ModifyBookCategory)
{
    ui->setupUi(this);
    model = new StdItemModel();

    model->setColumnCount(2);                        //设置有2列
    model->setHeaderData(0, Qt::Horizontal, "类别"); //设置第一列的表头为类型
    model->setHeaderData(1, Qt::Horizontal, "删除"); //设置第一列的表头为名称

    ui->tb->setModel(model);
    /*后续这里根据数量来动态设置列表框的高*/
    ui->tb->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // ui->tbv_borrow->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    // ui->tb->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    //横向填满，下面设置列宽没用了
    // ui->tb->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//布局排版是全部伸展开的效果

     loadclassify();
}

ModifyBookCategory::~ModifyBookCategory()
{
    delete ui;
}
void ModifyBookCategory::loadclassify()
{
    vector<BookClass> now_book_class;
    now_utils.GetAllClass(now_book_class);
    int n = now_book_class.size();
    for (int i = 0; i < n; i++)
    {
        model->setItem(i, 0, new QStandardItem(now_book_class[i].getName()));
//        qDebug() << "成功载入类别名";
        QPushButton *btn_delete = new QPushButton("删除");
        ui->tb->setIndexWidget(model->index(i, 1), btn_delete); //显示

        btn_delete->setProperty("tb_classify_name", now_book_class[i].getName());
        btn_delete->setProperty("tb_classify_no", i);

        //绑定按钮与对应的行数，用来后面区分删除按钮
        connect(btn_delete, &QPushButton::clicked, this, &ModifyBookCategory::on_btn_delete_clicked);
    }
    //绑定addclassify按钮与addclassify功能
    connect(ui->btn_addclassify, &QPushButton::clicked, this, &ModifyBookCategory::on_btn_addclassify_clicked);
}
void ModifyBookCategory::on_linePressed()
{
    QLineEdit *line = (QLineEdit *)sender();
    //提取按钮的自定义属性 数据类型须统一
    // QString ISBN = button->property("tb_ISBN").toString();//根据ISBN删借阅信息
    //    now_utils.GetBookByIsbn(const_cast<char*>(ISBN.toStdString().c_str()),now_book);
    //    BookDetails *bookDetails= new BookDetails();
    //    bookDetails->resize(1300,730);
    //    bookDetails->setStackWidget(psw);
    //    psw->insertWidget(2,bookDetails);
    //    psw->setCurrentIndex(2);
    QString classify = line->text();

    qDebug() << classify;
}
// void ModifyBookCategory::on_btn_modify_clicked(){

//}

void ModifyBookCategory::on_btn_addclassify_clicked()
{
//    qDebug() << "on btn_addclassify clicked";
    //获取文本框内容
    QString classify_name=ui->line_addclassify->text();
    //读取已有的类别，以此来找到未使用的新一位编号
    vector<BookClass> now_book_class;
    now_utils.GetAllClass(now_book_class);
    int n = now_book_class.size();

    //新建一个BookClass，存入对应属性
    BookClass book_class;
    book_class.setId(n);
    book_class.setName(const_cast<char*>(classify_name.toStdString().c_str()));

    //添加类别，并反馈
    if(now_utils.InsertClass(book_class)){
        QMessageBox::information(this,"添加类别","添加类别成功啦！");
        //动态添加新的行
        vector<BookClass> now_book_class;
        now_utils.GetAllClass(now_book_class);
        int n = now_book_class.size();
        model->setItem(n-1, 0, new QStandardItem(now_book_class[n-1].getName()));
        QPushButton *btn_delete = new QPushButton("删除");
        ui->tb->setIndexWidget(model->index(n-1, 1), btn_delete); //显示
        btn_delete->setProperty("tb_classify_name", now_book_class[n-1].getName());
        btn_delete->setProperty("tb_classify_no", n-1);

        //绑定按钮与对应的行数，用来后面区分删除按钮
        connect(btn_delete, &QPushButton::clicked, this, &ModifyBookCategory::on_btn_delete_clicked);
    }else{
        QMessageBox::information(this,"添加类别","添加类别出了点问题！");
    }
}

void ModifyBookCategory::on_btn_delete_clicked()
{
//    qDebug() << "on_btn_delete_clicked";
    //获取对应的行
    QPushButton *button = (QPushButton *)sender();
    QString classify_name = button->property("tb_classify_name").toString();
    QString classify_no = button->property("tb_classify_no").toString(); //根据classify_no删类别
//    qDebug() << "classify_no = " << classify_no;

    //获取对应名称，并赋予临时创建的book_class
//    vector<BookClass> now_book_class;
//    now_utils.GetClassByNo(classify_no.toInt() - 1,now_book_class);
    BookClass book_class;
    book_class.setName(const_cast<char*>(classify_name.toStdString().c_str()));
    book_class.setClassNo(classify_no.toInt());

    //删除对应的行
    if(now_utils.DeleteClass(book_class)){
        int row = ui->tb->currentIndex().row();
        model->removeRow(row);
    }
}
