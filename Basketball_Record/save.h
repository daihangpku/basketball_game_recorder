#ifndef SAVE_H
#define SAVE_H

#include <QWidget>

namespace Ui {
class save;
}

class save : public QWidget
{
    Q_OBJECT

public:
    explicit save(QWidget *parent = nullptr);
    ~save();

private slots:
    void on_pushButton_clicked();

signals:
    void qsave(QString str);

private:
    Ui::save *ui;
};

#endif // SAVE_H
