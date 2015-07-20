#include "parentclass.h"
#include<iostream>

using namespace std;

ParentClass::ParentClass()
{
    cout<<"父类构造函数"<<endl;
}

ParentClass::~ParentClass()
{
    cout<<"父类析构函数"<<endl;
}

template<class T>
int ParentClass::setValue(T value)
{
    this->value=value;
}

int ParentClass::print()
{
    cout<<"父类值："<<this->value<<endl;
}
