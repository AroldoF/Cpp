#include <iostream>
using namespace std;
int main()
{
    int x,y,i,soma=0;
    int maior, menor;
    cin>>x>>y;
    maior=max(x,y);
    menor=min(x,y);
    for (i = menor; i <=maior; i++)
    {
        if (i%13==0)
        {}
        else
        soma+=i;
    }
    cout<<soma<<endl;
    return 0;
}