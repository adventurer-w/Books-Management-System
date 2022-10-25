#ifndef ADMINBOOKMANAGEMENT_H
#define ADMINBOOKMANAGEMENT_H

#include <QWidget>
#include "MainWidget.h"
#include "stditemmodel.h"
#include "backend/Utils.h"

namespace Ui
{
    class AdminBookManagement;
}

class AdminBookManagement : public QWidget
{
    Q_OBJECT

public:
    explicit AdminBookManagement(QWidget *parent = nullptr);

    void load_classify();

    ~AdminBookManagement();

    void getBookList(QString classification, QString key);

    void paintEvent(QPaintEvent *);

    bool loadQss(const QString &StyleSheetFile);



    void setShadow();

    void showPopularBook();

    void loadInitialBooks();

    void new_button(QString button_text, QString picture_name, int position, Book book, int i);

    void showTableString(const QStringList table);

    void loadBooks();

    void setStackWidget(MainWidget *p);

    void setIcons();

    void on_TableModifyBtn_clicked();

    void on_remove_clicked();


    bool openExcel(const QString &filename);

    int nCurScroller = 0; //翻页时的当时滑动条位置
    int curPgNum = 1;
    int maxPgNum = 8;  // 一页显示条数
    int maxPgs;        //最大页数
    int curRecord = 0; //已经插入的记录
    QString pages;     //显示当前页
    StdItemModel *model;
    int m_row = 0;
    int m_col = 0;
    QString m_filename = "";

public:
    MainWidget *sub_mw;
signals:
    void changePageSignal(int index);
private slots:

    void on_btn_search_clicked();

    void on_btn_author_clicked();

    void on_btn_bookname_clicked();

    void on_btn_ISBN_clicked();

    void on_cbox_classify_currentIndexChanged(int);

    void on_btn_addbook_batch_clicked();

    void on_btn_first_clicked();

    void on_btn_la_clicked();

    void on_btn_last_clicked();

    void on_btn_fore_clicked();

    void on_line_search_returnPressed();

    void on_btn_addbook_clicked();

    void on_btn_addclassify_clicked();

    void on_btn_updaterank_clicked();

    void backToThis();

    void updateBookRecord(Book book);

private:
    Ui::AdminBookManagement *ui;
    QString classify; //当前选择的分类
    MainWidget *psw;  //底层stackwidget对象的指针，便于返回
};

// extern int add_or_mod;

#endif // ADMINBOOKLIST_H
