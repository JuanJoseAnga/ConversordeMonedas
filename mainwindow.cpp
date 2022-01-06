#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Conectar el dial de cent a fahr
    connect(ui->inCent, SIGNAL (valueChanged(int)),
            this,SLOT(cent2fahr(int)));
    //Conectar el dial de fahr a Cent
    connect(ui->inFahr, SIGNAL (valueChanged(int)),
            this,SLOT(fahr2cent(int)));
    //Conectar el dial de cent a kel
    connect(ui->inCent, SIGNAL (valueChanged(int)),
            this,SLOT(cent2kelv(int)));
    //Conectar el dial de kelv a cent
    connect(ui->inKel, SIGNAL (valueChanged(int)),
            this,SLOT(kelv2cent(int)));
    //Conectar el dial de fahr a kelv
    connect(ui->inFahr, SIGNAL (valueChanged(int)),
            this,SLOT(fahr2kelv(int)));
    //Conectar el dial de cent a kel
    connect(ui->inKel, SIGNAL (valueChanged(int)),
            this,SLOT(kelv2fahr(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cent2fahr(int cent)
{
    if(ui->inCent->hasFocus()){
        float fahr = (cent *9.0/5) + 32;
        ui->outFah->display(fahr);
    }

}

void MainWindow::fahr2cent(int i)
{
    if(ui->inFahr->hasFocus()){
        float cent = (i *9.0/5) + 32;
        ui->outCent->display(cent);
    }
}

void MainWindow::cent2kelv(int i)
{
    if(ui->inCent->hasFocus()){
        float k = i + 273;
        ui->outKel->display(k);
    }
}

void MainWindow::kelv2cent(int i)
{
    if(ui->inKel->hasFocus()){
        float c=i-273;
        ui->outCent->display(c);
    }
}

void MainWindow::fahr2kelv(int i)
{
    if(ui->inFahr->hasFocus()){
        float k=(i+459)*(5.0/9);
        ui->outKel->display(k);
    }
}

void MainWindow::kelv2fahr(int i)
{
    if(ui->inKel->hasFocus()){
        float f=(i-273)*1.8+32;
        ui->outFah->display(f);
    }
}



