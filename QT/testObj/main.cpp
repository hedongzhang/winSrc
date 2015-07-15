#include "mainwindow.h"
#include "tempclass.h"
#include<iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //MainWindow w1(w);
    //w1.show();

//    tempclass cl;
//    cl.printt();

//    tempclass c2(cl);
//    c2.printt();

//    tempclass c3=cl;
//    c3.printt();

    tempclass c4;
    int i=(int)c4;
    c4.printt();
    std::cout<<i<<std::endl;



    return a.exec();
}
