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

private:
    Ui::Dialog *ui;

    void paintEvent(QPaintEvent *e) override;

    graphics *graficos;
    QPainter *Canvas;
    int x1, y1, x2, y2;
    QColor color;


protected:
    void mousePressEvent(QMouseEvent *event) override;
/*
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
*/
    void mouseMoveEvent(QMouseEvent *event) override;
};
#endif // DIALOG_H
