#include "adminbookmanagement.h"
#include "ui_adminbookmanagement.h"

#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QTableView>
#include <QPushButton>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QFrame>
#include <QLabel>
#include <QLayout>
#include <QColor>
#include <QFile>
#include <QMessageBox>
#include <QScrollBar>
#include <QString>
#include <QStackedLayout>
#include <QFontDialog>
#include <QListView>
#include <QObject>
#include <QAxObject>
#include "qglobal.h"

#include "stditemmodel.h"
#include "ui_userprofilewidget.h"
#include "MainWidget.h"
#include "searchlineedit.h"
#include "ui_searchlineedit.h"
#include "bookranking.h"

#include "booklist.h"
#include "bookdetails.h"
#include "querybookwidget.h"
#include "backend/all_head.h"
#include "backend/Utils.h"
#include "GlobalSetting.h"

#include "adminmodifybookdetail.h"
#include "modifybookcategory.h"
#include <QtGlobal>
#include <QCoreApplication>
#include <QtCore>
#include <QVariant>
#include <QDebug>
#include <QFileDialog>
#include <iostream>
using namespace std;

extern Utils now_utils;
extern vector<Book> re;
extern Book now_book;
extern vector<Book> result;
extern vector<Book> result_boy;
extern vector<Book> result_girl;
extern vector<Book> result_point;
extern int now_i;
int add_or_mod;
int select_row=0;//用于直接修改某一条的记录
AdminBookManagement::AdminBookManagement(QWidget *parent) : QWidget(parent),
                                                            ui(new Ui::AdminBookManagement),
                                                            sub_mw(new MainWidget)
{
    //顶部栏设置
    //基于querybookwidget
    ui->setupUi(this);


    load_classify();
    setShadow();

    //图书搜索栏与图书搜索结果列表
    //基于book_list
    model = new StdItemModel();

    model->setColumnCount(7); //设置有7列
    model->setHeaderData(0, Qt::Horizontal, "书名");
    model->setHeaderData(1, Qt::Horizontal, "作者");
    model->setHeaderData(2, Qt::Horizontal, "出版社");
    model->setHeaderData(3, Qt::Horizontal, "ISBN");
    model->setHeaderData(4, Qt::Horizontal, "库存量");
    model->setHeaderData(5, Qt::Horizontal, "修改图书");
    model->setHeaderData(6, Qt::Horizontal, "删除图书");
    ui->tb->setModel(model);
    ui->tb->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->tb->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //布局排版是全部伸展开的效果

    //隐藏行头
    ui->tb->verticalHeader()->hide();
    //设置表格选中时为整行选中
    ui->tb->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置表格的单元为只读属性，即不能编辑
    ui->tb->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置单选
    ui->tb->setSelectionMode(QAbstractItemView::SingleSelection);
    //设置多选
    ui->tb->setSelectionMode(QAbstractItemView::MultiSelection);

    ui->tb->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tb->setShowGrid(false);
    ui->tb->resizeRowsToContents();
    connect(ui->tb->verticalScrollBar(), &QScrollBar::valueChanged, this, &AdminBookManagement::loadBooks);
    loadQss(":/qss/adminbookmanagement/bookmanagement.qss");

}

void AdminBookManagement::load_classify()
{
    //单独写出来是为了在modifybookcategory里面调用
    QStringList classify_list;
    classify_list << "全部";
    vector<BookClass> now_book_class;
    now_utils.GetAllClass(now_book_class);
    int n = now_book_class.size();
    for (int i = 0; i < n; i++)
    {
        classify_list << now_book_class[i].getName();
    }

    ui->cbox_classify->addItems(classify_list);
    ui->cbox_classify->setCurrentIndex(0); //设置默认选项
}

AdminBookManagement::~AdminBookManagement()
{
    delete ui;
}

// use in paint top of GUI
void AdminBookManagement::setShadow()
{
    QAbstractItemView *view = ui->cbox_classify->view();

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(6);
    effect->setColor(Qt::black);
    effect->setOffset(0, 0);
    view->setGraphicsEffect(effect);
    view->update();

    static_cast<QWidget *>(view->parent())
        ->setStyleSheet(
            "QWidget{border:none;background-color: rgb(255, 255, 255);}");

    QWidget *container = static_cast<QWidget *>(view->parent());
    container->setAttribute(Qt::WA_TranslucentBackground);
    container->setWindowFlag(Qt::FramelessWindowHint);
    container->setWindowFlag(Qt::NoDropShadowWindowHint);
}

// use in paint top of GUI
void AdminBookManagement::paintEvent(QPaintEvent *)
{
    QPainter painter(this); //初始化，需要Qpainter头文件
    QPixmap pix;//背景图
    pix.load(":/image/bookmanagement/background.jpg");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}


void AdminBookManagement::on_btn_addbook_clicked()
{
    //0代表添加
    add_or_mod = 0;
    AdminModifyBookDetail *admin_modify_book_detail = new AdminModifyBookDetail();
    connect(admin_modify_book_detail,SIGNAL(backSignal()),this,SLOT(backToThis()));//绑定返回按钮
    admin_modify_book_detail->resize(1300, 730);
    admin_modify_book_detail->move(this->x(),this->y());
    psw->insertWidget(3,admin_modify_book_detail);
    emit changePageSignal(3);//发出切换到3号页面的信号
}

/*
    批量添加书籍按钮 按下之后功能实现
    首先是弹出提示框，请用户选择excel
    读入整个excel
    并将整个excel中的书存入本地
    debug中会输出每本书是否成功
    本来是想设计成每成功一本弹出一下的，但是这样肯定不友好
    所以从简，提示成功了多少本就行
*/
void AdminBookManagement::on_btn_addbook_batch_clicked()
{
    //弹出提示框
    QMessageBox::information(NULL, QString::fromLocal8Bit(""), "请选择Excel文件,文件中列序按照封面路径、书名、作者、出版社、ISBN、分类、出版时间、总量、简介。会从excel第二行开始读取", QMessageBox::Ok);
    //请用户选择excel，默认路径是在项目地址下
    QString fileName = QFileDialog::getOpenFileName(this, "选择Exccel", "", tr("Excel (*.xls *.xlsx)"));
    //设置编码解码
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    //若读到的文件为空就退出
    if (fileName.isEmpty())
    {
        return;
    }
    //重构地址，用于c的文件读写
    fileName.replace(QString("/"), QString("\\"));
    //qDebug() << fileName;
    fileName = QDir::toNativeSeparators(fileName);

    //打开Excel进程、获取工作簿、工作表、单元格
    QAxObject *myExcel = new QAxObject("Excel.application", this);
    myExcel->setProperty("DisplayAlerts", false);
    //获取workbook
    QAxObject *workBooks = myExcel->querySubObject("WorkBooks");
    workBooks->dynamicCall("Open(const QString&)", fileName);
    //获取整个表格
    QAxObject *workBook = myExcel->querySubObject("ActiveWorkBook");
    QAxObject *mySheets = workBook->querySubObject("Sheets");
    QAxObject *sheet = mySheets->querySubObject("Item(int)", 1);

    //获取已经使用的单元格区域，并得到行列数
    QAxObject *range = sheet->querySubObject("UsedRange");
    QAxObject *rows = range->querySubObject("Rows");
    QAxObject *colums = range->querySubObject("Columns");
    int count_row = rows->dynamicCall("Count").toUInt();
    int count_col = colums->dynamicCall("Count").toUInt();

    int success_num = 0;
    //从第二行开始读
    for (int i = 2; i <= count_row; i++)
    {
        string pic = "zother/" + range->querySubObject("Cells(int,int)", i, 5)->dynamicCall("Value").toString().toStdString() + ".jpg";
        now_book.setImgPath(const_cast<char *>(pic.c_str()));
        qDebug() << "pic:" << QString::fromStdString(pic);
        pic = pictureDbPath + pic;
        QString save_filename =  QString::fromStdString(pic);
        save_filename.replace(QString("\\"), QString("/"));
        bool x = QFile::copy(range->querySubObject("Cells(int,int)", i, 1)->dynamicCall("Value").toString(),save_filename);


//        now_book.setImgPath(const_cast<char *>(pic.c_str()));
        //写入各种图书信息
//        now_book.setImgPath(const_cast<char *>(range->querySubObject("Cells(int,int)", i, 1)->dynamicCall("Value").toString().toStdString().c_str()));
        now_book.setBookName(const_cast<char *>(range->querySubObject("Cells(int,int)", i, 2)->dynamicCall("Value").toString().toStdString().c_str()));
        now_book.setAuthor(const_cast<char *>(range->querySubObject("Cells(int,int)", i, 3)->dynamicCall("Value").toString().toStdString().c_str()));
        now_book.setPublisher(const_cast<char *>(range->querySubObject("Cells(int,int)", i, 4)->dynamicCall("Value").toString().toStdString().c_str()));
        now_book.setIsbn(const_cast<char *>(range->querySubObject("Cells(int,int)", i, 5)->dynamicCall("Value").toString().toStdString().c_str()));
        //添加新的classify对应的No
        string classify_name = const_cast<char *>(range->querySubObject("Cells(int,int)", i, 6)->dynamicCall("Value").toString().toStdString().c_str());
        // qDebug() << classify_name.c_str();
        vector<BookClass> now_book_class;
        //表格中有错误的分类就报错
        if(now_utils.GetClassByName(const_cast<char*>(classify_name.c_str()),now_book_class) == 0)
        {
            qDebug() << QString::fromStdString(classify_name);
            QMessageBox::information(this,"录入失败","分类有误");
            return;
        }
        // qDebug() << now_book_class[0].getClassNo();
        now_book.setClassNo(now_book_class[0].getClassNo());
        // qDebug() << "match add book you can set ClassByName";
        now_book.setPublishDate(const_cast<char *>(range->querySubObject("Cells(int,int)", i, 7)->dynamicCall("Value").toString().toStdString().c_str()));
        now_book.setAllNum(range->querySubObject("Cells(int,int)", i, 8)->dynamicCall("Value").toString().toInt());
        now_book.setLeft(range->querySubObject("Cells(int,int)", i, 8)->dynamicCall("Value").toString().toInt());
        now_book.setIntroduction(const_cast<char *>(range->querySubObject("Cells(int,int)", i, 9)->dynamicCall("Value").toString().toStdString().c_str()));

        //控制台提醒哪些书籍添加完毕
        if (now_utils.InsertBook(now_book))
        {
            qDebug() << now_book.getBookName() << "成功";
            success_num++;
        }
        else
            qDebug() << now_book.getBookName() << "失败";

    }
    //浅浅提示一下用户
    string aa = "录入数量："+to_string(success_num);
    QMessageBox::information(this,"录入成功",QString::fromStdString(aa));

    //关闭工作簿、结束进程
    workBook->dynamicCall("Close()");
    myExcel->dynamicCall("Quit()");
}

// 以下方法都是用来在管理员界面查找书籍的
int flag_admin = 0; // 1书名，2作者，3isbn

void AdminBookManagement::on_btn_bookname_clicked()
{
    if(flag_admin == 1){
        flag_admin=0;
        ui->btn_bookname->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }
    else {

        flag_admin=1;
        ui->btn_bookname->setStyleSheet("color:rgb(255,255,255);\
                                        background-color:rgb(121,109,111);");
        ui->btn_author->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
        ui->btn_ISBN->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }
}

void AdminBookManagement::on_btn_author_clicked()
{
    if(flag_admin == 2){
        flag_admin=0;
        ui->btn_author->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }
    else {

        flag_admin=2;
        ui->btn_author->setStyleSheet("color:rgb(255,255,255);\
                                        background-color:rgb(121,109,111);");
        ui->btn_bookname->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
        ui->btn_ISBN->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }

}

void AdminBookManagement::on_btn_ISBN_clicked()
{
    if(flag_admin == 3){
        flag_admin=0;
        ui->btn_ISBN->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }
    else {
        flag_admin=3;
        ui->btn_ISBN->setStyleSheet("color:rgb(255,255,255);\
                                        background-color:rgb(121,109,111);");
        ui->btn_bookname->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
        ui->btn_author->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }
}

void AdminBookManagement::on_cbox_classify_currentIndexChanged(int)
{
    flag_admin = 0;

    ui->btn_ISBN->setStyleSheet("color:rgb(0,0,0);\
                                font-family:KaiTi;\
                                font-size:18px;\
                                font-weight:normal;\
                                padding:4px;");
    ui->btn_bookname->setStyleSheet("color:rgb(0,0,0);\
                                    font-family:KaiTi;\
                                    font-size:18px;\
                                    font-weight:normal;\
                                    padding:4px;");
    ui->btn_author->setStyleSheet("color:rgb(0,0,0);\
                                    font-family:KaiTi;\
                                    font-size:18px;\
                                    font-weight:normal;\
                                    padding:4px;");
}

/*
通过类别和key来得到符合条件的书本数据
*/
void AdminBookManagement::getBookList(QString classification, QString key)
{
    if (classification == "全部" && flag_admin == 0)
        flag_admin = 1;

    //qDebug() << classification << "  " << flag_admin;
    if (flag_admin == 0)
    {
//        now_utils.GetBooksByClassification(const_cast<char *>(classification.toStdString().c_str()), re);
        vector<BookClass> now_book_class;
        now_utils.GetClassByName(const_cast<char*>(classification.toStdString().c_str()),now_book_class);
        now_utils.GetBooksByClassNo(now_book_class[0].getClassNo(),re);
    }
    else if (flag_admin == 1)
    {
        now_utils.GetBooksByBookName(const_cast<char *>(key.toStdString().c_str()), re);
    }
    else if (flag_admin == 2)
    {
        now_utils.GetBooksByAuthor(const_cast<char *>(key.toStdString().c_str()), re);
    }
    else
    {
        now_utils.GetBookByIsbn(const_cast<char *>(key.toStdString().c_str()), now_book);
        re.push_back(now_book);
    }
    model->setRowCount(re.size());

    if (re.size() != 0)
        qDebug() << "书名" << re[0].getBookName();


}

void AdminBookManagement::on_btn_search_clicked()
{
    ui->btn_bookname->setDown(false);
    ui->btn_author->setDown(false);
    ui->btn_ISBN->setDown(false);
    re.clear();

    ui->tb->verticalScrollBar()->setValue(0);

    QString classification = ui->cbox_classify->currentText();
    QString val = ui->line_search->text();

    getBookList(classification, val);
    curRecord=0;
    loadInitialBooks();
    flag_admin = 0;
}


void AdminBookManagement::loadInitialBooks()
{
    /* 更新page*/
    int n = re.size(); //有
    //setIcons();
    maxPgs = n % maxPgNum == 0 ? n / maxPgNum : n / maxPgNum + 1;
    //qDebug()<< "maxpgs:" << maxPgs;
    pages = "1/" + QString::number(maxPgs, 10);
    ui->line->setText(pages);

     nCurScroller = ui->tb->verticalScrollBar()->value();
     int curPg = nCurScroller % maxPgNum == 0 ? nCurScroller / maxPgNum + 1 : nCurScroller / maxPgNum + 2; //当前所在页数
     int curSumPg = curRecord % maxPgNum == 0 ? curRecord / maxPgNum : curRecord / maxPgNum + 1;           //滚动条总的页数

     pages = QString::number(curPg, 10) + "/" + QString::number(maxPgs, 10);
     ui->line->setText(pages);


     int maxLoadNum = 100;
     int curNum = curRecord;
     int sum = re.size();
     curRecord = sum <= (unsigned int)curNum + maxLoadNum ? sum : curNum + maxLoadNum;

     for (int i = curNum; i < curRecord; i++)
     {

         model->setData(model->index(i,0),re[i].getBookName());
         model->setData(model->index(i,1),re[i].getAuthor());
         model->setData(model->index(i,2),re[i].getPublisher());
         model->setData(model->index(i,3),re[i].getIsbn());
         model->setData(model->index(i,4),QString::number(re[i].getLeft()));



         ui->tb->setRowHeight(i, 75);

         ////
         //载入修改按钮，一开始是准备写成函数的，但是发现就两个按钮，函数还要不停的传参，就算了
         QPushButton *button = new QPushButton("修改");
         string t1(re[i].getImgPath());
         string t2(re[i].getIsbn());
         string pic;
         if (t2.size() == 13)
             pic = pictureDbPath + t1 + "/" + t2 + ".jpg";
         else
             pic = pictureDbPath + string("moren") + ".jpg";
         QPixmap pixmap(pic.c_str());
         QPixmap fitpixmap;
         if (pixmap.isNull())
         {
             QPixmap pixmap2((pictureDbPath + "moren.jpg").c_str());
             fitpixmap = pixmap2.scaled(120, 75, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
         }
         else
         {
             fitpixmap = pixmap.scaled(120, 75, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
         }
         button->setProperty("tb_ISBN", model->index(i, 3, QModelIndex()).data().toString()); //设置按钮的自定义属性
         connect(button, &QPushButton::clicked, this, &AdminBookManagement::on_TableModifyBtn_clicked);
         ui->tb->setIndexWidget(model->index(i, 5), button); //将按钮加入表格中
         ////
         ////
         //载入删除按钮
         QPushButton *button_remove = new QPushButton("删除");
         string t1_2(re[i].getImgPath());
         string t2_2(re[i].getIsbn());
         string pic_2;
         if (t2.size() == 13)
             pic_2 = pictureDbPath + t1_2 + "/" + t2_2 + ".jpg";
         else
             pic_2 = pictureDbPath + string("moren") + ".jpg";
         QPixmap pixmap_2(pic_2.c_str());
         QPixmap fitpixmap_2;
         if (pixmap_2.isNull())
         {
             QPixmap pixmap2_2((pictureDbPath + "moren.jpg").c_str());
             fitpixmap_2 = pixmap2_2.scaled(120, 75, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
         }
         else
         {
             fitpixmap_2 = pixmap_2.scaled(120, 75, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
         }
         button_remove->setProperty("tb_ISBN", model->index(i, 3, QModelIndex()).data().toString()); //设置按钮的自定义属性

         connect(button_remove, &QPushButton::clicked, this, &AdminBookManagement::on_remove_clicked);
         ui->tb->setIndexWidget(model->index(i, 6), button_remove); //将按钮加入表格中
         ////
     }
      update();
}

void AdminBookManagement::loadBooks()
{
    nCurScroller = ui->tb->verticalScrollBar()->value();
    int curPg = nCurScroller % maxPgNum == 0 ? nCurScroller / maxPgNum + 1 : nCurScroller / maxPgNum + 2; //当前所在页数
    int curSumPg = curRecord % maxPgNum == 0 ? curRecord / maxPgNum : curRecord / maxPgNum + 1;           //滚动条总的页数

    pages = QString::number(curPg, 10) + "/" + QString::number(maxPgs, 10);
    ui->line->setText(pages);
    if (curRecord == re.size() || curPg < curSumPg / 2)
        return;

    int maxLoadNum = 100;
    int curNum = curRecord;
    int sum = re.size();
    curRecord = sum <= (unsigned int)curNum + maxLoadNum ? sum : curNum + maxLoadNum;

    for (int i = curNum; i < curRecord; i++)
    {
        model->setData(model->index(i,0),re[i].getBookName());
        model->setData(model->index(i,1),re[i].getAuthor());
        model->setData(model->index(i,2),re[i].getPublisher());
        model->setData(model->index(i,3),re[i].getIsbn());
        model->setData(model->index(i,4),QString::number(re[i].getLeft()));
        ui->tb->setRowHeight(i, 75);

        QPushButton *button = new QPushButton("修改");

        button->setProperty("tb_ISBN", model->index(i, 3, QModelIndex()).data().toString()); //设置按钮的自定义属性
        connect(button, &QPushButton::clicked, this, &AdminBookManagement::on_TableModifyBtn_clicked);
        ui->tb->setIndexWidget(model->index(i, 5), button); //将按钮加入表格中

        QPushButton *button_remove = new QPushButton("删除");

        button_remove->setProperty("tb_ISBN", model->index(i, 3, QModelIndex()).data().toString()); //设置按钮的自定义属性
        connect(button_remove, &QPushButton::clicked, this, &AdminBookManagement::on_remove_clicked);
        ui->tb->setIndexWidget(model->index(i, 6), button_remove); //将按钮加入表格中

    }
    update();
}

void AdminBookManagement::setStackWidget(MainWidget *p)
{
    this->psw = p;
}

void AdminBookManagement::backToThis(){

    emit changePageSignal(1);
}
void AdminBookManagement::on_TableModifyBtn_clicked()
{
    add_or_mod = 1;

    //先获取信号的发送者
    QPushButton *button = (QPushButton *)sender();

    //提取按钮的自定义属性 数据类型须统一
    QString ISBN = button->property("tb_ISBN").toString(); //根据ISBN删借阅信息

    now_utils.GetBookByIsbn(const_cast<char *>(ISBN.toStdString().c_str()), now_book);
    //qDebug() << now_book.getAuthor();

    AdminModifyBookDetail *admin_modify_book_detail = new AdminModifyBookDetail();
    connect(admin_modify_book_detail,SIGNAL(backSignal()),this,SLOT(backToThis()));
    admin_modify_book_detail->resize(1300, 730);
    psw->insertWidget(3,admin_modify_book_detail);
    /* 连接修改图书信息的信号和槽，以Book为参数*/
    connect(admin_modify_book_detail,SIGNAL(bookUpdateSignal(Book)),this,SLOT(updateBookRecord(Book)));

    emit changePageSignal(3);
    select_row = ui->tb->currentIndex().row();
}

void AdminBookManagement::on_remove_clicked()
{
    QPushButton *button = (QPushButton *)sender();

    //提取按钮的自定义属性 数据类型须统一
    QString ISBN = button->property("tb_ISBN").toString(); //根据ISBN删借阅信息

    now_utils.GetBookByIsbn(const_cast<char *>(ISBN.toStdString().c_str()), now_book);
    if(now_utils.DeleteBook(now_book)){
        int row = ui->tb->currentIndex().row();
        model->removeRow(row);
    }

}

void AdminBookManagement::on_btn_updateRank_clicked()
{
    if(now_utils.UpdateBookRank())
        qDebug()<<"总借阅榜单update成功！";
    if(now_utils.UpdateGirlRank())
        qDebug()<<"女生借阅排行榜update成功！";
    if(now_utils.UpdateBoyRank())
        qDebug()<<"男生借阅排行榜update成功！";
    if(now_utils.UpdatePointRank())
        qDebug()<<"高分借阅排行榜update成功！";
}

void AdminBookManagement::updateBookRecord(Book book)
{
    //将图书信息一一更新
    model->setItem(select_row, 0, new QStandardItem(book.getBookName()));
    model->setItem(select_row, 1, new QStandardItem(book.getAuthor()));
    model->setItem(select_row, 2, new QStandardItem(book.getPublisher()));
    model->setItem(select_row, 3, new QStandardItem(book.getIsbn()));
    model->setItem(select_row, 4, new QStandardItem(QString::number(book.getLeft())));
    ui->tb->setRowHeight(select_row,75);
}

void AdminBookManagement::on_btn_addclassify_clicked()
{
    //添加新类别
    ModifyBookCategory *modifyBookCategory = new ModifyBookCategory;
    modifyBookCategory->setWindowTitle("类别操作");
    modifyBookCategory->resize(270,450);
    modifyBookCategory->show();
}

//以下函数是翻页相关
void AdminBookManagement::on_btn_first_clicked()
{
    ui->tb->verticalScrollBar()->setSliderPosition(0);
    pages = "1/" + QString::number(maxPgs, 10);
    ui->line->setText(pages);
}

void AdminBookManagement::on_btn_la_clicked()
{

    int maxValue = ui->tb->verticalScrollBar()->maximum(); // 当前SCROLLER最大显示值
    nCurScroller = ui->tb->verticalScrollBar()->value();   //获得当前scroller值
    int curPg = nCurScroller % maxPgNum == 0 ? nCurScroller / maxPgNum + 1 : nCurScroller / maxPgNum + 2;
    loadBooks();

    if (curPg < maxPgs)
    {
        ui->tb->verticalScrollBar()->setSliderPosition(maxPgNum + nCurScroller);
        pages = QString::number(curPg + 1, 10) + "/" + QString::number(maxPgs, 10);
        ui->line->setText(pages);
    }
    else
    {
        ui->tb->verticalScrollBar()->setSliderPosition(0);
        pages = "1/" + QString::number(maxPgs, 10);
        ui->line->setText(pages);
    }
}

void AdminBookManagement::on_btn_last_clicked()
{
    int curSumPg = curRecord % maxPgNum == 0 ? curRecord / maxPgNum : curRecord / maxPgNum + 1; //滚动条总的页数
    while (curSumPg < maxPgs)
    {
        loadInitialBooks();
        //qDebug()<< "curPg:"<< curSumPg << "sumPg: "<< maxPgs;
        curSumPg = curRecord % maxPgNum == 0 ? curRecord / maxPgNum : curRecord / maxPgNum + 1; //滚动条总的页数
    }

    int maxValue = ui->tb->verticalScrollBar()->maximum(); // 当前SCROLLER最大显示值
    ui->tb->verticalScrollBar()->setSliderPosition(maxValue);
    pages = QString::number(maxPgs, 10) + "/" + QString::number(maxPgs, 10);
    ui->line->setText(pages);
}

void AdminBookManagement::on_btn_fore_clicked()
{
    int maxValue = ui->tb->verticalScrollBar()->maximum(); // 当前SCROLLER最大显示值
    nCurScroller = ui->tb->verticalScrollBar()->value();
    int curPg = nCurScroller % maxPgNum == 0 ? nCurScroller / maxPgNum + 1 : nCurScroller / maxPgNum + 2;
    if (nCurScroller > 0)
    {
        ui->tb->verticalScrollBar()->setSliderPosition(nCurScroller - maxPgNum);
        pages = QString::number(curPg - 1, 10) + "/" + QString::number(maxPgs, 10);
        ui->line->setText(pages);
    }
    else
    {
        ui->tb->verticalScrollBar()->setSliderPosition(maxValue);
        pages = QString::number(maxPgs, 10) + "/" + QString::number(maxPgs, 10);
        ui->line->setText(pages);
    }
}

void AdminBookManagement::on_line_search_returnPressed()
{
    int curSumPg = curRecord % maxPgNum == 0 ? curRecord / maxPgNum : curRecord / maxPgNum + 1; //滚动条总的页数
    nCurScroller = ui->tb->verticalScrollBar()->value();
    int curPg = nCurScroller % maxPgNum == 0 ? nCurScroller / maxPgNum + 1 : nCurScroller / maxPgNum + 2;
    pages = ui->line->text();
    int page = pages.toInt();
    if (page > maxPgs || page < 1)
    {
        pages = QString::number(curPg, 10) + '/' + QString::number(maxPgs, 10);
        ui->line->setText(pages);
        return;
    }
    while (curSumPg < page)
    {
        loadInitialBooks();
        curSumPg = curRecord % maxPgNum == 0 ? curRecord / maxPgNum : curRecord / maxPgNum + 1; //滚动条总的页数
    }
    ui->tb->verticalScrollBar()->setSliderPosition((page - 1) * maxPgNum);
    pages = QString::number(page, 10) + '/' + QString::number(maxPgs, 10);
    ui->line->setText(pages);
}
void AdminBookManagement::on_btn_updaterank_clicked(){
    now_utils.GetBookRank(result);
    now_utils.GetBoyRank(result_boy);
    now_utils.GetGirlRank(result_girl);
    now_utils.GetPointRank(result_point);
    qDebug() << "update success!";
}
bool AdminBookManagement::loadQss(const QString &StyleSheetFile)
{
    /*QSS文件所在的路径*/
    QFile ofile(StyleSheetFile);
    bool Ret = ofile.open(QFile::ReadOnly);

    if (!Ret)
    {
        QMessageBox::information(this, "Tip_adminInfo", ofile.errorString());
        return false;
    }

    this->setStyleSheet(ofile.readAll());
    ofile.close();
}
