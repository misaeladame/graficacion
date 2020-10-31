#include "matrix.h"
#include <iostream>

using namespace std;

int main(int agrc, char *argv[])
{

    // REALIZAR PRUEBA DE ESCRITORIO EN PAPEL AL SIGUIENTE CODIGO
    // MOSTRANDO GRAFICAMENTE LO EXPLICADO
    // ES DECIR COMO FUNCIONAN LOS METODOS


           Matrix m1(3,3,0);
           for(int i = 0; i <3; i++)
             for(int j = 0; j < 3; j++)
                 m1.SET(i,j, rand()%10);
           for(int i = 0; i <3; i++)
           {
             for(int j = 0; j < 3; j++)
                 cout<<  m1.GET(i,j)<<"   ";
             cout<<endl;
           }

           cout<<endl<<endl;
           Matrix m2(m1);

           for(int i = 0; i <3; i++)
             for(int j = 0; j < 3; j++)
                 m2.SET(i,j,8);
           for(int i = 0; i <3; i++)
           {
             for(int j = 0; j < 3; j++)
                 cout<<  m2.GET(i,j)<<"   ";
             cout<<endl;
           }

           cout<<endl<<endl;
           Matrix m3 = m1 * m2;

           for(int i = 0; i <3; i++)
           {
             for(int j = 0; j < 3; j++)
                 cout<<  m3.GET(i,j)<<"   ";
             cout<<endl;
           }

           cout<<endl<<endl;
           Matrix m4(m1);
           m4.Identidad();

           for(int i = 0; i <3; i++)
           {
             for(int j = 0; j < 3; j++)
                 cout<<  m4.GET(i,j)<<"   ";
             cout<<endl;
           }

           cout<<endl<<endl;

           Matrix m5(m1);
           m5.transpuesta(m1);

           for(int i = 0; i < 3; i++)
           {
             for(int j = 0; j < 3; j++)
                 cout<<  m5.GET(i,j)<<"   ";
             cout<<endl;
           }



    return 0;
}
