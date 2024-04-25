#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int main()
{
    int d, m, a, r;
    cout << "Para saber sua idade em dias, Digite: \n";
    cout << "Sua idade em anos: \n";
    cin >> a;
    cout << "retirando  sua idade em anos, quantos meses voce tem: \n";
    cin >> m;
    cout << "retirando  sua idade em anos e em meses, quantos dias voce tem: \n";
    cin >> d;
    r = (a * 365) + (m*30) + d;
    cout << "Sua idade em dia e: \n"
         << r;
    return 0;
}