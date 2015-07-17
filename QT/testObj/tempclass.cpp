#include "tempclass.h"
#include<iostream>
#include<cmath>

tempclass::tempclass()
{
    std::cout<<"gou zao han shu"<<std::endl;
    this->value=0;
}

tempclass::tempclass(int value)
{
    std::cout<<"gou zao han shu"<<std::endl;
    this->value=value;
}

tempclass::tempclass(tempclass& value)
{
    std::cout<<"kao bei gou zao han shu"<<std::endl;
}

tempclass::operator int()
{
    std::cout<<"int dui xiang gou zao han shu "<<std::endl;
    return this->value;
}

void tempclass::printt()
{
    std::cout << this->value << std::endl;
}
