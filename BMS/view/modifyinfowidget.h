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
    ~ModifyInfoWidget();

private:
    Ui::ModifyInfoWidget *ui;
};

#endif // MODIFYINFOWIDGET_H
