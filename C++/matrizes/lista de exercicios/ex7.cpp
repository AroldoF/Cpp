#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int i, j;
    int celsius[4][5];
    double fahrenheit[4][5];

    cout << "Matriz em Celsius:" << endl;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            celsius[i][j] = rand() % 50;
            cout << celsius[i][j] << "C ";
        }
        cout << endl;
    }

    cout<<"Matriz em Fahrenheit:"<<endl;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            fahrenheit[i][j] = celsius[i][j] * 1.8 + 32;
            cout << fahrenheit[i][j] << "F ";
        }
        cout << endl;
    }

    return 0;
}