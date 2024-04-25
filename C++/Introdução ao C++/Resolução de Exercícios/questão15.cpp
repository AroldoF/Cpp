#include <iostream>
#include <cmath>
#include <locale.h>
using namespace std;
int main()
{
    float g, r;
    cout << "Insira o valor em graus \n";
    cin >> g;
    r = 180 / g;
    cout << "O valor em graus: " << g << endl;
    cout << "comvertendo para radianos:"
         << "pi/" << r;
    return 0;
}