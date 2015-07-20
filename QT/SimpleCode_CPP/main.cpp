#include <iostream>
#include<parentclass.h>

using namespace std;

int main()
{
    SonClass* pSonClass=new SonClass;
    pSonClass->print();

    cout << "Hello World!" << endl;
    return 0;
}

