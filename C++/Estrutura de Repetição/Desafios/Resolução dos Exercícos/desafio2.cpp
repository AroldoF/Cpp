#include <iostream>
using namespace std;
int main()
{
    int soma, aux, i, a, totalp, contagem;
    soma = 0;
    i = 1;
    contagem = 0;
    cout<<"Digite a quantidade de numeros primos que deseja:\n";
    cin >> totalp;
    do
    {
        i++;
        aux = 0;
        for (a = 1; a <= i; a++)
        {
            if (i % a == 0)
            {
                aux++;
            }
        }
        if (aux == 2)
        {
            cout << i << endl;
            soma += i;
            contagem++;
        }
        if (contagem == totalp)
        {
            break;
        }
    } while (true);
    cout << soma;
}