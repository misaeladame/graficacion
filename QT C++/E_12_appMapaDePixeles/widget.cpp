#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap imagen("C:\\Users\\terry\\Desktop\\pez.png");

    ui->label->setPixmap(imagen);
}
// JUEVES 12 SUBIR PRUEBA DE ESCRITORIO
// DE LOS MOVIMIENTOS ALEATORIOS
// DOMINGO 15/ MARZO
// PROYECTO ANIMACION CON LA PECERA
// LUNES 16/ MARZO
// PROYECTO ANIMACION LIBRE

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{

}
