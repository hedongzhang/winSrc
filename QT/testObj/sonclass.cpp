#include "sonclass.h"
#include<iostream>
using namespace std;

SonClass::SonClass():sonValue(10)
{
    cout<<"子类构造函数"<<endl;
}

SonClass::~SonClass()
{
    cout<<"子类析造函数"<<endl;
}

void SonClass::setValue(int value)
{
    this->sonValue=value*value;
}

void SonClass::print()
{
    cout<<"子类值："<<this->sonValue<<endl;
}

void SonClass::tempMet()
{
    cout<<"我是子类的tempMet函数"<<endl;
}
