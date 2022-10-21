/********************************************************************************
** Form generated from reading UI file 'modifybookcategory.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYBOOKCATEGORY_H
#define UI_MODIFYBOOKCATEGORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyBookCategory
{
public:
    QLineEdit *line_addclassify;
    QPushButton *btn_addclassify;
    QTableView *tb;

    void setupUi(QWidget *ModifyBookCategory)
    {
        if (ModifyBookCategory->objectName().isEmpty())
            ModifyBookCategory->setObjectName(QString::fromUtf8("ModifyBookCategory"));
        ModifyBookCategory->resize(262, 492);
        line_addclassify = new QLineEdit(ModifyBookCategory);
        line_addclassify->setObjectName(QString::fromUtf8("line_addclassify"));
        line_addclassify->setGeometry(QRect(100, 10, 131, 30));
        btn_addclassify = new QPushButton(ModifyBookCategory);
        btn_addclassify->setObjectName(QString::fromUtf8("btn_addclassify"));
        btn_addclassify->setGeometry(QRect(0, 10, 90, 30));
        tb = new QTableView(ModifyBookCategory);
        tb->setObjectName(QString::fromUtf8("tb"));
        tb->setGeometry(QRect(0, 60, 230, 390));

        retranslateUi(ModifyBookCategory);

        QMetaObject::connectSlotsByName(ModifyBookCategory);
    } // setupUi

    void retranslateUi(QWidget *ModifyBookCategory)
    {
        ModifyBookCategory->setWindowTitle(QCoreApplication::translate("ModifyBookCategory", "Form", nullptr));
        btn_addclassify->setText(QCoreApplication::translate("ModifyBookCategory", "\346\267\273\345\212\240\345\210\206\347\261\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyBookCategory: public Ui_ModifyBookCategory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYBOOKCATEGORY_H
