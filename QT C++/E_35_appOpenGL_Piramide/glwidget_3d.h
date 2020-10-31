#ifndef GLWIDGET_3D_H
#define GLWIDGET_3D_H

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
    
signals:
    // APLICAR CON LOS MOVIMIENTOS DEL MOUSE
    void RotacionXChanged(int angulo);
    void RotacionYChanged(int angulo);
    void RotacionZChanged(int angulo);

public slots:
    
    void sRotacionX(int angulo);
    void sRotacionY(int angulo);
    void sRotacionZ(int angulo);

private:

    void dibujar();
    int rotarX;
    int rotarY;
    int rotarZ;

    QPoint ultimaPos; //tiene su X y Y

};

#endif // GLWIDGET_3D_H
