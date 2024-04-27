#include <iostream>
using namespace std;
int main()
{
    float n;
    cout << "Digite um numero!" << endl;
    cin >> n;
    if (n <= 25 && n >= 0)
    {
        cout << "Seu numero " << n << " esta entre 0 e 25!" << endl;
    }
    else if (n > 25 && n <= 50)
    {
        cout << "Seu numero " << n << " esta entre 25 e 50!" << endl;
    }
    else if (n > 50 && n <= 75)
    {
        cout << "Seu numero " << n << " esta entre 50 e 75!" << endl;
    }
    else if (n > 75 && n <= 100)
    {
        cout << "Seu numero " << n << " esta entre 75 e 100!" << endl;
    }
    else
        cout << "Seu numero " << n << " nao esta entre 0 e 100!" << endl;
    return 0;
}