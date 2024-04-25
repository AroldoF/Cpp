#include <iostream>
using namespace std;
int main()
{
    int impar[10], par[10];
    int todo[20];
    int i=0,a=0;
    for (i = 0; i <10; i++)
    {
        par[i]=i*2;
        impar[i]=(i*2)+1;
    }
    i=0;
    for (a = 0; a <10; a++)
    {
        todo[a*2]=par[i];
        todo[(a*2)+1]=impar[i];
        i++;
    }
    for (size_t i = 0; i < 20; i++)
    {
        cout<<todo[i]<<endl;
    }
    
    return 0;
}