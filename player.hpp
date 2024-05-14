#include<iostream>
#include<cstring>
#include<vector>
#include<utility>

using namespace std;
int mytime;
class Game{
    public:
    string game_name;
    string game_info;
    string team1;
    string team2;
    Game(string _name,string _team1,string _team2,string _info=""){
        game_name=_name;
        game_info=_info;
        team1=_team1;
        team2=_team2;
    }
};
class Score{
    public:
    int pts;
    int tm;
    Score(int _pts,int _time):pts(_pts),tm(_time){

    }
};
class Foul{
    public:
    int penalty;
    char type;
    Foul(int _penalty,char _type):penalty(_penalty),type(_type){

    }
};
class Player{

public:
    string name;//球员姓名
    string num;//球员号码
    //关于得分
    vector<Score> points[5];//个人得分记录0~3=1~4节 4=决胜期
    int sum_score_of_quarter[5];//单节得分
    int total_score;//总得分
    //关于个人犯规
    vector<Foul> foul[5];//个人犯规0~3=1~4节 4=决胜期
    int total_foul;//总犯规
    int special_foul;
    Player(string _name,string _num):num(_num),name(_name){
        memset(sum_score_of_quarter,0,sizeof(sum_score_of_quarter));
        total_score=0;

        total_foul=0;
        special_foul=0;
    }
    void get_score(int _pts,int _time,int _num_of_quarter){//球员得分
        points[_num_of_quarter-1].push_back(Score(_pts,_time));
        sum_score_of_quarter[_num_of_quarter-1]+=_pts;
        total_score+=_pts;
        return;
    }
    void get_foul(int _penalty,char _type,int _num_of_quarter){//球员犯规
        foul[_num_of_quarter-1].push_back(Foul(_penalty,_type));
        total_foul++;
        if(_type=='T'||_type=='U'){
            special_foul++;
        }
        else if(_type=='D'){
            special_foul+=2;
        }
        //！！！！！注意记得判断是否被罚出场
    }

    
};
class Headcoach{
    public:
    string name;
    vector<Foul> foul[5];//个人犯规0~3=1~4节 4=决胜期
    int total_foul;//总犯规
    int special_foul_B;
    int special_foul_C;
    void get_foul(int _penalty,char _type,int _num_of_quarter){//教练犯规
        if(_type=='P'){
            //报错，教练不可能是P
        }
        foul[_num_of_quarter-1].push_back(Foul(_penalty,_type));
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
        }
        
    }
    Headcoach(string _name):name(_name){
        total_foul=0;
        special_foul_B=0;
        special_foul_C=0;
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
	int score_of_each_quarter[5];													//第一节得分为score_of_each_quarter[0]
	int team_foul_cnt[5];                                                          //第一节犯规数位team_faul_cnt[0]
    int total_team_score;
	void get_foul(Player* _player,int _penalty,char _type,int _num_of_quarter);
	void get_score(Player* get_score_player,int pts,int mytime,int num_of_quarter) {  //参数顺序仿照player，前置player指针
		get_score_player->get_score(pts, mytime, num_of_quarter);
		score_of_each_quarter[num_of_quarter-1] += pts;                               //第一节对应的num_of_quarter=0
        total_team_score+=pts;
	}
	pair<int,int> first_half_timeout[2];//make_pair(num_of_quarter,minute)
    int first_half_timeout_used;
	pair<int,int> second_half_timeout[3];
    int second_half_timeout_used;
	//int total_score();
	Team(){}
	Team(string _name, bool _is_first_team, Player** _players,int _player_number, Headcoach* _headcoach):num_of_player(_player_number),name(_name) {
		
		is_first_team = _is_first_team;
		for (int i = 0; i < _player_number; i++) {
			players[i] = _players[i];
		}
		head_coach = _headcoach;
		for (int i = 0; i < 5; i++) {
			score_of_each_quarter[i] = 0;
			team_foul_cnt[i] = 0;
		}
		first_half_timeout_used = 0;
		second_half_timeout_used = 0;
        total_team_score=0;
	}
};

/*int Team::total_score() {
	int total = 0;
	for (int i = 0; i < 5; ++i) {
		total += score_of_each_quarter[i];
	}
	return total;
}*/
void Team::get_foul(Player* _player, int _penalty,char _type,int _num_of_quarter) {
	team_foul_cnt[_num_of_quarter-1]++;
    if(team_foul_cnt[_num_of_quarter-1]>=4){
        //
    }
	_player->get_foul(_penalty,_type,_num_of_quarter);
	return;
}
