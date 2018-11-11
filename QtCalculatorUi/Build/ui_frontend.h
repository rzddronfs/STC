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

class Ui_Form
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(277, 243);
        lineEdit = new QLineEdit(Form);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 251, 51));
        QFont font;
        font.setPointSize(20);
        lineEdit->setFont(font);
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit->setReadOnly(true);
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 80, 41, 31));
        pushButton_2 = new QPushButton(Form);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 80, 41, 31));
        pushButton_3 = new QPushButton(Form);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(120, 80, 41, 31));
        pushButton_4 = new QPushButton(Form);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 120, 41, 31));
        pushButton_5 = new QPushButton(Form);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(70, 120, 41, 31));
        pushButton_6 = new QPushButton(Form);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(120, 120, 41, 31));
        pushButton_7 = new QPushButton(Form);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(20, 160, 41, 31));
        pushButton_8 = new QPushButton(Form);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(70, 160, 41, 31));
        pushButton_9 = new QPushButton(Form);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(120, 160, 41, 31));
        pushButton_10 = new QPushButton(Form);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(220, 160, 41, 71));
        pushButton_11 = new QPushButton(Form);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(20, 200, 91, 31));
        pushButton_12 = new QPushButton(Form);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(120, 200, 41, 31));
        pushButton_13 = new QPushButton(Form);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(170, 80, 41, 31));
        pushButton_14 = new QPushButton(Form);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(170, 120, 41, 31));
        pushButton_15 = new QPushButton(Form);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(170, 160, 41, 31));
        pushButton_16 = new QPushButton(Form);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(170, 200, 41, 31));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("Form", "0", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Form", "7", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Form", "8", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Form", "9", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Form", "4", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Form", "5", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Form", "6", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Form", "1", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Form", "2", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("Form", "3", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("Form", "=", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("Form", "0", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("Form", ",", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("Form", "/", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("Form", "*", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("Form", "-", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("Form", "+", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRONTEND_H
