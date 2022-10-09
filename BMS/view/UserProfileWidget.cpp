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

    ui->lb_username->setText("姓名");
    ui->lb_username_txt->setText(QString::fromStdString(now_user.getName()));
    ui->lb_major_txt->setText(QString::fromStdString(now_user.getMajor()));
    ui->lb_number_txt->setText(QString::fromStdString(now_user.getAccount()));
    if(now_user.getSex()==1)
        ui->lb_sex_txt->setText("男");
    else if(now_user.getSex()==2)
        ui->lb_sex_txt->setText("女");
    else
        ui->lb_sex_txt->setText("未知");
    ui->lb_credit_txt->setText(QString::number(now_user.getDebet()));
    setShadow();
    showBorrow();
    connect(sle,SIGNAL(keySignal(QString)),this,SLOT(searchBooks(QString)));
    this->loadQss(":/qss/userprofilewidget/userprofile.qss");
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
    this->setStyleSheet("background-color: rgb(255, 255, 255);");
   ui->fm_personal_infor->setStyleSheet("background-color: rgb(0, 0, 0);");
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
   //设置具体阴影
   QGraphicsDropShadowEffect *shadow_effect1 = new QGraphicsDropShadowEffect(this);
   shadow_effect1->setOffset(0, 0);
   //阴影颜色
   shadow_effect1->setColor(QColor(38, 78, 119, 127));
   //阴影半径
   shadow_effect1->setBlurRadius(22);

   QGraphicsDropShadowEffect *shadow_effect2 = new QGraphicsDropShadowEffect(this);
   shadow_effect2->setOffset(0, 0);
   //阴影颜色
   shadow_effect2->setColor(QColor(38, 78, 119, 127));
   //阴影半径
   shadow_effect2->setBlurRadius(22);

   ui->fm_personal_infor->setGraphicsEffect(shadow_effect);
   ui->tbv_borrow->setGraphicsEffect(shadow_effect1);
   //ui->scroll_borrow->setGraphicsEffect(shadow_effect2);

}
void UserProfileWidget::searchBooks(QString key){
    qDebug() << "ok:" << key ;

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
//    int n=50;//借阅书数量
    qDebug()<<record.size();
    for(int i=0;i<record.size();i++){
        model->setItem(i, 0, new QStandardItem(record[i].getBookName()));
        model->setItem(i, 1, new QStandardItem(record[i].getAuthor()));
        model->setItem(i, 2, new QStandardItem(record[i].getPublisher()));
        model->setItem(i, 3, new QStandardItem(record[i].getIsbn()));
        model->setItem(i, 4, new QStandardItem(record[i].getDate()));
        ui->tbv_borrow->setRowHeight(i,50);
        //往表格中添加按钮控件
        QPushButton *button = new QPushButton("还书");

         //QPushButton *button1 = new QPushButton("还书");
        //设置按钮的自定义属性
        button->setProperty("tb_ISBN",model->index(i,3,QModelIndex()).data().toString());
    //    button->setProperty("S_Password",model->index(0,1,QModelIndex()).data().toInt());//还可以定义返回其他列
        //为按钮点击信号绑定响应槽函数
        connect(button, SIGNAL(clicked(bool)), this, SLOT(onTableBtnClicked()));
       // connect(button1, SIGNAL(clicked(bool)), this, SLOT(onTableBtnClicked()));
        //将按钮加入表格中
        ui->tbv_borrow->setIndexWidget(model->index(i,5),button);
        //ui->tbv_borrow->setIndexWidget(model->index(model->rowCount()-1,5),button);//rowCount()-1是最后行号，从0行开始
    }
     ui->tbv_borrow->setShowGrid(false);
}
void UserProfileWidget::onTableBtnClicked()
{
    //先获取信号的发送者
    QPushButton *button = (QPushButton*)sender();
    //提取按钮的自定义属性 数据类型须统一
    QString ISBN = button->property("tb_ISBN").toString();//根据ISBN删借阅信息
    now_utils.Return(now_user.getAccount(), const_cast<char*>(ISBN.toStdString().c_str()));
//    int Password = button->property("S_Password").toInt();
    //删除数据再重新调用
    QMessageBox::information(this,"还书信息","恭喜你，还书成功！");

    showBorrow();
}

//scollarea版本
//输出后端借阅书，改settex函数的内容book[i]->setText("book");
//void UserProfileWidget::showBorrow(){
//    int i=0,n=100;//借阅书数量
//    QLabel *book[1000];//容量200本书
//    QVBoxLayout *vlayout = new QVBoxLayout();
//    QWidget * pWgt = new QWidget(ui->scroll_borrow);
//    //QLabel *pLabel = new QLabel(ui->scroll_borrow);
//   // ui->scroll_borrow->setAlignment(Qt::AlignCenter);
//     for(int j=1;j<=n;j++){
//         QHBoxLayout *hlayout = new QHBoxLayout();
//        for(;i<j*5;i++){

//            book[i] = new QLabel(ui->scroll_borrow);
//            book[i] -> move(30+(i%5)*180,480+j*50);
//            //book[i] -> move((i%5)*180,j*10);
//            book[i]->setText("978-7-111-");
//            hlayout->addWidget(book[i]);
//           // ui->scroll_borrow->setWidget(book[i]);
//        }
//        QPushButton * btn = new QPushButton("还书",this);
//        hlayout->addWidget(btn);
//        hlayout->setSpacing(86);
//        vlayout->addItem(hlayout);
//     }
//     //pWgt->setLayout(vlayout);
//    // ui ->scroll_borrow->setWidget(pWgt);
//}
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
