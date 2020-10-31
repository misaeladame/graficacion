#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString fileName;
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage MainWindow::rotarR(const QImage &in)
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
            int alpha = qAlpha(pixeles[cols]);

            PixelesSalida[cols] = qRgba(red, 0, 0, alpha);

        }
    }
    return out;
}

QImage MainWindow::rotarR_AND(int valor_rojo, const QImage &in)
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
            int alpha = qAlpha(pixeles[cols]);
            PixelesSalida[cols] = qRgba(red & valor_rojo, 0, 0, alpha);
        }
    }
    return out;
}

QImage MainWindow::rotarR_OR(int valor_rojo, const QImage &in)
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
            int alpha = qAlpha(pixeles[cols]);
            PixelesSalida[cols] = qRgba(red | valor_rojo, 0, 0, alpha);
        }
    }
    return out;
}

QImage MainWindow::rotarR_XOR(int valor_rojo, const QImage &in)
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
            int alpha = qAlpha(pixeles[cols]);
            PixelesSalida[cols] = qRgba(red ^ valor_rojo, 0, 0, alpha);
        }
    }
    return out;
}

QImage MainWindow::rotarG(const QImage &in)
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
            int green = qGreen(pixeles[cols]);
            int alpha = qAlpha(pixeles[cols]);
            PixelesSalida[cols] = qRgba(0, green, 0, alpha);
        }
    }
    return out;
}

QImage MainWindow::rotarG_AND(int valor_verde, const QImage &in)
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
            int green = qGreen(pixeles[cols]);
            int alpha = qAlpha(pixeles[cols]);
            PixelesSalida[cols] = qRgba(0, green & valor_verde, 0, alpha);
        }
    }
    return out;
}

QImage MainWindow::rotarG_OR(int valor_verde, const QImage &in)
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
            int green = qGreen(pixeles[cols]);
            int alpha = qAlpha(pixeles[cols]);
            PixelesSalida[cols] = qRgba(0, green | valor_verde, 0, alpha);
        }
    }
    return out;
}

QImage MainWindow::rotarG_XOR(int valor_verde, const QImage &in)
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
            int green = qGreen(pixeles[cols]);
            int alpha = qAlpha(pixeles[cols]);
            PixelesSalida[cols] = qRgba(0, green ^ valor_verde, 0, alpha);
        }
    }
    return out;
}

QImage MainWindow::rotarB(const QImage &in)
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
            int blue = qBlue(pixeles[cols]);
            int alpha = qAlpha(pixeles[cols]);

            PixelesSalida[cols] = qRgba(0, 0, blue, alpha);
        }
    }
    return out;
}

QImage MainWindow::rotarB_AND(int valor_azul, const QImage &in)
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
            int blue = qBlue(pixeles[cols]);
            int alpha = qAlpha(pixeles[cols]);

            PixelesSalida[cols] = qRgba(0, 0, blue & valor_azul, alpha);
        }
    }
    return out;
}

QImage MainWindow::rotarB_OR(int valor_azul, const QImage &in)
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
            int blue = qBlue(pixeles[cols]);
            int alpha = qAlpha(pixeles[cols]);

            PixelesSalida[cols] = qRgba(0, 0, blue | valor_azul, alpha);
        }
    }
    return out;
}

QImage MainWindow::rotarB_XOR(int valor_azul, const QImage &in)
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
            int blue = qBlue(pixeles[cols]);
            int alpha = qAlpha(pixeles[cols]);

            PixelesSalida[cols] = qRgba(0, 0, blue ^ valor_azul, alpha);
        }
    }
    return out;
}

void MainWindow::on_pushButton_4_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp)"));

    QImage imagen(fileName);
    QImage imagen2(fileName);
    QImage imagen3(fileName);
    ui->label->setPixmap(QPixmap::fromImage(imagen));
    ui->label->setScaledContents(true);
    ui->label->setStyleSheet("border: 0;");

    imagen = rotarR(imagen);
    ui->label_2->setPixmap(QPixmap::fromImage(imagen));
    ui->label_2->setScaledContents(true);

    imagen2 = rotarG(imagen2);
    ui->label_3->setPixmap(QPixmap::fromImage(imagen2));
    ui->label_3->setScaledContents(true);

    imagen3 = rotarB(imagen3);
    ui->label_4->setPixmap(QPixmap::fromImage(imagen3));
    ui->label_4->setScaledContents(true);


}

void MainWindow::on_pushButton_8_clicked()
{
    QImage imagen(fileName);
    imagen = rotarG(imagen);
    ui->label_3->setPixmap(QPixmap::fromImage(imagen));
    ui->label_3->setScaledContents(true);
}


void MainWindow::on_pushButton_clicked()
{
    int valor_verde = ui->horizontalSlider->value();
    QImage imagen (fileName);
    imagen = rotarG_AND( valor_verde ,imagen);
    ui->label_3->setPixmap(QPixmap::fromImage(imagen));
    ui->label_3->setScaledContents(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    int valor_verde = ui->horizontalSlider->value();
    QImage imagen (fileName);
    imagen = rotarG_OR( valor_verde ,imagen);
    ui->label_3->setPixmap(QPixmap::fromImage(imagen));
    ui->label_3->setScaledContents(true);
}

void MainWindow::on_pushButton_3_clicked()
{
    int valor_verde = ui->horizontalSlider->value();
    QImage imagen (fileName);
    imagen = rotarG_XOR( valor_verde ,imagen);
    ui->label_3->setPixmap(QPixmap::fromImage(imagen));
    ui->label_3->setScaledContents(true);
}

void MainWindow::on_pushButton_10_clicked()
{
    QImage imagen(fileName);
    imagen = rotarR(imagen);
    ui->label_2->setPixmap(QPixmap::fromImage(imagen));
    ui->label_2->setScaledContents(true);
}

void MainWindow::on_pushButton_11_clicked()
{
    int valor_rojo = ui->horizontalSlider_3->value();
    QImage imagen (fileName);
    imagen = rotarR_AND( valor_rojo ,imagen);
    ui->label_2->setPixmap(QPixmap::fromImage(imagen));
    ui->label_2->setScaledContents(true);
}

void MainWindow::on_pushButton_12_clicked()
{
    int valor_rojo = ui->horizontalSlider_3->value();
    QImage imagen (fileName);
    imagen = rotarR_OR( valor_rojo ,imagen);
    ui->label_2->setPixmap(QPixmap::fromImage(imagen));
    ui->label_2->setScaledContents(true);
}

void MainWindow::on_pushButton_13_clicked()
{
    int valor_rojo = ui->horizontalSlider_3->value();
    QImage imagen (fileName);
    imagen = rotarR_XOR( valor_rojo ,imagen);
    ui->label_2->setPixmap(QPixmap::fromImage(imagen));
    ui->label_2->setScaledContents(true);
}

void MainWindow::on_pushButton_9_clicked()
{
    QImage imagen(fileName);
    imagen = rotarB(imagen);
    ui->label_4->setPixmap(QPixmap::fromImage(imagen));
    ui->label_4->setScaledContents(true);
}

void MainWindow::on_pushButton_5_clicked()
{
    int valor_azul = ui->horizontalSlider_2->value();
    QImage imagen (fileName);
    imagen = rotarB_AND( valor_azul ,imagen);
    ui->label_4->setPixmap(QPixmap::fromImage(imagen));
    ui->label_4->setScaledContents(true);
}

void MainWindow::on_pushButton_6_clicked()
{
    int valor_azul = ui->horizontalSlider_2->value();
    QImage imagen (fileName);
    imagen = rotarB_OR( valor_azul ,imagen);
    ui->label_4->setPixmap(QPixmap::fromImage(imagen));
    ui->label_4->setScaledContents(true);
}

void MainWindow::on_pushButton_7_clicked()
{
    int valor_azul = ui->horizontalSlider_2->value();
    QImage imagen (fileName);
    imagen = rotarB_XOR( valor_azul ,imagen);
    ui->label_4->setPixmap(QPixmap::fromImage(imagen));
    ui->label_4->setScaledContents(true);
}
