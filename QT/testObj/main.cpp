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

    SonClass* pSonClass=new SonClass;
    pSonClass->print();
}
