#include "save.h"
#include "ui_save.h"

save::save(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::save)
{
    ui->setupUi(this);
    setWindowTitle("");
    this->move(500,240);
}

save::~save()
{
    delete ui;
}

void save::on_pushButton_clicked()
{
    emit qsave(ui->lineEdit->text());
    this->close();
}
