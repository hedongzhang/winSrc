#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

class ClassTemp
{
private:
	list<int> alData;
	int num=0;
public:
	void add()
	{
		auto meth1 = [this](int i){this->num+=i; cout << this->num << endl; };
		for_each(this->alData.begin(), this->alData.end(), meth1);
	}
	void insert(int value)
	{
		alData.push_back(value);
	}
};


void mainLBD()
{
	/*auto func = [](){};
	func();

	auto func1 = [](){cout << "Hello world!" << endl; };
	func1();

	auto func2 = [](int a, int b){cout << a + b << endl; };
	func2(1,2);

	int temp = 10;
	auto func3 = [=](int x){x += temp; cout << x << endl;  };
	func3(1);

	auto func4 = [&](int x){  temp++; x *= temp; cout << x << endl;  };
	func4(1);

	list<int> lInt = {1,2,3,4,5,6};

	for_each(lInt.begin(),lInt.end(),func4);*/

	//	 ‘ temp’	副本机制，只能读temp不能写
	//int temp = 10;
	//auto func4 = [temp](int x){ x += temp; cout << x << endl;  };
	//func4(1);

	////	 ‘&temp'	 可以修改变量temp
	//int temp = 10;
	//auto func5 = [&temp](int x){ temp *= temp; x += temp; cout << x << endl;  };
	//func5(1);

	/*ClassTemp classTemp;
	classTemp.insert(1);
	classTemp.insert(2);
	classTemp.insert(3);
	classTemp.add();*/

	auto func2 = [](int a, int b)->int{cout << a + b << endl; return a + b; };
	//auto func2 = [](int a, int b)->decltype(a + b){cout << a + b << endl; return a + b; };
	cout<<func2(1,2)<<endl;

	system("pause");
}