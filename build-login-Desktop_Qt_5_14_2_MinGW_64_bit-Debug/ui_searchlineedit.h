/********************************************************************************
** Form generated from reading UI file 'searchlineedit.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHLINEEDIT_H
#define UI_SEARCHLINEEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchLineEdit
{
public:

    void setupUi(QWidget *SearchLineEdit)
    {
        if (SearchLineEdit->objectName().isEmpty())
            SearchLineEdit->setObjectName(QString::fromUtf8("SearchLineEdit"));
        SearchLineEdit->resize(400, 300);

        retranslateUi(SearchLineEdit);

        QMetaObject::connectSlotsByName(SearchLineEdit);
    } // setupUi

    void retranslateUi(QWidget *SearchLineEdit)
    {
        SearchLineEdit->setWindowTitle(QCoreApplication::translate("SearchLineEdit", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchLineEdit: public Ui_SearchLineEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHLINEEDIT_H
