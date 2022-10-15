#ifndef ADMINBOOKMANAGEMENT_H
#define ADMINBOOKMANAGEMENT_H

#include <QWidget>

namespace Ui {
class AdminBookManagement;
}

class AdminBookManagement : public QWidget
{
    Q_OBJECT

public:
    explicit AdminBookManagement(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    bool loadQss(const QString &StyleSheetFile);
    ~AdminBookManagement();

private:
    Ui::AdminBookManagement *ui;
};

#endif // ADMINBOOKLIST_H
