#include"ClassTemp.h"
#include<iostream>

void main1()
{
	ClassTemp classTemp;
	cout << classTemp << endl;
	FirendClass firendClass;
	firendClass.printf();
	firendClass.setValue(classTemp, 8);
	//cout << classTemp << endl;

	firendClass=classTemp + firendClass;
	firendClass.printf();

	ClassTemp classTemp1(classTemp);
	//cout << classTemp1 << endl;

	system("pause");
}