#include "ClassTemp.h"
#include<iostream>

ClassTemp::ClassTemp()
{
}


ClassTemp::~ClassTemp()
{
}


void ClassTemp::print()
{
	std::cout << this->value << std::endl;
}

void FirendClass::setValue(ClassTemp& classTemp,int value)
{
	classTemp.value = value;
}