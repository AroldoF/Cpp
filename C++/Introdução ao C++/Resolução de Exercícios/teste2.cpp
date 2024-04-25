#include <iostream>

int main() {
    int soma = 0;
    int quantidade = 0;

    // Loop para somar os números entre 15 e 100
    for (int i = 15; i <= 100; ++i) {
        soma += i;
        quantidade++;
    }

    // Calculando a média
    double media = static_cast<double>(soma) / quantidade;

    // Exibindo a média
    std::cout << "A media aritmetica dos numeros entre 15 e 100 e: " << media << std::endl;

    return 0;
}