#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <widget.h>
#include <QMainWindow>
#include <QString>
#include <QStackedWidget>
#include <MainWidget.h>
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
    void loadPages();
    ~MainWindow();
    //重写paintEvent
   // Widget *login =NULL;
    void paintEvent(QPaintEvent *);
private slots:
    void on_btn_userProfile_clicked();
    void on_btn_modifyInfo_clicked();
    void on_btn_queryBook_clicked();

private:
    Ui::MainWindow *ui;
    MainWidget *mw;
};
#endif // MAINWINDOW_H
