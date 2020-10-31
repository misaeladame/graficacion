#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "graficos.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dragon = arabesco = curvaHenon = malthus1 = malthus2 = mandelbrot = false;
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

    Canvas = new QPainter(this);

    graficos = new class graficos(); //CONSTRUIMOS NUESTRO OBJETO GRAFICOS

    if (dragon)
        graficos->dragon(Canvas, color);
    else if (arabesco)
        graficos->dragonArabesco(Canvas, color);
    else if (curvaHenon)
        graficos->curvaHenon(Canvas, color);
    else if (malthus1)
        graficos->malthus1(Canvas, color);
    else if (malthus2)
        graficos->malthus2(Canvas, color);
    else if (mandelbrot)
        graficos->mandelbrot(Canvas, color);

    Canvas->end();
}


void MainWindow::on_pushButton_2_clicked()
{
    arabesco = curvaHenon = malthus1 = malthus2 = mandelbrot = false;
    dragon = true;
    update();

}

void MainWindow::on_pushButton_3_clicked()
{
    dragon = curvaHenon = malthus1 = malthus2 = mandelbrot = false;
    arabesco = true;
    update();
}

void MainWindow::on_pushButton_4_clicked()
{
    dragon = arabesco = malthus1 = malthus2 = mandelbrot = false;
    curvaHenon = true;
    update();
}

void MainWindow::on_pushButton_5_clicked()
{
    dragon = arabesco = curvaHenon = malthus2 = mandelbrot = false;
    malthus1 = true;
    update();

}

void MainWindow::on_pushButton_6_clicked()
{
    dragon = arabesco = curvaHenon = malthus1 = mandelbrot = false;
    malthus2 = true;
    update();
}

void MainWindow::on_pushButton_7_clicked()
{
    dragon = arabesco = curvaHenon = malthus1 = malthus2 = false;
    mandelbrot = true;
    update();
}

void MainWindow::on_pushButton_8_clicked()
{
    QColor color_seleccionado = QColorDialog::getColor(Qt::white, this, "Selecciona tu Color");
    if(color_seleccionado.isValid())
        color = color_seleccionado;
}
