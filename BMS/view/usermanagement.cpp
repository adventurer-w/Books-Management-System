#include "usermanagement.h"
#include "ui_usermanagement.h"
#include "backend/Utils.h"
#include "admininfo.h"
#include <QPainter>
#include <QDateTime>

extern Utils now_utils;

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

//    loadRecords();
    loadQss(":/qss/usermanagement/usermanagement.qss");
}

UserManagement::~UserManagement()
{
    delete ui;
}

void UserManagement::loadRecords(){

}
void UserManagement::on_btn_delete_clicked(){
    //删除记录
    QPushButton *button = (QPushButton *)sender();

    //提取按钮的自定义属性
    QString account = button->property("account").toString(); //根据用户账号删借阅信息
    QString isbn = button->property("isbn").toString(); //根据ISBN删借阅信息

    //获取响应的借阅记录
    Record re0;
    now_utils.GetRecord(const_cast<char *>(account.toStdString().c_str()),const_cast<char *>(isbn.toStdString().c_str()),re0);

    //删除记录
    if(now_utils.DeleteRecord(re0)){
        int row = ui->tb->currentIndex().row();
        model->removeRow(row);
    }
}

void UserManagement::on_btn_borrowInstruction_clicked()
{
    BorrowInstruction *instruction = new BorrowInstruction();
    instruction->show();
}

void UserManagement::on_line_search_returnPressed()
{
    //搜索框回车，逻辑和搜索按钮一样
    on_btn_search_clicked();
}

void UserManagement::on_btn_search_clicked()
{
    //点击搜索按钮
    QString val=ui->line_search->text();
    qDebug()<< val << "yes";
    vector<Record> record;
    if(val == "")
    {
        //获取所有用户
        vector<User> result;
        for(int i = 0; i < 4; i++)
        {
            now_utils.GetUserByDepartmentNo(i,result);
        }
        //获取所有用户的借阅记录
        for(int i = 0; i< result.size(); i++)
        {
            now_utils.GetUserBorrowList(result[i].getAccount(),record);
        }

    }else{
        now_utils.GetUserBorrowList(const_cast<char*>(val.toStdString().c_str()),record);
    }

    //获取该用户全部借阅信息



    string info;

    for(int i=0 ;i<record.size();i++){

        //基本信息计算
        QString str=record[i].getDate();
        QDateTime borrow_time = QDateTime::fromString(str, "yyyy-MM-dd hh:mm:ss");
        QDateTime now_time = QDateTime::currentDateTime();
        qint64 time=borrow_time.secsTo(now_time);

        //插入各种表项
        model->setItem(i, 0, new QStandardItem(val));
        model->setItem(i, 1, new QStandardItem(record[i].getBookName()));
        model->setItem(i, 2, new QStandardItem(record[i].getAuthor()));
        model->setItem(i, 3, new QStandardItem(record[i].getDate()));
        model->setItem(i, 4, new QStandardItem(record[i].getIsbn()));
        if(time>=60*24*60*60)
            model->setItem(i, 5, new QStandardItem("是"));
        else
            model->setItem(i, 5, new QStandardItem("否"));

        ui->tb->setRowHeight(i,50);
        //往表格中添加按钮控件
        QPushButton *button = new QPushButton("删除");
        button->setStyleSheet("color:#000000;\
                              font-size:18px;\
                              font-family:KaiTi;\
                              font-weight:normal;");
        button->setProperty("account",const_cast<char*>(val.toStdString().c_str()));
        button->setProperty("isbn",record[i].getIsbn());

        ui->tb->setIndexWidget(model->index(i,6),button);
        connect(button, &QPushButton::clicked, this, &UserManagement::on_btn_delete_clicked);
    }
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
