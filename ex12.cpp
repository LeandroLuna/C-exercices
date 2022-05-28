#include <iostream>
using namespace std;
#include <locale>
#define MAX 30
#define NP 2
int main()
{
    setlocale(LC_ALL, "");
    float nota[MAX][NP];
    float maior = 0;
    int aluno, prova, n, pos;
    cout << "Digite número de alunos na sala (máximo 30): ";
    cin >> n;
    for (aluno = 0; aluno < n; aluno++)
    {
        cout << "Aluno " << aluno << endl;
        for (prova = 0; prova < NP; prova++)
        {
            cout << "Digite a nota da avaliação " << prova << ": ";
            cin >> nota[aluno][prova];
        }
    }
    maior = 0;
    for (aluno = 0; aluno < n; aluno++)
    {
        if (nota[aluno][1] > maior)
            maior = nota[aluno][1];
    }
    cout << "\n A maior nota da segunda prova é: " << maior << endl;
    do
    {
        cout << "Escolha um aluno para calcular média (0 até " << n - 1 << "): ";
        cin >> pos;
    } while (pos > n - 1);
    cout << "Media = " << (nota[pos][0] + nota[pos][1]) / 2;
    cout << endl;
    return 0;
}
