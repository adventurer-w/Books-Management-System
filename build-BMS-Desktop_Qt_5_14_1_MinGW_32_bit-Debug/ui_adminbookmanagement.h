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
    QPushButton *btn_first_3;
    QPushButton *btn_fore_3;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *line_3;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_la_3;
    QPushButton *btn_last_3;
    QPushButton *btn_author;
    QPushButton *btn_search;
    QComboBox *cbox_classify;
    QPushButton *btn_bookname;
    QPushButton *btn_ISBN;
    QLineEdit *lineEdit;
    QPushButton *btn_addbook;

    void setupUi(QWidget *AdminBookManagement)
    {
        if (AdminBookManagement->objectName().isEmpty())
            AdminBookManagement->setObjectName(QString::fromUtf8("AdminBookManagement"));
        AdminBookManagement->resize(1300, 900);
        tb = new QTableView(AdminBookManagement);
        tb->setObjectName(QString::fromUtf8("tb"));
        tb->setGeometry(QRect(30, 179, 1250, 660));
        layoutWidget = new QWidget(AdminBookManagement);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(330, 850, 564, 32));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btn_first_3 = new QPushButton(layoutWidget);
        btn_first_3->setObjectName(QString::fromUtf8("btn_first_3"));
        btn_first_3->setMinimumSize(QSize(90, 30));
        btn_first_3->setMaximumSize(QSize(90, 30));

        horizontalLayout_3->addWidget(btn_first_3);

        btn_fore_3 = new QPushButton(layoutWidget);
        btn_fore_3->setObjectName(QString::fromUtf8("btn_fore_3"));
        btn_fore_3->setMinimumSize(QSize(90, 30));
        btn_fore_3->setMaximumSize(QSize(90, 30));

        horizontalLayout_3->addWidget(btn_fore_3);

        horizontalSpacer_5 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        line_3 = new QLineEdit(layoutWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setMinimumSize(QSize(110, 30));
        line_3->setMaximumSize(QSize(110, 30));

        horizontalLayout_3->addWidget(line_3);

        horizontalSpacer_6 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        btn_la_3 = new QPushButton(layoutWidget);
        btn_la_3->setObjectName(QString::fromUtf8("btn_la_3"));
        btn_la_3->setMinimumSize(QSize(90, 30));
        btn_la_3->setMaximumSize(QSize(90, 30));

        horizontalLayout_3->addWidget(btn_la_3);

        btn_last_3 = new QPushButton(layoutWidget);
        btn_last_3->setObjectName(QString::fromUtf8("btn_last_3"));
        btn_last_3->setMinimumSize(QSize(90, 30));
        btn_last_3->setMaximumSize(QSize(90, 30));

        horizontalLayout_3->addWidget(btn_last_3);

        btn_author = new QPushButton(AdminBookManagement);
        btn_author->setObjectName(QString::fromUtf8("btn_author"));
        btn_author->setGeometry(QRect(290, 80, 70, 40));
        btn_author->setCheckable(true);
        btn_search = new QPushButton(AdminBookManagement);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));
        btn_search->setGeometry(QRect(1210, 80, 80, 40));
        cbox_classify = new QComboBox(AdminBookManagement);
        cbox_classify->setObjectName(QString::fromUtf8("cbox_classify"));
        cbox_classify->setGeometry(QRect(30, 80, 140, 40));
        btn_bookname = new QPushButton(AdminBookManagement);
        btn_bookname->setObjectName(QString::fromUtf8("btn_bookname"));
        btn_bookname->setGeometry(QRect(190, 80, 70, 40));
        btn_bookname->setCheckable(true);
        btn_ISBN = new QPushButton(AdminBookManagement);
        btn_ISBN->setObjectName(QString::fromUtf8("btn_ISBN"));
        btn_ISBN->setGeometry(QRect(390, 80, 70, 40));
        btn_ISBN->setCheckable(true);
        lineEdit = new QLineEdit(AdminBookManagement);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(519, 80, 680, 40));
        btn_addbook = new QPushButton(AdminBookManagement);
        btn_addbook->setObjectName(QString::fromUtf8("btn_addbook"));
        btn_addbook->setGeometry(QRect(1210, 30, 80, 40));

        retranslateUi(AdminBookManagement);

        QMetaObject::connectSlotsByName(AdminBookManagement);
    } // setupUi

    void retranslateUi(QWidget *AdminBookManagement)
    {
        AdminBookManagement->setWindowTitle(QCoreApplication::translate("AdminBookManagement", "Form", nullptr));
        btn_first_3->setText(QCoreApplication::translate("AdminBookManagement", "\351\246\226\351\241\265", nullptr));
        btn_fore_3->setText(QCoreApplication::translate("AdminBookManagement", "\344\270\212\344\270\200\351\241\265", nullptr));
        btn_la_3->setText(QCoreApplication::translate("AdminBookManagement", "\344\270\213\344\270\200\351\241\265", nullptr));
        btn_last_3->setText(QCoreApplication::translate("AdminBookManagement", "\345\260\276\351\241\265", nullptr));
        btn_author->setText(QCoreApplication::translate("AdminBookManagement", "\344\275\234\350\200\205", nullptr));
        btn_search->setText(QCoreApplication::translate("AdminBookManagement", "\346\220\234\347\264\242", nullptr));
        btn_bookname->setText(QCoreApplication::translate("AdminBookManagement", "\344\271\246\345\220\215", nullptr));
        btn_ISBN->setText(QCoreApplication::translate("AdminBookManagement", "ISBN", nullptr));
        btn_addbook->setText(QCoreApplication::translate("AdminBookManagement", "\346\267\273\345\212\240\345\233\276\344\271\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminBookManagement: public Ui_AdminBookManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINBOOKMANAGEMENT_H
