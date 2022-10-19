#ifndef BOOKLIST_H
#define BOOKLIST_H

#include <QWidget>
#include "MainWidget.h"
#include "stditemmodel.h"
namespace Ui {
class BookList;
}

class BookList : public QWidget
{
    Q_OBJECT

public:
    explicit BookList(QWidget *parent = nullptr);
    bool loadQss(const QString &StyleSheetFile);
    void setIcons();
    ~BookList();
    void on_TableBtn_clicked();
    void setStackWidget(MainWidget *p);
    void loadBooks();
    void loadInitialBooks();
    int nCurScroller = 0; //翻页时的当时滑动条位置
    int curPgNum=1;
    int maxPgNum = 4; // 一页显示条数
    int maxPgs;//最大页数
    int curRecord=0;//已经插入的记录
    QString pages;//显示当前页
    StdItemModel *model;

private slots:
    void on_btn_first_clicked();

    void on_btn_la_clicked();

    void on_btn_last_clicked();

    void on_btn_fore_clicked();

    void on_line_returnPressed();

    void on_btn_back_clicked();

private:
    Ui::BookList  *ui;
    MainWidget *psw;//底层stackwidget对象的指针，便于返回
};

#endif // BOOKLIST_H
