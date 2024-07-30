#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int matriz_A[7][7];
    int matriz_B[7][7];
    int i, j, k, fatorial, soma;

    cout << "Matriz A:" << endl;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            matriz_A[i][j] = rand() % 6;
            cout << matriz_A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matriz B:" << endl;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            if (i == j && i % 2 != 0)
            {
                fatorial = 1;
                for (k = matriz_A[i][j]; k > 0; k--)
                {
                    fatorial *= k;
                }
                matriz_B[i][j] = fatorial;
            }
            else
            {
                soma = 0;
                for (k = 1; k <= matriz_A[i][j]; k++)
                {
                    soma += k;
                }
                matriz_B[i][j] = soma;
            }

            cout << matriz_B[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}