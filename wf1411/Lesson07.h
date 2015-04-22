#ifndef _LESSON07_H_
#define _LESSON07_H_




class CCurrency
{
public:
	CCurrency(int value);
	virtual void print_exchange();
	void set_exchangeRate(double);

/*
	private: 1) why use prectected access type 2) why use static variable
	1) because we want the derive class can access the base variable
	2) because we want only copy for all the derived class instead of one copy for each object
*/

protected:
	static double ex_america;/*exchange rate of america*/
	static double ex_europe;
	int money;
};



class CAmerican:public CCurrency
{
public:
	CAmerican(int value);
	void print_exchange();
	void set_exchangeRate(double);
private:

};



class CEurope:public CCurrency
{
public:
	CEurope(int value);
	void print_exchange();
	void set_exchangeRate(double);
private:
};

class Boy;

class Girl
{
public:
	Girl(char*,int);
	void print(Boy&);
private:
	int m_age;
	char m_name[20];
};

class Boy
{
public:
	Boy(char*,int);
private:
	int m_age;
	char m_name[20];
	/*it doesn't matter where you declare in public or in private*/
	friend void printBoy(Boy &);
//	friend void Girl::print(Boy&);
	/*if we want all the girl class can access all the private variable fo boy*/
	friend class Girl;
};



/*类外的普通函数打印男孩信息*/


void exchange_rate();

void friend_test();


void friend_boy_girl();

class Complex
{

public:
	Complex(int x=0,int y=0);
	void print();

    Complex operator+(Complex&);
	friend Complex operator +(Complex&,Complex&);
//实现类成员复数自增
	//++a 返回自增之后的
Complex& operator ++();
Complex operator++(int);

private:
	int m_real;
	int m_virtual;

};

void operator_test();


void auto_increment();

void string_test();


class CShang_Stock;

class CShen_Stock
{
public:
	CShen_Stock(int,int,int);
	void print_Shang(CShang_Stock&);
	friend void count(CShang_Stock&shang ,CShen_Stock&sheng);
private:
	int nGeneral;
	int st;
	int pt;
};


class CShang_Stock
{
public:
	CShang_Stock(int,int,int);
	friend	void CShen_Stock::print_Shang(CShang_Stock&);
	friend void count(CShang_Stock&shang ,CShen_Stock&sheng);
private:
	int nGeneral;
	int st;
	int pt;
};


void count(CShang_Stock& ,CShen_Stock&);

void friend_stock_print();

void tatal_print();

#endif
