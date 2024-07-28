#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int i, j;
    int mat01[5][3], mat02[5][3], resultado[5][3];
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 3; j++)
        {
            mat01[i][j] = rand() % 10;
            mat02[i][j] = rand() % 10;
            cout << mat01[i][j] << " ";
            cout << mat02[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j > 3; j++)
        {
            resultado[i][j]=mat01[i][j]+mat02[i][j];
            cout<<"O resultado";
        }
    }
}