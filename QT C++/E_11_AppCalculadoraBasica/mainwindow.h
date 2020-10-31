#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digito_presionado();
    void on_pushButton_Punto_released();
    void operador_unario_pressed();
    void on_pushButton_Limpiar_released();
    void on_pushButton_Igual_released();
    void operador_binario_pressed();
};
#endif // MAINWINDOW_H
