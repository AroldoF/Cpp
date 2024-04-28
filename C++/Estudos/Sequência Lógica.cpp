#include <iostream>
using namespace std;
int main()
{
    int n, i;
    cin >> n;
    int um[n], dois[n], tres[n];
    for (i = 1; i <= n; i++)
    {
        um[i] = i;
        dois[i] = i * i;
        tres[i] = dois[i] * i;
    }
    for (i = 1; i <= n; i++)
    {
        cout << um[i] << " " << dois[i] << " " << tres[i] << endl;
        cout << um[i] << " " << dois[i] + 1 << " " << tres[i] + 1 << endl;
    }
    return 0;
}