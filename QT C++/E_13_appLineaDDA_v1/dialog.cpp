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
    Q_UNUSED(e);
    QPainter *Canvas = new QPainter(this);

 /* int pasos;// steps, cantidad de pixeles a dibujar
    int dx = x2 - x1;
    int dy = y2 - y1;
    float x_inc, y_inc, x = x1, y = y1;

    if(abs(dx) > abs(dy))
        pasos = abs(dx);
    else
        pasos = abs(dy);

    // aplicar en ambos el cast

    x_inc = float(dx)/pasos;
    y_inc = float(dy)/(float)pasos;
    // Primer punto de la línea

    Canvas->setPen(QColor(0,0,200));//grand()%155+100));
    //dibujamos el

    // canvas->drawPoint(floor(x+.5), floor(y+0.5));
    //floor(9.1) = 9,   floor(9.9) = 9
    //ceil(9.1) = 10,  ceil(9.9) = 10
        //implementar qround(5,5) =
    Canvas->drawPoint(round(x), round(y));

    for(int k = 0; k<= pasos; k++)
    {
        x = x + x_inc;
        y = y + y_inc;
        Canvas->drawPoint(round(x), qRound(y));
    } */

    // Canvas->end();

    // UTILIZANDO EL METODO PARA TRAZAR LA LINEA
   // lineaDDA(x1, y1, x2, y2, Canvas);
   // Canvas->end();

    //UTILIZANDO LA CLASE GRAFICOS
    graphics graficos;
    QColor color = QColor(0, 200, 125);
    graficos.lineaDDA(x1, y1, x2, y2, Canvas, color);
    Canvas->end();

}

void Dialog::lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas)
{
    int pasos;// steps, cantidad de pixeles a dibujar
        int dx = x2 - x1;
        int dy = y2 - y1;
        float x_inc, y_inc, x = x1, y = y1;

        if(abs(dx) > abs(dy))
            pasos = abs(dx);
        else
            pasos = abs(dy);

        // aplicar en ambos el cast

        x_inc = float(dx)/pasos;
        y_inc = float(dy)/(float)pasos;
        // Primer punto de la línea

        canvas->setPen(QColor(0,0,200));//grand()%155+100));
        //dibujamos el

        // canvas->drawPoint(floor(x+.5), floor(y+0.5));
        //floor(9.1) = 9,   floor(9.9) = 9
        //ceil(9.1) = 10,  ceil(9.9) = 10
            //implementar qround(5,5) =
        canvas->drawPoint(round(x), round(y));

        for(int k = 0; k<= pasos; k++)
        {
            x = x + x_inc;
            y = y + y_inc;
            canvas->drawPoint(round(x), qRound(y));
        }
}
