#ifndef PARENTCLASS_H
#define PARENTCLASS_H

#include<iostream>
using namespace std;

template<class T>
class ParentClass
{
public:
    ParentClass(){cout<<"���๹�캯��"<<endl;}
    virtual ~ParentClass(){cout<<"������������"<<endl;}

public:
    virtual void setValue(T value){this->value=value;}
    void print(){cout<<"����ֵ��"<<this->value<<endl;}
    //virtual int tempMet();
private:
    T value;
};

#endif // PARENTCLASS_H
