#include <iostream>
using namespace std;
int main()
{
    int i, soma = 0, media;
    int vet[5];
    for (i = 0; i < 5; i++)
    {
        cout << "Digite o num do vetor " << i + 1 << ":" << endl;
        cin >> vet[i];
        soma += vet[i];
    }
    media = soma / 5;
    cout << "A soma dos numeros e " << soma << endl;
    cout << "A media dos numeros e " << media << endl;

    return 0;
}