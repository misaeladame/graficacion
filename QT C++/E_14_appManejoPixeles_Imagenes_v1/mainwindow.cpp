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

QImage MainWindow::rotarRGB(const QImage &in)
{
    //ASIGNAMOS EL TAMAÑO DE LA IMAGEN (in) Y SU FORMATO
    QImage out(in.size(), in.format());
    //RECORREMOS EL ARREGLO DE LA IMAGEN (PIXELES INDEPENDIENTES)
    for(int ren = 0; ren < in.height(); ren++ )
    {
        const QRgb *pixeles = reinterpret_cast<const QRgb*>(in.scanLine(ren));
        //MODIFICAR LOS PIXELES DE SALIDA -out-
        QRgb *PixelesSalida = reinterpret_cast<QRgb*>(out.scanLine(ren));
        for (int cols = 0; cols < in.width(); cols++ ) {
            int red = qRed(pixeles[cols]);
            int green = qGreen(pixeles[cols]);
            int blue = qBlue(pixeles[cols]);
            int alpha = qAlpha(pixeles[cols]);
            //PixelesSalida[cols] = qRgba(red, green, blue, alpha);

            // rotamos
           // PixelesSalida[cols] = qRgba(blue, red, blue, alpha);
          //  PixelesSalida[cols] = qRgba (green, blue, red, alpha);
          //  PixelesSalida[cols] = qRgba(red, 0, 0, alpha);

            // ELIMINAR UNO A UNO LOS COLORES BASICO (ROJO, VERDE, AZUL)

            // ESCALA DE GRISES
          //  PixelesSalida[cols] = qRgba(0, 0,0, alpha);

         //   PixelesSalida[cols] = qRgba(red, red,red, alpha);
         //   PixelesSalida[cols] = qRgba(green, green, green, alpha);


            // REPASAR Y TRABAJAR CON AND -&-, OR -|- Y XOR -^-
            // 1010
            //              xor
            // 1111
            //

            //APLICAR LOS OPERADORES LOGICOS O A NIVEL DE BIT
            //PixelesSalida[cols] = qRgba(red ^ 0x00ffff, green ^ 0xff00ff, blue ^ 0x00ffff, alpha);
            PixelesSalida[cols] = qRgba(red & 0x00ffff, green & 0xff00ff, blue & 0x00ffff, alpha);
        }
    }
    return out;
}



void MainWindow::on_pushButton_clicked()
{
    QImage imagen(":/new/prefix1/paisaje.jpg");
    imagen = rotarRGB(imagen);
    ui->label_2->setPixmap(QPixmap::fromImage(imagen));
    ui->label_2->setScaledContents(true);

    imagen = rotarRGB(imagen);
    ui->label_3->setPixmap(QPixmap::fromImage(imagen));
    ui->label_3->setScaledContents(true);


    imagen = rotarRGB(imagen);
    ui->label_4->setPixmap(QPixmap::fromImage(imagen));
    ui->label_4->setScaledContents(true);


}
