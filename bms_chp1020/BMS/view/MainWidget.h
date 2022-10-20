#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QStackedWidget>
namespace Ui {
class MainWidget;
}

class MainWidget : public QStackedWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
//    void paintEvent(QPaintEvent *);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H
