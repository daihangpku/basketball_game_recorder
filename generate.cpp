#include "header.hpp"

void generate_game_report(ofstream& fout,Game &game, Team &team1, Team &team2, vector<Event*> &events) {
    fout << "Game Report: " << game.game_name << endl;
    fout << game.game_info << endl;
    fout << "Teams: " << game.team1 << " vs " << game.team2 << endl;

    // Print team details
    fout << "Team 1: " << team1.name << endl;
    for (int i = 0; i < team1.num_of_player; ++i) {
        fout << "Player: " << team1.players[i]->name << " (Number: " << team1.players[i]->num << ")" << endl;
        fout << "Total Score: " << team1.players[i]->total_score << ", Total Fouls: " << team1.players[i]->total_foul << endl;
    }
    fout << "Head Coach: " << team1.head_coach->name << endl;
    fout << "Total Team Score: " << team1.total_team_score << endl;

    fout << "Team 2: " << team2.name << endl;
    for (int i = 0; i < team2.num_of_player; ++i) {
        fout << "Player: " << team2.players[i]->name << " (Number: " << team2.players[i]->num << ")" << endl;
        fout << "Total Score: " << team2.players[i]->total_score << ", Total Fouls: " << team2.players[i]->total_foul << endl;
    }
    fout << "Head Coach: " << team2.head_coach->name << endl;
    fout << "Total Team Score: " << team2.total_team_score << endl;

    // Print events
    fout << "Events: " << endl;
    for (Event* event : events) {
        event->Print(fout);
    }
}


void process_event(Team &team1, Team &team2, Event* event) {
    if (Score_event* score_event = dynamic_cast<Score_event*>(event)) {
        // 处理得分事件
        Team &team = (score_event->players_team == 1) ? team1 : team2;
        team.get_score(team.players[score_event->player_num_in_list], score_event->pts, score_event->event_time.first, score_event->event_time.second);
    } else if (Foul_event* foul_event = dynamic_cast<Foul_event*>(event)) {
        // 处理犯规事件
        Team &team = (foul_event->players_team == 1) ? team1 : team2;
        team.get_foul(team.players[foul_event->player_num_in_list], foul_event->foul.penalty, foul_event->foul.type, foul_event->foul.time, foul_event->event_time.second);
    } else if (Timeout_event* timeout_event = dynamic_cast<Timeout_event*>(event)) {
        // 处理暂停事件
        Team &team = (timeout_event->team == 1) ? team1 : team2;
        team.get_timeout(timeout_event->event_time.first, timeout_event->event_time.second);
    }
}
int main() {
    ifstream fin("input.txt"); // 打开输入文件
    if (!fin) {
        cerr << "Error opening input file" << endl;
        return 1;
    }
    ofstream fout("output.txt"); // 打开输出文件
    if (!fout) {
        cerr << "Error opening output file" << endl;
        return 1;
    }

    // Input game information
    Game game = input_game(fin);

    // Input team information
    Team team1 = input_team(fin,true);
    Team team2 = input_team(fin,false);

    // Input events
    vector<Event*> events;
    int num_events;
    cin >> num_events;
    for (int i = 0; i < num_events; ++i) {
        events.push_back(input_event(fin));
    }
    for (Event* event : events) {
        process_event(team1, team2, event);
    }
    // Generate the game report
    generate_game_report(fout,game, team1, team2, events);

    // Clean up dynamically allocated memory
    for (Event* event : events) {
        delete event;
    }
    return 0;
}
