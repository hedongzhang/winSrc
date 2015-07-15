#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
public:
    Q_OBJECT
public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //MainWindow(const MainWindow&);

private:
    Ui::MainWindow *ui;
    int x,y;
};

#endif // MAINWINDOW_H
