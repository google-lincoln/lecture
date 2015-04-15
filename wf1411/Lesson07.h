#ifndef _LESSON07_H_
#define _LESSON07_H_




class CCurrency
{
public:
	CCurrency(int value);
	void print_exchange();
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




void exchange_rate();








#endif
