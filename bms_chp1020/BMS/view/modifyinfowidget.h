#ifndef MODIFYINFOWIDGET_H
#define MODIFYINFOWIDGET_H

#include <QWidget>

namespace Ui {
class ModifyInfoWidget;
}

class ModifyInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyInfoWidget(QWidget *parent = nullptr);
    bool loadQss(const QString &StyleSheetFile);
    void paintEvent(QPaintEvent *event);
    ~ModifyInfoWidget();
signals:
    void modifySignal();
private slots:
    void on_btn_modifyInfo_clicked();
    void on_btn_modifyPassword_clicked();

private:
    Ui::ModifyInfoWidget *ui;
};

#endif // MODIFYINFOWIDGET_H
