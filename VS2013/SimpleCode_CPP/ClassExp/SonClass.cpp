#include "SonClass.h"


SonClass::SonClass()
{
	cout << "子类构造函数" << endl;
	this->temp = new int[100000000];
}


SonClass::~SonClass()
{
	cout << "子类析构函数" << endl;
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