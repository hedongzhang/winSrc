#ifndef PARENTCLASS_H
#define PARENTCLASS_H

template<class T>
class ParentClass
{
public:
    ParentClass();
    virtual ~ParentClass();

public:
    extern virtual int setValue(T value);
    extern int print();
    //virtual int tempMet();
private:
    T value;
};

#endif // PARENTCLASS_H
