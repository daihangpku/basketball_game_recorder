#include "help.h"
#include "ui_help.h"
#include "mainwindow.h"
#include<QPaintEvent>
#include<QPainter>

help::help(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::help)
{
    ui->setupUi(this);
    this->move(150,80);
    setWindowTitle("帮助");
}

help::~help()
{
    delete ui;
}

void help::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(this->rect(),QPixmap("://pictures/3NeALzbQnx_small.jpg"));
}

void help::on_pushButton_clicked()
{
    MainWindow *me = new MainWindow;
    me->setGeometry(me->geometry());
    me->show();
    this->close();
}

