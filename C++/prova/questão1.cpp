#include <iostream>
using namespace std;
int main()
{
    int i, par = 0, impar = 0;
    int vet[10];
    for (i = 0; i < 10; i++)
    {
        cout << "Digite o num do vetor " << i + 1 << ":" << endl;
        cin >> vet[i];
    }
    for (i = 0; i < 10; i++)
    {
        if (vet[i] % 2 == 0)
        {
            par++;
        }
        else
        {
            impar++;
        }
    }
    cout << "Foram " << par << " numeros pares" << endl;
    cout << "Foram " << impar << " numeros impares" << endl;

    return 0;
}