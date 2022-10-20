/********************************************************************************
** Form generated from reading UI file 'adminmodifybookdetail.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMODIFYBOOKDETAIL_H
#define UI_ADMINMODIFYBOOKDETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminModifyBookDetail
{
public:
    QLabel *lb_bookposition;
    QLabel *lb_ISBN;
    QLabel *lb_publish;
    QLabel *lb_remain;
    QLabel *lb_intro;
    QLabel *lb_author;
    QLabel *lb_publishtime;
    QLabel *lb_classify;
    QLabel *lb_bookphoto;
    QLabel *lb_bookname;
    QLineEdit *line_bookname;
    QLineEdit *line_author;
    QLineEdit *line_publish;
    QLineEdit *line_ISBN;
    QLineEdit *line_classify;
    QLineEdit *line_publishtime;
    QLineEdit *line_remain;
    QLineEdit *line_bookposition;
    QPushButton *book_pushButton;
    QPushButton *btn_modifyimage;
    QTextEdit *lineEdit;
    QPushButton *btn_back;

    void setupUi(QWidget *AdminModifyBookDetail)
    {
        if (AdminModifyBookDetail->objectName().isEmpty())
            AdminModifyBookDetail->setObjectName(QString::fromUtf8("AdminModifyBookDetail"));
        AdminModifyBookDetail->resize(1600, 900);
        lb_bookposition = new QLabel(AdminModifyBookDetail);
        lb_bookposition->setObjectName(QString::fromUtf8("lb_bookposition"));
        lb_bookposition->setGeometry(QRect(440, 380, 200, 30));
        lb_ISBN = new QLabel(AdminModifyBookDetail);
        lb_ISBN->setObjectName(QString::fromUtf8("lb_ISBN"));
        lb_ISBN->setGeometry(QRect(440, 220, 140, 30));
        lb_publish = new QLabel(AdminModifyBookDetail);
        lb_publish->setObjectName(QString::fromUtf8("lb_publish"));
        lb_publish->setGeometry(QRect(440, 180, 130, 30));
        lb_remain = new QLabel(AdminModifyBookDetail);
        lb_remain->setObjectName(QString::fromUtf8("lb_remain"));
        lb_remain->setGeometry(QRect(440, 340, 130, 30));
        lb_intro = new QLabel(AdminModifyBookDetail);
        lb_intro->setObjectName(QString::fromUtf8("lb_intro"));
        lb_intro->setGeometry(QRect(110, 480, 80, 30));
        lb_author = new QLabel(AdminModifyBookDetail);
        lb_author->setObjectName(QString::fromUtf8("lb_author"));
        lb_author->setGeometry(QRect(440, 140, 130, 30));
        lb_publishtime = new QLabel(AdminModifyBookDetail);
        lb_publishtime->setObjectName(QString::fromUtf8("lb_publishtime"));
        lb_publishtime->setGeometry(QRect(440, 300, 130, 30));
        lb_classify = new QLabel(AdminModifyBookDetail);
        lb_classify->setObjectName(QString::fromUtf8("lb_classify"));
        lb_classify->setGeometry(QRect(440, 260, 200, 30));
        lb_bookphoto = new QLabel(AdminModifyBookDetail);
        lb_bookphoto->setObjectName(QString::fromUtf8("lb_bookphoto"));
        lb_bookphoto->setGeometry(QRect(120, 80, 200, 330));
        lb_bookname = new QLabel(AdminModifyBookDetail);
        lb_bookname->setObjectName(QString::fromUtf8("lb_bookname"));
        lb_bookname->setGeometry(QRect(440, 100, 200, 30));
        line_bookname = new QLineEdit(AdminModifyBookDetail);
        line_bookname->setObjectName(QString::fromUtf8("line_bookname"));
        line_bookname->setGeometry(QRect(700, 100, 280, 30));
        line_author = new QLineEdit(AdminModifyBookDetail);
        line_author->setObjectName(QString::fromUtf8("line_author"));
        line_author->setGeometry(QRect(700, 140, 280, 30));
        line_publish = new QLineEdit(AdminModifyBookDetail);
        line_publish->setObjectName(QString::fromUtf8("line_publish"));
        line_publish->setGeometry(QRect(700, 180, 280, 30));
        line_ISBN = new QLineEdit(AdminModifyBookDetail);
        line_ISBN->setObjectName(QString::fromUtf8("line_ISBN"));
        line_ISBN->setGeometry(QRect(700, 220, 280, 30));
        line_classify = new QLineEdit(AdminModifyBookDetail);
        line_classify->setObjectName(QString::fromUtf8("line_classify"));
        line_classify->setGeometry(QRect(700, 260, 280, 30));
        line_publishtime = new QLineEdit(AdminModifyBookDetail);
        line_publishtime->setObjectName(QString::fromUtf8("line_publishtime"));
        line_publishtime->setGeometry(QRect(700, 300, 280, 30));
        line_remain = new QLineEdit(AdminModifyBookDetail);
        line_remain->setObjectName(QString::fromUtf8("line_remain"));
        line_remain->setGeometry(QRect(700, 340, 280, 30));
        line_bookposition = new QLineEdit(AdminModifyBookDetail);
        line_bookposition->setObjectName(QString::fromUtf8("line_bookposition"));
        line_bookposition->setGeometry(QRect(700, 380, 280, 30));
        book_pushButton = new QPushButton(AdminModifyBookDetail);
        book_pushButton->setObjectName(QString::fromUtf8("book_pushButton"));
        book_pushButton->setGeometry(QRect(590, 810, 100, 40));
        btn_modifyimage = new QPushButton(AdminModifyBookDetail);
        btn_modifyimage->setObjectName(QString::fromUtf8("btn_modifyimage"));
        btn_modifyimage->setGeometry(QRect(170, 430, 90, 30));
        lineEdit = new QTextEdit(AdminModifyBookDetail);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 550, 1050, 200));
        btn_back = new QPushButton(AdminModifyBookDetail);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(0, 10, 40, 40));

        retranslateUi(AdminModifyBookDetail);

        QMetaObject::connectSlotsByName(AdminModifyBookDetail);
    } // setupUi

    void retranslateUi(QWidget *AdminModifyBookDetail)
    {
        AdminModifyBookDetail->setWindowTitle(QCoreApplication::translate("AdminModifyBookDetail", "Form", nullptr));
        lb_bookposition->setText(QCoreApplication::translate("AdminModifyBookDetail", "\345\233\276\344\271\246\344\275\215\347\275\256", nullptr));
        lb_ISBN->setText(QCoreApplication::translate("AdminModifyBookDetail", "ISBN", nullptr));
        lb_publish->setText(QCoreApplication::translate("AdminModifyBookDetail", "\345\207\272\347\211\210\347\244\276", nullptr));
        lb_remain->setText(QCoreApplication::translate("AdminModifyBookDetail", "\346\200\273\345\272\223\345\255\230\346\225\260", nullptr));
        lb_intro->setText(QCoreApplication::translate("AdminModifyBookDetail", "\347\256\200\344\273\213", nullptr));
        lb_author->setText(QCoreApplication::translate("AdminModifyBookDetail", "\344\275\234\350\200\205", nullptr));
        lb_publishtime->setText(QCoreApplication::translate("AdminModifyBookDetail", "\345\207\272\347\211\210\346\227\266\351\227\264", nullptr));
        lb_classify->setText(QCoreApplication::translate("AdminModifyBookDetail", "\345\210\206\347\261\273", nullptr));
        lb_bookphoto->setText(QCoreApplication::translate("AdminModifyBookDetail", "TextLabel", nullptr));
        lb_bookname->setText(QCoreApplication::translate("AdminModifyBookDetail", "\344\271\246\345\220\215", nullptr));
        book_pushButton->setText(QCoreApplication::translate("AdminModifyBookDetail", "\347\241\256\350\256\244", nullptr));
        btn_modifyimage->setText(QCoreApplication::translate("AdminModifyBookDetail", "\344\277\256\346\224\271\345\233\276\347\211\207", nullptr));
        btn_back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AdminModifyBookDetail: public Ui_AdminModifyBookDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMODIFYBOOKDETAIL_H
