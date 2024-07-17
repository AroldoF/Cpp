#include <iostream>
using namespace std;
int main()
{
    //revisão de vetores
    // setando as variáveis
    int i, j = 0, k = 0;
    int par[100], impar[100], vet[200];
    
    // for para preencher os vetores com numeros impares e pares
    for (i = 0; i < 200; i++)
    {
        if (i % 2 == 0)
        {
            par[j] = i;
            j++;
        }
        else
        {
            impar[k] = i;
            k++;
        }
    }

    // zerando as varáveis de contagem
    k = 0;
    j = 0;

    // for para preencher e imprimir um vetor com os numeros pares e impares
    for (i = 0; i < 200; i++)
    {
        if (i % 2 == 0)
        {
            vet[i] = par[j];
            j++;
            cout << "Numero par = " << vet[i] << endl;
        }
        else
        {
            vet[i] = impar[k];
            k++;
            cout << "Numero impar = " << vet[i] << endl;
        }
    }
}