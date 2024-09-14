#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int tam_disciplinas = 5; // Substitua com o valor real
    int m = 0, n = 0;
    ifstream arquivo;
    string matriz_notas[tam_disciplinas][5];
    arquivo.open("../notas.txt");

    if (arquivo.is_open()) {
        string linha;

        while (getline(arquivo, linha)) {
            size_t pos = 0;
            string delimiter = ";";
            string token;

            // Usando um stringstream para separar as notas
            while ((pos = linha.find(delimiter)) != string::npos) {
                token = linha.substr(0, pos);
                matriz_notas[m][n++] = token;
                linha.erase(0, pos + delimiter.length());
            }

            // Adiciona a última nota
            matriz_notas[m][n] = linha;
            n = 0; // Resetando o índice da coluna
            m++; // Avançando para a próxima linha
        }

        arquivo.close();
    } else {
        cerr << "Não foi possível abrir o arquivo." << endl;
    }

    // Exibindo o conteúdo da matriz para verificação
    for (int i = 0; i < tam_disciplinas; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << matriz_notas[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
