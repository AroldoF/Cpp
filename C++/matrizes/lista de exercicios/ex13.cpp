#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    double matriz_A[5][5];
    double soma = 0;
    int i, j;

    cout << "Matriz A:" << endl;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            matriz_A[i][j] = rand() % 5;
            cout << matriz_A[i][j] << " ";
            if (i == j && i % 2 != 0)
            {
                soma += matriz_A[i][j];
            }
        }
        cout << endl;
    }
    cout << "A somatoria dos indices impares da DP e " << soma << endl;

    return 0;
}