#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>
#include "graphics.h"
#include <math.h>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
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
    Canvas->end();

}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    ui->lineEdit->setText((QString::number(event->pos().x())));
    ui->lineEdit_2->setText((QString::number(event->pos().y())));
}

void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    ui->lineEdit_3->setText(QString::number(event->pos().x()));
    ui->lineEdit_4->setText(QString::number(event->pos().y()));
    on_pushButton_clicked();
}

void Dialog::mouseDoubleClickEvent(QMouseEvent *event)
{

}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{

}

// COLOR DIALOG
void Dialog::on_pushButton_2_clicked()
{
    QColor color_seleccionado = QColorDialog::getColor(Qt::white, this, "Selecciona tu Color");
    if(color_seleccionado.isValid()) {
        color = color_seleccionado;
    }
}
