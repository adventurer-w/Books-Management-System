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

User now_user;
Utils now_utils(baseDbPath);
Book now_book;
vector<Book> re;
QString classify;//搜索图书按分类

int main(int argc, char *argv[])
{
//    for(int i=0;i<1;i++){
//        insert();
//    }
//    Record re;
//    for(int i=0;i<1;i++){
//        re.setId(i);
//        re.setDate("20220327");
//        re.setIsbn("3211");
//        re.setAccount("123");
//        re.setBookName("羊了个羊");
//        re.setAuthor("余华");
//        re.setPublisher("清华大学出版社");
//        now_utils.InsertRecord(re);
//    }


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
    Widget w;
    w.show();
  //  QApplication a(argc, argv);
    //MainWindow ww;
    //ww.show();
    return app.exec();

}
