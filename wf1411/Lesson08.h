#ifndef _LESSON08_H_
#define _LESSON08_H_
#include "sqlite3.h"

void open_database();
void create_table();

static int callBack(void* data,int ncols,char**values,char**headers);
int login(void *pData,int ncols,char** values,char** headers);

void callback_test();

void get_table();

class DBConn
{
public:
	int getData(char*,sqlite3_callback,void*);
	static DBConn* getInstance();
private:
	friend class Garbo;
	DBConn();
	~DBConn();
	static DBConn* pConn;
	sqlite3 *db;
};

class Garbo
{
public:
	Garbo();
	~Garbo();
private:
	static Garbo garbo;
};

#endif
