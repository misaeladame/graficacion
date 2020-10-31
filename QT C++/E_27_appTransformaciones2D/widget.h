#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtGui>
#include <QKeyEvent>

#include "matrix.h"
#include "mapeo.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget() override;

    void paintEvent(QPaintEvent *event) override;
    void asignarFigura();
    void dibujarFigura(); // YA NO SE HA UTILIZADO

    //
    void dibujarFiguraMapeada();

    // TRANSFORMACIONES 2D
    void trasladar(int tx, int ty);

    void escalar(int sx, int sy);

    void keyPressEvent(QKeyEvent *evento) override;

private slots:
    void on_pushButton_clicked(); // Dibujar Normal, Y HACIA ABAJO

    void on_pushButton_2_clicked(); // DIBUJO MAPEADO, Y HACIA ARRIBA

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Widget *ui;

    float Fig[4][3]; // FIGURA ORIGINAL (DE INICIO SE USARA UN TRIANGULO)
    float FigAux[4][3]; // PARA RESPALDAR LOS PUNTOS ORIGINALES
                        // Y RESETEAR O RESTABLECERLOS CUANDO
                        // SE REQUIERA

   // QPointF points[4];  // INTENTAR EL USO DE ESTE OBJETO

    int ancho;  // ESTABLECER EL ANCHO DE LA FORMA PARA EL DIBUJO
                // RESTAR EL WIDTH DE LA FORMA - EL WIDTH DEL WIDGET CONTENEDOR

    int centroX, centroY;

    int tX, tY;

};
#endif // WIDGET_H
