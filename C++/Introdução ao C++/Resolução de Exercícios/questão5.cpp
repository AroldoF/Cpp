#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float v, r;
    cout << "Digite o raio! \n";
    cin >> r;
    v = (4 / 3) * 3.14159 * pow(r, 3);
    cout << "Volume e: \n"
         << v;
    return 0;
}