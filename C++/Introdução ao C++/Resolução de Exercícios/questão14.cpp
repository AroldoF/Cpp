#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float x1, x2, y1, y2, r;
    cout << "Para saber a distancia entre dois pontos \n";
    cout << "Insira o ponto A \n";
    cin >> x1 >> x2;
    cout << "Insira o ponto B \n";
    cin >> y1 >> y2;
    r = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << "A distancia entre os dois e: " << r << endl;
    return 0;
}