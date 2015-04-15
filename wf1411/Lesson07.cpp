#include "Lesson07.h"
#include <iostream>

using namespace std;

double CCurrency::ex_america = 6.3492;
double CCurrency::ex_europe = 7.9365;


CCurrency::CCurrency(int value)
{
	this->money = value;
}

void CCurrency::print_exchange()
{
//	printf("%d美元=%1f人民币\n",this->money,this->money*CCurrency::ex_america);
}


CAmerican::CAmerican(int value):CCurrency(value)
{

}

void CAmerican::set_exchangeRate(double rate)
{
	this->ex_america = rate;
}


void CAmerican::print_exchange()
{
	printf("%d美元=%1f人民币\n",this->money,this->money*CCurrency::ex_america);
}


CEurope::CEurope(int value):CCurrency(value)
{

}

void CEurope::set_exchangeRate(double rate)
{
	this->ex_europe = rate;
}

void CEurope::print_exchange()
{
	printf("%d欧元=%1f人民币\n",this->money,this->money*CCurrency::ex_europe);
}


void exchange_rate()
{
#if 0
	CAmerican a(100);
	CEurope e(100);



	a.print_exchange();
	e.print_exchange();

	a.set_exchangeRate(7.0);
	e.set_exchangeRate(10.0);

	a.print_exchange();
	e.print_exchange();
#endif 
	int a=0,b=3;

	scanf("%d" "%d",&a,&b);
	printf("%d" "%d",a,b);

#if 0
	CAmerican a(100);
	CEurope e(100);

	CCurrency *p;
	p = &a;
	p->print_exchange();

	p = &e;
	p->print_exchange();
#endif


}
