#ifndef DIALOG_H
#define DIALOG_H
#include "graphics.h"
#include <QDialog>
#include <QColorDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    //REALIZAR PRUEBA DE ESCRITORIO
    //AL METODO LINEA DDA
    //SUBIR FOTO
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();


private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    void paintEvent(QPaintEvent *e);

    // ESTE METODO YA NO SE VA A USAR
    //UTILIZAREMOS EL DE LA CLASE graphics
    void lineaDDA (int x1, int y1, int x2, int y2, QPainter *canvas);

  //  QPainter *Canvas;
    int x1, y1, x2, y2;
    QColor color;


};
#endif // DIALOG_H
