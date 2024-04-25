#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int h1, h2, m1, m2, hv, mv, hn, mn;
    // loop para a idade dos homens ficarem diferentes.
    do
    {
        cout << "Digite a idade do primeiro homem:\n";
        cin >> h1;
        cout << "Digite a idade do segundo homem:\n";
        cin >> h2;
        if (h1 == h2)
        {
            cout << "Digites homens com idades diferentes!\n";
        }
    } while (h1 == h2);
    // loop para a idade das mulheres ficarem diferentes.
    do
    {
        cout << "Digite a idade da primeira mulher:\n";
        cin >> m1;
        cout << "Digite a idade da segunda mulher:\n";
        cin >> m2;
        if (m1 == m2)
        {
            cout << "Digites mulheres com idades diferentes!\n";
        }
    } while (m1 == m2);
    // codigo para especificar quem é o mais novo e quem é o mais velho.
    if (h1 > h2 && m1 > m2)
    {
        hv = h1;
        hn = h2;
        mv = m1;
        mn = m2;
    }
    else
    {
        hv = h2;
        hn = h1;
        mv = m2;
        mn = m1;
    }
    cout << "A soma das idades do homem mais velho com a mulher mais nova:" << hv + mn << endl;
    cout << "O produto das idades do homem mais novo com a mulher mais velha:" << hn * mv << endl;
    return 0;
}