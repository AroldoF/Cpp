#include <iostream>
using namespace std;
int main()
{
    int n;
    n=0;
    cout<<"Os 10 a 1(contagem crescente):\n";
    for (size_t i = 1; i <=10; i++)
    {
        n=n+1;
        cout<<"Numero " <<n <<endl;
    }
    return 0;
}