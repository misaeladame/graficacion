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


void MainWindow::on_pushButton_clicked()
{
    close(); //this->close();
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
    dragon();
}

void MainWindow::dragon()
{
    QPainter Canvas (this); //QPainter *Canvas;
    int i;
    Paso = 4096;
    signo = -1;
    EjeX[1] = Canvas.window().width()/4;
    EjeX[4097] = 3 * Canvas.window().width()/4;
    EjeY[1] = EjeY[4097] = Canvas.window().height()/2;

    Canvas.setPen(QColor(50,50,200));
    QFont fuente = Canvas.font();
    fuente.setPointSize(fuente.pointSize() * 2);
    //Canvas.setFont(fuente);
    Canvas.setFont(QFont("ROCKWELL", 22));
    Canvas.drawText(5, 25, "CURVA FRACTAL DEL DRAGON");
    //LINEA HORIZONTAL
    //APLICAR LA LINEA DDA
    Canvas.setPen(QColor(255, 255, 255));
    Canvas.drawLine(EjeX[1],EjeY[1], EjeX[4097], EjeY[4097]);
    for( i = 1; i <= 11; i++)
    {
        generarDragon(&Canvas); //generarDragon(Canvas);
        Paso /= 2; // Paso = Paso / 2;
    }
    // REALIZAR UNA PRUEBA DE ESCRITORIO
    // A ESTA APP, MINIMO 4 CICLOS
    // MOSTRANDO EN PAPEL SU COMPORTAMIENTO
    // TANTO EN LAS VARIABLES COMO DE SU SALIDA PARA
    // MAÑANA INICIANDO LA CLASE,
    // LA LISTA SERA CON LA PUBLICACION DE SU PRUEBA

    // OPERADOR . ES PARA ACCESO A METODOS ESTATICOS
    // OPERADOR -> ES PARA ACCESO A METODOS DINAMICOS
}

void MainWindow::generarDragon(QPainter *Canvas)
{
    int j, dx, dy;
    j = Paso / 2;
    Canvas->setPen(QColor(0, 0, qrand()%155+100));//qrand()%

                             // signo *= -1;
    for(int i = 1; i <= 4096; i += Paso)
    {
        dx = EjeX[Paso+i] - EjeX[i];
        dy = EjeY[Paso+i] - EjeY[i];

        signo *= -1;
        EjeX[i + j] = EjeX[i] + ( dx + ( dy * signo)) / 2;
        EjeY[i + j] = EjeY[i] + ( dy - ( dx * signo)) / 2;
        //USAR LA LINEA DDA
        Canvas->drawLine(EjeX[i], EjeY[i], EjeX[i+j], EjeY[i+j] );
        Canvas->drawLine(EjeX[i+j], EjeY[i+j], EjeX[i+Paso], EjeY[i+Paso]);
    }
}
