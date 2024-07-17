#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double nota1,nota2,media;
    int saida;
    do
    {
        do
        {
            cin>>nota1;
            if(nota1>10||nota1<0)
                cout<<"nota invalida"<<endl;
        }while(nota1>10||nota1<0);
        do
        {
            cin>>nota2;
            if(nota2>10||nota2<0)
                cout<<"nota invalida"<<endl;
        }while(nota2>10||nota2<0);
        media=(nota1+nota2)/2;
        cout<<"media = "<<fixed<<setprecision(2)<<media<<endl;
        do
        {
            cout<<"novo calculo (1-sim 2-nao)"<<endl;
            cin>>saida;
        }while(saida!=1&&saida!=2);
    }while(saida!=2);
    
    return 0;
}