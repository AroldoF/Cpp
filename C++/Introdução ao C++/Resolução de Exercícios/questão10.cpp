#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float sm, r, sr;
    cout << "Insira o salario mensal \n";
    cin >> sm;
    cout << "Insira a porcentagem do reajuste \n";
    cin >> r;
    sr = (r * sm) / 100;
    cout << "O salario reajustado e:" << sr;

    return 0;
}