/********************************************************************************
** Form generated from reading UI file 'modifyinfowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYINFOWIDGET_H
#define UI_MODIFYINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyInfoWidget
{
public:
    QLabel *lb_modifyInfo;
    QFrame *line;
    QLabel *lb_number;
    QLineEdit *line_number;
    QLineEdit *line_name;
    QLabel *lb_name;
    QComboBox *box_sex;
    QLabel *lb_sex;
    QLabel *lb_mojor;
    QLineEdit *line_major;
    QLineEdit *line_major_2;
    QLabel *lb_mojor_2;
    QPushButton *btn_modifyInfo;
    QLabel *lb_modifyPassword;
    QLineEdit *line_password;
    QLabel *lb_password;
    QLabel *lb_confirmPassword;
    QLineEdit *line_confirmPassword;
    QPushButton *btn_modifyPassword;

    void setupUi(QWidget *ModifyInfoWidget)
    {
        if (ModifyInfoWidget->objectName().isEmpty())
            ModifyInfoWidget->setObjectName(QString::fromUtf8("ModifyInfoWidget"));
        ModifyInfoWidget->resize(1300, 900);
        lb_modifyInfo = new QLabel(ModifyInfoWidget);
        lb_modifyInfo->setObjectName(QString::fromUtf8("lb_modifyInfo"));
        lb_modifyInfo->setGeometry(QRect(270, 90, 90, 40));
        line = new QFrame(ModifyInfoWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(650, 150, 10, 600));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        lb_number = new QLabel(ModifyInfoWidget);
        lb_number->setObjectName(QString::fromUtf8("lb_number"));
        lb_number->setGeometry(QRect(120, 160, 80, 40));
        line_number = new QLineEdit(ModifyInfoWidget);
        line_number->setObjectName(QString::fromUtf8("line_number"));
        line_number->setGeometry(QRect(120, 220, 400, 40));
        line_name = new QLineEdit(ModifyInfoWidget);
        line_name->setObjectName(QString::fromUtf8("line_name"));
        line_name->setGeometry(QRect(120, 340, 400, 40));
        lb_name = new QLabel(ModifyInfoWidget);
        lb_name->setObjectName(QString::fromUtf8("lb_name"));
        lb_name->setGeometry(QRect(120, 280, 80, 40));
        box_sex = new QComboBox(ModifyInfoWidget);
        box_sex->setObjectName(QString::fromUtf8("box_sex"));
        box_sex->setGeometry(QRect(220, 400, 300, 40));
        lb_sex = new QLabel(ModifyInfoWidget);
        lb_sex->setObjectName(QString::fromUtf8("lb_sex"));
        lb_sex->setGeometry(QRect(120, 400, 80, 40));
        lb_mojor = new QLabel(ModifyInfoWidget);
        lb_mojor->setObjectName(QString::fromUtf8("lb_mojor"));
        lb_mojor->setGeometry(QRect(120, 460, 80, 40));
        line_major = new QLineEdit(ModifyInfoWidget);
        line_major->setObjectName(QString::fromUtf8("line_major"));
        line_major->setGeometry(QRect(120, 520, 400, 40));
        line_major_2 = new QLineEdit(ModifyInfoWidget);
        line_major_2->setObjectName(QString::fromUtf8("line_major_2"));
        line_major_2->setGeometry(QRect(120, 640, 400, 40));
        lb_mojor_2 = new QLabel(ModifyInfoWidget);
        lb_mojor_2->setObjectName(QString::fromUtf8("lb_mojor_2"));
        lb_mojor_2->setGeometry(QRect(120, 580, 80, 40));
        btn_modifyInfo = new QPushButton(ModifyInfoWidget);
        btn_modifyInfo->setObjectName(QString::fromUtf8("btn_modifyInfo"));
        btn_modifyInfo->setGeometry(QRect(260, 740, 120, 40));
        lb_modifyPassword = new QLabel(ModifyInfoWidget);
        lb_modifyPassword->setObjectName(QString::fromUtf8("lb_modifyPassword"));
        lb_modifyPassword->setGeometry(QRect(930, 90, 90, 40));
        line_password = new QLineEdit(ModifyInfoWidget);
        line_password->setObjectName(QString::fromUtf8("line_password"));
        line_password->setGeometry(QRect(790, 220, 400, 40));
        lb_password = new QLabel(ModifyInfoWidget);
        lb_password->setObjectName(QString::fromUtf8("lb_password"));
        lb_password->setGeometry(QRect(790, 160, 80, 40));
        lb_confirmPassword = new QLabel(ModifyInfoWidget);
        lb_confirmPassword->setObjectName(QString::fromUtf8("lb_confirmPassword"));
        lb_confirmPassword->setGeometry(QRect(790, 280, 80, 40));
        line_confirmPassword = new QLineEdit(ModifyInfoWidget);
        line_confirmPassword->setObjectName(QString::fromUtf8("line_confirmPassword"));
        line_confirmPassword->setGeometry(QRect(790, 340, 400, 40));
        btn_modifyPassword = new QPushButton(ModifyInfoWidget);
        btn_modifyPassword->setObjectName(QString::fromUtf8("btn_modifyPassword"));
        btn_modifyPassword->setGeometry(QRect(920, 740, 120, 40));

        retranslateUi(ModifyInfoWidget);

        QMetaObject::connectSlotsByName(ModifyInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *ModifyInfoWidget)
    {
        ModifyInfoWidget->setWindowTitle(QCoreApplication::translate("ModifyInfoWidget", "Form", nullptr));
        lb_modifyInfo->setText(QCoreApplication::translate("ModifyInfoWidget", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        lb_number->setText(QCoreApplication::translate("ModifyInfoWidget", "\345\255\246\345\217\267", nullptr));
        lb_name->setText(QCoreApplication::translate("ModifyInfoWidget", "\345\247\223\345\220\215", nullptr));
        lb_sex->setText(QCoreApplication::translate("ModifyInfoWidget", "\346\200\247\345\210\253", nullptr));
        lb_mojor->setText(QCoreApplication::translate("ModifyInfoWidget", "\344\270\223\344\270\232", nullptr));
        lb_mojor_2->setText(QCoreApplication::translate("ModifyInfoWidget", "\351\202\256\347\256\261", nullptr));
        btn_modifyInfo->setText(QCoreApplication::translate("ModifyInfoWidget", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        lb_modifyPassword->setText(QCoreApplication::translate("ModifyInfoWidget", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        lb_password->setText(QCoreApplication::translate("ModifyInfoWidget", "\345\257\206\347\240\201", nullptr));
        lb_confirmPassword->setText(QCoreApplication::translate("ModifyInfoWidget", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        btn_modifyPassword->setText(QCoreApplication::translate("ModifyInfoWidget", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyInfoWidget: public Ui_ModifyInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYINFOWIDGET_H
