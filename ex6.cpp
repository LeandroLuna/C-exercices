#include <iostream>
using namespace std;
#define MaxA 40

int main()
{
    int rm[MaxA], alunos, x, y = 0, aprovados[MaxA];
    float media[MaxA], a, b;

    cout << "Numero de alunos: ";
    cin >> alunos;
    if (alunos < MaxA && alunos > 0)
    {
        for (x = 0; x < alunos; x++)
        {
            cout << "Informe o RM do " << x + 1 << "o aluno: ";
            cin >> rm[x];
            cout << "Informe a 1a nota do aluno de rm " << rm[x] << ": ";
            cin >> a;
            cout << "Informe a 2a nota do aluno de rm " << rm[x] << ": ";
            cin >> b;
            media[x] = (a + b) / 2;
        }
        for (x = 0; x < alunos; x++)
        {
            if (media[x] >= 6)
            {
                aprovados[y] = rm[x];
                y++;
            }
        }
        cout << "\n\tAlunos aprovados: " << endl;
        for (x = 0; x < y; x++)
        {
            cout << aprovados[x] << endl;
        }
    }
    else
    {
        cout << "Informe um numero maior que 0 e menor ou igual a 40.";
    }
}