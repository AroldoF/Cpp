#include <iostream>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int vet[n];
    vet[0]=0;
    vet[1]=1;
    for (i = 2; i <n; i++)
    {
        vet[i]=vet[i-1]+vet[i-2];
    }
    for (i = 0; i <n-1; i++)
    {
        cout<<vet[i]<<", ";
    }
    cout<<vet[n-1]<<endl;
    return 0;
}