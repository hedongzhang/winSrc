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

int SonClass::setValue(int value)
{
    this->sonValue=value*value;
}

int SonClass::print(int a)
{
    cout<<"����ֵ��"<<this->sonValue<<endl;
}
int SonClass::print()
{
    cout<<"����ֵ��"<<this->sonValue<<endl;
}

int SonClass::tempMet()
{
    cout<<"���������tempMet����"<<endl;
}
