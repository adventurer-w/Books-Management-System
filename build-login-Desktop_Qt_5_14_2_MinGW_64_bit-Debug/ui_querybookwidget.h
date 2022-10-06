/********************************************************************************
** Form generated from reading UI file 'querybookwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYBOOKWIDGET_H
#define UI_QUERYBOOKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QueryBookWidget
{
public:
    QPushButton *btn_bookname;
    QPushButton *btn_author;
    QPushButton *btn_ISBN;
    QLineEdit *lineEdit;
    QComboBox *cbox_classify;
    QPushButton *btn_search;

    void setupUi(QWidget *QueryBookWidget)
    {
        if (QueryBookWidget->objectName().isEmpty())
            QueryBookWidget->setObjectName(QString::fromUtf8("QueryBookWidget"));
        QueryBookWidget->resize(1300, 900);
        btn_bookname = new QPushButton(QueryBookWidget);
        btn_bookname->setObjectName(QString::fromUtf8("btn_bookname"));
        btn_bookname->setGeometry(QRect(190, 80, 70, 41));
        btn_author = new QPushButton(QueryBookWidget);
        btn_author->setObjectName(QString::fromUtf8("btn_author"));
        btn_author->setGeometry(QRect(280, 80, 70, 41));
        btn_ISBN = new QPushButton(QueryBookWidget);
        btn_ISBN->setObjectName(QString::fromUtf8("btn_ISBN"));
        btn_ISBN->setGeometry(QRect(370, 80, 70, 41));
        lineEdit = new QLineEdit(QueryBookWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(470, 80, 730, 41));
        cbox_classify = new QComboBox(QueryBookWidget);
        cbox_classify->setObjectName(QString::fromUtf8("cbox_classify"));
        cbox_classify->setGeometry(QRect(30, 80, 141, 41));
        btn_search = new QPushButton(QueryBookWidget);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));
        btn_search->setGeometry(QRect(1210, 80, 50, 30));

        retranslateUi(QueryBookWidget);

        QMetaObject::connectSlotsByName(QueryBookWidget);
    } // setupUi

    void retranslateUi(QWidget *QueryBookWidget)
    {
        QueryBookWidget->setWindowTitle(QCoreApplication::translate("QueryBookWidget", "Form", nullptr));
        btn_bookname->setText(QCoreApplication::translate("QueryBookWidget", "\344\271\246\345\220\215", nullptr));
        btn_author->setText(QCoreApplication::translate("QueryBookWidget", "\344\275\234\350\200\205", nullptr));
        btn_ISBN->setText(QCoreApplication::translate("QueryBookWidget", "ISBN", nullptr));
        btn_search->setText(QCoreApplication::translate("QueryBookWidget", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QueryBookWidget: public Ui_QueryBookWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYBOOKWIDGET_H
