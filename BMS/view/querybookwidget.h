#ifndef QUERYBOOKWIDGET_H
#define QUERYBOOKWIDGET_H

#include <QWidget>
#include "MainWidget.h"
namespace Ui {
class QueryBookWidget;
}



class QueryBookWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QueryBookWidget(QWidget *parent = nullptr);
    ~QueryBookWidget();
    void getBookList(QString classification,QString key);
    void paintEvent(QPaintEvent *);
    void setShadow();
    void showPopularBook();
    void loadPages();
    bool loadQss(const QString &StyleSheetFile );

public:
     MainWidget* sub_mw ;
private slots:
    void on_btn_search_clicked();
    void on_btn_author_clicked();
    void on_btn_bookname_clicked();
    void on_btn_ISBN_clicked();
    void on_cbox_classify_clicked();
    void on_lineEdit_returnPressed();

private:
    Ui::QueryBookWidget *ui;
    QString classify;//当前选择的分类
};

//MainWidget* QueryBookWidget::sub_mw = new MainWidget();

#endif // QUERYBOOKWIDGET_H
