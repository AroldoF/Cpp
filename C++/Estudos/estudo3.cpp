#include <iostream>
using namespace std;
int main()
{
    int i,tamanho,maior,menor;
    cin>>tamanho;
    int vet[tamanho];

    for (i = 0; i < tamanho; i++)
    {
        cout<<"Digite um numero:"<<endl;
        cin>>vet[i];
        if (maior<vet[i]||i==0)
        {
            maior=vet[i];
        }
        if (menor>vet[i]||i==0)
        {
            menor=vet[i];
        }
    }
    cout<<"maior = "<<maior<<" menor = "<<menor<<endl;
}