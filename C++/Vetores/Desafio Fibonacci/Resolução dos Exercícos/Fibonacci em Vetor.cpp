#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cin >> n;
    if (n == 0)
    {
        cout << "Fib(0) = 0" << endl;
    }
    else
    {
        int vet[30];
        vet[0] = 0;
        vet[1] = 1;
        for (i = 2; i < 30; i++)
        {
            vet[i] = vet[i - 1] + vet[i - 2];
        }
        for (i = 0; i < 30; i++)
        {
            if (vet[i] == n)
            {
                cout << "Fib(" << i << ") = " << n << endl;
                break;
            }
            else if (vet[i] > n)
            {
                cout << "seu numero(" << n << ") nao esta no vetor!" << endl;
                break;
            }
        }
    }
    return 0;
}