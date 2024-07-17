#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    //revisão de estruturas condicionais e fluxogramas
    int a, b, c, d;
    double e;
    a = 3;
    b = 3;
    c = 4;
    c = a * b;
    if (a < c)
    {
        d = sqrt(c);
        if (d % 2 == 0)
        {
            cout << "Fim do programa" << endl;
        }
        else
        {
            e = sqrt(d * b * pow(a, 2) * sqrt(d));
            if (d >= e)
            {
                cout << "Imprimindo D= " << d << endl;
            }
            else
            {
                cout << "Imprimindo E= " << e << endl;
            }
        }
    }
    else
        cout << a << " Fim do programa!" << endl;
}