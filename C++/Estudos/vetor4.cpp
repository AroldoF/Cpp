#include <iostream>
#include <random>
using namespace std;
int main()
{
    int vet[15];
    int a, i;
    for (i = 0; i < 15; i++)
    {
        vet[i] = rand() % 16;
        cout << vet[i] << endl;
    }
    for (a = 0; a < 15; a++)
    {
        for (i = 0; i < 15; i++)
        {
            if (vet[a] == vet[i] && a != i)
            {
                cout << "O numero " << vet[a] << " no vetor " << a << " aparecec no vetor " << i << endl;
            }
        }
    }
    return 0;
}