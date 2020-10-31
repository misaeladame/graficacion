#include "dialog.h"
#include "ui_dialog.h"
#include <QTime>



Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(close()));
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_2_clicked()
{
    //this->close();
    close();
}

void Dialog::on_pushButton_4_clicked()
{
    QString dato = ui->lineEdit->text();
    int base = dato.toInt();

    double pot = ui->lineEdit_2->text().toDouble();
    double resul = pow(base, pot);

    ui->label_3->setText("RESULTADO : ");
    ui->label_3->setText(ui->label_3->text() + " " + QString::number(resul));
}

void Dialog::on_pushButton_5_clicked()
{
    QTime time = QTime::currentTime();
    qsrand(time.msec());

    int numA = qrand() % 900 + 100;
    ui->lineEdit_3->setText(QString::number(numA));
}

void Dialog::on_verticalSlider_valueChanged(int value)
{
    Q_UNUSED(value);

    ui->lcdNumber_2->setHexMode();
}

void Dialog::on_horizontalSlider_2_valueChanged(int value)
{

}
