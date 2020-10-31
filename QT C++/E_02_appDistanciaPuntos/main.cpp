#include <iostream>
#include "punto.h"

using namespace std;

int main()
{
    int x1, y1, x2, y2;
    cout<<"X1 =";
    cin>>x1;
    cout<<"Y1 =";
    cin>>y1;
    cout<<"X2 =";
    cin>>x2;
    cout<<"Y2 =";
    cin>>y2;
    Punto pi(x1,y1);//OBJETO ESTATICO

    Punto *pPunto;

    Punto *pf = new Punto(x2,y2);//OBJETO DINAMICO
    cout<<"DIRECCION DE *pf"<<hex<<pf<<dec<<endl;
    //OBJETO BLANCO
    //UN OBJETO UTILIZA UNO DE SUS METODOS
    //Y COMO ARGUMENTO OTRO OBJETO DEL MISMO TIPO
    double result = pi.calcularDist(*pf);

    cout<<"\tPUNTO INICIAL x = "<<pi.getX()<<endl;
    cout<<"\tPUNTO INICIAL y = "<<pi.getY()<<endl;
    cout<<"\tPUNTO FINAL x = "<<pf->getX()<<endl;
    cout<<"\tPUNTO FINAL y = "<<pf->getY()<<endl;

    cout<<"LA DISTANCIA ES : "<<result<<endl;

    pi.setX(50);
    pi.setY(150);

    cout<<"NUEVO VALOR DE pi.x = "<<pi.getX()<<endl;
    cout<<"NUEVO VALOR DE pi.y = "<<pi.getY()<<endl;
    cout<<"LA NUEVA DISTANCIA ES = "<<pi.calcularDist(*pf)<<endl;

    Punto pN(pi);
    cout<<"NUEVO PUNTO pN.x = "<<pN.getX()<<endl;
    cout<<"NUEVO PUNTO pN.y = "<<pN.getY()<<endl;
    cout<<"LA NUEVA DISTANCIA ES = "<<pf->calcularDist(pN)<<endl;

    return 0;
}
