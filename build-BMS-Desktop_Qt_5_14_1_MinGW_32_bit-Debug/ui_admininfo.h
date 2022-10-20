/********************************************************************************
** Form generated from reading UI file 'admininfo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMININFO_H
#define UI_ADMININFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminInfo
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
    QLineEdit *line_confirmPassword;
    QLabel *lb_modifyPassword;
    QLabel *lb_password;
    QLineEdit *line_password;
    QFrame *line;
    QPushButton *btn_modifyPassword;
    QLabel *lb_confirmPassword;
    QLineEdit *line_major;
    QLabel *lb_number_2;
    QLineEdit *line_number;
    QLabel *lb_mojor_2;
    QLineEdit *line_name;
    QLabel *lb_modifyInfo;
    QPushButton *btn_modifyInfo;
    QLineEdit *line_major_2;
    QLabel *lb_name;
    QComboBox *box_sex;
    QLabel *lb_mojor;
    QLabel *lb_sex_2;

    void setupUi(QWidget *AdminInfo)
    {
        if (AdminInfo->objectName().isEmpty())
            AdminInfo->setObjectName(QString::fromUtf8("AdminInfo"));
        AdminInfo->resize(1300, 900);
        fm_personal_infor = new QFrame(AdminInfo);
        fm_personal_infor->setObjectName(QString::fromUtf8("fm_personal_infor"));
        fm_personal_infor->setGeometry(QRect(110, 130, 471, 171));
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
        lb_credit->setGeometry(QRect(270, 100, 70, 30));
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
        lb_sex->setGeometry(QRect(270, 60, 70, 30));
        lb_credit_txt = new QLabel(fm_personal_infor);
        lb_credit_txt->setObjectName(QString::fromUtf8("lb_credit_txt"));
        lb_credit_txt->setGeometry(QRect(370, 100, 100, 30));
        lb_username_txt = new QLabel(fm_personal_infor);
        lb_username_txt->setObjectName(QString::fromUtf8("lb_username_txt"));
        lb_username_txt->setGeometry(QRect(100, 20, 160, 30));
        line_confirmPassword = new QLineEdit(AdminInfo);
        line_confirmPassword->setObjectName(QString::fromUtf8("line_confirmPassword"));
        line_confirmPassword->setGeometry(QRect(150, 600, 400, 40));
        lb_modifyPassword = new QLabel(AdminInfo);
        lb_modifyPassword->setObjectName(QString::fromUtf8("lb_modifyPassword"));
        lb_modifyPassword->setGeometry(QRect(290, 350, 90, 40));
        lb_password = new QLabel(AdminInfo);
        lb_password->setObjectName(QString::fromUtf8("lb_password"));
        lb_password->setGeometry(QRect(150, 420, 80, 40));
        line_password = new QLineEdit(AdminInfo);
        line_password->setObjectName(QString::fromUtf8("line_password"));
        line_password->setGeometry(QRect(150, 480, 400, 40));
        line = new QFrame(AdminInfo);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(690, 50, 10, 770));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        btn_modifyPassword = new QPushButton(AdminInfo);
        btn_modifyPassword->setObjectName(QString::fromUtf8("btn_modifyPassword"));
        btn_modifyPassword->setGeometry(QRect(280, 710, 120, 40));
        lb_confirmPassword = new QLabel(AdminInfo);
        lb_confirmPassword->setObjectName(QString::fromUtf8("lb_confirmPassword"));
        lb_confirmPassword->setGeometry(QRect(150, 540, 80, 40));
        line_major = new QLineEdit(AdminInfo);
        line_major->setObjectName(QString::fromUtf8("line_major"));
        line_major->setGeometry(QRect(850, 520, 400, 40));
        lb_number_2 = new QLabel(AdminInfo);
        lb_number_2->setObjectName(QString::fromUtf8("lb_number_2"));
        lb_number_2->setGeometry(QRect(740, 160, 80, 40));
        line_number = new QLineEdit(AdminInfo);
        line_number->setObjectName(QString::fromUtf8("line_number"));
        line_number->setGeometry(QRect(850, 220, 400, 40));
        lb_mojor_2 = new QLabel(AdminInfo);
        lb_mojor_2->setObjectName(QString::fromUtf8("lb_mojor_2"));
        lb_mojor_2->setGeometry(QRect(740, 580, 80, 40));
        line_name = new QLineEdit(AdminInfo);
        line_name->setObjectName(QString::fromUtf8("line_name"));
        line_name->setGeometry(QRect(850, 340, 400, 40));
        lb_modifyInfo = new QLabel(AdminInfo);
        lb_modifyInfo->setObjectName(QString::fromUtf8("lb_modifyInfo"));
        lb_modifyInfo->setGeometry(QRect(1000, 90, 90, 40));
        btn_modifyInfo = new QPushButton(AdminInfo);
        btn_modifyInfo->setObjectName(QString::fromUtf8("btn_modifyInfo"));
        btn_modifyInfo->setGeometry(QRect(990, 710, 120, 40));
        line_major_2 = new QLineEdit(AdminInfo);
        line_major_2->setObjectName(QString::fromUtf8("line_major_2"));
        line_major_2->setGeometry(QRect(850, 640, 400, 40));
        lb_name = new QLabel(AdminInfo);
        lb_name->setObjectName(QString::fromUtf8("lb_name"));
        lb_name->setGeometry(QRect(740, 280, 80, 40));
        box_sex = new QComboBox(AdminInfo);
        box_sex->setObjectName(QString::fromUtf8("box_sex"));
        box_sex->setGeometry(QRect(950, 400, 300, 40));
        lb_mojor = new QLabel(AdminInfo);
        lb_mojor->setObjectName(QString::fromUtf8("lb_mojor"));
        lb_mojor->setGeometry(QRect(740, 460, 80, 40));
        lb_sex_2 = new QLabel(AdminInfo);
        lb_sex_2->setObjectName(QString::fromUtf8("lb_sex_2"));
        lb_sex_2->setGeometry(QRect(740, 400, 80, 40));

        retranslateUi(AdminInfo);

        QMetaObject::connectSlotsByName(AdminInfo);
    } // setupUi

    void retranslateUi(QWidget *AdminInfo)
    {
        AdminInfo->setWindowTitle(QCoreApplication::translate("AdminInfo", "Form", nullptr));
        lb_major_txt->setText(QCoreApplication::translate("AdminInfo", "TextLabel", nullptr));
        lb_number->setText(QCoreApplication::translate("AdminInfo", "\345\255\246\345\217\267", nullptr));
        lb_username->setText(QCoreApplication::translate("AdminInfo", "\345\247\223\345\220\215", nullptr));
        lb_credit->setText(QCoreApplication::translate("AdminInfo", "\344\277\241\350\252\211\345\210\206", nullptr));
        lb_sex_txt->setText(QCoreApplication::translate("AdminInfo", "TextLabel", nullptr));
        lb_number_txt->setText(QCoreApplication::translate("AdminInfo", "TextLabel", nullptr));
        lb_major->setText(QCoreApplication::translate("AdminInfo", "\344\270\223\344\270\232", nullptr));
        lb_sex->setText(QCoreApplication::translate("AdminInfo", "\346\200\247\345\210\253", nullptr));
        lb_credit_txt->setText(QCoreApplication::translate("AdminInfo", "TextLabel", nullptr));
        lb_username_txt->setText(QCoreApplication::translate("AdminInfo", "TextLabel", nullptr));
        lb_modifyPassword->setText(QCoreApplication::translate("AdminInfo", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        lb_password->setText(QCoreApplication::translate("AdminInfo", "\345\257\206\347\240\201", nullptr));
        btn_modifyPassword->setText(QCoreApplication::translate("AdminInfo", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        lb_confirmPassword->setText(QCoreApplication::translate("AdminInfo", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        lb_number_2->setText(QCoreApplication::translate("AdminInfo", "\345\255\246\345\217\267", nullptr));
        lb_mojor_2->setText(QCoreApplication::translate("AdminInfo", "\351\202\256\347\256\261", nullptr));
        lb_modifyInfo->setText(QCoreApplication::translate("AdminInfo", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        btn_modifyInfo->setText(QCoreApplication::translate("AdminInfo", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        lb_name->setText(QCoreApplication::translate("AdminInfo", "\345\247\223\345\220\215", nullptr));
        lb_mojor->setText(QCoreApplication::translate("AdminInfo", "\344\270\223\344\270\232", nullptr));
        lb_sex_2->setText(QCoreApplication::translate("AdminInfo", "\346\200\247\345\210\253", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminInfo: public Ui_AdminInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMININFO_H
