#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include "widget.h"
#include "mainwindow.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include <string>
#include "../backend/Utils.h"
#include "../backend/MD5.h"
#include "../backend/User.h"
#include <QDir>
#include <QString>
namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
//    void getinfo();

private slots:
    void on_btn_register_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
