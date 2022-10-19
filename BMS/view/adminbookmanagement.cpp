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
extern int now_i;
int select_row=0;//用于直接修改某一条的记录
AdminBookManagement::AdminBookManagement(QWidget *parent) : QWidget(parent),
                                                            ui(new Ui::AdminBookManagement),
                                                            sub_mw(new MainWidget)
{
    ui->setupUi(this);

    ui->cbox_classify->addItems(QStringList() << "全部"
                                              << "历史"
                                              << "散文"
                                              << "科幻"
                                              << "互联网"
                                              << "传记"
                                              << "推理");
    ui->cbox_classify->setCurrentIndex(0); //设置默认选项

    setShadow();


    // book_list
    model = new StdItemModel();

    model->setColumnCount(7); //设置有9列

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
    //设置列宽
    // ui->tb->setColumnWidth(0, 120);            //参数：列号，宽度
    // ui->tb->setColumnWidth(1, 180);
    // ui->tb->setColumnWidth(2, 120);
    // ui->tb->setColumnWidth(3, 180);
    // ui->tb->setColumnWidth(4, 220);
    // ui->tb->setColumnWidth(5, 120);
    // ui->tb->setColumnWidth(6, 120);
    // ui->tb->setColumnWidth(7, 90);
    // ui->tb->setColumnWidth(8, 90);

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



    loadQss(":/qss/adminbookmanagement/bookmanagement.qss");
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
    //需要Qpainter头文件
    QPainter painter(this); //初始化
    QPixmap pix;
    //背景图
    pix.load(":/image/bookmanagement/background.jpg");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}
void AdminBookManagement::on_btn_addbook_clicked(){
    /* add book */

    AdminModifyBookDetail *admin_modify_book_detail = new AdminModifyBookDetail();
    connect(admin_modify_book_detail,SIGNAL(backSignal()),this,SLOT(backToThis()));
    admin_modify_book_detail->resize(1300, 730);
    psw->insertWidget(3,admin_modify_book_detail);
    emit changePageSignal(3);//发出切换到3号页面的信号

}
void AdminBookManagement::on_btn_addbook_batch_clicked()
{
    QMessageBox::information(NULL, QString::fromLocal8Bit(""), "请选择Excel文件,文件中列序按照封面路径、书名、作者、出版社、ISBN、分类、出版时间、总量、简介", QMessageBox::Ok);
    QString fileName = QFileDialog::getOpenFileName(this, "选择Exccel", "", tr("Excel (*.xls *.xlsx)"));

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));

    if (fileName.isEmpty())
    {
        return;
    }

    fileName.replace(QString("/"), QString("\\"));
    //qDebug() << fileName;

    fileName=QDir::toNativeSeparators(fileName);
 
    //打开Excel进程、获取工作簿、工作表、单元格
    // qDebug() << "now come1";
    QAxObject*myExcel=new QAxObject("Excel.application",this);
    myExcel->setProperty("DisplayAlerts",false);
    // qDebug() << "now come2";
    QAxObject*workBooks=myExcel->querySubObject("WorkBooks");
    workBooks->dynamicCall("Open(const QString&)",fileName);
    QAxObject*workBook=myExcel->querySubObject("ActiveWorkBook");
    QAxObject*mySheets=workBook->querySubObject("Sheets");
    QAxObject*sheet=mySheets->querySubObject("Item(int)",1);
 
    //获取已经使用的单元格区域，并得到行列数
    QAxObject*range=sheet->querySubObject("UsedRange");
    QAxObject*rows=range->querySubObject("Rows");
    QAxObject*colums=range->querySubObject("Columns");
    int count_row=rows->dynamicCall("Count").toUInt();
    int count_col=colums->dynamicCall("Count").toUInt();

    // qDebug() << "now come3";
    //提取单元格中内容，存放到StringList中
    QStringList tableString;

    tableString.clear();
    for(int i=1;i<=count_row;i++)
    {

        now_book.setImgPath(const_cast<char*>(range->querySubObject("Cells(int,int)",i,1)->dynamicCall("Value").toString().toStdString().c_str()));
        now_book.setBookName(const_cast<char*>(range->querySubObject("Cells(int,int)",i,2)->dynamicCall("Value").toString().toStdString().c_str()));
        now_book.setAuthor(const_cast<char*>(range->querySubObject("Cells(int,int)",i,3)->dynamicCall("Value").toString().toStdString().c_str()));
        now_book.setPublisher(const_cast<char*>(range->querySubObject("Cells(int,int)",i,4)->dynamicCall("Value").toString().toStdString().c_str()));
        now_book.setIsbn(const_cast<char*>(range->querySubObject("Cells(int,int)",i,5)->dynamicCall("Value").toString().toStdString().c_str()));
        now_book.setClassification(const_cast<char*>(range->querySubObject("Cells(int,int)",i,6)->dynamicCall("Value").toString().toStdString().c_str()));
        now_book.setPublishDate(const_cast<char*>(range->querySubObject("Cells(int,int)",i,7)->dynamicCall("Value").toString().toStdString().c_str()));
        now_book.setAllNum(range->querySubObject("Cells(int,int)",i,8)->dynamicCall("Value").toString().toInt());
        now_book.setIntroduction(const_cast<char*>(range->querySubObject("Cells(int,int)",i,9)->dynamicCall("Value").toString().toStdString().c_str()));

        qDebug() << now_book.getBookName();
        if(now_utils.InsertBook(now_book))
            qDebug() << "成功";
    }

    // qDebug() << "now come4";
    //关闭工作簿、结束进程
    workBook->dynamicCall("Close()");
    myExcel->dynamicCall("Quit()");
}

// use in select the way of finding books
int flag_admin = 1; // 1书名，2作者，3isbn
int ctrl_admin = 0x100;
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
}

/*
通过类别和key来得到符合条件的书本数据
*/
void AdminBookManagement::getBookList(QString classification, QString key)
{
    re.clear();
    if (classification == "全部" && ctrl_admin == 0)
        flag_admin = 1;
    qDebug() << classification << "  " << flag_admin;
    if (flag_admin == 0)
    {
        now_utils.GetBooksByClassification(const_cast<char *>(classification.toStdString().c_str()), re);
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

    // qDebug() << "come here";
    if (re.size() != 0)
        qDebug() << "书名" << re[0].getBookName();


}

void AdminBookManagement::on_btn_search_clicked()
{
    ui->btn_bookname->setDown(false);
    ui->btn_author->setDown(false);
    ui->btn_ISBN->setDown(false);
    flag_admin = 0;
    QString classification = ui->cbox_classify->currentText();
    QString val = ui->line_search->text();

    // qDebug() << "分类" << classification;
    // qDebug() << "搜索值" << val;

    getBookList(classification, val);
    loadInitialBooks();
}


void AdminBookManagement::loadInitialBooks()
{
    /* 更新page*/
    int n = re.size(); //有
    //setIcons();
    maxPgs = n % maxPgNum == 0 ? n / maxPgNum : n / maxPgNum + 1;
    qDebug()<< "maxpgs:" << maxPgs;
    pages = "1/" + QString::number(maxPgs, 10);
    ui->line->setText(pages);


    connect(ui->tb->verticalScrollBar(), &QScrollBar::valueChanged, this, &AdminBookManagement::loadBooks);



     nCurScroller = ui->tb->verticalScrollBar()->value();
     int curPg = nCurScroller % maxPgNum == 0 ? nCurScroller / maxPgNum + 1 : nCurScroller / maxPgNum + 2; //当前所在页数
     int curSumPg = curRecord % maxPgNum == 0 ? curRecord / maxPgNum : curRecord / maxPgNum + 1;           //滚动条总的页数

     pages = QString::number(curPg, 10) + "/" + QString::number(maxPgs, 10);
     ui->line->setText(pages);
     if (curRecord == re.size() || curPg < curSumPg / 2)
         return;

     int maxLoadNum = 20;
     int curNum = curRecord;
     int sum = re.size();
     curRecord = sum <= (unsigned int)curNum + maxLoadNum ? sum : curNum + maxLoadNum;

     for (int i = curNum; i < curRecord; i++)
     {
         model->setItem(i, 0, new QStandardItem(re[i].getBookName()));
         model->setItem(i, 1, new QStandardItem(re[i].getAuthor()));
         model->setItem(i, 2, new QStandardItem(re[i].getPublisher()));
         model->setItem(i, 3, new QStandardItem(re[i].getIsbn()));
         model->setItem(i, 4, new QStandardItem(QString::number(re[i].getLeft())));

         ui->tb->setRowHeight(i, 75);

         ////
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

    int maxLoadNum = 20;
    int curNum = curRecord;
    int sum = re.size();
    curRecord = sum <= (unsigned int)curNum + maxLoadNum ? sum : curNum + maxLoadNum;

    for (int i = curNum; i < curRecord; i++)
    {
        model->setItem(i, 0, new QStandardItem(re[i].getBookName()));
        model->setItem(i, 1, new QStandardItem(re[i].getAuthor()));
        model->setItem(i, 2, new QStandardItem(re[i].getPublisher()));
        model->setItem(i, 3, new QStandardItem(re[i].getIsbn()));
        model->setItem(i, 4, new QStandardItem(QString::number(re[i].getLeft())));

        ui->tb->setRowHeight(i, 75);

        ////
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

void AdminBookManagement::setStackWidget(MainWidget *p)
{
    this->psw = p;
}

//void AdminBookManagement::setIcons()
//{
//    QPixmap pixmap(":/image/querybook/back.png");
//    QPixmap fitpixmap = pixmap.scaled(35, 35, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//    ui->btn_->setIcon(QIcon(fitpixmap));
//    ui->btn_la_3->setIconSize(QSize(35, 35));
//    ui->btn_la_3->setFlat(true);
//}
void AdminBookManagement::backToThis(){

    emit changePageSignal(1);
}
void AdminBookManagement::on_TableModifyBtn_clicked()
{
    //先获取信号的发送者
    QPushButton *button = (QPushButton *)sender();

    //提取按钮的自定义属性 数据类型须统一
    QString ISBN = button->property("tb_ISBN").toString(); //根据ISBN删借阅信息

    now_utils.GetBookByIsbn(const_cast<char *>(ISBN.toStdString().c_str()), now_book);
    qDebug() << now_book.getAuthor();

    AdminModifyBookDetail *admin_modify_book_detail = new AdminModifyBookDetail();
    connect(admin_modify_book_detail,SIGNAL(backSignal()),this,SLOT(backToThis()));
    // qDebug() << "now come here5";
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

    //qDebug() << ISBN;
    now_utils.GetBookByIsbn(const_cast<char *>(ISBN.toStdString().c_str()), now_book);
    if(now_utils.DeleteBook(now_book)){
        int row = ui->tb->currentIndex().row();
        model->removeRow(row);
        //qDebug() << "delete row:" << row << "ok" <<endl;
    }


}
void AdminBookManagement::updateBookRecord(Book book){
    model->setItem(select_row, 0, new QStandardItem(book.getBookName()));
    model->setItem(select_row, 1, new QStandardItem(book.getAuthor()));
    model->setItem(select_row, 2, new QStandardItem(book.getPublisher()));
    model->setItem(select_row, 3, new QStandardItem(book.getIsbn()));
    model->setItem(select_row, 4, new QStandardItem(QString::number(book.getLeft())));
}

void AdminBookManagement::on_btn_addclassify_clicked(){
    ModifyBookCategory *modifyBookCategory = new ModifyBookCategory;
    modifyBookCategory->resize(230,450);
    modifyBookCategory->show();
}

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
