#include <iostream>
using namespace std;
int main()
{
    int n, p;
    p=0;
    do
    {
        cin>>n;
        if(n>0)
        {
            cout<<"Contagem do 1 ao numero escolhido!\n";
            for (size_t i = 1; i <=n; i++)
            {
                p=p+1;
                cout<<"Numero "<<p <<endl;
            }
        }
        else
        {
        cout<<"Numero invalido!\n";
        cout<<"Digite outro numero!\n";
        }
    } while (n<=0);
    return 0;
}