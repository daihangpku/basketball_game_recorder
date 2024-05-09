#include<iostream>
using namespace std;
int mytime;
class Player {
public:
	string name;
	void get_score(int pts, int time, int num_of_quarter) {}
	void get_foul(int a, char b, int c) {};
};

class Headcoach;
class Team {
public:
	string name;
	bool is_first_team;                                                             //第一支队=1,第二支队=0
	Player* players[12];															//第一个球员指针为player[0]
	short present_player[13] = {0};                                                 //初始化为0,1在场,0不在场,-1被罚下
	Headcoach* head_coach;
	int score_of_each_quarter[5];													//第一节得分为score_of_each_quarter[0]
	int team_faul_time[5];                                                          //第一节犯规数位team_faul_time[0]
	void get_foul(Player* _player, int a, char b, int c);
	void get_score(Player* get_score_player,int pts,int mytime,int num_of_quarter) {  //参数顺序仿照player，前置player指针
		get_score_player->get_score(pts, mytime, num_of_quarter);
		score_of_each_quarter[num_of_quarter] += pts;                               //第一节对应的num_of_quarter=0
	}
	int first_half_timeout;
	int second_half_timeout;
	int total_score();
	Team(){}
	Team(string _name, bool _is_first_team, Player** _players,int _player_number, Headcoach* _headcoach) {
		name = _name;
		is_first_team = _is_first_team;
		for (int i = 0; i < _player_number; i++) {
			players[i] = _players[i];
		}
		head_coach = _headcoach;
		for (int i = 0; i < 5; i++) {
			score_of_each_quarter[i] = 0;
			team_faul_time[i] = 0;
		}
		first_half_timeout = 2;
		second_half_timeout = 3;
	}
};

int Team::total_score() {
	int total = 0;
	for (int i = 0; i < 5; ++i) {
		total += score_of_each_quarter[i];
	}
	return total;
}
void Team::get_foul(Player* _player, int a, char b, int c) {
	team_faul_time[c]++;
	_player->get_foul(a, b, c);
	return;
}

int main(){}
