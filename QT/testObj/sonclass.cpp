#include "sonclass.h"
#include<iostream>
using namespace std;

SonClass::SonClass():sonValue(10)
{
    cout<<"���๹�캯��"<<endl;
}

SonClass::~SonClass()
{
    cout<<"�������캯��"<<endl;
}

void SonClass::setValue(int value)
{
    this->sonValue=value*value;
}

void SonClass::print()
{
    cout<<"����ֵ��"<<this->sonValue<<endl;
}

void SonClass::tempMet()
{
    cout<<"���������tempMet����"<<endl;
}
