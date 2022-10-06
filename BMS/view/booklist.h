#ifndef BOOKLIST_H
#define BOOKLIST_H

#include <QWidget>
#include "MainWidget.h"
namespace Ui {
class BookList ;
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
    int nCurScroller = 0; //翻页时的当时滑动条位置
    int pageValue = 3; // 一页显示条数
    int n=29;//图书记录条数
    int maxpages;//最大页数
    QString pages;//显示当前页

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
