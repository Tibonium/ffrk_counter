#include "ffrk_counter.h"
#include "ui_ffrk_counter.h"

/**
 * Constructor
 */
ffrk_counter::ffrk_counter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ffrk_counter),
    _data_file("ffrk_counter_data"),
    _settings("Tibonium Inc.", "FFRK Counter")
{
    ui->setupUi(this);
    QIntValidator *validator = new QIntValidator(0, 1000000, this) ;
    ui->num_runs_1->setValidator( validator ) ;
    ui->num_runs_1->installEventFilter( this ) ;
    ui->count1_1->setValidator( validator ) ;
    ui->count1_1->installEventFilter( this ) ;
    ui->count2_1->setValidator( validator ) ;
    ui->count2_1->installEventFilter( this ) ;
    ui->count3_1->setValidator( validator ) ;
    ui->count3_1->installEventFilter( this ) ;

    ui->num_runs_2->setValidator( validator ) ;
    ui->num_runs_2->installEventFilter( this ) ;
    ui->count1_2->setValidator( validator ) ;
    ui->count1_2->installEventFilter( this ) ;
    ui->count2_2->setValidator( validator ) ;
    ui->count2_2->installEventFilter( this ) ;
    ui->count3_2->setValidator( validator ) ;
    ui->count3_2->installEventFilter( this ) ;

    ui->num_runs_3->setValidator( validator ) ;
    ui->num_runs_3->installEventFilter( this ) ;
    ui->count1_3->setValidator( validator ) ;
    ui->count1_3->installEventFilter( this ) ;
    ui->count2_3->setValidator( validator ) ;
    ui->count2_3->installEventFilter( this ) ;
    ui->count3_3->setValidator( validator ) ;
    ui->count3_3->installEventFilter( this ) ;

    restore_settings() ;
    load_data() ;
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
        QTextStream output( &data_out ) ;
        output << ui->item_name_1->text() << "," << ui->num_runs_1->text() << "\n" ;
        output << ui->rarity1_1->text() << "," << ui->count1_1->text() << "\n" ;
        output << ui->rarity2_1->text() << "," << ui->count2_1->text() << "\n" ;
        output << ui->rarity3_1->text() << "," << ui->count3_1->text() << "\n" ;

        output << ui->item_name_2->text() << "," << ui->num_runs_2->text() << "\n" ;
        output << ui->rarity1_2->text() << "," << ui->count1_2->text() << "\n" ;
        output << ui->rarity2_2->text() << "," << ui->count2_2->text() << "\n" ;
        output << ui->rarity3_2->text() << "," << ui->count3_2->text() << "\n" ;

        output << ui->item_name_3->text() << "," << ui->num_runs_3->text() << "\n" ;
        output << ui->rarity1_3->text() << "," << ui->count1_3->text() << "\n" ;
        output << ui->rarity2_3->text() << "," << ui->count2_3->text() << "\n" ;
        output << ui->rarity3_3->text() << "," << ui->count3_3->text() ;
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
        QTextStream input( &data_in ) ;
        while( !input.atEnd() ) {
            // Item one
            QString line = input.readLine() ;
            QStringList items = line.split(",") ;
            ui->item_name_1->setText( items[0] ) ;
            ui->num_runs_1->setText( items[1] ) ;
            line = input.readLine() ;
            items = line.split(",") ;
            ui->rarity1_1->setText( items[0] ) ;
            ui->count1_1->setText( items[1] ) ;
            line = input.readLine() ;
            items = line.split(",") ;
            ui->rarity2_1->setText( items[0] ) ;
            ui->count2_1->setText( items[1] ) ;
            line = input.readLine() ;
            items = line.split(",") ;
            ui->rarity3_1->setText( items[0] ) ;
            ui->count3_1->setText( items[1] ) ;

            // Item two
            line = input.readLine() ;
            items = line.split(",") ;
            ui->item_name_2->setText( items[0] ) ;
            ui->num_runs_2->setText( items[1] ) ;
            line = input.readLine() ;
            items = line.split(",") ;
            ui->rarity1_2->setText( items[0] ) ;
            ui->count1_2->setText( items[1] ) ;
            line = input.readLine() ;
            items = line.split(",") ;
            ui->rarity2_2->setText( items[0] ) ;
            ui->count2_2->setText( items[1] ) ;
            line = input.readLine() ;
            items = line.split(",") ;
            ui->rarity3_2->setText( items[0] ) ;
            ui->count3_2->setText( items[1] ) ;

            // Item three
            ui->item_name_3->setText( items[0] ) ;
            ui->num_runs_3->setText( items[1] ) ;
            line = input.readLine() ;
            items = line.split(",") ;
            ui->rarity1_3->setText( items[0] ) ;
            ui->count1_3->setText( items[1] ) ;
            line = input.readLine() ;
            items = line.split(",") ;
            ui->rarity2_3->setText( items[0] ) ;
            ui->count2_3->setText( items[1] ) ;
            line = input.readLine() ;
            items = line.split(",") ;
            ui->rarity3_3->setText( items[0] ) ;
            ui->count3_3->setText( items[1] ) ;
            line = input.readLine() ;
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
    QLineEdit *obj = static_cast<QLineEdit*>(o) ;
    /** ============================= Section One ============================= **/
    if( obj == ui->num_runs_1 ) {
        if( e->type() == QEvent::KeyPress ) {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(e) ;
            if( keyEvent->key() == Qt::Key_Up ) {
                int value = ui->num_runs_1->text().toInt() ;
                value++ ;
                ui->num_runs_1->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Down ) {
                int value = ui->num_runs_1->text().toInt() ;
                value-- ;
                if( value < 0 )
                    ui->num_runs_1->setText( QString::number(0) ) ;
                else
                    ui->num_runs_1->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Delete ) {
                ui->num_runs_1->setText( QString::number(0) ) ;
            }
        }
    } else
    if( obj == ui->count1_1 ) {
        if( e->type() == QEvent::KeyPress ) {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(e) ;
            if( keyEvent->key() == Qt::Key_Up ) {
                int value = ui->count1_1->text().toInt() ;
                value++ ;
                ui->count1_1->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Down ) {
                int value = ui->count1_1->text().toInt() ;
                value-- ;
                if( value < 0 )
                    ui->count1_1->setText( QString::number(0) ) ;
                else
                    ui->count1_1->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Delete ) {
                ui->count1_1->setText( QString::number(0) ) ;
            }
        }
    } else
    if( obj == ui->count2_1 ) {
        if( e->type() == QEvent::KeyPress ) {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(e) ;
            if( keyEvent->key() == Qt::Key_Up ) {
                int value = ui->count2_1->text().toInt() ;
                value++ ;
                ui->count2_1->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Down ) {
                int value = ui->count2_1->text().toInt() ;
                value-- ;
                if( value < 0 )
                    ui->count2_1->setText( QString::number(0) ) ;
                else
                    ui->count2_1->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Delete ) {
                ui->count2_1->setText( QString::number(0) ) ;
            }
        }
    } else
    if( obj == ui->count3_1 ) {
        if( e->type() == QEvent::KeyPress ) {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(e) ;
            if( keyEvent->key() == Qt::Key_Up ) {
                int value = ui->count3_1->text().toInt() ;
                value++ ;
                ui->count3_1->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Down ) {
                int value = ui->count3_1->text().toInt() ;
                value-- ;
                if( value < 0 )
                    ui->count3_1->setText( QString::number(0) ) ;
                else
                    ui->count3_1->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Delete ) {
                ui->count3_1->setText( QString::number(0) ) ;
            }
        }
    } else
    /** ============================= Section two ============================= **/
    if( obj == ui->num_runs_2 ) {
        if( e->type() == QEvent::KeyPress ) {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(e) ;
            if( keyEvent->key() == Qt::Key_Up ) {
                int value = ui->num_runs_2->text().toInt() ;
                value++ ;
                ui->num_runs_2->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Down ) {
                int value = ui->num_runs_2->text().toInt() ;
                value-- ;
                if( value < 0 )
                    ui->num_runs_2->setText( QString::number(0) ) ;
                else
                    ui->num_runs_2->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Delete ) {
                ui->num_runs_2->setText( QString::number(0) ) ;
            }
        }
    } else
    if( obj == ui->count1_2 ) {
        if( e->type() == QEvent::KeyPress ) {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(e) ;
            if( keyEvent->key() == Qt::Key_Up ) {
                int value = ui->count1_2->text().toInt() ;
                value++ ;
                ui->count1_2->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Down ) {
                int value = ui->count1_2->text().toInt() ;
                value-- ;
                if( value < 0 )
                    ui->count1_2->setText( QString::number(0) ) ;
                else
                    ui->count1_2->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Delete ) {
                ui->count1_2->setText( QString::number(0) ) ;
            }
        }
    } else
    if( obj == ui->count2_2 ) {
        if( e->type() == QEvent::KeyPress ) {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(e) ;
            if( keyEvent->key() == Qt::Key_Up ) {
                int value = ui->count2_2->text().toInt() ;
                value++ ;
                ui->count2_2->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Down ) {
                int value = ui->count2_2->text().toInt() ;
                value-- ;
                if( value < 0 )
                    ui->count2_2->setText( QString::number(0) ) ;
                else
                    ui->count2_2->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Delete ) {
                ui->count2_2->setText( QString::number(0) ) ;
            }
        }
    } else
    if( obj == ui->count3_2 ) {
        if( e->type() == QEvent::KeyPress ) {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(e) ;
            if( keyEvent->key() == Qt::Key_Up ) {
                int value = ui->count3_2->text().toInt() ;
                value++ ;
                ui->count3_2->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Down ) {
                int value = ui->count3_2->text().toInt() ;
                value-- ;
                if( value < 0 )
                    ui->count3_2->setText( QString::number(0) ) ;
                else
                    ui->count3_2->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Delete ) {
                ui->count3_2->setText( QString::number(0) ) ;
            }
        }
    } else
    /** ============================= Section three ============================= **/
    if( obj == ui->num_runs_3 ) {
        if( e->type() == QEvent::KeyPress ) {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(e) ;
            if( keyEvent->key() == Qt::Key_Up ) {
                int value = ui->num_runs_3->text().toInt() ;
                value++ ;
                ui->num_runs_3->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Down ) {
                int value = ui->num_runs_3->text().toInt() ;
                value-- ;
                if( value < 0 )
                    ui->num_runs_3->setText( QString::number(0) ) ;
                else
                    ui->num_runs_3->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Delete ) {
                ui->num_runs_3->setText( QString::number(0) ) ;
            }
        }
    } else
    if( obj == ui->count1_3 ) {
        if( e->type() == QEvent::KeyPress ) {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(e) ;
            if( keyEvent->key() == Qt::Key_Up ) {
                int value = ui->count1_3->text().toInt() ;
                value++ ;
                ui->count1_3->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Down ) {
                int value = ui->count1_3->text().toInt() ;
                value-- ;
                if( value < 0 )
                    ui->count1_3->setText( QString::number(0) ) ;
                else
                    ui->count1_3->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Delete ) {
                ui->count1_3->setText( QString::number(0) ) ;
            }
        }
    } else
    if( obj == ui->count2_3 ) {
        if( e->type() == QEvent::KeyPress ) {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(e) ;
            if( keyEvent->key() == Qt::Key_Up ) {
                int value = ui->count2_3->text().toInt() ;
                value++ ;
                ui->count2_3->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Down ) {
                int value = ui->count2_3->text().toInt() ;
                value-- ;
                if( value < 0 )
                    ui->count2_3->setText( QString::number(0) ) ;
                else
                    ui->count2_3->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Delete ) {
                ui->count2_3->setText( QString::number(0) ) ;
            }
        }
    } else
    if( obj == ui->count3_3 ) {
        if( e->type() == QEvent::KeyPress ) {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(e) ;
            if( keyEvent->key() == Qt::Key_Up ) {
                int value = ui->count3_3->text().toInt() ;
                value++ ;
                ui->count3_3->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Down ) {
                int value = ui->count3_3->text().toInt() ;
                value-- ;
                if( value < 0 )
                    ui->count3_3->setText( QString::number(0) ) ;
                else
                    ui->count3_3->setText( QString::number(value) ) ;
            } else
            if( keyEvent->key() == Qt::Key_Delete ) {
                ui->count3_3->setText( QString::number(0) ) ;
            }
        }
    }

    return QWidget::eventFilter(obj,e) ;
}

/**
 * Updates an entire section
 */
void ffrk_counter::update_drop_rate(int section)
{
    int num_runs = 0 ;
    int drop_count1 = 0 ;
    int drop_count2 = 0 ;
    int drop_count3 = 0 ;
    double drop_rate = 0 ;
    QString tmp("Drop Rate: ") ;
    switch( section ) {
        case 1:
            num_runs = ui->num_runs_1->text().toInt() ;
            // First Rarity
            drop_count1 = ui->count1_1->text().toInt() ;
            drop_rate = double(drop_count1) / double(num_runs) ;
            ui->drop1_1->setText( tmp + QString::number(drop_rate) ) ;
            // Second Rarity
            drop_count2 = ui->count2_1->text().toInt() ;
            drop_rate = double(drop_count2) / double(num_runs) ;
            ui->drop2_1->setText( tmp + QString::number(drop_rate) ) ;
            // Third Rarity
            drop_count3 = ui->count3_1->text().toInt() ;
            drop_rate = double(drop_count3) / double(num_runs) ;
            ui->drop3_1->setText( tmp + QString::number(drop_rate) ) ;
            break ;
        case 2:
            num_runs = ui->num_runs_2->text().toInt() ;
            // First Rarity
            drop_count1 = ui->count1_2->text().toInt() ;
            drop_rate = double(drop_count1) / double(num_runs) ;
            ui->drop1_2->setText( tmp + QString::number(drop_rate) ) ;
            // Second Rarity
            drop_count2 = ui->count2_2->text().toInt() ;
            drop_rate = double(drop_count2) / double(num_runs) ;
            ui->drop2_2->setText( tmp + QString::number(drop_rate) ) ;
            // Third Rarity
            drop_count3 = ui->count3_2->text().toInt() ;
            drop_rate = double(drop_count3) / double(num_runs) ;
            ui->drop3_2->setText( tmp + QString::number(drop_rate) ) ;
            break ;
        case 3:
            num_runs = ui->num_runs_3->text().toInt() ;
            // First Rarity
            drop_count1 = ui->count1_3->text().toInt() ;
            drop_rate = double(drop_count1) / double(num_runs) ;
            ui->drop1_3->setText( tmp + QString::number(drop_rate) ) ;
            // Second Rarity
            drop_count2 = ui->count2_3->text().toInt() ;
            drop_rate = double(drop_count2) / double(num_runs) ;
            ui->drop2_3->setText( tmp + QString::number(drop_rate) ) ;
            // Third Rarity
            drop_count3 = ui->count3_3->text().toInt() ;
            drop_rate = double(drop_count3) / double(num_runs) ;
            ui->drop3_3->setText( tmp + QString::number(drop_rate) ) ;
            break ;
        default:
            break ;
    }
}

/**
 * Updates a single rarity of a section
 */
void ffrk_counter::update_drop_rate(int section, int rarity)
{
    int num_runs = 0 ;
    int drop_count = 0 ;
    double drop_rate = 0 ;
    QString tmp("Drop Rate: ") ;
    switch( section ) {
        case 1:
            num_runs = ui->num_runs_1->text().toInt() ;
            switch( rarity ) {
                case 1:
                    drop_count = ui->count1_1->text().toInt() ;
                    drop_rate = double(drop_count) / double(num_runs) ;
                    tmp += QString::number(drop_rate) ;
                    ui->drop1_1->setText( tmp ) ;
                    break ;
                case 2:
                    drop_count = ui->count2_1->text().toInt() ;
                    drop_rate = double(drop_count) / double(num_runs) ;
                    tmp += QString::number(drop_rate) ;
                    ui->drop2_1->setText( tmp ) ;
                    break ;
                case 3:
                    drop_count = ui->count3_1->text().toInt() ;
                    drop_rate = double(drop_count) / double(num_runs) ;
                    tmp += QString::number(drop_rate) ;
                    ui->drop3_1->setText( tmp ) ;
                    break ;
                default:
                    break ;
            }
            break ;
        case 2:
            num_runs = ui->num_runs_2->text().toInt() ;
            switch( rarity ) {
                case 1:
                    drop_count = ui->count1_2->text().toInt() ;
                    drop_rate = double(drop_count) / double(num_runs) ;
                    tmp += QString::number(drop_rate) ;
                    ui->drop1_2->setText( tmp ) ;
                    break ;
                case 2:
                    drop_count = ui->count2_2->text().toInt() ;
                    drop_rate = double(drop_count) / double(num_runs) ;
                    tmp += QString::number(drop_rate) ;
                    ui->drop2_2->setText( tmp ) ;
                    break ;
                case 3:
                    drop_count = ui->count3_2->text().toInt() ;
                    drop_rate = double(drop_count) / double(num_runs) ;
                    tmp += QString::number(drop_rate) ;
                    ui->drop3_2->setText( tmp ) ;
                    break ;
                default:
                    break ;
            }
            break ;
        case 3:
            num_runs = ui->num_runs_3->text().toInt() ;
            switch( rarity ) {
                case 1:
                    drop_count = ui->count1_3->text().toInt() ;
                    drop_rate = double(drop_count) / double(num_runs) ;
                    tmp += QString::number(drop_rate) ;
                    ui->drop1_3->setText( tmp ) ;
                    break ;
                case 2:
                    drop_count = ui->count2_3->text().toInt() ;
                    drop_rate = double(drop_count) / double(num_runs) ;
                    tmp += QString::number(drop_rate) ;
                    ui->drop2_3->setText( tmp ) ;
                    break ;
                case 3:
                    drop_count = ui->count3_3->text().toInt() ;
                    drop_rate = double(drop_count) / double(num_runs) ;
                    tmp += QString::number(drop_rate) ;
                    ui->drop3_3->setText( tmp ) ;
                    break ;
                default:
                    break ;
            }
            break ;
        default:
            break ;
    }
}

/** ======================================== SLOTS ======================================== **/
/**
 * Callbacks for information updated in Item 1's section
 */
void ffrk_counter::on_num_runs_1_textChanged(const QString &arg1)
{
    if( 0 < arg1.toInt() ) {
        update_drop_rate( 1 ) ;
    } else {
        ui->drop1_1->setText("Drop Rate: ---") ;
        ui->drop2_1->setText("Drop Rate: ---") ;
        ui->drop3_1->setText("Drop Rate: ---") ;
    }
}

void ffrk_counter::on_count1_1_textChanged(const QString &arg1)
{
    if( -1 < arg1.toInt() )
        update_drop_rate( 1, 1 ) ;
}

void ffrk_counter::on_count2_1_textChanged(const QString &arg1)
{
    if( -1 < arg1.toInt() )
        update_drop_rate( 1, 2 ) ;
}

void ffrk_counter::on_count3_1_textChanged(const QString &arg1)
{
    if( -1 < arg1.toInt() )
        update_drop_rate( 1, 3 ) ;
}

/**
 * Callbacks for information updated in Item 2's section
 */
void ffrk_counter::on_num_runs_2_textChanged(const QString &arg1)
{
    if( 0 < arg1.toInt() ) {
        update_drop_rate( 2 ) ;
    } else {
        ui->drop1_2->setText("Drop Rate: ---") ;
        ui->drop2_2->setText("Drop Rate: ---") ;
        ui->drop3_2->setText("Drop Rate: ---") ;
    }
}

void ffrk_counter::on_count1_2_textChanged(const QString &arg1)
{
    if( -1 < arg1.toInt() )
        update_drop_rate( 2, 1 ) ;
}

void ffrk_counter::on_count2_2_textChanged(const QString &arg1)
{
    if( -1 < arg1.toInt() )
        update_drop_rate( 2, 2 ) ;
}

void ffrk_counter::on_count3_2_textChanged(const QString &arg1)
{
    if( -1 < arg1.toInt() )
        update_drop_rate( 2, 3 ) ;
}

/**
 * Callbacks for information updated in Item 3's section
 */
void ffrk_counter::on_num_runs_3_textChanged(const QString &arg1)
{
    if( 0 < arg1.toInt() ) {
        update_drop_rate( 3 ) ;
    } else {
        ui->drop1_3->setText("Drop Rate: ---") ;
        ui->drop2_3->setText("Drop Rate: ---") ;
        ui->drop3_3->setText("Drop Rate: ---") ;
    }
}

void ffrk_counter::on_count1_3_textChanged(const QString &arg1)
{
    if( -1 < arg1.toInt() )
        update_drop_rate( 3, 1 ) ;
}

void ffrk_counter::on_count2_3_textChanged(const QString &arg1)
{
    if( -1 < arg1.toInt() )
        update_drop_rate( 3, 2 ) ;
}

void ffrk_counter::on_count3_3_textChanged(const QString &arg1)
{
    if( -1 < arg1.toInt() )
        update_drop_rate( 3, 3 ) ;
}
