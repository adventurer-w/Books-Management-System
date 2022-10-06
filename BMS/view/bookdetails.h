#ifndef BOOKDETAILS_H
#define BOOKDETAILS_H

#include <QWidget>
#include "MainWidget.h"
namespace Ui {
class BookDetails;
}

class BookDetails : public QWidget
{
    Q_OBJECT

public:
    explicit BookDetails(QWidget *parent = nullptr);
    void setStackWidget(MainWidget *p);
    void setIcons();
    bool loadQss(const QString &StyleSheetFile);
    ~BookDetails();

private slots:
    void on_btn_back_clicked();
    void on_btn_back_doubleclicked();

private:
    Ui::BookDetails *ui;
    MainWidget *psw;//底层stackwidget对象的指针，便于返回
};

#endif // BOOKDETAILS_H
