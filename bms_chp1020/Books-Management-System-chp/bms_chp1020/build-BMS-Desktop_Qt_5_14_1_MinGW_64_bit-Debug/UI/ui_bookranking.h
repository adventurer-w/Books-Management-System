/********************************************************************************
** Form generated from reading UI file 'bookranking.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKRANKING_H
#define UI_BOOKRANKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookRanking
{
public:
    QLabel *lb_popularborrow;
    QFrame *line_popular;
    QLabel *lb_categoryrank;
    QFrame *line_classify;
    QFrame *fm_collect;
    QLabel *lb_collect;
    QLabel *lb_collect1;
    QLabel *lb_collect2;
    QLabel *lb_collect3;
    QFrame *fm_man;
    QLabel *lb_man;
    QLabel *lb_man3;
    QLabel *lb_man1;
    QLabel *lb_man2;
    QFrame *fm_woman;
    QLabel *lb_woman;
    QLabel *lb_woman3;
    QLabel *lb_woman2;
    QLabel *lb_woman1;
    QFrame *fm_newbook;
    QLabel *lb_newbook;
    QLabel *lb_new3;
    QLabel *lb_new1;
    QLabel *lb_new2;
    QLabel *lb_book1;
    QLabel *lb_bookname1;
    QLabel *lb_book2;
    QLabel *lb_bookname2;
    QLabel *lb_bookname3;
    QLabel *lb_book3;
    QLabel *lb_book4;
    QLabel *lb_bookname4;
    QLabel *lb_bookname5;
    QLabel *lb_book5;
    QLabel *lb_bookname6;
    QLabel *lb_book6;
    QLabel *lb_bookname7;
    QLabel *lb_book7;

    void setupUi(QWidget *BookRanking)
    {
        if (BookRanking->objectName().isEmpty())
            BookRanking->setObjectName(QString::fromUtf8("BookRanking"));
        BookRanking->resize(1300, 730);
        lb_popularborrow = new QLabel(BookRanking);
        lb_popularborrow->setObjectName(QString::fromUtf8("lb_popularborrow"));
        lb_popularborrow->setGeometry(QRect(30, 0, 140, 40));
        line_popular = new QFrame(BookRanking);
        line_popular->setObjectName(QString::fromUtf8("line_popular"));
        line_popular->setGeometry(QRect(30, 50, 1230, 5));
        line_popular->setFrameShape(QFrame::HLine);
        line_popular->setFrameShadow(QFrame::Sunken);
        lb_categoryrank = new QLabel(BookRanking);
        lb_categoryrank->setObjectName(QString::fromUtf8("lb_categoryrank"));
        lb_categoryrank->setGeometry(QRect(30, 330, 140, 40));
        line_classify = new QFrame(BookRanking);
        line_classify->setObjectName(QString::fromUtf8("line_classify"));
        line_classify->setGeometry(QRect(30, 380, 1230, 5));
        line_classify->setFrameShape(QFrame::HLine);
        line_classify->setFrameShadow(QFrame::Sunken);
        fm_collect = new QFrame(BookRanking);
        fm_collect->setObjectName(QString::fromUtf8("fm_collect"));
        fm_collect->setGeometry(QRect(80, 410, 230, 290));
        fm_collect->setFrameShape(QFrame::StyledPanel);
        fm_collect->setFrameShadow(QFrame::Raised);
        lb_collect = new QLabel(fm_collect);
        lb_collect->setObjectName(QString::fromUtf8("lb_collect"));
        lb_collect->setGeometry(QRect(70, 20, 80, 30));
        lb_collect->setAlignment(Qt::AlignCenter);
        lb_collect1 = new QLabel(fm_collect);
        lb_collect1->setObjectName(QString::fromUtf8("lb_collect1"));
        lb_collect1->setGeometry(QRect(50, 80, 165, 40));
        lb_collect1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lb_collect2 = new QLabel(fm_collect);
        lb_collect2->setObjectName(QString::fromUtf8("lb_collect2"));
        lb_collect2->setGeometry(QRect(50, 140, 165, 40));
        lb_collect2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lb_collect3 = new QLabel(fm_collect);
        lb_collect3->setObjectName(QString::fromUtf8("lb_collect3"));
        lb_collect3->setGeometry(QRect(50, 210, 165, 40));
        lb_collect3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        fm_man = new QFrame(BookRanking);
        fm_man->setObjectName(QString::fromUtf8("fm_man"));
        fm_man->setGeometry(QRect(380, 410, 230, 290));
        fm_man->setFrameShape(QFrame::StyledPanel);
        fm_man->setFrameShadow(QFrame::Raised);
        lb_man = new QLabel(fm_man);
        lb_man->setObjectName(QString::fromUtf8("lb_man"));
        lb_man->setGeometry(QRect(70, 20, 80, 30));
        lb_man->setAlignment(Qt::AlignCenter);
        lb_man3 = new QLabel(fm_man);
        lb_man3->setObjectName(QString::fromUtf8("lb_man3"));
        lb_man3->setGeometry(QRect(50, 210, 165, 40));
        lb_man3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lb_man1 = new QLabel(fm_man);
        lb_man1->setObjectName(QString::fromUtf8("lb_man1"));
        lb_man1->setGeometry(QRect(50, 80, 165, 40));
        lb_man1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lb_man2 = new QLabel(fm_man);
        lb_man2->setObjectName(QString::fromUtf8("lb_man2"));
        lb_man2->setGeometry(QRect(50, 140, 165, 40));
        lb_man2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        fm_woman = new QFrame(BookRanking);
        fm_woman->setObjectName(QString::fromUtf8("fm_woman"));
        fm_woman->setGeometry(QRect(680, 410, 230, 290));
        fm_woman->setFrameShape(QFrame::StyledPanel);
        fm_woman->setFrameShadow(QFrame::Raised);
        lb_woman = new QLabel(fm_woman);
        lb_woman->setObjectName(QString::fromUtf8("lb_woman"));
        lb_woman->setGeometry(QRect(70, 20, 80, 30));
        lb_woman->setAlignment(Qt::AlignCenter);
        lb_woman3 = new QLabel(fm_woman);
        lb_woman3->setObjectName(QString::fromUtf8("lb_woman3"));
        lb_woman3->setGeometry(QRect(50, 210, 165, 40));
        lb_woman3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lb_woman2 = new QLabel(fm_woman);
        lb_woman2->setObjectName(QString::fromUtf8("lb_woman2"));
        lb_woman2->setGeometry(QRect(50, 140, 165, 40));
        lb_woman2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lb_woman1 = new QLabel(fm_woman);
        lb_woman1->setObjectName(QString::fromUtf8("lb_woman1"));
        lb_woman1->setGeometry(QRect(50, 80, 165, 40));
        lb_woman1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        fm_newbook = new QFrame(BookRanking);
        fm_newbook->setObjectName(QString::fromUtf8("fm_newbook"));
        fm_newbook->setGeometry(QRect(980, 410, 230, 290));
        fm_newbook->setFrameShape(QFrame::StyledPanel);
        fm_newbook->setFrameShadow(QFrame::Raised);
        lb_newbook = new QLabel(fm_newbook);
        lb_newbook->setObjectName(QString::fromUtf8("lb_newbook"));
        lb_newbook->setGeometry(QRect(70, 20, 80, 30));
        lb_newbook->setAlignment(Qt::AlignCenter);
        lb_new3 = new QLabel(fm_newbook);
        lb_new3->setObjectName(QString::fromUtf8("lb_new3"));
        lb_new3->setGeometry(QRect(50, 210, 165, 40));
        lb_new3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lb_new1 = new QLabel(fm_newbook);
        lb_new1->setObjectName(QString::fromUtf8("lb_new1"));
        lb_new1->setGeometry(QRect(50, 80, 165, 40));
        lb_new1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lb_new2 = new QLabel(fm_newbook);
        lb_new2->setObjectName(QString::fromUtf8("lb_new2"));
        lb_new2->setGeometry(QRect(50, 140, 165, 40));
        lb_new2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lb_book1 = new QLabel(BookRanking);
        lb_book1->setObjectName(QString::fromUtf8("lb_book1"));
        lb_book1->setGeometry(QRect(30, 80, 130, 170));
        lb_book1->setAlignment(Qt::AlignCenter);
        lb_bookname1 = new QLabel(BookRanking);
        lb_bookname1->setObjectName(QString::fromUtf8("lb_bookname1"));
        lb_bookname1->setGeometry(QRect(30, 260, 110, 30));
        lb_bookname1->setAlignment(Qt::AlignCenter);
        lb_bookname1->setMargin(0);
        lb_book2 = new QLabel(BookRanking);
        lb_book2->setObjectName(QString::fromUtf8("lb_book2"));
        lb_book2->setGeometry(QRect(200, 80, 130, 170));
        lb_book2->setAlignment(Qt::AlignCenter);
        lb_bookname2 = new QLabel(BookRanking);
        lb_bookname2->setObjectName(QString::fromUtf8("lb_bookname2"));
        lb_bookname2->setGeometry(QRect(200, 260, 110, 30));
        lb_bookname2->setAlignment(Qt::AlignCenter);
        lb_bookname3 = new QLabel(BookRanking);
        lb_bookname3->setObjectName(QString::fromUtf8("lb_bookname3"));
        lb_bookname3->setGeometry(QRect(370, 260, 110, 30));
        lb_bookname3->setAlignment(Qt::AlignCenter);
        lb_book3 = new QLabel(BookRanking);
        lb_book3->setObjectName(QString::fromUtf8("lb_book3"));
        lb_book3->setGeometry(QRect(370, 80, 130, 170));
        lb_book3->setAlignment(Qt::AlignCenter);
        lb_book4 = new QLabel(BookRanking);
        lb_book4->setObjectName(QString::fromUtf8("lb_book4"));
        lb_book4->setGeometry(QRect(540, 80, 130, 170));
        lb_book4->setAlignment(Qt::AlignCenter);
        lb_bookname4 = new QLabel(BookRanking);
        lb_bookname4->setObjectName(QString::fromUtf8("lb_bookname4"));
        lb_bookname4->setGeometry(QRect(540, 260, 110, 30));
        lb_bookname4->setAlignment(Qt::AlignCenter);
        lb_bookname5 = new QLabel(BookRanking);
        lb_bookname5->setObjectName(QString::fromUtf8("lb_bookname5"));
        lb_bookname5->setGeometry(QRect(710, 260, 110, 30));
        lb_bookname5->setAlignment(Qt::AlignCenter);
        lb_book5 = new QLabel(BookRanking);
        lb_book5->setObjectName(QString::fromUtf8("lb_book5"));
        lb_book5->setGeometry(QRect(710, 80, 130, 170));
        lb_book5->setAlignment(Qt::AlignCenter);
        lb_bookname6 = new QLabel(BookRanking);
        lb_bookname6->setObjectName(QString::fromUtf8("lb_bookname6"));
        lb_bookname6->setGeometry(QRect(880, 260, 110, 30));
        lb_bookname6->setAlignment(Qt::AlignCenter);
        lb_book6 = new QLabel(BookRanking);
        lb_book6->setObjectName(QString::fromUtf8("lb_book6"));
        lb_book6->setGeometry(QRect(880, 80, 130, 170));
        lb_book6->setAlignment(Qt::AlignCenter);
        lb_bookname7 = new QLabel(BookRanking);
        lb_bookname7->setObjectName(QString::fromUtf8("lb_bookname7"));
        lb_bookname7->setGeometry(QRect(1060, 260, 110, 30));
        lb_bookname7->setAlignment(Qt::AlignCenter);
        lb_book7 = new QLabel(BookRanking);
        lb_book7->setObjectName(QString::fromUtf8("lb_book7"));
        lb_book7->setGeometry(QRect(1060, 80, 130, 170));
        lb_book7->setAlignment(Qt::AlignCenter);

        retranslateUi(BookRanking);

        QMetaObject::connectSlotsByName(BookRanking);
    } // setupUi

    void retranslateUi(QWidget *BookRanking)
    {
        BookRanking->setWindowTitle(QCoreApplication::translate("BookRanking", "Form", nullptr));
        lb_popularborrow->setText(QCoreApplication::translate("BookRanking", "\347\203\255\351\227\250\345\200\237\351\230\205\346\246\234", nullptr));
        lb_categoryrank->setText(QCoreApplication::translate("BookRanking", "\345\210\206\347\261\273\346\216\222\350\241\214\346\246\234", nullptr));
        lb_collect->setText(QCoreApplication::translate("BookRanking", "\351\253\230\345\210\206\346\246\234", nullptr));
        lb_collect1->setText(QCoreApplication::translate("BookRanking", "\345\217\262\350\256\260", nullptr));
        lb_collect2->setText(QCoreApplication::translate("BookRanking", "\345\215\227\344\272\254\345\244\247\345\261\240\346\235\200", nullptr));
        lb_collect3->setText(QCoreApplication::translate("BookRanking", "\351\223\266\346\262\263\345\270\235\345\233\275\357\274\232\345\237\272\345\234\260\344\270\203\346\255\245\346\233\262", nullptr));
        lb_man->setText(QCoreApplication::translate("BookRanking", "\347\224\267\347\224\237\346\246\234\345\215\225", nullptr));
        lb_man3->setText(QCoreApplication::translate("BookRanking", "\351\223\266\346\262\263\345\270\235\345\233\275\357\274\232\345\237\272\345\234\260\344\270\203\346\255\245\346\233\262", nullptr));
        lb_man1->setText(QCoreApplication::translate("BookRanking", "\345\217\262\350\256\260", nullptr));
        lb_man2->setText(QCoreApplication::translate("BookRanking", "\345\215\227\344\272\254\345\244\247\345\261\240\346\235\200", nullptr));
        lb_woman->setText(QCoreApplication::translate("BookRanking", "\345\245\263\347\224\237\346\246\234\345\215\225", nullptr));
        lb_woman3->setText(QCoreApplication::translate("BookRanking", "\351\223\266\346\262\263\345\270\235\345\233\275\357\274\232\345\237\272\345\234\260\344\270\203\346\255\245\346\233\262", nullptr));
        lb_woman2->setText(QCoreApplication::translate("BookRanking", "\345\215\227\344\272\254\345\244\247\345\261\240\346\235\200", nullptr));
        lb_woman1->setText(QCoreApplication::translate("BookRanking", "\345\217\262\350\256\260", nullptr));
        lb_newbook->setText(QCoreApplication::translate("BookRanking", "\346\226\260\344\271\246\346\216\250\350\215\220", nullptr));
        lb_new3->setText(QCoreApplication::translate("BookRanking", "\351\223\266\346\262\263\345\270\235\345\233\275\357\274\232\345\237\272\345\234\260\344\270\203\346\255\245\346\233\262", nullptr));
        lb_new1->setText(QCoreApplication::translate("BookRanking", "\345\217\262\350\256\260", nullptr));
        lb_new2->setText(QCoreApplication::translate("BookRanking", "\345\215\227\344\272\254\345\244\247\345\261\240\346\235\200", nullptr));
        lb_book1->setText(QCoreApplication::translate("BookRanking", "TextLabel", nullptr));
        lb_bookname1->setText(QCoreApplication::translate("BookRanking", "TextLabel", nullptr));
        lb_book2->setText(QCoreApplication::translate("BookRanking", "TextLabel", nullptr));
        lb_bookname2->setText(QCoreApplication::translate("BookRanking", "TextLabel", nullptr));
        lb_bookname3->setText(QCoreApplication::translate("BookRanking", "TextLabel", nullptr));
        lb_book3->setText(QCoreApplication::translate("BookRanking", "TextLabel", nullptr));
        lb_book4->setText(QCoreApplication::translate("BookRanking", "TextLabel", nullptr));
        lb_bookname4->setText(QCoreApplication::translate("BookRanking", "TextLabel", nullptr));
        lb_bookname5->setText(QCoreApplication::translate("BookRanking", "TextLabel", nullptr));
        lb_book5->setText(QCoreApplication::translate("BookRanking", "TextLabel", nullptr));
        lb_bookname6->setText(QCoreApplication::translate("BookRanking", "TextLabel", nullptr));
        lb_book6->setText(QCoreApplication::translate("BookRanking", "TextLabel", nullptr));
        lb_bookname7->setText(QCoreApplication::translate("BookRanking", "TextLabel", nullptr));
        lb_book7->setText(QCoreApplication::translate("BookRanking", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookRanking: public Ui_BookRanking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKRANKING_H
