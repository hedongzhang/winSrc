#include"ClassTemp.h"
#include<iostream>

void main()
{
	ClassTemp classTemp;
	classTemp.print();
	FirendClass firendClass;
	firendClass.setValue(classTemp, 8);
	classTemp.print();

	ClassTemp classTemp1(classTemp);
	classTemp1.print();

	system("pause");
}