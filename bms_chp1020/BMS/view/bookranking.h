#ifndef BOOKRANKING_H
#define BOOKRANKING_H

#include <QWidget>
#include "MainWidget.h"
namespace Ui {
class BookRanking;
}

class BookRanking : public QWidget
{
    Q_OBJECT

public:
    explicit BookRanking(QWidget *parent = nullptr);
    void setShadow();
    void showPopularBook();
    void loadRankBooks();
    void showBorrowRank();
    void showHighScoreRank();
    bool loadQss(const QString &StyleSheetFile);
    ~BookRanking();



    MainWidget *psw;
private
    slots:
    void navigateToDetails();
private:
    Ui::BookRanking *ui;

};

#endif // BOOKRANKING_H
