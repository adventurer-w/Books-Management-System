/********************************************************************************
** Form generated from reading UI file 'usermanagement.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGEMENT_H
#define UI_USERMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserManagement
{
public:
    QLineEdit *line_search;
    QPushButton *btn_borrowInstruction;
    QPushButton *btn_search;
    QTableView *tb;

    void setupUi(QWidget *UserManagement)
    {
        if (UserManagement->objectName().isEmpty())
            UserManagement->setObjectName(QString::fromUtf8("UserManagement"));
        UserManagement->resize(1300, 900);
        line_search = new QLineEdit(UserManagement);
        line_search->setObjectName(QString::fromUtf8("line_search"));
        line_search->setGeometry(QRect(170, 50, 980, 40));
        btn_borrowInstruction = new QPushButton(UserManagement);
        btn_borrowInstruction->setObjectName(QString::fromUtf8("btn_borrowInstruction"));
        btn_borrowInstruction->setGeometry(QRect(40, 50, 100, 40));
        btn_borrowInstruction->setCheckable(true);
        btn_search = new QPushButton(UserManagement);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));
        btn_search->setGeometry(QRect(1180, 50, 70, 40));
        btn_search->setCheckable(true);
        tb = new QTableView(UserManagement);
        tb->setObjectName(QString::fromUtf8("tb"));
        tb->setGeometry(QRect(22, 139, 1250, 660));

        retranslateUi(UserManagement);

        QMetaObject::connectSlotsByName(UserManagement);
    } // setupUi

    void retranslateUi(QWidget *UserManagement)
    {
        UserManagement->setWindowTitle(QCoreApplication::translate("UserManagement", "Form", nullptr));
        btn_borrowInstruction->setText(QCoreApplication::translate("UserManagement", "\345\200\237\351\230\205\351\241\273\347\237\245", nullptr));
        btn_search->setText(QCoreApplication::translate("UserManagement", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserManagement: public Ui_UserManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGEMENT_H
