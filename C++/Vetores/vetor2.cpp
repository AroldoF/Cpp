#include <iostream>
using namespace std;
int main()
{
    //declarando variaveis
    int x, i, j = 0, k = 0, l = 0, y = 0;
    
    // coletando um numero impar
    do
    {
        cout << "Digite um numero impar:" << endl;
        cin >> x;
        if (x % 2 == 0)
        {
            cout << "Seu numero nao e impar!!!" << endl;
        }
    } while (x % 2 == 0);

    // calculando o numero de rodadas do codigo!
    for (i = 1; i <= x; i++)
    {
        if (i % 2 != 0)
        {
            y++;
        }
    }

    // codigo para o triângulo invertido!
    cout << "========================================" << endl;
    do
    {
        for (i = 1 + j; i <= x - j; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        j++;
        for (i = 0; i <= j + k; i++)
        {
            cout << " ";
        }
        k++;
        l++;
    } while (l != y);

    return 0;
}