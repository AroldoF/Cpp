#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void adicionar_pessoas(int tamanho)
{
    string nome;
    string pessoa;
    string numero;
    cout<<"Digite o nome da pessoa que voce quer adicionar"<<endl;
    cin >> nome;
    do
    {
        cout<<"Digite o numero da pessoa que voce quer adicionar"<<endl;
        cin >> numero;
        int c = 0;
        for (int i = 0; i < nome.length(); i++)
        {
            pessoa += nome[i];
            if (i == nome.length() - 1)
            {
                pessoa += ';';
                pessoa += ' ';
            }
        }
        for (int i = 0; i < numero.length(); i++)
        {
            if (numero[i] == ' ' || numero[i] == '-' || numero[i] == '*')
            {
            }
            else
            {
                if (c == 1)
                {
                    pessoa += " ";
                }
                if (c == 5)
                {
                    pessoa += "-";
                }
                c++;
                pessoa += numero[i];
            }
        }
        if (pessoa.length() - nome.length() - 2 != 11)
        {
            cout<<"O numero que voce digitou esta incorreto"<<endl;
        }
    } while (pessoa.length() - nome.length() - 2 != 11);

    string artigo("C:/Users/Aroldo/Documents/GitHub/Cpp/C++/manipulação_txt/agenda/agenda.txt");
    ofstream arquivo;
    arquivo.open("C:/Users/Aroldo/Documents/GitHub/Cpp/C++/manipulação_txt/agenda/agenda.txt", ios::app);

    if (arquivo.is_open())
    {
        arquivo << "/n";
        arquivo << pessoa;
    }
    arquivo.close();
    cout<<endl;
}

void mostrar()
{
    ifstream arquivo("C:/Users/Aroldo/Documents/GitHub/Cpp/C++/manipulação_txt/agenda/agenda.txt");
    string linha;
    while (getline(arquivo, linha))
    {
        cout << linha << endl;
    }
    arquivo.close();
    cout<<endl;
}

int informações()
{
    ifstream arquivo("C:/Users/Aroldo/Documents/GitHub/Cpp/C++/manipulação_txt/agenda/agenda.txt");
    string linha;
    int x = 0;
    while (getline(arquivo, linha))
    {
        x++;
    }
    return x;
    arquivo.close();
}

void procurar(string matriz[][2], string nome)
{
    ifstream arquivo("C:/Users/Aroldo/Documents/GitHub/Cpp/C++/manipulação_txt/agenda/agenda.txt");
    
    string pessoa;
    string telefone;
    string linha;
    int j = 0;
    int c = 0;
    int z = 0;

    while (getline(arquivo, linha))
    {
        for (int i = 0; i < linha.length(); i++)
        {
            if (linha[i] == ';')
            {
                j++;
            }
            else
            {
                if (linha[i] == ' ' && z == 2)
                {
                }
                else
                {
                    matriz[c][j] += linha[i];
                }
                z++;
            }
        }
        z = 0;
        j = 0;
        if (nome == matriz[c][j])
        {
            cout << "O numero de " << matriz[c][0] << " e" << matriz[c][1]<<endl;
            break;
        }
        c++;
    }
    arquivo.close();
    cout<<endl;
}

int main()
{
    int tamanho;
    tamanho = informações();
    string matriz[tamanho][2];
    string nome;
    int escolha;
    do
    {
        cout << "Digite 1 para procurar na agenda uma pessoa pelo nome!" << endl;
        cout << "Digite 2 para adicionar uma pessoa a agenda!" << endl;
        cout << "Digite 3 para mostrar a agenda!" << endl;
        cout << "Digite 4 para finalizar o programa!" << endl;
        cin >> escolha;
        cout<<endl;
        switch (escolha)
        {
        case 1:
            cout << "Digite o nome pessoa que voce quer o numero:" << endl;
            cin >> nome;
            procurar(matriz, nome);
            break;
        case 2:
            adicionar_pessoas(tamanho);
            break;
        case 3:
            mostrar();
            break;
        case 4:
            break;
        default:
            cout << "error" << endl;
            break;
        }
    } while (escolha != 4);

    return 0;
}