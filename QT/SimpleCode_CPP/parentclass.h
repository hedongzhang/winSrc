#ifndef PARENTCLASS_H
#define PARENTCLASS_H


class ParentClass
{
public:
    ParentClass();
    virtual ~ParentClass();

public:
    int setValue(int value);
    int print();
private:
    int value=0;
};

#endif // PARENTCLASS_H
