#include <iostream>
using namespace std;
int main()
{
    int i, a=0,tamanho;
    cin>>tamanho;
    int vet[tamanho],num[tamanho];
    bool enc=false;
    for (i = 0; i < tamanho; i++)
    {
        cout<<"Digite um numero:"<<endl;
        cin>>vet[i];
    }
    for (i = 0; i < tamanho; i++)
    {
        if (vet[i]+1==vet[i+1])
        {
            num[a]=vet[i];
            enc=true;
            a++;
        }
        else if (enc==true)
        {
            num[a]=vet[i];
            enc=false;
            a++;
        }
    }
    for (i = 0; i < a; i++)
    {
        cout<<num[i]<<endl;
    }
    
}