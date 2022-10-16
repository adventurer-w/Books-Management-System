#ifndef USERPROFILEWIDGET_H
#define USERPROFILEWIDGET_H

#include <QTableView>
#include <QWidget>
#include "QPainter"
#include <string>
#include "MainWidget.h"
namespace Ui {
class UserProfileWidget;
}

class UserProfileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserProfileWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void setShadow();
    bool loadQss(const QString &StyleSheetFile);
    void showBorrow();


    ~UserProfileWidget();
public slots:
    void onTableBtnClicked();
    void reserveBtnClicked();
    void searchBooks(QString key);
public:
    MainWidget *pmw;
private:
    Ui::UserProfileWidget *ui;

};

#endif // USERPROFILEWIDGET_H
