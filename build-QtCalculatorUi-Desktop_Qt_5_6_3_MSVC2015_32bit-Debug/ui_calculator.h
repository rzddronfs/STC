/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralWidget;
    QLineEdit *inputLine;
    QPlainTextEdit *resultsListing;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QStringLiteral("Calculator"));
        Calculator->resize(400, 300);
        centralWidget = new QWidget(Calculator);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inputLine = new QLineEdit(centralWidget);
        inputLine->setObjectName(QStringLiteral("inputLine"));
        inputLine->setGeometry(QRect(10, 230, 381, 20));
        resultsListing = new QPlainTextEdit(centralWidget);
        resultsListing->setObjectName(QStringLiteral("resultsListing"));
        resultsListing->setEnabled(true);
        resultsListing->setGeometry(QRect(10, 20, 381, 181));
        resultsListing->setReadOnly(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 53, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 210, 45, 13));
        Calculator->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Calculator);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        Calculator->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Calculator);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Calculator->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Calculator);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Calculator->setStatusBar(statusBar);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QApplication::translate("Calculator", "Calculator", Q_NULLPTR));
        label->setText(QApplication::translate("Calculator", "Echo listing", Q_NULLPTR));
        label_2->setText(QApplication::translate("Calculator", "Input line", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
