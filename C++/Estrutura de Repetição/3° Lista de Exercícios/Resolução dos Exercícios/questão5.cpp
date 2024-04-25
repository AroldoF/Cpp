#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float n, p;
    n = 0;
    for (size_t i = 1; i <= 50; i++)
    {
        p = 0;
        for (size_t a = 1; a <=i; a++)
        {
            if (i % a == 0)
            {
                p = p + 1;
            }
        }
            if (p == 2)
            {
                cout<<i <<endl;
                n = n + i;
            }
    }
    cout << n;
}