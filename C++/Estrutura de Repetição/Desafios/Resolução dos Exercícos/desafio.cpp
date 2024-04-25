#include <iostream>
using namespace std;
int main()
{
    int n, z, i;
    do
    {
        cout << "Digite um numero\n";
        cin >> n;
        z = 0;
        for (i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                z++;
            }
        }
        if (z == 2)
        {
            cout << "Seu numero e primo\n";
            break;
        }
        else
        cout<<"Seu numero nao e primo\n";
    } while (true);
    return 0;
}