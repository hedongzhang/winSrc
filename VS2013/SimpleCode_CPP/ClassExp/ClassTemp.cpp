#include "ClassTemp.h"
#include<iostream>

ClassTemp::ClassTemp()
{
}


ClassTemp::~ClassTemp()
{
}


int ClassTemp::print()
{
	std::cout << this->value << std::endl;
	return this->value;
}

ClassTemp& ClassTemp::operator+(ClassTemp& tempclass)
{
	this->value += tempclass.value;
	return *this;
}

void FirendClass::setValue(ClassTemp& classTemp,int value)
{
	classTemp.value = value;
}

void FirendClass::setValue(int value)
{
	this->value = value;
}
int FirendClass::printf()
{
	std::cout << this->value << std::endl;
	return this->value;
}

ostream& operator<<(ostream& ostre, ClassTemp classTemp)
{
	return ostre << classTemp.value;
}



FirendClass& operator+(ClassTemp& tempclass, FirendClass& firendclass)
{
	firendclass.setValue(tempclass.print() + firendclass.printf());
	return firendclass;
}