#include<iostream>
using namespace std;
int mytime;
class Player {
public:
	string name;
	void get_score(int pts, int time, int num_of_quarter) {}
	void faul(int a, char b, int c) {};
};

class Headcoach;
class Team {
public:
	string name;
	bool is_first_team;                                                             //��һ֧��=1,�ڶ�֧��=0
	Player* players[12];															//��һ����Աָ��Ϊplayer[0]
	short present_player[13] = {0};                                                 //��ʼ��Ϊ0,1�ڳ�,0���ڳ�,-1������
	Headcoach* head_coach;
	int score_of_each_quarter[5];													//��һ�ڵ÷�Ϊscore_of_each_quarter[0]
	int team_faul_time[5];                                                          //��һ�ڷ�����λteam_faul_time[0]
	void faul(Player* _player, int a, char b, int c);
	void get_score(Player* get_score_player,int pts,int mytime,int num_of_quarter) {  //����˳�����player��ǰ��playerָ��
		get_score_player->get_score(pts, mytime, num_of_quarter);
		score_of_each_quarter[num_of_quarter] += pts;                               //��һ�ڶ�Ӧ��num_of_quarter=0
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
void Team::faul(Player* _player, int a, char b, int c) {
	team_faul_time[c]++;
	_player->faul(a, b, c);
	return;
}

int main(){}
