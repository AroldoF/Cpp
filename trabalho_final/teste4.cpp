#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void exibirNotas(int tam_alunos, int tam_disciplinas, string nomes[][3], string disciplinas[][3], vector<vector<string>>& notas) {
    int m = 1, n = 1, j = 2;
    ifstream arquivo;
    
    // Abertura do arquivo
    arquivo.open("../notas.txt");
    if (arquivo.is_open()) {
        string linha;
        
        // Inicializa a primeira coluna com os nomes dos alunos
        for (int i = 1; i <= tam_alunos; i++) {
            notas[i][0] = nomes[i][0];
        }
        
        while (getline(arquivo, linha)) {
            // Reseta a linha da matriz
            notas[m][n] = "";
            string temp; // Temporário para armazenar cada nota ou nome
            
            for (char c : linha) {
                // Preenche os cabeçalhos das disciplinas (primeira linha da matriz)
                if (isalpha(c) && j <= tam_disciplinas && m == 1) {
                    notas[0][j] = ""; // Inicializa a célula da disciplina
                    for (int i = 0; i < tam_disciplinas; i++) {
                        if (c == disciplinas[i][0][0]) {
                            notas[0][j] = disciplinas[i][0]; // Nome da disciplina
                        }
                    }
                    j++;
                }
                
                // Adiciona a nota (dígitos ou "-")
                if (isdigit(c) || c == '-') {
                    temp += c;
                }
                // Quando encontra um delimitador, armazena a nota
                else if (c == ';' || c == ':') {
                    if (!temp.empty()) {
                        notas[m][n++] = temp; // Armazena a nota
                        temp.clear();         // Limpa o temporário
                    }
                }
            }

            // Adiciona o último item se houver
            if (!temp.empty()) {
                notas[m][n++] = temp;
            }
            
            // Reseta o índice da coluna e incrementa a linha
            n = 1;
            m++;
        }
        arquivo.close();
    } else {
        cout << "Não foi possível abrir o arquivo." << endl;
        return;
    }

    // Exibe o cabeçalho (disciplinas)
    cout << left << setw(15) << "Aluno/Disciplina"; 
    for (int i = 1; i <= tam_disciplinas; i++) {
        cout << left << setw(15) << notas[0][i]; // Cabeçalhos das disciplinas
    }
    cout << endl;

    // Exibe as notas dos alunos
    for (int i = 1; i <= tam_alunos; i++) {
        cout << left << setw(15) << notas[i][0]; // Nome dos alunos
        for (int j = 1; j <= tam_disciplinas; j++) {
            cout << left << setw(15) << notas[i][j]; // Notas
        }
        cout << endl;
    }
}

int main() {
    int tam_alunos = 5, tam_disciplinas = 4;

    // Exemplos de nomes e disciplinas (pode ser carregado de outra forma)
    string nomes[6][3] = { {"", "", ""}, {"Ana", "", ""}, {"Bruno", "", ""}, {"Carlos", "", ""}, {"Diana", "", ""}, {"Eduardo", "", ""} };
    string disciplinas[4][3] = { {"Matematica", "", ""}, {"Portugues", "", ""}, {"Historia", "", ""}, {"Ciencias", "", ""} };
    
    // Inicializa a matriz de notas (5 alunos x 4 disciplinas)
    vector<vector<string>> notas(6, vector<string>(5)); 
    
    // Exibe as notas
    exibirNotas(tam_alunos, tam_disciplinas, nomes, disciplinas, notas);
    
    return 0;
}
