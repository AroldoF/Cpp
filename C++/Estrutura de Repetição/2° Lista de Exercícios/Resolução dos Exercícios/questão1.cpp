#include <iostream>
using namespace std;
int main()
{
    int a = 6 * (3 + 2);
    int b = 2 + 6 * (3 + 2);
    int c = 2 + (3 * 6) / (2 + 4);
    int d = 2 * (8 / (3 + 1));
    int e = 3 + (16 - 2) / (2 * (9 - 2));
    int f = (6 / 3) + (8 / 2);
    int g = ((3 + (8 / 2)) * 4) + (3 + 2);
    int h = (6 * (3 * 3) + 6) - 10;
    int i = (((10 * 8) + 3) * 9);
    int j = ((-12) * (-4)) + (3 * (-4));

    cout << "resultado da conta 6*(3+2) = " << a << endl;
    cout << "resultado da conta 2+(6*(3+2)) = " << b << endl;
    cout << "resultado da conta 2+(3*6)/(2+4) = " << c << endl;
    cout << "resultado da conta 2*(8/(3+1)) = " << d << endl;
    cout << "resultado da conta 3+(16-2)/(2*(9-2)) = " << e << endl;
    cout << "resultado da conta (6/3)+(8/2) = " << f << endl;
    cout << "resultado da conta ((3+(8/2))*4)+(3+2) = " << g << endl;
    cout << "resultado da conta (6*(3*3)+6)-10 = " << h << endl;
    cout << "resultado da conta (((10*8)+3)*9) = " << i << endl;
    cout << "resultado da conta ((-12)*(-4))+(3*(-4)) = " << j << endl;
    return 0;
}