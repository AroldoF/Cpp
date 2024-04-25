#include <iostream>
using namespace std;
int main()
{
    int n;
    n = 0;
    for (size_t i = 1; i <= 1000; i++)
    {
        if (i % 2 == 0)
            n = n + i;
    }
    cout << "A soma de todos os numeros para de 1 a 1000 e: " << n << endl;
    return 0;
}