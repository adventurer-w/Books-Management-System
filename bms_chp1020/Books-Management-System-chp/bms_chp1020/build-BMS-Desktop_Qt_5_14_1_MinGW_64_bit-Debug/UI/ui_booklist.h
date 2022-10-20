/********************************************************************************
** Form generated from reading UI file 'booklist.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKLIST_H
#define UI_BOOKLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookList
{
public:
    QTableView *tb;
    QPushButton *btn_back;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_first;
    QPushButton *btn_fore;
    QSpacerItem *horizontalSpacer;
    QLineEdit *line;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_la;
    QPushButton *btn_last;

    void setupUi(QWidget *BookList)
    {
        if (BookList->objectName().isEmpty())
            BookList->setObjectName(QString::fromUtf8("BookList"));
        BookList->resize(1300, 730);
        tb = new QTableView(BookList);
        tb->setObjectName(QString::fromUtf8("tb"));
        tb->setGeometry(QRect(50, 50, 1250, 630));
        btn_back = new QPushButton(BookList);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(0, 10, 40, 40));
        layoutWidget = new QWidget(BookList);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(350, 690, 564, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_first = new QPushButton(layoutWidget);
        btn_first->setObjectName(QString::fromUtf8("btn_first"));
        btn_first->setMinimumSize(QSize(90, 30));
        btn_first->setMaximumSize(QSize(90, 30));

        horizontalLayout->addWidget(btn_first);

        btn_fore = new QPushButton(layoutWidget);
        btn_fore->setObjectName(QString::fromUtf8("btn_fore"));
        btn_fore->setMinimumSize(QSize(90, 30));
        btn_fore->setMaximumSize(QSize(90, 30));

        horizontalLayout->addWidget(btn_fore);

        horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        line = new QLineEdit(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(110, 30));
        line->setMaximumSize(QSize(110, 30));

        horizontalLayout->addWidget(line);

        horizontalSpacer_2 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_la = new QPushButton(layoutWidget);
        btn_la->setObjectName(QString::fromUtf8("btn_la"));
        btn_la->setMinimumSize(QSize(90, 30));
        btn_la->setMaximumSize(QSize(90, 30));

        horizontalLayout->addWidget(btn_la);

        btn_last = new QPushButton(layoutWidget);
        btn_last->setObjectName(QString::fromUtf8("btn_last"));
        btn_last->setMinimumSize(QSize(90, 30));
        btn_last->setMaximumSize(QSize(90, 30));

        horizontalLayout->addWidget(btn_last);


        retranslateUi(BookList);

        QMetaObject::connectSlotsByName(BookList);
    } // setupUi

    void retranslateUi(QWidget *BookList)
    {
        BookList->setWindowTitle(QCoreApplication::translate("BookList", "Form", nullptr));
        btn_back->setText(QString());
        btn_first->setText(QCoreApplication::translate("BookList", "\351\246\226\351\241\265", nullptr));
        btn_fore->setText(QCoreApplication::translate("BookList", "\344\270\212\344\270\200\351\241\265", nullptr));
        btn_la->setText(QCoreApplication::translate("BookList", "\344\270\213\344\270\200\351\241\265", nullptr));
        btn_last->setText(QCoreApplication::translate("BookList", "\345\260\276\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookList: public Ui_BookList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKLIST_H
