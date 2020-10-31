#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    dibujoOrientacionNormal = dibujoMapeado = false;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    if(dibujoOrientacionNormal)
        dibujarFigura();
    else if(dibujoMapeado)
        dibujarFiguraMapeada();
}

void Widget::asignarFigura()
{


    // UTILIZAR COORDENADAS  PARA DIBUJAR EL TRIANGULO
    // POLIGONO BASICO ES EL TRIANGULO

             // X              Y               H
    /*
    Fig[0][0] = 10; Fig[0][1] = 10; Fig[0][2] = 1;
    Fig[1][0] = 30; Fig[1][1] = 10; Fig[1][2] = 1;
    Fig[2][0] = 20; Fig[2][1] = 30; Fig[2][2] = 1;
    */
    /*
     * USANDO UN ESPACIO DE 1000 X 1000
    Fig[0][0] = 0; Fig[0][1] = 0; Fig[0][2] = 1;
    Fig[1][0] = 1000; Fig[1][1] = 0; Fig[1][2] = 1;
    Fig[2][0] = 0; Fig[2][1] = 1000; Fig[2][2] = 1;
    */

    /*
    // USANDO UN ESPACIO DE 10 X 10
    Fig[0][0] = 0; Fig[0][1] = 0; Fig[0][2] = 1;
    Fig[1][0] = 1000; Fig[1][1] = 0; Fig[1][2] = 1;
    Fig[2][0] = 0; Fig[2][1] = 1000; Fig[2][2] = 1;
    */

    // USANDO UN ESPACIO DE 21.5 X 28
    Fig[0][0] = 0; Fig[0][1] = 0; Fig[0][2] = 1;
    Fig[1][0] = 22; Fig[1][1] = 0; Fig[1][2] = 1;
    Fig[2][0] = 0; Fig[2][1] = 28; Fig[2][2] = 1;

    // EN DIBUJO QUE REALICEMOS CON LINEAS (VAMOS A PROBAR AQUI LA LINEA DDA)
    // EL PUNTO DE CIERRE O PUNTO INICIAL DE LA FIGURA SE REQUIERE CUANDO
    // DIBUJEMOS UTILIZANDO LOS TIPOS QPOINT

    //Fig[3][0] = 10; Fig[3][1] = 10; Fig[3][2] = 1;

    Fig[3][0] = 10; Fig[3][1] = 10; Fig[3][2] = 1;

    // ESTE ES EL PUNTO INICIAL, PARA CERRAR LA FIGURA

    //    <<<<<

    // RESPALDAR LOS VALORES DEL POLIGONO
    for ( int r = 0; r < 4; r++)
        for ( int c = 0; c < 3; c++ )
            FigAux[r][c] = Fig[r][c];


    //SE REQUIERE ESTABLECER EL ORIGEN EN EL CENTRO
    //DEL AREA DE DIBUJO
    //RESTARL EL WIDTH DE LA FORMA - EL WIDTH DEL WIDGET CONTENEDOR DE LOS BOTONES}

    ancho = this->size().width() - ui->widget->size().width();

    //CENTRO DEL AREA DE DIBUJO
    centroX = ancho/2;
    centroY = this->size().height()/2;

    // UTILIZAR EL TIPO QPOINT PARA DIBUJAR CON DRAWPOLYGON

    points[0].setX(Fig[0][0]);
    points[0].setY(Fig[0][1]);

    points[1].setX(Fig[1][0]);
    points[1].setY(Fig[1][1]);

    points[2].setX(Fig[2][0]);
    points[2].setY(Fig[2][1]);

    points[3].setX(Fig[3][0]);
    points[3].setY(Fig[3][1]);


}

void Widget::dibujarFigura()
{
    QPainter *canvas = new QPainter(this);

    // DIBUJAR EJE COORDINADO
    // LINEA HORIZONTAL
    //canvas->drawLine(0, this->size().height()/2, ancho, size().height()/2);

    //LINEA VERTICAL
    //canvas->drawLine(ancho/2, 0, ancho/2, size().height());

    for(int i = 0; i < 3; i++)
        canvas->drawLine(centroX+Fig[i][0], centroY+Fig[i][1], centroX+Fig[i+1][0], centroY+Fig[i+1][1]);
                    // centroX y centroY desplazan o trasladan
                    // al centro de la pantalla

    canvas->drawPolyline(points, 4);
    canvas->end();
}

void Widget::dibujarFiguraMapeada()
{
    QPainter *canvas = new QPainter(this);

    //DIBUJAR EJE COORDENADO
    //LINEA HORIZONTAL
    //canvas->drawLine(0, this->size().height()/2, ancho, size().height()/2);
    // LINEA VERTICAL
    //canvas->drawLine(ancho/2, 0, ancho/2, size().height());

    Mapeo dibujo;

    //LA VENTANA ES EL AREA DEL MUNDO REAL


    //dibujo.ventana(ancho/2, 0, ancho, size().height()/2);
    //? TIENEN LA MISMA DIMENSION
    //dibujo.ventana(0, 0, ancho/2, size().height()/2);
    //dibujo.ventana(0, 0, 1000, 1000);
    //dibujo.ventana(0, 0, 10, 10);
    //dibujo.ventana(0, 0, 21.5, 28); //HOJA DE MAQUINA
    dibujo.ventana(0, 0, 22, 28); //HOJA DE MAQUINA

    //VALOR DE SX = 0.25
    //VALOR DE SY = 0.25

    //EL PUERTO DE VISION SE COLOCARA LA DIVISIOM
    //DEL EJE CARTESIANO EN EL RECTANGULO DE LA DERECHA

    // dibujo.puerto(ancho/2, 0, ancho, size().height()/2);

   // dibujo.puerto(0, 0, 250, 250);

    // Valores antiguos
    //canvas->drawRect(125, 125, 250, 250);
/*
    // MIS VALORES
    dibujo.puerto(0, 0, 200, 300);
    canvas->drawRect(150, 100, 200, 300);

    int L = 150;
    int M = 400; */

    // X_Inicial; Y_Inicial; X_Final; Y_Final;
    // RECTANGULO PARA DEFINIR EL PUERTO

    zoom = ui->spinBox->value();


    dibujo.puerto(150 - zoom, 100 - zoom, 350 + zoom, 400 + zoom);
    canvas->drawRect(150 - zoom, 100 - zoom, 200 + (zoom * 2), 300 + (zoom * 2) );

    int L = 0;
    int M = 500; // ES LA SUMA DE LOS VALORES PARA YPVMIN + YPVMAX

    // PROYECTO ZOOM
    // UTILZAR EL MOVIMIENTO DE LAS FLECHAS ARRIBA - ABAJO
    // PARA ASIGNAR LA NUEVA ESQUINA SUPERIOR IZQUIERDA E INFERIOR DERECHA
    // TAMBIEN HAY QUE REDIBUJAR CON NUEVOS VALORES EL RECTANGULO

    // ESTABLACER EL ORIGEN EN EL PUERTO, SE USABA EN EL EJEMPLO
    // ESTE SE PUEDE COLOCAR DONDE EL SUUARIO LO REQUIERA

    //int L = centroX;
    //int L = 0



/* Valores antiguos
   // int L = 150; //SE DEBE CONSIDERAR XPVMIN
    //int M = centroY;
   // int M = 375; */

    //LEER EL MATERIAL DE LO ANALIZADO EN EL TEMA DE
    //COLOCACION DE LA VENTANA EN EL PUERTO DE VISION

    int x1, y1, x2, y2;

    canvas->setPen(QColor(255, 0, 0));
                    //pasamos la referencia de x1, y1
    dibujo.mapear(Fig[0][0], Fig[0][1], x1, y1, L, M);
    dibujo.mapear(Fig[2][0], Fig[2][1], x2, y2, L, M);
    // PRIMERO DIBUJAMOS LA LUNEA QUE CIERRA EL TRIANGULO


    canvas->drawLine(x1, y1, x2, y2);

    for (int i = 0; i < 2; i++) {
        dibujo.mapear(Fig[i][0], Fig[i][1], x1, y1, L, M);
        dibujo.mapear(Fig[i+1][0], Fig[i+1][1], x2, y2, L, M);

        canvas->drawLine(x1, y1, x2, y2);
    }

    // REALIZAR PRUEBA DE ESCRITORIO A ESTOS VALORES
    // ESCRIBEN LOS VALORES EN UNA HOJA, TOMAN FOTO
    // INICIAMOS LA CLASE SALUDANDO CON ESA FOTO
    canvas->end();

}


void Widget::on_pushButton_clicked()
{
    asignarFigura();
    dibujoOrientacionNormal = true;// Y hacia abajo
    dibujoMapeado = false;
    repaint();
}

void Widget::on_pushButton_2_clicked()
{
    asignarFigura();
    dibujoMapeado = true;// Y hacia abajo
    dibujoOrientacionNormal = false;
    repaint();
}
