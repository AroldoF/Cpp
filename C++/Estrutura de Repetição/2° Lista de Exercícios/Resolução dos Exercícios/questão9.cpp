#include <iostream>
using namespace std;
int main()
{
    float a, b, c, r;
    cout << "Digite 1 para usar o algoritimo ou 2 para ver as respostas da tabela!\n";
    cin >> r;
    if (r == 1)
    {
        cout << "Digite A, B e C, respectivamente.\n";
        cin >> a >> b >> c;
        if (a < b + c && b < a + c && c < a + b)
        {
            if (a == b && b == c)
            {
                cout << "Triangulo Equilatero";
            }
            else if (a == b || b == c || c == a)
            {
                cout << "Triangulo Isosceles";
            }
            else
            {
                cout << "Triangulo Escaleno";
            }
        }
        else
        {
            cout << "Nao e possivel formar um triangulo!";
        }
    }
    else
    {
        cout << "Resultado da tabela\n";
        cout << "A=1, B=2 e C= 3 pelo algoritimo nao e possivel formar um triangulo";
        cout << "A=3, B=4 e C= 5 pelo algoritimo o triangulo sera: Triangulo Escaleno";
        cout << "A=2, B=2 e C= 4 pelo algoritimo nao e possivel formar um triangulo";
        cout << "A=4, B=4 e C= 4 pelo algoritimo o triangulo sera: Triangulo Equilatero";
        cout << "A=5, B=3 e C= 3 pelo algoritimo o triangulo sera: Triangulo Isosceles";
    }
    return 0;
}