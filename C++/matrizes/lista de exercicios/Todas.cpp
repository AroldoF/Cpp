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

void mostrar(int colunas, int linhas, int x[][10])
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Quest01(int x[][10], int y[][10], int result[][3])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j] = x[i][j] + y[i][j];
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
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
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Quest04(int x[10][10], int result[10][3])
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
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Quest05(int x[12][10], int result[12][2])
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                result[i][j] = x[i][0] * 2;
            }
            else
            {
                result[i][j] = x[i][0] - 5;
            }
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Quest06(int x[][10], int result[][4])
{
for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int fatorial = 1;
            for (int k = x[i][j]; k > 0; k--)
            {
                fatorial *= k;
            }
            result[i][j] = fatorial;
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

void Quest07(int x[][10], double result[][5])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            result[i][j] = x[i][j] * 1.8 + 32;
            cout << result[i][j] << "F ";
        }
        cout << endl;
    }
    cout<<endl;
}

void Quest08(int x[][10], int result[][5])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i==j)
            {
                result[i][j]=x[i][j]*3;
            }
            else
                result[i][j]=x[i][j]*2;
            cout<<result[i][j]<<" ";
        }
        cout << endl;
    }
    cout<<endl;
}

void Quest09(int x[][10], int result[][7])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (i == j && i % 2 != 0)
            {
                int fatorial = 1;
                for (int k = x[i][j]; k > 0; k--)
                {
                    fatorial *= k;
                }
                result[i][j] = fatorial;
            }
            else
            {
                int soma = 0;
                for (int k = 1; k <= x[i][j]; k++)
                {
                    soma += k;
                }
                result[i][j] = soma;
            }

            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

void Quest10(int x[][10],int result[][5])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (x[i][j] % 2 == 0)
            {
                result[i][j] = x[i][j] + 5;
            }
            else
                result[i][j] = x[i][j] - 4;
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

int main()
{
    int i, j;
    int matriz_A1[5][10], matriz_A2[5][10];
    int result_A[5][3];
    int linhas = 5;
    int colunas = 3;

    cout << "LETRA A:"<< endl;
    matriz_aleatoria(colunas, linhas, matriz_A1);
    matriz_aleatoria(colunas, linhas, matriz_A2);
    mostrar(colunas, linhas, matriz_A1);
    mostrar(colunas, linhas,matriz_A2);
    Quest01(matriz_A1, matriz_A2, result_A);
    
    cout << "\nLETRA B:\n"<< endl;
    int matriz_B1[7][10], matriz_B2[7][10]; 
    int result_B[7][2];
    linhas = 7;
    colunas = 1;
    matriz_aleatoria(colunas, linhas, matriz_B1);
    matriz_aleatoria(colunas, linhas, matriz_B2);
    mostrar(colunas,linhas,matriz_B1);
    mostrar(colunas,linhas,matriz_B2);
    Quest02(matriz_B1, matriz_B2, result_B);

    cout << "LETRA C:"<< endl;
    int matriz_C[4][10];
    linhas = 4;
    colunas = 5;
    matriz_aleatoria(colunas, linhas, matriz_C);
    mostrar(colunas, linhas,matriz_C);

    cout << "LETRA D:"<< endl;
    int matriz_D[10][10];
    int result_D[10][3];
    colunas = 1;
    linhas = 10;
    matriz_aleatoria(colunas, linhas, matriz_D);
    mostrar(colunas,linhas,matriz_D);
    Quest04(matriz_D, result_D);

    cout << "LETRA E:"<< endl;
    int matriz_E[12][10], result_E[12][2];
    colunas = 1;
    linhas = 12;
    matriz_aleatoria(colunas, linhas, matriz_E);
    mostrar(colunas, linhas, matriz_E);
    Quest05(matriz_E, result_E);
    
    cout<<"LETRA F:"<<endl;
    int matriz_F[5][10];
    int result_F[5][4];
    linhas=5;
    colunas=4;
    matriz_aleatoria(colunas,linhas,matriz_F);
    mostrar(colunas,linhas,matriz_F);
    Quest06(matriz_F, result_F);

    cout<<"LETRA G:"<<endl;
    int matriz_G[4][10];
    double result_G[4][5];
    linhas=4;
    colunas=5;
    matriz_aleatoria(colunas,linhas,matriz_G);
    mostrar(colunas,linhas,matriz_G);
    Quest07(matriz_G,result_G);

    cout<<"LETRA H:"<<endl;
    int matriz_H[5][10];
    int result_H[5][5];
    linhas=5;
    colunas=5;
    matriz_aleatoria(colunas,linhas,matriz_H);
    mostrar(colunas,linhas,matriz_H);
    Quest08(matriz_H,result_H);

    cout<<"LETRA I:"<<endl;
    int matriz_I[7][10];
    int result_I[7][7];
    linhas=7;
    colunas=7;
    matriz_aleatoria(colunas,linhas,matriz_I);
    mostrar(colunas,linhas,matriz_I);
    Quest09(matriz_I,result_I);

    cout<<"LETRA J:"<<endl;
    int matriz_J[6][10];
    int result_J[6][5];
    linhas=6;
    colunas=5;
    matriz_aleatoria(colunas,linhas,matriz_J);
    mostrar(colunas,linhas,matriz_J);
    Quest10(matriz_J,result_J);

    return 0;
}
