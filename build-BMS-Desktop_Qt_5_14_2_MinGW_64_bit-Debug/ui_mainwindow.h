/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_quit;
    QAction *action;
    QAction *action_2;
    QWidget *centralwidget;
    QPushButton *btn_logout;
    QPushButton *btn_modifyInfo;
    QPushButton *btn_queryBook;
    QPushButton *btn_userProfile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 900);
        MainWindow->setMaximumSize(QSize(166666, 166666));
        action_quit = new QAction(MainWindow);
        action_quit->setObjectName(QString::fromUtf8("action_quit"));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_logout = new QPushButton(centralwidget);
        btn_logout->setObjectName(QString::fromUtf8("btn_logout"));
        btn_logout->setGeometry(QRect(30, 400, 200, 50));
        btn_modifyInfo = new QPushButton(centralwidget);
        btn_modifyInfo->setObjectName(QString::fromUtf8("btn_modifyInfo"));
        btn_modifyInfo->setGeometry(QRect(30, 300, 200, 50));
        btn_queryBook = new QPushButton(centralwidget);
        btn_queryBook->setObjectName(QString::fromUtf8("btn_queryBook"));
        btn_queryBook->setGeometry(QRect(30, 350, 200, 50));
        btn_userProfile = new QPushButton(centralwidget);
        btn_userProfile->setObjectName(QString::fromUtf8("btn_userProfile"));
        btn_userProfile->setGeometry(QRect(30, 250, 200, 50));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_quit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\344\270\252\344\272\272\344\277\241\346\201\257", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\345\200\237\351\230\205", nullptr));
        btn_logout->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        btn_modifyInfo->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        btn_queryBook->setText(QCoreApplication::translate("MainWindow", "\345\233\276\344\271\246\346\237\245\350\257\242", nullptr));
        btn_userProfile->setText(QCoreApplication::translate("MainWindow", "\344\270\252\344\272\272\344\270\255\345\277\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
