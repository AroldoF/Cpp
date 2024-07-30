#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int matriz_A[7][7];
    int soma = 0;
    int i, j;

    cout << "Matriz A:" << endl;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            matriz_A[i][j] = rand() % 5;
            cout << matriz_A[i][j] << " ";
            if (matriz_A[i][j] % 2 == 0)
            {
                soma++;
            }
        }
        cout << endl;
    }
    cout << "o total de numeros pares na Matriz e " << soma << endl;

    return 0;
}