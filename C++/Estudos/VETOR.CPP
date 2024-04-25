#include <iostream>
#include <random>
using namespace std;
int main()
{
    int vet[100];
    int aux[100];
    int x, i, a = 0;
    bool variavel = false;
    cin >> x;
    for (i = 0; i < 100; i++)
    {
        vet[i] = rand() % 101;
        cout << vet[i] << endl;
    }
    for (i = 0; i < 100; i++)
    {
        if (x == vet[i])
        {
            variavel = true;
            aux[a] = i;
            a++;
        }
    }
    for (i = 0; i <a; i++)
    {
        cout << "Sua variavel X = " << x << " foi encontrada, e aparece na posicao " << aux[i] << endl;
    }
    if (variavel == false)
    {
        cout << "Sua variavel X = " << x << " nao aparece no vetor" << endl;
    }
    return 0;
}