#include <iostream>
using namespace std;
int main()
{
    float n,y,z;
    n=0;
    z=0;
    for (size_t i = 15; i <=100; i++)
    {
        n=n+i;
        z++;
    }
    y=n/z;
    cout<<"A media dos numeros inteiros de 15 a 100 e: " <<y <<endl;
    return 0;
}