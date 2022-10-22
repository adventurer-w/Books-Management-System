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
    // 自定义的函数，为整个model设置数据



};

#endif // STDITEMMODEL_H
