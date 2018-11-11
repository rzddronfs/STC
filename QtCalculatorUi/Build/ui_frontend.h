/********************************************************************************
** Form generated from reading UI file 'frontend.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRONTEND_H
#define UI_FRONTEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Frontend
{
public:
    QLineEdit *lineDisplay;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_evaluate;
    QPushButton *pushButton_0;
    QPushButton *pushButton_comma;
    QPushButton *pushButton_divide;
    QPushButton *pushButton_multiply;
    QPushButton *pushButton_minus;
    QPushButton *pushButton_plus;
    QPushButton *pushButton_clear;

    void setupUi(QWidget *Frontend)
    {
        if (Frontend->objectName().isEmpty())
            Frontend->setObjectName(QStringLiteral("Frontend"));
        Frontend->resize(282, 243);
        lineDisplay = new QLineEdit(Frontend);
        lineDisplay->setObjectName(QStringLiteral("lineDisplay"));
        lineDisplay->setGeometry(QRect(10, 10, 260, 51));
        QFont font;
        font.setPointSize(20);
        lineDisplay->setFont(font);
        lineDisplay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineDisplay->setReadOnly(true);
        pushButton_7 = new QPushButton(Frontend);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 80, 41, 31));
        pushButton_8 = new QPushButton(Frontend);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(60, 80, 41, 31));
        pushButton_9 = new QPushButton(Frontend);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(110, 80, 41, 31));
        pushButton_4 = new QPushButton(Frontend);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 120, 41, 31));
        pushButton_5 = new QPushButton(Frontend);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(60, 120, 41, 31));
        pushButton_6 = new QPushButton(Frontend);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(110, 120, 41, 31));
        pushButton_1 = new QPushButton(Frontend);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setGeometry(QRect(10, 160, 41, 31));
        pushButton_2 = new QPushButton(Frontend);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(60, 160, 41, 31));
        pushButton_3 = new QPushButton(Frontend);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(110, 160, 41, 31));
        pushButton_evaluate = new QPushButton(Frontend);
        pushButton_evaluate->setObjectName(QStringLiteral("pushButton_evaluate"));
        pushButton_evaluate->setGeometry(QRect(230, 160, 41, 71));
        pushButton_0 = new QPushButton(Frontend);
        pushButton_0->setObjectName(QStringLiteral("pushButton_0"));
        pushButton_0->setGeometry(QRect(10, 200, 91, 31));
        pushButton_comma = new QPushButton(Frontend);
        pushButton_comma->setObjectName(QStringLiteral("pushButton_comma"));
        pushButton_comma->setGeometry(QRect(110, 200, 41, 31));
        pushButton_divide = new QPushButton(Frontend);
        pushButton_divide->setObjectName(QStringLiteral("pushButton_divide"));
        pushButton_divide->setGeometry(QRect(170, 80, 40, 31));
        pushButton_multiply = new QPushButton(Frontend);
        pushButton_multiply->setObjectName(QStringLiteral("pushButton_multiply"));
        pushButton_multiply->setGeometry(QRect(170, 120, 40, 31));
        pushButton_minus = new QPushButton(Frontend);
        pushButton_minus->setObjectName(QStringLiteral("pushButton_minus"));
        pushButton_minus->setGeometry(QRect(170, 160, 40, 31));
        pushButton_plus = new QPushButton(Frontend);
        pushButton_plus->setObjectName(QStringLiteral("pushButton_plus"));
        pushButton_plus->setGeometry(QRect(170, 200, 40, 31));
        pushButton_clear = new QPushButton(Frontend);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(230, 80, 41, 31));

        retranslateUi(Frontend);

        QMetaObject::connectSlotsByName(Frontend);
    } // setupUi

    void retranslateUi(QWidget *Frontend)
    {
        Frontend->setWindowTitle(QApplication::translate("Frontend", "Calculator", Q_NULLPTR));
        lineDisplay->setText(QApplication::translate("Frontend", "0", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Frontend", "7", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Frontend", "8", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("Frontend", "9", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Frontend", "4", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Frontend", "5", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Frontend", "6", Q_NULLPTR));
        pushButton_1->setText(QApplication::translate("Frontend", "1", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Frontend", "2", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Frontend", "3", Q_NULLPTR));
        pushButton_evaluate->setText(QApplication::translate("Frontend", "=", Q_NULLPTR));
        pushButton_0->setText(QApplication::translate("Frontend", "0", Q_NULLPTR));
        pushButton_comma->setText(QApplication::translate("Frontend", ",", Q_NULLPTR));
        pushButton_divide->setText(QApplication::translate("Frontend", "/", Q_NULLPTR));
        pushButton_multiply->setText(QApplication::translate("Frontend", "*", Q_NULLPTR));
        pushButton_minus->setText(QApplication::translate("Frontend", "-", Q_NULLPTR));
        pushButton_plus->setText(QApplication::translate("Frontend", "+", Q_NULLPTR));
        pushButton_clear->setText(QApplication::translate("Frontend", "C", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Frontend: public Ui_Frontend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRONTEND_H
