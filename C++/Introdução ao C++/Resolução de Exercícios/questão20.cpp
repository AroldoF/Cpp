#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float a, b, so, ve, di, me;
    cout << "Digite A e B para as operaçoes! \n";
    cin >> a >> b; // teste se poderia receber 2 variaveis em um cin.
    so = a + b;
    me = a - b;
    ve = a * b;
    di = a / b;
    cout << "A + B = " << so << endl;
    cout << "A - B = " << me << endl;
    cout << "A * B = " << ve << endl;
    cout << "A / B = " << di << endl;
    return 0;
}