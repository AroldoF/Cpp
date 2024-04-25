#include <iostream>
using namespace std;
int main()
{
    int i, a = 0, n, y = 0;
    cout << "Digite o tamanho" << endl;
    cin >> n;
    int vet[n];
    int aux[n];
    for (i = 0; i < n; i++)
    {
        cout << "Digite um numero" << endl;
        cin >> vet[i];
    }
    i = 0;
    for (a = 0; a < n; a++)
    {
        if (vet[a] == y + 1 && a != 0)
        {
            aux[i] = y;
            aux[i + 1] = vet[a];
            i += 2;
        }
        else
        y = vet[a];
    }
    cout<<"Sua sequencias de numeros seram:"<<endl;
    for (a = 0; a < i; a++)
    {
        cout << aux[a] << endl;
    }
}