#ifndef MODIFYBOOKCATEGORY_H
#define MODIFYBOOKCATEGORY_H

#include <QWidget>
#include "stditemmodel.h"

namespace Ui
{
    class ModifyBookCategory;
}

class ModifyBookCategory : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyBookCategory(QWidget *parent = nullptr);
    ~ModifyBookCategory();
    void loadclassify();
    StdItemModel *model;
    void on_linePressed();
    void on_btn_addclassify_clicked();
    void on_btn_modify_clicked();
    void on_btn_delete_clicked();
    void on_btn_update_clicked();

private:
    Ui::ModifyBookCategory *ui;
};

#endif // MODIFYBOOKCATEGORY_H
