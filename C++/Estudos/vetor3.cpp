#include <iostream>
#include <random>
using namespace std;
int main()
{
    int vet[20];
    int i, a=0, n;
    cout<<"Digite um numero!"<<endl;
    cin>>n;
    for (i = 0; i < 20; i++)
    {
        vet[i]=rand()%21;
        cout<<vet[i]<<endl;
    }
    for (i = 0; i <20; i++)
    {
        if (vet[i]==n)
        {
            a++;
        }
    }
    cout<<"Seu numero aparece "<<a<<" vezes"<<endl;
    return 0;
}