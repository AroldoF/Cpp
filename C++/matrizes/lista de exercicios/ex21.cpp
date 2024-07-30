#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int matriz_A[3][4];
    int matriz_B[3][4];
    int matriz_C[3][4];
    int i, j;

    cout << "Matriz A:" << endl;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            while (true)
            {
                matriz_A[i][j] = rand() % 16;
                if ((matriz_A[i][j] % 3 == 0 || matriz_A[i][j] % 4 == 0) && matriz_A[i][j] != 0)
                {
                    break;
                }
            }
            cout << matriz_A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matriz B:" << endl;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            while (true)
            {
                matriz_B[i][j] = rand() % 16;
                if ((matriz_B[i][j] % 5 == 0 || matriz_B[i][j] % 6 == 0) && matriz_B[i][j] != 0)
                {
                    break;
                }
            }
            cout << matriz_B[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matriz C:" << endl;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            matriz_C[i][j] = matriz_B[i][j] * matriz_A[i][j];
            cout << matriz_C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}