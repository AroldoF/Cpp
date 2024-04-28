#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double a, b, c, r1, r2, delta;
    cin >> a >> b >> c;
    bool impossivel = false;
    delta = sqrt(pow(b, 2) - 4 * a * c);
    if (a == 0 || isnan(delta))
    {
        impossivel = true;
    }
    if (impossivel == false)
    {
        r1 = (-b + delta) / (2 * a);
        r2 = (-b - delta) / (2 * a);
        cout << "R1 = " << fixed << setprecision(5) << r1 << endl;
        cout << "R2 = " << fixed << setprecision(5) << r2 << endl;
    }
    else
        cout << "Impossivel calcular" << endl;
    return 0;
}