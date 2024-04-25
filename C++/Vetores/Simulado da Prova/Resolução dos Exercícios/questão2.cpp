#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cin >> n;
    int vet[n];
    int menor;
    int maior;
    for (i = 0; i < n; i++)
    {
        cout << "Digite o " << i + 1 << " numero!" << endl;
        cin >> vet[i];
    }
    for (i = 0; i < n; i++)
    {
        if (i==0)
        {
            menor=vet[i];
            maior=vet[i];
        }
        if (vet[i] > maior)
        {
            maior = vet[i];
        }
        if (vet[i] < menor)
        {
            menor = vet[i];
        }
    }
cout << "Seu maior numero e " << maior << endl;
cout << "Seu menor numero e " << menor << endl;
}