#include<iostream>
#include<assert.h>
#include<string>
#include<iomanip>

using namespace std;


void mainIOS()
{
	//***直接使用iostream 的函数

	double i = 32.465453;
	cout << setprecision(10) << i << endl;;	//设置小数点精确度10位
	

	cout.width(20);		//设定宽度
	cout.fill('#');			//设定填充
	cout << i;
	cout << endl;

	cout.width(20);		//设定宽度
	cout.fill('#');			//设定填充
	cout.setf(cout.left);		//设置右对齐
	//cout.setf(cout.right,cout.left);		//清除右对齐，设置左对齐
	cout << i;
	cout << endl;


	//***使用iomanip.h头文件函数

	cout << left << setw(20)<<setfill('*') << i << endl;
	cout << i;

	cout << endl;
	system("pause");
}