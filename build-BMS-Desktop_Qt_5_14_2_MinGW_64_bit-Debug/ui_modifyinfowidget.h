/********************************************************************************
** Form generated from reading UI file 'modifyinfowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYINFOWIDGET_H
#define UI_MODIFYINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyInfoWidget
{
public:

    void setupUi(QWidget *ModifyInfoWidget)
    {
        if (ModifyInfoWidget->objectName().isEmpty())
            ModifyInfoWidget->setObjectName(QString::fromUtf8("ModifyInfoWidget"));
        ModifyInfoWidget->resize(1300, 900);

        retranslateUi(ModifyInfoWidget);

        QMetaObject::connectSlotsByName(ModifyInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *ModifyInfoWidget)
    {
        ModifyInfoWidget->setWindowTitle(QCoreApplication::translate("ModifyInfoWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyInfoWidget: public Ui_ModifyInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYINFOWIDGET_H
