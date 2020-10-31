#ifndef BYTECONVERTER_H
#define BYTECONVERTER_H

#include <QObject>

class ByteConverter : public QObject
{
    Q_OBJECT
public:
    explicit ByteConverter(QObject *parent = nullptr);

signals:
    void decChanged(const QString &);
    void hexChanged(const QString &);
    void binChanged(const QString &);


public slots:
    void setDec(const QString &);
    void setHex(const QString &);
    void setBin(const QString &);
};

#endif // BYTECONVERTER_H
