#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float f, c;
    cout << "Digite sua temperatura em Celsius! \n";
    cin >> c;
    f = c * 9 / 5 + 32;
    cout << "Temperatura em Fahrenheit!\n"
         << f;
    return 0;
}