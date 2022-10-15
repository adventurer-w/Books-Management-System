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
};

#endif // ADMININFO_H
