/********************************************************************************
** Form generated from reading UI file 'borrowinstruction.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BORROWINSTRUCTION_H
#define UI_BORROWINSTRUCTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BorrowInstruction
{
public:
    QLabel *lb_instruction;
    QFrame *line;
    QLabel *lb_borrowlimited;
    QTextEdit *textEdit;
    QLabel *lb_teacherlimited;
    QLabel *lb_undergraduate;
    QLabel *lb_doctor;
    QLabel *lb_master;
    QPushButton *btn_modifyConfirm;
    QLineEdit *line_teacher;
    QLineEdit *line_undergraduate;
    QLineEdit *line_doctor;
    QLineEdit *line_master;

    void setupUi(QWidget *BorrowInstruction)
    {
        if (BorrowInstruction->objectName().isEmpty())
            BorrowInstruction->setObjectName(QString::fromUtf8("BorrowInstruction"));
        BorrowInstruction->resize(800, 600);
        lb_instruction = new QLabel(BorrowInstruction);
        lb_instruction->setObjectName(QString::fromUtf8("lb_instruction"));
        lb_instruction->setGeometry(QRect(160, 30, 80, 30));
        line = new QFrame(BorrowInstruction);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(400, 30, 5, 540));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        lb_borrowlimited = new QLabel(BorrowInstruction);
        lb_borrowlimited->setObjectName(QString::fromUtf8("lb_borrowlimited"));
        lb_borrowlimited->setGeometry(QRect(560, 30, 80, 30));
        textEdit = new QTextEdit(BorrowInstruction);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 70, 340, 480));
        lb_teacherlimited = new QLabel(BorrowInstruction);
        lb_teacherlimited->setObjectName(QString::fromUtf8("lb_teacherlimited"));
        lb_teacherlimited->setGeometry(QRect(480, 70, 80, 30));
        lb_undergraduate = new QLabel(BorrowInstruction);
        lb_undergraduate->setObjectName(QString::fromUtf8("lb_undergraduate"));
        lb_undergraduate->setGeometry(QRect(480, 120, 80, 30));
        lb_doctor = new QLabel(BorrowInstruction);
        lb_doctor->setObjectName(QString::fromUtf8("lb_doctor"));
        lb_doctor->setGeometry(QRect(480, 220, 80, 30));
        lb_master = new QLabel(BorrowInstruction);
        lb_master->setObjectName(QString::fromUtf8("lb_master"));
        lb_master->setGeometry(QRect(480, 170, 80, 30));
        btn_modifyConfirm = new QPushButton(BorrowInstruction);
        btn_modifyConfirm->setObjectName(QString::fromUtf8("btn_modifyConfirm"));
        btn_modifyConfirm->setGeometry(QRect(540, 290, 90, 30));
        line_teacher = new QLineEdit(BorrowInstruction);
        line_teacher->setObjectName(QString::fromUtf8("line_teacher"));
        line_teacher->setGeometry(QRect(590, 70, 120, 30));
        line_undergraduate = new QLineEdit(BorrowInstruction);
        line_undergraduate->setObjectName(QString::fromUtf8("line_undergraduate"));
        line_undergraduate->setGeometry(QRect(590, 120, 120, 30));
        line_doctor = new QLineEdit(BorrowInstruction);
        line_doctor->setObjectName(QString::fromUtf8("line_doctor"));
        line_doctor->setGeometry(QRect(590, 220, 120, 30));
        line_master = new QLineEdit(BorrowInstruction);
        line_master->setObjectName(QString::fromUtf8("line_master"));
        line_master->setGeometry(QRect(590, 170, 120, 30));

        retranslateUi(BorrowInstruction);

        QMetaObject::connectSlotsByName(BorrowInstruction);
    } // setupUi

    void retranslateUi(QWidget *BorrowInstruction)
    {
        BorrowInstruction->setWindowTitle(QCoreApplication::translate("BorrowInstruction", "Form", nullptr));
        lb_instruction->setText(QCoreApplication::translate("BorrowInstruction", "\347\224\250\346\210\267\351\241\273\347\237\245", nullptr));
        lb_borrowlimited->setText(QCoreApplication::translate("BorrowInstruction", "\345\200\237\351\230\205\344\270\212\351\231\220", nullptr));
        lb_teacherlimited->setText(QCoreApplication::translate("BorrowInstruction", "\350\200\201\345\270\210", nullptr));
        lb_undergraduate->setText(QCoreApplication::translate("BorrowInstruction", "\346\234\254\347\247\221\347\224\237", nullptr));
        lb_doctor->setText(QCoreApplication::translate("BorrowInstruction", "\345\215\232\345\243\253\347\224\237", nullptr));
        lb_master->setText(QCoreApplication::translate("BorrowInstruction", "\347\241\225\345\243\253\347\224\237", nullptr));
        btn_modifyConfirm->setText(QCoreApplication::translate("BorrowInstruction", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BorrowInstruction: public Ui_BorrowInstruction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BORROWINSTRUCTION_H
