#include <iostream>
using namespace std;
#define v 10
int main()
{
    int vet[v], x, maior_num, y = 0;
    for (x = 0; x < v; x++)
    {
        cout << "Informe um valor inteiro: ";
        cin >> vet[x];
    }
    maior_num = vet[0];
    for (x = 0; x < v; x++)
    {
        if (maior_num < vet[x])
            maior_num = vet[x];
    }
    y = 0;
    while (maior_num != vet[y])
    {
        y++;
    }

    cout << "O maior numero e: " << maior_num << endl;
    cout << "A sua posicao no vetor entre 0 e 9 e: " << y;
}