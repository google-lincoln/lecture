#include "Lesson07.h"
#include <iostream>
#include <string>

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
#if 0
	/*scanf and printf accept paramters */
	int a=0,b=3;

	scanf("%d" "%d",&a,&b);
	printf("%d" "%d",a,b);
#endif 

#if 1
	CAmerican a(100);
	CEurope e(100);

	CCurrency *p;
	p = &a;
	p->print_exchange();

	p = &e;
	p->print_exchange();
#endif

}



/*Boy class implementation begin here*/

	Boy::Boy(char * name,int age)
	{
		strcpy(this->m_name,name);
		this->m_age = age;
	}
#if 1	
void printBoy(Boy& boy)
{
		printf("Boy:%s, %d\n",boy.m_name,boy.m_age);
}

#endif

void friend_test()
{
	Boy b1("paul",43);

	printBoy(b1);

}

Girl::Girl(char* name,int age)
{
	strcpy(this->m_name,name);
	this->m_age = age;
}

void Girl::print(Boy& boy)
{
	/*The Girl can print herself and boy information */
	printf("Girl:%s, %d\n",this->m_name,this->m_age);
	printf("Boy:%s, %d\n",boy.m_name,boy.m_age);
}


void friend_boy_girl()
{
	Boy b1("paul",43);

	printBoy(b1);

	Girl g1("mary",20);

	g1.print(b1);

}

Complex::Complex(int x,int y)
{
	this->m_real =x;
	this->m_virtual = y;
}


Complex operator+(Complex& c1,Complex& c2)
{
	Complex c;
	c.m_real = c1.m_real + c2.m_real;
	c.m_virtual =c1.m_virtual + c2.m_virtual;
	return c;
}

Complex Complex::operator +(Complex& c1)
{
	Complex c;
	c.m_real = this->m_real + c1.m_real;
	c.m_virtual = this->m_virtual + c1.m_virtual;
	return c;
}

void Complex::print()
{
	cout<<"real part:"<<this->m_real<<endl;
	cout<<"virtual part:"<<this->m_virtual<<endl;
}

void operator_test()
{
#if 0
	Complex a(1,2);

	Complex b(3,5);

	Complex c;

//	c1+c2;

	c = a+b;
	c.print();
#endif 

		Complex a(1,2);

	Complex b(3,5);

	Complex c;
	/*implicit invocation and explicit invocation */

	//c = operator+(a,b);
	//c.print();
//	c = a+ b;
	c = b.operator +(a);
	c.print();

}

Complex& Complex::operator ++()
{
	this->m_real++;
	this->m_virtual++;
	return *this;
}

Complex Complex::operator ++(int)
{
	//declare a tmp variable
//	Complex *p = this;
	Complex c;
	c = *this;

	this->m_real++;
	this->m_virtual++;

	return c;
	
}

void auto_increment()
{

	Complex a(1,2);
	Complex c;
	//c = ++a;
	c =a++;
	c.print();

}

void string_test()
{
	string s1("I love you ");
	string s2("jeremy!");

	string s3("c++");

	cout<<s1+s2<<endl;

	s2=s3;

	cout<<s1+s2<<endl;

	s1[3]='h';
	s1[4]='a';
	s1[5]='t';
	s1[6]='e';

	cout<<s1+s2<<endl;
}


CShen_Stock::CShen_Stock(int a,int b,int c)
{
	this->nGeneral = a;
	this->st = b;
	this->pt = c;
}


CShang_Stock::CShang_Stock(int a,int b,int c)
{
	this->nGeneral = a;
	this->st = b;
	this->pt = c;
}




void CShen_Stock::print_Shang(CShang_Stock &shang)
{
	cout<<"total stocks:"<<shang.nGeneral+ shang.pt+ shang.st<<endl;

}


void friend_stock_print()
{
	CShang_Stock sh(30,40,50);

	CShen_Stock shen(1,2,3);

	shen.print_Shang(sh);
}

void count(CShang_Stock&shang ,CShen_Stock&sheng)
{

	cout<<"total stocks shanghai and sheng:"<<endl;
	cout<<shang.nGeneral+ shang.pt+ shang.st+sheng.nGeneral+ sheng.pt+sheng.st<<endl;

}

void tatal_print()
{

	CShang_Stock sh(30,40,50);

	CShen_Stock shen(1,2,3);

	count(sh,shen);

}