#include <iostream>
#include <string>
using namespace std;
int main()
{
    string matriz[10][5];
    int i,j;
    for (i = 0; i < 2; i++)
    {
        cout<<"pesssoa "<<i+1<<":"<<endl;
        for (j = 0; j < 5; j++)
        {   
            switch (j)
            {
            case 0:
                cout<<"Digite seu nome:"<<endl;
                break;
            case 1:
                cout<<"Digite seu endereço:"<<endl;
                break;
            case 2:
                cout<<"Digite seu Codigo postal:"<<endl;
                break;
            case 3:
                cout<<"Digite seu bairro:"<<endl;
                break;
            default:
                cout<<"Digite seu telefone:"<<endl;
                break;
            }
            string line;
            getline(cin,line);
            matriz[i][j]=line;
        }
    }

    for (i = 0; i < 2; i++)
    {
        cout<<"pesssoa "<<i+1<<":"<<endl;
        for (j = 0; j < 5; j++)
        {   
            cout<<matriz[i][j]<<endl;
        }
        cout<<endl;
    }

    return 0;
}