#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float pes, metros;
    cout << "Insira a distancia em pes: \n";
    cin >> pes;
    metros = pes * 0.3048;
    cout << "A distancia em metros e: " << metros << endl;
    return 0;
}