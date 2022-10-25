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
#include"backend/MD5.h"

bool addAdminFlag=false;
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

//    BookClass b;
//    b.setClassNo(100);
//    b.setName("未知");
//    now_utils.InsertClass(b);

//    User u;
//    u.setAccount("00002222");
//    MD5 md5;
//    string tt=md5.read("123456aA");
//    u.setPassword(tt.c_str());
//    u.setDepartmentNo(-1);
//    now_utils.Register(u);

//    Book b;
//    now_utils.GetBookByIsbn(" ",b);
//    qDebug()<<b.getClassNo();
//    User u;
//    now_utils.GetUserByAccount("00001111",u);
//    u.setEmail("801231265@qq.com");
//    User t;
//    t.setAccount(u.getAccount());
//    now_utils.UpdateUser(t,u);

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

    now_utils.GetBookRank(result);
    now_utils.GetBoyRank(result_boy);
    now_utils.GetGirlRank(result_girl);
    now_utils.GetPointRank(result_point);
    //qDebug()<< result_boy.size();
    Widget w;
    w.show();

    return app.exec();

}
