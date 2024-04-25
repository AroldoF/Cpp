#include <iostream>
#include <iostream>
using namespace std;
int main()
{
    float v, d, t;
    cout<<"insira a distancia em km percorrida pelo projetil \n";
    cin>>d;
    cout<<"Insira o tempo em minutos que o projetil levou para concluir a açao \n";
    cin>>t;
    v=(d * 1000) / (t * 60);
    cout<<"A velocidade que o projetil atingiu foi: " <<v <<"m/s" <<endl;
    return 0;
}