#ifndef STDITEMMODEL_H
#define STDITEMMODEL_H

#include <QWidget>
#include <QStandardItemModel>
//#include "backend/Book.h"
//#include "booklist.h"
class StdItemModel :public QStandardItemModel
{
public:
    StdItemModel();
    QVariant data(const QModelIndex &index, int role) const;
    //void loadBookData(vector<Book> &re,BookList *bookList);
};

#endif // STDITEMMODEL_H
