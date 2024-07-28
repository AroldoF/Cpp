#include <iostream>
#include <string>
using namespace std;
int main()
{
    double notas[4][4];
    string nomes[4];
    double medias[4];
    int i, j;
    double media_aluno = 0, total = 0;
    string line;

    for (i = 0; i < 4; i++)
    {
        cout << "nome do aluno:" << endl;
        if (i != 0)
        {
            cin.ignore();
        }
        getline(cin, line);
        nomes[i] = line;
        for (j = 0; j < 4; j++)
        {
            cout << "nota " << j + 1 << ":" << endl;
            cin >> notas[i][j];
            media_aluno += notas[i][j];
        }
        medias[i] = media_aluno / 4;
        media_aluno = 0;
    }

    for (i = 0; i < 4; i++)
    {
        cout << "Aluno " << nomes[i] << " teve media " << medias[i] << endl;
        total += medias[i];
    }

    cout << "a media total dos alunos foi " << total / 4 << endl;
    return 0;
}
