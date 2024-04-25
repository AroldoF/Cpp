#include <iostream>
using namespace std;
int main()
{
    float sf, vdv, ns, sb;
    cout << "Digite o salario fixo do funcionario:\n";
    cin >> sf;
    cout << "Digite o valor das vendas efetuadas pelo funcionario:\n";
    cin >> vdv;
    ns = (0.03 * vdv) + sf;
    if (vdv > 1500)
    {
        sb = (0.05 * (vdv - 1500)) + ns;
        cout << "o salario do funcionario nesse mes sera: " << sb << endl;
    }
    else
        cout << "o salario do funcionario nesse mes sera: " << ns << endl;
}