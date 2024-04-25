#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int vet[20];
    int n, i, a;
    do
    {
        for (i = 0; i < 20; i++)
        {
            vet[i] = rand() % 21;
        }
        cout << "digite um numero: " << endl;
        cin>>n;
        for (a = 0; a < 20; a++)
        {
            cout << "meu vetor " << a << " e formado pelo numero " << vet[a] << endl;
            if (vet[a] == n)
            {
                cout << "Seu numero esta presente no vetor, forneca outro numero aleatorio: " << endl;
                cout<<"digite outro numero!" <<endl;
                break;
            }
        }
    } while (n == vet[a]);
    cout << "seu numero e valido, pois nao esta presente no vetor!" << endl;
    return 0;
}