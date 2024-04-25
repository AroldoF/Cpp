#include <iostream>
using namespace std;
int main()
{
    int n;
    n=100;
    cout<<"Os 10 numeros interios maiores que 100:\n";
    for (size_t i = 1; i <=10; i++)
    {
        n=n+1;
        cout<<"Numero " <<n <<endl;
    }
    return 0;
}