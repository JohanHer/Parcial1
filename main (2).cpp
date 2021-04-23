#include <iostream>

using namespace std;
int ***pmatriz;
void pedirdatos(int **);

int main()
{
    int cmatrices;
    cin >> cmatrices;
    pmatriz=new int**[3];
    for (int i=0; i<cmatrices; i++){
        pmatriz[i]= new int*[3];
    }

    for(int i=0; i<cmatrices; i++){
        pedirdatos(pmatriz[i]);
    }

    //cout << pmatriz[0][0][0];
    cout << *(*(*(pmatriz+0)+0)+0);

    for(int i=0; i<cmatrices; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                cout << pmatriz[i][j][k];
            }
            cout << endl;
        }
        cout << "-------" << endl;
    }

    return 0;
}

void pedirdatos(int **pm){
    pm = new int *[3];
    long int fila;
    int b;
    for (int i=0; i<3; i++){
        pm[i]= new int[3];
    }

    cout << "Para ingresar su patron, debe tener en cuenta que: "  << endl;
    cout << "- El numero 1 se reflejara como el led encendido "  << endl;
    cout << "- El numero 0 se reflejara como el led apagado "  << endl;
    cout << "- Debe ingresar fila por fila, por cada 1 o 0 de la fila debe presionar enter "  << endl;

    for(int i=0; i<3; i++){
        cout << "Ingrese la " << i+1 << " fila: " << endl;
        cin >> fila;
        for (int j=2; j>=0 ;j--){
            b=fila%10;
            *(*(pm+i)+j)=b;
            fila=fila/10;
        }
    }
/*
    for(int i=0; i<3; i++){
        for (int j=0; j<3 ;j++){
            cout << pm [i][j];
        }
        cout << endl;
    }*/
}
