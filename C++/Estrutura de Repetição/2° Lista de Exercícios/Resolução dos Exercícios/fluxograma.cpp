#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, b, ca, cb, r, e;
    a = 4;
    b = 4;
    ca = 2;
    r = b;
    while (ca <= a)
    {
        e = b;
        cb = 1;
        if (cb < ca)
        {
            while (cb < ca)
            {
                e = e * b;
                cb = cb + 1;
            }
            r = r + e;
            ca = ca + 2;
        }
        else
            cout << r;
    }
}