#include <QApplication>
#include <QDebug>
#include <QTextStream>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
   /* QTextStream qtin(stdin);
    QString res;
    qDebug()<<"TECLEA EXP. INFIJA ";*/

    string exp_infija1 = "1^2*((3-4)+5)/(6*7+8)";

    QString exp_infija = QString::fromStdString(exp_infija1);

    // RECORRER EL QSTRING Y ESCRIBIRLO DE
    // FORMA VERTICAL

    return a.exec();
}
