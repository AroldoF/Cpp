#include <iostream>
using namespace std;
int main()
{
    float idade[5];
    float altura[5];
    int i;
    for (i = 0; i <5; i++)
    {
        cout<<"digite a idade da pessoa:\n";
        cin>>idade[i];
        cout<<"digite a altura da pessoa:\n";
        cin>>altura[i];
    }
    for (int i = 5; i >=0; i--)
    {
        cout<<"idade e altura das pessoa(da ultima para a primeira)\n"<<idade[i] <<endl;
        cout<<altura[i] <<endl;
    }
    return 0;

}