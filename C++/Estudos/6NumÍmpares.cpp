#include <iostream>
using namespace std;
int main()
{
    int n, i, z = 0;
    cout << "Digite um numero!" << endl;
    cin >> n;
    int vet[6];
    i = n;
    do
    {
        if (i % 2 != 0 && i != n)
        {
            vet[z] = i;
            z++;
        }
        i++;
    } while (z < 6);
    cout << "Os numeros impares depois do numero " << n << " serao os numeros:" << endl;
    for (i = 0; i < 6; i++)
    {
        cout << vet[i] << " ";
    }

    return 0;
}