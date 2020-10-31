#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(moverEtiqueta()));
    connect(timer, SIGNAL(timeout()), this, SLOT(moverEtiqueta()));
    connect(timer, SIGNAL(timeout()), this, SLOT(moverEtiqueta()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    timer->start(50);
}

void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}

void MainWindow::moverEtiqueta()
{//static en C/C++ nos permite mantener el valor de una variable
    // en sucesivas llamadas al metodo donde se declara
    // similar al usar una variable global, pero controlada dentro del metodo
    // static int x = 0
    static int x = 0;
    static int y = 0;
    static bool band = true;



        if(ui->label->geometry().x() < (ui->widget->geometry().width() - ui->label->width()) && band)
        {
            ui->label->setStyleSheet("background-image: url(:/new/prefix1/pez.png)");
            //ui->label_2->setStyleSheet("background-image: url(:/new/prefix1/pez_moradito.png)");
            ui->label->setGeometry(x, ui->label->y(), ui->label->width(), ui->label->height());
            x += 5;
            if(ui->label->x() >= (ui->widget->geometry().width()-ui->label->geometry().width()))
            {
                band = false;
            }
        }
        if(!band)
        {
            ui->label->setStyleSheet("background-image: url(:/new/prefix1/pez_invertido.png)");
          //  ui->label->setStyleSheet("background-image: url(:/new/prefix1/pez_moradito_invertido.png)");

            ui->label->setGeometry(x, y, ui->label->width(), ui->label->height());
            x -= 5;
            y -= 5;
            if(ui->label->x() <= 0 ||
               ui->label->y() <= 0 )  {
                band = true;
            }
        }

        if(ui->label->geometry().y() < (ui->widget->geometry().height() - ui->label->height()) && band)
        {
            ui->label->setStyleSheet("background-image: url(:/new/prefix1/pez.png)");
        //    ui->label->setStyleSheet("background-image: url(:/new/prefix1/pez_moradito.png)");
            ui->label->setGeometry(ui->label->x(), y, ui->label->width(), ui->label->height());
            y += 5;
            if(ui->label->y() >= (ui->widget->geometry().height()-ui->label->geometry().height()))
            {
                band = false;

            }
        }
}

void MainWindow::moverEtiquetaXY()
{
    static int x = 0;
    int y = 0;
    static bool band = true;

    ui->label->setStyleSheet("background-image: url(:/new/prefix1/pez.png)");
    if(ui->label->geometry().x() < (ui->widget->geometry().width() - ui->label->width()) && band)
    {
        ui->label->setGeometry(x, ui->label->y(), ui->label->width(), ui->label->height());
        x+=10;
        if(ui->label->x() >= (ui->widget->geometry().width()-ui->label->geometry().width()))
        {
            band = false;
        }
    }

    //MAÑANA JUEVES REVISION: MOVIMIENTOS VERTICALES Y
    //AVANCE DE MOVIMIENTOS ALEATORIOS, VALIDANDO LOS EXTREMOS DE LA PECERA
    //NO DEBE DEJAR DE MOSTRARSE EL 0 LOS PECES
    if(!band)
    {
        x -= 10;
        ui->label->setGeometry(x, y, ui->label->width(), ui->label->height());
        if( x == 0)
            band = true;
    }
}
void MainWindow::on_moverEtiquetaBase_clicked()
{
    moverEtiqueta();
}

void MainWindow::on_pushButton_released()
{

}
