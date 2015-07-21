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

    return 1;
}
