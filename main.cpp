#include "mainwindow.h"
#include <QMainWindow>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Calcolatore del Fattoriale");

    w.show();
    return a.exec();
}
