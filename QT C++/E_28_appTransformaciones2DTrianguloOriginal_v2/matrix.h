#ifndef MATRIX_H
#define MATRIX_H

// TAREA 1. SELECCIONAR SU DIBUJO Y PLASMARLO EN UNA HOJA CUADRICULADA
// ESTABLECIENDO LOS PUNTOS DE LA FIGURA ENUN ARREGLO BIDIMENSIONAL
// TAREA 2. ANALIZAR LA APP, CON LA CLASE MATRIZ
// REALIZAR UNA PRUEBA DE ESCRITORIO, A LA APP MATRIZ

// ARCHIVO .H(eader) PARA LA DEFINICION DE LA CLASE
class Matrix
{

    int col, ren;
    float **Mat;// DECLARACION DE UN ARREGLO BIDIMENSIONAL EN JAVA

    public:

       Matrix(int nr=4,int nc=4, float valor=0);//constructor con arg. por defecto

       Matrix(float nr,float nc, float **m);

       Matrix(Matrix &);//CONSTRUCTORDE COPIA
       ~Matrix();
       // CODIGO inline
       void SET(int R, int C, float val) { Mat[R][C]=val; }
       float GET(int R, int C) { return Mat[R][C]; }
       int numCol() { return col; }
       int numRen() { return ren; }
       void Inicializa(int, int);

       // EN C++ TODOS LOS OPERADORES SE PUEDEN SOBRECARGAR

       Matrix &operator *=(Matrix &mat2);

       Matrix &operator*(const Matrix &m1);

       Matrix operator*(float);//Multiplicar por un escalar

       Matrix &operator=(Matrix &m);

       Matrix & asignar(Matrix);

       Matrix & Identidad();/* 1 0 0
                               0 1 0
                               0 0 1
                            */

       Matrix & transpuesta(Matrix);

       //FigT               Fig      ID    Tx    Ty
       Matrix & traslacion(Matrix, Matrix, int, int);

       Matrix & escalacion(Matrix, Matrix, int, int);

       Matrix & escalacionFijo(Matrix, Matrix, int, int, int, int);

       Matrix & rotacion(Matrix, Matrix, double);

       Matrix & rotacionPuntoPivote(Matrix, Matrix, double, int, int);

       Matrix & reflexionEjeX (Matrix, Matrix);

       Matrix & reflexionEjeY (Matrix, Matrix);

       Matrix & reflexionEjeCoordenado (Matrix, Matrix);

       Matrix & reflexionRectaYIgualX (Matrix, Matrix);

       Matrix & reflexionRectaYIgualMenosX (Matrix, Matrix);



};

#endif // MATRIX_H
