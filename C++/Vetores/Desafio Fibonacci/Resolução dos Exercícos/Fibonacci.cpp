#include <iostream>
using namespace std;
int main()
{
    int n,i,z=0,a=0;
    cout<<"Digite o tamanho do vetor"<<endl;
    cin>>n;
    int vet[n];
    int aux[n];
    bool encontrado=false;
    for (i = 0; i <n; i++)
    {
        cout<<"Digite o "<<i+1<<" numero"<<endl;
        cin>>vet[i];
    }
    for (i = 0; i <n; i++)
    {
        if (aux[a]+aux[a+1]==vet[i])
        {
            aux[z]=vet[i];
            z++;
            a++;
            encontrado=true;
        }
        if (encontrado==false)
        {
            z=0;
        }
        if (encontrado==false&&i>=1)
        {
            aux[z]=vet[i-1];
            aux[z+1]=vet[i];
            z+=2;
        }
    }
    for (i = 0; i <z; i++)
    {
        cout<<aux[i]<<endl;
    }
    return 0;
}