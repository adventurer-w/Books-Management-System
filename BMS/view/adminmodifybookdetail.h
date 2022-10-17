#ifndef ADMINMODIFYBOOKDETAIL_H
#define ADMINMODIFYBOOKDETAIL_H

#include <QWidget>

namespace Ui {
class AdminModifyBookDetail;
}

class AdminModifyBookDetail : public QWidget
{
    Q_OBJECT

public:
    explicit AdminModifyBookDetail(QWidget *parent = nullptr);
    ~AdminModifyBookDetail();

private:
    Ui::AdminModifyBookDetail *ui;
};

#endif // ADMINMODIFYBOOKDETAIL_H
