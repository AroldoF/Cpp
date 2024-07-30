#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int matriz_A[4][5];
    int matriz_B[4][1];
    int matriz_C[5][1];
    int soma = 0, soma_B = 0, soma_C = 0;
    int i, j;

    cout << "Matriz A:" << endl;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            matriz_A[i][j] = rand() % 5;
            cout << matriz_A[i][j] << " ";
            soma += matriz_A[i][j];
        }
        matriz_B[i][0] = soma;
        soma_B += soma;
        soma = 0;
        cout << endl;
    }

    cout << "Matriz B:" << endl;
    for (i = 0; i < 4; i++)
    {
        cout << matriz_B[i][0] << " ";
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i == 0)
            {
                matriz_C[j][0] = matriz_A[i][j];
            }
            else
                matriz_C[j][0] += matriz_A[i][j];
        }
    }

    cout << "\nMatriz C:" << endl;
    for (i = 0; i < 5; i++)
    {
        cout << matriz_C[i][0] << " ";
        soma_C += matriz_C[i][0];
    }

    cout << "\nA somatorio da matriz B e " << soma_B << endl;
    cout << "A somatorio da matriz C e " << soma_C << endl;

    return 0;
}