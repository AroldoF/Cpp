#include <iostream>
using namespace std;
int main()
{
    int senha, usuario, tu, ts;
    usuario = 1234;
    // codigo para identificar o usuario.
    do
    {
        cout << "Digite o Usuario:\n";
        cin >> tu;
        if (tu != usuario)
        {
            cout << "Usuario Invalido!\n";
        }
    } while (tu != usuario);
    cout << "Usuario identificado!\n";
    senha = 9999;
    // codigo para identificar a senha.
    do
    {
        cout << "Digite a Senha:\n";
        cin >> ts;
        if (ts != senha)
        {
            cout << "Senha Incorreta!\n";
        }
    } while (ts != senha);
    cout << "Acesso permitido!\n";
    return 0;
}