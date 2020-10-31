#ifndef BYTECONVERTERDIALOG_H
#define BYTECONVERTERDIALOG_H

#include <QObject>
#include <QDialog>

class QLineEdit;
class ByteConverterDialog : public QDialog
{
    Q_OBJECT
public:
    //explicit ByteConverterDialog(QObject *parent = nullptr);
    ByteConverterDialog();
private:
    QLineEdit *decEdit;
    QLineEdit *hexEdit;
    QLineEdit *binEdit;
};

#endif // BYTECONVERTERDIALOG_H
