/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *lb_number;
    QLineEdit *line_bumber;
    QLineEdit *line_name;
    QLabel *lb_name;
    QLabel *lb_sex;
    QComboBox *box_sex;
    QLabel *lb_email;
    QLabel *lb_major;
    QLineEdit *line_email;
    QLineEdit *line_password;
    QLabel *lb_passwod;
    QLabel *lb_emailcode;
    QLineEdit *line_emailcode;
    QLineEdit *line_confirmPasswod;
    QLabel *lb_confirmPasswod;
    QPushButton *btn_register;
    QLabel *label;
    QPushButton *btn_emailcode;
    QComboBox *comboBox;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(500, 721);
        lb_number = new QLabel(Register);
        lb_number->setObjectName(QString::fromUtf8("lb_number"));
        lb_number->setGeometry(QRect(150, 20, 70, 25));
        line_bumber = new QLineEdit(Register);
        line_bumber->setObjectName(QString::fromUtf8("line_bumber"));
        line_bumber->setGeometry(QRect(150, 60, 200, 30));
        line_name = new QLineEdit(Register);
        line_name->setObjectName(QString::fromUtf8("line_name"));
        line_name->setGeometry(QRect(150, 140, 200, 30));
        lb_name = new QLabel(Register);
        lb_name->setObjectName(QString::fromUtf8("lb_name"));
        lb_name->setGeometry(QRect(150, 100, 70, 25));
        lb_sex = new QLabel(Register);
        lb_sex->setObjectName(QString::fromUtf8("lb_sex"));
        lb_sex->setGeometry(QRect(150, 180, 70, 25));
        box_sex = new QComboBox(Register);
        box_sex->setObjectName(QString::fromUtf8("box_sex"));
        box_sex->setGeometry(QRect(210, 180, 90, 30));
        lb_email = new QLabel(Register);
        lb_email->setObjectName(QString::fromUtf8("lb_email"));
        lb_email->setGeometry(QRect(150, 300, 70, 25));
        lb_major = new QLabel(Register);
        lb_major->setObjectName(QString::fromUtf8("lb_major"));
        lb_major->setGeometry(QRect(150, 220, 70, 25));
        line_email = new QLineEdit(Register);
        line_email->setObjectName(QString::fromUtf8("line_email"));
        line_email->setGeometry(QRect(150, 340, 200, 30));
        line_password = new QLineEdit(Register);
        line_password->setObjectName(QString::fromUtf8("line_password"));
        line_password->setGeometry(QRect(150, 500, 200, 30));
        lb_passwod = new QLabel(Register);
        lb_passwod->setObjectName(QString::fromUtf8("lb_passwod"));
        lb_passwod->setGeometry(QRect(150, 460, 70, 25));
        lb_emailcode = new QLabel(Register);
        lb_emailcode->setObjectName(QString::fromUtf8("lb_emailcode"));
        lb_emailcode->setGeometry(QRect(150, 380, 90, 25));
        line_emailcode = new QLineEdit(Register);
        line_emailcode->setObjectName(QString::fromUtf8("line_emailcode"));
        line_emailcode->setGeometry(QRect(150, 420, 200, 30));
        line_confirmPasswod = new QLineEdit(Register);
        line_confirmPasswod->setObjectName(QString::fromUtf8("line_confirmPasswod"));
        line_confirmPasswod->setGeometry(QRect(150, 580, 200, 30));
        lb_confirmPasswod = new QLabel(Register);
        lb_confirmPasswod->setObjectName(QString::fromUtf8("lb_confirmPasswod"));
        lb_confirmPasswod->setGeometry(QRect(150, 540, 70, 25));
        btn_register = new QPushButton(Register);
        btn_register->setObjectName(QString::fromUtf8("btn_register"));
        btn_register->setGeometry(QRect(190, 630, 90, 35));
        label = new QLabel(Register);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 680, 200, 30));
        btn_emailcode = new QPushButton(Register);
        btn_emailcode->setObjectName(QString::fromUtf8("btn_emailcode"));
        btn_emailcode->setGeometry(QRect(380, 420, 101, 31));
        comboBox = new QComboBox(Register);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(150, 250, 201, 31));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Form", nullptr));
        lb_number->setText(QCoreApplication::translate("Register", "\345\255\246\345\217\267", nullptr));
        lb_name->setText(QCoreApplication::translate("Register", "\345\247\223\345\220\215", nullptr));
        lb_sex->setText(QCoreApplication::translate("Register", "\346\200\247\345\210\253", nullptr));
        lb_email->setText(QCoreApplication::translate("Register", "\351\202\256\347\256\261", nullptr));
        lb_major->setText(QCoreApplication::translate("Register", "\345\255\246\345\216\206\345\261\202\346\254\241", nullptr));
        lb_passwod->setText(QCoreApplication::translate("Register", "\345\257\206\347\240\201", nullptr));
        lb_emailcode->setText(QCoreApplication::translate("Register", "\351\202\256\347\256\261\351\252\214\350\257\201\347\240\201", nullptr));
        lb_confirmPasswod->setText(QCoreApplication::translate("Register", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        btn_register->setText(QCoreApplication::translate("Register", "\346\263\250\345\206\214", nullptr));
        label->setText(QCoreApplication::translate("Register", "\346\217\220\347\244\272\344\277\241\346\201\257", nullptr));
        btn_emailcode->setText(QCoreApplication::translate("Register", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
