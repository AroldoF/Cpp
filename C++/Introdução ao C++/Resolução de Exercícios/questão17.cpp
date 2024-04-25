#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float pes, cm;
    cout << "Insira a distancia em pes: \n";
    cin >> pes;
    cm = pes * 30.48;
    cout << "A distancia em centimetros e: " << cm << endl;
    return 0;
}