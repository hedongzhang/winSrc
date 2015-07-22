#include"mainwindow.h"
#include<iostream>
#include<QApplication>
#include"parentclass.h"
#include"sonclass.h"

using namespace std;


int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    //return a.exec();

    //ParentClass* pParentClass=new ParentClass;

    ParentClass<int>* pParentClass=new ParentClass<int>();
    //SonClass* pSonClass=new SonClass;
//    pSonClass->print();
//    pSonClass->tempMet();
    //cout<<sizeof(ParentClass<int>)<<endl;
    //cout<<sizeof(*pSonClass)<<endl;
    delete pParentClass;
}
