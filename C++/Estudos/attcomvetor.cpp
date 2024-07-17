#include <iostream>
using namespace std;
int main()
{
    int i;
    string nome[10];
    double preço[10], ttpg;
    for (i = 0; i < 10; i++)
    {
        cout << "Digite o nome do produto:" << endl;
        cin >> nome[i];
        cout << "Digite o preço do produto:" << endl;
        cin >> preço[i];
    }
    cout << "===============================================" << endl;
    cout << "Digite o maximo do valor do produto que deseja:" << endl;
    cout << "===============================================" << endl;
    cin >> ttpg;
    for (i = 0; i < 10; i++)
    {
        if (ttpg >= preço[i])
        {
            cout << nome[i] << " " << double(preço[i]) << "R$" << endl;
        }
    }
}