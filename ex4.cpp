#include <iostream>
using namespace std;

int main()
{
    int vet[10], n;

    for (n = 0; n < 10; n++)
    {
        cout << "Informe um numero inteiro para ser armazenado na posicao [" << n << "]: ";
        cin >> vet[n];
    }
    cout << endl;
    for (n = 0; n < 10; n++)
    {
        vet[n] += 2;
    }
    for (n = 5; n < 10; n++)
    {
        cout << "O valor somado a 2 da posicao [" << n << "] do vetor e: " << vet[n] << endl;
    }
}