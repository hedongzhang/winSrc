#include "parentclass.h"
#include<iostream>

using namespace std;

ParentClass::ParentClass():value(5)
{
    cout<<"���๹�캯��"<<endl;
}

ParentClass::~ParentClass()
{
    cout<<"������������"<<endl;
}

int ParentClass::setValue(int value)
{
    this->value=value;
}

int ParentClass::print()
{
    cout<<"����ֵ��"<<this->value<<endl;
}
