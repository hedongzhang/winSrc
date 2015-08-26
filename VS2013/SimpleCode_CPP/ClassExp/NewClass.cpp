#include "NewClass.h"
#include<iostream>
using namespace std;

NewClass::NewClass()
{
}


NewClass::~NewClass()
{
}

int NewClass::jia(int x, int y)
{
	return x + y;
}
int NewClass::jian(int x, int y)
{
	return x - y;
}
int NewClass::cheng(int x, int y)
{
	return x * y;
}
int NewClass::chu(int x, int y)
{
	return x / y;
}

int NewClass::addonce(int x, int y)
{
	this->value++;
	return this->value;
}


void NewClass::print()
{
	cout <<this->value<< endl;
}