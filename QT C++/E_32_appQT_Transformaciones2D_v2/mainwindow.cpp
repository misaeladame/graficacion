#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    angulo = 0;

    setWindowTitle(QString::fromUtf8("Un Tren chu chu !!!"));
    setFixedSize(400,400);
    timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(rotar()));
    timer->start(10);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainterPath elipsePath;

    //INVESTIGAR LOS OBJETOS DE QPAINTERPATH
    //DEFINIR UNA ELIPSE
    /*
    elipsePath.moveTo(80.0, 50.0);
    elipsePath.arcTo(20.0, 30.0, 60.0, 40.0, 0.0, 360.0);
    */

    QPainter painter(this);

    //DEFINIR UN TRIANGULO
    static const QPointF triangulo1[3] =
        {
          QPointF(10.0,60.0),
          QPointF(20.0,60.0),
          QPointF(15.0,50.0)
        };

    static const QPointF triangulo2[3] =
        {
          QPointF(20.0,40.0),
          QPointF(30.0,40.0),
          QPointF(25.0,30.0)
        };


    //DOCUMENTAR ESTE METODO DEL PAINT
    painter.setRenderHint(QPainter::Antialiasing);
    //TRANSFORMACIONES 2D
    painter.scale(width()/100.0, height()/100.0);
    painter.translate(50.0, 50.0);
    painter.rotate(angulo);
    painter.translate(-50, -50.0);

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));



    QLinearGradient gradiente(0,0,0,100);


    painter.setBrush(QColor(105,105,255));


    //painter.drawPath(elipsePath);
    painter.drawPolygon(triangulo1, 3);
    painter.drawRect(10, 60, 10, 10);

    painter.drawRect(20, 50, 35, 20);
    painter.drawRect(55, 30, 28, 40);


    painter.drawRect(20, 40, 10, 10);
    painter.drawPolygon(triangulo2, 3);

    // Ruedas del tren
    painter.setBrush(QColor(50,50,50));

    painter.drawEllipse(20, 65, 10,10);
    painter.drawEllipse(45, 61, 14, 14);
    painter.drawEllipse(65, 61, 14, 14);

    // Ventana del tren
    gradiente.setColorAt(0.2, Qt::white);
    gradiente.setColorAt(0.7, Qt::black);
    painter.setBrush(gradiente);
    painter.drawRect(63, 35, 12, 15);


    painter.setBrush(Qt::red);
    painter.drawRect(53, 27, 32, 3);


}

void MainWindow::rotar()
{
    ui->label->setText("Angulo :\n" +QString::number(angulo));
    update();

    int der = 1;
    int izq = 2;

    static int dir = der;
    if(dir == der && angulo <= 360)
    {
        angulo++;
        if(angulo==360) {
            dir = izq;
        }
    }
    if(dir == izq && angulo >= 0)
    {
        angulo--;
        if(angulo == 0)
        {
            dir = der;
        }
    }
}
