#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iomanip>

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

void salvar_matriz(string caminho_arquivo, string matriz[][3])
{
    int m = 0, n = 0;
    ifstream arquivo;
    arquivo.open(caminho_arquivo);
    if (arquivo.is_open())
    {
        string linha;
        while (getline(arquivo, linha))
        {
            for (auto i = 0; i < linha.length(); i++)
            {
                if (isalpha(linha[i]))
                {
                    matriz[m][n] += linha[i];
                }
                else if (isupper(linha[i + 1])&&n==0)
                {
                    matriz[m][n] += linha[i];
                }
                else if (linha[i] == ';')
                {
                    n++;
                }

                else if (isdigit(linha[i]))
                {
                    matriz[m][n] += linha[i];
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
}

void mostrar_matriz(int tam,string nomes[][3], string disciplinas[][3])
{
    cout<<"Alunos:\n"<<endl;
    for (int i = 0; i < tam; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            if (j==0)
                cout<<left<<setw(20)<< nomes[i][j] << "";
            else
                cout<<left<<setw(15)<< nomes[i][j] << "";
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

void exibirNotas(int tam_alunos, int tam_disciplinas,string nomes[][3], string disciplinas[][3]) {
    int m = 1, n = 1,j=2;
    ifstream arquivo;
    string matriz_notas[tam_disciplinas*tam_disciplinas+1][5];
    arquivo.open("../notas.txt");
     if (arquivo.is_open()) {
        string linha;
        
        // Exemplo para inicializar a primeira posição da matriz
       
        for (int i = 1; i < 5; i++)
        {
             matriz_notas[i][0] = nomes[i][0];
        }
        
        
        while (getline(arquivo, linha)) {
            // Reseta a linha da matriz
            matriz_notas[m][n] = "";
            string temp; // Temporário para armazenar cada nota ou nome

            for (char c : linha) 
            {
                
                if (isalpha(c)&&j<5&&m==1) 
                {
                    matriz_notas[0][j]="";
                    for (int i = 0; i < tam_disciplinas; i++)
                    {
                        if (c==disciplinas[i][0][0])
                        {
                            matriz_notas[0][j]=disciplinas[i][0];
                        }
                    }
                    //matriz_notas[0][j] += c; // Adiciona o caractere à string temporária
                    j++;
                } 
                if (isdigit(c)||c=='-')
                {
                    temp+=c;
                }
                
                else if (c == ';' || c == ':') 
                {
                    // Quando encontrar um delimitador, armazena a string temporária na matriz
                    if (!temp.empty()) 
                    {
                        matriz_notas[m][n++] = temp;
                        temp.clear(); // Limpa a string temporária
                    }
                }
            }

            // Adiciona o último item se houver
            if (!temp.empty()) 
            {
                matriz_notas[m][n++] = temp;
            }
            
            // Reseta o índice da coluna
            n = 1;
            m++;
        }
        arquivo.close();
    }
    else
    {
        std::cout << "Não foi possível abrir o arquivo." << std::endl;
    }
    cout << left << setw(15) << "Aluno/Disciplina"; // Espaçamento para o título das colunas
    for (int i = 1; i < 5; i++) {
        cout << left << setw(15) << matriz_notas[0][i]; // Cabeçalhos das disciplinas
    }
    cout << endl;

    // Exibe as notas dos alunos
    for (int i = 1; i < 6; i++) {
        cout << left << setw(15) << matriz_notas[i][0]; // Nome dos alunos
        for (int j = 1; j < 5; j++) {
            cout << left << setw(15) << matriz_notas[i][j]; // Notas dos alunos para cada disciplina
        }
        cout << endl;
    }
    
}

void lançar_notas()
{

}
int main()
{

    
    int tam_alunos = tamanho("../alunos.txt");
    int tam_disciplinas = tamanho("../disciplinas.txt");
    int tam_notas = tamanho("../notas.txt");

    string nomes[tam_alunos][3];
    string disciplinas[tam_disciplinas][3];
    
    std::vector<vector<string>> notas;
    salvar_matriz("../alunos.txt",nomes);
    salvar_matriz("../disciplinas.txt",disciplinas);
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
            tam_alunos++;
            salvar_matriz("../alunos.txt",nomes);
            break;
        case 3:
            cadastrar_disciplinas(tam_disciplinas,disciplinas);
            tam_disciplinas++;
            salvar_matriz("../disciplinas.txt",disciplinas);
            break;
        case 4:
            break;
        case 5:
            system("cls");
            break;
        case 6:
            exibirNotas(tam_alunos,tam_disciplinas,nomes,disciplinas);
            break;
        default:
            cout << "error" << endl;
            break;
        }
    } while (escolha != 4);

    return 0;
}