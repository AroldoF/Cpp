#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int i, j;
    int matriz[4][5];

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            matriz[i][j] = rand() % 5;
        }
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}