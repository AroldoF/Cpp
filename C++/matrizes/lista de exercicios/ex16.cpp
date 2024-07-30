#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int matriz_A[10][7];
    double par = 0, impar = 0;
    int i, j;
    float perc_par, perc_impar, total;
    cout << "Matriz A:" << endl;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 7; j++)
        {
            matriz_A[i][j] = rand() % 5;
            cout << matriz_A[i][j] << " ";
            if (matriz_A[i][j] % 2 == 0)
            {
                par++;
            }
            else
                impar++;
        }
        cout << endl;
    }
    total = par + impar;
    perc_par = (par / total) * 100;
    perc_impar = (impar / total) * 100;
    cout << "O total dos numeros na Matriz e " << total << endl;
    cout << "O total de numeros pares na Matriz e " << par << " e o percentual do total e " << perc_par << "%" << endl;
    cout << "O total de numeros impares na Matriz e " << impar << " e o percentual do total e " << perc_impar << "%" << endl;

    return 0;
}