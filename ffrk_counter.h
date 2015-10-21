#ifndef FFRK_COUNTER_H
#define FFRK_COUNTER_H

#include <QWidget>
#include <QObject>
#include <QEvent>
#include <QKeyEvent>

#include <iostream>

namespace Ui {
class ffrk_counter;
}

class ffrk_counter : public QWidget
{
    Q_OBJECT

public:
    explicit ffrk_counter(QWidget *parent = 0);
    ~ffrk_counter();

    bool eventFilter(QObject *o, QEvent *e) ;

private slots:
    void on_num_runs_1_textChanged(const QString &arg1);
    void on_count1_1_textChanged(const QString &arg1);
    void on_count2_1_textChanged(const QString &arg1);
    void on_count3_1_textChanged(const QString &arg1);

    void on_num_runs_2_textChanged(const QString &arg1);
    void on_count1_2_textChanged(const QString &arg1);
    void on_count2_2_textChanged(const QString &arg1);
    void on_count3_2_textChanged(const QString &arg1);

    void on_num_runs_3_textChanged(const QString &arg1);
    void on_count1_3_textChanged(const QString &arg1);
    void on_count2_3_textChanged(const QString &arg1);
    void on_count3_3_textChanged(const QString &arg1);


private:
    Ui::ffrk_counter *ui;

    void update_drop_rate(int section) ;
    void update_drop_rate(int section, int rarity) ;
};

#endif // FFRK_COUNTER_H
