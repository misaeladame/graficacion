#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtGui>

#include "mapeo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

//MACRO DE C++
#define radianes(g) ((double)(g) * M_PI / 180.0)
//CADA VERTICE DEL CUBO UTILIZA LA SIGUIENTE ESTRUCTURA
struct Puntos_3D
{
    int x, y, z;
    bool opcion;  //PARA MOVERSE O TRAZAR LINEA
};



class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *evt);
    void asignarCubo();
    void proyeccionCubo();
    void dibujarCubo();
    void inicializaPuerto();

    void lineto_3d(int x, int y, int z, float alpha, float phi, int i);
    void moveto_3d(int x, int y, int z, float alpha, float phi, int i);

    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_dial_sliderMoved(int position);

    void on_dial_2_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_checkBox_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_7_valueChanged(int arg1);

    void on_pushButton_7_clicked();

    void animacion();

    void on_pushButton_8_clicked();

private:
    Ui::Widget *ui;

    QPainter *canvas;
    QPointF points[16]; //16 MOVIMIENTOS PARA DIBUJAR EL CUBO
    Puntos_3D *cubo;
    Mapeo mapeo;
    int L, M;
    int ancho;

    float alpha, phi;



    //TRASLACION
    int tX, tY, tZ;

    //CENTRO DE LAS CARAS DEL CUBO
    int xC, yC, zC;

    //ROTACION
    bool rX, rY, rZ;
    int anguloX, anguloY, anguloZ;


    QTimer *timer;

};
#endif // WIDGET_H
