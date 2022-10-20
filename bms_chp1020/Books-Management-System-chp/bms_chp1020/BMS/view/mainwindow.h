#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "widget.h"
#include <QMainWindow>
#include <QString>
#include <QStackedWidget>
#include "MainWidget.h"
#include <QPushButton>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool loadQss(const QString &StyleSheetFile);
    void loadMenuBar();
    void loadPages(int mode);
    ~MainWindow();
    //重写paintEvent
   // Widget *login =NULL;
    void paintEvent(QPaintEvent *);
private slots:
    void menuBarBtnClicked();
    void loadUserInfo();
    void changePage(int index);


private:
    Ui::MainWindow *ui;
    MainWidget *mw;
    QPushButton *btn;
    QList<QPushButton*> btnList;//动态创建按钮的列表
    int userType;//0为管理员，1为 普通用户
};
#endif // MAINWINDOW_H
