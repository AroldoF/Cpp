#include <iostream>
using namespace std;
int main()
{
    int i, a,tamanho,n;
    cin>>tamanho;
    int vet[tamanho];

    for (i = 0; i < tamanho; i++)
    {
        cout<<"Digite um numero:"<<endl;
        cin>>vet[i];
    }

    cout<<"Digite o numero que voce quer remover"<<endl;
    cin>>n;

    for (i = 0; i < tamanho; i++)
    {
        if (vet[i]==n)
        {
            for (a = i; a < tamanho-1; a++)
            {
                vet[a]=vet[a+1];
            }
            tamanho-=1;
            i-=1;
        }
    }

    for (i = 0; i < tamanho; i++)
    {
        cout<<vet[i]<<endl;
    }
    
}