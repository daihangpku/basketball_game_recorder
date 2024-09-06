#ifndef REPLAY_H
#define REPLAY_H

#include <QWidget>
#include<QTime>
#include<QTimer>
#include<header.hpp>
#include<QPainter>
#include<QPaintEvent>

namespace Ui {
class replay;
}

class replay : public QWidget
{
    Q_OBJECT

public:
    explicit replay(QWidget *parent = nullptr);
    ~replay();
    QTimer timer1;
    QTime time1;

private slots:
    void on_pushButton_clicked();

    void timeout1_slot();

    void generate_game_report(Game &game, Team &team1, Team &team2);

    void on_see_clicked();

    void on_out2_clicked();

    void on_all_show_clicked();

    void on_continue_2_clicked();

    void on_stop_clicked();

    void process_event(Team &team1, Team &team2, Event* event);

    void on_begin_clicked();

    void on_replayy_clicked();

    void paintEvent(QPaintEvent *);

private:
    Ui::replay *ui;
};

#endif // REPLAY_H
