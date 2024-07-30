#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int matriz_A[5][6];
    int matriz_B[5][6];
    int matriz_C[5][6];
    int i, j;

    cout<<"Matriz A:"<<endl;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
        {
            do
            {
                matriz_A[i][j] = rand() % 6;
            } while (matriz_A[i][j] % 2 != 0);
            cout << matriz_A[i][j] << " ";
        }
        cout << endl;
    }

    cout<<"Matriz B:"<<endl;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
        {
            do
            {
                matriz_B[i][j] = rand() % 6;
            } while (matriz_B[i][j] % 2 == 0);
            cout << matriz_B[i][j] << " ";
        }
        cout << endl;
    }

    cout<<"Matriz C:"<<endl;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
        {
            matriz_C[i][j]=matriz_A[i][j]+matriz_B[i][j];
            cout<<matriz_C[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}