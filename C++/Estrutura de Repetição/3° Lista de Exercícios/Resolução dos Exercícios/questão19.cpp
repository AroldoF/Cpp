#include <iostream>
using namespace std;
int main()
{
    int x, y, r;
    cin>>x;
    cin>>y;
    r=0;
    if (x>y)
    {
        for (size_t i = y; i <=x; i++)
    {
        r=r+i;
    }
    }
    else if (x==y)
    {
        cout<<"a soma entre os 2 numeros(com eles inclusos) e: " <<x+y <<endl;
    }
    
    else
        for (size_t i = x; i <=y; i++)
        {
            r=r+i;
        }
    if (x!=y)
    {
        cout<<"a soma entre os 2 numeros(com eles inclusos) e: " <<r <<endl;
    }
    return 0;
}