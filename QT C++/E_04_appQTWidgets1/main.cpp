// #include <QCoreApplication>
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel etiqueta("TEC LAGUNA");//ETIQUETA ESTATICA
    etiqueta.setWindowTitle("PROBANDO QT 5");
    etiqueta.resize(300,300);
    etiqueta.show();

    QLabel *label = new QLabel("Etiqueta de QT");
    label->show();

    return a.exec();
}
