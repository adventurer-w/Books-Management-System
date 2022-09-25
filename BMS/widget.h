#ifndef WIDGET_H
#define WIDGET_H
#include <mainwindow.h>
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
   // MainWindow *personal_homepage=NULL;
public slots:
    void set_style();

private slots:
    void on_btn_login_clicked();

private:
    Ui::Widget *ui;
     QString user_name,uer_pwd;
};

#endif // WIDGET_H
