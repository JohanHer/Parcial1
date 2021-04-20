#include <iostream>

using namespace std;

int main()
{
    long int fila;
    int matrizLed [8][8]={{},{},{},{},{},{},{},{}};
    int b;

    cout << "Para ingresar su patron, debe tener en cuenta que: "  << endl;
    cout << "- El numero 1 se reflejara como el led encendido "  << endl;
    cout << "- El numero 0 se reflejara como el led apagado "  << endl;
    cout << "- Debe ingresar fila por fila, por cada 1 o 0 de la fila debe presionar enter "  << endl;

    for(int i=0; i<8; i++){
        cout << "Ingrese la " << i+1 << " fila: " << endl;
        cin >> fila;
        for (int j=7; j>=0 ;j--){
            b=fila%10;
            matrizLed [i][j]=b;
            fila=fila/10;
        }
    }

    for(int i=0; i<8; i++){
        for (int j=0; j<8 ;j++){
            cout << matrizLed [i][j];
        }
        cout << endl;
    }

    return 0;
}
