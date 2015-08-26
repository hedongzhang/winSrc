#include<iostream>
using namespace std;


template<typename T>
class Operator
{
public:
	virtual T getResult(T t1,T t2) = 0;
};

template<typename T>
class AddOperator:public Operator<T>
{
public:
	T getResult(T t1, T t2) override
	{
		return t1 + t2;
	}
};

template<typename T>
class MulOperator :public Operator<T>
{
public:
	T getResult(T t1, T t2) override
	{
		return t1 * t2;
	}
};

template<typename T>
class OperatorFactory
{
public:
	static Operator<T>* creatOperator(string type)
	{
		if (type == "+")
		{
			return new AddOperator<T>();
		}
		else if (type == "*")
		{
			return new MulOperator<T>();
		}
	}
};


void mainJDGC()
{
	Operator<int>* pOperator1 = OperatorFactory<int>::creatOperator("+");
	Operator<int>* pOperator2 = OperatorFactory<int>::creatOperator("*");
	cout<<pOperator1->getResult(6, 3)<<endl;
	cout << pOperator2->getResult(6, 3) << endl;


	system("pause");
}