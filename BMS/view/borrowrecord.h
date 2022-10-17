#ifndef BORROWRECORD_H
#define BORROWRECORD_H

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
class BorrowRecord;
}

class BorrowRecord : public QWidget
{
    Q_OBJECT

public:
    explicit BorrowRecord(QWidget *parent = nullptr);
    ~BorrowRecord();
    StdItemModel *model;
    void loadRecords();
    void on_btn_delete_clicked();
   bool loadQss(const QString &StyleSheetFile);
private slots:
    void on_btn_borrowInstruction_clicked();

    void on_line_search_returnPressed();

    void on_btn_search_clicked();

private:
    Ui::BorrowRecord *ui;
};

#endif // BORROWRECORD_H
