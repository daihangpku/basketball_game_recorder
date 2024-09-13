/********************************************************************************
** Form generated from reading UI file 'replay.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLAY_H
#define UI_REPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_replay
{
public:
    QPushButton *pushButton;
    QWidget *widget;
    QTextBrowser *screen;
    QPushButton *out2;
    QPushButton *stop;
    QPushButton *continue_2;
    QPushButton *all_show;
    QPushButton *begin;
    QPushButton *replayy;
    QWidget *widget_2;
    QLabel *label;
    QPushButton *see;
    QListWidget *choose;

    void setupUi(QWidget *replay)
    {
        if (replay->objectName().isEmpty())
            replay->setObjectName("replay");
        replay->resize(1291, 752);
        pushButton = new QPushButton(replay);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 80, 31));
        widget = new QWidget(replay);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(30, 30, 1221, 711));
        screen = new QTextBrowser(widget);
        screen->setObjectName("screen");
        screen->setGeometry(QRect(50, 20, 1131, 591));
        out2 = new QPushButton(widget);
        out2->setObjectName("out2");
        out2->setGeometry(QRect(1070, 610, 111, 41));
        stop = new QPushButton(widget);
        stop->setObjectName("stop");
        stop->setGeometry(QRect(730, 640, 111, 41));
        continue_2 = new QPushButton(widget);
        continue_2->setObjectName("continue_2");
        continue_2->setGeometry(QRect(730, 640, 111, 41));
        all_show = new QPushButton(widget);
        all_show->setObjectName("all_show");
        all_show->setGeometry(QRect(380, 640, 111, 41));
        begin = new QPushButton(widget);
        begin->setObjectName("begin");
        begin->setGeometry(QRect(560, 640, 111, 41));
        replayy = new QPushButton(widget);
        replayy->setObjectName("replayy");
        replayy->setGeometry(QRect(560, 640, 111, 41));
        stop->raise();
        continue_2->raise();
        screen->raise();
        out2->raise();
        all_show->raise();
        begin->raise();
        replayy->raise();
        widget_2 = new QWidget(replay);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(10, 19, 1271, 731));
        widget_2->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setGeometry(QRect(563, 0, 141, 51));
        see = new QPushButton(widget_2);
        see->setObjectName("see");
        see->setGeometry(QRect(580, 650, 111, 41));
        choose = new QListWidget(widget_2);
        choose->setObjectName("choose");
        choose->setGeometry(QRect(200, 80, 871, 541));
        widget->raise();
        widget_2->raise();
        pushButton->raise();

        retranslateUi(replay);

        QMetaObject::connectSlotsByName(replay);
    } // setupUi

    void retranslateUi(QWidget *replay)
    {
        replay->setWindowTitle(QCoreApplication::translate("replay", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("replay", "\350\277\224\345\233\236", nullptr));
        out2->setText(QCoreApplication::translate("replay", "\345\257\274\345\207\272", nullptr));
        stop->setText(QCoreApplication::translate("replay", "\346\232\202\345\201\234", nullptr));
        continue_2->setText(QCoreApplication::translate("replay", "\347\273\247\347\273\255", nullptr));
        all_show->setText(QCoreApplication::translate("replay", "\346\230\276\347\244\272\345\205\250\351\203\250", nullptr));
        begin->setText(QCoreApplication::translate("replay", "\345\274\200\345\247\213", nullptr));
        replayy->setText(QCoreApplication::translate("replay", "\350\247\202\347\234\213\345\233\236\346\224\276", nullptr));
        label->setText(QCoreApplication::translate("replay", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">\351\200\211\346\213\251\346\257\224\350\265\233</span></p></body></html>", nullptr));
        see->setText(QCoreApplication::translate("replay", "\347\224\237\346\210\220\346\210\230\346\212\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class replay: public Ui_replay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLAY_H
