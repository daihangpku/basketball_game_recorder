#ifndef RECORD_H
#define RECORD_H

#include <QWidget>
#include<QDialog>
#include<QTimer>
#include<QTime>
#include"header.hpp"
#include<QPainter>
#include<QPaintEvent>

namespace Ui {
class record;
}

class record : public QWidget
{
    Q_OBJECT

public:
    explicit record(QWidget *parent = nullptr);
    ~record();
    QTimer timer1,timer2;
    QTime time1,time2;

private slots:
    void receivedata(Team a,Team b,Game c);

    void timeout1_slot();

    void timeout2_slot();

    void on_get1_clicked();

    void on_get2_clicked();

    void on_get3_clicked();

    void on_foul_clicked();

    void on_timeout_clicked();

    void on_reset_clicked();

    void on_team1_member1_clicked();

    void on_team1_member2_clicked();

    void on_team1_member3_clicked();

    void on_team1_member4_clicked();

    void on_team1_member5_clicked();

    void on_team1_member6_clicked();

    void on_team1_member7_clicked();

    void on_team1_member8_clicked();

    void on_team1_member9_clicked();

    void on_team1_member10_clicked();

    void on_team1_member11_clicked();

    void on_team1_member12_clicked();

    void on_team2_member1_clicked();

    void on_team2_member2_clicked();

    void on_team2_member3_clicked();

    void on_team2_member4_clicked();

    void on_team2_member5_clicked();

    void on_team2_member6_clicked();

    void on_team2_member7_clicked();

    void on_team2_member8_clicked();

    void on_team2_member9_clicked();

    void on_team2_member10_clicked();

    void on_team2_member11_clicked();

    void on_team2_member12_clicked();

    void on_timeout_team1_clicked();

    void on_timeout_team2_clicked();

    void on_next_quarter_clicked();

    void on_foul_player_clicked();

    void on_foul_coach_clicked();

    void on_player_P_clicked();

    void on_player_T_clicked();

    void on_player_U_clicked();

    void on_D_clicked();

    void on_coach_B_clicked();

    void on_coach_C_clicked();

    void on_foul_0_clicked();

    void on_foul_1_clicked();

    void on_foul_2_clicked();

    void on_foul_3_clicked();

    void on_will_next_quarter_clicked();

    void on_not_next_quarter_clicked();

    void on_team1_coach_clicked();

    void on_team2_coach_clicked();

    void on_begin_clicked();

    void on_bigtime_freeze_clicked();

    void on_bigtime_continue_clicked();

    void on_smalltime_freeze_clicked();

    void on_smalltime_continue_clicked();

    void on_bigtime_plus_clicked();

    void on_bigtime_subtract_clicked();

    void on_smalltime_plus_clicked();

    void on_smalltime_subtract_clicked();

    void on_smalltime_reset_clicked();

    void on_end_record_clicked();

    void on_comfirm_end_clicked();

    void on_not_end_clicked();

    void saveevent(QString str);

    void paintEvent(QPaintEvent *);

private:
    Ui::record *ui;
};

#endif // RECORD_H
