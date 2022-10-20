#include "stditemmodel.h"
#include <QStandardItemModel>
StdItemModel::StdItemModel()
{

}
/*
 *@author yuan
继承了QStandardItemModel类
重写QStandardItemModel的data方法，使得单元格内容能够居中对齐

*/

QVariant StdItemModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignCenter);  //按需调整
    }
    return QStandardItemModel::data(index,role);
}
