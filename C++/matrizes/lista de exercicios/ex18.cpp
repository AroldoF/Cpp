#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int matriz_A[4][1];
    int matriz_B[4][1];
    int matriz_C[4][1];
    int matriz_D[4][1];
    int result[4][4];
    int i, j, fatorial;

    cout << "Matrizes A, B, C e D:" << endl;
    for (i = 0; i < 4; i++)
    {
        matriz_A[i][0] = rand() % 5;
        cout<<matriz_A[i][0]<<" ";
        matriz_B[i][0] = rand() % 5;
        cout<<matriz_B[i][0]<<" ";
        matriz_C[i][0] = rand() % 5;
        cout<<matriz_C[i][0]<<" ";
        matriz_D[i][0] = rand() % 5;
        cout<<matriz_D[i][0]<<" ";
        cout<<endl;
    }

    cout<<"Matriz E:"<<endl;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            switch (j)
            {
            case 0:
                result[i][j] = matriz_A[i][0] * 2;
                break;
            case 1:
                result[i][j] = matriz_B[i][0] * 3;
                break;
            case 2:
                result[i][j] = matriz_C[i][0] * 4;
                break;
            default:
                fatorial = 1;
                for (int k = matriz_D[i][0]; k > 0; k--)
                {
                    fatorial *= k;
                }
                result[i][j]=fatorial;
                break;
            }
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}