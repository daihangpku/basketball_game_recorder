#include "record.h"
#include "record_mode.h"
#include "ui_record.h"
#include "save.h"
#include "mainwindow.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<QApplication>
#include<QObject>
#include<QVBoxLayout>
#include<Qstring>
#include<QDialog>
#include<vector>
#include<QTimer>
#include<QTime>
#include<QTimerEvent>
#include<QPainter>
#include<QPaintEvent>

Event* EVENT[10000];
Game game0;
int event_num=0;
Team team1,team2;
int GET=0;
int current_time=0;
int quarter=1;//1~4
bool FOUL=false;
char FOUL_who='x';
char FOUL_cate='x';
int FOUL_num=-1;

QString string_to_qstring(const string& str)
{
    return QString(QString::fromLocal8Bit(str));
}

string qstring_to_string0(const QString& qstr)
{
    QByteArray localBytes = qstr.toLocal8Bit();
    return localBytes.data();
}

record::record(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::record)
{
    ui->setupUi(this);
    this->move(150,60);
    setWindowTitle("篮球记录系统");
    //this->setWindowState(Qt::WindowMaximized);
    record_mode *my = new record_mode;
    my->setGeometry(my->geometry());
    my->show();
    connect(my, SIGNAL(sentdata(Team,Team,Game)), this, SLOT(receivedata(Team,Team,Game)));
    connect(&timer1,SIGNAL(timeout()),this,SLOT(timeout1_slot()));
    connect(&timer2,SIGNAL(timeout()),this,SLOT(timeout2_slot()));
    time1.setHMS(0,0,0,0);
    time2.setHMS(0,0,0,0);
    ui->team1_widget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->team2_widget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->team1_widget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->team2_widget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->team1_total_quarter->setSelectionMode(QAbstractItemView::NoSelection);
    ui->team1_total_quarter->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->team1_total->setSelectionMode(QAbstractItemView::NoSelection);
    ui->team1_total->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->team2_total_quarter->setSelectionMode(QAbstractItemView::NoSelection);
    ui->team2_total_quarter->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->team2_total->setSelectionMode(QAbstractItemView::NoSelection);
    ui->team2_total->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->timeout_team1->hide();
    ui->timeout_team2->hide();
    ui->widget_foul->hide();
    ui->confirm_to_next_quarter->hide();
    ui->select_player->hide();
    ui->get1->hide();
    ui->get2->hide();
    ui->get3->hide();
    ui->foul->hide();
    ui->timeout->hide();
    ui->reset->hide();
    ui->smalltime_freeze->hide();
    ui->smalltime_continue->hide();
    ui->bigtime_continue->hide();
    ui->bigtime_freeze->hide();
    ui->comfirm_end->hide();
    ui->not_end->hide();
    ui->end_record->hide();
}

record::~record()
{
    delete ui;
}

void record::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(this->rect(),QPixmap("://pictures/R-C.png"));
}

void record::receivedata(Team a,Team b,Game c)
{
    team1=a;
    team2=b;
    game0=c;
    this->show();
    ui->team1_coach->setText(string_to_qstring(team1.head_coach->name));
    ui->team2_coach->setText(string_to_qstring(team2.head_coach->name));
    ui->team1_name->setText(string_to_qstring(team1.name));
    ui->team2_name->setText(string_to_qstring(team2.name));
    ui->team1_member1->setText(string_to_qstring(team1.players[0]->name));ui->team1_widget->item(0,0)->setText(string_to_qstring(team1.players[0]->num));
    ui->team1_member2->setText(string_to_qstring(team1.players[1]->name));ui->team1_widget->item(1,0)->setText(string_to_qstring(team1.players[1]->num));
    ui->team1_member3->setText(string_to_qstring(team1.players[2]->name));ui->team1_widget->item(2,0)->setText(string_to_qstring(team1.players[2]->num));
    ui->team1_member4->setText(string_to_qstring(team1.players[3]->name));ui->team1_widget->item(3,0)->setText(string_to_qstring(team1.players[3]->num));
    ui->team1_member5->setText(string_to_qstring(team1.players[4]->name));ui->team1_widget->item(4,0)->setText(string_to_qstring(team1.players[4]->num));
    switch(team1.num_of_player){
    case 12:{ui->team1_member12->setText(string_to_qstring(team1.players[11]->name));ui->team1_widget->item(11,0)->setText(string_to_qstring(team1.players[11]->num));}
    case 11:{ui->team1_member11->setText(string_to_qstring(team1.players[10]->name));ui->team1_widget->item(10,0)->setText(string_to_qstring(team1.players[10]->num));}
    case 10:{ui->team1_member10->setText(string_to_qstring(team1.players[9]->name));ui->team1_widget->item(9,0)->setText(string_to_qstring(team1.players[9]->num));}
    case 9:{ui->team1_member9->setText(string_to_qstring(team1.players[8]->name));ui->team1_widget->item(8,0)->setText(string_to_qstring(team1.players[8]->num));}
    case 8:{ui->team1_member8->setText(string_to_qstring(team1.players[7]->name));ui->team1_widget->item(7,0)->setText(string_to_qstring(team1.players[7]->num));}
    case 7:{ui->team1_member7->setText(string_to_qstring(team1.players[6]->name));ui->team1_widget->item(6,0)->setText(string_to_qstring(team1.players[6]->num));}
    case 6:{ui->team1_member6->setText(string_to_qstring(team1.players[5]->name));ui->team1_widget->item(5,0)->setText(string_to_qstring(team1.players[5]->num));}
    }
    ui->team2_member1->setText(string_to_qstring(team2.players[0]->name));ui->team2_widget->item(0,0)->setText(string_to_qstring(team2.players[0]->num));
    ui->team2_member2->setText(string_to_qstring(team2.players[1]->name));ui->team2_widget->item(1,0)->setText(string_to_qstring(team2.players[1]->num));
    ui->team2_member3->setText(string_to_qstring(team2.players[2]->name));ui->team2_widget->item(2,0)->setText(string_to_qstring(team2.players[2]->num));
    ui->team2_member4->setText(string_to_qstring(team2.players[3]->name));ui->team2_widget->item(3,0)->setText(string_to_qstring(team2.players[3]->num));
    ui->team2_member5->setText(string_to_qstring(team2.players[4]->name));ui->team2_widget->item(4,0)->setText(string_to_qstring(team2.players[4]->num));
    switch(team2.num_of_player){
    case 12:{ui->team2_member12->setText(string_to_qstring(team2.players[11]->name));ui->team2_widget->item(11,0)->setText(string_to_qstring(team2.players[11]->num));}
    case 11:{ui->team2_member11->setText(string_to_qstring(team2.players[10]->name));ui->team2_widget->item(10,0)->setText(string_to_qstring(team2.players[10]->num));}
    case 10:{ui->team2_member10->setText(string_to_qstring(team2.players[9]->name));ui->team2_widget->item(9,0)->setText(string_to_qstring(team2.players[9]->num));}
    case 9:{ui->team2_member9->setText(string_to_qstring(team2.players[8]->name));ui->team2_widget->item(8,0)->setText(string_to_qstring(team2.players[8]->num));}
    case 8:{ui->team2_member8->setText(string_to_qstring(team2.players[7]->name));ui->team2_widget->item(7,0)->setText(string_to_qstring(team2.players[7]->num));}
    case 7:{ui->team2_member7->setText(string_to_qstring(team2.players[6]->name));ui->team2_widget->item(6,0)->setText(string_to_qstring(team2.players[6]->num));}
    case 6:{ui->team2_member6->setText(string_to_qstring(team2.players[5]->name));ui->team2_widget->item(5,0)->setText(string_to_qstring(team2.players[5]->num));}
    }
    switch(team1.num_of_player){
    case 5:{ui->team1_member6->setCheckable(false);ui->team1_member6->setText(" -----");ui->team1_widget->item(5,0)->setText(" ---");ui->team1_widget->item(5,1)->setText(" ---");ui->team1_widget->item(5,2)->setText(" ---");}
    case 6:{ui->team1_member7->setCheckable(false);ui->team1_member7->setText(" -----");ui->team1_widget->item(6,0)->setText(" ---");ui->team1_widget->item(6,1)->setText(" ---");ui->team1_widget->item(6,2)->setText(" ---");}
    case 7:{ui->team1_member8->setCheckable(false);ui->team1_member8->setText(" -----");ui->team1_widget->item(7,0)->setText(" ---");ui->team1_widget->item(7,1)->setText(" ---");ui->team1_widget->item(7,2)->setText(" ---");}
    case 8:{ui->team1_member9->setCheckable(false);ui->team1_member9->setText(" -----");ui->team1_widget->item(8,0)->setText(" ---");ui->team1_widget->item(8,1)->setText(" ---");ui->team1_widget->item(8,2)->setText(" ---");}
    case 9:{ui->team1_member10->setCheckable(false);ui->team1_member10->setText(" -----");ui->team1_widget->item(9,0)->setText(" ---");ui->team1_widget->item(9,1)->setText(" ---");ui->team1_widget->item(9,2)->setText(" ---");}
    case 10:{ui->team1_member11->setCheckable(false);ui->team1_member11->setText(" -----");ui->team1_widget->item(10,0)->setText(" ---");ui->team1_widget->item(10,1)->setText(" ---");ui->team1_widget->item(10,2)->setText(" ---");}
    case 11:{ui->team1_member12->setCheckable(false);ui->team1_member12->setText(" -----");ui->team1_widget->item(11,0)->setText(" ---");ui->team1_widget->item(11,1)->setText(" ---");ui->team1_widget->item(11,2)->setText(" ---");}
    }
    switch(team2.num_of_player){
    case 5:{ui->team2_member6->setCheckable(false);ui->team2_member6->setText(" -----");ui->team2_widget->item(5,0)->setText(" ---");ui->team2_widget->item(5,1)->setText(" ---");ui->team2_widget->item(5,2)->setText(" ---");}
    case 6:{ui->team2_member7->setCheckable(false);ui->team2_member7->setText(" -----");ui->team2_widget->item(6,0)->setText(" ---");ui->team2_widget->item(6,1)->setText(" ---");ui->team2_widget->item(6,2)->setText(" ---");}
    case 7:{ui->team2_member8->setCheckable(false);ui->team2_member8->setText(" -----");ui->team2_widget->item(7,0)->setText(" ---");ui->team2_widget->item(7,1)->setText(" ---");ui->team2_widget->item(7,2)->setText(" ---");}
    case 8:{ui->team2_member9->setCheckable(false);ui->team2_member9->setText(" -----");ui->team2_widget->item(8,0)->setText(" ---");ui->team2_widget->item(8,1)->setText(" ---");ui->team2_widget->item(8,2)->setText(" ---");}
    case 9:{ui->team2_member10->setCheckable(false);ui->team2_member10->setText(" -----");ui->team2_widget->item(9,0)->setText(" ---");ui->team2_widget->item(9,1)->setText(" ---");ui->team2_widget->item(9,2)->setText(" ---");}
    case 10:{ui->team2_member11->setCheckable(false);ui->team2_member11->setText(" -----");ui->team2_widget->item(10,0)->setText(" ---");ui->team2_widget->item(10,1)->setText(" ---");ui->team2_widget->item(10,2)->setText(" ---");}
    case 11:{ui->team2_member12->setCheckable(false);ui->team2_member12->setText(" -----");ui->team2_widget->item(11,0)->setText(" ---");ui->team2_widget->item(11,1)->setText(" ---");ui->team2_widget->item(11,2)->setText(" ---");}
    }
}

void record::on_get1_clicked()
{
    GET=1;
    ui->select_player->show();
    FOUL=false;
    FOUL_who='x';
    FOUL_cate='x';
    FOUL_num=-1;
    ui->widget_foul->hide();
    ui->timeout_team1->hide();
    ui->timeout_team2->hide();
    string time=qstring_to_string0(ui->bigtime->text());
    current_time=(time[0]-'0')*600+(time[1]-'0')*60+(time[3]-'0')*10+(time[4]-'0');
}

void record::on_get2_clicked()
{
    GET=2;
    ui->select_player->show();
    FOUL=false;
    FOUL_who='x';
    FOUL_cate='x';
    FOUL_num=-1;
    ui->widget_foul->hide();
    ui->timeout_team1->hide();
    ui->timeout_team2->hide();
    string time=qstring_to_string0(ui->bigtime->text());
    current_time=(time[0]-'0')*600+(time[1]-'0')*60+(time[3]-'0')*10+(time[4]-'0');
}

void record::on_get3_clicked()
{
    GET=3;
    ui->select_player->show();
    FOUL=false;
    FOUL_who='x';
    FOUL_cate='x';
    FOUL_num=-1;
    ui->widget_foul->hide();
    ui->timeout_team1->hide();
    ui->timeout_team2->hide();
    string time=qstring_to_string0(ui->bigtime->text());
    current_time=(time[0]-'0')*600+(time[1]-'0')*60+(time[3]-'0')*10+(time[4]-'0');
}

void record::on_foul_clicked()
{
    GET=0;
    FOUL=true;
    FOUL_who='x';
    FOUL_cate='x';
    FOUL_num=-1;
    ui->select_player->hide();
    ui->timeout_team1->hide();
    ui->timeout_team2->hide();
    ui->widget_foul->show();
    ui->foul_man->show();
    ui->foul_coach->show();
    ui->foul_player->show();
    ui->foul_detail->hide();
    ui->player_P->hide();
    ui->player_T->hide();
    ui->player_U->hide();
    ui->coach_B->hide();
    ui->coach_C->hide();
    ui->D->hide();
    ui->foul_0->hide();
    ui->foul_1->hide();
    ui->foul_2->hide();
    ui->foul_3->hide();
    ui->seefoul_cate->setText("");
    ui->seefoul_num->setText("");
    string time=qstring_to_string0(ui->bigtime->text());
    current_time=(time[0]-'0')*600+(time[1]-'0')*60+(time[3]-'0')*10+(time[4]-'0');
}

void record::on_foul_player_clicked()
{
    FOUL_who='P';
    ui->foul_man->hide();
    ui->foul_coach->hide();
    ui->foul_player->hide();
    ui->foul_detail->show();
    ui->player_P->show();
    ui->player_T->show();
    ui->player_U->show();
    ui->D->show();
    ui->foul_0->show();
    ui->foul_1->show();
    ui->foul_2->show();
    ui->foul_3->show();
}

void record::on_foul_coach_clicked()
{
    FOUL_who='C';
    ui->foul_man->hide();
    ui->foul_coach->hide();
    ui->foul_player->hide();
    ui->foul_detail->show();
    ui->coach_B->show();
    ui->coach_C->show();
    ui->D->show();
    ui->foul_0->show();
    ui->foul_1->show();
    ui->foul_2->show();
    ui->foul_3->show();
}

void record::on_player_P_clicked()
{
    FOUL_cate='P';
    ui->seefoul_cate->setText("P");
}

void record::on_player_T_clicked()
{
    FOUL_cate='T';
    ui->seefoul_cate->setText("T");
}

void record::on_player_U_clicked()
{
    FOUL_cate='U';
    ui->seefoul_cate->setText("U");
}

void record::on_D_clicked()
{
    FOUL_cate='D';
    ui->seefoul_cate->setText("D");
}

void record::on_coach_B_clicked()
{
    FOUL_cate='B';
    ui->seefoul_cate->setText("B");
}

void record::on_coach_C_clicked()
{
    FOUL_cate='C';
    ui->seefoul_cate->setText("C");
}

void record::on_foul_0_clicked()
{
    FOUL_num=0;
    ui->seefoul_num->setText("0");
}

void record::on_foul_1_clicked()
{
    FOUL_num=1;
    ui->seefoul_num->setText("1");
}

void record::on_foul_2_clicked()
{
    FOUL_num=2;
    ui->seefoul_num->setText("2");
}

void record::on_foul_3_clicked()
{
    FOUL_num=3;
    ui->seefoul_num->setText("3");
}

void record::on_timeout_clicked()
{
    GET=0;
    FOUL=false;
    FOUL_who='x';
    FOUL_cate='x';
    FOUL_num=-1;
    ui->select_player->hide();
    ui->widget_foul->hide();
    ui->timeout_team1->show();
    ui->timeout_team2->show();
    string time=qstring_to_string0(ui->bigtime->text());
    current_time=(time[0]-'0')*600+(time[1]-'0')*60+(time[3]-'0')*10+(time[4]-'0');
}

void record::on_timeout_team1_clicked()
{
    team1.get_timeout(current_time,quarter-1);
    ui->timeout_team1->hide();
    ui->timeout_team2->hide();
    EVENT[event_num]=new Timeout_event("timeout",pair(current_time,quarter),1);
    event_num++;
    ui->team1_total->item(0,2)->setText(QString::number(team1.get_available_timeout(current_time,quarter-1)));
}

void record::on_timeout_team2_clicked()
{
    team2.get_timeout(current_time,quarter-1);
    ui->timeout_team1->hide();
    ui->timeout_team2->hide();
    EVENT[event_num]=new Timeout_event("timeout",pair(current_time,quarter),2);
    event_num++;
    ui->team2_total->item(0,2)->setText(QString::number(team2.get_available_timeout(current_time,quarter-1)));
}

void record::on_reset_clicked()
{
    GET=0;
    FOUL=false;
    FOUL_who='x';
    FOUL_cate='x';
    FOUL_num=-1;
    ui->select_player->hide();
    ui->widget_foul->hide();
    ui->timeout_team1->hide();
    ui->timeout_team2->hide();
}

void record::on_team1_member1_clicked()
{
    if(GET){
        team1.get_score(team1.players[0],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),1,0,GET);
        event_num++;
        ui->team1_widget->item(0,1)->setText(QString::number(team1.players[0]->total_score));
        ui->team1_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team1.score_of_each_quarter[min(quarter-1,4)]));
        ui->team1_total->item(0,0)->setText(QString::number(team1.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team1.get_foul(team1.players[0],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),1,0,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team1_widget->item(0,2)->setText(QString::number(team1.players[0]->total_foul));
        ui->team1_total->item(0,1)->setText(QString::number(team1.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team1_member2_clicked()
{
    if(GET){
        team1.get_score(team1.players[1],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),1,1,GET);
        event_num++;
        ui->team1_widget->item(1,1)->setText(QString::number(team1.players[1]->total_score));
        ui->team1_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team1.score_of_each_quarter[min(quarter-1,4)]));
        ui->team1_total->item(0,0)->setText(QString::number(team1.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team1.get_foul(team1.players[1],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),1,1,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team1_widget->item(1,2)->setText(QString::number(team1.players[1]->total_foul));
        ui->team1_total->item(0,1)->setText(QString::number(team1.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team1_member3_clicked()
{
    if(GET){
        team1.get_score(team1.players[2],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),1,2,GET);
        event_num++;
        ui->team1_widget->item(2,1)->setText(QString::number(team1.players[2]->total_score));
        ui->team1_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team1.score_of_each_quarter[min(quarter-1,4)]));
        ui->team1_total->item(0,0)->setText(QString::number(team1.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team1.get_foul(team1.players[2],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),1,2,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team1_widget->item(2,2)->setText(QString::number(team1.players[2]->total_foul));
        ui->team1_total->item(0,1)->setText(QString::number(team1.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team1_member4_clicked()
{
    if(GET){
        team1.get_score(team1.players[3],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),1,3,GET);
        event_num++;
        ui->team1_widget->item(3,1)->setText(QString::number(team1.players[3]->total_score));
        ui->team1_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team1.score_of_each_quarter[min(quarter-1,4)]));
        ui->team1_total->item(0,0)->setText(QString::number(team1.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team1.get_foul(team1.players[3],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),1,3,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team1_widget->item(3,2)->setText(QString::number(team1.players[3]->total_foul));
        ui->team1_total->item(0,1)->setText(QString::number(team1.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team1_member5_clicked()
{
    if(GET){
        team1.get_score(team1.players[4],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),1,4,GET);
        event_num++;
        ui->team1_widget->item(4,1)->setText(QString::number(team1.players[4]->total_score));
        ui->team1_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team1.score_of_each_quarter[min(quarter-1,4)]));
        ui->team1_total->item(0,0)->setText(QString::number(team1.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team1.get_foul(team1.players[4],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),1,4,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team1_widget->item(4,2)->setText(QString::number(team1.players[4]->total_foul));
        ui->team1_total->item(0,1)->setText(QString::number(team1.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team1_member6_clicked()
{
    if(GET){
        team1.get_score(team1.players[5],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),1,5,GET);
        event_num++;
        ui->team1_widget->item(5,1)->setText(QString::number(team1.players[5]->total_score));
        ui->team1_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team1.score_of_each_quarter[min(quarter-1,4)]));
        ui->team1_total->item(0,0)->setText(QString::number(team1.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team1.get_foul(team1.players[5],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),1,5,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team1_widget->item(5,2)->setText(QString::number(team1.players[5]->total_foul));
        ui->team1_total->item(0,1)->setText(QString::number(team1.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team1_member7_clicked()
{
    if(GET){
        team1.get_score(team1.players[6],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),1,6,GET);
        event_num++;
        ui->team1_widget->item(6,1)->setText(QString::number(team1.players[6]->total_score));
        ui->team1_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team1.score_of_each_quarter[min(quarter-1,4)]));
        ui->team1_total->item(0,0)->setText(QString::number(team1.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team1.get_foul(team1.players[6],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),1,6,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team1_widget->item(6,2)->setText(QString::number(team1.players[6]->total_foul));
        ui->team1_total->item(0,1)->setText(QString::number(team1.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team1_member8_clicked()
{
    if(GET){
        team1.get_score(team1.players[7],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),1,7,GET);
        event_num++;
        ui->team1_widget->item(7,1)->setText(QString::number(team1.players[7]->total_score));
        ui->team1_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team1.score_of_each_quarter[min(quarter-1,4)]));
        ui->team1_total->item(0,0)->setText(QString::number(team1.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team1.get_foul(team1.players[7],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),1,7,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team1_widget->item(7,2)->setText(QString::number(team1.players[7]->total_foul));
        ui->team1_total->item(0,1)->setText(QString::number(team1.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team1_member9_clicked()
{
    if(GET){
        team1.get_score(team1.players[8],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),1,8,GET);
        event_num++;
        ui->team1_widget->item(8,1)->setText(QString::number(team1.players[8]->total_score));
        ui->team1_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team1.score_of_each_quarter[min(quarter-1,4)]));
        ui->team1_total->item(0,0)->setText(QString::number(team1.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team1.get_foul(team1.players[8],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),1,8,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team1_widget->item(8,2)->setText(QString::number(team1.players[8]->total_foul));
        ui->team1_total->item(0,1)->setText(QString::number(team1.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team1_member10_clicked()
{
    if(GET){
        team1.get_score(team1.players[9],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),1,9,GET);
        event_num++;
        ui->team1_widget->item(9,1)->setText(QString::number(team1.players[9]->total_score));
        ui->team1_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team1.score_of_each_quarter[min(quarter-1,4)]));
        ui->team1_total->item(0,0)->setText(QString::number(team1.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team1.get_foul(team1.players[9],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),1,9,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team1_widget->item(9,2)->setText(QString::number(team1.players[9]->total_foul));
        ui->team1_total->item(0,1)->setText(QString::number(team1.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team1_member11_clicked()
{
    if(GET){
        team1.get_score(team1.players[10],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),1,10,GET);
        event_num++;
        ui->team1_widget->item(10,1)->setText(QString::number(team1.players[10]->total_score));
        ui->team1_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team1.score_of_each_quarter[min(quarter-1,4)]));
        ui->team1_total->item(0,0)->setText(QString::number(team1.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team1.get_foul(team1.players[10],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),1,10,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team1_widget->item(10,2)->setText(QString::number(team1.players[10]->total_foul));
        ui->team1_total->item(0,1)->setText(QString::number(team1.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team1_member12_clicked()
{
    if(GET){
        team1.get_score(team1.players[11],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),1,11,GET);
        event_num++;
        ui->team1_widget->item(11,1)->setText(QString::number(team1.players[11]->total_score));
        ui->team1_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team1.score_of_each_quarter[min(quarter-1,4)]));
        ui->team1_total->item(0,0)->setText(QString::number(team1.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team1.get_foul(team1.players[11],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),1,11,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team1_widget->item(11,2)->setText(QString::number(team1.players[11]->total_foul));
        ui->team1_total->item(0,1)->setText(QString::number(team1.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team2_member1_clicked()
{
    if(GET){
        team2.get_score(team2.players[0],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),2,0,GET);
        event_num++;
        ui->team2_widget->item(0,1)->setText(QString::number(team2.players[0]->total_score));
        ui->team2_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team2.score_of_each_quarter[min(quarter-1,4)]));
        ui->team2_total->item(0,0)->setText(QString::number(team2.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team2.get_foul(team2.players[0],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),2,0,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team2_widget->item(0,2)->setText(QString::number(team2.players[0]->total_foul));
        ui->team2_total->item(0,1)->setText(QString::number(team2.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team2_member2_clicked()
{
    if(GET){
        team2.get_score(team2.players[1],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),2,1,GET);
        event_num++;
        ui->team2_widget->item(1,1)->setText(QString::number(team2.players[1]->total_score));
        ui->team2_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team2.score_of_each_quarter[min(quarter-1,4)]));
        ui->team2_total->item(0,0)->setText(QString::number(team2.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team2.get_foul(team2.players[1],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),2,1,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team2_widget->item(1,2)->setText(QString::number(team2.players[1]->total_foul));
        ui->team2_total->item(0,1)->setText(QString::number(team2.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team2_member3_clicked()
{
    if(GET){
        team2.get_score(team2.players[2],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),2,2,GET);
        event_num++;
        ui->team2_widget->item(2,1)->setText(QString::number(team2.players[2]->total_score));
        ui->team2_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team2.score_of_each_quarter[min(quarter-1,4)]));
        ui->team2_total->item(0,0)->setText(QString::number(team2.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team2.get_foul(team2.players[2],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),2,2,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team2_widget->item(2,2)->setText(QString::number(team2.players[2]->total_foul));
        ui->team2_total->item(0,1)->setText(QString::number(team2.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team2_member4_clicked()
{
    if(GET){
        team2.get_score(team2.players[3],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),2,3,GET);
        event_num++;
        ui->team2_widget->item(3,1)->setText(QString::number(team2.players[3]->total_score));
        ui->team2_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team2.score_of_each_quarter[min(quarter-1,4)]));
        ui->team2_total->item(0,0)->setText(QString::number(team2.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team2.get_foul(team2.players[3],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),2,3,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team2_widget->item(3,2)->setText(QString::number(team2.players[3]->total_foul));
        ui->team2_total->item(0,1)->setText(QString::number(team2.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team2_member5_clicked()
{
    if(GET){
        team2.get_score(team2.players[4],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),2,4,GET);
        event_num++;
        ui->team2_widget->item(4,1)->setText(QString::number(team2.players[4]->total_score));
        ui->team2_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team2.score_of_each_quarter[min(quarter-1,4)]));
        ui->team2_total->item(0,0)->setText(QString::number(team2.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team2.get_foul(team2.players[4],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),2,4,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team2_widget->item(4,2)->setText(QString::number(team2.players[4]->total_foul));
        ui->team2_total->item(0,1)->setText(QString::number(team2.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team2_member6_clicked()
{
    if(GET){
        team2.get_score(team2.players[5],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),2,5,GET);
        event_num++;
        ui->team2_widget->item(5,1)->setText(QString::number(team2.players[5]->total_score));
        ui->team2_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team2.score_of_each_quarter[min(quarter-1,4)]));
        ui->team2_total->item(0,0)->setText(QString::number(team2.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team2.get_foul(team2.players[5],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),2,5,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team2_widget->item(5,2)->setText(QString::number(team2.players[5]->total_foul));
        ui->team2_total->item(0,1)->setText(QString::number(team2.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team2_member7_clicked()
{
    if(GET){
        team2.get_score(team2.players[6],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),2,6,GET);
        event_num++;
        ui->team2_widget->item(6,1)->setText(QString::number(team2.players[6]->total_score));
        ui->team2_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team2.score_of_each_quarter[min(quarter-1,4)]));
        ui->team2_total->item(0,0)->setText(QString::number(team2.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team2.get_foul(team2.players[6],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),2,6,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team2_widget->item(6,2)->setText(QString::number(team2.players[6]->total_foul));
        ui->team2_total->item(0,1)->setText(QString::number(team2.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team2_member8_clicked()
{
    if(GET){
        team2.get_score(team2.players[7],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),2,7,GET);
        event_num++;
        ui->team2_widget->item(7,1)->setText(QString::number(team2.players[7]->total_score));
        ui->team2_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team2.score_of_each_quarter[min(quarter-1,4)]));
        ui->team2_total->item(0,0)->setText(QString::number(team2.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team2.get_foul(team2.players[7],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),2,7,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team2_widget->item(7,2)->setText(QString::number(team2.players[7]->total_foul));
        ui->team2_total->item(0,1)->setText(QString::number(team2.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team2_member9_clicked()
{
    if(GET){
        team2.get_score(team2.players[8],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),2,8,GET);
        event_num++;
        ui->team2_widget->item(8,1)->setText(QString::number(team2.players[8]->total_score));
        ui->team2_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team2.score_of_each_quarter[min(quarter-1,4)]));
        ui->team2_total->item(0,0)->setText(QString::number(team2.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team2.get_foul(team2.players[8],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),2,8,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team2_widget->item(8,2)->setText(QString::number(team2.players[8]->total_foul));
        ui->team2_total->item(0,1)->setText(QString::number(team2.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team2_member10_clicked()
{
    if(GET){
        team2.get_score(team2.players[9],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),2,9,GET);
        event_num++;
        ui->team2_widget->item(9,1)->setText(QString::number(team2.players[9]->total_score));
        ui->team2_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team2.score_of_each_quarter[min(quarter-1,4)]));
        ui->team2_total->item(0,0)->setText(QString::number(team2.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team2.get_foul(team2.players[9],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),2,9,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team2_widget->item(9,2)->setText(QString::number(team2.players[9]->total_foul));
        ui->team2_total->item(0,1)->setText(QString::number(team2.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team2_member11_clicked()
{
    if(GET){
        team2.get_score(team2.players[10],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),2,10,GET);
        event_num++;
        ui->team2_widget->item(10,1)->setText(QString::number(team2.players[10]->total_score));
        ui->team2_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team2.score_of_each_quarter[min(quarter-1,4)]));
        ui->team2_total->item(0,0)->setText(QString::number(team2.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team2.get_foul(team2.players[10],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),2,10,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team2_widget->item(10,2)->setText(QString::number(team2.players[10]->total_foul));
        ui->team2_total->item(0,1)->setText(QString::number(team2.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team2_member12_clicked()
{
    if(GET){
        team2.get_score(team2.players[11],GET,current_time,quarter-1);
        EVENT[event_num]=new Score_event("score",pair(current_time,quarter),2,11,GET);
        event_num++;
        ui->team2_widget->item(11,1)->setText(QString::number(team2.players[11]->total_score));
        ui->team2_total_quarter->item(0,min(quarter-1,4))->setText(QString::number(team2.score_of_each_quarter[min(quarter-1,4)]));
        ui->team2_total->item(0,0)->setText(QString::number(team2.total_team_score));
        GET=0;
        ui->select_player->hide();
    }
    else if(FOUL&&FOUL_who=='P'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team2.get_foul(team2.players[11],FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),2,11,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team2_widget->item(11,2)->setText(QString::number(team2.players[11]->total_foul));
        ui->team2_total->item(0,1)->setText(QString::number(team2.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team1_coach_clicked()
{
    if(FOUL&&FOUL_who=='C'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team1.head_coach->get_foul(FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),1,-1,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team1_widget->item(12,2)->setText(QString::number(team1.head_coach->total_foul));
        ui->team1_total->item(0,1)->setText(QString::number(team1.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_team2_coach_clicked()
{
    if(FOUL&&FOUL_who=='C'&&FOUL_cate!='x'&&FOUL_num!=-1){
        team2.head_coach->get_foul(FOUL_num,FOUL_cate,current_time,quarter-1);
        EVENT[event_num]=new Foul_event("foul",pair(current_time,quarter),2,-1,Foul(FOUL_num,FOUL_cate,current_time));
        event_num++;
        ui->team2_widget->item(12,2)->setText(QString::number(team2.head_coach->total_foul));
        ui->team2_total->item(0,1)->setText(QString::number(team2.team_foul_cnt[min(quarter-1,3)]));
        FOUL=false;
        FOUL_who='x';
        FOUL_cate='x';
        FOUL_num=-1;
        ui->widget_foul->hide();
    }
}

void record::on_will_next_quarter_clicked()
{
    ui->confirm_to_next_quarter->show();
    GET=0;
    FOUL=false;
    FOUL_who='x';
    FOUL_cate='x';
    FOUL_num=-1;
    ui->widget_foul->hide();
    ui->timeout_team1->hide();
    ui->timeout_team2->hide();
    ui->select_player->hide();
}

void record::on_not_next_quarter_clicked()
{
    ui->confirm_to_next_quarter->hide();
}

void record::on_next_quarter_clicked()
{
    quarter++;
    ui->team1_total->item(0,1)->setText("0");
    ui->team2_total->item(0,1)->setText("0");
    if(quarter==2){
        ui->quarternum->setText("当前节数：第2节");
    }
    if(quarter==3){
        ui->quarternum->setText("当前节数：第3节");
    }
    if(quarter==4){
        ui->quarternum->setText("当前节数：第4节");
    }
    if(quarter>=5){
        ui->quarternum->setText("当前节数：决胜期");
    }
    ui->confirm_to_next_quarter->hide();
    ui->get1->hide();
    ui->get2->hide();
    ui->get3->hide();
    ui->foul->hide();
    ui->timeout->hide();
    ui->reset->hide();
    ui->smalltime_freeze->hide();
    ui->smalltime_continue->hide();
    ui->bigtime_continue->hide();
    ui->bigtime_freeze->hide();
    timer1.stop();
    time1.setHMS(0,0,0,0);
    ui->bigtime->setText("00.00");
    timer2.stop();
    time2.setHMS(0,0,0,0);
    ui->smalltime->setText("00.00");
    ui->begin->show();
    ui->team2_total->item(0,1)->setText(QString::number(team2.team_foul_cnt[min(quarter-1,3)]));
    ui->team1_total->item(0,1)->setText(QString::number(team1.team_foul_cnt[min(quarter-1,3)]));
}

void record::on_begin_clicked()
{
    ui->get1->show();
    ui->get2->show();
    ui->get3->show();
    ui->foul->show();
    ui->timeout->show();
    ui->reset->show();
    ui->begin->hide();
    timer1.start(30);
    timer2.start(30);
    ui->bigtime_freeze->show();
    ui->smalltime_freeze->show();
    ui->team1_total->item(0,2)->setText(QString::number(team1.get_available_timeout(current_time,quarter-1)));
    ui->team2_total->item(0,2)->setText(QString::number(team2.get_available_timeout(current_time,quarter-1)));
    ui->end_record->show();
}

void record::timeout1_slot()
{
    time1=time1.addMSecs(30);
    QString time=time1.toString("hh:mm:ss.zzz");
    ui->bigtime->setText(time.mid(3,-2));
}

void record::timeout2_slot()
{
    time2=time2.addMSecs(30);
    QString time=time2.toString("hh:mm:ss.zzz");
    ui->smalltime->setText(time.mid(6,-2));
}

void record::on_bigtime_freeze_clicked()
{
    timer1.stop();
    timer2.stop();
    ui->bigtime_continue->show();
    ui->smalltime_continue->hide();
    ui->bigtime_freeze->hide();
    ui->smalltime_freeze->hide();
}

void record::on_bigtime_continue_clicked()
{
    timer1.start(30);
    timer2.start(30);
    ui->bigtime_continue->hide();
    ui->bigtime_freeze->show();
    ui->smalltime_freeze->show();
}

void record::on_smalltime_freeze_clicked()
{
    timer2.stop();
    ui->smalltime_continue->show();
    ui->smalltime_freeze->hide();
}

void record::on_smalltime_continue_clicked()
{
    timer2.start(30);
    ui->smalltime_freeze->show();
    ui->smalltime_continue->hide();
}

void record::on_smalltime_reset_clicked()
{
    time2.setHMS(0,0,0,0);
    ui->smalltime->setText("00.00");
}

void record::on_bigtime_plus_clicked()
{
    time1=time1.addMSecs(300);
    QString time=time1.toString("hh:mm:ss.zzz");
    ui->bigtime->setText(time.mid(3,6));
}

void record::on_bigtime_subtract_clicked()
{
    time1=time1.addMSecs(-300);
    QString time=time1.toString("hh:mm:ss.zzz");
    ui->bigtime->setText(time.mid(3,6));
}

void record::on_smalltime_plus_clicked()
{
    time2=time2.addMSecs(300);
    QString time=time2.toString("hh:mm:ss.zzz");
    ui->smalltime->setText(time.mid(6,4));
}

void record::on_smalltime_subtract_clicked()
{
    time2=time2.addMSecs(-300);
    QString time=time2.toString("hh:mm:ss.zzz");
    ui->smalltime->setText(time.mid(6,4));
}

void record::on_end_record_clicked()
{
    ui->comfirm_end->show();
    ui->not_end->show();
}

void record::on_comfirm_end_clicked()
{
    save *sa = new save;
    sa->setGeometry(sa->geometry());
    sa->setWindowModality(Qt::ApplicationModal);
    connect(sa, SIGNAL(qsave(QString)), this, SLOT(saveevent(QString)));
    sa->show();
}

void record::on_not_end_clicked()
{
    ui->comfirm_end->hide();
    ui->not_end->hide();
}

void record::saveevent(QString str)
{
    string s=qstring_to_string0(str);
    ofstream fileout("Savedgames//"+s+".txt");
    game0.Print(fileout);
    team1.Print(fileout);
    team2.Print(fileout);
    fileout<<event_num<<endl;
    for(int i=0;i<event_num;i++){
        EVENT[i]->Print(fileout);
    }
    fileout.close();
    MainWindow *sm = new MainWindow;
    sm->setGeometry(sm->geometry());
    this->close();
    sm->show();
}
