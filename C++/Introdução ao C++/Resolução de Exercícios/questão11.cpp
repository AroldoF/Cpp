#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float cf, im, pd, pdf;
    cout << "Insira o custo de produçao do carro \n";
    cin >> cf;
    im = (45 / cf) * 100;
    pd = (28 / cf) * 100;
    pdf = cf + pd + im;
    cout << "O valor final do carro e:" << pdf;
    return 0;
}