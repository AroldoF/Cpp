#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    n = 0;
    for (size_t i = 1; i <=100; i++)
    {
        if(i % 2 != 0)
        {
        n= n+i;
        }
    }
    cout<<"A soma dos numeros impares de 1 a 100 e: " <<n <<endl;
    return 0;
}