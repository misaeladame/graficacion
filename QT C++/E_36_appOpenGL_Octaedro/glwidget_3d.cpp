#include "glwidget_3d.h"


glwidget_3d::glwidget_3d(QWidget *parent) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    // Se inicializa en 0 todas las variables declaradas en el .h
    rotarX = 0;
    rotarY = 0;
    rotarZ = 0;

    posicion_lx = 0;
    posicion_ly = 0;
    posicion_lz = 0;

    rojo = 0;
    verde = 0;
    azul = 0;
}


void glwidget_3d::initializeGL()
{
    /*
    Función de conveniencia para especificar el color de fondo en OpenGL. Llama a glClearColor
    (en modo RGBA) con el color c. Se aplica en el contexto GL widgets.

    Se usa un QColor que son valores de R G B de 0 a 255, en este caso se guardan  como variables
    porque se puede modificar en tiempo de ejecución.
    */
    qglClearColor(QColor(rojo, verde, azul));
    /*
    glEnable es para habilitar las capacidades de GL
    GL_DEPTH_TEST (prueba de profundidad) es una operación de procesamiento por muestra
    realizada después del (Fragment Shade) sombreador de fragmentos (y a veces antes).
    */
    glEnable(GL_DEPTH_TEST);
    /*
    glShadeModel seleccione sombreado plano o suave
    en este caso fue suave que es (GL_SMOOTH)

    El sombreado suave, el valor predeterminado, hace que los colores calculados de los
    vértices se interpolen a medida que la primitiva se rasteriza, generalmente asignando
    diferentes colores a cada fragmento de píxel resultante.
    */
    glShadeModel(GL_SMOOTH);

    /*
    El modelo de luz OpenGL supone que la luz que llega a su ojo desde la superficie del
    polígono llega por cuatro mecanismos diferentes:
    */
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    /*
    AMBIENTE: luz que proviene de todas las direcciones por igual y se dispersa en todas las
    direcciones por igual por los polígonos en su escena. Esto no es del todo cierto en el
    mundo real, pero es una buena primera aproximación a la luz que viene de manera bastante
    uniforme desde arriba y llega a una superficie rebotando en muchas otras superficies que
    también podrían ser uniformes.

    DIFUSO: luz que proviene de una fuente puntual particular (como el Sol) y golpea las
    superficies con una intensidad que depende de si están orientadas hacia la luz o lejos de ella.
    Sin embargo, una vez que la luz irradia desde la superficie, lo hace igualmente en todas las
    direcciones. Es la iluminación difusa la que mejor define la forma de los objetos 3D.

    ESPECULAR: al igual que con la iluminación difusa, la luz proviene de una fuente puntual,
    pero con la iluminación especular, se refleja más en la forma de un espejo donde la mayor
    parte de la luz rebota en una dirección particular definida por la forma de la superficie.
    La iluminación especular es lo que produce los reflejos brillantes y nos ayuda a distinguir
    entre superficies planas y opacas como el yeso y superficies brillantes como plásticos y
    metales pulidos.
    EMISIÓN - en este caso, la luz es realmente emitida por el polígono - igualmente en todas las direcciones
    */
    static GLfloat material_ambiente[] = {0.08f, 0.08f, 0.08f, 1.0};
    static GLfloat material_difusa[] = {0.2f, 0.2f, 0.7f, 1.0};
    static GLfloat material_specular[] = {0.3f, 0.3f, 0.9f, 1.0};

    static GLfloat luz_ambiente[] = {0.8f, 0.8f, 0.8f, 0.0};
    static GLfloat luz_difusa[] = {1.0, 1.0, 1.0, 0.0};
    static GLfloat luz_specular[] = {1.0, 1.0, 1.0, 0.0};
    /*
    Por defecto, la luz en OpenGL es blanca y proviene de la dirección Z. Probablemente puedas decir esto por la
    forma en que se ve el cubo. En OpenGL, y en la mayoría de los sistemas gráficos, las luces pueden estar
    en un punto en el espacio o en el infinito. Siempre usaremos un vector 4D para describir la posición de una luz.
    El vector tiene valores x, y, z y w. Si w es 1.0, estamos definiendo una luz en un punto en el espacio.
    Si w es 0.0, la luz está en el infinito.
    */
    static GLfloat luz_posicion[] = {1.0, 1.0, 1.0, 0.0};

    posicionLuz[0] =  posicion_lx;
    posicionLuz[1] =  posicion_ly;
    posicionLuz[2] =  posicion_lz;
    posicionLuz[3] =  1.0;

    /*
    La función glMaterialfv especifica parámetros de material para el modelo de iluminación.
    Son tres parámetros

    1.- La cara o caras que se están actualizando. Debe ser uno de los siguientes:
        GL_FRONT, GL_BACK o GL_FRONT y GL_BACK.
    2.- El parámetro material de la cara o caras que se actualizan.
        Pueden ser varias, en este caso se usan cuatro distintas:

        GL_AMBIENT
        El parámetro params contiene cuatro valores de punto flotante que especifican la reflectancia
        RGBA ambiental del material. Los valores enteros se asignan linealmente de manera que el valor
        representable más positivo se asigna a 1.0, y el valor representable más negativo se asigna a -1.0.
        Los valores de punto flotante se asignan directamente. No se fijan valores enteros ni de punto flotante.
        La reflectancia ambiental predeterminada para los materiales orientados hacia adelante y hacia atrás es
        (0.2, 0.2, 0.2, 1.0).

        GL_DIFFUSE
        El parámetro params contiene cuatro valores de punto flotante que especifican la reflectancia difusa RGBA del
        material. Los valores enteros se asignan linealmente de manera que el valor representable más positivo se
        asigna a 1.0, y el valor representable más negativo se asigna a -1.0. Los valores de punto flotante se asignan
        directamente. No se fijan valores enteros ni de punto flotante. La reflectancia difusa predeterminada para los
        materiales orientados hacia adelante y hacia atrás es (0.8, 0.8, 0.8, 1.0).

        GL_SPECULAR
        El parámetro params contiene cuatro valores de punto flotante que especifican la reflectancia RGBA especular
        del material. Los valores enteros se asignan linealmente de manera que el valor representable más positivo se asigna
        a 1.0, y el valor representable más negativo se asigna a -1.0. Los valores de punto flotante se asignan directamente.
        No se fijan valores enteros ni de punto flotante. La reflectancia especular predeterminada para los materiales
        orientados hacia adelante y hacia atrás es (0.0, 0.0, 0.0, 1.0).

        GL_SHININESS
        El parámetro param es un valor entero único que especifica el exponente especular RGBA del material. Los valores
        enteros se asignan directamente. Solo se aceptan valores en el rango [0, 128]. El exponente especular predeterminado
        para los materiales orientados hacia adelante y hacia atrás es 0.

    3.- El valor con el que se establecerá el parámetro GL_SHININESS.
    */
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, material_ambiente);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, material_difusa);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, material_specular);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.0f);

    glLightfv(GL_LIGHT0, GL_AMBIENT, luz_ambiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luz_difusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luz_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, luz_posicion);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, posicionLuz);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
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

void glwidget_3d::sLuzX(double p_lx)
{
    posicion_lx = float (p_lx);
    initializeGL();
    updateGL();
}

void glwidget_3d::sLuzY(double p_ly)
{
    posicion_ly = float (p_ly);
    initializeGL();
    updateGL();
}

void glwidget_3d::sLuzZ(double p_lz)
{
    posicion_lz = float (p_lz);
    initializeGL();
    updateGL();
}

void glwidget_3d::sColorRojo(int r)
{
    rojo = r;
    initializeGL();
    updateGL();
}

void glwidget_3d::sColorVerde(int v)
{
    rojo = v;
    initializeGL();
    updateGL();
}

void glwidget_3d::sColorAzul(int a)
{
    azul = a;
    initializeGL();
    updateGL();
}

void glwidget_3d::dibujar()
{
    // CUADRADO
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



    //cara 5
    glBegin(GL_TRIANGLES);
        glNormal3f(0, -1, -0.707f);
        glVertex3f(-1.0, -1.0, 0);
        glVertex3f(1.0, -1.0, 0);
        glVertex3f(0.0, 0.0, -1.2f);
    glEnd();

    //cara 6
    glBegin(GL_TRIANGLES);
        glNormal3f(1.0, 0, -0.707f);
        glVertex3f(1.0, -1.0, 0);
        glVertex3f(1.0, 1.0, 0);
        glVertex3f(0.0, 0.0, -1.2f);
    glEnd();

    //cara 7
    glBegin(GL_TRIANGLES);
        glNormal3f(0, 1, -0.707f);
        glVertex3f(1.0, 1.0, 0);
        glVertex3f(-1.0, 1.0, 0);
        glVertex3f(0.0, 0.0, -1.2f);
    glEnd();

    //cara 8
    glBegin(GL_TRIANGLES);
        glNormal3f(-1.0, 0, -0.707f);
        glVertex3f(-1.0, 1.0, 0);
        glVertex3f(-1.0, -1.0, 0);
        glVertex3f(0.0, 0.0, -1.2f);
    glEnd();


}
