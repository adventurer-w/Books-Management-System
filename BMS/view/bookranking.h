#ifndef BOOKRANKING_H
#define BOOKRANKING_H

#include <QWidget>

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
    bool loadQss(const QString &StyleSheetFile);
    ~BookRanking();

private:
    Ui::BookRanking *ui;
};

#endif // BOOKRANKING_H
