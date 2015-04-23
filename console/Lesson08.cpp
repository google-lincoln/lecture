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
}

int createTable(void*pData,int nCols,char**values,char**headers)
{
    if(pData!=NULL)
        fprintf(stdout,"%s:\n",(const char*)pData);
    fprintf(stdout,"cols:%d\n",nCols);
    for(int col=0;col<nCols;col++)
    {
        printf("%s = %s\n",headers[col],values[col]?values[col]:"NULL");
    }
    printf("\n");
    return 0;
}

void create_table()
{
    sqlite3*db;
    char *sql;
    char*zErrMsg=0;
    int rc;

   /*Open database */
   rc = sqlite3_open("test.db",&db);
   if(rc)
   {
       fprintf(stderr,"Can't open database:%s\n",sqlite3_errmsg(db));
       exit(0);
   }
   else
   {
       fprintf(stderr,"Open database sucessfully\n");
   }

   /*Create SQL statement*/
   sql ="create table company("     \
           "id int primary key not null,"\
           "name text not null,"\
           "age  int not null,"\
           "address char(50),"\
           "salary real);";

   /*Excute SQL statement*/
   sqlite3_exec(db,sql,createTable,0,&zErrMsg);
   if(rc!=SQLITE_OK)
   {
       fprintf(stderr,"SQL error:%s\n",sqlite3_errmsg(db));
       sqlite3_free(zErrMsg);
   }
   else
   {
       fprintf(stderr,"Table created successfully\n");
   }

   sqlite3_close(db);
}


void insert_data()
{
    sqlite3* db;
    int rc;
    char *sql;
    char*zErrMsg;

    /*Open database*/
    rc = sqlite3_open("test.db",&db);

    if(rc)
    {
        fprintf(stderr,"Can't open database:%s\n",sqlite3_errmsg(db));
        exit(0);
    }
    else
    {
        fprintf(stderr,"Open database successfully\n");
    }

    /* insert SQL statement */
    sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
          "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
          "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
          "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
          "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";
    /*Execute SQL statement*/
    rc =sqlite3_exec(db,sql,createTable,0,&zErrMsg);

    if(rc)
    {
        fprintf(stderr,"SQL error: %s\n",zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout,"Records inserted successfully\n");
    }
    sqlite3_close(db);
}

void select_data()
{
    sqlite3*db;
    char*sql;
    char* zErrMsg=0;
    int rc;

    /*Open database */
    rc = sqlite3_open("test.db",&db);
    if(rc)
    {
        fprintf(stderr,"Can't open database: %s\n",sqlite3_errmsg(db));
        exit(0);
    }
    else
    {
        fprintf(stdout,"Open database successfully\n");
    }

    /*Select SQL statement*/
    sql = "select * from company";

    /*Execute SQL statement*/
    rc = sqlite3_exec(db,sql,createTable,0,&zErrMsg);

    if(rc!=SQLITE_OK)
    {
        fprintf(stderr,"SQL error:%s\n",sqlite3_errmsg(db));
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout,"Records Query successfully\n");
    }

    sqlite3_close(db);
}


void update_data()
{
    sqlite3* db ;
    int rc;
    char* zErrMsg=0;
    char* sql;

    const char* data = "Callback function called";

    /*Open database */
    rc = sqlite3_open("test.db",&db);

    if(rc!=SQLITE_OK)
    {
        fprintf(stderr,"Can't open database:%s\n",sqlite3_errmsg(db));
        exit(0);
    }
    else
    {
        fprintf(stderr,"Open database successfullly\n");
    }

    /* Create merged SQL statement */
     sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1; " \
           "SELECT * from COMPANY";

    /*Executed SQL Statement*/
     rc = sqlite3_exec(db,sql,createTable,(void*)data,&zErrMsg);

     if(rc!=SQLITE_OK)
     {
         fprintf(stderr,"SQL error:%s\n",sqlite3_errmsg(db));
         sqlite3_free(zErrMsg);
     }
     else
     {
         fprintf(stderr,"update and select success!\n");
     }

     sqlite3_close(db);
}














