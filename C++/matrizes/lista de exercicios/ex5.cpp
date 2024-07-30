#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int i,j;
    int matriz_A[12][1],matriz_B[12][1];
    int result[12][2];

    cout<<"Matriz A:"<<endl;
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 1; j++)
        {
            matriz_A[i][j]=rand()%6;
            cout<<matriz_A[i][j]<<" ";
        } 
    }

    cout<<"\nMatriz B:"<<endl;
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 1; j++)
        {
            matriz_B[i][j]=rand()%6;
            cout<<matriz_B[i][j]<<" ";
        } 
    }

    cout<<"\nMatriz C:"<<endl;
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (j==0)
            {
                result[i][j]=matriz_A[i][0]*2;
            }
            else
            {
                result[i][j]=5-matriz_B[i][0];
            }
            cout<<result[i][j]<<" ";
        }
        cout<<endl; 
    }
    
    return 0;
}