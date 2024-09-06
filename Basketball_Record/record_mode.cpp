#include "record_mode.h"
#include "ui_record_mode.h"
#include "mainwindow.h"
#include<iostream>
#include<QApplication>
#include<QObject>
#include<QVBoxLayout>
#include<Qstring>
#include<QPainter>
#include<QPaintEvent>
using namespace std;

Team teama,teamb;
Game game;

string qstring_to_string(const QString& qstr)
{
    QByteArray localBytes = qstr.toLocal8Bit();
    return localBytes.data();
}

record_mode::record_mode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::record_mode)
{
    //this->setWindowState(Qt::WindowMaximized);
    ui->setupUi(this);
    this->move(150,60);
    setWindowTitle("篮球记录系统");
    ui->widget_teams->hide();
    ui->widget_members->hide();
}

record_mode::~record_mode()
{
    delete ui;
}

void record_mode::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(this->rect(),QPixmap("://pictures/980.png"));
}

void record_mode::on_backbutton_clicked()
{
    MainWindow *my = new MainWindow;
    my->setGeometry(my->geometry());
    my->show();
    this->close();
}

void record_mode::on_go_to_teams_clicked()
{
    ui->widget_events->hide();
    ui->widget_teams->show();
    ui->label1_warn1->hide();
    ui->label1_warn2->hide();
    ui->backbutton->hide();
}

void record_mode::on_back_to_event_clicked()
{
    ui->widget_teams->hide();
    ui->widget_events->show();
    ui->backbutton->show();
}

void record_mode::on_go_to_members_clicked()
{
    if(ui->teamname1->text()=="") ui->label1_warn1->show();
    else ui->label1_warn1->hide();
    if(ui->teamname2->text()=="") ui->label1_warn2->show();
    else ui->label1_warn2->hide();
    if(ui->teamname1->text()!=""&&ui->teamname2->text()!="")
    {
        ui->widget_teams->hide();
        ui->widget_members->show();
        ui->member1_name6->setReadOnly(false);ui->member1_name7->setReadOnly(false);ui->member1_name8->setReadOnly(false);ui->member1_name9->setReadOnly(false);ui->member1_name10->setReadOnly(false);ui->member1_name11->setReadOnly(false);ui->member1_name12->setReadOnly(false);
        ui->member2_name6->setReadOnly(false);ui->member2_name7->setReadOnly(false);ui->member2_name8->setReadOnly(false);ui->member2_name9->setReadOnly(false);ui->member2_name10->setReadOnly(false);ui->member2_name11->setReadOnly(false);ui->member2_name12->setReadOnly(false);
        ui->member1_number6->setReadOnly(false);ui->member1_number7->setReadOnly(false);ui->member1_number8->setReadOnly(false);ui->member1_number9->setReadOnly(false);ui->member1_number10->setReadOnly(false);ui->member1_number11->setReadOnly(false);ui->member1_number12->setReadOnly(false);
        ui->member2_number6->setReadOnly(false);ui->member2_number7->setReadOnly(false);ui->member2_number8->setReadOnly(false);ui->member2_number9->setReadOnly(false);ui->member2_number10->setReadOnly(false);ui->member2_number11->setReadOnly(false);ui->member2_number12->setReadOnly(false);
        ui->member1_name6->setText("");ui->member1_name7->setText("");ui->member1_name8->setText("");ui->member1_name9->setText("");ui->member1_name10->setText("");ui->member1_name11->setText("");ui->member1_name12->setText("");
        ui->member2_name6->setText("");ui->member2_name7->setText("");ui->member2_name8->setText("");ui->member2_name9->setText("");ui->member2_name10->setText("");ui->member2_name11->setText("");ui->member2_name12->setText("");
        ui->member1_number6->setText("");ui->member1_number7->setText("");ui->member1_number8->setText("");ui->member1_number9->setText("");ui->member1_number10->setText("");ui->member1_number11->setText("");ui->member1_number12->setText("");
        ui->member2_number6->setText("");ui->member2_number7->setText("");ui->member2_number8->setText("");ui->member2_number9->setText("");ui->member2_number10->setText("");ui->member2_number11->setText("");ui->member2_number12->setText("");
        int x=(ui->membernum1->currentIndex()+5);
        int y=(ui->membernum2->currentIndex()+5);
        switch(x){
        case 5:{ui->member1_name6->setReadOnly(true);ui->member1_number6->setReadOnly(true);ui->member1_name6->setText("         --------");ui->member1_number6->setText("         --------");}
        case 6:{ui->member1_name7->setReadOnly(true);ui->member1_number7->setReadOnly(true);ui->member1_name7->setText("         --------");ui->member1_number7->setText("         --------");}
        case 7:{ui->member1_name8->setReadOnly(true);ui->member1_number8->setReadOnly(true);ui->member1_name8->setText("         --------");ui->member1_number8->setText("         --------");}
        case 8:{ui->member1_name9->setReadOnly(true);ui->member1_number9->setReadOnly(true);ui->member1_name9->setText("         --------");ui->member1_number9->setText("         --------");}
        case 9:{ui->member1_name10->setReadOnly(true);ui->member1_number10->setReadOnly(true);ui->member1_name10->setText("         --------");ui->member1_number10->setText("         --------");}
        case 10:{ui->member1_name11->setReadOnly(true);ui->member1_number11->setReadOnly(true);ui->member1_name11->setText("         --------");ui->member1_number11->setText("         --------");}
        case 11:{ui->member1_name12->setReadOnly(true);ui->member1_number12->setReadOnly(true);ui->member1_name12->setText("         --------");ui->member1_number12->setText("         --------");}
        }
        switch(y){
        case 5:{ui->member2_name6->setReadOnly(true);ui->member2_number6->setReadOnly(true);ui->member2_name6->setText("         --------");ui->member2_number6->setText("         --------");}
        case 6:{ui->member2_name7->setReadOnly(true);ui->member2_number7->setReadOnly(true);ui->member2_name7->setText("         --------");ui->member2_number7->setText("         --------");}
        case 7:{ui->member2_name8->setReadOnly(true);ui->member2_number8->setReadOnly(true);ui->member2_name8->setText("         --------");ui->member2_number8->setText("         --------");}
        case 8:{ui->member2_name9->setReadOnly(true);ui->member2_number9->setReadOnly(true);ui->member2_name9->setText("         --------");ui->member2_number9->setText("         --------");}
        case 9:{ui->member2_name10->setReadOnly(true);ui->member2_number10->setReadOnly(true);ui->member2_name10->setText("         --------");ui->member2_number10->setText("         --------");}
        case 10:{ui->member2_name11->setReadOnly(true);ui->member2_number11->setReadOnly(true);ui->member2_name11->setText("         --------");ui->member2_number11->setText("         --------");}
        case 11:{ui->member2_name12->setReadOnly(true);ui->member2_number12->setReadOnly(true);ui->member2_name12->setText("         --------");ui->member2_number12->setText("         --------");}
        }
        ui->warning_member1->hide();
        ui->warning_member2->hide();
    }
}

void record_mode::on_back_to_teams_clicked()
{
    ui->widget_members->hide();
    ui->widget_teams->show();
}

void record_mode::on_go_to_record_clicked()
{
    bool check1=true,check2=true;
    if(ui->member1_name1->text()==""||ui->member1_name2->text()==""||ui->member1_name3->text()==""||ui->member1_name4->text()==""||ui->member1_name5->text()==""||ui->member1_name6->text()==""||ui->member1_name7->text()==""||ui->member1_name8->text()==""||ui->member1_name9->text()==""||ui->member1_name10->text()==""||ui->member1_name11->text()==""||ui->member1_name12->text()==""||ui->member1_number1->text()==""||ui->member1_number2->text()==""||ui->member1_number3->text()==""||ui->member1_number4->text()==""||ui->member1_number5->text()==""||ui->member1_number6->text()==""||ui->member1_number7->text()==""||ui->member1_number8->text()==""||ui->member1_number9->text()==""||ui->member1_number10->text()==""||ui->member1_number11->text()==""||ui->member1_number12->text()==""||ui->coach1_name->text()=="")
    {
        check1=false;
        ui->warning_member1->show();
    }
    else ui->warning_member1->hide();
    if(ui->member2_name1->text()==""||ui->member2_name2->text()==""||ui->member2_name3->text()==""||ui->member2_name4->text()==""||ui->member2_name5->text()==""||ui->member2_name6->text()==""||ui->member2_name7->text()==""||ui->member2_name8->text()==""||ui->member2_name9->text()==""||ui->member2_name10->text()==""||ui->member2_name11->text()==""||ui->member2_name12->text()==""||ui->member2_number1->text()==""||ui->member2_number2->text()==""||ui->member2_number3->text()==""||ui->member2_number4->text()==""||ui->member2_number5->text()==""||ui->member2_number6->text()==""||ui->member2_number7->text()==""||ui->member2_number8->text()==""||ui->member2_number9->text()==""||ui->member2_number10->text()==""||ui->member2_number11->text()==""||ui->member2_number12->text()==""||ui->coach2_name->text()=="")
    {
        check2=false;
        ui->warning_member2->show();
    }
    else ui->warning_member2->hide();
    if(check1&&check2)
    {
        ui->widget_members->hide();
        teama.name=qstring_to_string(ui->teamname1->text());
        teama.is_first_team=true;
        teama.num_of_player=ui->membernum1->currentIndex()+5;
        teamb.name=qstring_to_string(ui->teamname2->text());
        teamb.is_first_team=false;
        teamb.num_of_player=ui->membernum2->currentIndex()+5;
        teama.players[0]=new Player(qstring_to_string(ui->member1_name1->text()),qstring_to_string(ui->member1_number1->text()));teama.players[1]=new Player(qstring_to_string(ui->member1_name2->text()),qstring_to_string(ui->member1_number2->text()));teama.players[2]=new Player(qstring_to_string(ui->member1_name3->text()),qstring_to_string(ui->member1_number3->text()));teama.players[3]=new Player(qstring_to_string(ui->member1_name4->text()),qstring_to_string(ui->member1_number4->text()));teama.players[4]=new Player(qstring_to_string(ui->member1_name5->text()),qstring_to_string(ui->member1_number5->text()));
        teamb.players[0]=new Player(qstring_to_string(ui->member2_name1->text()),qstring_to_string(ui->member2_number1->text()));teamb.players[1]=new Player(qstring_to_string(ui->member2_name2->text()),qstring_to_string(ui->member2_number2->text()));teamb.players[2]=new Player(qstring_to_string(ui->member2_name3->text()),qstring_to_string(ui->member2_number3->text()));teamb.players[3]=new Player(qstring_to_string(ui->member2_name4->text()),qstring_to_string(ui->member2_number4->text()));teamb.players[4]=new Player(qstring_to_string(ui->member2_name5->text()),qstring_to_string(ui->member2_number5->text()));
        teama.head_coach=new Headcoach(qstring_to_string(ui->coach1_name->text()));
        teamb.head_coach=new Headcoach(qstring_to_string(ui->coach2_name->text()));
        game.game_name=qstring_to_string(ui->eventname->text());
        game.game_info=qstring_to_string(ui->eventtime->text())+"%"+qstring_to_string(ui->eventplace->text());
        game.team1=teama.name;
        game.team2=teamb.name;
        int x=(ui->membernum1->currentIndex()+5);
        int y=(ui->membernum2->currentIndex()+5);
        switch(x){
        case 12:teama.players[11]=new Player(qstring_to_string(ui->member1_name12->text()),qstring_to_string(ui->member1_number12->text()));
        case 11:teama.players[10]=new Player(qstring_to_string(ui->member1_name11->text()),qstring_to_string(ui->member1_number11->text()));
        case 10:teama.players[9]=new Player(qstring_to_string(ui->member1_name10->text()),qstring_to_string(ui->member1_number10->text()));
        case 9:teama.players[8]=new Player(qstring_to_string(ui->member1_name9->text()),qstring_to_string(ui->member1_number9->text()));
        case 8:teama.players[7]=new Player(qstring_to_string(ui->member1_name8->text()),qstring_to_string(ui->member1_number8->text()));
        case 7:teama.players[6]=new Player(qstring_to_string(ui->member1_name7->text()),qstring_to_string(ui->member1_number7->text()));
        case 6:teama.players[5]=new Player(qstring_to_string(ui->member1_name6->text()),qstring_to_string(ui->member1_number6->text()));
        }
        switch(y){
        case 12:teamb.players[11]=new Player(qstring_to_string(ui->member2_name12->text()),qstring_to_string(ui->member2_number12->text()));
        case 11:teamb.players[10]=new Player(qstring_to_string(ui->member2_name11->text()),qstring_to_string(ui->member2_number11->text()));
        case 10:teamb.players[9]=new Player(qstring_to_string(ui->member2_name10->text()),qstring_to_string(ui->member2_number10->text()));
        case 9:teamb.players[8]=new Player(qstring_to_string(ui->member2_name9->text()),qstring_to_string(ui->member2_number9->text()));
        case 8:teamb.players[7]=new Player(qstring_to_string(ui->member2_name8->text()),qstring_to_string(ui->member2_number8->text()));
        case 7:teamb.players[6]=new Player(qstring_to_string(ui->member2_name7->text()),qstring_to_string(ui->member2_number7->text()));
        case 6:teamb.players[5]=new Player(qstring_to_string(ui->member2_name6->text()),qstring_to_string(ui->member2_number6->text()));
        }
        emit sentdata(teama,teamb,game);
        this->close();
    }
}


