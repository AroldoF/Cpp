#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

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

void salvar_matriz(string nomes[][3], string disciplinas[][3])
{
    int m = 0, n = 0;
    ifstream arquivo;
    string nome = "";
    arquivo.open("../alunos.txt");
    if (arquivo.is_open())
    {
        string linha;
        while (getline(arquivo, linha))
        {
            for (auto i = 0; i < linha.length(); i++)
            {
                if (isalpha(linha[i]))
                {
                    nomes[m][n] += linha[i];
                }
                else if (isupper(linha[i + 1]))
                {
                    nomes[m][n] += linha[i];
                }
                else if (linha[i] == ';')
                {
                    n++;
                }
                else if (isdigit(linha[i]))
                {
                    nomes[m][n] += linha[i];
                }
            }
            n = 0;
            m++;
        }
        arquivo.close();
    }
    else
    {
        std::cout << "Não foi possível abrir o arquivo." << std::endl;
    }

    m=0,n=0;
    ifstream meuarquivo;
    meuarquivo.open("../disciplinas.txt");
    if (meuarquivo.is_open())
    {
        string linha;
        while (getline(meuarquivo, linha))
        {
            for (auto i = 0; i < linha.length(); i++)
            {
                if (isalpha(linha[i]))
                {
                    disciplinas[m][n] += linha[i];
                }
                else if (linha[i] == ';')
                {
                    n++;
                }
                else if (isdigit(linha[i]))
                {
                    disciplinas[m][n] += linha[i];
                }
            }
            n = 0;
            m++;
        }
        meuarquivo.close();
    }
    else
    {
        std::cout << "Não foi possível abrir o arquivo." << std::endl;
    }

    
}

void mostrar_matriz(int tam,string nomes[][3], string disciplinas[][3])
{
    cout<<"Alunos:\n"<<endl;
    for (int i = 0; i < tam; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            cout << nomes[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;

    cout<<"Disciplinas:\n"<<endl;
    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            cout << disciplinas[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
}

void adicionar_alunos(int tam, string nomes[][3])
{
    int i;
    string aluno = "";
    bool quebra = false;
    do
    {
        cout << "Digite o nome do aluno: ";
        getline(cin, aluno);
        aluno[0] = toupper(aluno[0]);
        cout << aluno << endl;
        for (auto i = 0; i < aluno.length(); i++)
        {
            if (isalpha(aluno[i]))
            {
                quebra = true;
            }
            else if (isalpha(aluno[i + 1]))
            {
                aluno[i + 1] = toupper(aluno[i + 1]);
            }
            else
            {
                cout << "Houve um erro! Digite o nome novamente!\n"
                     << endl;
                quebra = false;
                break;
            }
        }
    } while (!quebra);
    string nome = aluno;
    string matricula = "";
    do
    {
        cout << "Digite a matricula do Aluno(Apenas 4 digitos): ";
        cin >> matricula;
        for (i = 0; i < tam; i++)
        {
            if (matricula == nomes[i][1])
            {
                cout << "Existe aluno cadastrado com essa matricula!\n"
                     << endl;
                break;
            }
        }

    } while (matricula == nomes[i][1] || matricula.length() != 4);

    string turma = "";
    while (true)
    {
        cout << "Digite a turma do Aluno: [A a Z] ";
        cin >> turma;
        turma[0] = toupper(turma[0]);
        if (isalpha(turma[0]) && turma.length() == 1)
        {
            break;
        }
        cout << "Erro!\n"
             << endl;
    }
    aluno += "; ";
    aluno += matricula;
    aluno += "; ";
    aluno += turma;

    fstream arquivo;
    arquivo.open("../alunos.txt", ios::out | ios::app);
    if (arquivo.is_open())
    {
        arquivo << "\n";
        arquivo << aluno;
    }
    else
        cout << "Não foi possível abrir o arquivo." << endl;

    cout << "O Aluno " << nome << " adicionado com sucesso!"<<endl;
}

void cadastrar_disciplinas(int tam, string disciplinas[][3])
{
    int i;
    string disciplina = "";
    bool quebra = false;
    do
    {
        cout << "Digite o nome da disciplina: ";
        getline(cin, disciplina);
        disciplina[0] = toupper(disciplina[0]);
        for (auto i = 0; i < disciplina.length(); i++)
        {
            if (isalpha(disciplina[i]))
            {
                quebra = true;
            }
            else
            {
                cout << "Houve um erro! Digite o nome novamente!\n"
                     << endl;
                quebra = false;
                break;
            }
        }
    } while (!quebra);
    string nome = disciplina;
    string codigo = "";
    do
    {
        cout << "Digite o codigo da Disciplina(Apenas 3 digitos): ";
        cin >> codigo;
        for (i = 0; i < tam; i++)
        {
            if (codigo == disciplinas[i][1])
            {
                cout << "Existe aluno cadastrado com essa matricula!\n"
                     << endl;
                break;
            }
        }

    } while (codigo == disciplinas[i][1] || codigo.length() != 3);

    string turma = "";
    while (true)
    {
        cout << "Digite a turma do Aluno: [A a Z] ";
        cin >> turma;
        turma[0] = toupper(turma[0]);
        if (isalpha(turma[0]) && turma.length() == 1)
        {
            break;
        }
        cout << "Erro!\n"
             << endl;
    }
    disciplina += "; ";
    disciplina += codigo;
    disciplina += "; ";
    disciplina += turma;

    fstream arquivo;
    arquivo.open("../disciplinas.txt", ios::out | ios::app);
    if (arquivo.is_open())
    {
        arquivo << "\n";
        arquivo << disciplina;
    }
    else
        cout << "Não foi possível abrir o arquivo." << endl;

    cout << "A disciplina " << nome << " adicionado com sucesso!"<<endl;
}

int main()
{
    int tam_alunos = tamanho("../alunos.txt");
    int tam_disciplinas = tamanho("../disciplinas.txt");
    int tam_notas = tamanho("../notas.txt");

    string nomes[tam_alunos][3];
    string disciplinas[tam_disciplinas][3];
    salvar_matriz(nomes,disciplinas);
    int escolha;
    do
    {
        cout << "Digite 1 para mostrar alunos e disciplinas" << endl;
        cout << "Digite 2 para adicionar aluno" << endl;
        cout << "Digite 3 para adicionar disciplinas" << endl;
        cout << "Digite 4 para sair" << endl;
        cout << "Digite 5 para limpar" << endl;
        cin >> escolha;
        cout<<endl;
        switch (escolha)
        {
        case 1:
            mostrar_matriz(tam_alunos, nomes,disciplinas);
            break;
        case 2:
            adicionar_alunos(tam_alunos, nomes);
            break;
        case 3:
            cadastrar_disciplinas(tam_disciplinas,disciplinas);
            break;
        case 4:
            break;
        case 5:
            system("cls");
            break;
        default:
            cout << "error" << endl;
            break;
        }
    } while (escolha != 4);
    return 0;
}