#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtGui>
#include <QKeyEvent>
#include <QTimer>

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

    void escalarFijo(int sx, int sy, int pfx, int pfy);

    void rotar(double angulo_grados);

    void rotarSentidoHorario(double angulo_grados);

    void rotarPuntoPivote(double angulo_grados, int xr, int yr);

    void reflexionEjeX();

    void reflexionEjeY();

    void reflexionEjeCoordenado();

    void reflexionRectaYIgualX();

    void reflexionRectaYIgualMenosX();

    void keyPressEvent(QKeyEvent *evento) override;

private slots:
    void on_pushButton_clicked(); // Dibujar Normal, Y HACIA ABAJO

    void on_pushButton_2_clicked(); // DIBUJO MAPEADO, Y HACIA ARRIBA

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_spinBox_5_valueChanged(int arg1);

    void on_spinBox_6_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_pushButton_15_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_11_clicked();

// ANIMACION
    void rotarAnimacion1();

    void rotarAnimacion2();

    void rotarAnimacion3(); // INICIAR TIMER 3

    void rotarAnimacion4(); // INICIAR TIMER 4

    void on_pushButton_14_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

private:
    Ui::Widget *ui;

    float Fig[4][3]; // FIGURA ORIGINAL (DE INICIO SE USARA UN TRIANGULO)
    float FigAux[4][3]; // PARA RESPALDAR LOS PUNTOS ORIGINALES
                        // Y RESETEAR O RESTABLECERLOS CUANDO
                        // SE REQUIERA

    float Fig2[4][3]; // FIGURA ORIGINAL (DE INICIO SE USARA UN TRIANGULO)
    float FigAux2[4][3];


   // QPointF points[4];  // INTENTAR EL USO DE ESTE OBJETO

  //  int ancho;  // ESTABLECER EL ANCHO DE LA FORMA PARA EL DIBUJO
                // RESTAR EL WIDTH DE LA FORMA - EL WIDTH DEL WIDGET CONTENEDOR

    int altura;

    int centroX, centroY;

    int tX, tY;

    QTimer *timer1, *timer2, *timer3, *timer4;

    int angulo;
};
#endif // WIDGET_H
