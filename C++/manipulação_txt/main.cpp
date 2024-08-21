#include <iostream>
#include <fstream>  

using namespace std;

int main()
{
    ifstream arquivo("C:/Users/heloy/Desktop/test/test.txt");

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }
    double soma=0;
    int num=0;
    string linha;
    while (getline(arquivo, linha))
    {
        cout << linha << endl;
        soma+=stod(linha);
        num++;
    }

    arquivo.close();

    double media=soma/num;

    ofstream meuarquivo("C:/Users/heloy/Desktop/test/resp.txt");

    if (meuarquivo.is_open())
    {   
        meuarquivo<<"primeira linha\n";
        meuarquivo<<"segunda linha\n";
        meuarquivo<<media;
    }
    else
        cout << "Erro ao abrir arquivo de texto.";

    meuarquivo.close();

    return 0;
}