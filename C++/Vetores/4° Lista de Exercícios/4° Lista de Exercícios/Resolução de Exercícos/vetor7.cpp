#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int vetor[10];
    int limite=10;
    for (int i = 0; i < 10; i++)
    {
        vetor[i]=rand()%(limite+1);
    }
    cout<<"digite um valor:\n";
    cin>>vetor[8];
    int x=vetor[8];
    for (int i = 0; i <10; i++)
    {
        cout<<"memoria do vetor= "<<vetor[i]<<endl;
        if (vetor[8]==i||x==vetor[i])
        {
            cout<<"achei " <<vetor[i] <<endl;
            break;
        }
    }
    return 0;
}