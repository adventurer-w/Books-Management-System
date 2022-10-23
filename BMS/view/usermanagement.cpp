#include "usermanagement.h"
#include "ui_usermanagement.h"
#include "backend/Utils.h"
#include "admininfo.h"
#include <QPainter>
#include <QDateTime>
#include <backend/addUsers.h>
extern Utils now_utils;

UserManagement::UserManagement(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManagement)
{
    ui->setupUi(this);

    curRecordIndex = 0;
    model = new StdItemModel();

    model->setColumnCount(7); //设置有7列
    model->setHeaderData(0,Qt::Horizontal,"账号");  //设置第一列的表头为类型
    model->setHeaderData(1,Qt::Horizontal,"书名");  //设置第一列的表头为名称
    model->setHeaderData(2,Qt::Horizontal,"作者");
    model->setHeaderData(3,Qt::Horizontal,"借书日期");
    model->setHeaderData(4,Qt::Horizontal,"ISBN");
    model->setHeaderData(5,Qt::Horizontal,"状态");
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
    ui->tb->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//所有列都扩展自适应宽度，填充充满整个屏幕宽度

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

    //隐藏行头
    ui->tb_user->verticalHeader()->hide();
    //设置表格选中时为整行选中
    ui->tb_user->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置表格的单元为只读属性，即不能编辑
    ui->tb_user->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置单选
    ui->tb_user->setSelectionMode(QAbstractItemView::SingleSelection);
    //设置多选
    ui->tb_user->setSelectionMode(QAbstractItemView::MultiSelection);

    loadUsers();
    loadQss(":/qss/usermanagement/usermanagement.qss");
}

UserManagement::~UserManagement()
{
    delete ui;
}

/*
 * @author yuan
 * 根据用户账户输出 每个用户所有 record信息*/
void UserManagement::printRecords(QString account,vector<Record> &record){


    for(int i=0 ;i<record.size();i++){

        //基本信息计算
        QString str=record[i].getDate();
        QDateTime borrow_time = QDateTime::fromString(str, "yyyy-MM-dd hh:mm:ss");
        QDateTime now_time = QDateTime::currentDateTime();
        qint64 time=borrow_time.secsTo(now_time);

        //插入各种表项

        model->setItem(i+curRecordIndex, 0, new QStandardItem(account));
        model->setItem(i+curRecordIndex, 1, new QStandardItem(record[i].getBookName()));
        model->setItem(i+curRecordIndex, 2, new QStandardItem(record[i].getAuthor()));
        model->setItem(i+curRecordIndex, 3, new QStandardItem(record[i].getDate()));
        model->setItem(i+curRecordIndex, 4, new QStandardItem(record[i].getIsbn()));

        vector<Record> re_history;
        now_utils.GetUserBorrowHistory(const_cast<char*>(account.toStdString().c_str()),re_history);
        bool is_revert = false;
        for(int i = 0; i < re_history.size(); i++)
            if(re_history[i].getIsbn() == record[i].getIsbn())is_revert = true;
        
        if(is_revert)
            model->setItem(i+curRecordIndex, 5, new QStandardItem("已归还"));
        else
            if(time>=60*24*60*60)
                model->setItem(i+curRecordIndex, 5, new QStandardItem("逾期"));
            else
                model->setItem(i+curRecordIndex, 5, new QStandardItem("借阅"));

        ui->tb->setRowHeight(i+curRecordIndex,50);
        //往表格中添加按钮控件
        QPushButton *button = new QPushButton("删除");
        button->setStyleSheet("color:#000000;\
                              font-size:18px;\
                              font-family:KaiTi;\
                              font-weight:normal;");
        button->setProperty("account",const_cast<char*>(account.toStdString().c_str()));
        button->setProperty("isbn",record[i].getIsbn());

        ui->tb->setIndexWidget(model->index(i+curRecordIndex,6),button);
        connect(button, &QPushButton::clicked, this, &UserManagement::on_btn_delete_clicked);
    }
    curRecordIndex+=record.size();
}
void UserManagement::loadUsers(){

    vector<User> users;
    for(int i = 0; i < 4; i++)
    {
        now_utils.GetUserByDepartmentNo(i,users);
    }

    usersmodel = new StdItemModel();
    usersmodel->clear();
    usersmodel->setColumnCount(3); //设置有3列
    usersmodel->setHeaderData(0,Qt::Horizontal,"账号");  //设置第一列的表头为类型
    usersmodel->setHeaderData(1,Qt::Horizontal,"姓名");  //设置第一列的表头为名称
    usersmodel->setHeaderData(2,Qt::Horizontal,"操作");  //删除/冻结用户

    ui->tb_user->setModel(usersmodel);

    ui->tb_user->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//所有列都扩展自适应宽度，填充充满整个屏幕宽度

    ui->tb_user->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);//对第0列单独设置固定宽度


    //设置列宽
    ui->tb_user->setColumnWidth(0,120);			//参数：列号，宽度
    usersmodel->setRowCount(users.size());
    for(int i=0; i< users.size();++i){




        usersmodel->setData(usersmodel->index(i, 0), users[i].getAccount());
        usersmodel->setData(usersmodel->index(i, 1), users[i].getName());

        QPushButton *button = new QPushButton("删除");
        button->setStyleSheet("color:#000000;\
                              font-size:18px;\
                              font-family:KaiTi;\
                              font-weight:normal;");
        button->setProperty("account",users[i].getAccount());

        ui->tb_user->setIndexWidget(usersmodel->index(i,2),button);
        connect(button, &QPushButton::clicked, this, &UserManagement::deleteUser);
    }


}
void UserManagement::deleteUser(){
    QPushButton *button = (QPushButton *)sender();

    //提取按钮的自定义属性
    QString account = button->property("account").toString(); //根据用户账号删借阅信息

    User u;
    now_utils.GetUserByAccount((char *)account.toStdString().c_str(),u);

    if(now_utils.DeleteUser(u)){
        int row = ui->tb_user->currentIndex().row();
        usersmodel->removeRow(row);
    }
}
void UserManagement::on_btn_adduser_clicked(){
    insert();
    loadUsers();
}
void UserManagement::on_btn_delete_clicked(){
    //删除记录
    QPushButton *button = (QPushButton *)sender();

    //提取按钮的自定义属性
    QString account = button->property("account").toString(); //根据用户账号删借阅信息
    QString isbn = button->property("isbn").toString(); //根据ISBN删借阅信息

    //获取相应的借阅记录
    Record re0;
    now_utils.GetRecord(const_cast<char *>(account.toStdString().c_str()),const_cast<char *>(isbn.toStdString().c_str()),re0);

    vector<Record> re_history;
    now_utils.GetUserBorrowHistory(const_cast<char *>(account.toStdString().c_str()),re_history);
    bool is_revert = false;
    for(int i = 0; i < re_history.size(); i++)
        if(re_history[i].getIsbn() == const_cast<char *>(isbn.toStdString().c_str()))is_revert = true;

    //删除记录
    if(now_utils.DeleteRecord(re0)){
        int row = ui->tb->currentIndex().row();
        model->removeRow(row);
        if(!is_revert)
            now_utils.Return(const_cast<char *>(account.toStdString().c_str()),const_cast<char *>(isbn.toStdString().c_str()));
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
    //qDebug()<< val << "yes";
    vector<Record> record;
    curRecordIndex=0;//当前记录索引清零
    if(val == "")
    {
        //获取所有用户
        vector<User> result;
        for(int i = 0; i < 4; i++)
        {
            now_utils.GetUserByDepartmentNo(i,result);
        }
        //输出所有用户的借阅记录
        for(int i = 0; i< result.size(); i++)
        {
            now_utils.GetUserBorrowList(result[i].getAccount(),record);
            if(record.size() > 0)printRecords(QString(QLatin1String(result[i].getAccount())),record);
            record.clear();
        }

    }else{
        now_utils.GetUserBorrowList(const_cast<char*>(val.toStdString().c_str()),record);
        printRecords(val,record);
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
