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

//#include<Qpagi
BookList::BookList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookList )
{
    ui->setupUi(this);
    StdItemModel *model = new StdItemModel();

    model->setColumnCount(6); //设置有6列
    model->setHeaderData(0,Qt::Horizontal,"封面");  //设置第一列的表头为类型
    model->setHeaderData(1,Qt::Horizontal,"书名");  //设置第一列的表头为名称
    model->setHeaderData(2,Qt::Horizontal,"作者");
    model->setHeaderData(3,Qt::Horizontal,"出版社");
    model->setHeaderData(4,Qt::Horizontal,"ISBN");
    model->setHeaderData(5,Qt::Horizontal,"详情");

    ui->tb->setModel(model);
    /*后续这里根据数量来动态设置列表框的高*/
    ui->tb->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->tbv_borrow->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    //ui->tb->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    //横向填满，下面设置列宽没用了
    //ui->tb->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//布局排版是全部伸展开的效果

    //设置列宽
    ui->tb->setColumnWidth(0,120);			//参数：列号，宽度
    ui->tb->setColumnWidth(1,230);
    ui->tb->setColumnWidth(2,230);
    ui->tb->setColumnWidth(3,230);
    ui->tb->setColumnWidth(4,260);
    ui->tb->setColumnWidth(5,230);
    //设置行高
  //  ui->tb->verticalHeader()->setDefaultSectionSize(250);

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

    //往表格中添加数据 连接后端把下面加入for循环
    n=29;//借阅书数量
    for(int i=0;i<29;i++){
        model->setItem(i, 1, new QStandardItem("三体：纪念版"));
        model->setItem(i, 2, new QStandardItem("刘慈欣"));
        model->setItem(i, 3, new QStandardItem("重庆出版社"));
        model->setItem(i, 4, new QStandardItem("987-1-23455-2"));
        ui->tb->setRowHeight(i,150);
        //往表格中添加按钮控件
        QPushButton *button = new QPushButton("详情");

//        QTablev *btItem = new QTableWidgetItem();   //靶体
//          btItem->setTextAlignment(Qt::AlignCenter);    //文字居中
//          btItem->setIcon(QIcon(":/image/蓝旗.png"));
//           btItem->setText("红旗飘飘");
//           ui->tableWidget->setItem(0,5,btItem);


        QLabel *l1 = new QLabel();     //创建lable
       // l1->resize(50,100);
        l1-> setFixedSize (120,150);
        QPixmap pixmap(":/image/querybook/live.jpg");
        QPixmap fitpixmap = pixmap.scaled(120, 150, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);


        l1->setPixmap(fitpixmap);    //加载图片
        l1->setScaledContents(true);
        l1->setAlignment(Qt::AlignCenter);      //设置居中
        ui->tb->setIndexWidget(model->index(i,0),l1);     //显示

        //button->resize(30,30);
        //button-> setFixedSize (100,30);
        //设置按钮的自定义属性
        button->setProperty("tb_ISBN",model->index(i,4,QModelIndex()).data().toString());
    //    button->setProperty("S_Password",model->index(0,1,QModelIndex()).data().toInt());//还可以定义返回其他列
        //为按钮点击信号绑定响应槽函数
        //connect(button, SIGNAL(clicked(bool)), this, SLOT(on_TableBtn_clicked()));
         connect(button,&QPushButton::clicked,this,&BookList::on_TableBtn_clicked);
       // connect(button1, SIGNAL(clicked(bool)), this, SLOT(onTableBtnClicked()));
        //将按钮加入表格中
        ui->tb->setIndexWidget(model->index(i,5),button);
        //ui->tbv_borrow->setIndexWidget(model->index(model->rowCount()-1,5),button);//rowCount()-1是最后行号，从0行开始
        ui->tb->resizeRowsToContents();

    }

    setIcons();
    maxpages=n%pageValue==0? n/pageValue : n/pageValue+1;
    pages="1/"+QString::number(maxpages,10);
    ui->line->setText(pages);

    ui->tb->setShowGrid(false);
    loadQss(":/qss/booklist/booklist.qss");
}
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
    BookDetails *bookDetails= new BookDetails();
    bookDetails->resize(1300,730);
    bookDetails->setStackWidget(psw);
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
    ui->tb->verticalScrollBar()->setSliderPosition(0);
    pages="1/"+QString::number(maxpages,10);
    ui->line->setText(pages);
}

void BookList::on_btn_la_clicked()
{

    int maxValue = ui->tb->verticalScrollBar()->maximum(); // 当前SCROLLER最大显示值
    nCurScroller = ui->tb->verticalScrollBar()->value(); //获得当前scroller值
    int currentpage=   nCurScroller%pageValue==0?  nCurScroller/pageValue+1:nCurScroller/pageValue+2;
    if(nCurScroller<maxValue)
    {
        ui->tb->verticalScrollBar()->setSliderPosition(pageValue+nCurScroller);
        pages=QString::number(currentpage+1,10)+"/"+QString::number(maxpages,10);
        ui->line->setText(pages);
    }
    else
    {
        ui->tb->verticalScrollBar()->setSliderPosition(0);
        pages="1/"+QString::number(maxpages,10);
        ui->line->setText(pages);
    }
}



void BookList::on_btn_last_clicked()
{
    int maxValue = ui->tb->verticalScrollBar()->maximum(); // 当前SCROLLER最大显示值
    ui->tb->verticalScrollBar()->setSliderPosition(maxValue);
    pages=QString::number(maxpages,10)+"/"+QString::number(maxpages,10);
    ui->line->setText(pages);
}

void BookList::on_btn_fore_clicked()
{
    int maxValue = ui->tb->verticalScrollBar()->maximum(); // 当前SCROLLER最大显示值
    nCurScroller = ui->tb->verticalScrollBar()->value();
    int currentpage=   nCurScroller%pageValue==0?  nCurScroller/pageValue+1:nCurScroller/pageValue+2;
        if(nCurScroller>0){
            ui->tb->verticalScrollBar()->setSliderPosition(nCurScroller-pageValue);
            pages=QString::number(currentpage-1,10)+"/"+QString::number(maxpages,10);
            ui->line->setText(pages);
        }
        else{
            ui->tb->verticalScrollBar()->setSliderPosition(maxValue);
            pages=QString::number(maxpages,10)+"/"+QString::number(maxpages,10);
            ui->line->setText(pages);
        }

}

void BookList::on_line_returnPressed()
{
    nCurScroller = ui->tb->verticalScrollBar()->value();
    int currentpage=   nCurScroller%pageValue==0?  nCurScroller/pageValue+1:nCurScroller/pageValue+2;
    pages=ui->line->text();
    int page=pages.toInt();
    if(page>maxpages||page<1){
        pages=QString::number(currentpage,10)+'/'+QString::number(maxpages,10);
        ui->line->setText(pages);
    }
    else{
        ui->tb->verticalScrollBar()->setSliderPosition((page-1)*pageValue);
        pages=QString::number(page,10)+'/'+QString::number(maxpages,10);
        ui->line->setText(pages);
    }
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
