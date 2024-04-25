#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int nc;
    float sf, sb, vdv, st;
    cout << "Digite o salario fixo do funcionario e depois bonus fixo que ele recebe por venda: \n";
    cin >> sf >> sb;
    cout << "Digite numero de carros vendidos por ele e depois valor total de suas vendas: \n";
    cin >> nc >> vdv;
    st = sf + (sb * nc) + (5 * vdv / 100) * nc;
    cout << "O salario do funcionario depois de todos os bonus sera: " << st;
    return 0;
}