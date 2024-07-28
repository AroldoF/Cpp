#include <iostream>
using namespace std;
int main()
{
    int matriz[12][4];
    int j,i;
    double total_mes=0,total=0;
    for (i = 0; i < 12; i++)
    {
        for (j = 0; j < 4; j++)
        {
            //cout<<"Digite a matriz["<<i<<"}["<<j<<"]:"<<endl;
            //cin>>matriz[i][j];
            matriz[i][j]=1;
        }
        
    }
    for (i = 0; i < 12; i++)
    {
        cout<<"Mes "<<i+1<<":"<<endl;
        for ( j = 0; j < 4; j++)
        {
            cout<<"Total da semana "<<j+1<<" = "<<matriz[i][j]<<endl;
            total_mes+=matriz[i][j];
        }
        cout<<"total mes "<<i+1<<" = "<<total_mes<<endl;
        cout<<endl;
        total+=total_mes;
        total_mes=0;
    }
    cout<<"total ano = "<<total<<endl;
    return 0;
}