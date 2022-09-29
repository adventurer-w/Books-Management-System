#ifndef QUERYBOOKWIDGET_H
#define QUERYBOOKWIDGET_H

#include <QWidget>

namespace Ui {
class QueryBookWidget;
}

class QueryBookWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QueryBookWidget(QWidget *parent = nullptr);
    ~QueryBookWidget();

private:
    Ui::QueryBookWidget *ui;
};

#endif // QUERYBOOKWIDGET_H
