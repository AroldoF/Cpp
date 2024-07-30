#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int i, j;
    int matriz_A[7][1], matriz_B[7][1];
    int result[7][2];

    // preenchendo as matrizes
    cout << "Matriz A e B" << endl;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 1; j++)
        {
            matriz_A[i][j] = rand() % 5;
            matriz_B[i][j] = rand() % 5;
            cout << matriz_A[i][j] << " ";
            cout << matriz_B[i][j] << " ";
        }
        cout << endl;
    }

    // preenchendo o resultado
    cout << "matriz final" << endl;
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                result[i][j] = matriz_A[i][0];
            }
            else
                result[i][j] = matriz_B[i][0];
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}