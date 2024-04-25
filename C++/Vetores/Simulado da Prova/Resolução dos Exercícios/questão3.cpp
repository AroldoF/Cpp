#include <iostream>
using namespace std;
int main()
{
    int n,i,somapar=0,somaimpar=0;
    int vet[n];
    cin>>n;
    for (i = 0; i <n; i++)
    {
        cout<<"Digite o " <<i+1<<" numero!"<<endl;
        cin>>vet[i];
        if (vet[i]%2==0)
        {
            somapar+=vet[i];
        }
        else
        somaimpar+=vet[i];
    }
    cout<<"A soma de todos os numeros pares do seu vetor e "<<somapar<<endl;
    cout<<"A soma de todos os numeros impares do seu vetor e "<<somaimpar<<endl;
    return 0;
}