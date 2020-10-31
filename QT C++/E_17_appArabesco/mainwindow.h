#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "graficos.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    void paintEvent(QPaintEvent *e) override;
    void dragon(); // en esta app, seria el main
    void generarDragon(QPainter *Canvas);
    int EjeX[4098], EjeY[4098], Paso;
    int signo;


};
#endif // MAINWINDOW_H
