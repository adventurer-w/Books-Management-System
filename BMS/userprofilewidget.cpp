#include "userprofilewidget.h"
#include "ui_userprofilewidget.h"
#include "QPainter"
#include "QDebug"
#include "QFrame"
#include <QGraphicsDropShadowEffect>
#include <QColor>
#include <QFile>
#include <QMessageBox>
#include"QFontDialog"
#include "searchlineedit.h"
UserProfileWidget::UserProfileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserProfileWidget)
{
    ui->setupUi(this);
    //设置字体
    //ft.setPointSize(20);
    bool enable = true;
    QFont ft;//=QFontDialog::getFont(&enable,QFont("宋体",20,QFont::Bold),this,"姓名");//设置字体，STKaiti是华文楷体
    //字体大小
    ft.setPointSize(50);
    ft.setFamily("宋体");
    //设置文字大小为50像素
    ft.setPixelSize(50);

    //设置搜索按钮
    SearchLineEdit *sle = new SearchLineEdit;
    sle->setParent(this);
    sle->move(650,300);
    sle->resize(470,40);

    this->loadQss(":/qss/userprofilewidget/userprofile.qss");
    QPalette label_pe;
    //字体颜色
      //label_pe.setColor(QPalette::WindowText, Qt::white);
       //ui->lb_username->setPalette(label_pe);
        ui->lb_username->setText("姓名");
            ui->lb_username->setFont(ft);


       ui->lb_major->setText("专业");
       ui->lb_major_txt->setText("计算机科学与技术");
       ui->lb_number->setText("学号");
       ui->lb_number_txt->setText("123456789");
       ui->lb_sex->setText("姓别");
       ui->lb_sex_txt->setText("男");
       ui->lb_credit->setText("信誉分");
       ui->lb_credit_txt->setText("100");

   //设置阴影
   this->setStyleSheet("background-color: rgb(255, 255, 255);");
       ui->fm_personal_infor->setStyleSheet("background-color: rgb(0, 0, 0);");
       ui->fm_personal_infor->setStyleSheet("border-radius:8px;");
       ui->fm_book->setStyleSheet("background-color: rgb(0, 0, 0);");
       ui->fm_book->setStyleSheet("border-radius:8px;");
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
       ui->fm_personal_infor->setGraphicsEffect(shadow_effect);
       ui->fm_book->setGraphicsEffect(shadow_effect1);

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
bool UserProfileWidget::loadQss(const QString &StyleSheetFile){

        /*QSS文件所在的路径*/
        QFile ofile(StyleSheetFile);
        bool Ret = ofile.open(QFile::ReadOnly);

        if (!Ret)
        {
             QMessageBox::information(this,"Tip",ofile.errorString());
             return false;
        }

        this->setStyleSheet(ofile.readAll());
        ofile.close();

}
