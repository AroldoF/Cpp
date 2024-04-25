#include <iostream>
using namespace std;
int main()
{
    float a,b,r;
    cout<<"Digite o valor de A:\n";
    cin>>a;
    cout<<"Digite o valor de B:\n";
    cin>>b;
    if (b==0)
    {
        for (size_t i = 0; i <100000; i++)
        {
            cout<<"De um valor diferente de 0 para B\n";
            cout<<"Digite o valor de B:\n";
            cin>>b;
            if(b!=0)
            {
                break;
            }
        }
    }
    r=a/b;
    cout<<"A divisao de A e B sera: " <<r <<endl;
    return 0;
}