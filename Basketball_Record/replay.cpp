#include "replay.h"
#include "ui_replay.h"
#include "mainwindow.h"
#include "header.hpp"
#include<iostream>
#include<QTime>
#include<QTimer>
#include<QPainter>
#include<QPaintEvent>
#include<io.h>

int num_events;
int now_report_event=0;
string filename="";
vector<Event*> events;
Team teamx,teamy;

QString string_to_qstring2(const string& str)
{
    return QString(QString::fromLocal8Bit(str));
}

string qstring_to_string2(const QString& qstr)
{
    QByteArray localBytes = qstr.toLocal8Bit();
    return localBytes.data();
}

Game input_game(ifstream& fin) {
    string game_name,game_info,team1,team2;
    fin>>game_name>>game_info;
    fin>>team1>>team2;
    Game tmp(game_name,team1,team2,game_info);
    return tmp;
}

Team input_team(ifstream& fin,bool is_first_team){
    string name;
    int num_of_player;
    fin>>name>>num_of_player;
    Player* players[12];
    for(int i=0;i<num_of_player;i++){
        string pname,num;
        fin>>pname>>num;
        players[i]=new Player(pname,num);
    }
    string hname;
    fin>>hname;
    Headcoach* headcoach=new Headcoach(hname);
    Team t(name,is_first_team,players,num_of_player,headcoach);
    return t;
}

Event *input_event(ifstream& fin){
    string event_type;
    int event_time1,event_time2;
    fin>>event_type;
    fin>>event_time1>>event_time2;
    if(event_type=="score"){
        int players_team;
        int player_num_in_list;
        int pts;
        fin>>players_team>>player_num_in_list>>pts;
        return new Score_event(event_type,make_pair(event_time1,event_time2),players_team,player_num_in_list,pts);
    }
    else if(event_type=="foul"){
        int players_team;
        int player_num_in_list;
        Foul foul;
        fin>>players_team>>player_num_in_list;
        fin>>foul.penalty>>foul.type>>foul.time;
        return new Foul_event(event_type,make_pair(event_time1,event_time2),players_team,player_num_in_list,foul);
    }
    else if(event_type=="timeout"){
        int team;
        fin>>team;
        return new Timeout_event(event_type,make_pair(event_time1,event_time2),team);
    }
}

void getFiles(string path, vector<string>& files)
{
    intptr_t hFile = 0;
    struct _finddata_t fileinfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
    {
        do
        {
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
            }
            else
            {
                files.push_back(p.assign(path).append("\\").append(fileinfo.name));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}

replay::replay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::replay)
{
    ui->setupUi(this);
    this->move(150,80);
    setWindowTitle("篮球记录系统");
    ui->widget->hide();
    connect(&timer1,SIGNAL(timeout()),this,SLOT(timeout1_slot()));
    time1.setHMS(0,0,0,0);
    string filePath = "Savedgames";
    vector<string> files;
    getFiles(filePath, files);
    int size = files.size();
    for (int i = 0; i < size; i++)
    {
        ui->choose->addItem(string_to_qstring2(files[i].substr(11,files[i].length()-15)));
    }
}

replay::~replay()
{
    delete ui;
}

void replay::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(this->rect(),QPixmap("://pictures/3NeALzbQnx_small.jpg"));
}

void replay::timeout1_slot()
{
    if(now_report_event<num_events){
        QString event_info;
        if (dynamic_cast<Score_event*>(events[now_report_event])) {
            Score_event* se = static_cast<Score_event*>(events[now_report_event]);
            Team& team=se->players_team==1?teamx:teamy;
            event_info = QString::number(se->event_time.second) + "节" + QString::number(se->event_time.first/60) + "分"+QString::number(se->event_time.first%60)+
                         "秒 "+string_to_qstring2(team.name) + string_to_qstring2(team.players[se->player_num_in_list]->num)+"号" +string_to_qstring2(team.players[se->player_num_in_list]->name)
                          + "得" + QString::number(se->pts)+"分";
        } else if (dynamic_cast<Foul_event*>(events[now_report_event])) {
            Foul_event* fe = static_cast<Foul_event*>(events[now_report_event]);
            Team& team=fe->players_team==1?teamx:teamy;
            QString s;
            if(fe->foul.type=='P'){
                s="普通犯规";
            }
            else if(fe->foul.type=='U'){
                s="违体犯规";
            }
            else if(fe->foul.type=='D'){
                s="取消比赛资格的犯规";
            }
            else{
                s="技术犯规";
            }
            if(fe->player_num_in_list!=-1){
                event_info = QString::number(fe->event_time.second) + "节" + QString::number(fe->event_time.first/60) + "分"+QString::number(fe->event_time.first%60)+
                             "秒 "+string_to_qstring2(team.name) + string_to_qstring2(team.players[fe->player_num_in_list]->num)+"号" +string_to_qstring2(team.players[fe->player_num_in_list]->name)
                             +s +"  对手"+QString::number(fe->foul.penalty)+"罚";
            }
            else{
                event_info = QString::number(fe->event_time.second) + "节" + QString::number(fe->event_time.first/60) + "分"+QString::number(fe->event_time.first%60)+
                             "秒 "+string_to_qstring2(team.name) + "教练" +string_to_qstring2(team.head_coach->name)
                             +s +"  对手"+QString::number(fe->foul.penalty)+"罚";
            }
        } else if (dynamic_cast<Timeout_event*>(events[now_report_event])) {
            Timeout_event* te = static_cast<Timeout_event*>(events[now_report_event]);
            Team& team=te->team==1?teamx:teamy;
            event_info = QString::number(te->event_time.second) + "节" + QString::number(te->event_time.first/60) + "分"+QString::number(te->event_time.first%60)+
                         "秒 "+string_to_qstring2(team.name)+"请求暂停";
        }
        ui->screen->append(event_info+"\n");
        now_report_event++;
    }
    else{
        timer1.stop();
        ui->stop->hide();
        ui->continue_2->hide();
        ui->all_show->hide();
    }
}

void replay::on_pushButton_clicked()
{
    MainWindow *me = new MainWindow;
    me->setGeometry(me->geometry());
    me->show();
    this->close();
}

void replay::generate_game_report(Game &game, Team &team1, Team &team2) {
    ui->screen->append("比赛名称："+string_to_qstring2(game.game_name)+"\n");
    int cutplace=0;
    for(;game.game_info[cutplace]!='%';cutplace++){}
    if(cutplace!=0) ui->screen->append("比赛时间："+string_to_qstring2(game.game_info.substr(0,cutplace))+"\n");
    if(game.game_info.length()>cutplace+1) ui->screen->append("比赛地点："+string_to_qstring2(game.game_info.substr(cutplace+1,game.game_info.length()-cutplace-1))+"\n");
    ui->screen->append("队伍："+string_to_qstring2(game.team1+" vs "+game.team2)+"\n");

    // Print team details
    ui->screen->append("队伍 1："+string_to_qstring2(team1.name)+"\n");
    for (int i = 0; i < team1.num_of_player; ++i) {
        ui->screen->append("队员："+string_to_qstring2(team1.players[i]->name)+"（号码："+string_to_qstring2(team1.players[i]->num)+"）"+"\n");
        Player* player = team1.players[i];
        int three_pointers =0;
        for(int i=0;i<10;i++){
            for(int j=0;j<player->points[i].size();j++){
                if(player->points[i][j].pts==3){
                    three_pointers++;
                }
            }
        }
        ui->screen->append("总得分数："+QString::number(team1.players[i]->total_score)+"，总犯规数："+QString::number(team1.players[i]->total_foul)+"，三分数：" +QString::number(three_pointers)+"\n");
    }
    ui->screen->append("教练："+string_to_qstring2(team1.head_coach->name)+"\n");
    ui->screen->append("队伍总得分："+QString::number(team1.total_team_score)+"\n");

    ui->screen->append("队伍 2："+string_to_qstring2(team2.name)+"\n");
    for (int i = 0; i < team2.num_of_player; ++i) {
        ui->screen->append("队员："+string_to_qstring2(team2.players[i]->name)+"（号码："+string_to_qstring2(team2.players[i]->num)+"）"+"\n");
        Player* player = team2.players[i];
        int three_pointers =0;
        for(int i=0;i<10;i++){
            for(int j=0;j<player->points[i].size();j++){
                if(player->points[i][j].pts==3){
                    three_pointers++;
                }
            }
        }
        ui->screen->append("总得分数："+QString::number(team2.players[i]->total_score)+"，总犯规数："+QString::number(team2.players[i]->total_foul)+"，三分数：" +QString::number(three_pointers)+"\n");
    }
    ui->screen->append("教练："+string_to_qstring2(team2.head_coach->name)+"\n");
    ui->screen->append("队伍总得分："+QString::number(team2.total_team_score)+"\n");
    //ui->screen->append(QString::number(num_events));
}

void replay::process_event(Team &team1, Team &team2, Event* event) {
    if (Score_event* score_event = dynamic_cast<Score_event*>(event)) {
        // 处理得分事件
        Team &team = (score_event->players_team == 1) ? team1 : team2;
        team.get_score(team.players[score_event->player_num_in_list], score_event->pts, score_event->event_time.first, score_event->event_time.second);
    } else if (Foul_event* foul_event = dynamic_cast<Foul_event*>(event)) {
        // 处理犯规事件
        Team &team = (foul_event->players_team == 1) ? team1 : team2;
        if(foul_event->player_num_in_list!=-1)
            team.get_foul(team.players[foul_event->player_num_in_list], foul_event->foul.penalty, foul_event->foul.type, foul_event->foul.time, foul_event->event_time.second);
        else{
            team.head_coach->get_foul(foul_event->foul.penalty, foul_event->foul.type, foul_event->foul.time, foul_event->event_time.second);
        }
    } else if (Timeout_event* timeout_event = dynamic_cast<Timeout_event*>(event)) {
        // 处理暂停事件
        Team &team = (timeout_event->team == 1) ? team1 : team2;
        team.get_timeout(timeout_event->event_time.first, timeout_event->event_time.second);
    }
}

void replay::on_see_clicked()
{
    QListWidgetItem *selectedone=ui->choose->currentItem();
    if(selectedone){
        filename=qstring_to_string2(selectedone->text());
    }
    if(filename!=""){
        ui->widget->show();
        ui->widget_2->hide();
        ui->continue_2->hide();
        ui->all_show->hide();
        ui->begin->hide();
        ui->stop->hide();
        ifstream fin("Savedgames//"+filename+".txt");
        Game game = input_game(fin);
        teamx = Team(input_team(fin,true));
        teamy = Team(input_team(fin,false));
        fin >> num_events;
        for (int i = 0; i < num_events; ++i) {
            events.push_back(input_event(fin));
        }
        for (int i=0;i<num_events;i++) {
            process_event(teamx, teamy, events[i]);
        }
        generate_game_report(game, teamx, teamy);
    }
}

void replay::on_all_show_clicked()
{
    for(;now_report_event<num_events;now_report_event++){
        QString event_info;
        if (dynamic_cast<Score_event*>(events[now_report_event])) {
            Score_event* se = static_cast<Score_event*>(events[now_report_event]);
            Team& team=se->players_team==1?teamx:teamy;
            event_info = QString::number(se->event_time.second) + "节" + QString::number(se->event_time.first/60) + "分"+QString::number(se->event_time.first%60)+
                         "秒 "+string_to_qstring2(team.name) + string_to_qstring2(team.players[se->player_num_in_list]->num)+"号" +string_to_qstring2(team.players[se->player_num_in_list]->name)
                          + "得" + QString::number(se->pts)+"分";
        } else if (dynamic_cast<Foul_event*>(events[now_report_event])) {
            Foul_event* fe = static_cast<Foul_event*>(events[now_report_event]);
            Team& team=fe->players_team==1?teamx:teamy;
            QString s;
            if(fe->foul.type=='P'){
                s="普通犯规";
            }
            else if(fe->foul.type=='U'){
                s="违体犯规";
            }
            else if(fe->foul.type=='D'){
                s="取消比赛资格的犯规";
            }
            else{
                s="技术犯规";
            }
            if(fe->player_num_in_list!=-1){
                event_info = QString::number(fe->event_time.second) + "节" + QString::number(fe->event_time.first/60) + "分"+QString::number(fe->event_time.first%60)+
                             "秒 "+string_to_qstring2(team.name) + string_to_qstring2(team.players[fe->player_num_in_list]->num)+"号" +string_to_qstring2(team.players[fe->player_num_in_list]->name)
                             +s +"  对手"+QString::number(fe->foul.penalty)+"罚";
            }
            else{
                event_info = QString::number(fe->event_time.second) + "节" + QString::number(fe->event_time.first/60) + "分"+QString::number(fe->event_time.first%60)+
                             "秒 "+string_to_qstring2(team.name) + "教练" +string_to_qstring2(team.head_coach->name)
                             +s +"  对手"+QString::number(fe->foul.penalty)+"罚";
            }
        } else if (dynamic_cast<Timeout_event*>(events[now_report_event])) {
            Timeout_event* te = static_cast<Timeout_event*>(events[now_report_event]);
            Team& team=te->team==1?teamx:teamy;
            event_info = QString::number(te->event_time.second) + "节" + QString::number(te->event_time.first/60) + "分"+QString::number(te->event_time.first%60)+
                         "秒 "+string_to_qstring2(team.name)+"请求暂停";
        }
        ui->screen->append(event_info+"\n");
    }
    timer1.stop();
    ui->stop->hide();
    ui->continue_2->hide();
    ui->all_show->hide();
}

void replay::on_continue_2_clicked()
{
    ui->continue_2->hide();
    ui->stop->show();
    timer1.start(300);
}

void replay::on_stop_clicked()
{
    ui->continue_2->show();
    ui->stop->hide();
    timer1.stop();
}

void replay::on_begin_clicked()
{
    timer1.start(300);
    ui->all_show->show();
    ui->stop->show();
    ui->begin->hide();
}

void replay::on_replayy_clicked()
{
    ui->begin->show();
    ui->out2->hide();
    ui->replayy->hide();
    ui->screen->setText("");
}

void replay::on_out2_clicked()
{
    QString str=ui->screen->toPlainText();
    ofstream fout("Savedreports//"+filename+".txt");
    fout<<qstring_to_string2(str);
    fout.close();
}

