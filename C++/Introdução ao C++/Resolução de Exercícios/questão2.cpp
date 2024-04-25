#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float b, a, r;
    cout << "Digite sua base! \n";
    cin >> b;
    cout << "Digite sua altura! \n";
    cin >> a;
    r = b * a;
    cout << "Sua área é: \n"
         << r;
    return 0;
}