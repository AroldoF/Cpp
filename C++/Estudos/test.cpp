#include <iostream>
using namespace std;
int main()
{
    int n, i, a, z;
    cin >> n;
    a = 1;
    for (i = 0; i < n; i++)
    {
        z = n - i;
        a = z * a;
    }
    cout << a << endl;
    return 0;
}