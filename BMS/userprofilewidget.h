#ifndef USERPROFILEWIDGET_H
#define USERPROFILEWIDGET_H

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
    bool loadQss(const QString &StyleSheetFile);
    ~UserProfileWidget();

private:
    Ui::UserProfileWidget *ui;
};

#endif // USERPROFILEWIDGET_H
