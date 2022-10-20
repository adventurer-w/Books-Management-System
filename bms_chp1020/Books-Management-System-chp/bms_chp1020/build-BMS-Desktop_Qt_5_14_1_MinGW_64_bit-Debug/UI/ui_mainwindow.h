/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
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
    QLabel *lb_username_main;
    QLabel *lb_number_main;
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
        lb_username_main = new QLabel(centralwidget);
        lb_username_main->setObjectName(QString::fromUtf8("lb_username_main"));
        lb_username_main->setGeometry(QRect(170, 70, 100, 20));
        lb_number_main = new QLabel(centralwidget);
        lb_number_main->setObjectName(QString::fromUtf8("lb_number_main"));
        lb_number_main->setGeometry(QRect(170, 100, 100, 20));
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
        lb_username_main->setText(QCoreApplication::translate("MainWindow", "\344\270\201\346\235\260", nullptr));
        lb_number_main->setText(QCoreApplication::translate("MainWindow", "20040032005", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
