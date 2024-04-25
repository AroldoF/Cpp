#include <iostream>
#include <random>
using namespace std;
int main()
{
    int vet[20];
    int i, n, a;
    for (i = 0; i < 20; i++)
    {
        vet[i] = rand() % 21;
        cout << vet[i] << endl;
    }
    cout << "Digite um numero!" << endl;
    cin >> n;
    do
    {
        a = 0;
        for (i = 0; i < 20; i++)
        {
            if (vet[i] == n)
            {
                vet[i] = rand() % 101;
                cout << "Seu numero se repete na posiçao " << i << endl;
                cout << "Seu novo numeto nesta posicao sera: " << vet[i] << endl;
                a++;
            }
        }
    } while (a != 0);
    cout<<"Seu numero nao esta no vetor"<<endl;
    return 0;
}