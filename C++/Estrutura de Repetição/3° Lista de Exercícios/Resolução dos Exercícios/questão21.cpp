#include <iostream>
using namespace std;
int main()
{
    float x,y,z,m,r;
    cin>>x;
    m=0;
    z=0;
    cout<<"Insira o valor de cada mercadoria\n";
    for (size_t i = 0; i < x; i++)
    {
        z++;
        cout<<"Insira o valor da mercadoria de numero "<<z<<endl;
        cin>>y;
        m=m+y;
    }
    r=m/z;
    cout<<"o valor total das mercadorias e: " <<m <<endl;
    cout<<"A media de preco das mercadorias: " <<r <<endl;
    return 0;
}