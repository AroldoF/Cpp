#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float custo, final;
    cout << "Digite o custo de producao da fabrica:\n";
    cin >> custo;
    final = custo + (0.28 * custo) + (0.45 * custo);
    cout << "O valor final do produto sera: " << final << endl;
    return 0;
}