#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
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

    //~player(){}
};



