#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int i, j, fatorial;
    int matriz_A[10][1];
    int result[10][3];

    cout << "Matriz A:" << endl;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 1; j++)
        {
            matriz_A[i][j] = rand() % 5;
            cout << matriz_A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Resultado da matriz:" << endl;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 3; j++)
        {
            switch (j)
            {
            case 0:
                result[i][j] = matriz_A[i][0] + 5;
                break;
            case 1:
                fatorial = 1;
                for (int k = matriz_A[i][0]; k > 0; k--)
                {
                    fatorial *= k;
                }
                result[i][j] = fatorial;
                break;
            default:
                result[i][j] = matriz_A[i][0] * matriz_A[i][0];
                break;
            }
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}