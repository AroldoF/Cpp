#include <iostream>
using namespace std;
int main()
{
    int i, maior = 0, n = 0;
    int vet[10];
    
    for (i = 0; i < 10; i++)
    {
        cout << "Digite o num do vetor " << i + 1 << ":" << endl;
        cin >> vet[i];
    }

    for (i = 0; i < 10; i++)
    {
        if (maior < vet[i] || i == 0)
        {
            maior = vet[i];
        }
    }

    for (i = 0; i < 10; i++)
    {
        if ((vet[i] > n || i == 0) && vet[i] < maior)
        {
            n = vet[i];
        }
    }

    cout << "O segundo maior e " << n << endl;

    return 0;
}