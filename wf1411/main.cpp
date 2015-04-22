#include <iostream>
#include "Lesson07.h"
#include "Lesson08.h"



using namespace std;


int main()
{

	/*Lesson7 begin here*/
	//exchange_rate();
	//friend_test();
	//friend_boy_girl();
//	operator_test();

//	auto_increment();
//	string_test();
//	friend_stock_print();
	//tatal_print();

	//open_database();
	//create_table();
	//callback_test();
//	get_table();

	char name[20]="";
	char password[20]="";

	char sql[256]="";
	bool loginFlag = false;

	DBConn * dbConn = DBConn::getInstance();

	printf("请输入用户名:");
	scanf("%s",name);
	printf("请输入密码:");
	scanf("%s",password);

	sprintf(sql,"select * from student where studentName ='%s' and age =%s ",name,password);

	dbConn->getData(sql,login,&loginFlag);

	if(loginFlag)
	{
		printf("Login ok!\n");
	}

	return 0;
}