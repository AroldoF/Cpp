#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream arquivo("C:/Users/heloy/Documents/GitHub/Cpp/C++/matrizes/Encapsulamento_e_Funções/leitura_de_txt/test.txt");

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }
    string linha;
    while (getline(arquivo, linha))
    {
        cout << linha << endl;
    }
    
    arquivo.close();
}