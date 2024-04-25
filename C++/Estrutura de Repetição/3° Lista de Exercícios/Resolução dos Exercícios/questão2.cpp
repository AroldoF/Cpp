#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    n = 0;
    for (size_t i = 1; i <= 900; i++)
    {
        n = n + i;
    }
    cout << n;
    return 0;
}