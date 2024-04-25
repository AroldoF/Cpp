#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cout<<"Digite o numero de repeticoes do codigo\n";
    cin >> a;
    b = 0;
    for (size_t i = 1; i <= a; i++)
    {
        if (i % 2 != 0)
        {
            b = b + i;
        }
    }
    cout <<"A soma dos numeros inpares dentro do numero de repeticoes que voce pediu sera: " << b <<endl;
    return 0;
}