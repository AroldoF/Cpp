#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype> // Para toupper

using namespace std;

int tamanho(string caminho_arquivo)
{
    ifstream arquivo;
    int i = 0;
    arquivo.open(caminho_arquivo);
    if (arquivo.is_open())
    {
        string linha;
        while (getline(arquivo, linha))
        {
            i++;
        }
        arquivo.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo: " << caminho_arquivo << endl;
    }
    return i;
}

void salvar_matriz(vector<vector<string>> &nomes, vector<vector<string>> &disciplinas)
{
    ifstream arquivo;
    string nome = "";
    arquivo.open("../alunos.txt");
    if (arquivo.is_open())
    {
        string linha;
        while (getline(arquivo, linha))
        {
            vector<string> aluno;
            string temp = "";
            for (char c : linha)
            {
                if (c == ';')
                {
                    aluno.push_back(temp);
                    temp = "";
                }
                else
                {
                    temp += c;
                }
            }
            nomes.push_back(aluno);
        }
        arquivo.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo." << endl;
    }

    ifstream meuarquivo;
    meuarquivo.open("../disciplinas.txt");
    if (meuarquivo.is_open())
    {
        string linha;
        while (getline(meuarquivo, linha))
        {
            vector<string> disciplina;
            string temp = "";
            for (char c : linha)
            {
                if (c == ';')
                {
                    disciplina.push_back(temp);
                    temp = "";
                }
                else
                {
                    temp += c;
                }
            }
            disciplinas.push_back(disciplina);
        }
        meuarquivo.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo." << endl;
    }
}

void mostrar_matriz(const vector<vector<string>> &nomes, const vector<vector<string>> &disciplinas)
{
    cout << "Alunos:\n";
    for (const auto &aluno : nomes)
    {
        for (const auto &campo : aluno)
        {
            cout << campo << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Disciplinas:\n";
    for (const auto &disciplina : disciplinas)
    {
        for (const auto &campo : disciplina)
        {
            cout << campo << " ";
        }
        cout << endl;
    }
}

int main()
{
    int tam_alunos = tamanho("../alunos.txt");
    int tam_disciplinas = tamanho("../disciplinas.txt");

    vector<vector<string>> nomes;
    vector<vector<string>> disciplinas;

    salvar_matriz(nomes, disciplinas);

    int escolha;
    do
    {
        cout << "Digite 1 para adicionar aluno" << endl;
        cout << "Digite 2 para mostrar alunos e disciplinas" << endl;
        cout << "Digite 3 para sair" << endl;
        cin >> escolha;
        cout << endl;
        switch (escolha)
        {
        case 1:
            // adicionar_alunos(tam_alunos, nomes); // função ainda a ser implementada
            break;
        case 2:
            mostrar_matriz(nomes, disciplinas);
            break;
        case 3:
            break;
        default:
            cout << "Opção inválida" << endl;
            break;
        }
    } while (escolha != 3);

    return 0;
}
