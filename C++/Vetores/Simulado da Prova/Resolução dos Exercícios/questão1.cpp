#include <iostream>
using namespace std;
int main()
{
    int a,i=0; 
    double b = 0, c = 0, soma = 0, z = 0, mediap;
    cout << "Digite a quantidade de notas!" << endl;
    cin >> a;
    double vet[a];
    double peso[a];
    double media[a];
    for (i = 0; i < a; i++)
    {
        cout<<"Digite a nota!" <<endl;
        cin >> vet[i];
        soma += vet[i];
        cout << "Digite o peso de cada nota!" << endl;
        cin >> peso[i];
        c += peso[i];
    }
    for (i = 0; i < a; i++)
    {
        media[i] = vet[i] * peso[i];
        z += media[i];
    }
    b = soma / a;
    mediap = z / c;
    cout << "a media aritimetica e: " << b << endl;
    cout << "a media poderada e: " << mediap << endl;
    return 0;
}