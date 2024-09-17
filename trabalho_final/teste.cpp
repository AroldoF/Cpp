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
            matriz[m][n] = "";
            for (auto i = 0; i < linha.length(); i++)
            {

                if (isalpha(linha[i]))
                {
                    matriz[m][n] += linha[i];
                }
                else if (isupper(linha[i + 1]) && n == 0)
                {
                    matriz[m][n] += linha[i];
                }
                else if (linha[i] == ';')
                {
                    n++;
                    matriz[m][n] = "";
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
        cout << "Não foi possível abrir o arquivo." << endl;
    }
}

void mostrar_matriz(string nomes[][3], string disciplinas[][3], int tam_alunos, int tam_disciplinas)
{
    cout << left << setw(20) << "Alunos:" << left << setw(15) << "Materias:" << left << setw(15) << "Turma:\n"
         << endl;
    for (int i = 0; i < tam_alunos; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
                cout << left << setw(20) << nomes[i][j] << "";
            else
                cout << left << setw(15) << nomes[i][j] << "";
        }
        cout << endl;
    }
    cout << endl;

    cout << left << setw(20) << "Materias:" << left << setw(15) << "Codigo:" << left << setw(15) << "Turma:\n"
         << endl;
    for (int i = 0; i < tam_disciplinas; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
                cout << left << setw(20) << disciplinas[i][j] << "";
            else
                cout << left << setw(15) << disciplinas[i][j] << "";
        }
        cout << endl;
    }
    cout << endl;
}

void adicionar_alunos(int tam, string nomes[][3])
{
    int i;
    string aluno = "";
    bool quebra = false;
    do
    {
        cout << "Digite o nome do aluno: ";
        cin.ignore();
        getline(cin, aluno);
        aluno[0] = toupper(aluno[0]);
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

    arquivo.close();

    turma += ";";
    fstream meuarquivo;
    meuarquivo.open("../notas.txt", ios::out | ios::app);
    if (arquivo.is_open())
    {
        arquivo << "\n";
        arquivo << turma;
    }
    else
        cout << "Não foi possível abrir o arquivo." << endl;

    meuarquivo.close();

    cout << "O Aluno " << nome << " adicionado com sucesso!\n"
         << endl;
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

    cout << "A disciplina " << nome << " adicionado com sucesso!" << endl;
}

void exibirNotas(int tam_alunos, int tam_disciplinas, string nomes[][3], string disciplinas[][3], vector<vector<string>> &notas)
{
    int m = 1, n = 1;
    // int j = 2;
    ifstream arquivo;

    // Abertura do arquivo
    arquivo.open("../notas.txt");
    if (arquivo.is_open())
    {
        string linha;

        // Certifique-se de que os limites são respeitados ao preencher
        for (int i = 1; i <= tam_alunos; i++)
        {
            notas[i][0] = nomes[i - 1][0]; // Ajustando para garantir que o índice de nomes começa no 0
        }
        for (int i = 2; i <= tam_disciplinas + 1; i++)
        {
            notas[0][i] = disciplinas[i - 2][0]; // Ajustando para garantir que o índice de disciplinas começa no 0
            cout << notas[0][i] << endl;
        }
        notas[0][1] = "Matricula";
        while (getline(arquivo, linha))
        {
            // Reseta a linha da matriz
            notas[m][n] = "";
            string temp; // Temporário para armazenar cada nota ou nome
            for (char c : linha)
            {
                /*
                    // Preenche os cabeçalhos das disciplinas (primeira linha da matriz)
                    if (isalpha(c) && j <= tam_disciplinas+1)
                    {
                        notas[0][j] = ""; // Inicializa a célula da disciplina
                        for (int i = 0; i < tam_disciplinas; i++)
                        {
                            if (c == disciplinas[i][0][0])
                            {
                                for (i = 2; i < tam_disciplinas; i++)
                                {
                                    if (c!=notas[0][i][0])
                                    {
                                        notas[0][j] = disciplinas[i][0]; // Nome da disciplina
                                        break;
                                    }

                                }
                            }
                        }
                        j++;
                    }*/
                if (isalpha(c))
                {
                    char materia = c;
                }

                // Adiciona a nota (dígitos ou "-")
                if (isdigit(c) || c == '-')
                {
                    temp += c;
                }
                // Quando encontra um delimitador, armazena a nota
                else if (c == ';')
                {
                    if (!temp.empty())
                    {
                        notas[m][n++] = temp; // Armazena a nota
                        temp.clear();         // Limpa o temporário
                    }
                }
            }

            // Adiciona o último item se houver
            if (!temp.empty())
            {
                for (int i = 0; i < tam_disciplinas; i++)
                {
                    // Comparar o char 'c' com o primeiro caractere da string disciplinas[i][0]
                    if (c == disciplinas[i][0][0])
                    {
                        // Atribuir o valor de 'temp' à posição correta em 'notas'
                        notas[m][i + 2] = temp;
                    }
                }
            }

            // Reseta o índice da coluna e incrementa a linha
            n = 1;
            m++;
        }
        arquivo.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo." << endl;
        return;
    }

    // Exibe o cabeçalho (disciplinas)
    /*cout << left << setw(20) << "Aluno/Disciplina";
    for (int i = 1; i <= tam_disciplinas; i++)
    {
        cout << left << setw(15) << notas[0][i]; // Cabeçalhos das disciplinas
    }
    cout << endl;*/
    notas[0][0] = "Aluno/Disciplina";
    // Exibe as notas dos alunos
    for (int i = 0; i <= tam_alunos + 1; i++)
    {
        // cout << left << setw(20) << notas[i][0]; // Nome dos alunos
        for (int j = 0; j <= tam_disciplinas + 1; j++)
        {
            cout << left << setw(20) << notas[i][j]; // Notas
        }
        cout << endl;
    }
    cout << endl;
}

void lançar_notas(string nomes[][3], int tam_alunos, string disciplinas[][3], int tam_disciplinas, vector<vector<string>> &notas)
{
    string modificação = "";
    string buscas;
    bool quebra = false;
    do
    {
        int i;
        cout << "Digite o nome ou a Matricula do aluno ";

        getline(cin, modificação);
        for (i = 0; i < tam_alunos; i++)
        {
            if ((modificação == nomes[i][0]) || (modificação == nomes[i][1]))
            {
                buscas = nomes[i][1];
                quebra = true;
                break;
            }
        }
    } while (!quebra);
    string var;
    int c = 1;
    string linha_modificada;
    linha_modificada = "";
    string notas_string;
    notas_string = "";
    int n1;
    float media = 0;
    fstream arquivo;
    vector<string> line;
    int k = 0;
    // bool encontrei = false;
    arquivo.open("../notas.txt", ios::in | ios::out);
    if (arquivo.is_open())
    {
        int pos = 0;
        string linha;
        while (getline(arquivo, linha))
        {
            line.push_back(linha);
            pos = linha.find(';');
            var = linha.substr(0, pos);
            if (buscas == var)
            {
                linha_modificada += buscas;
                linha_modificada += ";";
                string escolha = "";
                for (int i = 0; i < tam_disciplinas; i++)
                {
                    cout << "Voce quer modificar a materia de " << disciplinas[i][0] << "? [S/N]" << endl;
                    cin >> escolha;
                    escolha[0] = toupper(escolha[0]);
                    if (escolha[0] == 'S')
                    {
                        cout << "Digite a nota de " << disciplinas[i][0] << ":" << endl;
                        linha_modificada += disciplinas[i][0][0];
                        linha_modificada += ";";
                        c = 1;
                        while (true)
                        {
                            cout << "Digite a nota do " << c << " Bimestre: ";
                            cin >> n1;
                            if (n1 < 0 || n1 > 100)
                            {
                                cout << "Você digitou uma nota fora dos parametros!\nDigite novamente" << endl;
                                n1 = -1;
                                c--;
                            }
                            else
                            {

                                media += n1;
                                notas_string += to_string(n1);
                                if (c == 4)
                                {
                                    notas_string += ";";
                                    linha_modificada += notas_string;
                                    cout << endl;
                                    notas_string = "";
                                    n1 = -1;
                                    break;
                                }
                                else
                                    notas_string += "-";
                            }
                            c++;
                        }
                        // encontrei = true;
                        k = line.size() - 1;
                    }
                    // else if (encontrei==false)
                    {
                        // k++;
                    }
                }
            }
        }
        arquivo.close();
    }
    else
        cout << "arquivo nao abriu!" << endl;

    cout << "linha modificada e:\n"
         << linha_modificada << endl;

    cout << k << endl;
    line[k] = linha_modificada;
    arquivo.open("../notas.txt", ios::out | ios::trunc);
    if (arquivo.is_open())
    {
        for (int i = 0; i < line.size(); i++)
        {
            arquivo << line[i] << "\n";
        }
    }
    arquivo.close();
}

int main()
{

    int tam_alunos = tamanho("../alunos.txt");
    int tam_disciplinas = tamanho("../disciplinas.txt");
    // int tam_notas = tamanho("../notas.txt");

    string nomes[tam_alunos][3];
    string disciplinas[tam_disciplinas][3];

    vector<vector<string>> notas(tam_alunos + 1, vector<string>(tam_disciplinas + 2));
    salvar_matriz("../alunos.txt", nomes);
    salvar_matriz("../disciplinas.txt", disciplinas);
    int escolha;
    do
    {
        cout << "Digite 1 para mostrar alunos e disciplinas" << endl;
        cout << "Digite 2 para adicionar aluno" << endl;
        cout << "Digite 3 para adicionar disciplinas" << endl;
        cout << "Digite 4 para sair" << endl;
        cout << "Digite 5 para limpar" << endl;
        cin >> escolha;
        cout << endl;
        switch (escolha)
        {
        case 1:
            mostrar_matriz(nomes, disciplinas, tam_alunos, tam_disciplinas);
            break;
        case 2:
            adicionar_alunos(tam_alunos, nomes);
            tam_alunos++;
            salvar_matriz("../alunos.txt", nomes);
            break;
        case 3:
            cadastrar_disciplinas(tam_disciplinas, disciplinas);
            tam_disciplinas++;
            salvar_matriz("../disciplinas.txt", disciplinas);
            break;
        case 4:
            break;
        case 5:
            system("cls");
            break;
        case 6:
            exibirNotas(tam_alunos, tam_disciplinas, nomes, disciplinas, notas);
            break;
        case 7:
            lançar_notas(nomes, tam_alunos, disciplinas, tam_disciplinas, notas);
            break;
        default:
            cout << "error" << endl;
            break;
        }
    } while (escolha != 4);

    return 0;
}