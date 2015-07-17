#ifndef SONCLASS_H
#define SONCLASS_H

#include"parentclass.h"

class SonClass : public ParentClass
{
public:
    SonClass();
    ~SonClass();

public:
    int setValue(int value);
    int print();
    int print(int a);
private:
    int sonValue;
};

#endif // SONCLASS_H
