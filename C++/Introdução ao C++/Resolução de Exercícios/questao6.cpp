#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float v, c, l, a;
    cout << "Digite o Comprimento! \n";
    cin >> c;
    cout << "Digite a largura! \n";
    cin >> l;
    cout << "Digite a altura! \n";
    cin >> a;
    v = c * l * a;
    cout << "O Volume e: \n"
         << v;
    return 0;
}