#include <QApplication>
#include<QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*
    QLabel etiqueta("TEC LAGUNA");
    etiqueta.setWindowTitle("PRACTICANDO CON QT 5");
    etiqueta.resize(400, 400);
    etiqueta.show();
    */

    // ETIQUETA DINAMICA
 /*   QLabel *etiqueta = new QLabel("TECNOLOGICO DE LA LAGUNA");

    etiqueta->setWindowTitle("PRACTICANDO CON QT5 ");
    etiqueta->resize(500,500);

    etiqueta->setFrameStyle(QFrame::Panel | QFrame::Sunken );

    etiqueta->setAlignment(Qt::AlignVCenter | Qt::AlignRight);

    etiqueta->show(); */

    // ETIQUETA DINAMICA

    QLabel *etiqueta = new QLabel("TECNOLOGICO DE LA LAGUNA");

    etiqueta->setText("<h2>Tecnologico<font color=blue> de la </font><font color = #40608E> LAGUNA</font></h2>");

    etiqueta->setWindowTitle("PRACTICANDO CON QT5");
    etiqueta->resize(500,500);
    etiqueta->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    etiqueta->setAlignment(Qt::AlignVCenter | Qt::AlignRight);

    etiqueta->show();

    return a.exec();
}
