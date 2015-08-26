#include<stdlib.h>
#include<iostream>

using namespace std;

class ClassA
{

	virtual void method1()
	{
		cout << "ClassA::method1" << endl;
	}
	void method2()
	{
		cout << "ClassA::method2" << endl;
	}
};

class ClassB :public ClassA
{
private:
	int data = 0;
//public:
	void method1()
	{
		cout << "ClassB::method1" << endl;
	}
	virtual void method3()
	{
		cout << "ClassB::method3" << endl;
	}
};

typedef void(*FUN)();

void mainXHSB()
{
	//ClassA a;
	ClassB b;
	cout << sizeof(ClassA) << endl;
	cout << sizeof(b) << endl;

	for (size_t i = 0; i < 2; i++)
	{
		FUN fun = (FUN)*((int*)*(int*)(&b) + i);
		fun();
	}
	

	system("pause");
}