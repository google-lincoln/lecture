#include "Lesson08.h"
#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>

void connect_database()
{

    sqlite3* db;
    char* zErr=0;
    int rc;

    rc = sqlite3_open("test.db",&db);

    if(rc)
    {
        fprintf(stderr,"Can't open database: %s\n",sqlite3_errmsg(db));
        exit(0);
    }
    else
    {
        fprintf(stderr,"Opened database successfully\n");
    }
    sqlite3_close(db);

}
