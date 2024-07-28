#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int m, p, n, i, j, k = 0, limite, x = 0;
    cout << "m, p e n" << endl;
    cin >> m >> p >> n;
    int matrizA[m][p];
    int matrizB[p][n];
    int matrizM[m][n];

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            matrizA[i][j] = rand() % 11;
            cout << matrizA[i][j] << " ";
        }
    }
    cout << endl;
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < n; j++)
        {
            matrizB[i][j] = rand() % 11;
            cout << matrizB[i][j] << " ";
        }
    }

    cout << endl;
    limite = p;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            matrizM[i][j] = matrizA[i][k] * matrizB[x][j];
            if (i == m - 1 && j == n - 1)
            {
                matrizM[i][j] = 0;
            }
            cout << "matriz [" << i << "] [" << j << "] = " << matrizM[i][j] << endl;
            if (k != limite)
            {
                k++;
            }
        }
        k = 0;
        if (x != limite)
        {
            x++;
        }
        cout << endl;
    }
    return 0;
}