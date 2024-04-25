#include <iostream>
using namespace std;
int main()
{
    int e;
    float b, n, v;
    // loop caso o usuario erre algum dado.
    do
    {
        cout << "Digite o numero total de eleitores do municipio \n";
        cin >> e;
        cout << "Digite o numero de votos em branco:\n";
        cin >> b;
        cout << "Digite o numero de votos nulos:\n";
        cin >> n;
        cout << "Digite o numero de votos validos:\n";
        cin >> v;
        // if para uma mensagem de erro
        if (e != b + n + v)
        {
            cout << "Dados incorretos\n";
        }
    } while (e != b + n + v);
    cout << "Porcentagem dos votos em branco " << (b * 100) / e << "%" << endl;
    cout << "Porcentagem dos votos nulos " << (n * 100) / e << "%" << endl;
    cout << "Porcentagem dos votos validos " << (v * 100) / e << "%" << endl;
    return 0;
}