#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//AGREGAR AL ZOOM
void MainWindow::keyPressEvent(QKeyEvent *evento)
{                                      // VK = VIRTUAL KEY
    if(evento->key() == Qt::Key_Up) //FLECHA ARRIBA en WINDOWS VK_UP
        ui->label->setText("PRESIONASTE TECLA ARRIBA");
    if(evento->key() == Qt::Key_Down)
        ui->label->setText("PRESIONASTE FLECHA ABAJO");
    if(evento->key() == Qt::Key_A)
        ui->label->setText("PRESIONASTE LA TECLA A");
    if(evento->key() == Qt::Key_F10)
        this->close();
}

