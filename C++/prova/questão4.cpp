#include <iostream>
using namespace std;
int main()
{
    int x, i;
    int vet[8];

    for (i = 0; i < 8; i++)
    {
        cout << "Digite o num do vetor " << i << ":" << endl;
        cin >> vet[i];
    }

    cout << "Digite o numero q deseja encontrar:" << endl;
    cin >> x;

    for (i = 0; i < 8; i++)
    {
        if (x == vet[i])
        {
            cout << x << " Aparece no meu vet[" << i << "]" << endl;
        }
    }

    return 0;
}