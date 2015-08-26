#include<iostream>
using namespace std;


template<typename T>
class CashBase
{
public:
	virtual T getCash(T t1) = 0;
};

template<typename T>
class CashNormal :public CashBase<T>
{
public:
	T getCash(T t1) override
	{
		return t1;
	}
};

template<typename T>
class CashRebate :public CashBase<T>
{
private:
	int moneyRebate = 10;
public:
	CashRebate(int moneyRebate)
	{
		this->moneyRebate = moneyRebate;
	}

public:
	T getCash(T t1) override
	{
		return t1 *this->moneyRebate/10;
	}
};

template<typename T>
class ContextCash
{
private:
	CashBase<T>* pCashBase;

public:
	ContextCash(string type)
	{
		if (type == "1")
		{
			this->pCashBase = new CashNormal<T>();
		}
		else if (type == "2")
		{
			this->pCashBase = new CashRebate<T>(8);
		}
	}

	T getCash(T value)
	{
		return this->pCashBase->getCash(value);
	}
};


int mainCL()
{
	ContextCash<double>* pContextCash1 = new ContextCash<double>("1");
	ContextCash<double>* pContextCash2 = new ContextCash<double>("2");

	cout<<pContextCash1->getCash(10.5)<<endl;
	cout<<pContextCash2->getCash(10.5)<<endl;

	system("pause");
}