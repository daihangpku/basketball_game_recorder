/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_help
{
public:
    QPushButton *pushButton;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *help)
    {
        if (help->objectName().isEmpty())
            help->setObjectName("help");
        help->resize(1193, 672);
        pushButton = new QPushButton(help);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 80, 31));
        textBrowser = new QTextBrowser(help);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(85, 40, 1021, 591));

        retranslateUi(help);

        QMetaObject::connectSlotsByName(help);
    } // setupUi

    void retranslateUi(QWidget *help)
    {
        help->setWindowTitle(QCoreApplication::translate("help", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("help", "\350\277\224\345\233\236", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">1. \344\270\273\347\225\214\351\235\242\345\212\237\350\203\275</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\344\270\273\347\225\214\351\235\242\346\217\220\344\276\233\350\277\233\345\205\245\350\256\260\345\275\225\346\250\241\345\274"
                        "\217\345\222\214\345\233\236\346\224\276\346\250\241\345\274\217\347\232\204\345\205\245\345\217\243\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\350\256\260\345\275\225\346\250\241\345\274\217\346\214\211\351\222\256\357\274\232\347\202\271\345\207\273\350\277\233\345\205\245\350\256\260\345\275\225\346\257\224\350\265\233\347\232\204\347\225\214\351\235\242\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\345\233\236\346\224\276\346\250\241\345\274\217\346\214\211\351\222\256\357\274\232\347\202\271\345\207\273\350\277\233\345\205\245\345\233\236\346\224\276\345\267\262\350\256\260\345\275\225\346\257\224\350\265\233\347\232\204\347\225\214\351\235\242\343\200\202</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-botto"
                        "m:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">2. \350\256\260\345\275\225\346\250\241\345\274\217\346\223\215\344\275\234\350\257\264\346\230\216</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">2.1 \350\277\233\345\205\245\350\256\260\345\275\225\346\250\241\345\274\217</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\347\202\271\345\207\273\344\270\273\347\225\214\351\235\242\347\232\204\342\200\234\350\256\260\345\275\225\346\226\260\346\257\224\350\265\233\342\200\235\346\214\211\351\222\256\357\274\214\350\277\233\345\205\245\350\256\260\345\275\225\347"
                        "\225\214\351\235\242\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">2.2 \350\256\260\345\275\225\347\225\214\351\235\242\346\214\211\351\222\256\345\212\237\350\203\275</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\345\274\200\345\247\213\346\257\224\350\265\233\346\214\211\351\222\256\357\274\232\347\202\271\345\207\273\346\255\244\346\214\211\351\222\256\357\274\214\345\274\200\345\247\213\350\256\260\345\275\225\346\257\224\350\265\233\343\200\202\351\200\232\350\277\207\346\216\247\345\210\266\345\274\200\345\201\234\350\241\250\346\214\211\351\222\256\357\274\214\350\256\241\346\227\266\345\231\250\345\260\206\345\274\200\345\247\213\350\256\241\346\227\266\357\274\214\347\263\273\347\273\237\345\274\200\345\247\213\350\256\260\345\275\225\346\257\224\350"
                        "\265\233\344\272\213\344\273\266\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\345\276\227\345\210\206\346\214\211\351\222\256\357\274\232\345\214\205\346\213\254\342\200\234\345\276\2271\345\210\206\342\200\235\343\200\201\342\200\234\345\276\2272\345\210\206\342\200\235\343\200\201\342\200\234\345\276\2273\345\210\206\342\200\235\344\270\211\344\270\252\346\214\211\351\222\256\357\274\214\345\210\206\345\210\253\350\256\260\345\275\225\347\220\203\345\221\230\345\276\227\345\210\2061\343\200\2012\345\222\2143\345\210\206\343\200\202\347\202\271\345\207\273\345\220\216\345\206\215\347\202\271\345\207\273\345\257\271\345\272\224\347\220\203\345\221\230\350\256\260\345\275\225\344\270\200\346\254\241\350\277\233\347\220\203\344\272\213\344\273\266\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; tex"
                        "t-indent:0px;\"><span style=\" font-size:12pt;\">\347\212\257\350\247\204\346\214\211\351\222\256\357\274\232\347\202\271\345\207\273\342\200\234\347\212\257\350\247\204\342\200\235\346\214\211\351\222\256\357\274\214\345\271\266\346\217\220\347\244\272\351\200\211\346\213\251\347\212\257\350\247\204\347\261\273\345\236\213\357\274\214\351\200\211\345\245\275\345\220\216\347\202\271\345\207\273\345\257\271\345\272\224\347\220\203\345\221\230\350\256\260\345\275\225\344\270\200\346\254\241\347\212\257\350\247\204\344\272\213\344\273\266\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\346\232\202\345\201\234\346\214\211\351\222\256\357\274\232\347\202\271\345\207\273\342\200\234\346\232\202\345\201\234\342\200\235\346\214\211\351\222\256\357\274\214\351\200\211\346\213\251\345\257\271\345\272\224\351\230\237\344\274\215\357\274\214\350\256\260\345\275\225\344\270\200\346\254\241\346"
                        "\232\202\345\201\234\344\272\213\344\273\266\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\344\270\213\344\270\200\350\212\202\346\214\211\351\222\256\357\274\232\347\202\271\345\207\273\347\273\223\346\235\237\346\255\244\350\212\202\357\274\214\350\277\233\345\205\245\344\270\213\344\270\200\350\212\202\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">2.3 \344\277\235\345\255\230\346\257\224\350\265\233\350\256\260\345\275\225</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\346\257\224\350\265\233\347\273\223\346\235\237\345\220\216\357\274\214\347\263\273\347\273\237\344\274\232\344\277\235\345\255\230\350\256\260\345\275\225"
                        "\346\225\260\346\215\256\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\344\277\235\345\255\230\350\256\260\345\275\225\346\214\211\351\222\256\357\274\232\347\202\271\345\207\273\346\255\244\346\214\211\351\222\256\357\274\214\350\276\223\345\205\245\346\226\207\344\273\266\345\220\215\357\274\214\345\260\206\346\257\224\350\265\233\350\256\260\345\275\225\344\277\235\345\255\230\345\210\260\346\234\254\345\234\260\346\226\207\344\273\266\343\200\202</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:12pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:18pt;\">3. \345\233\236\346\224\276\346\250\241\345\274\217\346\223\215\344\275\234\350\257\264\346"
                        "\230\216</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">3.1 \350\277\233\345\205\245\345\233\236\346\224\276\346\250\241\345\274\217</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\347\202\271\345\207\273\344\270\273\347\225\214\351\235\242\347\232\204\342\200\234\350\247\202\347\234\213\345\233\236\346\224\276\342\200\235\346\214\211\351\222\256\357\274\214\350\277\233\345\205\245\345\233\236\346\224\276\347\225\214\351\235\242\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">3.2 \345\233\236\346\224\276\347\225\214\351\235\242\346\214\211\351\222\256\345\212\237\350\203\275</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; marg"
                        "in-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\351\200\211\346\213\251\346\257\224\350\265\233\347\225\214\351\235\242\357\274\232\347\202\271\345\207\273\351\200\211\346\213\251\345\267\262\344\277\235\345\255\230\347\232\204\346\257\224\350\265\233\350\256\260\345\275\225\346\226\207\344\273\266\357\274\214\345\212\240\350\275\275\350\256\260\345\275\225\346\225\260\346\215\256\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\347\224\237\346\210\220\346\210\230\346\212\245\346\214\211\351\222\256\357\274\232\347\202\271\345\207\273\342\200\234\347\224\237\346\210\220\346\210\230\346\212\245\342\200\235\346\214\211\351\222\256\357\274\214\347\224\237\346\210\220\346\257\224\350\265\233\346\210\230\346\212\245\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-bl"
                        "ock-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\346\222\255\346\224\276\346\214\211\351\222\256\357\274\232\347\202\271\345\207\273\342\200\234\350\247\202\347\234\213\345\233\236\346\224\276\342\200\235\346\214\211\351\222\256\357\274\214\345\274\200\345\247\213\345\233\236\346\224\276\346\257\224\350\265\233\350\256\260\345\275\225\343\200\202\347\263\273\347\273\237\345\260\206\346\214\211\346\227\266\351\227\264\351\241\272\345\272\217\346\230\276\347\244\272\345\220\204\344\270\252\344\272\213\344\273\266\343\200\202</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\346\232\202\345\201\234/\347\273\247\347\273\255\346\214\211\351\222\256\357\274\232\347\202\271\345\207\273\342\200\234\346\232\202\345\201\234\342\200\235\346\214\211\351\222\256\357\274\214\346\232\202\345\201\234\345\233\236\346\224\276\343\200\202\345\206\215\346\254\241\347\202\271\345\207\273\345\217"
                        "\257\344\273\245\347\273\247\347\273\255\345\233\236\346\224\276\343\200\202</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class help: public Ui_help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
