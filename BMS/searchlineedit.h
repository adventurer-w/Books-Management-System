#ifndef SEARCHLINEEDIT_H
#define SEARCHLINEEDIT_H

#include <QWidget>
#include <QLineEdit>
namespace Ui {
class SearchLineEdit;
}

class SearchLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit SearchLineEdit(QWidget *parent = nullptr);
    bool loadQss(const QString &StyleSheetFile);
    ~SearchLineEdit();

private:
    Ui::SearchLineEdit *ui;
};

#endif // SEARCHLINEEDIT_H
