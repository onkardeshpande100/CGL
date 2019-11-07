/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton;
    QPlainTextEdit *Sx;
    QPlainTextEdit *Sy;
    QPushButton *scale_button;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPlainTextEdit *angle;
    QPushButton *rotate_button;
    QPushButton *translate_button;
    QPlainTextEdit *Tx;
    QPlainTextEdit *Ty;
    QLabel *label_5;
    QLabel *label_6;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 500);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 400, 400));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(460, 20, 97, 31));
        Sx = new QPlainTextEdit(centralWidget);
        Sx->setObjectName(QString::fromUtf8("Sx"));
        Sx->setGeometry(QRect(420, 80, 80, 30));
        Sy = new QPlainTextEdit(centralWidget);
        Sy->setObjectName(QString::fromUtf8("Sy"));
        Sy->setGeometry(QRect(510, 80, 80, 30));
        scale_button = new QPushButton(centralWidget);
        scale_button->setObjectName(QString::fromUtf8("scale_button"));
        scale_button->setGeometry(QRect(450, 120, 97, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(420, 60, 65, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(510, 60, 65, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(430, 180, 65, 21));
        angle = new QPlainTextEdit(centralWidget);
        angle->setObjectName(QString::fromUtf8("angle"));
        angle->setGeometry(QRect(420, 210, 80, 30));
        rotate_button = new QPushButton(centralWidget);
        rotate_button->setObjectName(QString::fromUtf8("rotate_button"));
        rotate_button->setGeometry(QRect(450, 250, 97, 31));
        translate_button = new QPushButton(centralWidget);
        translate_button->setObjectName(QString::fromUtf8("translate_button"));
        translate_button->setGeometry(QRect(450, 360, 97, 31));
        Tx = new QPlainTextEdit(centralWidget);
        Tx->setObjectName(QString::fromUtf8("Tx"));
        Tx->setGeometry(QRect(420, 320, 80, 30));
        Ty = new QPlainTextEdit(centralWidget);
        Ty->setObjectName(QString::fromUtf8("Ty"));
        Ty->setGeometry(QRect(510, 320, 80, 30));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(420, 300, 65, 21));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(510, 300, 65, 21));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Draw", 0, QApplication::UnicodeUTF8));
        scale_button->setText(QApplication::translate("MainWindow", "Scale", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Sx", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Sy", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Angle", 0, QApplication::UnicodeUTF8));
        rotate_button->setText(QApplication::translate("MainWindow", "Rotate", 0, QApplication::UnicodeUTF8));
        translate_button->setText(QApplication::translate("MainWindow", "Translate", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Tx", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Ty", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
