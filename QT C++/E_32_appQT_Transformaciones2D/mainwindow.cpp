#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    angulo = 0;

    setWindowTitle(QString::fromUtf8("ROTACION DE UNA ELIPSE CON QPaintPath"));
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
    elipsePath.moveTo(80.0, 50.0);
    elipsePath.arcTo(20.0, 30.0, 60.0, 40.0, 0.0, 360.0);

    QPainter painter(this);

    //DEFINIR UN TRIANGULO
    static const QPointF puntos[3] =
        {
          QPointF(10.0,30.0),
          QPointF(90,30.0),
          QPointF(50.0,60.0)
        };

    //DOCUMENTAR ESTE METODO DEL PAINT
    painter.setRenderHint(QPainter::Antialiasing);
    //TRANSFORMACIONES 2D
    painter.scale(width()/100.0, height()/100.0);
    painter.translate(50.0, 50.0);
    painter.rotate(angulo);
    painter.translate(-50, -50.0);

    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    QLinearGradient gradiente(0,0,0,100);
    gradiente.setColorAt(0.0, Qt::blue);
    gradiente.setColorAt(1.0, Qt::white);

    painter.setBrush(gradiente);

    painter.drawPath(elipsePath);
    painter.drawPolygon(puntos, 3);
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
