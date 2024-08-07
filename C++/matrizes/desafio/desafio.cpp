#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int m = 3, n = 4;
    int cidade[m][n];
    int i, j, soma = 0;
    int x1, x2, y1, y2;
    cin>>x1>>x2>>y1>>y2;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cidade[i][j] = rand() % 10;
            cout << cidade[i][j] << " ";
        }
        cout << endl;
    }

    for (i = x1; i <= x2; i++) {
        for (j = y1; j <= y2; j++) {
            soma += cidade[i][j];
        }
    }

    cout << "A soma da poluicao da subarea de (" << x1 << ", " << y1 << ") ate (" << x2 << ", " << y2 << ") e de " << soma << endl;

    return 0;
}