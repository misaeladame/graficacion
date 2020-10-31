#ifndef DIALOG_H
#define DIALOG_H

#include "graphics.h"
#include <QDialog>
#include <QColorDialog>
#include <QMouseEvent> // PARA MANEJAR LOS EVENTOS DEL MOUSE

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog() override;

private slots:
    void on_pushButton_clicked();// linea dda

    void on_pushButton_2_clicked();// DIALOGO PARA SELECCIONAR EL COLOR

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_6_valueChanged(int arg1);

    void on_spinBox_7_valueChanged(int arg1);

private:
    Ui::Dialog *ui;

    void paintEvent(QPaintEvent *e) override;

    graphics *graficos;
    QPainter *Canvas;
    int x1, y1, x2, y2;
    QColor color;

    int xc, yc, radio;
    bool linea, circuloPitagoras, circuloPolares, circuloA, esp1, esp2;
    double radio_e, factor, th;

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;
};
#endif // DIALOG_H
