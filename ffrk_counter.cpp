#include "ffrk_counter.h"
#include "ui_ffrk_counter.h"

/**
 * Constructor
 */
ffrk_counter::ffrk_counter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ffrk_counter),
    _data_file("ffrk_counter_data"),
    _settings("Tibonium Inc.", "FFRK Counter"),
    _initialized(false)
{
    ui->setupUi(this);
    ui->drop_table->installEventFilter(this) ;
    restore_settings() ;
    load_data() ;
    _initialized = true ;
    int size( ui->drop_table->rowCount() ) ;
    for(int i=0; i<size; ++i) {
        update_information( i ) ;
    }
    ui->drop_table->resizeColumnsToContents() ;
}

/**
 * Destructor
 */
ffrk_counter::~ffrk_counter()
{
    delete ui;
}

/**
 * Saves data and window settings upon closing
 */
void ffrk_counter::closeEvent(QCloseEvent *e)
{
    save_data() ;
    save_settings() ;
    e->accept() ;
}

/**
 * Saves current data
 */
void ffrk_counter::save_data()
{
    QFile data_out(_data_file) ;
    data_out.open(QFile::WriteOnly) ;
    if( data_out.exists() ) {
        QTableWidget *table = ui->drop_table ;
        int size( table->rowCount() ) ;
        QTextStream output( &data_out ) ;
        for(int i=0; i<size; ++i) {
            output << table->item(i, NAME)->text() << ","
                   << table->item(i, RUNS)->text() << ","
                   << table->item(i, COUNT)->text() ;
            if( i < size-1 ) {
                output << "\n" ;
            }
        }
    } else {
        QMessageBox msg ;
        msg.setWindowTitle("Error saving data") ;
        msg.setText( data_out.errorString() ) ;
        msg.exec() ;
    }
    data_out.close() ;
}

/**
 * Loads existing data, if present
 */
void ffrk_counter::load_data()
{
    QFile data_in(_data_file) ;
    data_in.open(QFile::ReadOnly) ;
    if( data_in.exists() ) {
        QTableWidget *table = ui->drop_table ;
        QTextStream input( &data_in ) ;
        while( !input.atEnd() ) {
            QString line = input.readLine() ;
            QStringList data = line.split(",") ;
            int row = add_row() ;
            table->item(row, NAME)->setText( data[0] ) ;
            table->item(row, RUNS)->setText( data[1] ) ;
            table->item(row, COUNT)->setText( data[2] ) ;
        }
    } else {
        /** Quitely fail, its ok if it doesn't exist */
    }
    data_in.close() ;
}

/**
 * Restores window settings
 */
void ffrk_counter::restore_settings()
{
    if( _settings.contains("position") )
        move( _settings.value("position").toPoint() ) ;
    if( _settings.contains("size") )
        resize( _settings.value("size").toSize() ) ;
}

/**
 * Saves window settings
 */
void ffrk_counter::save_settings()
{
    _settings.setValue("position", pos()) ;
    _settings.setValue("size", size()) ;
}

/**
 * Keyboard shortcuts for incrementing
 */
bool ffrk_counter::eventFilter(QObject *o, QEvent *e)
{
    if( e->type() == QEvent::KeyPress ) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(e) ;
        QKeySequence keySeq( keyEvent->key() | keyEvent->modifiers() ) ;
        if( keySeq.matches( QKeySequence(Qt::CTRL + Qt::Key_Up) ) ) {
            int value = 0 ;
            int size( ui->drop_table->rowCount() ) ;
            for(int i=0; i<size; ++i) {
                value = ui->drop_table->item(i, RUNS)->text().toInt() ;
                value++ ;
                ui->drop_table->item(i, RUNS)->setText( QString::number(value) ) ;
            }
            return true ;
        } else
        if( keySeq.matches( QKeySequence(Qt::CTRL + Qt::Key_Down) ) ) {
            int value = 0 ;
            int size( ui->drop_table->rowCount() ) ;
            for(int i=0; i<size; ++i) {
                value = ui->drop_table->item(i, RUNS)->text().toInt() ;
                value-- ;
                if( 0 < value )
                    ui->drop_table->item(i, RUNS)->setText( QString::number(value) ) ;
                else
                    ui->drop_table->item(i, RUNS)->setText( QString::number(0) ) ;
            }
            return true ;
        }
    }
    if( e->type() == QEvent::KeyPress ) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(e) ;
        int column = ui->drop_table->currentColumn() ;
        if( column == RUNS || column == COUNT ) {
            if( keyEvent->key() == Qt::Key_Plus ) {
                int row = ui->drop_table->currentRow() ;
                int value = ui->drop_table->item(row, column)->text().toInt() ; ;
                value++ ;
                ui->drop_table->item(row, column)->setText( QString::number(value) ) ;
                return true ;
            } else
            if( keyEvent->key() == Qt::Key_Minus ) {
                int row = ui->drop_table->currentRow() ;
                int value = ui->drop_table->item(row, column)->text().toInt() ; ;
                value-- ;
                if( 0 < value )
                    ui->drop_table->item(row, column)->setText( QString::number(value) ) ;
                else
                    ui->drop_table->item(row, column)->setText( QString::number(0) ) ;
                return true ;
            } else
            if( keyEvent->key() == Qt::Key_1 ) {
                int row = ui->drop_table->currentRow() ;
                int value = ui->drop_table->item(row, column)->text().toInt() ; ;
                value++ ;
                ui->drop_table->item(row, column)->setText( QString::number(value) ) ;
                return true ;
            } else
            if( keyEvent->key() == Qt::Key_2 ) {
                int row = ui->drop_table->currentRow() ;
                int value = ui->drop_table->item(row, column)->text().toInt() ; ;
                value += 2 ;
                ui->drop_table->item(row, column)->setText( QString::number(value) ) ;
                return true ;
            } else
            if( keyEvent->key() == Qt::Key_3 ) {
                int row = ui->drop_table->currentRow() ;
                int value = ui->drop_table->item(row, column)->text().toInt() ; ;
                value += 3 ;
                ui->drop_table->item(row, column)->setText( QString::number(value) ) ;
                return true ;
            } else
            if( keyEvent->key() == Qt::Key_4 ) {
                int row = ui->drop_table->currentRow() ;
                int value = ui->drop_table->item(row, column)->text().toInt() ; ;
                value += 4 ;
                ui->drop_table->item(row, column)->setText( QString::number(value) ) ;
                return true ;
            } else
            if( keyEvent->key() == Qt::Key_5 ) {
                int row = ui->drop_table->currentRow() ;
                int value = ui->drop_table->item(row, column)->text().toInt() ; ;
                value += 5 ;
                ui->drop_table->item(row, column)->setText( QString::number(value) ) ;
                return true ;
            } else
            if( keyEvent->key() == Qt::Key_6 ) {
                int row = ui->drop_table->currentRow() ;
                int value = ui->drop_table->item(row, column)->text().toInt() ; ;
                value += 6 ;
                ui->drop_table->item(row, column)->setText( QString::number(value) ) ;
                return true ;
            } else
            if( keyEvent->key() == Qt::Key_7 ) {
                int row = ui->drop_table->currentRow() ;
                int value = ui->drop_table->item(row, column)->text().toInt() ; ;
                value += 7 ;
                ui->drop_table->item(row, column)->setText( QString::number(value) ) ;
                return true ;
            } else
            if( keyEvent->key() == Qt::Key_8 ) {
                int row = ui->drop_table->currentRow() ;
                int value = ui->drop_table->item(row, column)->text().toInt() ; ;
                value += 8 ;
                ui->drop_table->item(row, column)->setText( QString::number(value) ) ;
                return true ;
            } else
            if( keyEvent->key() == Qt::Key_9 ) {
                int row = ui->drop_table->currentRow() ;
                int value = ui->drop_table->item(row, column)->text().toInt() ; ;
                value += 9 ;
                ui->drop_table->item(row, column)->setText( QString::number(value) ) ;
                return true ;
            }
        }
    }
    return QWidget::eventFilter(o,e) ;
}

/**
 * Updates an entire section
 */
void ffrk_counter::update_information(int row)
{
    int runs = ui->drop_table->item(row, RUNS)->text().toInt() ;
    int count = ui->drop_table->item(row, COUNT)->text().toInt() ;
    double drop_rate = double(count) / double(runs) ;
    ui->drop_table->item(row, INFO)->setText(  QString::number(drop_rate) ) ;
}

/**
 * Helper function that adds another row to the table
 */
int ffrk_counter::add_row()
{
    ui->drop_table->insertRow( ui->drop_table->rowCount() ) ;
    int row = ui->drop_table->rowCount() - 1 ;

    ui->drop_table->setItem(row, NAME, new QTableWidgetItem(QString()) ) ;

    QTableWidgetItem *runs = new QTableWidgetItem(QString("0")) ;
    runs->setFlags( runs->flags() ^ Qt::ItemIsEditable ) ;
    ui->drop_table->setItem(row, RUNS, runs ) ;

    QTableWidgetItem *count = new QTableWidgetItem(QString("0")) ;
    count->setFlags( count->flags() ^ Qt::ItemIsEditable ) ;
    ui->drop_table->setItem(row, COUNT, count ) ;

    QTableWidgetItem *info = new QTableWidgetItem(QString("0")) ;
    info->setFlags( info->flags() ^ Qt::ItemIsEditable ) ;
    ui->drop_table->setItem(row, INFO, info ) ;

    return row ;
}

/** ======================================== SLOTS ======================================== **/
/**
 * Callback to update information when data has changed
 */
void ffrk_counter::on_drop_table_cellChanged(int row, int column)
{
    if( _initialized ) {
        switch(column) {
            case RUNS:
                update_information( row ) ;
                break ;
            case COUNT:
                update_information( row ) ;
                break ;
            default:
                break ;
        }
    }
}

/**
 * Adds another row to the table
 */
void ffrk_counter::on_add_row_button_clicked()
{
    add_row() ;
}

/**
 * Removes the current row from the table
 */
void ffrk_counter::on_remove_row_button_clicked()
{
    int row = ui->drop_table->currentRow() ;
    ui->drop_table->removeRow( row ) ;
}
