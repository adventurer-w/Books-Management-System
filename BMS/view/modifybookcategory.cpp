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
#include <QLineEdit>

#include<QInputDialog>
#include "adminmodifybookdetail.h"

extern Utils now_utils;
extern vector<BookClass> now_book_class;

ModifyBookCategory::ModifyBookCategory(QWidget *parent) : QWidget(parent),
                                                          ui(new Ui::ModifyBookCategory)
{
    ui->setupUi(this);
    model = new StdItemModel();


    model->setColumnCount(2);
    //设置有3列
    model->setHeaderData(0, Qt::Horizontal, "类别"); //设置第一列的表头为类型
    model->setHeaderData(1, Qt::Horizontal, "删除"); //设置第一列的表头为名称
   


    ui->tb->setModel(model);
    /*后续这里根据数量来动态设置列表框的高*/
    ui->tb->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tb->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//所有列都扩展自适应宽度，填充充满整个屏幕宽度

    ui->tb->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);//对第0列单独设置固定宽度
    ui->tb->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Fixed);//对第0列单独设置固定宽度


    //设置列宽
    ui->tb->setColumnWidth(0,60);
    ui->tb->setColumnWidth(1,100);//参数：列号，宽度
    loadclassify();
}

ModifyBookCategory::~ModifyBookCategory()
{
    delete ui;
}
void ModifyBookCategory::loadclassify()
{
    model->removeRows(0, model->rowCount()); // 删除所有行

    vector<BookClass> now_book_class;
    now_utils.GetAllClass(now_book_class);
    int n = now_book_class.size();
    model->setRowCount(n);

    for (int i = 0; i < n; i++)
    {
        //model->setItem(i, 0, new QStandardItem(now_book_class[i].getName()));
        QLineEdit *le = new QLineEdit;
        le->setText(now_book_class[i].getName());
        ui->tb->setIndexWidget(model->index(i,0),le);
        le->setProperty("tb_classify_name", now_book_class[i].getName());
        le->setProperty("tb_classify_no", now_book_class[i].getClassNo());
        le->setProperty("new_classify_name","");
        connect(le,&QLineEdit::returnPressed,this,&ModifyBookCategory::tableModifyClicked);
        connect(le,&QLineEdit::textChanged,this,&ModifyBookCategory::leModifyText);

        QPushButton *btn_delete = new QPushButton("删除");
        ui->tb->setIndexWidget(model->index(i, 1), btn_delete); //显示
        btn_delete->setProperty("tb_classify_name", now_book_class[i].getName());
        btn_delete->setProperty("tb_classify_no", now_book_class[i].getClassNo());
        //绑定按钮与对应的行数，用来后面区分删除按钮
        connect(btn_delete, &QPushButton::clicked, this, &ModifyBookCategory::on_btn_delete_clicked);

    }
    //绑定addclassify按钮与addclassify功能
    connect(ui->btn_addclassify, &QPushButton::clicked, this, &ModifyBookCategory::on_btn_addclassify_clicked);

}

void ModifyBookCategory::on_linePressed()
{
    QLineEdit *line = (QLineEdit *)sender();
    QString classify = line->text();
//    AdminBookManagement::load_classify();
}

void ModifyBookCategory::on_btn_addclassify_clicked()
{
    //    qDebug() << "on btn_addclassify clicked";
    //获取文本框内容
    QString classify_name = ui->line_addclassify->text();

    if(classify_name.size()==0){
        QMessageBox::information(this, "添加类别", "请输入类名");
        return;
    }

    //读取已有的类别，以此来找到未使用的新一位编号
    vector<BookClass> now_book_class;
    now_utils.GetAllClass(now_book_class);
    int n = now_book_class.size();
    int nextNo = 0;
    for(int i= 0; i< n; ++i){
        if(nextNo<now_book_class[i].classNo)nextNo=now_book_class[i].classNo;
    }
    nextNo++;
    //新建一个BookClass，存入对应属性
    BookClass book_class;
    book_class.setClassNo(nextNo);
    book_class.setName(const_cast<char *>(classify_name.toStdString().c_str()));

    //添加类别，并反馈
    if (now_utils.InsertClass(book_class))
    {
        QMessageBox::information(this, "添加类别", "添加类别成功啦！");

        //动态添加新的行
        vector<BookClass> now_book_class;
        now_utils.GetAllClass(now_book_class);
        n = now_book_class.size();
        //model->setItem(n - 1, 0, new QStandardItem(now_book_class[n - 1].getName()));
        model->setRowCount(n);
        QLineEdit *le = new QLineEdit;
        le->setText(now_book_class[n-1].getName());
        ui->tb->setIndexWidget(model->index(n-1,0),le);
        le->setProperty("tb_classify_name", now_book_class[n-1].getName());
        le->setProperty("tb_classify_no", now_book_class[n-1].getClassNo());
        connect(le,&QLineEdit::returnPressed,this,&ModifyBookCategory::tableModifyClicked);
        connect(le,&QLineEdit::textChanged,this,&ModifyBookCategory::leModifyText);


        QPushButton *btn_delete = new QPushButton("删除");
        ui->tb->setIndexWidget(model->index(n - 1, 1), btn_delete); //显示
        btn_delete->setProperty("tb_classify_name", now_book_class[n - 1].getName());
        btn_delete->setProperty("tb_classify_no", now_book_class[n-1].getClassNo());

        //绑定按钮与对应的行数，用来后面区分删除按钮
        connect(btn_delete, &QPushButton::clicked, this, &ModifyBookCategory::on_btn_delete_clicked);
        emit updateCategorySignal();
    }
    else
    {
        QMessageBox::information(this, "添加类别", "添加类别出了点问题！");
    }
}

void ModifyBookCategory::on_btn_delete_clicked()
{
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

        vector<Book> bt;
        now_utils.GetBooksByClassNo(stoi(classify_no.toStdString().c_str()),bt);
        if(bt.size()>0){
            QMessageBox::StandardButton result=QMessageBox::question(this,"提示信息","该分类仍有图书，删除后该图书分类将为未知，是否确认删除",QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
            if(result==QMessageBox::Yes){
                QMessageBox::information(this, "提示信息", "该功能需要较长时间，请稍候！");
                //将该分类的书置为未知分类
                for(int i=0;i<bt.size();i++){
                    Book bt2;
                    bt2.setIsbn(bt[i].getIsbn());
                    bt[i].setClassNo(100);
                    now_utils.UpdateBook(bt2,bt[i]);
                }
                //删除该分类
                if (now_utils.DeleteClass(book_class))
                {
                    int row = ui->tb->currentIndex().row();
                    model->removeRow(row);
                    emit updateCategorySignal();
                    QMessageBox::information(this, "提示信息", "删除成功！");
                }
            }
        }
        //删除对应的行
        else if (now_utils.DeleteClass(book_class))
        {
            int row = ui->tb->currentIndex().row();
            model->removeRow(row);
            emit updateCategorySignal();
            QMessageBox::information(this, "提示信息", "删除成功！");
        }
}

void ModifyBookCategory::leModifyText(const QString text){
    QLineEdit *le = (QLineEdit *)sender();
    le->setProperty("new_classify_name",text);
}
void ModifyBookCategory::tableModifyClicked()
{
    //获取对应的行
    QLineEdit *le = (QLineEdit *)sender();
    QString classify_name = le->property("tb_classify_name").toString();

    if(classify_name.size()==0){
        QMessageBox::information(this, "添加类别", "请输入类别名称");
        return;
    }

    QString classify_no = le->property("tb_classify_no").toString();

    QString new_name = le->property("new_classify_name").toString();

    if (!classify_name.isEmpty() && new_name!="")

    {
        BookClass old_book_class;
        old_book_class.setName(const_cast<char *>(classify_name.toStdString().c_str()));
        old_book_class.setClassNo(classify_no.toInt());

        BookClass new_book_class;
        new_book_class.setName(const_cast<char *>(new_name.toStdString().c_str()));
        new_book_class.setClassNo(classify_no.toInt());
        //qDebug()<< "old:"<< classify_name << "new : "<< new_name;


        if(now_utils.ChangeClassByNo(old_book_class,new_book_class) == true){
            QMessageBox::information(this, "添加类别", "修改成功");
            emit updateCategorySignal();
        }
        else{
            QMessageBox::information(this, "添加类别", "修改失败");
        }


    }else{
        QMessageBox::information(this, "添加类别", "修改失败");
    }


    loadclassify();
}
