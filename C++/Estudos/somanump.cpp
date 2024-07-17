#include <iostream>
using namespace std;
int main()
{
    int x,soma=0,saida=0;
    cin>>x;
    do
    {
        if (x%2==0&&x>0)
        {
            soma+=x;
            saida++;
        }
        x++;
    } while (saida!=5&&x>0);
    cout<<soma<<endl;
    
    return 0;
}