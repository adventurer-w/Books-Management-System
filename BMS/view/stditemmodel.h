#ifndef STDITEMMODEL_H
#define STDITEMMODEL_H

#include <QWidget>
#include <QStandardItemModel>
class StdItemModel :public QStandardItemModel
{
public:
    StdItemModel();
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // STDITEMMODEL_H
