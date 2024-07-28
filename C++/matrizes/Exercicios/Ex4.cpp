#include <iostream>
using namespace std;

int main()
{
    int m, p, n, i, j, k;
    cout << "Digite os valores de m, p e n: ";
    cin >> m >> p >> n;

    int matrizA[m][p];
    int matrizB[p][n];
    int matrizM[m][n];

    cout << "Matriz A:" << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            matrizA[i][j] = rand() % 3;
            cout << matrizA[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matriz B:" << endl;
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < n; j++)
        {
            matrizB[i][j] = rand() % 3;
            cout << matrizB[i][j] << " ";
        }
        cout << endl;
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            matrizM[i][j] = 0;
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            matrizM[i][j] = 0;
            for (k = 0; k < p; k++)
            {
                matrizM[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    cout << "Matriz M:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrizM[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}