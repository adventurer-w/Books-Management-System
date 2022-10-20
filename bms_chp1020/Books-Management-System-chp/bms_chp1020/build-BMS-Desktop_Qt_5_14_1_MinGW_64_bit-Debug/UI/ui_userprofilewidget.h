/********************************************************************************
** Form generated from reading UI file 'userprofilewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPROFILEWIDGET_H
#define UI_USERPROFILEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserProfileWidget
{
public:
    QFrame *fm_personal_infor;
    QLabel *lb_major_txt;
    QLabel *lb_number;
    QLabel *lb_username;
    QLabel *lb_credit;
    QLabel *lb_sex_txt;
    QLabel *lb_number_txt;
    QLabel *lb_major;
    QLabel *lb_sex;
    QLabel *lb_credit_txt;
    QLabel *lb_username_txt;
    QLabel *lb_currentborrow;
    QTableView *tbv_borrow;
    QPushButton *pushButton;

    void setupUi(QWidget *UserProfileWidget)
    {
        if (UserProfileWidget->objectName().isEmpty())
            UserProfileWidget->setObjectName(QString::fromUtf8("UserProfileWidget"));
        UserProfileWidget->resize(1300, 900);
        UserProfileWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        fm_personal_infor = new QFrame(UserProfileWidget);
        fm_personal_infor->setObjectName(QString::fromUtf8("fm_personal_infor"));
        fm_personal_infor->setGeometry(QRect(260, 40, 471, 171));
        fm_personal_infor->setFrameShape(QFrame::StyledPanel);
        fm_personal_infor->setFrameShadow(QFrame::Raised);
        lb_major_txt = new QLabel(fm_personal_infor);
        lb_major_txt->setObjectName(QString::fromUtf8("lb_major_txt"));
        lb_major_txt->setGeometry(QRect(100, 60, 161, 30));
        lb_number = new QLabel(fm_personal_infor);
        lb_number->setObjectName(QString::fromUtf8("lb_number"));
        lb_number->setGeometry(QRect(30, 100, 41, 30));
        lb_username = new QLabel(fm_personal_infor);
        lb_username->setObjectName(QString::fromUtf8("lb_username"));
        lb_username->setGeometry(QRect(30, 20, 41, 30));
        lb_credit = new QLabel(fm_personal_infor);
        lb_credit->setObjectName(QString::fromUtf8("lb_credit"));
        lb_credit->setGeometry(QRect(300, 100, 70, 30));
        lb_sex_txt = new QLabel(fm_personal_infor);
        lb_sex_txt->setObjectName(QString::fromUtf8("lb_sex_txt"));
        lb_sex_txt->setGeometry(QRect(370, 60, 100, 30));
        lb_number_txt = new QLabel(fm_personal_infor);
        lb_number_txt->setObjectName(QString::fromUtf8("lb_number_txt"));
        lb_number_txt->setGeometry(QRect(100, 100, 160, 30));
        lb_major = new QLabel(fm_personal_infor);
        lb_major->setObjectName(QString::fromUtf8("lb_major"));
        lb_major->setGeometry(QRect(30, 60, 41, 30));
        lb_sex = new QLabel(fm_personal_infor);
        lb_sex->setObjectName(QString::fromUtf8("lb_sex"));
        lb_sex->setGeometry(QRect(310, 60, 70, 30));
        lb_credit_txt = new QLabel(fm_personal_infor);
        lb_credit_txt->setObjectName(QString::fromUtf8("lb_credit_txt"));
        lb_credit_txt->setGeometry(QRect(370, 100, 100, 30));
        lb_username_txt = new QLabel(fm_personal_infor);
        lb_username_txt->setObjectName(QString::fromUtf8("lb_username_txt"));
        lb_username_txt->setGeometry(QRect(100, 20, 160, 30));
        lb_currentborrow = new QLabel(UserProfileWidget);
        lb_currentborrow->setObjectName(QString::fromUtf8("lb_currentborrow"));
        lb_currentborrow->setGeometry(QRect(120, 300, 230, 40));
        tbv_borrow = new QTableView(UserProfileWidget);
        tbv_borrow->setObjectName(QString::fromUtf8("tbv_borrow"));
        tbv_borrow->setGeometry(QRect(120, 370, 1030, 250));
        pushButton = new QPushButton(UserProfileWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 230, 101, 31));

        retranslateUi(UserProfileWidget);

        QMetaObject::connectSlotsByName(UserProfileWidget);
    } // setupUi

    void retranslateUi(QWidget *UserProfileWidget)
    {
        UserProfileWidget->setWindowTitle(QCoreApplication::translate("UserProfileWidget", "Form", nullptr));
        lb_major_txt->setText(QCoreApplication::translate("UserProfileWidget", "TextLabel", nullptr));
        lb_number->setText(QCoreApplication::translate("UserProfileWidget", "\345\255\246\345\217\267", nullptr));
        lb_username->setText(QCoreApplication::translate("UserProfileWidget", "\345\247\223\345\220\215", nullptr));
        lb_credit->setText(QCoreApplication::translate("UserProfileWidget", " \346\254\240\346\254\276", nullptr));
        lb_sex_txt->setText(QCoreApplication::translate("UserProfileWidget", "TextLabel", nullptr));
        lb_number_txt->setText(QCoreApplication::translate("UserProfileWidget", "TextLabel", nullptr));
        lb_major->setText(QCoreApplication::translate("UserProfileWidget", "\345\255\246\345\216\206", nullptr));
        lb_sex->setText(QCoreApplication::translate("UserProfileWidget", "\346\200\247\345\210\253", nullptr));
        lb_credit_txt->setText(QCoreApplication::translate("UserProfileWidget", "TextLabel", nullptr));
        lb_username_txt->setText(QCoreApplication::translate("UserProfileWidget", "TextLabel", nullptr));
        lb_currentborrow->setText(QCoreApplication::translate("UserProfileWidget", "\345\275\223\345\211\215\345\200\237\351\230\205", nullptr));
        pushButton->setText(QCoreApplication::translate("UserProfileWidget", "\345\200\237\351\230\205\351\241\273\347\237\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserProfileWidget: public Ui_UserProfileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPROFILEWIDGET_H
