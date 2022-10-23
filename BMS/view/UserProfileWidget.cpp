#include "userprofilewidget.h"
#include "ui_userprofilewidget.h"
#include<QPushButton>
#include "QPainter"
#include "QDebug"
#include "QFrame"
#include <QLabel>
#include <QLayout>
#include <QGraphicsDropShadowEffect>
#include <QColor>
#include <QFile>
#include <QMessageBox>
#include <QTableView>
#include <QStandardItem>
#include <QStandardItemModel>
#include<QScrollBar>
#include"QFontDialog"
#include "stditemmodel.h"
#include "searchlineedit.h"
#include "backend/User.h"
#include "backend/Utils.h"
#include "backend/all_head.h"
#include "querybookwidget.h"
#include <QString>
#include <QDateTime>
#include "smtp.h"
extern User now_user;
extern Utils now_utils;

UserProfileWidget::UserProfileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserProfileWidget)
{
    ui->setupUi(this);


    //设置搜索按钮
       SearchLineEdit *sle = new SearchLineEdit;
       sle->setParent(this);
       sle->move(650,300);
       sle->resize(470,40);
       //加载本页面qss

       //ui->lb_username->setText("姓名");
       ui->lb_username_txt->setText(QString::fromStdString(now_user.getName()));
       vector<Department> major_result;
       now_utils.GetDepartmentByNo(now_user.getDepartmentNo(),major_result);
       ui->lb_major_txt->setText(QString::fromStdString(major_result[0].getName())+"（上限："+QString::number(major_result[0].getMaxBook())+"本)");
       ui->lb_number_txt->setText(QString::fromStdString(now_user.getAccount()));
       if(now_user.getSex()==1)
           ui->lb_sex_txt->setText("男");
       else if(now_user.getSex()==2)
           ui->lb_sex_txt->setText("女");
       else
           ui->lb_sex_txt->setText("未知");
       setShadow();
       showBorrow();
       connect(sle,SIGNAL(keySignal(QString)),this,SLOT(searchBooks(QString)));
       loadQss(":/qss/userprofilewidget/userprofile.qss");
       this->setStyleSheet("background-color: rgb(255, 255, 255);");
       ui->btn_borrowinstruction->setStyleSheet("color:#000000;\
                                                font-size:18px;\
                                                font-family:KaiTi;\
                                                font-weight:normal;\
                                                background:transparent;");
}

UserProfileWidget::~UserProfileWidget()
{
    delete ui;
}



//放背景图
void UserProfileWidget::paintEvent(QPaintEvent *){
    //需要Qpainter头文件
    QPainter painter(this);//初始化
    QPixmap pix;
    //背景图
    pix.load(":/image/UserProfile/background.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //qDebug() << "user paint" <<endl;

    //画头像
    QPainterPath path;
     path.addEllipse(100,60,120,120);//加入一个圆形   绘图是从左上角的（56，20）坐标开始绘制的  ，120，120是绘图的宽高
     pix.load(":/image/pic/personal_homepage.jpg");
     painter.setClipPath(path);
     painter.drawPixmap(QRect(100,60,120,120),pix);

}
void UserProfileWidget::setShadow(){
    //设置阴影
   //this->setStyleSheet("background-color: rgb(255, 255, 255);");
   ui->fm_personal_infor->setStyleSheet("background-color: rgb(0,0, 0);");
   ui->fm_personal_infor->setStyleSheet("border-radius:8px;");

   ui->tbv_borrow->setStyleSheet("background-color: rgb(0, 0, 0);");
   ui->tbv_borrow->setStyleSheet("border-radius:8px;");
   //设置具体阴影
   QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
   shadow_effect->setOffset(0, 0);
   //阴影颜色
   shadow_effect->setColor(QColor(38, 78, 119, 127));
   //阴影半径
   shadow_effect->setBlurRadius(22);


   ui->fm_personal_infor->setGraphicsEffect(shadow_effect);

   //设置具体阴影
   QGraphicsDropShadowEffect *shadow_effect1 = new QGraphicsDropShadowEffect(this);
   shadow_effect1->setOffset(0, 0);
   //阴影颜色
   shadow_effect1->setColor(QColor(38, 78, 119, 127));
   //阴影半径
   shadow_effect1->setBlurRadius(22);

   ui->tbv_borrow->setGraphicsEffect(shadow_effect1);
   //ui->scroll_borrow->setGraphicsEffect(shadow_effect2);

}
void UserProfileWidget::searchBooks(QString key){
    //qDebug() << "ok:" << key ;

    QueryBookWidget *queryBookWidget = new QueryBookWidget;

    pmw->insertWidget(1,queryBookWidget);
    pmw->setCurrentIndex(1);
    queryBookWidget->loadPages();
    queryBookWidget->getBookList("全部",key);
    queryBookWidget->sub_mw->setCurrentIndex(1);



}
void UserProfileWidget::showBorrow(){
    StdItemModel *model = new StdItemModel();

    model->setColumnCount(6); //设置有6列
    model->setHeaderData(0,Qt::Horizontal,"书名");  //设置第一列的表头为类型
    model->setHeaderData(1,Qt::Horizontal,"作者");  //设置第一列的表头为名称
    model->setHeaderData(2,Qt::Horizontal,"出版社");
    model->setHeaderData(3,Qt::Horizontal,"ISBN");
    model->setHeaderData(4,Qt::Horizontal,"借阅时间");
    model->setHeaderData(5,Qt::Horizontal,"一键还书");
    ui->tbv_borrow->setModel(model);


    /*后续这里根据数量来动态设置列表框的高*/
    ui->tbv_borrow->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //ui->tbv_borrow->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    ui->tbv_borrow->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);

    //设置列宽
    ui->tbv_borrow->setColumnWidth(0,170);			//参数：列号，宽度
    ui->tbv_borrow->setColumnWidth(1,170);
    ui->tbv_borrow->setColumnWidth(2,170);
    ui->tbv_borrow->setColumnWidth(3,170);
    ui->tbv_borrow->setColumnWidth(4,170);
    ui->tbv_borrow->setColumnWidth(5,140);

    //隐藏行头
    ui->tbv_borrow->verticalHeader()->hide();
    //设置表格选中时为整行选中
    ui->tbv_borrow->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置表格的单元为只读属性，即不能编辑
    ui->tbv_borrow->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置单选
    ui->tbv_borrow->setSelectionMode(QAbstractItemView::SingleSelection);
    //设置多选
    ui->tbv_borrow->setSelectionMode(QAbstractItemView::MultiSelection);

    //往表格中添加数据 连接后端把下面加入for循环
    vector<Record> record;
    now_utils.GetUserBorrowList(now_user.getAccount(),record);
    int debet=0;
    string info;
    int i=0;
    for(;i<record.size();i++){

        QString str=record[i].getDate();
        QDateTime borrow_time = QDateTime::fromString(str, "yyyy-MM-dd hh:mm:ss");
        QDateTime now_time = QDateTime::currentDateTime();
        qint64 time=borrow_time.secsTo(now_time);
        int flag=0;
        if(time>=45*24*60*60 && time<60*24*60*60){
            //超过45天则提醒用户
            flag=1;
            int day=int((60*24*60*60-time)/(24*60*60));
            info+="《";
            info+=record[i].getBookName();
            info+="》还有";
            info+=to_string(day);
            info+="天到期!\n";
        }

        if(time>=60*24*60*60){
            //超过60天进行扣款
            flag=2;
            int day=int((time-60*24*60*60)/(24*60*60)+1);//不满一天按照一天计算
            debet+=day>=100?100:day;
            info+="《";
            info+=record[i].getBookName();
            info+="》已到期";
            info+=to_string(day);
            info+="天!\n";
        }
        if(flag==1){
            string s=record[i].getBookName();
            s+="即将到期";
            model->setItem(i, 0, new QStandardItem(s.c_str()));
        }
        else if(flag==2){
            string s=record[i].getBookName();
            s+="已逾期";
            model->setItem(i, 0, new QStandardItem(s.c_str()));
        }
        else
            model->setItem(i, 0, new QStandardItem(record[i].getBookName()));
        model->setItem(i, 1, new QStandardItem(record[i].getAuthor()));
        model->setItem(i, 2, new QStandardItem(record[i].getPublisher()));
        model->setItem(i, 3, new QStandardItem(record[i].getIsbn()));
        model->setItem(i, 4, new QStandardItem(record[i].getDate()));

        ui->tbv_borrow->setRowHeight(i,50);
        //往表格中添加按钮控件
        QPushButton *button = new QPushButton("还书");
        button->setStyleSheet("color:#000000;\
                              font-size:18px;\
                              font-family:KaiTi;\
                              font-weight:normal;");
        button->setProperty("tb_ISBN",model->index(i,3,QModelIndex()).data().toString());
        connect(button, SIGNAL(clicked(bool)), this, SLOT(onTableBtnClicked()));
        ui->tbv_borrow->setIndexWidget(model->index(i,5),button);
    }


    //预约列表
    vector<Reserve> reserve;
    now_utils.GetUserReserveList(now_user.getAccount(),reserve);
    for(int j=0;i<record.size()+reserve.size();i++,j++){
        string s=reserve[j].getBookName();
        s+="\n（预约中）";
        model->setItem(i, 0, new QStandardItem(s.c_str()));
        model->setItem(i, 1, new QStandardItem(reserve[j].getAuthor()));
        model->setItem(i, 2, new QStandardItem(reserve[j].getPublisher()));
        model->setItem(i, 3, new QStandardItem(reserve[j].getIsbn()));
        s=reserve[j].getDate();
        s+="\n(预约时间)";
        model->setItem(i, 4, new QStandardItem(s.c_str()));
        ui->tbv_borrow->setRowHeight(i,50);
        QPushButton *button = new QPushButton("取消预约");
        button->setStyleSheet("color:#000000;\
                              font-size:18px;\
                              font-family:KaiTi;\
                              font-weight:normal;");

        button->setProperty("tb_ISBN",model->index(i,3,QModelIndex()).data().toString());
        connect(button, SIGNAL(clicked(bool)), this, SLOT(reserveBtnClicked()));
        ui->tbv_borrow->setIndexWidget(model->index(i,5),button);
    }

    vector<Record> re_history;
    now_utils.GetUserBorrowHistory(now_user.getAccount(),re_history);
    for(int j=0;i<record.size()+reserve.size()+re_history.size();i++,j++){
        string s=re_history[j].getBookName();
        s+="\n（曾借阅）";
        model->setItem(i, 0, new QStandardItem(s.c_str()));
        model->setItem(i, 1, new QStandardItem(re_history[j].getAuthor()));
        model->setItem(i, 2, new QStandardItem(re_history[j].getPublisher()));
        model->setItem(i, 3, new QStandardItem(re_history[j].getIsbn()));
        s=re_history[j].getDate();
        s+="\n(曾借阅时间)";
        model->setItem(i, 4, new QStandardItem(s.c_str()));
        ui->tbv_borrow->setRowHeight(i,50);
    }
    if(debet>0){
        User t;
        t.setAccount(now_user.getAccount());
        now_user.setDebet(debet);
        now_utils.UpdateUser(t,now_user);
    }
    ui->lb_credit_txt->setText(QString::number(now_user.getDebet()));
    if(info.size()>0){
         QMessageBox::information(this,"提示信息",QString::fromStdString(info));
    }
    ui->tbv_borrow->setShowGrid(false);
}

void UserProfileWidget::onTableBtnClicked()//还书
{
    //先获取信号的发送者
    QPushButton *button = (QPushButton*)sender();
    //提取按钮的自定义属性 数据类型须统一
    QString ISBN = button->property("tb_ISBN").toString();
    bool lost_book=false;
    if(now_user.getDebet()>0){
        QMessageBox::StandardButton result=QMessageBox::question(this,"提示信息","请选择缴纳逾期罚款后还书(点击yes) 或 赔偿书籍(点击no)",QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
        //点击即可罚款
        if(result==QMessageBox::Yes){
            //缴纳逾期罚款

        }else{
            //赔偿书籍则不还书，总量减1(库存也减1，因为还书会加1，相当于不变)
            lost_book=true;
            Book bt1,bt2;
            bt1.setIsbn(const_cast<char*>(ISBN.toStdString().c_str()));
            now_utils.GetBookByIsbn(const_cast<char*>(ISBN.toStdString().c_str()),bt2);
            bt2.setAllNum(bt2.getAllNum()-1);
            bt2.setLeft(bt2.getLeft()-1);
            now_utils.UpdateBook(bt1,bt2);
        }

        Record rt;
        now_utils.GetRecord(now_user.getAccount(),const_cast<char*>(ISBN.toStdString().c_str()),rt);

        QString str=rt.getDate();
        QDateTime borrow_time = QDateTime::fromString(str, "yyyy-MM-dd hh:mm:ss");
        QDateTime now_time = QDateTime::currentDateTime();
        qint64 time=borrow_time.secsTo(now_time);
        int day=int((time-60*24*60*60)/(24*60*60)+1);
        int dt=day>=100?100:day;
        User ut;
        ut.setAccount(now_user.getAccount());
        now_user.setDebet(now_user.getDebet()-dt);
        now_utils.UpdateUser(ut,now_user);
    }

    if(now_utils.Return(now_user.getAccount(), const_cast<char*>(ISBN.toStdString().c_str()))){
        QMessageBox::information(this,"还书信息","恭喜你，还书成功！");
        User ut;
        ut.setAccount(now_user.getAccount());
        now_user.setNumBorrowed(now_user.getNumBorrowed()-1);
        now_utils.UpdateUser(ut,now_user);

        Reserve reserve;
        now_utils.GetReserveUser(const_cast<char*>(ISBN.toStdString().c_str()),reserve);
        Book bt;
        now_utils.GetBookByIsbn(const_cast<char*>(ISBN.toStdString().c_str()),bt);

        //若有人预约该书，则自动借书，并发邮件提醒
        string reserve_isbn = reserve.getIsbn();
        if(reserve_isbn.size()==13 && !lost_book){
            Record record;
            record.setIsbn(bt.getIsbn());
            QDateTime dateTime = QDateTime::currentDateTime();//获取系统当前的时间
            QString str = dateTime .toString("yyyy-MM-dd hh:mm:ss");//格式化时间
    //        QString str="2022-06-10 10:10:10";//测试时使用
            record.setDate(str.toStdString().c_str());
            record.setAuthor(bt.getAuthor());
            record.setAccount(reserve.getAccount());
            record.setBookName(bt.getBookName());
            record.setPublisher(bt.getPublisher());

            now_utils.DeleteReserve(reserve);
            now_utils.InsertRecord(record);
            User ut;
            now_utils.GetUserByAccount(reserve.getAccount(),ut);
            string email=ut.getEmail();
//            string email="805513225@qq.com";
//            string bookname=reserve.getBookName();
            string article="Your reservation has arrived at the library, please pick it up at the library as soon as possible!";
            //发邮件提醒
            CSmtp smtp(
                    25,                             /*smtp端口*/
                    "smtp.163.com",                 /*smtp服务器地址*/
                    "chenhaopeng0327@163.com",         /*你的邮箱地址*/
                    "CAVELDHPXYDOOGDK",                   /*邮箱授权码*/
                    email,  /*目的邮箱地址,这一部分用空格分割可添加多个收信人*/
                    "图书馆预约提醒",                           /*主题*/
                    article      /*邮件正文*/
                    );

                int err;
                if ((err = smtp.SendEmail_Ex()) != 0)
                {
                    if (err == 1)
                        qDebug() << "错误1: 由于网络不畅通，发送失败!" << endl;
                    if (err == 2)
                        qDebug() << "错误2: 用户名错误,请核对!" << endl;
                    if (err == 3)
                        qDebug() << "错误3: 用户密码错误，请核对!" << endl;
                    if (err == 4)
                        qDebug() << "错误4: 请检查附件目录是否正确，以及文件是否存在!" << endl;
                }

        }else{
            Book bt1;
            bt1.setIsbn(const_cast<char*>(ISBN.toStdString().c_str()));
            bt.setLeft(bt.getLeft()+1);
            now_utils.UpdateBook(bt1,bt);
        }
    }


    showBorrow();
}

void UserProfileWidget::reserveBtnClicked()
{
    //取消预约
    QPushButton *button = (QPushButton*)sender();
    QString ISBN = button->property("tb_ISBN").toString();

    Reserve reserve;
    now_utils.GetReserve(now_user.getAccount(),const_cast<char*>(ISBN.toStdString().c_str()),reserve);
    if(now_utils.DeleteReserve(reserve))
        QMessageBox::information(this,"提示信息","已取消预约！");

    showBorrow();
}
bool UserProfileWidget::loadQss(const QString &StyleSheetFile){

        /*QSS文件所在的路径*/
        QFile ofile(StyleSheetFile);
        bool Ret = ofile.open(QFile::ReadOnly);

        if (!Ret)
        {
             QMessageBox::information(this,"Tip_userprofile",ofile.errorString());
             return false;
        }

        this->setStyleSheet(ofile.readAll());
        ofile.close();

}

void UserProfileWidget::on_btn_borrowinstruction_clicked(){
    //string s=now_utils.getGuidelines();
    //QMessageBox::information(this,"借阅须知",QString::fromStdString(s));
}
