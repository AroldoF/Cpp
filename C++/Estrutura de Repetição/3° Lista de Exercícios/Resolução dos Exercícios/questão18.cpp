#include <iostream>
using namespace std;
int main()
{
    float n, p;
    n=0;
    for (size_t i = 0; i < 10; i++)
    {
        cout<<"Digite um valor!\n";
        cin>>p;
        if (p<40)
        {
            n=n+p;
        }
    }
    if (n==0)
    {
        cout<<"Nao houve soma, pois todos os numeros eram maiores que 40!\n";
    }
    else
        cout<<"A soma dos numeros inferiores a 40 e: " <<n <<endl;
    return 0;
}