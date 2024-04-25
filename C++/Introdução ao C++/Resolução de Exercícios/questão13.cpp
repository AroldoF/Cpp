#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float n1, n2, n3, r;
    cout << "Insira as 3 notas do alunos: \n";
    cin >> n1 >> n2 >> n3;
    r = (n1 * 2 + n2 * 3 + n3 * 5) / (2 + 3 + 5);
    cout << "A media ponderada desse aluno e: \n"
         << r;
    return 0;
}