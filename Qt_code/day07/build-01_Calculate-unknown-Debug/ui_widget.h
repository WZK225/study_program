/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *display;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *Button7;
    QPushButton *Button8;
    QPushButton *Button9;
    QPushButton *ButtonPlus;
    QPushButton *Button4;
    QPushButton *Button5;
    QPushButton *Button6;
    QPushButton *ButtonMinus;
    QPushButton *Button1;
    QPushButton *Button2;
    QPushButton *Button3;
    QPushButton *ButtonMultiply;
    QPushButton *ButtonClear;
    QPushButton *Button0;
    QPushButton *ButtonEqual;
    QPushButton *ButtonDivide;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(367, 293);
        Widget->setMinimumSize(QSize(0, 40));
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        display = new QLineEdit(Widget);
        display->setObjectName(QString::fromUtf8("display"));

        verticalLayout->addWidget(display);

        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(0, 40));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Button7 = new QPushButton(widget);
        Button7->setObjectName(QString::fromUtf8("Button7"));
        Button7->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button7, 0, 0, 1, 1);

        Button8 = new QPushButton(widget);
        Button8->setObjectName(QString::fromUtf8("Button8"));
        Button8->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button8, 0, 1, 1, 1);

        Button9 = new QPushButton(widget);
        Button9->setObjectName(QString::fromUtf8("Button9"));
        Button9->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button9, 0, 2, 1, 1);

        ButtonPlus = new QPushButton(widget);
        ButtonPlus->setObjectName(QString::fromUtf8("ButtonPlus"));
        ButtonPlus->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(ButtonPlus, 0, 3, 1, 1);

        Button4 = new QPushButton(widget);
        Button4->setObjectName(QString::fromUtf8("Button4"));
        Button4->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button4, 1, 0, 1, 1);

        Button5 = new QPushButton(widget);
        Button5->setObjectName(QString::fromUtf8("Button5"));
        Button5->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button5, 1, 1, 1, 1);

        Button6 = new QPushButton(widget);
        Button6->setObjectName(QString::fromUtf8("Button6"));
        Button6->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button6, 1, 2, 1, 1);

        ButtonMinus = new QPushButton(widget);
        ButtonMinus->setObjectName(QString::fromUtf8("ButtonMinus"));
        ButtonMinus->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(ButtonMinus, 1, 3, 1, 1);

        Button1 = new QPushButton(widget);
        Button1->setObjectName(QString::fromUtf8("Button1"));
        Button1->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button1, 2, 0, 1, 1);

        Button2 = new QPushButton(widget);
        Button2->setObjectName(QString::fromUtf8("Button2"));
        Button2->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button2, 2, 1, 1, 1);

        Button3 = new QPushButton(widget);
        Button3->setObjectName(QString::fromUtf8("Button3"));
        Button3->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button3, 2, 2, 1, 1);

        ButtonMultiply = new QPushButton(widget);
        ButtonMultiply->setObjectName(QString::fromUtf8("ButtonMultiply"));
        ButtonMultiply->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(ButtonMultiply, 2, 3, 1, 1);

        ButtonClear = new QPushButton(widget);
        ButtonClear->setObjectName(QString::fromUtf8("ButtonClear"));
        ButtonClear->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(ButtonClear, 3, 0, 1, 1);

        Button0 = new QPushButton(widget);
        Button0->setObjectName(QString::fromUtf8("Button0"));
        Button0->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(Button0, 3, 1, 1, 1);

        ButtonEqual = new QPushButton(widget);
        ButtonEqual->setObjectName(QString::fromUtf8("ButtonEqual"));
        ButtonEqual->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(ButtonEqual, 3, 2, 1, 1);

        ButtonDivide = new QPushButton(widget);
        ButtonDivide->setObjectName(QString::fromUtf8("ButtonDivide"));
        ButtonDivide->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(ButtonDivide, 3, 3, 1, 1);


        verticalLayout->addWidget(widget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        Button7->setText(QCoreApplication::translate("Widget", "7", nullptr));
        Button8->setText(QCoreApplication::translate("Widget", "8", nullptr));
        Button9->setText(QCoreApplication::translate("Widget", "9", nullptr));
        ButtonPlus->setText(QCoreApplication::translate("Widget", "+", nullptr));
        Button4->setText(QCoreApplication::translate("Widget", "4", nullptr));
        Button5->setText(QCoreApplication::translate("Widget", "5", nullptr));
        Button6->setText(QCoreApplication::translate("Widget", "6", nullptr));
        ButtonMinus->setText(QCoreApplication::translate("Widget", "-", nullptr));
        Button1->setText(QCoreApplication::translate("Widget", "1", nullptr));
        Button2->setText(QCoreApplication::translate("Widget", "2", nullptr));
        Button3->setText(QCoreApplication::translate("Widget", "3", nullptr));
        ButtonMultiply->setText(QCoreApplication::translate("Widget", "*", nullptr));
        ButtonClear->setText(QCoreApplication::translate("Widget", "clear", nullptr));
        Button0->setText(QCoreApplication::translate("Widget", "0", nullptr));
        ButtonEqual->setText(QCoreApplication::translate("Widget", "=", nullptr));
        ButtonDivide->setText(QCoreApplication::translate("Widget", "/", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
