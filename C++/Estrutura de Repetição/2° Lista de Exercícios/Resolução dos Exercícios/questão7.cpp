#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float n1, n2, n3, mex, ma;
    cout << "Digite a primeira nota do aluno:\n";
    cin >> n1;
    cout << "Digite a segunda nota do aluno:\n";
    cin >> n2;
    cout << "Digite a terceira nota do aluno:\n";
    cin >> n3;
    cout << "Digite a media de exercicios do aluno:\n";
    cin >> mex;
    // Calculo da media de aproveitamento.
    ma = (n1 + n2 * 2 + n3 * 3 + mex) / 7;
    // Classificando em A, B, C, D  utilizando o resultado da media de aproveitamento.
    if (ma >= 9)
    {
        cout << "A media de aproveitamento do aluno e um: A";
    }
    else if (ma >= 7.5)
    {
        cout << "A media de aproveitamento do aluno e um: B";
    }
    else if (ma >= 6)
    {
        cout << "A media de aproveitamento do aluno e um: C";
    }
    else
        cout << "A media de aproveitamento do aluno e um: D";
}