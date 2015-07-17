#include"ClassTemp.h"
#include"SonClass.h"
#include<iostream>


void main()
{

	SonClass sonClass;
	sonClass.setValue(190);
	sonClass.print();

	ClassTemp* pTClass = &sonClass;
	pTClass->setValue(190);
	pTClass->print();

	system("pause");
}