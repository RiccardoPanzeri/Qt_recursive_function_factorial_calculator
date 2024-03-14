#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fattoriale.h"
#include <algorithm>
#include <QMessageBox>
using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber_risultato->setDigitCount(10);
    ui->lineEdit_numero->setText("0");
    ui->pushButton_calcola->setStyleSheet("QPushButton{color: rgb(97, 255, 29)} QPushButton:focus { color: white; };");
    ui->pushButton_cancella->setStyleSheet("QPushButton{color: rgb(97, 255, 29)} QPushButton:focus { color: white; };");
    ui->lcdNumber_risultato->setFocus();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_calcola_clicked()
{
    int n = 0;
    int result = 0;


    if(!ui->lineEdit_numero->text().isEmpty()){
        QString input = ui->lineEdit_numero->text();
        string inputStd = input.toStdString(); // converto la Qstring in una stringa C++
        if(all_of(inputStd.begin(), inputStd.end(), Fattoriale::isInt) && stoi(inputStd) <= 16){//con la funzione all_off della libreria algorithm, controllo che la stringa sia composta solo da numeri interi
            n = stoi(inputStd); //converto la QString in stringa c++; dopo di che la converto in numero con stoi(); il compilatore da problemi se il numero di cui calcoliamo il fattoriale è maggiore di 16, quindi setto a 16 il limite.
            result = fattoriale.calcola(n);
        }else if (!all_of(inputStd.begin(), inputStd.end(), Fattoriale::isInt)){
            QMessageBox::critical(this, "Input Errato", "Input errato!\n inserisci un numero intero positivo");
            return;
        }else if(stoi(inputStd) > 16){
            QMessageBox::critical(this, "Valore troppo grande", "Il valore inserito è troppo grande, inserisci un numero intero positivo inferiore a 17");
            ui->lineEdit_numero->setText(0);
            return;
        }
    }else{
             QMessageBox::warning(this, "Attenzione", "Campo input vuoto");
            return;
        }

        ui->lcdNumber_risultato->display(result);
        qDebug()<<"Calcolo effettuato";



    qDebug()<<fattoriale.calcola(n);



}


void MainWindow::on_pushButton_cancella_clicked()
{
    ui->lcdNumber_risultato->display(0);
    ui->lineEdit_numero->setText("0");
}

