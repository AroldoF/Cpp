#include <iostream>
using namespace std;
int main()
{
    int n,i,z=0,a=0;
    cout<<"Digite o tamanho do vetor"<<endl;
    cin>>n;
    int vet[n];
    int aux[n];
    for (i = 0; i <n; i++)
    {
        cout<<"Digite o "<<i+1<<" numero"<<endl;
        cin>>vet[i];
    }
    for (i = 0; i <n; i++)
    {
        if (vet[i-1]+vet[i-2]==vet[i]&&i>=2)
        {
            aux[z]=vet[i-2];
            aux[z+1]=vet[i-1];
            aux[z+2]=vet[i];
            z+=3;
        }
    }
    for (i = 0; i <z; i++)
    {
        cout<<aux[i]<<endl;
    }
    return 0;
}