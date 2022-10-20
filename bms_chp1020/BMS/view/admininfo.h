#ifndef ADMININFO_H
#define ADMININFO_H

#include <QWidget>

namespace Ui {
class AdminInfo;
}

class AdminInfo : public QWidget
{
    Q_OBJECT

public:
    explicit AdminInfo(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    bool loadQss(const QString &StyleSheetFile);
    ~AdminInfo();

private:
    Ui::AdminInfo *ui;

private slots:
    void on_btn_modifyInfo_clicked();
    void on_btn_modifyPassword_clicked();
};

#endif // ADMININFO_H
