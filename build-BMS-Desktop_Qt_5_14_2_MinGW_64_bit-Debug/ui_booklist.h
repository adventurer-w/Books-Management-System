/********************************************************************************
** Form generated from reading UI file 'booklist.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKLIST_H
#define UI_BOOKLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookList
{
public:
    QTableView *tb;
    QPushButton *btn_fore;
    QLineEdit *line;
    QPushButton *btn_la;
    QPushButton *btn_first;
    QPushButton *btn_last;
    QPushButton *btn_back;

    void setupUi(QWidget *BookList)
    {
        if (BookList->objectName().isEmpty())
            BookList->setObjectName(QString::fromUtf8("BookList"));
        BookList->resize(1300, 730);
        tb = new QTableView(BookList);
        tb->setObjectName(QString::fromUtf8("tb"));
        tb->setGeometry(QRect(0, 50, 1300, 630));
        btn_fore = new QPushButton(BookList);
        btn_fore->setObjectName(QString::fromUtf8("btn_fore"));
        btn_fore->setGeometry(QRect(450, 690, 90, 30));
        line = new QLineEdit(BookList);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(570, 690, 110, 30));
        btn_la = new QPushButton(BookList);
        btn_la->setObjectName(QString::fromUtf8("btn_la"));
        btn_la->setGeometry(QRect(720, 690, 90, 30));
        btn_first = new QPushButton(BookList);
        btn_first->setObjectName(QString::fromUtf8("btn_first"));
        btn_first->setGeometry(QRect(350, 690, 90, 30));
        btn_last = new QPushButton(BookList);
        btn_last->setObjectName(QString::fromUtf8("btn_last"));
        btn_last->setGeometry(QRect(820, 690, 90, 30));
        btn_back = new QPushButton(BookList);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(0, 10, 40, 40));

        retranslateUi(BookList);

        QMetaObject::connectSlotsByName(BookList);
    } // setupUi

    void retranslateUi(QWidget *BookList)
    {
        BookList->setWindowTitle(QCoreApplication::translate("BookList", "Form", nullptr));
        btn_fore->setText(QCoreApplication::translate("BookList", "\344\270\212\344\270\200\351\241\265", nullptr));
        btn_la->setText(QCoreApplication::translate("BookList", "\344\270\213\344\270\200\351\241\265", nullptr));
        btn_first->setText(QCoreApplication::translate("BookList", "\351\246\226\351\241\265", nullptr));
        btn_last->setText(QCoreApplication::translate("BookList", "\345\260\276\351\241\265", nullptr));
        btn_back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BookList: public Ui_BookList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKLIST_H
