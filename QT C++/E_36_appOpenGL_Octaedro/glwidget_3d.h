#ifndef GLWIDGET_3D_H
#define GLWIDGET_3D_H

//Importar librerías
#include <QObject>
#include <QGLWidget>

#include <QtOpenGL>
#include <QtWidgets>

class glwidget_3d : public QGLWidget
{
    Q_OBJECT
public:
    explicit glwidget_3d(QWidget *parent = nullptr);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    
    QSize miniumSizeHint() const;
    QSize sizeHint() const override;
    
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override; 

    GLfloat posicionLuz[4];
    
signals:
    // APLICAR CON LOS MOVIMIENTOS DEL MOUSE
    void RotacionXChanged(int angulo);
    void RotacionYChanged(int angulo);
    void RotacionZChanged(int angulo);

public slots:
    
    void sRotacionX(int angulo);
    void sRotacionY(int angulo);
    void sRotacionZ(int angulo);

    void sLuzX(double p_lx);
    void sLuzY(double p_ly);
    void sLuzZ(double p_lz);

    void sColorRojo(int r);
    void sColorVerde(int v);
    void sColorAzul(int a);

private:

    void dibujar();
    int rotarX;
    int rotarY;
    int rotarZ;

    float posicion_lx;
    float posicion_ly;
    float posicion_lz;

    int rojo;
    int verde;
    int azul;



    QPoint ultimaPos; //tiene su X y Y

};

#endif // GLWIDGET_3D_H
