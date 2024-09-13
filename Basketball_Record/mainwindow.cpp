#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "record.h"
#include "replay.h"
#include "help.h"
#include<iostream>
#include<QApplication>
#include<QPainter>
#include<QPaintEvent>
#include<direct.h>
using namespace std;
int x=1;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ui->pushButton->setStyleSheet("QPushButton{font-size:32px;}");
    //ui->pushButton_2->setStyleSheet("QPushButton{font-size:32px;}");
    ui->setupUi(this);
    this->move(500,240);
    string patha="Savedgames",pathb="Savedreports";
    mkdir(patha.c_str());
    mkdir(pathb.c_str());
    setWindowTitle("篮球记录系统");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(this->rect(),QPixmap("://pictures/OIP-C.jpg"));
}

void MainWindow::on_pushButton_clicked()
{
    record *my = new record;
    my->setGeometry(my->geometry());
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    replay *my = new replay;
    my->setGeometry(my->geometry());
    my->show();
    this->close();
}

void MainWindow::on_pushButton_3_clicked()
{
    help *my = new help;
    my->setGeometry(my->geometry());
    my->show();
    this->close();
}

