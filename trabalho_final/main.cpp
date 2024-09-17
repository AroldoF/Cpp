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

void mostrar_matriz(string nomes[][3], string disciplinas[][3], int tam_alunos, int tam_disciplinas, vector<vector<string>> &notas)
{
    int escolha_int;
    cout << "Voce deseja ver mais detalhadamente sobre os alunos? [1]" << endl;
    cout << "Voce deseja ver mais detalhadamente sobre as disciplinas? [2]" << endl;
    cout << "Voce deseja ver mais detalhadamente sobre as notas? [3]" << endl;
    cin >> escolha_int;
    switch (escolha_int)
    {
    case 1:
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
        break;
    case 2:
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
        break;
    case 3:
        notas[0][0] = "Aluno/Disciplina";
        for (int i = 0; i < tam_alunos + 1; i++)
        {
            // cout << left << setw(20) << notas[i][0]; // Nome dos alunos
            for (int j = 0; j < tam_disciplinas + 2; j++)
            {
                cout << left << setw(20) << notas[i][j]; // Notas
            }
            cout << endl;
        }
        cout << endl;
        break;
    default:
        cout << "erro!" << endl;
        break;
    }
}

void adicionar_alunos(int tam, string nomes[][3], int tam_disciplinas, string disciplinas[][3])
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
    {
        cout << "Nao foi possível abrir o arquivo." << endl;
    }

    arquivo.close();

    
    string linha_modificada = "";
    linha_modificada += matricula;
    for (i = 0; i < tam_disciplinas; i++)
    {
        linha_modificada += ";";
        linha_modificada += disciplinas[i][0][0];
        linha_modificada += ";0-0-0-0";
    }
    fstream meuarquivo;
    meuarquivo.open("../notas.txt", ios::out | ios::app);
    if (meuarquivo.is_open())
    {
        meuarquivo << "\n";
        meuarquivo << linha_modificada;
    }
    else
    {
        cout << "Nao foi possível abrir o arquivo." << endl;
    }
    meuarquivo.close();
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
    {
        cout << "Não foi possível abrir o arquivo." << endl;
    }
    arquivo.close();

    fstream meuarquivo;
    string linha;
    vector<string> line(tam + 1);
    int x = 0;
    meuarquivo.open("../notas.txt", ios::in);
    if (meuarquivo.is_open())
    {
        while (getline(meuarquivo, linha))
        {
            line[x] = linha;
            line[x] += ";";
            line[x] += disciplina[0];
            line[x] += ";0-0-0-0";
            cout << line[x] << endl;
            x++;
        }
        meuarquivo.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo." << endl;
    }

    meuarquivo.open("../notas.txt", ios::out | ios::trunc);
    if (meuarquivo.is_open())
    {
        for (int i = 0; i < line.size(); i++)
        {
            meuarquivo << line[i] << endl;
        }
        meuarquivo.close();
    }
    else
    {
        cout << "Não foi possível abrir o arquivo." << endl;
    }
    meuarquivo.close();

    cout << "A disciplina " << nome << " adicionado com sucesso!" << endl;
}

void exibirNotas(int tam_alunos, int tam_disciplinas, string nomes[][3], string disciplinas[][3], vector<vector<string>> &notas)
{
    int m = 1, n = 1;
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
        }
        notas[0][1] = "Matricula";
        while (getline(arquivo, linha))
        {
            // Reseta a linha da matriz
            notas[m][n] = "";
            string temp; // Temporário para armazenar cada nota ou nome
            for (char c : linha)
            {
                if (isalpha(c))
                {
                    string materia = string(1, c);
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
                notas[m][n++] = temp;
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
}

void lançar_notas(string nomes[][3], int tam_alunos, string disciplinas[][3], int tam_disciplinas, vector<vector<string>> &notas)
{
    string modificação = "";
    string buscas;
    bool quebra = false;
    do
    {
        int i;
        cout << "Digite o nome ou a Matricula do aluno " << endl;
        cin.ignore();
        getline(cin, modificação);
        modificação[0]=toupper(modificação[0]);
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
    int c = 1, l = 1;
    string linha_modificada;
    linha_modificada = "";
    string notas_string;
    notas_string = "";
    int n1;
    float media = 0;
    fstream arquivo;
    vector<string> line;
    int k = 0;

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
                    }
                    else
                    {
                        linha_modificada += disciplinas[i][0][0];
                        linha_modificada += ";";
                        linha_modificada += notas[l][i + 2];
                        if (i + 1 == tam_disciplinas)
                        {
                        }
                        else
                            linha_modificada += ";";
                    }
                }
                k = line.size() - 1;
            }
            l++;
        }
        arquivo.close();
    }
    else
        cout << "arquivo nao abriu!" << endl;

    cout << "linha modificada e:\n"
         << linha_modificada << endl;

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

void relatorio(vector<vector<string>> &notas, int tam_disciplinas, string nomes[][3], int tam_alunos, string disciplinas[][3])
{
    int escolha;
    string var = "";
    float media = 0;
    cout << "Voce quer consultar as notas de um aluno especifico em todas as disciplinas? [1]" << endl;
    cout << "Voce quer consultar as notas de todos os alunos em cada materia? [2]" << endl;
    cin >> escolha;
    if (escolha == 1)
    {
        cout << "nome ou matricula do aluno:" << endl;
        cin >> var;

        // Procurar o nome ou matrícula no vetor de nomes
        for (int i = 0; i < tam_alunos; i++)
        {
            if (var == nomes[i][0] || var == nomes[i][1])
            {
                var = nomes[i][1]; // Atribui a matrícula, se encontrada
                break;             // Sai do loop após encontrar o aluno
            }
        }

        int j = -1;
        // Buscar a matrícula no vetor de notas
        for (int i = 1; i < tam_alunos; i++)
        {
            if (var == notas[i][1]) // Matrícula correspondente
            {
                j = i; // Guarda a posição do aluno
                break;
            }
        }

        if (j == -1)
        {
            cout << "Aluno não encontrado." << endl;
            return;
        }

        cout << "Relatorio do aluno " << nomes[j][0] << ":" << endl;
        // Exibir disciplinas e cabeçalhos
        for (int i = 2; i < tam_disciplinas + 2; i++)
        {
            cout << left << setw(15) << notas[0][i] << left << setw(15) << "Media";
        }
        cout << endl;

        // Processar as notas e calcular as médias para o aluno 'j'
        string bimestres = "";
        float media = 0.0;
        int nota_count = 0;

        for (int i = 2; i < tam_disciplinas + 2; i++)
        {
            // Exibir a disciplina atual
            cout << left << setw(15) << notas[j][i];

            // Resetar as variáveis para cada disciplina
            bimestres = "";
            media = 0.0;
            nota_count = 0;

            // Percorrer os caracteres das notas
            for (size_t l = 0; l < notas[j][i].length(); l++)
            {
                if (isdigit(notas[j][i][l]))
                {
                    bimestres += notas[j][i][l]; // Constrói o número da nota
                }

                // Se encontrar o separador '-' ou atingir a última posição
                if (notas[j][i][l] == '-' || l == notas[j][i].length() - 1)
                {
                    if (!bimestres.empty())
                    {
                        media += stof(bimestres); // Converte para float e adiciona à média
                        nota_count++;
                    }
                    bimestres = ""; // Limpa a string temporária
                }
            }

            // Exibir a média (evitar divisão por zero)
            if (nota_count > 0)
            {
                cout << left << setw(15) << media / nota_count;
            }
            else
            {
                cout << left << setw(15) << "N/A"; // Sem notas
            }
        }
        cout << endl;
    }
    else if (escolha == 2)
    {
        cout << "nome ou codigo da disciplina:" << endl;
        cin >> var;
        var[0] = toupper(var[0]);
        for (int i = 0; i < tam_disciplinas; i++)
        {
            if (var[0] == disciplinas[i][0][0] || var == disciplinas[i][1])
            {
                var = disciplinas[i][0]; // Atribui a matrícula, se encontrada
                break;                   // Sai do loop após encontrar o aluno
            }
        }

        int j = -1;
        // Buscar a matrícula no vetor de notas
        for (int i = 2; i < tam_disciplinas + 2; i++)
        {
            if (var == notas[0][i]) // Matrícula correspondente
            {
                j = i; // Guarda a posição do aluno
                break;
            }
        }

        if (j == -1)
        {
            cout << "Disciplina nao encontrado." << endl;
            return;
        }

        cout << "Relatorio da materia de " << var << ":" << endl;
        cout << left << setw(20) << notas[0][j] << left << setw(15) << "Notas:" << left << setw(15) << "Media";
        cout << endl;

        // Processar as notas e calcular as médias para o aluno 'j'
        string bimestres = "";
        float media = 0.0;
        int nota_count = 0;

        for (int i = 1; i < tam_alunos + 1; i++)
        {
            // Exibir a disciplina atual
            cout << left << setw(20) << notas[i][0];
            cout << left << setw(15) << notas[i][j];
            // Resetar as variáveis para cada disciplina
            bimestres = "";
            media = 0.0;
            nota_count = 0;

            // Percorrer os caracteres das notas
            for (size_t l = 0; l < notas[i][j].length(); l++)
            {
                if (isdigit(notas[i][j][l]))
                {
                    bimestres += notas[i][j][l]; // Constrói o número da nota
                }

                // Se encontrar o separador '-' ou atingir a última posição
                if (notas[i][j][l] == '-' || l == notas[i][j].length() - 1)
                {
                    if (!bimestres.empty())
                    {
                        media += stof(bimestres); // Converte para float e adiciona à média
                        nota_count++;
                    }
                    bimestres = ""; // Limpa a string temporária
                }
            }

            // Exibir a média (evitar divisão por zero)
            if (nota_count > 0)
            {
                cout << left << setw(15) << media / nota_count;
            }
            else
            {
                cout << left << setw(15) << "N/A"; // Sem notas
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{

    int tam_alunos = tamanho("../alunos.txt");
    int tam_disciplinas = tamanho("../disciplinas.txt");

    string nomes[tam_alunos][3];
    string disciplinas[tam_disciplinas][3];

    vector<vector<string>> notas(tam_alunos + 1, vector<string>(tam_disciplinas + 2));
    salvar_matriz("../alunos.txt", nomes);
    salvar_matriz("../disciplinas.txt", disciplinas);

    string escolha_string = "";
    int escolha;
    do
    {
        cout << "Digite 1 para mostrar alunos, disciplinas e notas" << endl;
        cout << "Digite 2 para adicionar aluno" << endl;
        cout << "Digite 3 para adicionar disciplinas" << endl;
        cout << "Digite 4 para adicionar notas" << endl;
        cout << "Digite 5 para um relatorio de alunos ou materias" << endl;
        cout << "Digite 6 para limpar" << endl;
        cout << "Digite 0 para sair" << endl;
        cin >> escolha;
        cout << endl;
        exibirNotas(tam_alunos, tam_disciplinas, nomes, disciplinas, notas);
        switch (escolha)
        {
        case 1:
            mostrar_matriz(nomes, disciplinas, tam_alunos, tam_disciplinas,notas);
            break;
        case 2:
            adicionar_alunos(tam_alunos, nomes, tam_disciplinas, disciplinas);
            tam_alunos++;
            salvar_matriz("../alunos.txt", nomes);
            exibirNotas(tam_alunos, tam_disciplinas, nomes, disciplinas, notas);
            cout << "Voce quer adicionar notas? [S/N]" << endl;
            cin >> escolha_string;
            escolha_string[0] = toupper(escolha_string[0]);
            if (escolha_string[0] == 'S')
            {
                lançar_notas(nomes, tam_alunos, disciplinas, tam_disciplinas, notas);
            }
            break;
        case 3:
            cadastrar_disciplinas(tam_disciplinas, disciplinas);
            tam_disciplinas++;
            salvar_matriz("../disciplinas.txt", disciplinas);
            exibirNotas(tam_alunos, tam_disciplinas, nomes, disciplinas, notas);
            cout << "Voce quer adicionar notas? [S/N]" << endl;
            cin >> escolha_string;
            escolha_string[0] = toupper(escolha_string[0]);
            if (escolha_string[0] == 'S')
            {
                lançar_notas(nomes, tam_alunos, disciplinas, tam_disciplinas, notas);
            }
            break;
        case 4:
            lançar_notas(nomes, tam_alunos, disciplinas, tam_disciplinas, notas);
            exibirNotas(tam_alunos, tam_disciplinas, nomes, disciplinas, notas);
            break;
        case 5:
            relatorio(notas, tam_disciplinas, nomes, tam_alunos, disciplinas);

            break;
        case 6:
            system("cls");
            break;
        case 0:
            break;
        default:
            cout << "error" << endl;
            break;
        }
    } while (escolha != 0);

    return 0;
}