#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    alpha = 63.4;
    phi   = 30.0;

    tX = tY = tZ = 0;

    //ESTABLECER EL EJE DE GIRO
    // 1ero. CON RESPECTO A UN EJE PIVOTE
    // CONSIDERANDO EL CENTRO DEL CUBO
    // EN CADA UNO DE SUS EJES

    xC = 150;
    yC = 100;
    zC = 50;

    rX = rY = rZ = false;

    anguloX = anguloY = anguloZ = 0;

    timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT (animacion()));

    asignarCubo();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *evt)
{
    Q_UNUSED(evt)
    inicializaPuerto();
    proyeccionCubo();

}

void Widget::asignarCubo()
{
    Puntos_3D cuboBase[] = {{100,50,0,0},{200,50,0,1},{200,150,0,1},
                            {100,150,0,1},{100,50,0,1},{100,50,100,1},
                            {200,50,100,1},{200,150,100,1},{200,150,0,1},
                            {200,50,0,0},{200,50,100,1},{100,50,100,0},
                            {100,150,100,1},{100,150,0,1},{100,150,100,0},
                            {200,150,100,1}};

    cubo = new Puntos_3D[16];
    for(int i = 0; i < 16; i++)
        cubo[i] = cuboBase[i];
    inicializaPuerto();

    ancho = this->size().width() - ui->widget->size().width();



}

void Widget::proyeccionCubo()
{
    canvas = new QPainter(this);


    canvas->setPen(QPen(Qt::white,3));
    //LINEA HORIZONTAL, EJE X
    canvas->drawLine(0, size().height()-1, ancho,size().height()-1);
    //LINEA VERTICAL,  EJE Y
    canvas->drawLine(1,0,1,size().height());

    //DIBUJAR EL EJE Z
    int zx1 = 0;
    int zy1 = 0;
    int zx2 = ancho * cos(radianes(phi));
    int zy2 = ancho *  sin(radianes(phi));
    //MAPEAR LOS VALORES
    int x1,y1,x2,y2;
    mapeo.mapear(zx1,zy1,x1,y1,L,M);
    mapeo.mapear(zx2,zy2,x2,y2,L,M);
    //YA ESTA PROYECTADO Y MAPEADO
    //DIBUJAR EJE Z
    canvas->drawLine(x1,y1,x2,y2);

     //CALCULAR LA PROYECCION DEL CUBO
    int x, y, z;
    for(int i =0; i < 16; i++)
    {
        x = cubo[i].x;
        y = cubo[i].y;
        z = cubo[i].z;

        if(rX) {
            x = cubo[i].x;
            y = floor((yC+(cubo[i].y-yC)*cos(radianes(anguloX))+(cubo[i].z-zC)*sin(radianes(anguloX)))+0.5);
            z = floor((zC+(-(cubo[i].y-yC)*sin(radianes(anguloX)))+(cubo[i].z-zC)*cos(radianes(anguloX)))+0.5);
        } if( rY ) {
            y = cubo[i].y;
            x = floor((xC+(cubo[i].x-xC)*cos(radianes(anguloY))-(cubo[i].z-zC)*sin(radianes(anguloY)))+0.5);
            z = floor((zC+(cubo[i].x-xC)*sin(radianes(anguloY))+(cubo[i].z-zC)*cos(radianes(anguloY)))+0.5);
        } if (rZ) {
            z = cubo[i].z;
            x = floor((xC+(cubo[i].x-xC)*cos(radianes(anguloZ))-(cubo[i].y-yC)*sin(radianes(anguloZ)))+0.5);
            y = floor((yC+(cubo[i].x-xC)*sin(radianes(anguloZ))+(cubo[i].y-yC)*cos(radianes(anguloZ)))+0.5);
        }


        if(cubo[i].opcion)  //  0 = MOVETO, 1 = LINETO
           // lineto_3d(cubo[i].x+tX,cubo[i].y+tY,cubo[i].z+tZ,radianes(alpha),qDegreesToRadians(phi),i);
            lineto_3d(x+tX,y+tY,z+tZ,radianes(alpha),qDegreesToRadians(phi),i);

        else
    //        moveto_3d(cubo[i].x+tX,cubo[i].y+tY,cubo[i].z+tZ,radianes(alpha),qDegreesToRadians(phi),i);
            moveto_3d(x+tX,y+tY,z+tZ,radianes(alpha),qDegreesToRadians(phi),i);

    }

    canvas->setPen(QPen(QColor(255,100,0),3));
    dibujarCubo();
    canvas->end();
}

void Widget::dibujarCubo()
{
   for(int i = 0; i < 15; i++)
       canvas->drawLine(points[i].x(),points[i].y(), points[i+1].x(),points[i+1].y());
}

void Widget::inicializaPuerto()
{
    mapeo.ventana(0,0,size().width()-ancho,size().height());
    mapeo.puerto(0,0,size().width()-ancho,size().height());
    L = 0;
    M = size().height();

}

void Widget::lineto_3d(int x, int y, int z, float alpha, float phi, int i)
{
    int xp, yp;
    int longitud; // SEGEMENTO L DE LA PROYECCION
    float tanalpha;
    if((tanalpha = tan(alpha)) != 0)
        longitud = (int)(z/tanalpha);  //PARA NO DIVIR POR CERO
    else
        longitud = 0;
    xp = x + longitud * cos(phi);
    yp = y + longitud * sin(phi);

    //MAPEAR LOS VALORES PROYECTADOS
    int x1, y1;
    mapeo.mapear(xp,yp,x1,y1,L,M);
    points[i].setX(x1);
    points[i].setY(y1);

}
void Widget::moveto_3d(int x, int y, int z, float alpha, float phi, int i)
{
    int xp, yp;
    int longitud; // SEGEMENTO L DE LA PROYECCION
    float tanalpha;
    if((tanalpha = tan(alpha)) != 0)
        longitud = (int)(z/tanalpha);  //PARA NO DIVIR POR CERO
    else
        longitud = 0;
    xp = x + longitud * cos(phi);
    yp = y + longitud * sin(phi);

    //MAPEAR LOS VALORES PROYECTADOS
    int x1, y1;
    mapeo.mapear(xp,yp,x1,y1,L,M);
    points[i].setX(x1);
    points[i].setY(y1);


}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
        tX -= ui->spinBox_5->value();
    if(event->key() == Qt::Key_D)
        tX += ui->spinBox_5->value();
    if(event->key() == Qt::Key_W)
        tY += ui->spinBox_4->value();
    if(event->key() == Qt::Key_S)
        tY -= ui->spinBox_4->value();
    if(event->key() == Qt::Key_9)
        tZ += ui->spinBox_6->value();
    if(event->key() == Qt::Key_0)
        tZ -= ui->spinBox_6->value();

    if(event->key() == Qt::Key_X) {
        anguloX+=ui->spinBox_7->value();  rX = true; rY = false; rZ = false;
    }
    if(event->key() == Qt::Key_C) {
        anguloX-=ui->spinBox_7->value(); rX = true; rY = false; rZ = false;
    }
    if(event->key() == Qt::Key_Y) {
        anguloY+=ui->spinBox_8->value();  rX = false; rY = true; rZ = false;
    }
    if(event->key() == Qt::Key_T) {
        anguloY-=ui->spinBox_8->value(); rX = false; rY = true; rZ = false;
    }
    if(event->key() == Qt::Key_Z) {
        anguloZ+=ui->spinBox_9->value(); rX = false; rY = false; rZ = true;
    }
    if(event->key() == Qt::Key_B) {
        anguloZ-=ui->spinBox_9->value(); rX = false; rY = false; rZ = true;
    }


    repaint();
}

void Widget::on_dial_sliderMoved(int position)
{
   alpha = position;
   inicializaPuerto();
   update();
}

void Widget::on_dial_2_valueChanged(int value)
{
   this->phi = value;
   inicializaPuerto();
   repaint();
}

void Widget::on_pushButton_clicked()
{
    tX+=ui->spinBox_5->value();
    repaint();
}

void Widget::on_pushButton_2_clicked()
{
    tX-=ui->spinBox_5->value();
    repaint();
}

void Widget::on_pushButton_3_clicked()
{
    tY+=ui->spinBox_4->value();
    repaint();
}

void Widget::on_pushButton_4_clicked()
{
    tY-=ui->spinBox_4->value();
    repaint();
}

void Widget::on_pushButton_5_clicked()
{
    tZ+=ui->spinBox_6->value();
    update();
}

void Widget::on_pushButton_6_clicked()
{
    tZ-=ui->spinBox_6->value();
    update();
}

void Widget::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
        ui->widget->setEnabled(false);
    else
        ui->widget->setEnabled(true);
}

void Widget::on_spinBox_valueChanged(int valor)
{
    xC = valor;
    //inicializaPuerto();
    repaint();
}

void Widget::on_spinBox_2_valueChanged(int valor)
{
    yC = valor;
    //inicializaPuerto();
    repaint();
}

void Widget::on_spinBox_3_valueChanged(int valor)
{
    zC = valor;
    //inicializaPuerto();
    repaint();
}

void Widget::on_spinBox_7_valueChanged(int arg1)
{

}

void Widget::on_pushButton_7_clicked()
{
    timer->start(10);
    animacion();
    ui->pushButton_7->setEnabled(false);
}

void Widget::animacion()
{
    static int cont = 0;

    if ( cont <= 900 )
    {
        if (cont <= 180 ) {
            tX++;
            anguloX++; rX = true; rY = false; rZ = false;
        } else if (cont > 180 && cont <= 540) {
            tY++;
            anguloY++; rX = false; rY = true; rZ = false;
        } else if (cont > 540 && cont <= 900) {
            tZ--;
            anguloZ++; rX = false; rY = false; rZ = true;
        }
    }
    cont++;
    repaint();
}

void Widget::on_pushButton_8_clicked()
{
    timer->stop();

    alpha = 63.4;
    phi   = 30.0;

    tX = tY = tZ = 0;

    //ESTABLECER EL EJE DE GIRO
    // 1ero. CON RESPECTO A UN EJE PIVOTE
    // CONSIDERANDO EL CENTRO DEL CUBO
    // EN CADA UNO DE SUS EJES

    xC = ui->spinBox->value();
    yC = ui->spinBox_2->value();
    zC = ui->spinBox_3->value();

    rX = rY = rZ = false;

    anguloX = anguloY = anguloZ = 0;

    update();
}
