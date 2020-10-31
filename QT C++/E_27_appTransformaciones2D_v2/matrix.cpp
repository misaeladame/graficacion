#include "matrix.h"
#include <math.h>
#include <assert.h>

Matrix::Matrix(int nr,int nc, float valor)
{
    //this->ren = ren;
  ren = nr;
  col = nc;
  Mat = new float*[ren];
  assert(Mat);//Verifica si new regresa NULL, de ser asi aborta el programa
  for(int i = 0; i < ren; i++)
  {
      Mat[i] = new float[col];
      assert(Mat[i]);
  }
//EN C++ SE DEBEN INICIALIZAR LAS VARIABLES, INCLUIDOS LOS ARREGLOS
  for(int i = 0; i < ren; i++)
    for(int j = 0; j < col; j++)
        Mat[i][j] = valor;
}

Matrix::Matrix(float nr,float nc, float **m)
{
  ren = nr;
  col = nc;
  Mat = new float*[ren];
  assert(Mat);
  for(int i = 0; i < ren; i++)
  {
      Mat[i] = new float[col];
      assert(Mat[i]);
  }

  for(int i = 0; i < ren; i++)
    for(int j = 0; j < col; j++)
        Mat[i][j] = m[i][j];
}


//CONSTRUCTOR DE COPIA

Matrix::Matrix(Matrix &m)
{
   this->ren=m.numRen();
   col=m.numCol();
   Mat =new float*[ren];
   for(int i = 0; i < ren; i++)
  {
     Mat[i] = new float[col];
     assert(Mat[i]);
  }
   for(int i=0; i<ren; i++)
      for( int j=0; j<col; j++)
         Mat[i][j]=m.GET(i,j);
}

void Matrix::Inicializa(int R, int C)//Inicializa a ceros
{
   col=C;
   ren=R;
   Mat=new float *[ren];
   for(int i=0; i<ren; i++)
      Mat[i]=new float[col];
   for(int i=0; i<ren; i++)
      for(int j=0; j<col; j++)
         Mat[i][j]=0;
}

Matrix &Matrix::operator*=(Matrix &mat2)
{
   Matrix aux;
   aux.Inicializa(ren, mat2.numCol());


   for(int i=0; i<ren; i++)
   {
      for(int j=0; j<mat2.numCol(); j++)
      {
         float suma=0;
        // Mat[i][j]=0;
         for(int k=0; k<col; k++)
         {
           suma+=floor(Mat[i][k]*mat2.GET(k,j)+0.5);
           aux.SET(i,j,suma);//SOBERCARGAR EL OPERADOR [][] ??
         }
         //aux.SET(i,j,suma);
      }
   }
   asignar(aux);
   return *this;
}

Matrix Matrix::operator*(float val)//MULTIPLICAR POR UN ESCALAR
{
   Matrix temp;
   temp.Inicializa(ren,col);
   for(int i=0; i<ren;i++)
      for(int j=0; j<col; j++)
         temp.SET(i,j,Mat[i][j]* val);
   return temp;
}


Matrix &Matrix::operator*(const Matrix &m1)
{
  //assert((ren == m1.ren) && (col == m1.col));
   Matrix * result = new Matrix(ren,col,0);
   assert(result);
   for(int i=0; i < ren; i++)
     for(int j = 0;  j < col; j++)
                       //DEBE SER EL NUMERO DE COLUMNAS
                     //REN SOLO SI ES CUADRADA EJ: 3 x 3
       for(int k = 0; k < col; k++)
            //result->Mat[i][j]= result->Mat[i][j] + Mat[i][k] * m1.Mat[k][j];
           result->Mat[i][j] += Mat[i][k] * m1.Mat[k][j];


   return *result;
}

Matrix &Matrix::operator=(Matrix &m)
{
//eliminar el tamaño de la matriz destino
  for(int i= 0; i<ren;i++ )
     //Se borran las columnas por renglones de la matriz
       delete [] Mat[i];
  //Se borra el arreglo de punteros
  delete []Mat;
//Asignar los nuevos datos de la matriz que llego
  ren=m.numRen();
  col = m.numCol();
  Mat = new float*[ren];
  assert(Mat);
  for(int i = 0; i < ren; i++)
  {
     Mat[i] = new float[col];
     assert(Mat[i]);
  }
  for( int i =0; i < ren; i++)
    for(int j = 0; j < col; j++)
        Mat[i][j] = m.Mat[i][j];

  return *this;
}


Matrix &Matrix::asignar(Matrix m)
{
   for(int i=0;i<m.numRen();i++)
       for(int j=0;j<m.numCol();j++)
                Mat[i][j]=m.GET(i,j);
   return *this;
}

Matrix::~Matrix()//DESTRUCTOR
{
  //Se libera la memoria
  for(int i= 0; i<ren;i++ )
     //Se borran los renglones de la matriz
       delete [] Mat[i];
  //Se borra el arreglo de punteros
  delete []Mat;

}

Matrix &Matrix::Identidad()
{
  for(int i=0; i < ren; i++)
    for( int j = 0; j < col; j++)
      if( i == j)
         Mat[i][i]= 1;
      else
         Mat[i][j]= 0;
  return *this;
}

Matrix &Matrix::transpuesta(Matrix m)
{
    for(int i=0; i < col; i++ )
        for(int j = 0; j < ren; j++ )
            Mat[j][i] = m.GET(i, j);

    return *this;
}

//-------------------------TRANSFORMACIONES----------------------------
Matrix &Matrix::traslacion(Matrix f, Matrix id, int tx, int ty)
{
    id.Identidad(); //MAT. DE TRANSFORMACION
    id.SET(2, 0, tx);
    id.SET(2, 1, ty);

    f*=id;
    this->asignar(f);
    return *this;

}

Matrix &Matrix::escalacion(Matrix f, Matrix id, int sx, int sy)
{
    id.SET(0, 0, sx);
    id.SET(1, 1, sy);
    id.SET(2, 2, 1);

    f*=id;
    this->asignar(f);
    return *this;

}

Matrix &Matrix::escalacionFijo(Matrix f, Matrix id, int sx, int sy, int pfx, int pfy )
{
    //id.escalacion(f, id, sx, sy);
    id.SET(0, 0, sx);
    id.SET(1, 1, sy);
    id.SET(2, 2, 1);

    id.SET(2, 0, -pfx*(sx-1));
    id.SET(2, 1, -pfy*(sy-1));

    f*=id;
    this->asignar(f);
    return *this;
}

