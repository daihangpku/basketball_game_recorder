#ifndef HELP_H
#define HELP_H

#include <QWidget>
#include<QPainter>
#include<QPaintEvent>

namespace Ui {
class help;
}

class help : public QWidget
{
    Q_OBJECT

public:
    explicit help(QWidget *parent = nullptr);
    ~help();

private slots:
    void on_pushButton_clicked();

    void paintEvent(QPaintEvent *);

private:
    Ui::help *ui;
};

#endif // HELP_H
