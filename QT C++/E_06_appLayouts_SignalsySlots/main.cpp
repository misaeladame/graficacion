#include <QApplication>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QPushButton>
#include <QVBoxLayout>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget ventana;
    //LAYOUT VERTICAL
    QVBoxLayout *mainLayout = new QVBoxLayout(&ventana);

    QLabel *label = new QLabel("0");
    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    QPushButton* boton1 = new QPushButton("Salir");

    // MODIFICAR PROPIEDADES DE LA ETIQUETA
    // COLOR, FONT

    mainLayout->addWidget(label);
    mainLayout->addWidget(spinBox);
    mainLayout->addWidget(slider);
    mainLayout->addWidget(boton1);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));
    QObject::connect(slider,SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));

    QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

    QObject::connect(boton1, SIGNAL(clicked()), qApp, SLOT(quit()));
    ventana.show();

    return a.exec();
}
