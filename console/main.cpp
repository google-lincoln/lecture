#include <QtCore/QCoreApplication>
#include <stdio.h>
#include "Lesson08.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    connect_database();

    return a.exec();
}
