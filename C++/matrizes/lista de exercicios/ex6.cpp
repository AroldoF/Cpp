#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int matriz_A[5][4];
    int matriz_B[5][4];
    int i, j, fatorial;

    cout << "Matriz A:" << endl;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            matriz_A[i][j] = rand() % 6;
            cout << matriz_A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matriz B:" << endl;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            fatorial = 1;
            for (int k = matriz_A[i][j]; k > 0; k--)
            {
                fatorial *= k;
            }
            matriz_B[i][j] = fatorial;
            cout << matriz_B[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}