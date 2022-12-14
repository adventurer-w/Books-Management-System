#ifndef BORROWINSTRUCTION_H
#define BORROWINSTRUCTION_H

#include <QWidget>
#include <QFile>
#include <QMessageBox>
namespace Ui {
class BorrowInstruction;
}

class BorrowInstruction : public QWidget
{
    Q_OBJECT

public:
    explicit BorrowInstruction(QWidget *parent = nullptr);
    ~BorrowInstruction();
   bool loadQss(const QString &StyleSheetFile);
   void on_btn_modifyConfirm_clicked();
private:
    Ui::BorrowInstruction *ui;
};

#endif // BORROWINSTRUCTION_H
