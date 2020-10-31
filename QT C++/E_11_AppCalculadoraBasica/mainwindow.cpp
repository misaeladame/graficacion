#include "mainwindow.h"
#include "ui_mainwindow.h"

double primerNumero;
bool usuarioEscribeSegundoNumero = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digito_presionado()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digito_presionado()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digito_presionado()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digito_presionado()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digito_presionado()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digito_presionado()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digito_presionado()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digito_presionado()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digito_presionado()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digito_presionado()));

    connect(ui->pushButton_MasMenos, SIGNAL(released()), this, SLOT(operador_unario_pressed()));
    connect(ui->pushButton_Porcentaje, SIGNAL(released()), this, SLOT(operador_unario_pressed()));

    connect(ui->pushButton_Suma, SIGNAL(released()), this, SLOT(operador_binario_pressed()));
    connect(ui->pushButton_Resta, SIGNAL(released()), this, SLOT(operador_binario_pressed()));
    connect(ui->pushButton_Multiplicacion, SIGNAL(released()), this, SLOT(operador_binario_pressed()));
    connect(ui->pushButton_Division, SIGNAL(released()), this, SLOT(operador_binario_pressed()));

    ui->pushButton_Suma->setCheckable(true);
    ui->pushButton_Resta->setCheckable(true);
    ui->pushButton_Multiplicacion->setCheckable(true);
    ui->pushButton_Division->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digito_presionado()
{
    QPushButton *boton = (QPushButton*)sender();

    double numero_label;
    QString nuevo_label;

    if ((ui->pushButton_Suma->isChecked() ||
        ui->pushButton_Resta->isChecked() ||
        ui->pushButton_Multiplicacion->isChecked() ||
        ui->pushButton_Division->isChecked()) &&
        (!usuarioEscribeSegundoNumero))
    {
        numero_label = boton->text().toDouble();
        usuarioEscribeSegundoNumero = true;
        nuevo_label = QString::number(numero_label,'g', 15);
    } else {
        if (ui->label->text().contains('.') && boton->text() == "0")
        {
            nuevo_label = ui->label->text() + boton->text();
        } else {
            numero_label = (ui->label->text() + boton->text()).toDouble();
            nuevo_label = QString::number(numero_label, 'g', 15);
        }

    }

    ui->label->setText(nuevo_label);

}

void MainWindow::on_pushButton_Punto_released()
{
    ui->label->setText(ui->label->text() +".");
}

void MainWindow::operador_unario_pressed()
{
    QPushButton * boton = (QPushButton*) sender();
    double numero_label;
    QString nuevo_label;

    if (boton->text() == "+/-")
    {
        numero_label = ui->label->text().toDouble();
        numero_label = numero_label *- 1;
        nuevo_label = QString::number(numero_label, 'g', 15);
        ui->label->setText(nuevo_label);
    }

    if (boton->text() == "%")
    {
        numero_label = ui->label->text().toDouble();
        numero_label = numero_label * 0.01;
        nuevo_label = QString::number(numero_label, 'g', 15);
        ui->label->setText(nuevo_label);
    }

    usuarioEscribeSegundoNumero = false;
}

void MainWindow::on_pushButton_Limpiar_released()
{
    ui->pushButton_Suma->setChecked(false);
    ui->pushButton_Resta->setChecked(false);
    ui->pushButton_Multiplicacion->setChecked(false);
    ui->pushButton_Division->setChecked(false);

    usuarioEscribeSegundoNumero = false;

    ui->label->setText("0");

}

void MainWindow::on_pushButton_Igual_released()
{
    double numero_label, segundoNumero;
    QString nuevo_label;

    segundoNumero = ui->label->text().toDouble();


    if (ui->pushButton_Suma->isChecked())
    {
        numero_label = primerNumero + segundoNumero;
        nuevo_label = QString::number(numero_label, 'g', 15);
        ui->label->setText(nuevo_label);
        ui->pushButton_Suma->setChecked(false);
    }
    else if (ui->pushButton_Resta->isChecked())
    {
        numero_label = primerNumero - segundoNumero;
        nuevo_label = QString::number(numero_label, 'g', 15);
        ui->label->setText(nuevo_label);
        ui->pushButton_Resta->setChecked(false);
    }
    else if (ui->pushButton_Multiplicacion->isChecked())
    {
        numero_label = primerNumero * segundoNumero;
        nuevo_label = QString::number(numero_label, 'g', 15);
        ui->label->setText(nuevo_label);
        ui->pushButton_Multiplicacion->setChecked(false);
    }
    else if (ui->pushButton_Division->isChecked())
    {
        numero_label = primerNumero / segundoNumero;
        nuevo_label = QString::number(numero_label, 'g', 15);
        ui->label->setText(nuevo_label);
        ui->pushButton_Division->setChecked(false);
    }
}

void MainWindow::operador_binario_pressed()
{
    QPushButton *boton = (QPushButton*) sender();


    primerNumero = ui->label->text().toDouble();

    boton->setChecked(true);
}
