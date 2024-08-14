#include <iostream>
#include <stdlib.h>
using namespace std;

void matriz_aleatoria(int colunas, int linhas, int x[][10])
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            x[i][j] = rand() % 10;
        }
    }
}

void Quest01(int x[][10], int y[][10], int result[][10])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = x[i][j] + y[i][j];
        }
    }
}

void Quest02(int x[7][10], int y[7][10], int result[7][2])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                result[i][j] = x[i][0];
            }
            else
                result[i][j] = y[i][0];
        }
    }
}

void Quest04(int x[10][10], int result[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            switch (j)
            {
            case 0:
                result[i][j] = x[i][0] + 5; // Adiciona 5 ao valor de x[i][0]
                break;
            case 1:
            {
                // Calcula o fatorial de x[i][0]
                int fatorial = 1;
                for (int k = x[i][0]; k > 0; k--)
                {
                    fatorial *= k;
                }
                result[i][j] = fatorial;
                break;
            }
            default:
                result[i][j] = x[i][0] * x[i][0]; // Calcula o quadrado de x[i][0]
                break;
            }
        }
    }
}

int main()
{
    int i, j;
    int mat01[5][10], mat02[5][10];
    int result[5][10];
    int linhas = 5;
    int colunas = 3;

    matriz_aleatoria(colunas, linhas, mat01);
    matriz_aleatoria(colunas, linhas, mat02);

    cout << "LETRA A:\n"
         << endl;
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            cout << mat01[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            cout << mat02[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    Quest01(mat01, mat02, result);

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nLETRA B:\n"
         << endl;
    int m[7][10], n[7][10], r[7][2];
    linhas = 7;
    colunas = 1;

    matriz_aleatoria(colunas, linhas, m);
    matriz_aleatoria(colunas, linhas, n);
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 1; j++)
        {
            cout << m[i][j] << " ";
            cout << n[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    Quest02(m, n, r);
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nLETRA C:\n"
         << endl;
    linhas = 4;
    colunas = 5;
    matriz_aleatoria(colunas, linhas, m);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nLETRA D:\n"
         << endl;
    colunas = 3;
    linhas = 10;
    matriz_aleatoria(colunas, linhas, m);
    // Quest04(m,result);
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
