#ifndef FFRK_COUNTER_H
#define FFRK_COUNTER_H

#include <QWidget>
#include <QObject>
#include <QEvent>
#include <QKeyEvent>
#include <QSettings>
#include <QFile>
#include <QStringList>
#include <QMessageBox>
#include <QTextStream>

#include <iostream>

namespace Ui {
class ffrk_counter;
}

class ffrk_counter : public QWidget
{
    Q_OBJECT

public:

    typedef enum {
        NAME  = 0,
        RUNS  = 1,
        COUNT = 2,
        INFO  = 3
    } column_type ;

    explicit ffrk_counter(QWidget *parent = 0);
    ~ffrk_counter();

    void closeEvent(QCloseEvent *e) ;
    bool eventFilter(QObject *o, QEvent *e) ;

private slots:

    void on_drop_table_cellChanged(int row, int column);

    void on_add_row_button_clicked();

    void on_remove_row_button_clicked();

private:
    Ui::ffrk_counter *ui;

    QString _data_file ;
    void load_data() ;
    void save_data() ;

    QSettings _settings ;
    void restore_settings() ;
    void save_settings() ;

    bool _initialized ;
    void update_information(int row) ;
    int add_row() ;
};

#endif // FFRK_COUNTER_H
