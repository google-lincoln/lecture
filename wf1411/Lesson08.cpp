#include "Lesson08.h"
#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>



#pragma comment (lib,"sqlite3.lib")


void open_database()
{
	sqlite3* db=NULL;
	char* pathName = "student.db";
	char*zErrMsg = 0;
	int rc;

	rc = sqlite3_open(pathName,&db);

	if(SQLITE_OK==rc)
	{
		printf("Open database successfully\n");
	}
	else
	{
		printf("Cannot open database !\n");
		exit(1);
	}

	sqlite3_close(db);

}

void create_table()
{
	sqlite3* db;
	char*zErr;
	int rc;
	char* sql;

	rc =sqlite3_open("test.db",&db);

	if(rc)
	{
		fprintf(stderr,"Can't open database: %s\n",sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}

	sql = "create table episodes(id int,name text)";
	rc = sqlite3_exec(db,sql,NULL,NULL,&zErr);

	if(rc!=SQLITE_OK)
	{
		if(zErr!=NULL)
		{
			fprintf(stderr,"SQL error: %s\n",zErr);
			sqlite3_free(zErr);
		}
	}

	sql ="insert into episodes values(10,'The Dinner Party')";

	rc = sqlite3_exec(db,sql,NULL,NULL,&zErr);

	sqlite3_close(db);
	
}







void callback_test()
{
	sqlite3* db;
	int rc;
	char* sql;
	char* zErr;

	rc = sqlite3_open("test.db",&db);

	if(rc)
	{
		fprintf(stderr,"Can't open database: %s\n",sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}

	const char* data ="Callback function called";

	sql = "insert into episodes (id,name) values(11,'Mackinaw Peaches');"
		  "select * from episodes;";
	rc = sqlite3_exec(db,sql,&callBack,(void*)data,&zErr);

	if(rc!=SQLITE_OK)
	{
		if(zErr!=NULL)
		{
			fprintf(stderr,"SQL error:%s\n",zErr);
			sqlite3_free(zErr);
		}
	}

	sqlite3_close(db);
}

static int callBack(void*data,int ncols,char**values,char**headers)
{
	int i;
	fprintf(stderr,"%s:",(const char*)data);

	for(i=0;i<ncols;i++)
	{
		fprintf(stderr,"%s=%s",headers[i],values[i]);
	}
	fprintf(stderr,"\n");

	return 0;
}


void get_table()
{
	sqlite3* db;
	int rc;
	char* sql;
	char* zErr;
	char** pResult;
	int cols,rows;
	
	sql = "select * from episodes";

	rc = sqlite3_open("test.db",&db);

	if(rc)
	{
		fprintf(stderr,"Can't open database: %s\n",sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}

	sqlite3_get_table(db,sql,&pResult,&rows,&cols,&zErr);

	for(int row=0;row<rows;row++)
	{
		for(int col=0;col<cols;col++)
		{
			printf("%s:=%s\n",pResult[col],pResult[(row+1)*cols+col]);
		
		}
		printf("\n");
	}



}