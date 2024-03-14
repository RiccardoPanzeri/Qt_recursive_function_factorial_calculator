#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fattoriale.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_calcola_clicked();

    void on_pushButton_cancella_clicked();

private:
    Ui::MainWindow *ui;
    Fattoriale fattoriale;
};
#endif // MAINWINDOW_H
