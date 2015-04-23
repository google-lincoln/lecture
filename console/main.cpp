#include <QtCore/QCoreApplication>
#include <stdio.h>
#include "Lesson08.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //connect_database();
    //create_table();
    ///insert_data();
    //select_data();
    update_data();
    return a.exec();
}
