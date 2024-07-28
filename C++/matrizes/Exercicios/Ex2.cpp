#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
    string matriz[2][5];
    int i,j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 5; j++)
        {   
            string line;
            getline(cin,line);
            matriz[i][j]=line;
            //cin>>matriz[i][j];
        }
        
    }
    int largura=20;
    cout<<left;
    cout<<"|";
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 5; j++)
        {   
            cout<< setw(largura)<<matriz[i][j]<<" |";
        }
        cout<<endl;
        if (i!=1)
        {
            cout<<"|";
        }
    }
    return 0;
}