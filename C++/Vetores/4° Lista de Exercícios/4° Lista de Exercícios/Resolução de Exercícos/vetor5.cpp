#include <iostream>
using namespace std;
int main()
{
    float n1[10];
    float n2[10];
    float n3[10];
    float n4[10];
    float media[10];
    float soma=0;
    for (int i = 0; i <10; i++)
    {
        cout<<"Digite a nota 1:\n";
        cin>>n1[i];
        cout<<"Digite a nota 2:\n";
        cin>>n2[i];
        cout<<"Digite a nota 3:\n";
        cin>>n3[i];
        cout<<"Digite a nota 4:\n";
        cin>>n4[i];
        media[i]=(n1[i]+n2[i]+n3[i]+n4[i])/4;
        if(media[i]>=7.0)
        {
            cout<<"Sua media e: " <<media[i] <<endl;
            cout<<"aprovado " <<endl;
            soma++;
        }
        else
        {
        cout<<"Sua media e: " <<media[i] <<endl;
        cout<<"nao passou\n";
        }
    }
    cout<<"O numero de alunos que passou com media 7 acima foi " <<soma <<endl;
    return 0;
}