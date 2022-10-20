#include "usermanagement.h"
#include "ui_usermanagement.h"
#include <QPainter>
UserManagement::UserManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManagement)
{
    ui->setupUi(this);
    model = new StdItemModel();

    model->setColumnCount(7); //设置有7列
    model->setHeaderData(0,Qt::Horizontal,"账号");  //设置第一列的表头为类型
    model->setHeaderData(1,Qt::Horizontal,"书名");  //设置第一列的表头为名称
    model->setHeaderData(2,Qt::Horizontal,"作者");
    model->setHeaderData(3,Qt::Horizontal,"借书日期");
    model->setHeaderData(4,Qt::Horizontal,"ISBN");
    model->setHeaderData(5,Qt::Horizontal,"逾期");
    model->setHeaderData(6,Qt::Horizontal,"删除");

    ui->tb->setModel(model);
    //设置列宽
    ui->tb->setColumnWidth(0,160);			//参数：列号，宽度
    ui->tb->setColumnWidth(1,180);
    ui->tb->setColumnWidth(2,170);
    ui->tb->setColumnWidth(3,230);
    ui->tb->setColumnWidth(4,230);
    ui->tb->setColumnWidth(5,140);
    ui->tb->setColumnWidth(6,140);


    /*后续这里根据数量来动态设置列表框的高*/
    ui->tb->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->tbv_borrow->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    //ui->tb->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    //横向填满，下面设置列宽没用了
    //ui->tb->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//布局排版是全部伸展开的效果

    loadRecords();
    loadQss(":/qss/usermanagement/usermanagement.qss");
}

UserManagement::~UserManagement()
{
    delete ui;
}

void UserManagement::loadRecords(){

    for(int i=0;i<10;i++){
        QPushButton *btn_delete = new QPushButton("删除");


        //设置按钮的自定义属性
        //btn_delete->setProperty("tb_ISBN",model->index(i,4,QModelIndex()).data().toString());
         connect(btn_delete,&QPushButton::clicked,this,&UserManagement::on_btn_delete_clicked);
        //将按钮加入表格中
        ui->tb->setIndexWidget(model->index(i,6),btn_delete);

    }
}
void UserManagement::on_btn_delete_clicked(){
    //删除记录

}

void UserManagement::on_btn_borrowInstruction_clicked()
{
    BorrowInstruction *instruction = new BorrowInstruction();
    instruction->show();
}

void UserManagement::on_line_search_returnPressed()
{
    //搜索框回车，逻辑和搜索按钮一样
}

void UserManagement::on_btn_search_clicked()
{
    //点击搜索按钮
}
void UserManagement::paintEvent(QPaintEvent *)
{
    //需要Qpainter头文件
    QPainter painter(this); //初始化
    QPixmap pix;
    //背景图
    pix.load(":/image/usermanagement/background.jpg");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}
bool UserManagement::loadQss(const QString &StyleSheetFile){

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
