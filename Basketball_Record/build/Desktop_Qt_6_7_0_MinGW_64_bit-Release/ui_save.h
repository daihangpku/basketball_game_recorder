/********************************************************************************
** Form generated from reading UI file 'save.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVE_H
#define UI_SAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_save
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *save)
    {
        if (save->objectName().isEmpty())
            save->setObjectName("save");
        save->resize(408, 128);
        lineEdit = new QLineEdit(save);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(80, 50, 251, 23));
        label = new QLabel(save);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 10, 151, 31));
        pushButton = new QPushButton(save);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 90, 80, 24));

        retranslateUi(save);

        QMetaObject::connectSlotsByName(save);
    } // setupUi

    void retranslateUi(QWidget *save)
    {
        save->setWindowTitle(QCoreApplication::translate("save", "Form", nullptr));
        label->setText(QCoreApplication::translate("save", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\350\257\267\350\276\223\345\205\245\344\277\235\345\255\230\346\226\207\344\273\266\345\220\215</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("save", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class save: public Ui_save {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_H
