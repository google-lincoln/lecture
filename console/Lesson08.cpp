#include "Lesson08.h"
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

void connect_database()
{
    sqlite3* db;
    char* zErrMsg;
    int rc;

    rc = sqlite3_open("test.db",&db);

    if(rc!=SQLITE_OK)
    {
        fprintf(stderr,"Can't open database: %s\n",sqlite3_errmsg(db));
        exit(1);
    }
    else
    {
        fprintf(stderr,"Open database sucessfully\n");
    }
    sqlite3_close(db);
    printf("hell world\n");

}
