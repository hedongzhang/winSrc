#include"mainwindow.h"
#include<iostream>
#include<QApplication>
#include"parentclass.h"
#include"sonclass.h"

using namespace std;


int main(int argc, char *argv[])
{
    ParentClass<int>* pParentClass=new ParentClass<int>();
    delete pParentClass;

    SonClass* pSonClass=new SonClass();
    pSonClass->print();
    delete pSonClass;

    return 1;
}
