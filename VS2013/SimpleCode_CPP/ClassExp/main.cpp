#include"ClassTemp.h"
#include"SonClass.h"
#include<iostream>


void main()
{
	ClassTemp* pTempClass=new ClassTemp;
	pTempClass->setValue(10);
	pTempClass->print();

	SonClass* pSonClass =static_cast<SonClass>(pTempClass);
	delete(pSonClass);

	


	/*SonClass sonClass;
	sonClass.setValue(20);
	sonClass.print();

	ClassTemp* pTempClass=&sonClass;
	pTempClass->setValue(20);
	pTempClass->print();*/

	system("pause");
}