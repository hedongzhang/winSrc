#ifndef PARENTCLASS_H
#define PARENTCLASS_H

#include<iostream>
using namespace std;

template<class T>
class ParentClass
{
public:
    ParentClass(){cout<<"父类构造函数"<<endl;}
    virtual ~ParentClass(){cout<<"父类析构函数"<<endl;}

public:
    virtual void setValue(T value){this->value=value;}
    void print(){cout<<"父类值："<<this->value<<endl;}
    //virtual int tempMet();
private:
    T value;
};

#endif // PARENTCLASS_H
