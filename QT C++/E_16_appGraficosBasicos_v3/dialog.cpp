#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>
#include "graphics.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;

    xc = 0;
    yc = 0;

    xc_p = 0;
    yc_p = 0;

    radio = 0;
    radio_p = 0;
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    x1 = ui->lineEdit->text().toInt();
    y1 = ui->lineEdit_2->text().toInt();

    x2 = ui->lineEdit_3->text().toInt();
    y2 = ui->lineEdit_4->text().toInt();
    update();//INVOCA AUTOMATICAMENTE A paintEvent
}

void Dialog::paintEvent(QPaintEvent *e)
{//ALGORITMO LINEADDA
    Q_UNUSED(e)

    QPainter *Canvas = new QPainter(this);

    graficos = new graphics(); //CONSTRUIMOS NUESTRO OBJETO GRAFICOS

    graficos->lineaDDA(x1, y1, x2, y2, Canvas, color);

    graficos->circuloPitagoras(xc, yc, radio, Canvas);

    graficos->circuloPolares(xc_p, yc_p, radio_p, Canvas);

    graficos->circulo(xc_c, yc_c, radio_c, Canvas);

    Canvas->end();

}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    ui->lineEdit->setText((QString::number(event->pos().x())));
    ui->lineEdit_2->setText((QString::number(event->pos().y())));
}

/*
void Dialog::mouseReleaseEvent(QMouseEvent *event)
{

}

void Dialog::mouseDoubleClickEvent(QMouseEvent *event)
{

}
*/

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    ui->lineEdit_3->setText(QString::number(event->pos().x()));
    ui->lineEdit_4->setText(QString::number(event->pos().y()));
    on_pushButton_clicked();
}

// COLOR DIALOG
void Dialog::on_pushButton_2_clicked()
{
    QColor color_seleccionado = QColorDialog::getColor(Qt::white, this, "Selecciona tu Color");
    if(color_seleccionado.isValid()) {
        color = color_seleccionado;
    }
}

void Dialog::on_pushButton_3_clicked()
{
    xc = ui->lineEdit_5->text().toInt();
    yc = ui->lineEdit_6->text().toInt();

    radio = ui->lineEdit_7->text().toInt();

    update();//INVOCA AUTOMATICAMENTE A paintEvent
}

void Dialog::on_pushButton_4_clicked()
{
    xc_p = ui->lineEdit_5->text().toInt();
    yc_p = ui->lineEdit_6->text().toInt();

    radio_p = ui->lineEdit_7->text().toInt();

    update();//INVOCA AUTOMATICAMENTE A paintEvent
}

void Dialog::on_pushButton_5_clicked()
{
    xc_c = ui->lineEdit_5->text().toInt();
    yc_c = ui->lineEdit_6->text().toInt();

    radio_c = ui->lineEdit_7->text().toInt();

    update();//INVOCA AUTOMATICAMENTE A paintEvent
}
