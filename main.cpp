#include "ffrk_counter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ffrk_counter w;
    w.show();

    return a.exec();
}
