#include <QtCore/QCoreApplication>
#include "Lesson08.h"
#include <stdio.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    connect_database();
    //fflush(stdout);
   // printf("hell world\n");
    //fflush(stdout);
    cout<<"hello"<<endl;
    qDebug("hell world\n");
//    cout<<"hello world"<<endl;
    return a.exec();
}
