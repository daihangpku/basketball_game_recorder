#ifndef RECORD_MODE_H
#define RECORD_MODE_H

#include <QWidget>
#include"header.hpp"
#include<QPainter>
#include<QPaintEvent>

namespace Ui {
class record_mode;
}

class record_mode : public QWidget
{
    Q_OBJECT

public:
    explicit record_mode(QWidget *parent = nullptr);
    ~record_mode();

private slots:
    void on_backbutton_clicked();

    void on_go_to_members_clicked();

    void on_go_to_teams_clicked();

    void on_back_to_event_clicked();

    void on_back_to_teams_clicked();

    void on_go_to_record_clicked();

    void paintEvent(QPaintEvent *);

signals:
    void sentdata(Team a,Team b,Game c);

private:
    Ui::record_mode *ui;
};

#endif // RECORD_MODE_H
