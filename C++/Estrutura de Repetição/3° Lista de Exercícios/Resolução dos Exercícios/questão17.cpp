#include <iostream>
using namespace std;
int main()
{
    float n;
    for (size_t i = 0; i < 10; i++)
    {
        cout<<"Digite um valor!\n";
        cin>>n;
        if (n>=10 && n<=20)
        {
            cout<<"O numero " <<n <<" esta entre 10 e 20!" <<endl;
        }
        else
            cout<<"O numero " <<n <<" nao esta entre 10 e 20!" <<endl;
    }
    return 0;    
}