#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float pma, pmo, kgma, kgmo, vt, kgt;
    cout << "Quantos kg de morango foram comprados?\n";
    cin >> kgmo;
    cout << "Quantos kg de maca foram comprados?\n";
    cin >> kgma;
    // condições para identificar qual o valor de cada kg.
    if (kgmo <= 5)
    {
        pmo = (kgmo * 2.5);
    }
    else
    {
        pmo = kgmo * 2.2;
    }
    if (kgma <= 5)
    {
        pma = (kgma * 1.8);
    }
    else
    {
        pma = kgma * 1.5;
    }
    // calculo do valor total das compras(sem o desconto de 10%) e minhas quantidade de kg comprados.
    vt = pmo + pma;
    kgt = kgma + kgmo;
    // condições e o calculo para o desconto de 10%, e entrega do valor total a pagar.
    if (vt > 25)
    {
        vt = vt - (0.10 * vt);
        cout << "o valor a pagar vai ser:" << vt << endl;
    }
    else if (kgt > 8)
    {
        vt = vt - (0.10 * vt);
        cout << "o valor a pagar vai ser:" << vt << endl;
    }
    else
        cout << "o valor a pagar vai ser:" << vt << endl;
    return 0;
}