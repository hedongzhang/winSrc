#include<iostream>
#include<string>

using namespace std;

class MyExcept: public runtime_error
{
public:
	MyExcept(const string &msg) :runtime_error(msg)
	{

	}
};


class Temp
{
private:
	int a=0;
	int b = 0;
public:

	class TempExp
	{
	private:
		string msg;
	public:
		TempExp(string msg)
		{
			this->msg = msg;
		}

		string getMsg()
		{
			return this->msg;
		}
	};

	void setAB(int a,int b)
	{
		this->a = a;
		this->b = b;
	}
	int add()
	{
		if ((a + b) < 0)
		{
			throw MyExcept("相加溢出");
		}
		else if ((a + b) == 0)
		{
			//抛出自定义异常
			throw Temp::TempExp("我喜欢错误！");
		}
		else
		{
			throw runtime_error("");
		}
		return a + b;
	}
};


void mainYCCL()
{
	try
	{
		Temp t;
		//t.setAB(100000000000, 2000000000);
		//t.setAB(0, 0);
		t.setAB(1, 1);
		t.add();
	}
	catch (MyExcept e)
	{
		cout << e.what() << endl;
	}
	catch (Temp::TempExp e)
	{
		cout << e.getMsg() << endl;
	}
	catch (...)
	{
		cout << "未知错误！" << endl;
	}

	system("pause");
}