#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int vetor[15];
    int a, i, z;
    for (i = 0; i < 15; i++)
    {
        vetor[i] = rand() % (16);
    }
    for (a = 0; a < 15; a++)
    {
        cout<<"O vetor "<<a <<" formado pelo numero " << vetor[a] << endl;
        for (z = 0; z < 14; z++)
        {
            if (vetor[a] == vetor[z] && z != a)
            {
                cout << "Achei, o valor " << vetor[a] << " esta armazenado no Vetor " << z << endl;
                cout << "E o numero " << vetor[a] << " tambem esta armazenado no proprio Vetor " << a << endl;
            }
        }
    }
    return 0;
}