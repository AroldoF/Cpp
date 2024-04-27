#include <iostream>
using namespace std;
int main()
{
    int x, y, i, z = 0, maior, menor, soma = 0;
    cin >> x >> y;
    if (x >= y)
    {
        maior = x;
        menor = y;
    }
    else
    {
        maior = y;
        menor = x;
    }
    for (i = menor; i < maior; i++)
    {
        if (i % 2 != 0 && i != menor)
        {
            soma += i;
            z++;
        }
    }
    cout << soma << endl;
    return 0;
}