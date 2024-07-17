#include <iostream>
using namespace std;
int main()
{
    //revisão de estruturas de repetição e fibonacci
    int i;
    double fib0 = 0, fib1 = 1, fib_at;
    int ff;
    cout << "Fibonacci pos 0 = " << fib0 << endl;
    //cout << "Fibonacci pos 1 = " << fib1 << endl;
    for (i = 2; i < 100; i++)
    {
        fib_at = fib0 + fib1;
        ff=fib_at;
        if (ff % 2 == 0)
        {
            cout << "Fibonacci pos " << i << " = " << fib_at << endl;
        }
        fib0 = fib1;
        fib1 = fib_at;
    }
}