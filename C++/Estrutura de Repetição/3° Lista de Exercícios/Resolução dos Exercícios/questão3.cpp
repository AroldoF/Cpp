#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float n, p, m;
    p = 0;
    for (size_t i = 1; i <= 10; i++)
    {
        cout << "Digite uma nota:\n";
        cin >> n;
        p = p + n;
    }
    m = p / 10;
    cout << "A soma dessas notas e: " << p << endl;
    cout << "A media desses notas e: " << m << endl;
    cout << m;
    return 0;
}