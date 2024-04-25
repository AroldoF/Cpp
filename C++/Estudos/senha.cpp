#include <iostream>
using namespace std;
int main()
{
    int cod, codcerto=1234;
    int senha, senhacerta=9999;
    do
    {
        cout<<"Digite o Codigo do Usuario" <<endl;
        cin>>cod;
        if (cod!=codcerto)
            cout<<"Usuário inválido!"<<endl;
        else
            cout<<"Usuário Valido!"<<endl;
    } while (cod!=codcerto);
    do
    {
        cout<<"Digite a Senha" <<endl;
        cin>>senha;
        if (senha!=senhacerta)
            cout<<"Senha incorreta!"<<endl;
        else
            cout<<"Acesso Permitido"<<endl;
    } while (senha!=senhacerta);
    
    return 0;
}