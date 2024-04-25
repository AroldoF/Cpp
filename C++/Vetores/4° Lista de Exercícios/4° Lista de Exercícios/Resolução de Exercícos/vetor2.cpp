#include <iostream>
using namespace std;
int main()
{
    int vet[10];
    for (int i = 1; i <=10; i++)
    {
        vet[i]=i;
    }
    for (int i = 10; i >=1; i--)
    {
        cout<<"vet = " <<vet[i] <<endl;
    }
    return 0;
}