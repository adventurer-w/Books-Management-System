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
    void tableModifyClicked();
    void on_btn_delete_clicked();
    void leModifyText(const QString text);


private:
    Ui::ModifyBookCategory *ui;

signals:
	void AmySignal();
};

#endif // MODIFYBOOKCATEGORY_H
