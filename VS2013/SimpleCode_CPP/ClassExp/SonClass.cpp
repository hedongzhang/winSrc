#include "SonClass.h"


SonClass::SonClass()
{
}


SonClass::~SonClass()
{
}


void SonClass::setValue(int value)
{
	this->ClassTemp::setValue(value*value);
}