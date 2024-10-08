#ifndef Header
#define Header
#include<iostream>
#include<cstring>
#include<vector>
#include<utility>
#include<fstream>
using namespace std;
//int mytime;

class Game{
    public:
    string game_name;
    string game_info;
    string team1;
    string team2;
    void Print(ofstream& fout) {
        fout << game_name << endl << game_info << endl;
        fout << team1<< endl << team2 << endl;
    }
    Game(string _name,string _team1,string _team2,string _info=""):game_name(_name),game_info(_info),team1(_team1),team2(_team2){}
};
class Score{
    public:
    int pts;
    int tm;
    Score(int _pts,int _time):pts(_pts),tm(_time){}
};
class Foul{
    public:
    int penalty;
    char type;
    int time;
    Foul(){}
    Foul(int _penalty,char _type,int _time):penalty(_penalty),type(_type),time(_time){}
};
class Player{
public:
    string name;//球员姓名
    string num;//球员号码
    //关于得分
    vector<Score> points[10];//个人得分记录0~3=1~4节 4=决胜期
    int sum_score_of_quarter[10];//单节得分
    int total_score;//总得分
    //关于个人犯规
    vector<Foul> foul[10];//个人犯规0~3=1~4节 4=决胜期
    int total_foul;//总犯规
    int special_foul;
    bool is_GD;
    Player(string _name,string _num):num(_num),name(_name){
        memset(sum_score_of_quarter,0,sizeof(sum_score_of_quarter));
        total_score=0;
        is_GD=false;
        total_foul=0;
        special_foul=0;
    }
    void Print(ofstream& fout) {
        fout << name << " " << num << endl;
    }
    void get_score(int _pts,int _time,int _num_of_quarter){//球员得分
        points[_num_of_quarter].push_back(Score(_pts,_time));
        sum_score_of_quarter[_num_of_quarter]+=_pts;
        total_score+=_pts;
        return;
    }
    void get_foul(int _penalty,char _type,int _time,int _num_of_quarter){//球员犯规
        foul[_num_of_quarter].push_back(Foul(_penalty,_type,_time));
        total_foul++;
        if(_type=='T'||_type=='U'){
            special_foul++;
        }
        else if(_type=='D'){
            special_foul+=2;
        }
        
        if(total_foul>=5||special_foul>=2){
            is_GD=true;//被罚下
        }
    }

    
};
class Headcoach{
    public:
    string name;
    vector<Foul> foul[10];//个人犯规0~3=1~4节 4=决胜期
    int total_foul;//总犯规
    int special_foul_B;
    int special_foul_C;
    bool is_GD;
    void get_foul(int _penalty,char _type,int _time,int _num_of_quarter){//教练犯规
        if(_type=='P'){
            //报错，教练不可能是P
        }
        foul[_num_of_quarter].push_back(Foul(_penalty,_type,_time));

        total_foul++;
        if(_type=='C'||_type=='U'){
            special_foul_C++;
        }
        else if(_type=='D'){
            special_foul_C+=2;
        }
        else if(_type=='B'){
            special_foul_B++;
        }
        if(special_foul_C>=2||special_foul_B+special_foul_C>=3){
            //！！！！！注意记得判断是否被罚出场
            is_GD=true;
        }
        
    }
    Headcoach(string _name):name(_name){
        total_foul=0;
        special_foul_B=0;
        special_foul_C=0;
        is_GD=false;
    }
    void Print(ofstream& fout) {
        fout << name << endl;
    }
};
class Team {
public:
	string name;
	bool is_first_team;                                                             //第一支队=1,第二支队=0
    int num_of_player;
	Player* players[12];															//第一个球员指针为player[0]
	short present_player[13] = {0};                                                 //初始化为0,1在场,0不在场,-1被罚下
	Headcoach* head_coach;
	int score_of_each_quarter[10];													//第一节得分为score_of_each_quarter[0]
	int team_foul_cnt[4];                                                          //第一节犯规数位team_faul_cnt[0]
    int total_team_score;
	void get_foul(Player* _player,int _penalty,char _type,int _time,int _num_of_quarter){
	    team_foul_cnt[min(_num_of_quarter,3)]++;
        if(team_foul_cnt[min(_num_of_quarter,3)]>=4){
            //
        }
	    _player->get_foul(_penalty,_type,_time,_num_of_quarter);
	    return;
    }
	void get_score(Player* get_score_player,int pts,int mytime,int num_of_quarter) {  //参数顺序仿照player，前置player指针
		get_score_player->get_score(pts, mytime, num_of_quarter);
		score_of_each_quarter[min(num_of_quarter,4)] += pts;                               //第一节对应的num_of_quarter=0
        total_team_score+=pts;
	}
	pair<int,int> first_half_timeout[2];//make_pair(second,num_of_quarter)
    int first_half_timeout_used;
	pair<int,int> second_half_timeout[3];
    int second_half_timeout_used;
    pair<int,int> ot_timeout[6];
    int ot_timeout_used[6];
    int get_available_timeout(int _time,int _num_of_quarter){
        if(_num_of_quarter<=1){
            return 2-first_half_timeout_used;
        }
        else if(_num_of_quarter==2||(_num_of_quarter==3&&_time<480)){
            return 3-second_half_timeout_used;
        }
        else if(_num_of_quarter==3){
            if(second_half_timeout_used==0){
                second_half_timeout_used++;
            }
            return 3-second_half_timeout_used;
        }
        else if(_num_of_quarter>=4){
            return 1-ot_timeout_used[_num_of_quarter-4];
        }
    }
	void get_timeout(int _time,int _num_of_quarter){
        if(_num_of_quarter<=1){
            if(first_half_timeout_used<2){
                first_half_timeout[first_half_timeout_used]=make_pair(_time,_num_of_quarter);
                first_half_timeout_used++;
            }
            else{
                //不能叫暂停了；
            }
        }
        else if(_num_of_quarter<=3){
            if(_num_of_quarter==3&&_time>=8*60&&second_half_timeout_used==0){
                second_half_timeout[second_half_timeout_used]=make_pair(-1,-1);
                second_half_timeout_used++;
            }
            if(second_half_timeout_used<3){
                second_half_timeout[second_half_timeout_used]=make_pair(_time,_num_of_quarter);
                second_half_timeout_used++;
            }
            else{
                //不能叫暂停了；
            }
        }
        else{
            if(ot_timeout_used[_num_of_quarter-4]==0){
                ot_timeout[_num_of_quarter-4]=make_pair(_time,_num_of_quarter);
                ot_timeout_used[_num_of_quarter-4]=1;
            }
        }
        
    }
	Team(){
        memset(score_of_each_quarter,0,sizeof(score_of_each_quarter));
        memset(team_foul_cnt,0,sizeof(team_foul_cnt));
		first_half_timeout_used = 0;
		second_half_timeout_used = 0;
        total_team_score=0;
        memset(ot_timeout_used,0,sizeof(ot_timeout_used));
    }
	Team(string _name, bool _is_first_team, Player** _players,int _player_number, Headcoach* _headcoach):num_of_player(_player_number),name(_name) {
		
		is_first_team = _is_first_team;
		for (int i = 0; i < _player_number; i++) 	players[i] = _players[i];
		head_coach = _headcoach;
		
        memset(score_of_each_quarter,0,sizeof(score_of_each_quarter));
        memset(team_foul_cnt,0,sizeof(team_foul_cnt));
		first_half_timeout_used = 0;
		second_half_timeout_used = 0;
        total_team_score=0;
        memset(ot_timeout_used,0,sizeof(ot_timeout_used));
	}
    void Print(ofstream& fout) {
        fout << name << " " << num_of_player << endl;
        for (int i = 0; i < num_of_player; i++) {
            players[i]->Print(fout);
        }
        head_coach->Print(fout);
    }
};



//事件类
class Event{
    public:
    string event_type;
    pair<int,int> event_time;//前time 后quarter
    Event(string _event_type,pair<int,int> _event_time){
        event_type=_event_type;
        event_time=_event_time;
    }
    virtual void Print(ofstream& fout)=0;
    
};
class Score_event:public Event{
    public:
    int players_team;
    int player_num_in_list;
    int pts;
    Score_event(string _event_type,pair<int,int> _event_time,int _players_team,int _player_num_in_list,int _pts):Event(_event_type,_event_time){
        player_num_in_list=_player_num_in_list;
        players_team=_players_team;
        pts=_pts;
    }
    void Print(ofstream& fout){
        fout<<event_type<<" "<<event_time.first<<" "<<event_time.second<<" ";
        fout<<players_team<<" "<<player_num_in_list<<" ";
        fout<<pts<<endl;
    }
};
class Foul_event:public Event{
    public:
    int players_team;
    int player_num_in_list;
    Foul foul;
    Foul_event(string _event_type,pair<int,int> _event_time,int _players_team,int _player_num_in_list,Foul _foul):Event(_event_type,_event_time){
        player_num_in_list=_player_num_in_list;
        players_team=_players_team;
        foul=_foul;
    }
    void Print(ofstream& fout){
        fout<<event_type<<" "<<event_time.first<<" "<<event_time.second<<" ";
        fout<<players_team<<" "<<player_num_in_list<<" ";
        fout<<foul.penalty<<" "<<foul.type<<" "<<foul.time<<endl;
    }
};
class Timeout_event:public Event{
    public:
    int team;
    Timeout_event(string _event_type,pair<int,int> _event_time,int _team):Event(_event_type,_event_time){
        team=_team;
    }
    void Print(ofstream& fout){
        fout<<event_type<<" "<<event_time.first<<" "<<event_time.second<<" ";
        fout<<team<<endl;
    }
};
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
#endif