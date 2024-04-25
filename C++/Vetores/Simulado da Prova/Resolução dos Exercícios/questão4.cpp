#include <iostream>
using namespace std;
int main()
{
    int n,i,a,z=0,x=1;
    cin>>n;
    int vet[n];
    for (i = 0; i <n; i++)
    {
        cout<<"Digite seu " <<i+1<<" numero!"<<endl;
        cin>>vet[i];
    }
    cout<<"Digite o numero que quer remover"<<endl;
    cin>>a;
    cout<<"Seu vetor reorganizado sera:"<<endl;
    for (i = 0; i <n-x; i++)
    {
        if (vet[i]==a)
        {
            for (z = i; z <n-x; z++)
            {
                vet[z]=vet[z+1];
            }
            n--;
            i--;
        }
    }
    for (i = 0; i <n; i++)
    {
        cout<<vet[i]<<endl;
    }
    
}