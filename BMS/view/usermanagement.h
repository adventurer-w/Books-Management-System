#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <QWidget>
#include "booklist.h"
#include "ui_booklist.h"
#include <QTableView>
#include <QPushButton>
#include<QLabel>
#include"QAbstractScrollArea"
#include<QScrollBar>//滑动条
#include <QFile>
#include <QMessageBox>
#include "MainWidget.h"
#include "bookdetails.h"
#include "querybookwidget.h"
#include "backend/all_head.h"
#include "backend/Utils.h"
#include <QDebug>
#include "GlobalSetting.h"
#include "stditemmodel.h"
#include "borrowinstruction.h"
namespace Ui {
class UserManagement;
}

class UserManagement : public QWidget
{
    Q_OBJECT

public:
    explicit UserManagement(QWidget *parent = nullptr);
    ~UserManagement();
    StdItemModel *model;
    StdItemModel *usersmodel;
    void printRecords(QString account,vector<Record> &record);
    void on_btn_delete_clicked();
   bool loadQss(const QString &StyleSheetFile);
   void paintEvent(QPaintEvent *);
   void loadUsers();
   void deleteUser();
private slots:
    void on_btn_borrowInstruction_clicked();

    void on_line_search_returnPressed();

    void on_btn_search_clicked();

    void on_btn_adduser_clicked();

private:
    Ui::UserManagement *ui;
    int curRecordIndex;
};

#endif // UserManagement_H
