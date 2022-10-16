#include "adminbookmanagement.h"
#include "ui_adminbookmanagement.h"

#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QTableView>
#include <QPushButton>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QDebug>
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
#include "qglobal.h"

#include "stditemmodel.h"
#include "querybookwidget.h"
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


extern Utils now_utils;
extern vector<Book> re;
extern Book now_book;
extern int now_i;

AdminBookManagement::AdminBookManagement(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::AdminBookManagement),
        sub_mw(new MainWidget)
{
    ui->setupUi(this);
    ui->btn_bookname->setAutoExclusive(false);
    ui->btn_ISBN->setAutoExclusive(false);
    ui->btn_author->setAutoExclusive(false);
    ui->cbox_classify->addItems(QStringList() << "全部" << "历史" << "散文" << "科幻" << "互联网" << "传记" << "推理");
    ui->cbox_classify->setCurrentIndex(0);//设置默认选项

    setShadow();
    QString qssfile = ":/qss/querybookwidget/querybook.qss";
    loadQss(qssfile);

    //book_list
    model = new StdItemModel();

    model->setColumnCount(9); //设置有9列
    model->setHeaderData(0, Qt::Horizontal, "封面");
    model->setHeaderData(1, Qt::Horizontal, "书名");
    model->setHeaderData(2, Qt::Horizontal, "作者");
    model->setHeaderData(3, Qt::Horizontal, "出版社");
    model->setHeaderData(4, Qt::Horizontal, "ISBN");
    model->setHeaderData(5, Qt::Horizontal, "库存量");
    model->setHeaderData(6, Qt::Horizontal, "修改库存");
    model->setHeaderData(7, Qt::Horizontal, "修改图书");
    model->setHeaderData(8, Qt::Horizontal, "删除图书");
    ui->tb->setModel(model);
    ui->tb->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //设置列宽
    ui->tb->setColumnWidth(0, 120);            //参数：列号，宽度
    ui->tb->setColumnWidth(1, 180);
    ui->tb->setColumnWidth(2, 120);
    ui->tb->setColumnWidth(3, 180);
    ui->tb->setColumnWidth(4, 220);
    ui->tb->setColumnWidth(5, 120);
    ui->tb->setColumnWidth(6, 120);
    ui->tb->setColumnWidth(7, 90);
    ui->tb->setColumnWidth(8, 90);

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

    loadIntialBooks();
    int n = re.size();//有
    setIcons();
    maxPgs = n % maxPgNum == 0 ? n / maxPgNum : n / maxPgNum + 1;
    pages = "1/" + QString::number(maxPgs, 10);
    ui->line_3->setText(pages);
    ui->tb->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tb->setShowGrid(false);
    ui->tb->resizeRowsToContents();

    connect(ui->tb->verticalScrollBar(), &QScrollBar::valueChanged, this, &AdminBookManagement::loadBooks);
}

AdminBookManagement::~AdminBookManagement()
{
    delete ui;
}

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

void AdminBookManagement::paintEvent(QPaintEvent *)
{
    //需要Qpainter头文件
    QPainter painter(this);//初始化
    QPixmap pix;
    //背景图
    pix.load(":/image/querybook/background.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

void AdminBookManagement::on_btn_addbook_clicked()
{
    qDebug() << "abc";
}


int flag_admin = 0;//1书名，2作者，3isbn
int ctrl_admin = 0x000;

void AdminBookManagement::on_btn_bookname_clicked()
{
    if ((ctrl_admin >> 8) % 2 == 1)
    {
        ui->btn_bookname->setDown(false);
        ctrl_admin &= 0x011;
        ui->btn_bookname->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }
    else
    {

        ui->btn_bookname->setDown(true);
        ctrl_admin |= 0x100;
        flag_admin = 1;
        ui->btn_bookname->setStyleSheet("color:rgb(255,255,255);\
                                        background-color:rgb(121,109,111);");
    };
}

void AdminBookManagement::on_btn_author_clicked()
{
    if ((ctrl_admin >> 4) % 2 == 1)
    {
        ui->btn_author->setDown(false);
        ctrl_admin &= 0x101;
        ui->btn_author->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }
    else
    {
        ui->btn_author->setDown(true);
        ctrl_admin |= 0x010;
        flag_admin = 2;
        ui->btn_author->setStyleSheet("color:rgb(255,255,255);\
                                        background-color:rgb(121,109,111);");
    };
}

void AdminBookManagement::on_btn_ISBN_clicked()
{
    if ((ctrl_admin) % 2 == 1)
    {
        ui->btn_ISBN->setDown(false);
        ctrl_admin &= 0x110;
        ui->btn_ISBN->setStyleSheet("color:rgb(0,0,0);\
                                        font-family:KaiTi;\
                                        font-size:18px;\
                                        font-weight:normal;\
                                        padding:4px;");
    }

    else
    {
        ui->btn_ISBN->setDown(true);
        ctrl_admin |= 0x001;
        flag_admin = 3;
        ui->btn_ISBN->setStyleSheet("color:rgb(255,255,255);\
                                        background-color:rgb(121,109,111);");
    };
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
    if (classification == "全部" && ctrl_admin == 0)flag_admin = 1;
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

    qDebug() << "come here";
    if (re.size() != 0)
        qDebug() << "书名" << re[0].getBookName();

    AdminBookManagement *bookList = new AdminBookManagement();
    bookList->resize(1300, 730);
    bookList->setStackWidget(sub_mw);
    sub_mw->insertWidget(1, bookList);
    sub_mw->setCurrentIndex(1);
}

void AdminBookManagement::on_btn_search_clicked()
{
    QString classification = ui->cbox_classify->currentText();
    QString val = ui->lineEdit->text();

    qDebug() << "分类" << classification;
    qDebug() << "搜索值" << val;

    getBookList(classification, val);
}


void AdminBookManagement::on_lineEdit_returnPressed()
{
    AdminBookManagement *bookList = new AdminBookManagement();
    bookList->resize(1300, 730);
    sub_mw->insertWidget(1, bookList);
    sub_mw->setCurrentIndex(1);
}


void AdminBookManagement::loadIntialBooks()
{
    qDebug() << "loadIntialBooks1";
    nCurScroller = ui->tb->verticalScrollBar()->value();

    int curNum = curRecord;
    int maxLoadNum = 60;
    curRecord = re.size() <= curNum + maxLoadNum ? re.size() : curNum + maxLoadNum;

    qDebug() << "loadIntialBooks2";
    // for (int i = curNum; i < curRecord; i++)
    // {
    //     qDebug() << "loadIntialBooks3";
    //     model->setItem(i, 1, new QStandardItem(re[i].getBookName()));
    //     model->setItem(i, 2, new QStandardItem(re[i].getAuthor()));
    //     model->setItem(i, 3, new QStandardItem(re[i].getPublisher()));
    //     model->setItem(i, 4, new QStandardItem(re[i].getIsbn()));
    //     model->setItem(i, 5, new QStandardItem(re[i].getLeft() > 0 ? "有" : "无"));
    //     qDebug() << "loadIntialBooks4";
    //     ui->tb->setRowHeight(i, 150);

    // }
}

void AdminBookManagement::new_button(QString button_text,QString picture_name, int position, Book book, int i)
{
    //往表格中添加按钮控件
    QPushButton *button = new QPushButton(button_text);
    QLabel *l1 = new QLabel();     //创建lable
    string t1(book.getImgPath());
    string t2(book.getIsbn());
    string pic;
    if (t2.size() == 13)
        pic = pictureDbPath + t1 + "/" + t2 + ".jpg";
    else
        // pic = pictureDbPath + string(picture_name) + ".jpg";
        ;

    QPixmap pixmap(pic.c_str());
    QPixmap fitpixmap;
    if (pixmap.isNull())
    {
        QPixmap pixmap2((pictureDbPath + "moren.jpg").c_str());
        fitpixmap = pixmap2.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }
    else
    {
        fitpixmap = pixmap.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }

    l1->setPixmap(fitpixmap);    //加载图片
    l1->setScaledContents(true);
    l1->setAlignment(Qt::AlignCenter);      //设置居中
    ui->tb->setIndexWidget(model->index(i, 0), l1);     //显示

    //设置按钮的自定义属性
    button->setProperty("tb_ISBN", model->index(i, 4, QModelIndex()).data().toString());
    connect(button, &QPushButton::clicked, this, &AdminBookManagement::on_TableBtn_clicked);
    //将按钮加入表格中
    ui->tb->setIndexWidget(model->index(i, position), button);
}

void AdminBookManagement::loadBooks()
{

    nCurScroller = ui->tb->verticalScrollBar()->value();
    int curPg = nCurScroller % maxPgNum == 0 ? nCurScroller / maxPgNum + 1 : nCurScroller / maxPgNum + 2;//当前所在页数
    int curSumPg = curRecord % maxPgNum == 0 ? curRecord / maxPgNum : curRecord / maxPgNum + 1;//滚动条总的页数

    pages = QString::number(curPg, 10) + "/" + QString::number(maxPgs, 10);
    ui->line_3->setText(pages);
    if (curRecord == re.size() || curPg < curSumPg / 2) return;

    int maxLoadNum = 20;
    int curNum = curRecord;
    int sum = re.size();
    curRecord = sum <= (unsigned int) curNum + maxLoadNum ? sum : curNum + maxLoadNum;

    for (int i = curNum; i < curRecord; i++)
    {

        model->setItem(i, 1, new QStandardItem(re[i].getBookName()));
        model->setItem(i, 2, new QStandardItem(re[i].getAuthor()));
        model->setItem(i, 3, new QStandardItem(re[i].getPublisher()));
        model->setItem(i, 4, new QStandardItem(re[i].getIsbn()));
        model->setItem(i, 5, new QStandardItem(QString::number(re[i].getLeft())));

        ui->tb->setRowHeight(i, 150);

        AdminBookManagement::new_button("修改","moren",6,re[i],i);
        AdminBookManagement::new_button("修改","moren",7,re[i],i);
        AdminBookManagement::new_button("删除","moren",8,re[i],i);
        
    }
}

void AdminBookManagement::setStackWidget(MainWidget *p)
{
    this->psw = p;
}

void AdminBookManagement::setIcons()
{
    QPixmap pixmap(":/image/querybook/back.png");
    QPixmap fitpixmap = pixmap.scaled(35, 35, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->btn_la_3->setIcon(QIcon(fitpixmap));
    ui->btn_la_3->setIconSize(QSize(35, 35));
    ui->btn_la_3->setFlat(true);
}

void AdminBookManagement::on_TableBtn_clicked()
{
    //先获取信号的发送者
    QPushButton *button = (QPushButton *) sender();
    //提取按钮的自定义属性 数据类型须统一
    QString ISBN = button->property("tb_ISBN").toString();//根据ISBN删借阅信息
    now_utils.GetBookByIsbn(const_cast<char *>(ISBN.toStdString().c_str()), now_book);
    BookDetails *bookDetails = new BookDetails();
    bookDetails->resize(1300, 730);
    bookDetails->setStackWidget(psw);
    psw->insertWidget(2, bookDetails);
    psw->setCurrentIndex(2);

    //int Password = button->property("S_Password").toInt();
    //删除数据再重新调用

}

void AdminBookManagement::on_btn_first_3_clicked()
{
    ui->tb->verticalScrollBar()->setSliderPosition(0);
    pages = "1/" + QString::number(maxPgs, 10);
    ui->line_3->setText(pages);
}

void AdminBookManagement::on_btn_la_3_clicked()
{

    int maxValue = ui->tb->verticalScrollBar()->maximum(); // 当前SCROLLER最大显示值
    nCurScroller = ui->tb->verticalScrollBar()->value(); //获得当前scroller值
    int curPg = nCurScroller % maxPgNum == 0 ? nCurScroller / maxPgNum + 1 : nCurScroller / maxPgNum + 2;
    loadBooks();

    if (curPg < maxPgs)
    {
        ui->tb->verticalScrollBar()->setSliderPosition(maxPgNum + nCurScroller);
        pages = QString::number(curPg + 1, 10) + "/" + QString::number(maxPgs, 10);
        ui->line_3->setText(pages);
    }
    else
    {
        ui->tb->verticalScrollBar()->setSliderPosition(0);
        pages = "1/" + QString::number(maxPgs, 10);
        ui->line_3->setText(pages);
    }
}


void AdminBookManagement::on_btn_last_3_clicked()
{
    int curSumPg = curRecord % maxPgNum == 0 ? curRecord / maxPgNum : curRecord / maxPgNum + 1;//滚动条总的页数
    while (curSumPg < maxPgs)
    {
        loadIntialBooks();
        curSumPg = curRecord % maxPgNum == 0 ? curRecord / maxPgNum : curRecord / maxPgNum + 1;//滚动条总的页数
    }

    int maxValue = ui->tb->verticalScrollBar()->maximum(); // 当前SCROLLER最大显示值
    ui->tb->verticalScrollBar()->setSliderPosition(maxValue);
    pages = QString::number(maxPgs, 10) + "/" + QString::number(maxPgs, 10);
    ui->line_3->setText(pages);
}

void AdminBookManagement::on_btn_fore_3_clicked()
{
    int maxValue = ui->tb->verticalScrollBar()->maximum(); // 当前SCROLLER最大显示值
    nCurScroller = ui->tb->verticalScrollBar()->value();
    int curPg = nCurScroller % maxPgNum == 0 ? nCurScroller / maxPgNum + 1 : nCurScroller / maxPgNum + 2;
    if (nCurScroller > 0)
    {
        ui->tb->verticalScrollBar()->setSliderPosition(nCurScroller - maxPgNum);
        pages = QString::number(curPg - 1, 10) + "/" + QString::number(maxPgs, 10);
        ui->line_3->setText(pages);
    }
    else
    {
        ui->tb->verticalScrollBar()->setSliderPosition(maxValue);
        pages = QString::number(maxPgs, 10) + "/" + QString::number(maxPgs, 10);
        ui->line_3->setText(pages);
    }

}

void AdminBookManagement::on_line_3_returnPressed()
{
    int curSumPg = curRecord % maxPgNum == 0 ? curRecord / maxPgNum : curRecord / maxPgNum + 1;//滚动条总的页数
    nCurScroller = ui->tb->verticalScrollBar()->value();
    int curPg = nCurScroller % maxPgNum == 0 ? nCurScroller / maxPgNum + 1 : nCurScroller / maxPgNum + 2;
    pages = ui->line_3->text();
    int page = pages.toInt();
    if (page > maxPgs || page < 1)
    {
        pages = QString::number(curPg, 10) + '/' + QString::number(maxPgs, 10);
        ui->line_3->setText(pages);
        return;
    }
    while (curSumPg < page)
    {
        loadIntialBooks();
        curSumPg = curRecord % maxPgNum == 0 ? curRecord / maxPgNum : curRecord / maxPgNum + 1;//滚动条总的页数
    }
    ui->tb->verticalScrollBar()->setSliderPosition((page - 1) * maxPgNum);
    pages = QString::number(page, 10) + '/' + QString::number(maxPgs, 10);
    ui->line_3->setText(pages);

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
