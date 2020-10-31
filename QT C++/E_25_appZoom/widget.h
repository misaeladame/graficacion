#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtGui>

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
    void dibujarFigura();
    void dibujarFiguraMapeada();

private slots:
    void on_pushButton_clicked(); // Dibujar Normal, Y HACIA ABAJO

    void on_pushButton_2_clicked(); // DIBUJO MAPEADO, Y HACIA ARRIBA

private:
    Ui::Widget *ui;

    float Fig[4][3]; // FIGURA ORIGINAL (DE INICIO SE USARA UN TRIANGULO)
    float FigAux[4][3]; // PARA RESPALDAR LOS PUNTOS ORIGINALES
                        // Y RESETEAR O RESTABLECERLOS CUANDO
                        // SE REQUIERA

    QPointF points[4];

    int ancho;  // ESTABLECER EL ANCHO DE LA FORMA PARA EL DIBUJO
                // RESTAR EL WIDTH DE LA FORMA - EL WIDTH DEL WIDGET CONTENEDOR

    int centroX, centroY;

    bool dibujoOrientacionNormal; // Y hacia abajo
    bool dibujoMapeado; // Y hacia arriba

    int zoom;
};
#endif // WIDGET_H
