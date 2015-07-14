#include "mainwindow.h"
#include "tempclass.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //MainWindow w1(w);
    //w1.show();

    tempclass cl;
    cl.printt();

    tempclass c2(cl);
    c2.printt();

    return a.exec();
}
