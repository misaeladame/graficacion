#include <iostream>

using namespace std;

int main()
{
 /*   int a = 10;
    int *pa;

    cout << "Valor de a = " << a << endl;
    cout << "Direccion de a = " << &a <<endl;

    pa = &a;
    cout << "Valor de a = " << *pa << endl;
    cout << "Direccion de pa = " << pa <<endl;

    *pa *= 2;
    cout << "Valor de a = " << a << endl;
    cout << "Valor de *pa = " << *pa <<endl;
    return 0; */

    // an array with 5 elements.
    double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    double *p;
    p = balance;
    // output each array element's value
    cout << "Array values using pointer " <<endl;
    for ( int i = 0; i < 5; i++ ) {
        cout << "*(p + " << i << ") : ";
        // cout << *(p + 1) << endl;
        //USANDO ARITMETICA DE PUNTEROS
        cout << "Contenido de *p = " << *p << " Direccion de p = " << p <<endl;
        p++;
    }
    cout << "Array valuees using balance as address " << endl;

    for ( int i = 0; i < 5; i++) {
        cout << "*(balance + " << i <<") : ";
        cout << *(balance + i) << endl;
    }
    for ( int i = 0; i < 5; i++) {
        cout << "*(balance + [" << i <<"] : ";
        cout << balance[i] << endl;
    }

    return 0;
}
