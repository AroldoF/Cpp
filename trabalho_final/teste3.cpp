#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <cctype>

using namespace std;

// Variáveis globais para o número de alunos e disciplinas
int tam_alunos = 0;
int tam_disciplinas = 0;


vector<vector<string>> alunos;
vector<vector<string>> disciplinas;
vector<vector<string>> notas;
vector<vector<string>> relatorio;

// Função para contar linhas de um arquivo (número de registros)
int tamanho(string caminho_arquivo)
{
    ifstream arquivo(caminho_arquivo);
    int linhas = 0;
    if (arquivo.is_open())
    {
        string linha;
        while (getline(arquivo, linha))
        {
            linhas++;
        }
        arquivo.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo: " << caminho_arquivo << endl;
    }
    return linhas;
}

void salvar_matriz(string caminho_arquivo, vector<vector<string>> &matriz)
{
    ifstream arquivo(caminho_arquivo);
    if (arquivo.is_open())
    {
        string linha;
        int m = 0;
        while (getline(arquivo, linha))
        {
            matriz[m].clear();
            string valor = "";
            for (char c : linha)
            {
                if (c == ';')
                {
                    matriz[m].push_back(valor);
                    valor.clear();
                }
                else
                {
                    valor += c;
                }
            }
            matriz[m].push_back(valor); // Adiciona o último valor da linha
            m++;
        }
        arquivo.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo: " << caminho_arquivo << endl;
    }
}

void mostrar_matriz()
{
    cout << left << setw(20) << "Alunos:" << left << setw(15) << "Matricula:" << left << setw(15) << "Turma:\n"
         << endl;
    for (int i = 0; i < tam_alunos; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << left << setw(15) << alunos[i][j] << "";
        }
        cout << endl;
    }
    cout << endl;

    cout << left << setw(20) << "Disciplinas:" << left << setw(15) << "Codigo:" << left << setw(15) << "Turma:\n"
         << endl;
    for (int i = 0; i < tam_disciplinas; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << left << setw(15) << disciplinas[i][j] << "";
        }
        cout << endl;
    }
    cout << endl;
}

// Função para adicionar novos alunos
void adicionar_alunos()
{
    string aluno = "";
    string matricula = "";
    string turma = "";

    cout << "Digite o nome do aluno: ";
    cin.ignore();
    getline(cin, aluno);
    aluno[0] = toupper(aluno[0]);

    // Validação da matrícula
    do
    {
        cout << "Digite a matrícula do Aluno (4 dígitos): ";
        cin >> matricula;
    } while (matricula.length() != 4);

    // Validação da turma
    do
    {
        cout << "Digite a turma do Aluno [A-Z]: ";
        cin >> turma;
        turma[0] = toupper(turma[0]);
    } while (!isalpha(turma[0]) || turma.length() != 1);

    // Adiciona o aluno ao arquivo
    ofstream arquivo("../alunos.txt", ios::app);
    if (arquivo.is_open())
    {
        arquivo << aluno << "; " << matricula << "; " << turma << "\n";
        arquivo.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo." << endl;
    }

    // Atualiza o número de alunos e adiciona o novo aluno à matriz
    tam_alunos++;
    alunos.resize(tam_alunos, vector<string>(3));
    alunos[tam_alunos - 1] = {aluno, matricula, turma};

    cout << "Aluno adicionado com sucesso!\n"
         << endl;
}

// Função para cadastrar novas disciplinas
void cadastrar_disciplinas()
{
    string disciplina = "";
    string codigo = "";
    string turma = "";

    cout << "Digite o nome da disciplina: ";
    cin.ignore();
    getline(cin, disciplina);
    disciplina[0] = toupper(disciplina[0]);

    // Validação do código
    do
    {
        cout << "Digite o código da Disciplina (3 dígitos): ";
        cin >> codigo;
    } while (codigo.length() != 3);

    // Validação da turma
    do
    {
        cout << "Digite a turma da Disciplina [A-Z]: ";
        cin >> turma;
        turma[0] = toupper(turma[0]);
    } while (!isalpha(turma[0]) || turma.length() != 1);

    // Adiciona a disciplina ao arquivo
    ofstream arquivo("../disciplinas.txt", ios::app);
    if (arquivo.is_open())
    {
        arquivo << disciplina << "; " << codigo << "; " << turma << "\n";
        arquivo.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo." << endl;
    }

    // Atualiza o número de disciplinas e adiciona a nova disciplina à matriz
    tam_disciplinas++;
    disciplinas.resize(tam_disciplinas, vector<string>(3));
    disciplinas[tam_disciplinas - 1] = {disciplina, codigo, turma};

    cout << "Disciplina adicionada com sucesso!\n"
         << endl;
}

void exibirNotas()
{
    int k;
    int m = 1, n = 1;
    string bimestres = "";
    string materia = "";
    float media = 0;
    int b=0;
    ifstream arquivo;
    int x=1,y=1;
    // Abertura do arquivo
    arquivo.open("../notas.txt");
    if (arquivo.is_open())
    {
        string linha;
        
        // Preenche os nomes dos alunos nas primeiras posições
        for (int i = 1; i <= tam_alunos; i++)
        {
            notas[i][0] = alunos[i - 1][0]; // Ajuste do índice
        }

        // Preenche os nomes das disciplinas na linha 0
        for (int i = 2; i <= tam_disciplinas + 1; i++)
        {
            notas[0][i] = disciplinas[i - 2][0]; // Ajuste do índice
        }
        notas[0][1] = "Matricula";
        while (getline(arquivo, linha))
        {
            notas[m][n] = "";
            string temp;
            materia = ""; // Reseta a variável para cada linha

            for (char c : linha)
            {
                // Verifica se é uma letra, assumindo que é o início de uma matéria
                if (isalpha(c))
                {
                    materia += c; // Acumula os caracteres da matéria
                }

                // Adiciona a nota (dígitos ou "-")
                if (isdigit(c) || c == '-')
                {
                    if (c == '-')
                    {
                        //cout<<bimestres<<" ";
                        media += stof(bimestres);
                        relatorio[x][y]=bimestres;
                        y++;
                        if (b==4)
                        {

                            media=media/4;
                            relatorio[x][y]=to_string(media);
                            media=0;
                            x++;
                        }
                        
                        cout << media << endl;
                        bimestres = "";
                        b++;
                    }
                    else 
                    {
                        bimestres += c;
                        if (k>4)
                        {
                            relatorio[0][0]=bimestres;
                            bimestres="";
                        }

                    }
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
                k++;
            }

            // Adiciona o último item se houver
            if (!temp.empty())
            {
                for (int i = 0; i < tam_disciplinas; i++)
                {
                    // Comparar a string `materia` com a string da disciplina completa
                    if (materia == disciplinas[i][0])
                    {
                        // Atribuir o valor de 'temp' à posição correta em 'notas'
                        notas[m][i + 2] = temp;
                    }
                }
            }

            // Reseta o índice da coluna e incrementa a linha
            n = 1;
            m++;
            k=0;
            x=1;
            y=1; 
        }
        arquivo.close();

        
    }
    else
    {
        cout << "Não foi possível abrir o arquivo." << endl;
        return;
    }

    // Exibe as notas dos alunos
    notas[0][0] = "Aluno/Disciplina";
    for (int i = 0; i <= tam_alunos + 1; i++)
    {
        for (int j = 0; j <= tam_disciplinas + 1; j++)
        {
            cout << left << setw(20) << notas[i][j]; // Notas
        }
        cout << endl;
    }
    cout << endl;


    for (int i = 0; i <= tam_disciplinas+1 + 1; i++)
    {
        for (int j = 0; j <= 6 + 1; j++)
        {
            cout << left << setw(20) << relatorio[i][j]; // Notas
        }
        cout << endl;
    }
    cout << endl;
}


void lançar_notas()
{
    string modificação = "";
    string buscas;
    bool quebra = false;

    // Buscando aluno por nome ou matrícula
    do
    {
        cout << "Digite o nome ou a matrícula do aluno: ";
        getline(cin, modificação);

        for (int i = 0; i < tam_alunos; i++)
        {
            if ((modificação == alunos[i][0]) || (modificação == alunos[i][1]))
            {
                buscas = alunos[i][1];
                quebra = true;
                break;
            }
        }

        if (!quebra)
            cout << "Aluno não encontrado. Tente novamente.\n";

    } while (!quebra);

    string var, linha_modificada = "", notas_string = "";
    int n1, k = -1;
    float media = 0;
    vector<string> line;
    fstream arquivo;

    // Abrindo arquivo de notas
    arquivo.open("../notas.txt", ios::in);
    if (arquivo.is_open())
    {
        string linha;
        while (getline(arquivo, linha))
        {
            line.push_back(linha);
            int pos = linha.find(';');
            var = linha.substr(0, pos); // Captura a matrícula

            // Se a matrícula encontrada é a que buscamos
            if (buscas == var)
            {
                linha_modificada = buscas + ";"; // Começa a montar a linha modificada com a matrícula
                string escolha;
                for (int i = 0; i < tam_disciplinas; i++)
                {
                    // Pergunta se o usuário deseja modificar as notas de cada disciplina
                    cout << "Você quer modificar a disciplina " << disciplinas[i][0] << "? [S/N]" << endl;
                    cin >> escolha;
                    escolha[0] = toupper(escolha[0]);

                    if (escolha[0] == 'S')
                    {
                        linha_modificada += disciplinas[i][0] + ";"; // Adiciona o nome da disciplina

                        // Coleta as notas dos 4 bimestres
                        media = 0;
                        notas_string = "";
                        for (int c = 1; c <= 4; c++)
                        {
                            do
                            {
                                cout << "Digite a nota do " << c << "º Bimestre (0-100): ";
                                cin >> n1;
                                if (n1 < 0 || n1 > 100)
                                {
                                    cout << "Nota inválida! Digite novamente." << endl;
                                }
                            } while (n1 < 0 || n1 > 100);

                            media += n1;
                            notas_string += to_string(n1);
                            if (c < 4) notas_string += "-";
                        }

                        media /= 4; // Calcula a média final
                        notas_string += ";";
                        linha_modificada += notas_string; // Adiciona as notas à linha modificada

                        k = line.size() - 1; // Marca a posição da linha que será modificada
                    }
                }
            }
        }
        arquivo.close();
    }
    else
    {
        cout << "Arquivo de notas não abriu!" << endl;
        return;
    }

    // Se modificou alguma linha, atualiza o arquivo
    if (k != -1)
    {
        arquivo.open("../notas.txt", ios::out | ios::trunc);
        if (arquivo.is_open())
        {
            for (int i = 0; i < line.size(); i++)
            {
                if (i == k)
                    arquivo << linha_modificada << "\n"; // Substitui a linha modificada
                else
                    arquivo << line[i] << "\n"; // Reescreve as outras linhas
            }
            arquivo.close();
            cout << "Notas adicionadas com sucesso!" << endl;
        }
        else
        {
            cout << "Erro ao abrir o arquivo para escrita!" << endl;
        }
    }
    else
    {
        cout << "Nenhuma modificação foi feita." << endl;
    }
}

// Função principal
int main()
{
    // Inicializa o número de alunos e disciplinas
    tam_alunos = tamanho("../alunos.txt");
    tam_disciplinas = tamanho("../disciplinas.txt");

    // Redimensiona as matrizes de acordo com o número de alunos e disciplinas
    alunos.resize(tam_alunos, vector<string>(3));
    disciplinas.resize(tam_disciplinas, vector<string>(3));
    notas.resize(tam_alunos+2, vector<string>(tam_disciplinas+2));
    relatorio.resize(tam_disciplinas+1, vector<string>(6));

    // Carrega os dados dos arquivos para as matrizes
    salvar_matriz("../alunos.txt", alunos);
    salvar_matriz("../disciplinas.txt", disciplinas);
    exibirNotas();
    int escolha;
    do
    {
        cout << "Menu de opções:\n";
        cout << "1. Mostrar alunos e disciplinas\n";
        cout << "2. Adicionar aluno\n";
        cout << "3. Adicionar disciplina\n";
        cout << "4. Sair\n";
        cout << "Digite sua escolha: ";
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            mostrar_matriz();
            break;
        case 2:
            adicionar_alunos();
            break;
        case 3:
            cadastrar_disciplinas();
            break;
        case 4:
            cout << "Saindo...\n";
            break;
        case 5:
            lançar_notas();
            break;
        default:
            cout << "Opção inválida! Tente novamente.\n";
        }
    } while (escolha != 4);

    return 0;
}
