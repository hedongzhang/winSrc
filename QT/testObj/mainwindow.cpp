#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->x=1000;
//    this->y=500;
//    resize(this->x,this->y);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*MainWindow::MainWindow(const MainWindow& other)
{
}
*/
