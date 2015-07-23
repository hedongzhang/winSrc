#include"ClassTemp.h"
#include"SonClass.h"
#include<iostream>
#include"MyArray.h"
#include<string>
#include<array>

void main()
{
	MyArray<> myArray;
	myArray[0] = 0;
	myArray[1] = 1;
	myArray[2] = 2;
	myArray[3] = 3;
	myArray[4] = 4;
	myArray.print();

	int str = myArray;
	cout << str << endl;

	system("pause");
}