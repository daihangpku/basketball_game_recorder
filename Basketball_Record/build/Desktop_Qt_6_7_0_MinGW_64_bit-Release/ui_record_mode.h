/********************************************************************************
** Form generated from reading UI file 'record_mode.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORD_MODE_H
#define UI_RECORD_MODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_record_mode
{
public:
    QPushButton *backbutton;
    QWidget *widget_teams;
    QLineEdit *teamname1;
    QLabel *label1_3;
    QLabel *label1_5;
    QLabel *label1_4;
    QLabel *label1_2;
    QLineEdit *teamname2;
    QLabel *label1_1;
    QLabel *label1_warn2;
    QLabel *label1_warn1;
    QLabel *label1_7;
    QComboBox *membernum2;
    QPushButton *back_to_event;
    QPushButton *go_to_members;
    QLabel *label1_6;
    QComboBox *membernum1;
    QWidget *widget_events;
    QLabel *label0_1;
    QPushButton *go_to_teams;
    QLabel *label0_2;
    QLabel *label0_3;
    QLabel *label0_4;
    QLineEdit *eventname;
    QLineEdit *eventtime;
    QLineEdit *eventplace;
    QLabel *label0_6;
    QLabel *label0_5;
    QLineEdit *mainreferee;
    QLineEdit *secondreferee;
    QWidget *widget_members;
    QLabel *label2_1;
    QLabel *label2_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *member1_name1;
    QLineEdit *member1_number1;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *member1_name2;
    QLineEdit *member1_name3;
    QLineEdit *member1_name4;
    QLineEdit *member1_name5;
    QLineEdit *member1_name6;
    QLineEdit *member1_name7;
    QLineEdit *member1_name11;
    QLineEdit *member1_name9;
    QLineEdit *member1_name8;
    QLineEdit *member1_number2;
    QLineEdit *member2_name6;
    QLineEdit *member2_name5;
    QLineEdit *member1_number12;
    QLineEdit *member1_number11;
    QLineEdit *member1_number10;
    QLineEdit *member1_number9;
    QLineEdit *member1_name12;
    QLineEdit *member1_name10;
    QLineEdit *member1_number7;
    QLineEdit *member1_number6;
    QLineEdit *member1_number5;
    QLineEdit *member1_number4;
    QLineEdit *member1_number8;
    QLineEdit *member2_name4;
    QLineEdit *member2_name3;
    QLineEdit *member2_name2;
    QLineEdit *member2_number1;
    QLineEdit *member2_name1;
    QLineEdit *member1_number3;
    QLabel *label2_5;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLineEdit *member2_number5;
    QLineEdit *member2_number4;
    QLineEdit *member2_number3;
    QLineEdit *member2_number6;
    QLineEdit *member2_name8;
    QLineEdit *member2_name7;
    QLineEdit *member2_number7;
    QLineEdit *member2_number8;
    QLineEdit *member2_name11;
    QLineEdit *member2_name10;
    QLineEdit *member2_name9;
    QLineEdit *member2_number10;
    QLineEdit *member2_number9;
    QLineEdit *member2_number2;
    QLineEdit *member2_name12;
    QLineEdit *member2_number12;
    QLineEdit *member2_number11;
    QPushButton *back_to_teams;
    QPushButton *go_to_record;
    QLabel *label_28;
    QLineEdit *coach1_name;
    QLabel *label_29;
    QLineEdit *coach2_name;
    QLabel *warning_member1;
    QLabel *warning_member2;

    void setupUi(QWidget *record_mode)
    {
        if (record_mode->objectName().isEmpty())
            record_mode->setObjectName("record_mode");
        record_mode->resize(1320, 740);
        backbutton = new QPushButton(record_mode);
        backbutton->setObjectName("backbutton");
        backbutton->setGeometry(QRect(0, 0, 81, 31));
        widget_teams = new QWidget(record_mode);
        widget_teams->setObjectName("widget_teams");
        widget_teams->setGeometry(QRect(-90, -20, 1461, 751));
        widget_teams->setStyleSheet(QString::fromUtf8(""));
        teamname1 = new QLineEdit(widget_teams);
        teamname1->setObjectName("teamname1");
        teamname1->setGeometry(QRect(290, 330, 121, 23));
        label1_3 = new QLabel(widget_teams);
        label1_3->setObjectName("label1_3");
        label1_3->setGeometry(QRect(1180, 170, 91, 51));
        label1_5 = new QLabel(widget_teams);
        label1_5->setObjectName("label1_5");
        label1_5->setGeometry(QRect(1090, 320, 111, 41));
        label1_4 = new QLabel(widget_teams);
        label1_4->setObjectName("label1_4");
        label1_4->setGeometry(QRect(120, 320, 111, 41));
        label1_2 = new QLabel(widget_teams);
        label1_2->setObjectName("label1_2");
        label1_2->setGeometry(QRect(210, 170, 91, 51));
        teamname2 = new QLineEdit(widget_teams);
        teamname2->setObjectName("teamname2");
        teamname2->setGeometry(QRect(1260, 330, 121, 23));
        label1_1 = new QLabel(widget_teams);
        label1_1->setObjectName("label1_1");
        label1_1->setGeometry(QRect(520, 40, 451, 101));
        label1_warn2 = new QLabel(widget_teams);
        label1_warn2->setObjectName("label1_warn2");
        label1_warn2->setGeometry(QRect(1260, 360, 91, 16));
        label1_warn1 = new QLabel(widget_teams);
        label1_warn1->setObjectName("label1_warn1");
        label1_warn1->setGeometry(QRect(290, 360, 84, 16));
        label1_7 = new QLabel(widget_teams);
        label1_7->setObjectName("label1_7");
        label1_7->setGeometry(QRect(1090, 460, 111, 41));
        membernum2 = new QComboBox(widget_teams);
        membernum2->addItem(QString());
        membernum2->addItem(QString());
        membernum2->addItem(QString());
        membernum2->addItem(QString());
        membernum2->addItem(QString());
        membernum2->addItem(QString());
        membernum2->addItem(QString());
        membernum2->addItem(QString());
        membernum2->setObjectName("membernum2");
        membernum2->setGeometry(QRect(1260, 470, 121, 21));
        back_to_event = new QPushButton(widget_teams);
        back_to_event->setObjectName("back_to_event");
        back_to_event->setGeometry(QRect(620, 660, 91, 41));
        go_to_members = new QPushButton(widget_teams);
        go_to_members->setObjectName("go_to_members");
        go_to_members->setGeometry(QRect(780, 660, 91, 41));
        label1_6 = new QLabel(widget_teams);
        label1_6->setObjectName("label1_6");
        label1_6->setGeometry(QRect(120, 460, 111, 41));
        membernum1 = new QComboBox(widget_teams);
        membernum1->addItem(QString());
        membernum1->addItem(QString());
        membernum1->addItem(QString());
        membernum1->addItem(QString());
        membernum1->addItem(QString());
        membernum1->addItem(QString());
        membernum1->addItem(QString());
        membernum1->addItem(QString());
        membernum1->setObjectName("membernum1");
        membernum1->setGeometry(QRect(290, 470, 121, 21));
        widget_events = new QWidget(record_mode);
        widget_events->setObjectName("widget_events");
        widget_events->setGeometry(QRect(-90, -20, 1481, 751));
        widget_events->setStyleSheet(QString::fromUtf8(""));
        label0_1 = new QLabel(widget_events);
        label0_1->setObjectName("label0_1");
        label0_1->setGeometry(QRect(520, 40, 451, 101));
        go_to_teams = new QPushButton(widget_events);
        go_to_teams->setObjectName("go_to_teams");
        go_to_teams->setGeometry(QRect(700, 660, 91, 41));
        label0_2 = new QLabel(widget_events);
        label0_2->setObjectName("label0_2");
        label0_2->setGeometry(QRect(570, 200, 111, 41));
        label0_3 = new QLabel(widget_events);
        label0_3->setObjectName("label0_3");
        label0_3->setGeometry(QRect(570, 280, 111, 41));
        label0_4 = new QLabel(widget_events);
        label0_4->setObjectName("label0_4");
        label0_4->setGeometry(QRect(570, 360, 111, 41));
        eventname = new QLineEdit(widget_events);
        eventname->setObjectName("eventname");
        eventname->setGeometry(QRect(710, 210, 211, 23));
        eventtime = new QLineEdit(widget_events);
        eventtime->setObjectName("eventtime");
        eventtime->setGeometry(QRect(710, 290, 211, 23));
        eventplace = new QLineEdit(widget_events);
        eventplace->setObjectName("eventplace");
        eventplace->setGeometry(QRect(710, 370, 211, 23));
        label0_6 = new QLabel(widget_events);
        label0_6->setObjectName("label0_6");
        label0_6->setGeometry(QRect(570, 520, 111, 41));
        label0_5 = new QLabel(widget_events);
        label0_5->setObjectName("label0_5");
        label0_5->setGeometry(QRect(570, 440, 111, 41));
        mainreferee = new QLineEdit(widget_events);
        mainreferee->setObjectName("mainreferee");
        mainreferee->setGeometry(QRect(710, 450, 211, 23));
        secondreferee = new QLineEdit(widget_events);
        secondreferee->setObjectName("secondreferee");
        secondreferee->setGeometry(QRect(710, 530, 211, 23));
        widget_members = new QWidget(record_mode);
        widget_members->setObjectName("widget_members");
        widget_members->setGeometry(QRect(-120, -30, 1551, 771));
        widget_members->setStyleSheet(QString::fromUtf8(""));
        label2_1 = new QLabel(widget_members);
        label2_1->setObjectName("label2_1");
        label2_1->setGeometry(QRect(550, 50, 451, 101));
        label2_2 = new QLabel(widget_members);
        label2_2->setObjectName("label2_2");
        label2_2->setGeometry(QRect(320, 130, 91, 51));
        label = new QLabel(widget_members);
        label->setObjectName("label");
        label->setGeometry(QRect(300, 190, 51, 31));
        label_2 = new QLabel(widget_members);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(460, 190, 101, 31));
        label_3 = new QLabel(widget_members);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(140, 240, 51, 21));
        member1_name1 = new QLineEdit(widget_members);
        member1_name1->setObjectName("member1_name1");
        member1_name1->setGeometry(QRect(260, 240, 113, 23));
        member1_number1 = new QLineEdit(widget_members);
        member1_number1->setObjectName("member1_number1");
        member1_number1->setGeometry(QRect(450, 240, 113, 23));
        label_7 = new QLabel(widget_members);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(140, 280, 51, 21));
        label_8 = new QLabel(widget_members);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(140, 320, 51, 21));
        label_9 = new QLabel(widget_members);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(140, 360, 51, 21));
        label_10 = new QLabel(widget_members);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(140, 400, 51, 21));
        label_11 = new QLabel(widget_members);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(140, 440, 51, 21));
        label_12 = new QLabel(widget_members);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(140, 680, 51, 21));
        label_13 = new QLabel(widget_members);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(140, 640, 51, 21));
        label_14 = new QLabel(widget_members);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(970, 240, 51, 21));
        label_15 = new QLabel(widget_members);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(140, 480, 51, 21));
        label_16 = new QLabel(widget_members);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(140, 520, 51, 21));
        label_17 = new QLabel(widget_members);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(140, 600, 51, 21));
        label_18 = new QLabel(widget_members);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(140, 560, 51, 21));
        member1_name2 = new QLineEdit(widget_members);
        member1_name2->setObjectName("member1_name2");
        member1_name2->setGeometry(QRect(260, 280, 113, 23));
        member1_name3 = new QLineEdit(widget_members);
        member1_name3->setObjectName("member1_name3");
        member1_name3->setGeometry(QRect(260, 320, 113, 23));
        member1_name4 = new QLineEdit(widget_members);
        member1_name4->setObjectName("member1_name4");
        member1_name4->setGeometry(QRect(260, 360, 113, 23));
        member1_name5 = new QLineEdit(widget_members);
        member1_name5->setObjectName("member1_name5");
        member1_name5->setGeometry(QRect(260, 400, 113, 23));
        member1_name6 = new QLineEdit(widget_members);
        member1_name6->setObjectName("member1_name6");
        member1_name6->setGeometry(QRect(260, 440, 113, 23));
        member1_name7 = new QLineEdit(widget_members);
        member1_name7->setObjectName("member1_name7");
        member1_name7->setGeometry(QRect(260, 480, 113, 23));
        member1_name11 = new QLineEdit(widget_members);
        member1_name11->setObjectName("member1_name11");
        member1_name11->setGeometry(QRect(260, 640, 113, 23));
        member1_name9 = new QLineEdit(widget_members);
        member1_name9->setObjectName("member1_name9");
        member1_name9->setGeometry(QRect(260, 560, 113, 23));
        member1_name8 = new QLineEdit(widget_members);
        member1_name8->setObjectName("member1_name8");
        member1_name8->setGeometry(QRect(260, 520, 113, 23));
        member1_number2 = new QLineEdit(widget_members);
        member1_number2->setObjectName("member1_number2");
        member1_number2->setGeometry(QRect(450, 280, 113, 23));
        member2_name6 = new QLineEdit(widget_members);
        member2_name6->setObjectName("member2_name6");
        member2_name6->setGeometry(QRect(1090, 440, 113, 23));
        member2_name5 = new QLineEdit(widget_members);
        member2_name5->setObjectName("member2_name5");
        member2_name5->setGeometry(QRect(1090, 400, 113, 23));
        member1_number12 = new QLineEdit(widget_members);
        member1_number12->setObjectName("member1_number12");
        member1_number12->setGeometry(QRect(450, 680, 113, 23));
        member1_number11 = new QLineEdit(widget_members);
        member1_number11->setObjectName("member1_number11");
        member1_number11->setGeometry(QRect(450, 640, 113, 23));
        member1_number10 = new QLineEdit(widget_members);
        member1_number10->setObjectName("member1_number10");
        member1_number10->setGeometry(QRect(450, 600, 113, 23));
        member1_number9 = new QLineEdit(widget_members);
        member1_number9->setObjectName("member1_number9");
        member1_number9->setGeometry(QRect(450, 560, 113, 23));
        member1_name12 = new QLineEdit(widget_members);
        member1_name12->setObjectName("member1_name12");
        member1_name12->setGeometry(QRect(260, 680, 113, 23));
        member1_name10 = new QLineEdit(widget_members);
        member1_name10->setObjectName("member1_name10");
        member1_name10->setGeometry(QRect(260, 600, 113, 23));
        member1_number7 = new QLineEdit(widget_members);
        member1_number7->setObjectName("member1_number7");
        member1_number7->setGeometry(QRect(450, 480, 113, 23));
        member1_number6 = new QLineEdit(widget_members);
        member1_number6->setObjectName("member1_number6");
        member1_number6->setGeometry(QRect(450, 440, 113, 23));
        member1_number5 = new QLineEdit(widget_members);
        member1_number5->setObjectName("member1_number5");
        member1_number5->setGeometry(QRect(450, 400, 113, 23));
        member1_number4 = new QLineEdit(widget_members);
        member1_number4->setObjectName("member1_number4");
        member1_number4->setGeometry(QRect(450, 360, 113, 23));
        member1_number8 = new QLineEdit(widget_members);
        member1_number8->setObjectName("member1_number8");
        member1_number8->setGeometry(QRect(450, 520, 113, 23));
        member2_name4 = new QLineEdit(widget_members);
        member2_name4->setObjectName("member2_name4");
        member2_name4->setGeometry(QRect(1090, 360, 113, 23));
        member2_name3 = new QLineEdit(widget_members);
        member2_name3->setObjectName("member2_name3");
        member2_name3->setGeometry(QRect(1090, 320, 113, 23));
        member2_name2 = new QLineEdit(widget_members);
        member2_name2->setObjectName("member2_name2");
        member2_name2->setGeometry(QRect(1090, 280, 113, 23));
        member2_number1 = new QLineEdit(widget_members);
        member2_number1->setObjectName("member2_number1");
        member2_number1->setGeometry(QRect(1280, 240, 113, 23));
        member2_name1 = new QLineEdit(widget_members);
        member2_name1->setObjectName("member2_name1");
        member2_name1->setGeometry(QRect(1090, 240, 113, 23));
        member1_number3 = new QLineEdit(widget_members);
        member1_number3->setObjectName("member1_number3");
        member1_number3->setGeometry(QRect(450, 320, 113, 23));
        label2_5 = new QLabel(widget_members);
        label2_5->setObjectName("label2_5");
        label2_5->setGeometry(QRect(1150, 130, 91, 51));
        label_19 = new QLabel(widget_members);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(1120, 190, 51, 31));
        label_20 = new QLabel(widget_members);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(1290, 190, 101, 31));
        label_21 = new QLabel(widget_members);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(970, 280, 51, 21));
        label_22 = new QLabel(widget_members);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(970, 320, 51, 21));
        label_23 = new QLabel(widget_members);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(970, 400, 51, 21));
        label_24 = new QLabel(widget_members);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(970, 360, 51, 21));
        label_25 = new QLabel(widget_members);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(970, 440, 51, 21));
        label_26 = new QLabel(widget_members);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(970, 520, 51, 21));
        label_27 = new QLabel(widget_members);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(970, 480, 51, 21));
        label_31 = new QLabel(widget_members);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(970, 680, 51, 21));
        label_32 = new QLabel(widget_members);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(970, 640, 51, 21));
        label_33 = new QLabel(widget_members);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(970, 600, 51, 21));
        label_34 = new QLabel(widget_members);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(970, 560, 51, 21));
        member2_number5 = new QLineEdit(widget_members);
        member2_number5->setObjectName("member2_number5");
        member2_number5->setGeometry(QRect(1280, 400, 113, 23));
        member2_number4 = new QLineEdit(widget_members);
        member2_number4->setObjectName("member2_number4");
        member2_number4->setGeometry(QRect(1280, 360, 113, 23));
        member2_number3 = new QLineEdit(widget_members);
        member2_number3->setObjectName("member2_number3");
        member2_number3->setGeometry(QRect(1280, 320, 113, 23));
        member2_number6 = new QLineEdit(widget_members);
        member2_number6->setObjectName("member2_number6");
        member2_number6->setGeometry(QRect(1280, 440, 113, 23));
        member2_name8 = new QLineEdit(widget_members);
        member2_name8->setObjectName("member2_name8");
        member2_name8->setGeometry(QRect(1090, 520, 113, 23));
        member2_name7 = new QLineEdit(widget_members);
        member2_name7->setObjectName("member2_name7");
        member2_name7->setGeometry(QRect(1090, 480, 113, 23));
        member2_number7 = new QLineEdit(widget_members);
        member2_number7->setObjectName("member2_number7");
        member2_number7->setGeometry(QRect(1280, 480, 113, 23));
        member2_number8 = new QLineEdit(widget_members);
        member2_number8->setObjectName("member2_number8");
        member2_number8->setGeometry(QRect(1280, 520, 113, 23));
        member2_name11 = new QLineEdit(widget_members);
        member2_name11->setObjectName("member2_name11");
        member2_name11->setGeometry(QRect(1090, 640, 113, 23));
        member2_name10 = new QLineEdit(widget_members);
        member2_name10->setObjectName("member2_name10");
        member2_name10->setGeometry(QRect(1090, 600, 113, 23));
        member2_name9 = new QLineEdit(widget_members);
        member2_name9->setObjectName("member2_name9");
        member2_name9->setGeometry(QRect(1090, 560, 113, 23));
        member2_number10 = new QLineEdit(widget_members);
        member2_number10->setObjectName("member2_number10");
        member2_number10->setGeometry(QRect(1280, 600, 113, 23));
        member2_number9 = new QLineEdit(widget_members);
        member2_number9->setObjectName("member2_number9");
        member2_number9->setGeometry(QRect(1280, 560, 113, 23));
        member2_number2 = new QLineEdit(widget_members);
        member2_number2->setObjectName("member2_number2");
        member2_number2->setGeometry(QRect(1280, 280, 113, 23));
        member2_name12 = new QLineEdit(widget_members);
        member2_name12->setObjectName("member2_name12");
        member2_name12->setGeometry(QRect(1090, 680, 113, 23));
        member2_number12 = new QLineEdit(widget_members);
        member2_number12->setObjectName("member2_number12");
        member2_number12->setGeometry(QRect(1280, 680, 113, 23));
        member2_number11 = new QLineEdit(widget_members);
        member2_number11->setObjectName("member2_number11");
        member2_number11->setGeometry(QRect(1280, 640, 113, 23));
        back_to_teams = new QPushButton(widget_members);
        back_to_teams->setObjectName("back_to_teams");
        back_to_teams->setGeometry(QRect(650, 670, 91, 41));
        go_to_record = new QPushButton(widget_members);
        go_to_record->setObjectName("go_to_record");
        go_to_record->setGeometry(QRect(810, 670, 91, 41));
        label_28 = new QLabel(widget_members);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(140, 720, 51, 21));
        coach1_name = new QLineEdit(widget_members);
        coach1_name->setObjectName("coach1_name");
        coach1_name->setGeometry(QRect(260, 720, 113, 23));
        label_29 = new QLabel(widget_members);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(970, 720, 51, 21));
        coach2_name = new QLineEdit(widget_members);
        coach2_name->setObjectName("coach2_name");
        coach2_name->setGeometry(QRect(1090, 720, 113, 23));
        warning_member1 = new QLabel(widget_members);
        warning_member1->setObjectName("warning_member1");
        warning_member1->setGeometry(QRect(420, 160, 91, 16));
        warning_member2 = new QLabel(widget_members);
        warning_member2->setObjectName("warning_member2");
        warning_member2->setGeometry(QRect(1250, 160, 91, 16));
        widget_events->raise();
        widget_teams->raise();
        backbutton->raise();
        widget_members->raise();

        retranslateUi(record_mode);

        QMetaObject::connectSlotsByName(record_mode);
    } // setupUi

    void retranslateUi(QWidget *record_mode)
    {
        record_mode->setWindowTitle(QCoreApplication::translate("record_mode", "Form", nullptr));
        backbutton->setText(QCoreApplication::translate("record_mode", "\350\277\224\345\233\236", nullptr));
        label1_3->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:26pt;\">\347\220\203\351\230\2372</span></p></body></html>", nullptr));
        label1_5->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:20pt;\">\351\230\237\344\274\215\345\220\215\347\247\260</span></p></body></html>", nullptr));
        label1_4->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:20pt;\">\351\230\237\344\274\215\345\220\215\347\247\260</span></p></body></html>", nullptr));
        label1_2->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:26pt;\">\347\220\203\351\230\2371</span></p></body></html>", nullptr));
        label1_1->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:48pt;\">\350\257\267\350\276\223\345\205\245\347\220\203\351\230\237\344\277\241\346\201\257</span></p></body></html>", nullptr));
        label1_warn2->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" color:#ff0000;\">\350\257\267\345\241\253\345\206\231\351\230\237\344\274\215\345\220\215\347\247\260</span></p></body></html>", nullptr));
        label1_warn1->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" color:#ff0000;\">\350\257\267\345\241\253\345\206\231\351\230\237\344\274\215\345\220\215\347\247\260</span></p></body></html>", nullptr));
        label1_7->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:20pt;\">\351\230\237\345\221\230\346\225\260\347\233\256</span></p></body></html>", nullptr));
        membernum2->setItemText(0, QCoreApplication::translate("record_mode", "5", nullptr));
        membernum2->setItemText(1, QCoreApplication::translate("record_mode", "6", nullptr));
        membernum2->setItemText(2, QCoreApplication::translate("record_mode", "7", nullptr));
        membernum2->setItemText(3, QCoreApplication::translate("record_mode", "8", nullptr));
        membernum2->setItemText(4, QCoreApplication::translate("record_mode", "9", nullptr));
        membernum2->setItemText(5, QCoreApplication::translate("record_mode", "10", nullptr));
        membernum2->setItemText(6, QCoreApplication::translate("record_mode", "11", nullptr));
        membernum2->setItemText(7, QCoreApplication::translate("record_mode", "12", nullptr));

        back_to_event->setText(QCoreApplication::translate("record_mode", "\344\270\212\344\270\200\346\255\245", nullptr));
        go_to_members->setText(QCoreApplication::translate("record_mode", "\344\270\213\344\270\200\346\255\245", nullptr));
        label1_6->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:20pt;\">\351\230\237\345\221\230\346\225\260\347\233\256</span></p></body></html>", nullptr));
        membernum1->setItemText(0, QCoreApplication::translate("record_mode", "5", nullptr));
        membernum1->setItemText(1, QCoreApplication::translate("record_mode", "6", nullptr));
        membernum1->setItemText(2, QCoreApplication::translate("record_mode", "7", nullptr));
        membernum1->setItemText(3, QCoreApplication::translate("record_mode", "8", nullptr));
        membernum1->setItemText(4, QCoreApplication::translate("record_mode", "9", nullptr));
        membernum1->setItemText(5, QCoreApplication::translate("record_mode", "10", nullptr));
        membernum1->setItemText(6, QCoreApplication::translate("record_mode", "11", nullptr));
        membernum1->setItemText(7, QCoreApplication::translate("record_mode", "12", nullptr));

        label0_1->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:48pt;\">\350\257\267\350\276\223\345\205\245\346\257\224\350\265\233\344\277\241\346\201\257</span></p></body></html>", nullptr));
        go_to_teams->setText(QCoreApplication::translate("record_mode", "\344\270\213\344\270\200\346\255\245", nullptr));
        label0_2->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:20pt;\">\346\257\224\350\265\233\345\220\215\347\247\260</span></p></body></html>", nullptr));
        label0_3->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:20pt;\">\346\257\224\350\265\233\346\227\266\351\227\264</span></p></body></html>", nullptr));
        label0_4->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:20pt;\">\346\257\224\350\265\233\345\234\260\347\202\271</span></p></body></html>", nullptr));
        label0_6->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:20pt;\">\345\211\257\350\243\201\345\210\244\345\221\230</span></p></body></html>", nullptr));
        label0_5->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:20pt;\">\344\270\273\350\243\201\345\210\244\345\221\230</span></p></body></html>", nullptr));
        label2_1->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:48pt;\">\350\257\267\350\276\223\345\205\245\351\230\237\345\221\230\344\277\241\346\201\257</span></p></body></html>", nullptr));
        label2_2->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:26pt;\">\347\220\203\351\230\2371</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:18pt;\">\345\247\223\345\220\215</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:18pt;\">\347\220\203\350\241\243\345\217\267\347\240\201</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2301</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2302</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2303</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2304</span></p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2305</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2306</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\23012</span></p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\23011</span></p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2301</span></p></body></html>", nullptr));
        label_15->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2307</span></p></body></html>", nullptr));
        label_16->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2308</span></p></body></html>", nullptr));
        label_17->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\23010</span></p></body></html>", nullptr));
        label_18->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2309</span></p></body></html>", nullptr));
        label2_5->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:26pt;\">\347\220\203\351\230\2372</span></p></body></html>", nullptr));
        label_19->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:18pt;\">\345\247\223\345\220\215</span></p></body></html>", nullptr));
        label_20->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:18pt;\">\347\220\203\350\241\243\345\217\267\347\240\201</span></p></body></html>", nullptr));
        label_21->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2302</span></p></body></html>", nullptr));
        label_22->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2303</span></p></body></html>", nullptr));
        label_23->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2305</span></p></body></html>", nullptr));
        label_24->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2304</span></p></body></html>", nullptr));
        label_25->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2306</span></p></body></html>", nullptr));
        label_26->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2308</span></p></body></html>", nullptr));
        label_27->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2307</span></p></body></html>", nullptr));
        label_31->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\23012</span></p></body></html>", nullptr));
        label_32->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\23011</span></p></body></html>", nullptr));
        label_33->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\23010</span></p></body></html>", nullptr));
        label_34->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\351\230\237\345\221\2309</span></p></body></html>", nullptr));
        back_to_teams->setText(QCoreApplication::translate("record_mode", "\344\270\212\344\270\200\346\255\245", nullptr));
        go_to_record->setText(QCoreApplication::translate("record_mode", "\345\274\200\345\247\213\350\256\260\345\275\225", nullptr));
        label_28->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\225\231\347\273\203\345\221\230</span></p></body></html>", nullptr));
        label_29->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" font-size:12pt;\">\346\225\231\347\273\203\345\221\230</span></p></body></html>", nullptr));
        warning_member1->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" color:#ff0000;\">\350\257\267\350\276\223\345\205\245\345\256\214\346\225\264\344\277\241\346\201\257</span></p></body></html>", nullptr));
        warning_member2->setText(QCoreApplication::translate("record_mode", "<html><head/><body><p><span style=\" color:#ff0000;\">\350\257\267\350\276\223\345\205\245\345\256\214\346\225\264\344\277\241\346\201\257</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class record_mode: public Ui_record_mode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORD_MODE_H