#ifndef SEARCHLINEEDIT_H
#define SEARCHLINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
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
public slots:
    void sendKey();
signals:
    void keySignal(QString key);


private:
    Ui::SearchLineEdit *ui;
    QPushButton* btn;
};

#endif // SEARCHLINEEDIT_H
