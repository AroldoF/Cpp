#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float rb, rn, rv, nt, nb, nv, nn;
    cout << "Para descobrir o percentual, forneça dados: \n";
    cout << "Digite o numero de votos em branco: \n";
    cin >> nb;
    cout << "Digite o numero de votos nulos: \n";
    cin >> nn;
    cout << "Digite o numero de votos validos: \n";
    cin >> nv;
    nt = nb + nn + nv;
    rb = (nb / nt) * 100;
    rn = (nn / nt) * 100;
    rv = (nv / nt) * 100;
    cout << "Numero total de eleitores " << nt << endl;
    cout << "Percentual do numero de votos em branco:" << rb << "%" << endl;
    cout << "Percentual do numero de votos nulos:" << rn << "%" << endl;
    cout << "Percentual do numero de votos validos:" << rv << "%" << endl;

    return 0;
}