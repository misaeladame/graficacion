#include "byteconverterdialog.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QIntValidator>
#include <QRegExpValidator>

#include "byteconverter.h"

//ByteConverterDialog::ByteConverterDialog(QObject *parent) : QObject(parent)
//{

//}

ByteConverterDialog::ByteConverterDialog()
{
    // Geenerar Layouts necesarios
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QGridLayout *editLayout = new QGridLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    QLabel *decLabel= new QLabel("Decimal");
    QLabel *hexLabel = new QLabel("Hexadecimal");
    QLabel *binLabel = new QLabel("Binario");

    decEdit = new QLineEdit;
    hexEdit = new QLineEdit;
    binEdit = new QLineEdit;

    editLayout->addWidget(decLabel, 0, 0);
    editLayout->addWidget(decEdit, 0, 1);
    editLayout->addWidget(hexLabel,1,0);
    editLayout->addWidget(binLabel, 2, 0);
    editLayout->addWidget(binEdit, 2, 1);
    editLayout->addWidget(hexEdit, 1, 1);

    QPushButton *botonSalir = new QPushButton("Salir");

    buttonLayout->addStretch();
    buttonLayout->addWidget(botonSalir);

    mainLayout->addLayout(editLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    connect(botonSalir, SIGNAL(released()), this, SLOT(accept()) );

    // VALIRAR LA ENTRADA DE VALROES DE 4 BYTES (4294967296)

    QRegExpValidator *decVal = new QRegExpValidator(QRegExp("[0-9]{1,10}"), hexEdit);
    decEdit->setValidator(decVal);

    // EXPRESIONES REGULARES
    QRegExpValidator *hexVal = new QRegExpValidator(QRegExp("[0-9A-Fa-f]{1,8}"), hexEdit);
    hexEdit->setValidator(hexVal);

    QRegExpValidator *binVal = new QRegExpValidator(QRegExp("[0-1]{1,32}"), binEdit);
    binEdit->setValidator(binVal);

    ByteConverter *conv = new ByteConverter;

    connect(decEdit, SIGNAL(textChanged(QString)), conv, SLOT(setDec(QString)));
    connect(hexEdit, SIGNAL(textChanged(QString)), conv, SLOT(setHex(QString)));
    connect(binEdit, SIGNAL(textChanged(QString)), conv, SLOT(setBin(QString)));

    connect(conv, SIGNAL(decChanged(QString)), decEdit, SLOT(setText(QString)));
    connect(conv, SIGNAL(hexChanged(QString)), hexEdit, SLOT(setText(QString)));
    connect(conv, SIGNAL(binChanged(QString)), binEdit, SLOT(setText(QString)));
}
