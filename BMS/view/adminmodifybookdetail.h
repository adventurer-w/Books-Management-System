#ifndef ADMINMODIFYBOOKDETAIL_H
#define ADMINMODIFYBOOKDETAIL_H

#include <QWidget>
#include "MainWidget.h"

namespace Ui {
class AdminModifyBookDetail;
}

class AdminModifyBookDetail : public QWidget
{
    Q_OBJECT

public:
    explicit AdminModifyBookDetail(QWidget *parent = nullptr);
    ~AdminModifyBookDetail();
    void loadBookDetail();
    void setStackWidget(MainWidget *p);
    void setIcons();
    bool loadQss(const QString &StyleSheetFile);

    void on_pushButton_clicked();
signals:
void backSignal();
private slots:
     void on_btn_back_clicked();


private:
    Ui::AdminModifyBookDetail *ui;
    MainWidget *psw;//底层stackwidget对象的指针，便于返回
};

#endif // ADMINMODIFYBOOKDETAIL_H
