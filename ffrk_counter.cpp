#include "ffrk_counter.h"
#include "ui_ffrk_counter.h"

/**
 * Constructor
 */
ffrk_counter::ffrk_counter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ffrk_counter)
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

}

/**
 * Destructor
 */
ffrk_counter::~ffrk_counter()
{
    delete ui;
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
