#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float c, f;
    cout << "Digite sua temperatura em Fahrenheit! \n";
    cin >> f;
    c = ((f - 32) * 5) / 9;
    cout << "Temperatura em Celsius!\n"
         << c;
    return 0;
}