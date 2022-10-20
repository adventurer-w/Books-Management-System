/********************************************************************************
** Form generated from reading UI file 'adminbookmanagement.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINBOOKMANAGEMENT_H
#define UI_ADMINBOOKMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminBookManagement
{
public:
    QTableView *tb;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_first;
    QPushButton *btn_fore;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *line;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_la;
    QPushButton *btn_last;
    QPushButton *btn_author;
    QPushButton *btn_addbook;
    QComboBox *cbox_classify;
    QPushButton *btn_bookname;
    QPushButton *btn_ISBN;
    QLineEdit *line_search;
    QPushButton *btn_addclassify;
    QPushButton *btn_search;
    QPushButton *btn_addbook_batch;

    void setupUi(QWidget *AdminBookManagement)
    {
        if (AdminBookManagement->objectName().isEmpty())
            AdminBookManagement->setObjectName(QString::fromUtf8("AdminBookManagement"));
        AdminBookManagement->resize(1300, 900);
        tb = new QTableView(AdminBookManagement);
        tb->setObjectName(QString::fromUtf8("tb"));
        tb->setGeometry(QRect(30, 179, 1250, 620));
        layoutWidget = new QWidget(AdminBookManagement);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(330, 850, 564, 32));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btn_first = new QPushButton(layoutWidget);
        btn_first->setObjectName(QString::fromUtf8("btn_first"));
        btn_first->setMinimumSize(QSize(90, 30));
        btn_first->setMaximumSize(QSize(90, 30));

        horizontalLayout_3->addWidget(btn_first);

        btn_fore = new QPushButton(layoutWidget);
        btn_fore->setObjectName(QString::fromUtf8("btn_fore"));
        btn_fore->setMinimumSize(QSize(90, 30));
        btn_fore->setMaximumSize(QSize(90, 30));

        horizontalLayout_3->addWidget(btn_fore);

        horizontalSpacer_5 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        line = new QLineEdit(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(110, 30));
        line->setMaximumSize(QSize(110, 30));

        horizontalLayout_3->addWidget(line);

        horizontalSpacer_6 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        btn_la = new QPushButton(layoutWidget);
        btn_la->setObjectName(QString::fromUtf8("btn_la"));
        btn_la->setMinimumSize(QSize(90, 30));
        btn_la->setMaximumSize(QSize(90, 30));

        horizontalLayout_3->addWidget(btn_la);

        btn_last = new QPushButton(layoutWidget);
        btn_last->setObjectName(QString::fromUtf8("btn_last"));
        btn_last->setMinimumSize(QSize(90, 30));
        btn_last->setMaximumSize(QSize(90, 30));

        horizontalLayout_3->addWidget(btn_last);

        btn_author = new QPushButton(AdminBookManagement);
        btn_author->setObjectName(QString::fromUtf8("btn_author"));
        btn_author->setGeometry(QRect(350, 80, 70, 40));
        btn_author->setCheckable(true);
        btn_addbook = new QPushButton(AdminBookManagement);
        btn_addbook->setObjectName(QString::fromUtf8("btn_addbook"));
        btn_addbook->setGeometry(QRect(170, 20, 80, 40));
        cbox_classify = new QComboBox(AdminBookManagement);
        cbox_classify->setObjectName(QString::fromUtf8("cbox_classify"));
        cbox_classify->setGeometry(QRect(30, 80, 140, 40));
        btn_bookname = new QPushButton(AdminBookManagement);
        btn_bookname->setObjectName(QString::fromUtf8("btn_bookname"));
        btn_bookname->setGeometry(QRect(250, 80, 70, 40));
        btn_bookname->setCheckable(true);
        btn_ISBN = new QPushButton(AdminBookManagement);
        btn_ISBN->setObjectName(QString::fromUtf8("btn_ISBN"));
        btn_ISBN->setGeometry(QRect(450, 80, 70, 40));
        btn_ISBN->setCheckable(true);
        line_search = new QLineEdit(AdminBookManagement);
        line_search->setObjectName(QString::fromUtf8("line_search"));
        line_search->setGeometry(QRect(550, 80, 600, 40));
        btn_addclassify = new QPushButton(AdminBookManagement);
        btn_addclassify->setObjectName(QString::fromUtf8("btn_addclassify"));
        btn_addclassify->setGeometry(QRect(30, 20, 101, 40));
        btn_addclassify->setCheckable(true);
        btn_search = new QPushButton(AdminBookManagement);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));
        btn_search->setGeometry(QRect(1150, 80, 80, 40));
        btn_addbook_batch = new QPushButton(AdminBookManagement);
        btn_addbook_batch->setObjectName(QString::fromUtf8("btn_addbook_batch"));
        btn_addbook_batch->setGeometry(QRect(280, 20, 141, 40));

        retranslateUi(AdminBookManagement);

        QMetaObject::connectSlotsByName(AdminBookManagement);
    } // setupUi

    void retranslateUi(QWidget *AdminBookManagement)
    {
        AdminBookManagement->setWindowTitle(QCoreApplication::translate("AdminBookManagement", "Form", nullptr));
        btn_first->setText(QCoreApplication::translate("AdminBookManagement", "\351\246\226\351\241\265", nullptr));
        btn_fore->setText(QCoreApplication::translate("AdminBookManagement", "\344\270\212\344\270\200\351\241\265", nullptr));
        btn_la->setText(QCoreApplication::translate("AdminBookManagement", "\344\270\213\344\270\200\351\241\265", nullptr));
        btn_last->setText(QCoreApplication::translate("AdminBookManagement", "\345\260\276\351\241\265", nullptr));
        btn_author->setText(QCoreApplication::translate("AdminBookManagement", "\344\275\234\350\200\205", nullptr));
        btn_addbook->setText(QCoreApplication::translate("AdminBookManagement", "\346\267\273\345\212\240\345\233\276\344\271\246", nullptr));
        btn_bookname->setText(QCoreApplication::translate("AdminBookManagement", "\344\271\246\345\220\215", nullptr));
        btn_ISBN->setText(QCoreApplication::translate("AdminBookManagement", "ISBN", nullptr));
        btn_addclassify->setText(QCoreApplication::translate("AdminBookManagement", "\347\261\273\345\210\253\347\256\241\347\220\206", nullptr));
        btn_search->setText(QCoreApplication::translate("AdminBookManagement", "\346\220\234\347\264\242", nullptr));
        btn_addbook_batch->setText(QCoreApplication::translate("AdminBookManagement", "\346\211\271\351\207\217\346\267\273\345\212\240\345\233\276\344\271\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminBookManagement: public Ui_AdminBookManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINBOOKMANAGEMENT_H
