#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    double matriz_A[15][15];
    double soma=0;
    int i, j;

    cout << "Matriz A:" << endl;
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 15; j++)
        {
            matriz_A[i][j] = rand() % 5;
            cout << matriz_A[i][j] << " ";
            if (i==j)
            {
                soma+=matriz_A[i][j];
            }
        }
        cout << endl;
    }
    cout<<"A somatoria da DP e "<<soma<<endl;

    return 0;
}