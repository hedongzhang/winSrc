#include "SonClass.h"


SonClass::SonClass()
{
	cout << "���๹�캯��" << endl;
	this->temp = new int[100000000];
}


SonClass::~SonClass()
{
	cout << "������������" << endl;
	delete[](this->temp);
}


void SonClass::setValue(int value)
{
	this->ClassTemp::setValue(value*value);
}

void SonClass::setPP(int value)
{
	this->sonValue = value;
}