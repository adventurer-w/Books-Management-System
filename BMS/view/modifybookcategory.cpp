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
#include<QInputDialog>
#include "adminmodifybookdetail.h"

extern Utils now_utils;
extern vector<BookClass> now_book_class;

ModifyBookCategory::ModifyBookCategory(QWidget *parent) : QWidget(parent),
                                                          ui(new Ui::ModifyBookCategory)
{
    ui->setupUi(this);
    model = new StdItemModel();

    model->setColumnCount(3);                        //设置有3列
    model->setHeaderData(0, Qt::Horizontal, "类别"); //设置第一列的表头为类型
    model->setHeaderData(1, Qt::Horizontal, "删除"); //设置第一列的表头为名称
    model->setHeaderData(2, Qt::Horizontal, "修改");

    ui->tb->setModel(model);
    /*后续这里根据数量来动态设置列表框的高*/
    ui->tb->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    loadclassify();
}

ModifyBookCategory::~ModifyBookCategory()
{
    delete ui;
}
void ModifyBookCategory::loadclassify()
{
    qDebug() << "re";
    vector<BookClass> now_book_class;
    now_utils.GetAllClass(now_book_class);
    int n = now_book_class.size();
    for (int i = 0; i < n; i++)
    {
        model->setItem(i, 0, new QStandardItem(now_book_class[i].getName()));

        QPushButton *btn_delete = new QPushButton("删除");
        ui->tb->setIndexWidget(model->index(i, 1), btn_delete); //显示
        btn_delete->setProperty("tb_classify_name", now_book_class[i].getName());
        btn_delete->setProperty("tb_classify_no", i);
        //绑定按钮与对应的行数，用来后面区分删除按钮
        connect(btn_delete, &QPushButton::clicked, this, &ModifyBookCategory::on_btn_delete_clicked);

        QPushButton *btn_update = new QPushButton("修改");
        ui->tb->setIndexWidget(model->index(i, 2), btn_update); //显示
        btn_update->setProperty("tb_classify_name", now_book_class[i].getName());
        btn_update->setProperty("tb_classify_no", i);
        connect(btn_update, &QPushButton::clicked, this, &ModifyBookCategory::on_btn_update_clicked);
    }
    //绑定addclassify按钮与addclassify功能
    connect(ui->btn_addclassify, &QPushButton::clicked, this, &ModifyBookCategory::on_btn_addclassify_clicked);
}

void ModifyBookCategory::on_linePressed()
{
    QLineEdit *line = (QLineEdit *)sender();
    QString classify = line->text();
}

void ModifyBookCategory::on_btn_addclassify_clicked()
{
    //    qDebug() << "on btn_addclassify clicked";
    //获取文本框内容
    QString classify_name = ui->line_addclassify->text();
    //读取已有的类别，以此来找到未使用的新一位编号
    vector<BookClass> now_book_class;
    now_utils.GetAllClass(now_book_class);
    int n = now_book_class.size();

    //新建一个BookClass，存入对应属性
    BookClass book_class;
    book_class.setId(n);
    book_class.setName(const_cast<char *>(classify_name.toStdString().c_str()));

    //添加类别，并反馈
    if (now_utils.InsertClass(book_class))
    {
        QMessageBox::information(this, "添加类别", "添加类别成功啦！");
        //动态添加新的行
        vector<BookClass> now_book_class;
        now_utils.GetAllClass(now_book_class);
        int n = now_book_class.size();
        model->setItem(n - 1, 0, new QStandardItem(now_book_class[n - 1].getName()));
        QPushButton *btn_delete = new QPushButton("删除");
        ui->tb->setIndexWidget(model->index(n - 1, 1), btn_delete); //显示
        btn_delete->setProperty("tb_classify_name", now_book_class[n - 1].getName());
        btn_delete->setProperty("tb_classify_no", n - 1);

        //绑定按钮与对应的行数，用来后面区分删除按钮
        connect(btn_delete, &QPushButton::clicked, this, &ModifyBookCategory::on_btn_delete_clicked);
    }
    else
    {
        QMessageBox::information(this, "添加类别", "添加类别出了点问题！");
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
    book_class.setName(const_cast<char *>(classify_name.toStdString().c_str()));
    book_class.setClassNo(classify_no.toInt());

    //删除对应的行
    if (now_utils.DeleteClass(book_class))
    {
        int row = ui->tb->currentIndex().row();
        model->removeRow(row);
    }
}

void ModifyBookCategory::on_btn_update_clicked()
{
    //获取对应的行
    QPushButton *button = (QPushButton *)sender();
    QString classify_name = button->property("tb_classify_name").toString();
    QString classify_no = button->property("tb_classify_no").toString();

    bool ok;
    QString text = QInputDialog::getText(this, tr("类别修改"),tr("请输入新的类别名称"), QLineEdit::Password,0, &ok);
    if (ok && !text.isEmpty())
    {
        BookClass book_class;
        book_class.setName(const_cast<char *>(classify_name.toStdString().c_str()));
        book_class.setClassNo(classify_no.toInt());
        now_utils.DeleteClass(book_class);
        //先删后改
        book_class.setName(const_cast<char *>(text.toStdString().c_str()));
        book_class.setClassNo(classify_no.toInt());
        now_utils.InsertClass(book_class);
        QMessageBox::information(this, "添加类别", "修改成功");
    }else{
        QMessageBox::information(this, "添加类别", "修改失败");
    }


    loadclassify();
}
