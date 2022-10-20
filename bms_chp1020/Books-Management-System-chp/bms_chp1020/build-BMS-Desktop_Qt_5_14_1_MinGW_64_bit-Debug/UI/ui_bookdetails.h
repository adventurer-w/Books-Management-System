/********************************************************************************
** Form generated from reading UI file 'bookdetails.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKDETAILS_H
#define UI_BOOKDETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookDetails
{
public:
    QLabel *lb_bookname1;
    QFrame *line;
    QLabel *lb_bookphoto;
    QLabel *lb_intro;
    QLabel *lb_intro_txt;
    QLabel *lb_bookname2;
    QLabel *lb_author;
    QLabel *lb_publish;
    QLabel *lb_ISBN;
    QLabel *lb_collect;
    QLabel *lb_grade;
    QLabel *lb_remain;
    QLabel *lb_publishtime;
    QLabel *lb_classify;
    QLabel *lb_bookposition;
    QLabel *lb_historyborrow;
    QLabel *lb_classify_txt;
    QLabel *lb_remain_txt;
    QLabel *lb_publishtime_txt;
    QLabel *lb_grade_txt;
    QLabel *lb_historyborrow_txt;
    QLabel *lb_ISBN_2;
    QLabel *lb_bookposition_txt;
    QLabel *lb_collect_txt;
    QLabel *lb_publish_2;
    QLabel *lb_author_2;
    QPushButton *btn_star;
    QPushButton *btn_borrow;
    QPushButton *btn_reserve;
    QPushButton *btn_back;

    void setupUi(QWidget *BookDetails)
    {
        if (BookDetails->objectName().isEmpty())
            BookDetails->setObjectName(QString::fromUtf8("BookDetails"));
        BookDetails->resize(1300, 900);
        lb_bookname1 = new QLabel(BookDetails);
        lb_bookname1->setObjectName(QString::fromUtf8("lb_bookname1"));
        lb_bookname1->setGeometry(QRect(50, 109, 500, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(18);
        lb_bookname1->setFont(font);
        line = new QFrame(BookDetails);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(50, 170, 1230, 5));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lb_bookphoto = new QLabel(BookDetails);
        lb_bookphoto->setObjectName(QString::fromUtf8("lb_bookphoto"));
        lb_bookphoto->setGeometry(QRect(80, 220, 200, 330));
        lb_intro = new QLabel(BookDetails);
        lb_intro->setObjectName(QString::fromUtf8("lb_intro"));
        lb_intro->setGeometry(QRect(70, 580, 80, 30));
        lb_intro_txt = new QLabel(BookDetails);
        lb_intro_txt->setObjectName(QString::fromUtf8("lb_intro_txt"));
        lb_intro_txt->setGeometry(QRect(70, 700, 2200, 150));
        lb_bookname2 = new QLabel(BookDetails);
        lb_bookname2->setObjectName(QString::fromUtf8("lb_bookname2"));
        lb_bookname2->setGeometry(QRect(400, 220, 200, 30));
        lb_author = new QLabel(BookDetails);
        lb_author->setObjectName(QString::fromUtf8("lb_author"));
        lb_author->setGeometry(QRect(400, 250, 130, 30));
        lb_publish = new QLabel(BookDetails);
        lb_publish->setObjectName(QString::fromUtf8("lb_publish"));
        lb_publish->setGeometry(QRect(400, 280, 130, 30));
        lb_ISBN = new QLabel(BookDetails);
        lb_ISBN->setObjectName(QString::fromUtf8("lb_ISBN"));
        lb_ISBN->setGeometry(QRect(400, 310, 130, 30));
        lb_collect = new QLabel(BookDetails);
        lb_collect->setObjectName(QString::fromUtf8("lb_collect"));
        lb_collect->setGeometry(QRect(400, 460, 200, 30));
        lb_grade = new QLabel(BookDetails);
        lb_grade->setObjectName(QString::fromUtf8("lb_grade"));
        lb_grade->setGeometry(QRect(400, 370, 130, 30));
        lb_remain = new QLabel(BookDetails);
        lb_remain->setObjectName(QString::fromUtf8("lb_remain"));
        lb_remain->setGeometry(QRect(400, 430, 130, 30));
        lb_publishtime = new QLabel(BookDetails);
        lb_publishtime->setObjectName(QString::fromUtf8("lb_publishtime"));
        lb_publishtime->setGeometry(QRect(400, 400, 130, 30));
        lb_classify = new QLabel(BookDetails);
        lb_classify->setObjectName(QString::fromUtf8("lb_classify"));
        lb_classify->setGeometry(QRect(400, 340, 200, 30));
        lb_bookposition = new QLabel(BookDetails);
        lb_bookposition->setObjectName(QString::fromUtf8("lb_bookposition"));
        lb_bookposition->setGeometry(QRect(400, 520, 200, 30));
        lb_historyborrow = new QLabel(BookDetails);
        lb_historyborrow->setObjectName(QString::fromUtf8("lb_historyborrow"));
        lb_historyborrow->setGeometry(QRect(400, 490, 200, 30));
        lb_classify_txt = new QLabel(BookDetails);
        lb_classify_txt->setObjectName(QString::fromUtf8("lb_classify_txt"));
        lb_classify_txt->setGeometry(QRect(660, 340, 280, 30));
        lb_remain_txt = new QLabel(BookDetails);
        lb_remain_txt->setObjectName(QString::fromUtf8("lb_remain_txt"));
        lb_remain_txt->setGeometry(QRect(660, 430, 280, 30));
        lb_publishtime_txt = new QLabel(BookDetails);
        lb_publishtime_txt->setObjectName(QString::fromUtf8("lb_publishtime_txt"));
        lb_publishtime_txt->setGeometry(QRect(660, 400, 280, 30));
        lb_grade_txt = new QLabel(BookDetails);
        lb_grade_txt->setObjectName(QString::fromUtf8("lb_grade_txt"));
        lb_grade_txt->setGeometry(QRect(660, 370, 280, 30));
        lb_historyborrow_txt = new QLabel(BookDetails);
        lb_historyborrow_txt->setObjectName(QString::fromUtf8("lb_historyborrow_txt"));
        lb_historyborrow_txt->setGeometry(QRect(660, 490, 280, 30));
        lb_ISBN_2 = new QLabel(BookDetails);
        lb_ISBN_2->setObjectName(QString::fromUtf8("lb_ISBN_2"));
        lb_ISBN_2->setGeometry(QRect(660, 310, 280, 30));
        lb_bookposition_txt = new QLabel(BookDetails);
        lb_bookposition_txt->setObjectName(QString::fromUtf8("lb_bookposition_txt"));
        lb_bookposition_txt->setGeometry(QRect(660, 520, 280, 30));
        lb_collect_txt = new QLabel(BookDetails);
        lb_collect_txt->setObjectName(QString::fromUtf8("lb_collect_txt"));
        lb_collect_txt->setGeometry(QRect(660, 460, 280, 30));
        lb_publish_2 = new QLabel(BookDetails);
        lb_publish_2->setObjectName(QString::fromUtf8("lb_publish_2"));
        lb_publish_2->setGeometry(QRect(660, 280, 280, 30));
        lb_author_2 = new QLabel(BookDetails);
        lb_author_2->setObjectName(QString::fromUtf8("lb_author_2"));
        lb_author_2->setGeometry(QRect(660, 250, 280, 30));
        btn_star = new QPushButton(BookDetails);
        btn_star->setObjectName(QString::fromUtf8("btn_star"));
        btn_star->setGeometry(QRect(990, 280, 100, 40));
        btn_borrow = new QPushButton(BookDetails);
        btn_borrow->setObjectName(QString::fromUtf8("btn_borrow"));
        btn_borrow->setGeometry(QRect(990, 370, 100, 40));
        btn_reserve = new QPushButton(BookDetails);
        btn_reserve->setObjectName(QString::fromUtf8("btn_reserve"));
        btn_reserve->setGeometry(QRect(990, 460, 100, 40));
        btn_back = new QPushButton(BookDetails);
        btn_back->setObjectName(QString::fromUtf8("btn_back"));
        btn_back->setGeometry(QRect(0, 90, 40, 40));

        retranslateUi(BookDetails);

        QMetaObject::connectSlotsByName(BookDetails);
    } // setupUi

    void retranslateUi(QWidget *BookDetails)
    {
        BookDetails->setWindowTitle(QCoreApplication::translate("BookDetails", "Form", nullptr));
        lb_bookname1->setText(QCoreApplication::translate("BookDetails", "TextLabel", nullptr));
        lb_bookphoto->setText(QCoreApplication::translate("BookDetails", "TextLabel", nullptr));
        lb_intro->setText(QCoreApplication::translate("BookDetails", "\347\256\200\344\273\213", nullptr));
        lb_intro_txt->setText(QCoreApplication::translate("BookDetails", "TextLabel", nullptr));
        lb_bookname2->setText(QCoreApplication::translate("BookDetails", "TextLabel", nullptr));
        lb_author->setText(QCoreApplication::translate("BookDetails", "\344\275\234\350\200\205", nullptr));
        lb_publish->setText(QCoreApplication::translate("BookDetails", "\345\207\272\347\211\210\347\244\276", nullptr));
        lb_ISBN->setText(QCoreApplication::translate("BookDetails", "ISBN", nullptr));
        lb_collect->setText(QCoreApplication::translate("BookDetails", "\346\224\266\350\227\217\346\225\260", nullptr));
        lb_grade->setText(QCoreApplication::translate("BookDetails", "\350\257\204\345\210\206", nullptr));
        lb_remain->setText(QCoreApplication::translate("BookDetails", "\345\211\251\344\275\231/\346\200\273\345\272\223\345\255\230", nullptr));
        lb_publishtime->setText(QCoreApplication::translate("BookDetails", "\345\207\272\347\211\210\346\227\266\351\227\264", nullptr));
        lb_classify->setText(QCoreApplication::translate("BookDetails", "\345\210\206\347\261\273", nullptr));
        lb_bookposition->setText(QCoreApplication::translate("BookDetails", "\345\233\276\344\271\246\344\275\215\347\275\256", nullptr));
        lb_historyborrow->setText(QCoreApplication::translate("BookDetails", "\345\216\206\345\217\262\345\200\237\351\230\205\346\225\260", nullptr));
        lb_classify_txt->setText(QCoreApplication::translate("BookDetails", "TextLabel", nullptr));
        lb_remain_txt->setText(QCoreApplication::translate("BookDetails", "TextLabel", nullptr));
        lb_publishtime_txt->setText(QCoreApplication::translate("BookDetails", "TextLabel", nullptr));
        lb_grade_txt->setText(QCoreApplication::translate("BookDetails", "TextLabel", nullptr));
        lb_historyborrow_txt->setText(QCoreApplication::translate("BookDetails", "TextLabel", nullptr));
        lb_ISBN_2->setText(QCoreApplication::translate("BookDetails", "TextLabel", nullptr));
        lb_bookposition_txt->setText(QCoreApplication::translate("BookDetails", "TextLabel", nullptr));
        lb_collect_txt->setText(QCoreApplication::translate("BookDetails", "TextLabel", nullptr));
        lb_publish_2->setText(QCoreApplication::translate("BookDetails", "TextLabel", nullptr));
        lb_author_2->setText(QCoreApplication::translate("BookDetails", "TextLabel", nullptr));
        btn_star->setText(QCoreApplication::translate("BookDetails", "\346\224\266\350\227\217+", nullptr));
        btn_borrow->setText(QCoreApplication::translate("BookDetails", "\345\200\237\351\230\205+", nullptr));
        btn_reserve->setText(QCoreApplication::translate("BookDetails", "\351\242\204\347\272\246+", nullptr));
        btn_back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BookDetails: public Ui_BookDetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKDETAILS_H
