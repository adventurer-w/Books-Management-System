#include "booklist.h"
#include "ui_booklist.h"
#include <QTableView>
#include <QPushButton>
#include<QLabel>
#include <QStandardItem>
#include <QStandardItemModel>
#include "stditemmodel.h"
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
#include <QLineEdit>
#include "GlobalSetting.h"
extern Utils now_utils;
extern vector<Book> re;
extern Book now_book;
extern int now_i;

//#include<Qpagi
BookList::BookList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookList )
{
    ui->setupUi(this);
    tbv = new QTableView();
    tbv->move(50,50);
    tbv->resize(1250,630);
    tbv->setParent(this);

    le=new QLineEdit();
    le->move(578,691);
    le->resize(110,30);
    le->setParent(this);

    model = new StdItemModel();
    model->clear();
    model->setColumnCount(7); //设置有7列
    model->setHeaderData(0,Qt::Horizontal,"封面");  //设置第一列的表头为类型
    model->setHeaderData(1,Qt::Horizontal,"书名");  //设置第一列的表头为名称
    model->setHeaderData(2,Qt::Horizontal,"作者");
    model->setHeaderData(3,Qt::Horizontal,"出版社");
    model->setHeaderData(4,Qt::Horizontal,"ISBN");
    model->setHeaderData(5,Qt::Horizontal,"有无库存");
    model->setHeaderData(6,Qt::Horizontal,"详情");

    tbv->setModel(model);
    /*后续这里根据数量来动态设置列表框的高*/
    tbv->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //tbvv_borrow->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    //tbv->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    //横向填满，下面设置列宽没用了
    //tbv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//布局排版是全部伸展开的效果

    //设置列宽
    tbv->setColumnWidth(0,120);			//参数：列号，宽度
    tbv->setColumnWidth(1,180);
    tbv->setColumnWidth(2,180);
    tbv->setColumnWidth(3,180);
    tbv->setColumnWidth(4,220);
    tbv->setColumnWidth(5,180);
    tbv->setColumnWidth(6,180);
    //设置行高
  //  tbv->verticalHeader()->setDefaultSectionSize(250);

    //隐藏行头
    tbv->verticalHeader()->hide();
    //设置表格选中时为整行选中
    tbv->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置表格的单元为只读属性，即不能编辑
    tbv->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置单选
    tbv->setSelectionMode(QAbstractItemView::SingleSelection);
    //设置多选
    tbv->setSelectionMode(QAbstractItemView::MultiSelection);

    //qDebug()<<re.size();
    loadInitialBooks();
    int n = re.size();//有
    setIcons();
    maxPgs=n%maxPgNum==0? n/maxPgNum : n/maxPgNum+1;
    pages="1/"+QString::number(maxPgs,10);
    le->setText(pages);
    tbv->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    tbv->setShowGrid(false);
    tbv->resizeRowsToContents();
    loadQss(":/qss/booklist/booklist.qss");

   // connect(tbv->verticalScrollBar(), SIGNAL(valueChanged(int)), pSpinBox, SLOT(setValue(int)));
    //connect(tbv->verticalScrollBar(),&QScrollBar::sliderReleased,this,&BookList::loadBooks);
    //connect(tbv->verticalScrollBar(),&QScrollBar::sliderPressed,this,&BookList::loadBooks);
    connect(tbv->verticalScrollBar(),&QScrollBar:: valueChanged,this,&BookList::loadBooks);

}

/*
加载每个页面的图书列表项目
*/
//line输入跳转时
void BookList::loadInitialBooks(){
    nCurScroller = tbv->verticalScrollBar()->value();

    int curNum = curRecord;
    int maxLoadNum = 0;
    model->setRowCount(re.size()-1);
    tbv->horizontalHeader()->setDefaultSectionSize(150);
    curRecord = re.size() <= curNum+maxLoadNum ? re.size():curNum+maxLoadNum;

    for(int i=curNum;i<curRecord;i++){

//        model->setItem(i, 1, new QStandardItem(re[i].getBookName()));
//        model->setItem(i, 2, new QStandardItem(re[i].getAuthor()));
//        model->setItem(i, 3, new QStandardItem(re[i].getPublisher()));
//        model->setItem(i, 4, new QStandardItem(re[i].getIsbn()));
//        model->setItem(i, 5, new QStandardItem(re[i].getLeft()>0 ? "有":"无"));
        model->setData(model->index(i, 1), re[i].getBookName());
        model->setData(model->index(i, 2), re[i].getAuthor());
        model->setData(model->index(i, 3), re[i].getPublisher());
        model->setData(model->index(i, 4), re[i].getIsbn());
        model->setData(model->index(i, 5), re[i].getLeft()>0 ? "有":"无");


        tbv->setRowHeight(i,150);
        //往表格中添加按钮控件
        QPushButton *button = new QPushButton("详情");
        QLabel *l1 = new QLabel();     //创建lable

        string t1(re[i].getImgPath());
        string t2(re[i].getIsbn());
        string pic;
        if(t2.size()==13)
                   pic=pictureDbPath+t1;
               else
                   pic=pictureDbPath+"moren.jpg";

        QPixmap pixmap(pic.c_str());
       QPixmap fitpixmap;
       if(pixmap.isNull()){
           qDebug()<<"1空";
           QPixmap pixmap2((pictureDbPath+"moren.jpg").c_str());
           fitpixmap = pixmap2.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
       }else{
           fitpixmap = pixmap.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
       }



        l1->setPixmap(fitpixmap);    //加载图片
        l1->setScaledContents(true);
        l1->setAlignment(Qt::AlignCenter);      //设置居中
        tbv->setIndexWidget(model->index(i,0),l1);     //显示

        //设置按钮的自定义属性
        button->setProperty("tb_ISBN",model->index(i,4,QModelIndex()).data().toString());
         connect(button,&QPushButton::clicked,this,&BookList::on_TableBtn_clicked);
        //将按钮加入表格中
        tbv->setIndexWidget(model->index(i,6),button);


    }
}
/*
滚动条监听函数，如果当前滚动条到了最大滚动条的一半，则执行函数继续加载maxLoadNum条；否认返回
*/
void BookList::loadBooks(){

    nCurScroller = tbv->verticalScrollBar()->value();
    int curPg=   nCurScroller%maxPgNum==0?  nCurScroller/maxPgNum+1:nCurScroller/maxPgNum+2;//当前所在页数
    int curSumPg =  curRecord%maxPgNum==0 ? curRecord/maxPgNum:curRecord/maxPgNum+1;//滚动条总的页数

    pages=QString::number(curPg,10)+"/"+QString::number(maxPgs,10);
    le->setText(pages);
    if(curRecord==re.size()-1){
        qDebug()<<"stop :"<<endl;
        emit stopSignal();
        return;
    }
    if(curRecord==re.size()-1 || curPg<curSumPg/2) return;

    int maxLoadNum = 20;
    int curNum = curRecord;
    int sum = re.size();
    curRecord = sum <= (unsigned int)curNum+ maxLoadNum ? sum:curNum+ maxLoadNum;

    for(int i=curNum;i<curRecord;i++){

        model->setData(model->index(i, 1), re[i].getBookName());
        model->setData(model->index(i, 2), re[i].getAuthor());
        model->setData(model->index(i, 3), re[i].getPublisher());
        model->setData(model->index(i, 4), re[i].getIsbn());
        model->setData(model->index(i, 5), re[i].getLeft()>0 ? "有":"无");
        //qDebug()<< i << " ";
        tbv->setRowHeight(i,150);
        //往表格中添加按钮控件
        QPushButton *button = new QPushButton("详情");
        QLabel *l1 = new QLabel();     //创建lablel        //qDebug()<< -i << " ";
        string t1(re[i].getImgPath());
        string t2(re[i].getIsbn());
        string pic;
        if(t2.size()==13)
                   pic=pictureDbPath+t1+"/"+t2+".jpg";
               else
                   pic=pictureDbPath+"moren.jpg";

        QPixmap pixmap(pic.c_str());
       QPixmap fitpixmap;
       if(pixmap.isNull()){
           QPixmap pixmap2((pictureDbPath+"moren.jpg").c_str());
           fitpixmap = pixmap2.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
       }else{
           fitpixmap = pixmap.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
       }

        //qDebug()<< i << " ";
        l1->setPixmap(fitpixmap);    //加载图片
        l1->setScaledContents(true);
        qDebug()<< i+1 << " ";
        l1->setAlignment(Qt::AlignCenter);      //设置居中
        tbv->setIndexWidget((const QModelIndex &)model->index(i,0),l1);     //显示
         //model->setData(model->index(i, 0), l1);
        qDebug()<< -i << " ";
        //设置按钮的自定义属性
        button->setProperty("tb_ISBN",(const QVariant &)(model->index(i,4,QModelIndex()).data().toString()));
        connect(button,&QPushButton::clicked,this,&BookList::on_TableBtn_clicked);
        //qDebug()<< i << " ";
        //将按钮加入表格中
        tbv->setIndexWidget((const QModelIndex &)model->index(i,6),button);


    }
}
//void BookList::loadBooks(){

//    nCurScroller = tbv->verticalScrollBar()->value();
//    int curPg=   nCurScroller%maxPgNum==0?  nCurScroller/maxPgNum+1:nCurScroller/maxPgNum+2;//当前所在页数
//    int curSumPg =  curRecord%maxPgNum==0 ? curRecord/maxPgNum:curRecord/maxPgNum+1;//滚动条总的页数

//    pages=QString::number(curPg,10)+"/"+QString::number(maxPgs,10);
//    le->setText(pages);
//    if(curRecord==re.size()-1){
//        qDebug()<<"stop :"<<endl;
//        emit stopSignal();
//        return;
//    }
//    if(curRecord==re.size()-1 || curPg<curSumPg/2) return;

//    int maxLoadNum = 20;
//    int curNum = curRecord;
//    int sum = re.size();
//    curRecord = sum <= (unsigned int)curNum+ maxLoadNum ? sum:curNum+ maxLoadNum;

//    for(int i=curNum;i<curRecord;i++){

//        model->setItem(i, 1, new QStandardItem(re[i].getBookName()));
//        model->setItem(i, 2, new QStandardItem(re[i].getAuthor()));
//        model->setItem(i, 3, new QStandardItem(re[i].getPublisher()));
//        model->setItem(i, 4, new QStandardItem(re[i].getIsbn()));
//        model->setItem(i, 5, new QStandardItem(re[i].getLeft()>0 ? "有":"无"));

//        tbv->setRowHeight(i,150);
//        //往表格中添加按钮控件
//        QPushButton *button = new QPushButton("详情");
//        QLabel *l1 = new QLabel();     //创建lable
//        string t1(re[i].getImgPath());
//        string t2(re[i].getIsbn());
//        string pic;
//        if(t2.size()==13)
//                   pic=pictureDbPath+t1+"/"+t2+".jpg";
//               else
//                   pic=pictureDbPath+"moren.jpg";

//        QPixmap pixmap(pic.c_str());
//               QPixmap fitpixmap;
//               if(pixmap.isNull()){
//                   QPixmap pixmap2((pictureDbPath+"moren.jpg").c_str());
//                   fitpixmap = pixmap2.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//               }else{
//                   fitpixmap = pixmap.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
//               }


//        l1->setPixmap(fitpixmap);    //加载图片
//        l1->setScaledContents(true);
//        l1->setAlignment(Qt::AlignCenter);      //设置居中
//        tbv->setIndexWidget(model->index(i,0),l1);     //显示

//        //设置按钮的自定义属性
//        button->setProperty("tb_ISBN",model->index(i,4,QModelIndex()).data().toString());
//        connect(button,&QPushButton::clicked,this,&BookList::on_TableBtn_clicked);
//        //将按钮加入表格中
//        tbv->setIndexWidget(model->index(i,6),button);


//    }
//}
/*
 * @author yuan
设置stackwidget的指针，便于控制页面返回操作
*/
void BookList::setStackWidget(MainWidget *p){
    this->psw = p;
}
void BookList::setIcons(){
    QPixmap pixmap(":/image/querybook/back.png");
    QPixmap fitpixmap = pixmap.scaled(35, 35, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->btn_back->setIcon(QIcon(fitpixmap));
    ui->btn_back->setIconSize(QSize(35, 35));
    ui->btn_back->setFlat(true);
}
void BookList::on_TableBtn_clicked()
{
    //先获取信号的发送者
    QPushButton *button = (QPushButton*)sender();
    //提取按钮的自定义属性 数据类型须统一
    QString ISBN = button->property("tb_ISBN").toString();//根据ISBN删借阅信息
    now_utils.GetBookByIsbn(const_cast<char*>(ISBN.toStdString().c_str()),now_book);
    BookDetails *bookDetails= new BookDetails();
    bookDetails->resize(1300,730);
    bookDetails->move(0,170);
    bookDetails->setStackWidget(psw);
    bookDetails->setPreIndex(1);//用于返回前面调用的界面
    psw->insertWidget(2,bookDetails);
    psw->setCurrentIndex(2);

//    int Password = button->property("S_Password").toInt();
    //删除数据再重新调用

}

void BookList::on_btn_back_clicked()
{
   psw->setCurrentIndex(0);
}

BookList::~BookList()
{
    delete ui;
}

void BookList::on_btn_first_clicked()
{
    tbv->verticalScrollBar()->setSliderPosition(0);
    pages="1/"+QString::number(maxPgs,10);
    le->setText(pages);
}

void BookList::on_btn_la_clicked()
{

    int maxValue = tbv->verticalScrollBar()->maximum(); // 当前SCROLLER最大显示值
    nCurScroller = tbv->verticalScrollBar()->value(); //获得当前scroller值
    int curPg=   nCurScroller%maxPgNum==0?  nCurScroller/maxPgNum+1:nCurScroller/maxPgNum+2;
    loadBooks();

    if(curPg<maxPgs)
    {
        tbv->verticalScrollBar()->setSliderPosition(maxPgNum+nCurScroller);
        pages=QString::number(curPg+1,10)+"/"+QString::number(maxPgs,10);
        le->setText(pages);
    }
    else
    {
        tbv->verticalScrollBar()->setSliderPosition(0);
        pages="1/"+QString::number(maxPgs,10);
        le->setText(pages);
    }
}



void BookList::on_btn_last_clicked()
{
     int curSumPg =  curRecord%maxPgNum==0 ? curRecord/maxPgNum:curRecord/maxPgNum+1;//滚动条总的页数
    while(curSumPg<maxPgs){
        loadInitialBooks();
         curSumPg =  curRecord%maxPgNum==0 ? curRecord/maxPgNum:curRecord/maxPgNum+1;//滚动条总的页数
    }

    int maxValue = tbv->verticalScrollBar()->maximum(); // 当前SCROLLER最大显示值
    tbv->verticalScrollBar()->setSliderPosition(maxValue);
    pages=QString::number(maxPgs,10)+"/"+QString::number(maxPgs,10);
    le->setText(pages);
}

void BookList::on_btn_fore_clicked()
{
    int maxValue = tbv->verticalScrollBar()->maximum(); // 当前SCROLLER最大显示值
    nCurScroller = tbv->verticalScrollBar()->value();
    int curPg=   nCurScroller%maxPgNum==0?  nCurScroller/maxPgNum+1:nCurScroller/maxPgNum+2;
        if(nCurScroller>0){
            tbv->verticalScrollBar()->setSliderPosition(nCurScroller-maxPgNum);
            pages=QString::number(curPg-1,10)+"/"+QString::number(maxPgs,10);
            le->setText(pages);
        }
        else{
            tbv->verticalScrollBar()->setSliderPosition(maxValue);
            pages=QString::number(maxPgs,10)+"/"+QString::number(maxPgs,10);
            le->setText(pages);
        }

}

void BookList::on_line_returnPressed()
{
     int curSumPg =  curRecord%maxPgNum==0 ? curRecord/maxPgNum:curRecord/maxPgNum+1;//滚动条总的页数
    nCurScroller = tbv->verticalScrollBar()->value();
    int curPg=   nCurScroller%maxPgNum==0?  nCurScroller/maxPgNum+1:nCurScroller/maxPgNum+2;
    pages=le->text();
    int page=pages.toInt();
    if(page>maxPgs||page<1){
        pages=QString::number(curPg,10)+'/'+QString::number(maxPgs,10);
        le->setText(pages);
        return ;
    }
    while(curSumPg<page){
        loadInitialBooks();
         curSumPg =  curRecord%maxPgNum==0 ? curRecord/maxPgNum:curRecord/maxPgNum+1;//滚动条总的页数
    }
        tbv->verticalScrollBar()->setSliderPosition((page-1)*maxPgNum);
        pages=QString::number(page,10)+'/'+QString::number(maxPgs,10);
        le->setText(pages);

}
bool BookList::loadQss(const QString &StyleSheetFile){

        /*QSS文件所在的路径*/
        QFile ofile(StyleSheetFile);
        bool Ret = ofile.open(QFile::ReadOnly);

        if (!Ret)
        {
             QMessageBox::information(this,"Tip_booklist",ofile.errorString());
             return false;
        }

        this->setStyleSheet(ofile.readAll());
        ofile.close();

}
