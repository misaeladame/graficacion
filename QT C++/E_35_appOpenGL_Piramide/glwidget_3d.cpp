#include "glwidget_3d.h"


glwidget_3d::glwidget_3d(QWidget *parent) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    rotarX = 0;
    rotarY = 0;
    rotarZ = 0;
}

void glwidget_3d::initializeGL()
{
    // DOCUMENTAR
    qglClearColor(QColor(255, 100, 100));  //Qt::blue
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    static GLfloat posicionLuz[4] = {0, 0, 10, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, posicionLuz);


}

void glwidget_3d::paintGL()
{// DOCUMENTAR
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0, 0, -10);
    glRotatef(rotarX /* / 16 */, 1.0, 0.0, 0.0);
    glRotatef(rotarY /* / 16 */, 0.0, 1.0, 0.0);
    glRotatef(rotarZ /* / 16 */, 0.0, 0.0, 1.0);
    dibujar();
}

void glwidget_3d::resizeGL(int w, int h)
{
    int lado = qMin(w, h);
    // establecer el ASPECT RATIO o RAZON DE ASPECTO
    glViewport((w-lado)/2, (h - lado)/2, lado, lado);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

#ifdef QT_OPENGL_ES_1
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);

}

QSize glwidget_3d::miniumSizeHint() const
{
    return QSize(50, 50);
}

QSize glwidget_3d::sizeHint() const
{
    return QSize(400, 400);
}

static void qNormalizaAngulo(int &angulo)
{
    while(angulo < 0)
        angulo = 0;     // += 360 * 16;
    while(angulo > 360)
        angulo = 360;     // -= 360 * 16;
}

void glwidget_3d::mousePressEvent(QMouseEvent *event)
{
    ultimaPos = event->pos();
}

void glwidget_3d::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - ultimaPos.x();
    int dy = event->y() - ultimaPos.y();
    if(event->buttons() & Qt::LeftButton)
    {
        sRotacionX(rotarX + 8 * dy);
        sRotacionY(rotarY + 8 * dx);
    }
    else if(event->buttons() & Qt::RightButton)
    {
        sRotacionX(rotarX + 8 * dy);
        sRotacionZ(rotarZ + 8 * dx);
    }

    ultimaPos = event->pos();
}

void glwidget_3d::sRotacionX(int angulo)
{
    qNormalizaAngulo(angulo);
    if(angulo != rotarX)
    {
        rotarX = angulo;
        emit RotacionXChanged(angulo);
        updateGL();
    }
}

void glwidget_3d::sRotacionY(int angulo)
{
    qNormalizaAngulo(angulo);
    if(angulo != rotarY)
    {
        rotarY = angulo;
        emit RotacionYChanged(angulo);
        updateGL();
    }
}

void glwidget_3d::sRotacionZ(int angulo)
{
    qNormalizaAngulo(angulo);
    if(angulo != rotarZ)
    {
        rotarZ = angulo;
        emit RotacionZChanged(angulo);
        updateGL();
    }
}

void glwidget_3d::dibujar()
{
    // DIBUJAR EN PAPEL Y SUBIR MAÑAMA EN DISCORD
    glBegin(GL_QUADS);
        glNormal3f(0, 0, -1);
        glVertex3f(-1.0, -1.0, 0);
        glVertex3f(-1.0, 1.0, 0);
        glVertex3f(1.0, 1.0, 0);
        glVertex3f(1.0, -1.0, 0);
    glEnd();

    // CARA 1
    glBegin(GL_TRIANGLES);
        glNormal3f(0, -1, 0.707f);
        glVertex3f(-1, -1, 0);
        glVertex3f(1, -1, 0);
        glVertex3f(0, 0, 1.2f);
    glEnd();

    // CARA 2
    glBegin(GL_TRIANGLES);
        glNormal3f(0, -1, 0.707f);
        glVertex3f(1, -1, 0);
        glVertex3f(1, 1, 0);
        glVertex3f(0, 0, 1.2f);
    glEnd();

    // CARA 3
    glBegin(GL_TRIANGLES);
        glNormal3f(0, 1, 0.707f);
        glVertex3f(1, 1, 0);
        glVertex3f(-1, 1, 0);
        glVertex3f(0, 0, 1.2f);
    glEnd();

    // CARA 4
    glBegin(GL_TRIANGLES);
        glNormal3f(-1.0, 0, 0.707f);
        glVertex3f(-1, 1, 0);
        glVertex3f(-1, -1, 0);
        glVertex3f(0, 0, 1.2f);
    glEnd();


}
