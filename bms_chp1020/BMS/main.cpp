#include "view/widget.h"
#include "view/mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include "backend/User.h"
#include "backend/Utils.h"
#include <string>
#include <QDir>
#include <QDebug>
#include <view/GlobalSetting.h>
#include "backend/addUsers.h"
#include "backend/addBooks.h"
#include "backend/MD5.h"

User now_user;
Utils now_utils(baseDbPath);
Book now_book;
vector<Book> re;
QString classify;//搜索图书按分类
vector<Book> result;
vector<Book> result_boy;
vector<Book> result_girl;
vector<Book> result_point;
int main(int argc, char *argv[])
{

//    string classification[25]={"爱情","传记","创业","科幻","管理","历史","绘本","互联网","经济","金融","漫画","奇幻","散文","商业","社会","生活","摄影","诗词","随笔","推理","武侠","小说","心理","政治","哲学"};
//    string wenjian[25]={"aiqing","biography","chuangye","fiction","guanli","history","huiben","internet","jingji","jinrong","manhua","qihuan","sanwen","shangye","shehui","shenghuo","sheying","shici","suibi","tuili","wuxia","xiaoshuo","xinli","zhengzhi","zhexue"};
//    for(int i=0;i<25;i++){
//        qDebug()<<i<<" is runnnig";
//        addBooks(wenjian[i],classification[i]);
//    }

//        string department[4]={"本科","硕士","博士","教职工"};
//        for(int i=0;i<4;i++){
//            Department d;
//            d.setName(const_cast<char*>(department[i].c_str()));
//            d.setDepartmentNo(i);
//            d.setMaxBook((i+1)*5);
//            now_utils.InsertDepartment(d);
//        }


    QApplication app(argc, argv);

    QFile file(":/qss/base.qss");/*baseQSS文件所在的路径*/

    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    app.setStyleSheet(stylesheet);
    file.close();

    QFile file2(":/qss/login/style-1.qss");/*QSS文件所在的路径*/

    file2.open(QFile::ReadOnly);
    QTextStream filetext2(&file2);
    QString stylesheet2 = filetext2.readAll();
    app.setStyleSheet(stylesheet2);
    file2.close();


//        if(now_utils.UpdateBookRank())
//            qDebug()<<"总借阅榜单update成功！";
//        if(now_utils.UpdateGirlRank())
//            qDebug()<<"女生借阅排行榜update成功！";
//        if(now_utils.UpdateBoyRank())
//            qDebug()<<"男生借阅排行榜update成功！";

//        if(now_utils.UpdatePointRank())
//            qDebug()<<"高分借阅排行榜update成功！";
    now_utils.GetBookRank(result);
    now_utils.GetBoyRank(result_boy);
    now_utils.GetGirlRank(result_girl);
    now_utils.GetPointRank(result_point);

    Widget w;
    w.show();
  //  QApplication a(argc, argv);
    //MainWindow ww;
    //ww.show();
    return app.exec();

}
