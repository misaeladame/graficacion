#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <math.h>

//INVESTIGAR LA NOTACION UML

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked(); // Potencia

    void on_pushButton_5_clicked();

    void on_verticalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
