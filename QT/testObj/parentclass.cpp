#include "parentclass.h"
#include<iostream>

using namespace std;

ParentClass::ParentClass()
{
    cout<<"���๹�캯��"<<endl;
}

ParentClass::~ParentClass()
{
    cout<<"������������"<<endl;
}

template<class T>
int ParentClass::setValue(T value)
{
    this->value=value;
}

int ParentClass::print()
{
    cout<<"����ֵ��"<<this->value<<endl;
}
