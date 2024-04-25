#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int vet[20];
    int n, i, a, c = 0;
    for (i = 0; i < 20; i++)
    {
        vet[i] = rand() % 21;
    }
    cout << "digite um numero:\n";
    cin >> n;
    for (a = 0; a < 20; a++)
    {
        cout << "meu vetor " << a << " e formado pelo numero " << vet[a] << endl;
        if (vet[a] == n)
        {
            c++;
        }
    }
    cout << "O seu numero escolhido se repetiu por " << c << " vezes" << endl;
    return 0;
}