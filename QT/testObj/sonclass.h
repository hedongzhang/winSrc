#ifndef SONCLASS_H
#define SONCLASS_H

#include"parentclass.h"

class SonClass //: public ParentClass
{
public:
    SonClass();
    ~SonClass();

public:
    void setValue(int value);
    void print();
    virtual void tempMet();
private:
    int sonValue;
};

#endif // SONCLASS_H
