#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define NUM_ALUNOS 100
#define NUM_DISCIPLINAS 10

// Estrutura para Aluno
struct Aluno {
    std::string nome;
    int matricula;
    std::string turma;
};

// Estrutura para Disciplina
struct Disciplina {
    std::string nome;
    int codigo;
};

// Matriz de notas
float notas[NUM_ALUNOS][NUM_DISCIPLINAS];

// Função para cadastrar aluno
void cadastrarAluno() {
    Aluno aluno;
    std::ofstream arquivo("alunos.txt", std::ios::app);

    std::cout << "Nome do aluno: ";
    std::getline(std::cin, aluno.nome);
    std::cout << "Matrícula: ";
    std::cin >> aluno.matricula;
    std::cin.ignore();
    std::cout << "Turma: ";
    std::getline(std::cin, aluno.turma);

    if (arquivo.is_open()) {
        arquivo << aluno.nome << "," << aluno.matricula << "," << aluno.turma << "\n";
        arquivo.close();
    } else {
        std::cout << "Erro ao abrir o arquivo de alunos." << std::endl;
    }
}

// Função para cadastrar disciplina
void cadastrarDisciplina() {
    Disciplina disciplina;
    std::ofstream arquivo("disciplinas.txt", std::ios::app);

    std::cout << "Nome da disciplina: ";
    std::getline(std::cin, disciplina.nome);
    std::cout << "Código da disciplina: ";
    std::cin >> disciplina.codigo;
    std::cin.ignore();

    if (arquivo.is_open()) {
        arquivo << disciplina.nome << "," << disciplina.codigo << "\n";
        arquivo.close();
    } else {
        std::cout << "Erro ao abrir o arquivo de disciplinas." << std::endl;
    }
}

// Função para lançar nota
void lancarNota(int alunoID, int disciplinaID, float nota) {
    notas[alunoID][disciplinaID] = nota;

    std::ofstream arquivo("notas.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << alunoID << "," << disciplinaID << "," << nota << "\n";
        arquivo.close();
    } else {
        std::cout << "Erro ao abrir o arquivo de notas." << std::endl;
    }
}

// Função para calcular a média de um aluno em todas as disciplinas
float calcularMediaAluno(int alunoID) {
    float soma = 0;
    int numDisciplinas = 0;

    for (int i = 0; i < NUM_DISCIPLINAS; i++) {
        soma += notas[alunoID][i];
        numDisciplinas++;
    }
    return (numDisciplinas > 0) ? soma / numDisciplinas : 0;
}

// Função para consultar notas de um aluno
void consultarNotasAluno(int alunoID) {
    std::cout << "Notas do Aluno " << alunoID << ":\n";
    for (int i = 0; i < NUM_DISCIPLINAS; i++) {
        std::cout << "Disciplina " << i << ": " << notas[alunoID][i] << "\n";
    }
}

// Função para consultar notas de todos os alunos em uma disciplina
void consultarNotasDisciplina(int disciplinaID) {
    std::cout << "Notas da Disciplina " << disciplinaID << ":\n";
    for (int i = 0; i < NUM_ALUNOS; i++) {
        std::cout << "Aluno " << i << ": " << notas[i][disciplinaID] << "\n";
    }
}

// Função para gerar relatório
void gerarRelatorio() {
    std::ofstream relatorio("relatorio.txt");

    if (relatorio.is_open()) {
        for (int i = 0; i < NUM_ALUNOS; i++) {
            relatorio << "Aluno " << i << ":\n";
            for (int j = 0; j < NUM_DISCIPLINAS; j++) {
                relatorio << "Disciplina " << j << ": " << notas[i][j] << "\n";
            }
            relatorio << "Média geral: " << calcularMediaAluno(i) << "\n";
            relatorio << "-------------------------\n";
        }
        relatorio.close();
    } else {
        std::cout << "Erro ao criar o relatório." << std::endl;
    }
}

// Menu principal
void menu() {
    int opcao, alunoID, disciplinaID;
    float nota;

    do {
        std::cout << "\n--- Menu Principal ---\n";
        std::cout << "1. Cadastrar Aluno\n";
        std::cout << "2. Cadastrar Disciplina\n";
        std::cout << "3. Lançar Nota\n";
        std::cout << "4. Consultar Notas do Aluno\n";
        std::cout << "5. Consultar Notas por Disciplina\n";
        std::cout << "6. Gerar Relatório\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        std::cin.ignore(); // Limpar o buffer de entrada

        switch (opcao) {
            case 1:
                cadastrarAluno();
                break;
            case 2:
                cadastrarDisciplina();
                break;
            case 3:
                std::cout << "ID do Aluno: ";
                std::cin >> alunoID;
                std::cout << "ID da Disciplina: ";
                std::cin >> disciplinaID;
                std::cout << "Nota: ";
                std::cin >> nota;
                lancarNota(alunoID, disciplinaID, nota);
                break;
            case 4:
                std::cout << "ID do Aluno: ";
                std::cin >> alunoID;
                consultarNotasAluno(alunoID);
                break;
            case 5:
                std::cout << "ID da Disciplina: ";
                std::cin >> disciplinaID;
                consultarNotasDisciplina(disciplinaID);
                break;
            case 6:
                gerarRelatorio();
                break;
            case 0:
                std::cout << "Saindo...\n";
                break;
            default:
                std::cout << "Opção inválida!\n";
                break;
        }
    } while (opcao != 0);
}

// Função principal
int main() {
    menu();
    return 0;
}
