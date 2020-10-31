#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QImage rotarR(const QImage &in);
    QImage rotarR_AND(int valor_verde, const QImage &in);
    QImage rotarR_OR(int valor_verde, const QImage &in);
    QImage rotarR_XOR(int valor_verde, const QImage &in);

    QImage rotarG(const QImage &in);
    QImage rotarG_AND(int valor_rojo, const QImage &in);
    QImage rotarG_OR(int valor_rojo, const QImage &in);
    QImage rotarG_XOR(int valor_rojo, const QImage &in);

    QImage rotarB(const QImage &in);
    QImage rotarB_AND(int valor_azul, const QImage &in);
    QImage rotarB_OR(int valor_azul, const QImage &in);
    QImage rotarB_XOR(int valor_azul, const QImage &in);


    QString fileName;

private slots:

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
