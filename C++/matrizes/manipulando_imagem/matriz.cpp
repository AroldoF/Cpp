#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int imagem[10][10];
    int manipulação[10][10];
    int matriz[2][2] = {
        {1, 1},
        {1, 1}};
    int i, j, k, z;

    cout << "Imagem sem filtro" << endl;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            imagem[i][j] = 1;
            cout << imagem[i][j] << " ";
        }
        cout << endl;
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            manipulação[i][j] = 0;
            for (k = 0; k < 2; k++)
            {
                for (z = 0; z < 2; z++)
                {
                    if (i + k < 10 && j + z < 10)
                    {
                        manipulação[i][j] += imagem[k + i][z + j] * matriz[k][z];
                    }
                }
            }
        }
    }

    cout << "\nImagem com filtro" << endl;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            cout << manipulação[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}