#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>
#include "graphics.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    linea = circuloPitagoras = circuloA = esp1 = esp2 = false;
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    x1 = ui->spinBox_4->value();
    y1 = ui->spinBox_6->value();

    x2 = ui->spinBox_5->value();
    y2 = ui->spinBox_7->value();

    linea = true;
    update();//INVOCA AUTOMATICAMENTE A paintEvent
}

void Dialog::paintEvent(QPaintEvent *e)
{//ALGORITMO LINEADDA
    Q_UNUSED(e)

    Canvas = new QPainter(this);

    graficos = new graphics(); //CONSTRUIMOS NUESTRO OBJETO GRAFICOS
    if (linea)
        graficos->lineaDDA(x1, y1, x2, y2, Canvas, color);
    else if (circuloPitagoras)
        graficos->circuloPitagoras(xc, yc, radio, Canvas, color);
    else if (circuloPolares)
        graficos->circuloPolares(xc, yc, radio, Canvas, color);
    else if (circuloA)
        graficos->circulo(xc, yc, radio, Canvas, color);
    else if (esp1)
        graficos->espiral1(radio_e, factor, Canvas, color);
    else if (esp2)
        graficos->espiral2(radio_e, th, Canvas, color);

    linea = circuloPitagoras = circuloPolares = circuloA = esp1 = esp2 = false;

    Canvas->end();

}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event)
    //X1
    ui->spinBox_4->setValue(event->pos().x());
    //Y1
    ui->spinBox_6->setValue(event->pos().y());

    //VALIDAR ENTRADA

    //ASIGNAR PARA EL DIBUJO DE LOS CIRCULOS : xc , yc
    ui->spinBox->setValue(event->pos().x());  // xc
    ui->spinBox_2->setValue(event->pos().y()); // yc
}

void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    // X2
    ui->spinBox_5->setValue(event->pos().x());
    // Y2
    ui->spinBox_7->setValue(event->pos().y());

    // RADIO                             Y2          -          Y1
    ui->spinBox_3->setValue(ui->spinBox_7->value() - ui->spinBox_6->value());

    // INVOCAMOS AL BOTON 1 QUE TRAZA LA LINEA DDA
    on_pushButton_clicked();
}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    //X2
    ui->spinBox_5->setValue(event->pos().x());
    //Y2
    ui->spinBox_7->setValue(event->pos().y());


  //  ui->lineEdit_3->setText(QString::number(event->pos().x()));
  //  ui->lineEdit_4->setText(QString::number(event->pos().y()));
    on_pushButton_clicked();

}

// COLOR DIALOG
void Dialog::on_pushButton_2_clicked()
{
    QColor color_seleccionado = QColorDialog::getColor(Qt::white, this, "Selecciona tu Color");
    if(color_seleccionado.isValid())
        color = color_seleccionado;    
}

void Dialog::on_pushButton_3_clicked()
{
    xc = ui->spinBox->value();//SOLAMENTE USAMOS SU VALOR
    yc = ui->spinBox_2->value();

    radio = ui->spinBox_3->value();

    circuloPitagoras = true;

    update();//INVOCA AUTOMATICAMENTE A paintEvent
}

void Dialog::on_pushButton_4_clicked()
{
    xc = ui->spinBox->value();//SOLAMENTE USAMOS SU VALOR
    yc = ui->spinBox_2->value();

    radio = ui->spinBox_3->value();

    circuloPolares = true;

    update();//INVOCA AUTOMATICAMENTE A paintEvent
}

void Dialog::on_pushButton_5_clicked()
{
    xc = ui->spinBox->value();//SOLAMENTE USAMOS SU VALOR
    yc = ui->spinBox_2->value();

    radio = ui->spinBox_3->value();

    circuloA = true;
    update();//INVOCA AUTOMATICAMENTE A paintEvent
}

// Espiral 1
void Dialog::on_pushButton_6_clicked()
{
    radio_e = ui->doubleSpinBox_3->value();
    factor = ui->doubleSpinBox->value();

    esp1 = true;
    update();
}

// Espiral 2
void Dialog::on_pushButton_7_clicked()
{
    radio_e = ui->doubleSpinBox_3->value();

    th = ui->doubleSpinBox_2->value();

    esp2 = true;
    update();
}

void Dialog::on_spinBox_3_valueChanged(int radio)
{
    if ( radio > (ui->spinBox_7->value() - ui->spinBox_6->value()) ) {
        ui->spinBox_3->setValue(ui->spinBox_7->value() - ui->spinBox_6->value());
    }
}

void Dialog::on_spinBox_6_valueChanged(int arg1)
{
    Q_UNUSED(arg1)
    ui->spinBox_3->setValue(ui->spinBox_7->value() - ui->spinBox_6->value());
}

void Dialog::on_spinBox_7_valueChanged(int arg1)
{
    Q_UNUSED(arg1)
    ui->spinBox_3->setValue(ui->spinBox_7->value() - ui->spinBox_6->value());
}
