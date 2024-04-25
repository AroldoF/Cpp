#include <iostream>
using namespace std;
int main()
{
    float vet[4];
    float m;
    float soma;
    for (int i = 0; i <4; i++)
    {
        cin>>vet[i];
        soma+=vet[i];
    }
    m=soma/4;
    cout<<m <<endl;
}