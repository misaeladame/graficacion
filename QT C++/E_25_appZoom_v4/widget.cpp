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
    // MURCIELAGO
             // X              Y               H
    Fig[0][0] = 3; Fig[0][1] = 3; Fig[0][2] = 1;
    Fig[1][0] = 5; Fig[1][1] = -1; Fig[1][2] = 1;
    Fig[2][0] = 6; Fig[2][1] = -2; Fig[2][2] = 1;
    Fig[3][0] = 8; Fig[3][1] = 0; Fig[3][2] = 1;
    Fig[4][0] = 10; Fig[4][1] = 4; Fig[4][2] = 1;
    Fig[5][0] = 12; Fig[5][1] = 8; Fig[5][2] = 1;
    Fig[6][0] = 13; Fig[6][1] = 12; Fig[6][2] = 1;
    Fig[7][0] = 13; Fig[7][1] = 16; Fig[7][2] = 1;
    Fig[8][0] = 15; Fig[8][1] = 15; Fig[8][2] = 1;
    Fig[9][0] = 19; Fig[9][1] = 15; Fig[9][2] = 1;
    Fig[10][0] = 22; Fig[10][1] = 15; Fig[10][2] = 1;
    Fig[11][0] = 24; Fig[11][1] = 15; Fig[11][2] = 1;
    Fig[12][0] = 26; Fig[12][1] = 16; Fig[12][2] = 1;
    Fig[13][0] = 25; Fig[13][1] = 14; Fig[13][2] = 1;
    Fig[14][0] = 23; Fig[14][1] = 10; Fig[14][2] = 1;
    Fig[15][0] = 22; Fig[15][1] = 6; Fig[15][2] = 1;
    Fig[16][0] = 19; Fig[16][1] = 5; Fig[16][2] = 1;
    Fig[17][0] = 17; Fig[17][1] = 3; Fig[17][2] = 1;
    Fig[18][0] = 16; Fig[18][1] = 1; Fig[18][2] = 1;
    Fig[19][0] = 15; Fig[19][1] = -3; Fig[19][2] = 1;
    Fig[20][0] = 15; Fig[20][1] = -7; Fig[20][2] = 1;
    Fig[21][0] = 13; Fig[21][1] = -8; Fig[21][2] = 1;
    Fig[22][0] = 11; Fig[22][1] = -10; Fig[22][2] = 1;
    Fig[23][0] = 9; Fig[23][1] = -12; Fig[23][2] = 1;
    Fig[24][0] = 8; Fig[24][1] = -14; Fig[24][2] = 1;
    Fig[25][0] = 7; Fig[25][1] = -18; Fig[25][2] = 1;
    Fig[26][0] = 5; Fig[26][1] = -16; Fig[26][2] = 1;
    Fig[27][0] = 1; Fig[27][1] = -14; Fig[27][2] = 1;
    Fig[28][0] = 0; Fig[28][1] = -14; Fig[28][2] = 1;
    Fig[29][0] = -4; Fig[29][1] = -15; Fig[29][2] = 1;
    Fig[30][0] = -6; Fig[30][1] = -17; Fig[30][2] = 1;
    Fig[31][0] = -8; Fig[31][1] = -15; Fig[31][2] = 1;
    Fig[32][0] = -10; Fig[32][1] = -13; Fig[32][2] = 1;
    Fig[33][0] = -11; Fig[33][1] = -12; Fig[33][2] = 1;
    Fig[34][0] = -12; Fig[34][1] = -12; Fig[34][2] = 1;
    Fig[35][0] = -13; Fig[35][1] = -12; Fig[35][2] = 1;
    Fig[36][0] = -14; Fig[36][1] = -13; Fig[36][2] = 1;
    Fig[37][0] = -17; Fig[37][1] = -15; Fig[37][2] = 1;
    Fig[38][0] = -18; Fig[38][1] = -15; Fig[38][2] = 1;
    Fig[39][0] = -22; Fig[39][1] = -13; Fig[39][2] = 1;
    Fig[40][0] = -24; Fig[40][1] = -12; Fig[40][2] = 1;
    Fig[41][0] = -25; Fig[41][1] = -12; Fig[41][2] = 1;
    Fig[42][0] = -27; Fig[42][1] = -13; Fig[42][2] = 1;
    Fig[43][0] = -25; Fig[43][1] = -11; Fig[43][2] = 1;
    Fig[44][0] = -23; Fig[44][1] = -8; Fig[44][2] = 1;
    Fig[45][0] = -21; Fig[45][1] = -5; Fig[45][2] = 1;
    Fig[46][0] = -19; Fig[46][1] = 0; Fig[46][2] = 1;
    Fig[47][0] = -15; Fig[47][1] = -2; Fig[47][2] = 1;
    Fig[48][0] = -12; Fig[48][1] = -4; Fig[48][2] = 1;
    Fig[49][0] = -10; Fig[49][1] = -5; Fig[49][2] = 1;
    Fig[50][0] = -7; Fig[50][1] = -6; Fig[50][2] = 1;
    Fig[51][0] = -4; Fig[51][1] = -6; Fig[51][2] = 1;
    Fig[52][0] = -1; Fig[52][1] = -6; Fig[52][2] = 1;
    Fig[53][0] = -1; Fig[53][1] = -3; Fig[53][2] = 1;
    Fig[54][0] = -2; Fig[54][1] = 1; Fig[54][2] = 1;
    Fig[55][0] = 0; Fig[55][1] = -1; Fig[55][2] = 1;
    Fig[56][0] = 1; Fig[56][1] = 0; Fig[56][2] = 1;
    Fig[57][0] = 2; Fig[57][1] = 0; Fig[57][2] = 1;
    Fig[58][0] = 3; Fig[58][1] = 1; Fig[58][2] = 1;
    Fig[59][0] = 3; Fig[59][1] = 3; Fig[59][2] = 1;



    Fig[60][0] = 10; Fig[60][1] = 10; Fig[60][2] = 1;

    // ESTE ES EL PUNTO INICIAL, PARA CERRAR LA FIGURA

    //    <<<<<

    // RESPALDAR LOS VALORES DEL POLIGONO
    for ( int r = 0; r < 61; r++)
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

    Mapeo dibujo;

    //LA VENTANA ES EL AREA DEL MUNDO REAL

    dibujo.ventana(-27, -18, 26, 16); //HOJA DE MAQUINA

    zoom = ui->spinBox->value();

    dibujo.puerto(100 - zoom, 150 - zoom, 400 + zoom, 350 + zoom);
    canvas->drawRect(100 - zoom, 150 - zoom, 300 + (zoom * 2), 200 + (zoom * 2) );

    int L = 0;
    int M = 500; // ES LA SUMA DE LOS VALORES PARA YPVMIN + YPVMAX

    int x1, y1, x2, y2;

    canvas->setPen(QColor(0, 0, 165));

    for (int i = 0; i < 59; i++) {
        dibujo.mapear(Fig[i][0], Fig[i][1], x1, y1, L, M);
        dibujo.mapear(Fig[i+1][0], Fig[i+1][1], x2, y2, L, M);

        canvas->drawLine(x1, y1, x2, y2);
    }

    // REALIZAR PRUEBA DE ESCRITORIO A ESTOS VALORES
    // ESCRIBEN LOS VALORES EN UNA HOJA, TOMAN FOTO
    // INICIAMOS LA CLASE SALUDANDO CON ESA FOTO
    canvas->end();

}

void Widget::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key() == Qt::Key_Up) //FLECHA ARRIBA en WINDOWS VK_UP
        ui->spinBox->stepUp();
    if(evento->key() == Qt::Key_Down)
        ui->spinBox->stepDown();
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
