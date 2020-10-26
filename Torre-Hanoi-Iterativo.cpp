#include <iostream>
using namespace std;

int f[1000000],g[1000000],h[1000000];

int potencia(int base, int exponente)
{
    int result = 1;
    for(int i=0; i<exponente; i++)
    {
        result=result*base;
    }
    return result;
}
///suma 1, si es 3 regresa a 1
int bucle3suma(int valor)
{
    valor++;
    if(valor>3)
        valor=1;
    return valor;
}
///resta 1, si es 1 regresa a 3
int bucle3resta(int valor)
{
    valor--;
    if(valor<1)
        valor=3;
    return valor;
}
int main()
{

    ///Torre1 empieza hacia torre de destino en este caso 3
    int nTorre1=3,nTorre2=1;///numeros de Torre
    int numPlat;///numero de Platillos
    int numPasos;
    int mitadPasos;
    int mPasos;///mitad de la mitad de Pasos
    int platillo;
    int movPlat; ///veces que se mueve el platillo n
    int ex;///cada platillo aumenta en uno el exponete
    int caso = 1;
    int i;

    cout << "Escribe el numero de platillos"<<endl;
    cin >> numPlat;

    numPasos = potencia(2,numPlat);
    mitadPasos = numPasos/2;
    /**
    *cada movimiento se guarda en la mitad del
    *total de movimintos hasta que completar el
    * numero de movimentos
    */
    f[mitadPasos] = nTorre1;/// f y g contienen la posicion de la torre en el paso n
    g[mitadPasos] = nTorre2;///
    h[mitadPasos] = numPlat;///contiene el numero de platillo en el paso n
    platillo = numPlat;

    ex = 1;
    while(mitadPasos>1)
    {
        platillo--;
        if(caso)
        {
            movPlat = potencia(2,ex);
            mPasos = mitadPasos/2;

            nTorre1=2; nTorre2=1;
            i = 0;
            while(i<movPlat)
            {
                f[mPasos] = nTorre1;
                g[mPasos] = nTorre2;
                h[mPasos] = platillo;
                mPasos = mPasos + mitadPasos;
                nTorre1 = bucle3suma(nTorre1);
                nTorre2 = bucle3suma(nTorre2);
                i++;
            }
        }
        if(!caso)
        {
            movPlat = potencia(2,ex);
            mPasos = mitadPasos/2;

            nTorre1=3; nTorre2=1;
            i = 0;
            while(i<movPlat)
            {
                f[mPasos] = nTorre1;
                g[mPasos] = nTorre2;
                h[mPasos] = platillo;
                mPasos = mPasos + mitadPasos;
                nTorre1 = bucle3resta(nTorre1);
                nTorre2 = bucle3resta(nTorre2);
                i++;
            }
        }
        caso=!caso;
        ex++;
        mitadPasos = mitadPasos/2;
    }

    for(i=1; i<numPasos; i++)
    {
        cout<<"Mover Platillo "<<h[i]<<" ";
        cout<<"de torre "<<g[i]<<" ";
        cout<<"a torre "<<f[i]<<" "<<endl;
        //cout<<endl;
    }
    cout<<"\nnumero de movimientos "<<numPasos-1<<endl;
    return 0;
}