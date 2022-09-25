#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <widget.h>
#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    bool loadQss(const QString &StyleSheetFile);
    ~MainWindow();
    //重写paintEvent
   // Widget *login =NULL;
    void paintEvent(QPaintEvent *);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
