#include "adminmodifybookdetail.h"
#include "ui_adminmodifybookdetail.h"
#include <QFile>
#include <QMessageBox>
#include "backend/all_head.h"
#include <backend/Utils.h>
#include <backend/User.h>
#include <QDebug>
#include <QPainter>
#include "GlobalSetting.h"
#include <qdatetime.h>
#include <QFileDialog>

#include <QImage>
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
#include <QScreen>
#include <QGuiApplication>
extern Utils now_utils;
extern User now_user;
extern vector<Book> re;
extern Book now_book;
extern int add_or_mod;

AdminModifyBookDetail::AdminModifyBookDetail(QWidget *parent) : QWidget(parent),
                                                                ui(new Ui::AdminModifyBookDetail)
{
    ui->setupUi(this);

    loadBookDetail();
    setIcons();
    loadQss(":/qss/bookdetails/bookdetails.qss");
}

AdminModifyBookDetail::~AdminModifyBookDetail()
{
    delete ui;
}
void AdminModifyBookDetail::paintEvent(QPaintEvent *)
{
    //需要Qpainter头文件
    QPainter painter(this); //初始化
    QPixmap pix;
    //背景图
    pix.load(":/image/bookmanagement/background.jpg");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}
void AdminModifyBookDetail::loadBookDetail()
{
    //只有在修改界面下才会预载入这些旧书的信息
    if (add_or_mod == 1)
    {
        ui->line_bookname->setText(now_book.getBookName());
        ui->line_author->setText(now_book.getAuthor());
        ui->line_publish->setText(now_book.getPublisher());
        ui->line_ISBN->setText(now_book.getIsbn());
        //        ui->line_classify->setText(now_book.getClassifition());
        vector<BookClass> now_book_class;
        now_utils.GetClassByNo(now_book.getClassNo(), now_book_class);
        ui->line_classify->setText(now_book_class[0].getName());
        ui->line_publishtime->setText(now_book.getPublishDate());
        ui->line_remain->setText(QString::number(now_book.getAllNum()));
        ui->lineEdit->insertPlainText(now_book.getIntroduction());
    }

    connect(ui->book_pushButton, &QPushButton::clicked, this, &AdminModifyBookDetail::on_pushButton_clicked);
    connect(ui->btn_modifyimage, &QPushButton::clicked, this, &AdminModifyBookDetail::on_btn_modifyimage_clicked);

    QLabel *l1 = new QLabel(); //创建lable

    l1->setFixedSize(120, 150);

    string t1(now_book.getImgPath());
    string t2(now_book.getIsbn());
    string pic;
    if (t2.size() == 13)
        pic = pictureDbPath + t1;
    else
        pic = pictureDbPath + "moren.jpg";
    qDebug() << QString::fromStdString(pic);

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
    ui->lb_bookphoto->setPixmap(fitpixmap); //加载图片

    ui->lb_bookphoto->setScaledContents(true);
    ui->lb_bookphoto->setAlignment(Qt::AlignCenter); //设置居中
}
void AdminModifyBookDetail::setStackWidget(MainWidget *p)
{
    this->psw = p;
}
void AdminModifyBookDetail::on_btn_back_clicked()
{

    emit backSignal();
}
void AdminModifyBookDetail::setIcons()
{
    /*将图标图片缩小到指定尺寸*/
    QPixmap pixmap(":/image/querybook/back.png");
    QPixmap fitpixmap = pixmap.scaled(35, 35, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->btn_back->setIcon(QIcon(fitpixmap));
    ui->btn_back->setIconSize(QSize(35, 35));
    ui->btn_back->setFlat(true);
}
bool AdminModifyBookDetail::loadQss(const QString &StyleSheetFile)
{
    /*QSS文件所在的路径*/
    QFile ofile(StyleSheetFile);
    bool Ret = ofile.open(QFile::ReadOnly);

    if (!Ret)
    {
        QMessageBox::information(this, "Tip_bookdetails", ofile.errorString());
        return false;
    }

    this->setStyleSheet(ofile.readAll());
    ofile.close();
}

void AdminModifyBookDetail::on_btn_modifyimage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "选择图片", "", tr("JPEG Files(*.jpg);;PNG Files(*.png)"));
    fileName.replace(QString("/"), QString("\\"));
    qDebug() << fileName;

    QString runPath;
    QString hglpName;
    QString hglpPath;

    runPath = QCoreApplication::applicationDirPath(); //获取exe路径
    hglpName = "photo";
    hglpPath = QString("%1/%2").arg(runPath).arg(hglpName);

    if (fileName.isEmpty())
        return;
    else
    {
        QImage img;
        if (!(img.load(fileName))) //加载图像
        {
            QMessageBox::information(this, tr("打开图像失败"), tr("打开图像失败!"));
            return;
        }
        ui->lb_bookphoto->setPixmap(QPixmap::fromImage(img.scaled(ui->lb_bookphoto->size())));
    }
}

void AdminModifyBookDetail::on_pushButton_clicked()
{
    Book old_book;
    old_book.setIsbn(now_book.getIsbn());
    //读取各个line的值
    QString bookname = ui->line_bookname->text();       //书名
    QString author = ui->line_author->text();           //作者
    QString publish = ui->line_publish->text();         //出版社
    QString ISBN = ui->line_ISBN->text();               // ISBN
    QString classify = ui->line_classify->text();       //类别
    QString publishtime = ui->line_publishtime->text(); //出版时间
    QString remain = ui->line_remain->text();           //库存
    QString introduction = ui->lineEdit->toPlainText();

    //存储图片到对应目录下，我这里是在cover下新建了一个zother文件夹
    string pic = "zother/" + ISBN.toStdString() + ".jpg";
    now_book.setImgPath(const_cast<char *>(pic.c_str()));
    pic = pictureDbPath + pic;
    QString save_filename =  QString::fromStdString(pic);
    save_filename.replace(QString("\\"), QString("/"));
    QScreen *screen = QGuiApplication::primaryScreen();
    screen->grabWindow(ui->lb_bookphoto->winId()).save(save_filename);

    //设置新值
    now_book.setBookName(const_cast<char *>(bookname.toStdString().c_str()));
    now_book.setAuthor(const_cast<char *>(author.toStdString().c_str()));
    now_book.setPublisher(const_cast<char *>(publish.toStdString().c_str()));
    now_book.setIsbn(const_cast<char *>(ISBN.toStdString().c_str()));
    //    now_book.setClassification(const_cast<char*>(classify.toStdString().c_str()));
    vector<BookClass> now_book_class;
    qDebug() << "get now_book_class";
    if (now_utils.GetClassByName(const_cast<char *>(classify.toStdString().c_str()), now_book_class) == 0)
    {
        QMessageBox::information(this, "录入失败", "分类有误");
        return;
    }
    now_book.setClassNo(now_book_class[0].getClassNo());
    qDebug() << now_book_class[0].getClassNo();
    now_book.setPublishDate(const_cast<char *>(publishtime.toStdString().c_str()));
    //区分新书库存、旧书增加库存
    if (add_or_mod == 0)
    {
        now_book.setLeft(remain.toInt());
        now_book.setAllNum(remain.toInt());
    }
    if (add_or_mod == 1)
    {
        int add_count = remain.toInt() - now_book.getAllNum();
        now_book.setLeft(now_book.getLeft() + add_count);
        now_book.setAllNum(remain.toInt());
    }
    now_book.setIntroduction(const_cast<char *>(introduction.toStdString().c_str()));

    //简单的信息提示
    if (add_or_mod == 0)
    {
        if (now_utils.InsertBook(now_book))
        {
            QMessageBox::information(this, "添加信息", "添加图书成功啦！");
            emit bookUpdateSignal(now_book);
            emit backSignal();
        }
        else
        {
            QMessageBox::information(this, "添加信息", "真可惜，添加图书信息失败了!");
        }
    }
    if (add_or_mod == 1)
    {
        if (now_utils.UpdateBook(old_book, now_book))
        {
            QMessageBox::information(this, "修改信息", "修改图书信息成功啦！");
            emit bookUpdateSignal(now_book);
            emit backSignal();
        }
        else
        {
            QMessageBox::information(this, "修改信息", "真可惜，修改图书信息失败了!");
        }
    }
}
