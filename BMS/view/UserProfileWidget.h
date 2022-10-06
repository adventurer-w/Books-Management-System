#ifndef USERPROFILEWIDGET_H
#define USERPROFILEWIDGET_H

#include <QTableView>
#include <QWidget>
#include "QPainter"
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
private slots:
    void onTableBtnClicked();
private:
    Ui::UserProfileWidget *ui;
};

#endif // USERPROFILEWIDGET_H
