#include <iostream>
using namespace std;
int main()
{
    float a, b, r;
    cout << "Digite o valor de A:\n";
    cin >> a;
    do
    {
        cout << "Digite o valor de B:\n";
        cin >> b;
        if (b == 0)
        {
            cout << "Valor invalido\n";
        }
    } while (b == 0);
    r = a / b;
    cout << "A divisao de A e B sera: " << r << endl;
    return 0;
}