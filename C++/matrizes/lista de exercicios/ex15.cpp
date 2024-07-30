#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int i,j,soma=0,soma_total=0;
    float matriz_A[8][6];
    float matriz_B[8][1];

    cout << "Matriz A:" << endl;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 6; j++)
        {
            matriz_A[i][j] = rand() % 5;
            cout << matriz_A[i][j] << " ";
        }
        cout << endl;
    }
    
    cout<<"Matriz B:"<<endl;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 6; j++)
        {
            soma+=matriz_A[i][j];
        }
        matriz_B[i][0]=soma;
        cout<<matriz_B[i][0]<<endl;
        soma_total+=soma;
        soma=0;
    }
    cout<<"O somatorio da matriz B e "<<soma_total<<endl;

    return 0;
}