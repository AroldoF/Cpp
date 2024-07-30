#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int matriz_A[5][5];
    int matriz_B[5][5];
    int i, j, x = 0, y = 4;

    cout << "Matriz A:" << endl;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            matriz_A[i][j] = rand() % 5;
            cout << matriz_A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matriz B:" << endl;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i == x && j == y)
            {
                matriz_B[i][j] = matriz_A[i][j] * 3;
            }
            else
                matriz_B[i][j] = matriz_A[i][j] * 2;
            cout << matriz_B[i][j] << " ";
        }
        x++;
        y--;
        cout << endl;
    }

    return 0;
}