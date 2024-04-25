#include <iostream>
using namespace std;
int main()
{
    float a1, a2, m;
    do
    {
        cout << "Digite a primeita nota\n";
        cin >> a1;
        if (a1 < 0 || a1 > 10)
        {
            cout << "Numero invalido!\n";
        }
    } while (a1 < 0 || a1 > 10);
    do
    {
        cout << "Digite a segunda nota\n";
        cin >> a2;
        if (a2 > 10 || a2 < 0)
        {
            cout << "Numero invalido!\n";
        }
    } while (a2 > 10 || a2 < 0);
    m = (a1 + a2) / 2;
    cout << "A media do aluno e: " << m << endl;
    return 0;
}
